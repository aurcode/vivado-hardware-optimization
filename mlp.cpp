#include "mlp.hpp"
#include "weights_mlp_q.h"

// =============================================================================
// Explicit Finite State Machine (FSM) States
// Orchestrates Time-Division Multiplexed (TDM) compute flow
// =============================================================================
typedef enum {
    FSM_LOAD_INPUT = 0,
    FSM_LAYER1,
    FSM_LAYER2,
    FSM_LAYER3,
    FSM_WRITE_OUTPUT,
    FSM_DONE
} fsm_state_t;

// =============================================================================
// Lightweight Hardware Pruning: Rescaling & Sign-Bit Comparison for ReLU
// Rescales products from 2^24 to 2^10 via right-shift >> 14 with rounding (+8192)
// ReLU activates strictly via sign-bit mux: (x > 0) ? x : 0
// =============================================================================
inline data_t rescale_and_relu(acc_t acc) {
    #pragma HLS INLINE
    acc_t rounded = (acc + RESCALE_ROUND) >> RESCALE_SHIFT;
    if (rounded <= 0) {
        return 0;
    } else if (rounded > 32767) {
        return 32767;
    } else {
        return (data_t)rounded;
    }
}

inline data_t rescale_linear(acc_t acc) {
    #pragma HLS INLINE
    acc_t rounded = (acc + RESCALE_ROUND) >> RESCALE_SHIFT;
    if (rounded > 32767) {
        return 32767;
    } else if (rounded < -32768) {
        return -32768;
    } else {
        return (data_t)rounded;
    }
}

