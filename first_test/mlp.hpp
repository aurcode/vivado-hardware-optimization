#ifndef MLP_HPP_
#define MLP_HPP_

#include <stdint.h>

// =============================================================================
// Track A Architecture Dimensions (MNIST 28x28)
// 784 Inputs -> 128 Hidden (ReLU) -> 64 Hidden (ReLU) -> 10 Outputs (Logits)
// =============================================================================
#define INPUT_NODES   784
#define L1_NODES      128
#define L2_NODES      64
#define OUTPUT_NODES  10

// Hardware TDM (Time-Division Multiplexing) SIMD Factor
// 16-way parallel MAC array reused across all three network layers
#define SIMD_WIDTH    16
#define L1_BLOCKS     (INPUT_NODES / SIMD_WIDTH) // 49 blocks
#define L2_BLOCKS     (L1_NODES / SIMD_WIDTH)    // 8 blocks
#define L3_BLOCKS     (L2_NODES / SIMD_WIDTH)    // 4 blocks

// =============================================================================
// Custom Fixed-Point Integer Scaling Specifications
// Strictly adhering to "No Floating-Point Logic" rule
// Activations have 10 fractional bits (scale 2^10 = 1024)
// Weights have 14 fractional bits (scale 2^14 = 16384)
// Multiplier products have 24 fractional bits (scale 2^24)
// Rescaling: right shift by 14 bits (>> 14) with midpoint rounding (+ 8192)
// =============================================================================
#define ACT_SCALE_BITS    10
#define WEIGHT_SCALE_BITS 14
#define PROD_SCALE_BITS   (ACT_SCALE_BITS + WEIGHT_SCALE_BITS) // 24
#define RESCALE_SHIFT     14
#define RESCALE_ROUND     (1 << (RESCALE_SHIFT - 1))          // 8192 (0.5 LSB)

typedef int16_t data_t;
typedef int16_t weight_t;
typedef int32_t acc_t;

// =============================================================================
// Top-Level Synthesizable Accelerator Function Declaration
// =============================================================================
void mlp_accel(
    const data_t in_vec[INPUT_NODES],
    data_t out_vec[OUTPUT_NODES]
);

#endif // MLP_HPP_
