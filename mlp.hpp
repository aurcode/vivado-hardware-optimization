#ifndef MLP_HPP_
#define MLP_HPP_

// Architecture Dimensions
// 8 inputs -> 16 hidden neurons (ReLU) -> 4 output neurons
#define INPUT_NODES   8
#define HIDDEN_NODES  16
#define OUTPUT_NODES  4

// Data type definition
// Using float ensures synthesizability to DSP48 blocks on Zynq-7000 (xc7z020)
// and seamless native C++ compilation on host without external headers.
typedef float data_t;

// Top-level synthesizable function declaration
void mlp_accel(
    const data_t in_vec[INPUT_NODES],
    data_t out_vec[OUTPUT_NODES]
);

#endif // MLP_HPP_