// =============================================================================
// Unified Parameterized 16-way SIMD MAC Compute Core
// Highly reused across all 3 layers via Time-Division Multiplexing (TDM)
// Implements 16 parallel DSP48 multipliers followed by a balanced adder tree
// =============================================================================
inline acc_t simd_mac16(const data_t act_slice[SIMD_WIDTH], const weight_t w_slice[SIMD_WIDTH]) {
    #pragma HLS INLINE
    acc_t prod[SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=prod complete dim=1

    // Stage 1: 16 parallel fixed-point multipliers
    SIMD_MUL: for (int k = 0; k < SIMD_WIDTH; ++k) {
        #pragma HLS UNROLL
        prod[k] = (acc_t)act_slice[k] * (acc_t)w_slice[k];
    }

    // Stage 2: Balanced 16-input Pipelined Adder Tree (Prevents timing violations)
    acc_t stage1[8];
    #pragma HLS ARRAY_PARTITION variable=stage1 complete dim=1
    TREE_L1: for (int k = 0; k < 8; ++k) {
        #pragma HLS UNROLL
        stage1[k] = prod[2*k] + prod[2*k + 1];
    }

    acc_t stage2[4];
    #pragma HLS ARRAY_PARTITION variable=stage2 complete dim=1
    TREE_L2: for (int k = 0; k < 4; ++k) {
        #pragma HLS UNROLL
        stage2[k] = stage1[2*k] + stage1[2*k + 1];
    }

    acc_t stage3[2];
    #pragma HLS ARRAY_PARTITION variable=stage3 complete dim=1
    stage3[0] = stage2[0] + stage2[1];
    stage3[1] = stage2[2] + stage2[3];

    return stage3[0] + stage3[1];
}

// =============================================================================
// Top-Level Synthesizable Accelerator: mlp_accel
// =============================================================================
void mlp_accel(
    const data_t in_vec[INPUT_NODES],
    data_t out_vec[OUTPUT_NODES]
) {
    // -------------------------------------------------------------------------
    // AXI4-Lite Control & Memory-Mapped Data Interfaces (Zynq PS-PL Bridge)
    // -------------------------------------------------------------------------
    #pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=in_vec bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=out_vec bundle=CTRL_BUS

    // -------------------------------------------------------------------------
    // On-Chip Activation Memory Buffers (Block-Aligned for SIMD Access)
    // -------------------------------------------------------------------------
    // Local input image buffer (49 blocks x 16 elements = 784 inputs)
    data_t input_buf[L1_BLOCKS][SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=input_buf complete dim=2

    // Ping-Pong Buffers for intermediate layer activations
    // ping_buf: Layer 1 activations (8 blocks x 16 elements = 128 neurons)
    data_t ping_buf[L2_BLOCKS][SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=ping_buf complete dim=2

    // pong_buf: Layer 2 activations (4 blocks x 16 elements = 64 neurons)
    data_t pong_buf[L3_BLOCKS][SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=pong_buf complete dim=2

    // Output logits buffer (10 elements)
    data_t out_buf[OUTPUT_NODES];
    #pragma HLS ARRAY_PARTITION variable=out_buf complete dim=1

    // -------------------------------------------------------------------------
    // Weight Storage On-Chip Partitioning
    // Partitioning along innermost SIMD dimension (16) enables parallel read
    // -------------------------------------------------------------------------
    #pragma HLS ARRAY_PARTITION variable=weights_l1 complete dim=3
    #pragma HLS ARRAY_PARTITION variable=weights_l2 complete dim=3
    #pragma HLS ARRAY_PARTITION variable=weights_l3 complete dim=3

    // -------------------------------------------------------------------------
    // Finite State Machine (FSM) Execution Loop
    // -------------------------------------------------------------------------
    fsm_state_t state = FSM_LOAD_INPUT;
    bool execution_active = true;

    EXEC_FSM: while (execution_active) {
        #pragma HLS PIPELINE off
        switch (state) {
            case FSM_LOAD_INPUT: {
                // Buffer input pixels from AXI bus into local BRAM blocks
                LOAD_LOOP_B: for (int b = 0; b < L1_BLOCKS; ++b) {
                    #pragma HLS PIPELINE II=1
                    for (int k = 0; k < SIMD_WIDTH; ++k) {
                        #pragma HLS UNROLL
                        input_buf[b][k] = in_vec[b * SIMD_WIDTH + k];
                    }
                }
                state = FSM_LAYER1;
                break;
            }

            case FSM_LAYER1: {
                // Layer 1: 784 Inputs -> 128 Hidden Neurons
                // TDM Execution: 49 SIMD-16 blocks per neuron = 6,272 compute cycles
                L1_NEURONS: for (int n = 0; n < L1_NODES; ++n) {
                    acc_t acc = 0;
                    L1_BLOCKS_LOOP: for (int b = 0; b < L1_BLOCKS; ++b) {
                        #pragma HLS PIPELINE II=1
                        data_t act_chunk[SIMD_WIDTH];
                        weight_t w_chunk[SIMD_WIDTH];
                        #pragma HLS ARRAY_PARTITION variable=act_chunk complete dim=1
                        #pragma HLS ARRAY_PARTITION variable=w_chunk complete dim=1

                        FETCH_L1: for (int k = 0; k < SIMD_WIDTH; ++k) {
                            #pragma HLS UNROLL
                            act_chunk[k] = input_buf[b][k];
                            w_chunk[k] = weights_l1[n][b][k];
                        }
                        acc += simd_mac16(act_chunk, w_chunk);
                    }
                    ping_buf[n / SIMD_WIDTH][n % SIMD_WIDTH] = rescale_and_relu(acc);
                }
                state = FSM_LAYER2;
                break;
            }

            case FSM_LAYER2: {
                // Layer 2: 128 Hidden Inputs -> 64 Hidden Neurons
                // TDM Execution: 8 SIMD-16 blocks per neuron = 512 compute cycles
                L2_NEURONS: for (int n = 0; n < L2_NODES; ++n) {
                    acc_t acc = 0;
                    L2_BLOCKS_LOOP: for (int b = 0; b < L2_BLOCKS; ++b) {
                        #pragma HLS PIPELINE II=1
                        data_t act_chunk[SIMD_WIDTH];
                        weight_t w_chunk[SIMD_WIDTH];
                        #pragma HLS ARRAY_PARTITION variable=act_chunk complete dim=1
                        #pragma HLS ARRAY_PARTITION variable=w_chunk complete dim=1

                        FETCH_L2: for (int k = 0; k < SIMD_WIDTH; ++k) {
                            #pragma HLS UNROLL
                            act_chunk[k] = ping_buf[b][k];
                            w_chunk[k] = weights_l2[n][b][k];
                        }
                        acc += simd_mac16(act_chunk, w_chunk);
                    }
                    pong_buf[n / SIMD_WIDTH][n % SIMD_WIDTH] = rescale_and_relu(acc);
                }
                state = FSM_LAYER3;
                break;
            }

            case FSM_LAYER3: {
                // Layer 3: 64 Hidden Inputs -> 10 Output Classes
                // TDM Execution: 4 SIMD-16 blocks per neuron = 40 compute cycles
                L3_NEURONS: for (int n = 0; n < OUTPUT_NODES; ++n) {
                    acc_t acc = 0;
                    L3_BLOCKS_LOOP: for (int b = 0; b < L3_BLOCKS; ++b) {
                        #pragma HLS PIPELINE II=1
                        data_t act_chunk[SIMD_WIDTH];
                        weight_t w_chunk[SIMD_WIDTH];
                        #pragma HLS ARRAY_PARTITION variable=act_chunk complete dim=1
                        #pragma HLS ARRAY_PARTITION variable=w_chunk complete dim=1

                        FETCH_L3: for (int k = 0; k < SIMD_WIDTH; ++k) {
                            #pragma HLS UNROLL
                            act_chunk[k] = pong_buf[b][k];
                            w_chunk[k] = weights_l3[n][b][k];
                        }
                        acc += simd_mac16(act_chunk, w_chunk);
                    }
                    // Linear logits (no ReLU on final classification layer)
                    out_buf[n] = rescale_linear(acc);
                }
                state = FSM_WRITE_OUTPUT;
                break;
            }

            case FSM_WRITE_OUTPUT: {
                // Write output logits to AXI bus
                WRITE_LOOP: for (int i = 0; i < OUTPUT_NODES; ++i) {
                    #pragma HLS PIPELINE II=1
                    out_vec[i] = out_buf[i];
                }
                state = FSM_DONE;
                break;
            }

            case FSM_DONE: {
                execution_active = false;
                break;
            }
        }
    }
}
