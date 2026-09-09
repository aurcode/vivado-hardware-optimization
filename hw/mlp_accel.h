#ifndef MLP_ACCEL_H
#define MLP_ACCEL_H

#include <ap_fixed.h>

// ============================================================================
// Fixed-Point Numerical Representation (Matching hw/weights.h)
// ap_fixed<11, 3, AP_RND, AP_SAT>:
//   Total Width (W)  = 11 bits
//   Integer Bits (I) = 3 bits (1 sign bit + 2 magnitude bits)
//   Fractional Bits  = 8 bits (Q3.8 format, resolution delta = 1/256 = 0.00390625)
//   Dynamic Range    = [-4.0, +3.99609375]
//   Rounding Mode    = AP_RND
//   Overflow Mode    = AP_SAT
// ============================================================================
typedef ap_fixed<11, 3, AP_RND, AP_SAT> custom_data_t;

// Accumulator Precision:
// Product of two ap_fixed<11, 3> produces up to 6 integer bits and 16 fractional bits.
// Accumulating up to 784 terms across a layer requires headroom:
// 24 bits with 8 integer bits and 16 fractional bits guarantees zero intermediate saturation.
typedef ap_fixed<24, 8, AP_RND, AP_SAT> acc_t;

// ============================================================================
// MLP Topology Dimensions (784-64-10 Architecture Without Bias)
// ============================================================================
#define INPUT_NODES   784
#define L1_NODES      64
#define OUTPUT_NODES  10

// Hardware TDM SIMD Parallelism Factor
#define SIMD_WIDTH    16
#define L1_BLOCKS     (INPUT_NODES / SIMD_WIDTH)  // 784 / 16 = 49 blocks
#define L2_BLOCKS     (L1_NODES / SIMD_WIDTH)     // 64 / 16 = 4 blocks

// ============================================================================
// Compute Core & Top-Level Interface Declarations
// ============================================================================

// Single 16-way SIMD MAC compute core with balanced adder reduction tree
// #pragma HLS INLINE OFF in implementation guarantees single instance reuse
void simd_mac16(
    const custom_data_t act[SIMD_WIDTH],
    const custom_data_t wt[SIMD_WIDTH],
    acc_t &acc
);

// Top-level synthesizable accelerator
void mlp_accel(
    const custom_data_t input_img[INPUT_NODES],
    unsigned char *pred_digit
);

#endif // MLP_ACCEL_H
