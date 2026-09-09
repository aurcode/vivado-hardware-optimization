#include "mlp_accel.h"
#include "weights.h"

// ============================================================================
// 16-Way SIMD MAC Compute Core with Balanced Binary Adder Tree
// #pragma HLS INLINE OFF forces Vivado HLS to instantiate exactly ONE physical
// instance of this module, reused by both FC1 and FC2 (proving hardware reuse).
// ============================================================================
void simd_mac16(
    const custom_data_t act[SIMD_WIDTH],
    const custom_data_t wt[SIMD_WIDTH],
    acc_t &acc
) {
    #pragma HLS INLINE OFF

    acc_t prod[SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=prod complete dim=1

    // Stage 0: 16 parallel DSP multiplications
    SIMD_MUL: for (int k = 0; k < SIMD_WIDTH; ++k) {
        #pragma HLS UNROLL
        prod[k] = (acc_t)act[k] * (acc_t)wt[k];
    }

    // Stage 1: Balanced adder tree Level 1 (8 adders)
    acc_t stage1[8];
    #pragma HLS ARRAY_PARTITION variable=stage1 complete dim=1
    TREE_L1: for (int k = 0; k < 8; ++k) {
        #pragma HLS UNROLL
        stage1[k] = prod[2 * k] + prod[2 * k + 1];
    }

    // Stage 2: Balanced adder tree Level 2 (4 adders)
    acc_t stage2[4];
    #pragma HLS ARRAY_PARTITION variable=stage2 complete dim=1
    TREE_L2: for (int k = 0; k < 4; ++k) {
        #pragma HLS UNROLL
        stage2[k] = stage1[2 * k] + stage1[2 * k + 1];
    }

    // Stage 3: Balanced adder tree Level 3 (2 adders)
    acc_t stage3[2];
    #pragma HLS ARRAY_PARTITION variable=stage3 complete dim=1
    stage3[0] = stage2[0] + stage2[1];
    stage3[1] = stage2[2] + stage2[3];

    // Stage 4: Balanced adder tree Level 4 (1 final adder) + loop accumulator
    acc_t tree_sum = stage3[0] + stage3[1];
    acc += tree_sum;
}

// ============================================================================
// Top-Level Synthesizable Accelerator: mlp_accel
// Implements sequential TDM FSM: FC1 (3136 cycles) -> ReLU -> FC2 (40 cycles) -> Argmax
// ============================================================================
void mlp_accel(
    const custom_data_t input_img[INPUT_NODES],
    unsigned char *pred_digit
) {
    // AXI4-Lite Control and Memory-Mapped Interfaces for Zynq PS-PL Integration
    #pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=input_img bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=pred_digit bundle=CTRL_BUS

    // Local On-Chip Memory Buffers
    custom_data_t in_buf[INPUT_NODES];
    #pragma HLS ARRAY_PARTITION variable=in_buf cyclic factor=16 dim=1

    custom_data_t l1_act[L1_NODES];
    #pragma HLS ARRAY_PARTITION variable=l1_act cyclic factor=16 dim=1

    custom_data_t l2_logits[OUTPUT_NODES];
    #pragma HLS ARRAY_PARTITION variable=l2_logits complete dim=1

    // Step 1: Buffer input image from AXI bus
    LOAD_INP: for (int i = 0; i < INPUT_NODES; ++i) {
        #pragma HLS PIPELINE II=1
        in_buf[i] = input_img[i];
    }

    // Step 2: FC1 Layer (784 -> 64) via TDM Reuse of simd_mac16
    // 64 hidden neurons x (784/16 = 49 chunks) = 3,136 compute cycles
    FC1_NEURONS: for (int n = 0; n < L1_NODES; ++n) {
        acc_t acc = 0;
        FC1_CHUNKS: for (int b = 0; b < L1_BLOCKS; ++b) {
            #pragma HLS PIPELINE II=1
            custom_data_t act_chunk[SIMD_WIDTH];
            custom_data_t wt_chunk[SIMD_WIDTH];
            #pragma HLS ARRAY_PARTITION variable=act_chunk complete dim=1
            #pragma HLS ARRAY_PARTITION variable=wt_chunk complete dim=1

            for (int k = 0; k < SIMD_WIDTH; ++k) {
                #pragma HLS UNROLL
                act_chunk[k] = in_buf[b * SIMD_WIDTH + k];
                wt_chunk[k] = weights_L1[n][b * SIMD_WIDTH + k];
            }
            simd_mac16(act_chunk, wt_chunk, acc);
        }

        // Sign-bit ReLU activation
        if (acc < 0) {
            l1_act[n] = 0;
        } else {
            l1_act[n] = (custom_data_t)acc;
        }
    }

    // Step 3: FC2 Layer (64 -> 10) via TDM Reuse of EXACT SAME simd_mac16 core
    // 10 output classes x (64/16 = 4 chunks) = 40 compute cycles
    FC2_CLASSES: for (int c = 0; c < OUTPUT_NODES; ++c) {
        acc_t acc = 0;
        FC2_CHUNKS: for (int b = 0; b < L2_BLOCKS; ++b) {
            #pragma HLS PIPELINE II=1
            custom_data_t act_chunk[SIMD_WIDTH];
            custom_data_t wt_chunk[SIMD_WIDTH];
            #pragma HLS ARRAY_PARTITION variable=act_chunk complete dim=1
            #pragma HLS ARRAY_PARTITION variable=wt_chunk complete dim=1

            for (int k = 0; k < SIMD_WIDTH; ++k) {
                #pragma HLS UNROLL
                act_chunk[k] = l1_act[b * SIMD_WIDTH + k];
                wt_chunk[k] = weights_L2[c][b * SIMD_WIDTH + k];
            }
            simd_mac16(act_chunk, wt_chunk, acc);
        }
        // Linear classification logits
        l2_logits[c] = (custom_data_t)acc;
    }

    // Step 4: 10-Way Parallel Argmax with Deterministic Tie-Breaking
    unsigned char best_digit = 0;
    custom_data_t max_val = l2_logits[0];
    ARGMAX_TREE: for (int c = 1; c < OUTPUT_NODES; ++c) {
        #pragma HLS UNROLL
        if (l2_logits[c] > max_val) {
            max_val = l2_logits[c];
            best_digit = (unsigned char)c;
        }
    }
    *pred_digit = best_digit;
}
