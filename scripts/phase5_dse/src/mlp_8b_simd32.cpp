#include <stdint.h>
#include "../headers/weights_mlp_8b_simd32.h"

#define INPUT_NODES   784
#define INPUT_PAD     800
#define L1_NODES      128
#define L2_NODES      64
#define OUTPUT_NODES  10

#define SIMD_WIDTH    32
#define L1_BLOCKS     25
#define L2_BLOCKS     4
#define L3_BLOCKS     2

#define RESCALE_SHIFT 6
#define RESCALE_ROUND 32

typedef int8_t data_t;
typedef int8_t weight_t;
typedef int32_t acc_t;

inline data_t rescale_and_relu(acc_t acc) {
    #pragma HLS INLINE
    acc_t rounded = (acc + RESCALE_ROUND) >> RESCALE_SHIFT;
    if (rounded <= 0) return 0;
    if (rounded > 127) return 127;
    return (data_t)rounded;
}

inline data_t rescale_linear(acc_t acc) {
    #pragma HLS INLINE
    acc_t rounded = (acc + RESCALE_ROUND) >> RESCALE_SHIFT;
    if (rounded > 127) return 127;
    if (rounded < -128) return -128;
    return (data_t)rounded;
}

inline acc_t simd_mac32(const data_t act[SIMD_WIDTH], const weight_t w[SIMD_WIDTH]) {
    #pragma HLS INLINE
    acc_t prod[SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=prod complete dim=1

    for (int k = 0; k < SIMD_WIDTH; ++k) {
        #pragma HLS UNROLL
        prod[k] = (acc_t)act[k] * (acc_t)w[k];
    }

    acc_t stage1[16];
    #pragma HLS ARRAY_PARTITION variable=stage1 complete dim=1
    for (int k = 0; k < 16; ++k) {
        #pragma HLS UNROLL
        stage1[k] = prod[2*k] + prod[2*k + 1];
    }

    acc_t stage2[8];
    #pragma HLS ARRAY_PARTITION variable=stage2 complete dim=1
    for (int k = 0; k < 8; ++k) {
        #pragma HLS UNROLL
        stage2[k] = stage1[2*k] + stage1[2*k + 1];
    }

    acc_t stage3[4];
    #pragma HLS ARRAY_PARTITION variable=stage3 complete dim=1
    for (int k = 0; k < 4; ++k) {
        #pragma HLS UNROLL
        stage3[k] = stage2[2*k] + stage2[2*k + 1];
    }

    acc_t stage4[2];
    #pragma HLS ARRAY_PARTITION variable=stage4 complete dim=1
    stage4[0] = stage3[0] + stage3[1];
    stage4[1] = stage3[2] + stage3[3];

    return stage4[0] + stage4[1];
}

void mlp_accel_8b32(const data_t in_vec[INPUT_NODES], data_t out_vec[OUTPUT_NODES]) {
    #pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=in_vec bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=out_vec bundle=CTRL_BUS

    data_t input_buf[L1_BLOCKS][SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=input_buf complete dim=2

    data_t ping_buf[L2_BLOCKS][SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=ping_buf complete dim=2

    data_t pong_buf[L3_BLOCKS][SIMD_WIDTH];
    #pragma HLS ARRAY_PARTITION variable=pong_buf complete dim=2

    data_t out_buf[OUTPUT_NODES];
    #pragma HLS ARRAY_PARTITION variable=out_buf complete dim=1

    #pragma HLS ARRAY_PARTITION variable=weights_l1_8b32 complete dim=3
    #pragma HLS ARRAY_PARTITION variable=weights_l2_8b32 complete dim=3
    #pragma HLS ARRAY_PARTITION variable=weights_l3_8b32 complete dim=3

    // Load with zero padding up to 800
    for (int b = 0; b < L1_BLOCKS; ++b) {
        #pragma HLS PIPELINE II=1
        for (int k = 0; k < SIMD_WIDTH; ++k) {
            #pragma HLS UNROLL
            int idx = b * SIMD_WIDTH + k;
            input_buf[b][k] = (idx < INPUT_NODES) ? in_vec[idx] : (data_t)0;
        }
    }

    // Layer 1
    L1_LOOP: for (int n = 0; n < L1_NODES; ++n) {
        acc_t acc = 0;
        L1_BLOCKS_LOOP: for (int b = 0; b < L1_BLOCKS; ++b) {
            #pragma HLS PIPELINE II=1
            data_t act_chunk[SIMD_WIDTH];
            weight_t w_chunk[SIMD_WIDTH];
            #pragma HLS ARRAY_PARTITION variable=act_chunk complete dim=1
            #pragma HLS ARRAY_PARTITION variable=w_chunk complete dim=1
            for (int k = 0; k < SIMD_WIDTH; ++k) {
                #pragma HLS UNROLL
                act_chunk[k] = input_buf[b][k];
                w_chunk[k] = weights_l1_8b32[n][b][k];
            }
            acc += simd_mac32(act_chunk, w_chunk);
        }
        ping_buf[n / SIMD_WIDTH][n % SIMD_WIDTH] = rescale_and_relu(acc);
    }

    // Layer 2
    L2_LOOP: for (int n = 0; n < L2_NODES; ++n) {
        acc_t acc = 0;
        L2_BLOCKS_LOOP: for (int b = 0; b < L2_BLOCKS; ++b) {
            #pragma HLS PIPELINE II=1
            data_t act_chunk[SIMD_WIDTH];
            weight_t w_chunk[SIMD_WIDTH];
            #pragma HLS ARRAY_PARTITION variable=act_chunk complete dim=1
            #pragma HLS ARRAY_PARTITION variable=w_chunk complete dim=1
            for (int k = 0; k < SIMD_WIDTH; ++k) {
                #pragma HLS UNROLL
                act_chunk[k] = ping_buf[b][k];
                w_chunk[k] = weights_l2_8b32[n][b][k];
            }
            acc += simd_mac32(act_chunk, w_chunk);
        }
        pong_buf[n / SIMD_WIDTH][n % SIMD_WIDTH] = rescale_and_relu(acc);
    }

    // Layer 3
    L3_LOOP: for (int n = 0; n < OUTPUT_NODES; ++n) {
        acc_t acc = 0;
        L3_BLOCKS_LOOP: for (int b = 0; b < L3_BLOCKS; ++b) {
            #pragma HLS PIPELINE II=1
            data_t act_chunk[SIMD_WIDTH];
            weight_t w_chunk[SIMD_WIDTH];
            #pragma HLS ARRAY_PARTITION variable=act_chunk complete dim=1
            #pragma HLS ARRAY_PARTITION variable=w_chunk complete dim=1
            for (int k = 0; k < SIMD_WIDTH; ++k) {
                #pragma HLS UNROLL
                act_chunk[k] = pong_buf[b][k];
                w_chunk[k] = weights_l3_8b32[n][b][k];
            }
            acc += simd_mac32(act_chunk, w_chunk);
        }
        out_buf[n] = rescale_linear(acc);
    }

    // Write Out
    for (int i = 0; i < OUTPUT_NODES; ++i) {
        #pragma HLS PIPELINE II=1
        out_vec[i] = out_buf[i];
    }
}
