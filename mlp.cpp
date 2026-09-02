#include "mlp.hpp"

// Layer 1 Weights [16 hidden neurons x 8 inputs]
static const data_t weights_l1[HIDDEN_NODES][INPUT_NODES] = {
    { 0.25f, -0.15f,  0.30f,  0.10f, -0.05f,  0.18f,  0.22f, -0.12f},
    {-0.18f,  0.42f, -0.11f,  0.29f,  0.33f, -0.21f,  0.15f,  0.08f},
    { 0.31f,  0.05f, -0.45f,  0.12f,  0.28f,  0.39f, -0.17f,  0.21f},
    {-0.09f, -0.22f,  0.19f,  0.51f, -0.14f,  0.07f,  0.32f, -0.25f},
    { 0.14f,  0.35f,  0.27f, -0.18f,  0.40f, -0.31f,  0.11f,  0.05f},
    {-0.27f,  0.16f, -0.32f,  0.24f, -0.19f,  0.44f, -0.08f,  0.36f},
    { 0.45f, -0.08f,  0.13f, -0.37f,  0.22f,  0.16f, -0.29f,  0.14f},
    { 0.08f,  0.29f, -0.21f,  0.15f, -0.36f,  0.25f,  0.41f, -0.19f},
    {-0.33f, -0.14f,  0.40f,  0.09f,  0.17f, -0.28f,  0.23f,  0.31f},
    { 0.19f,  0.23f, -0.07f, -0.42f,  0.31f,  0.12f, -0.15f, -0.22f},
    { 0.28f, -0.31f,  0.16f,  0.20f, -0.25f,  0.34f,  0.09f,  0.18f},
    {-0.12f,  0.18f,  0.35f, -0.11f,  0.08f, -0.16f,  0.27f, -0.30f},
    { 0.37f,  0.04f, -0.29f,  0.33f, -0.18f,  0.21f, -0.40f,  0.15f},
    {-0.21f, -0.38f,  0.12f, -0.05f,  0.29f,  0.17f,  0.35f, -0.11f},
    { 0.16f,  0.27f, -0.19f,  0.38f, -0.22f, -0.09f,  0.14f,  0.26f},
    {-0.40f,  0.11f,  0.25f, -0.29f,  0.13f,  0.30f, -0.18f, -0.07f}
};

// Layer 1 Biases [16 hidden neurons]
static const data_t bias_l1[HIDDEN_NODES] = {
    0.05f, -0.02f, 0.08f, -0.04f, 0.01f, 0.07f, -0.06f, 0.03f,
    -0.01f, 0.04f, -0.03f, 0.06f, -0.05f, 0.02f, -0.07f, 0.09f
};

// Layer 2 Weights [4 output neurons x 16 hidden inputs]
static const data_t weights_l2[OUTPUT_NODES][HIDDEN_NODES] = {
    { 0.15f, -0.22f,  0.31f, -0.14f,  0.28f, -0.09f,  0.18f,  0.25f,
     -0.30f,  0.12f, -0.17f,  0.21f,  0.08f, -0.26f,  0.34f, -0.11f},
    {-0.19f,  0.35f, -0.12f,  0.27f, -0.16f,  0.33f, -0.21f,  0.14f,
      0.22f, -0.31f,  0.15f, -0.08f,  0.29f,  0.17f, -0.25f,  0.19f},
    { 0.28f, -0.11f,  0.24f,  0.30f, -0.20f,  0.15f,  0.36f, -0.18f,
      0.11f,  0.26f, -0.29f,  0.13f, -0.22f,  0.31f,  0.07f, -0.24f},
    {-0.25f,  0.18f, -0.33f,  0.09f,  0.24f, -0.28f,  0.12f,  0.30f,
     -0.14f,  0.19f,  0.27f, -0.32f,  0.16f, -0.10f,  0.23f,  0.35f}
};

// Layer 2 Biases [4 output neurons]
static const data_t bias_l2[OUTPUT_NODES] = {
    0.02f, -0.05f, 0.03f, -0.01f
};

// Top-level synthesizable function
void mlp_accel(
    const data_t in_vec[INPUT_NODES],
    data_t out_vec[OUTPUT_NODES]
) {
    // Vivado HLS Interface Directives
    // Maps function control and data ports to an AXI4-Lite slave interface
    // compatible with Zynq Processing System (PS)
    #pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=in_vec bundle=CTRL_BUS
    #pragma HLS INTERFACE s_axilite port=out_vec bundle=CTRL_BUS

    // Partition input array registers for parallel access
    #pragma HLS ARRAY_PARTITION variable=in_vec complete dim=1
    #pragma HLS ARRAY_PARTITION variable=out_vec complete dim=1

    // Intermediate hidden layer buffer
    data_t hidden_layer[HIDDEN_NODES];
    #pragma HLS ARRAY_PARTITION variable=hidden_layer complete dim=1

    // =========================================================================
    // Layer 1: Dense Matrix Multiplication + ReLU Activation
    // =========================================================================
    L1_NEURON: for (int h = 0; h < HIDDEN_NODES; ++h) {
        #pragma HLS PIPELINE II=1
        data_t acc = bias_l1[h];
        L1_ACC: for (int i = 0; i < INPUT_NODES; ++i) {
            #pragma HLS UNROLL
            acc += weights_l1[h][i] * in_vec[i];
        }
        // ReLU activation: f(x) = max(0, x)
        hidden_layer[h] = (acc > 0.0f) ? acc : 0.0f;
    }

    // =========================================================================
    // Layer 2: Output Dense Layer (Linear)
    // =========================================================================
    L2_NEURON: for (int o = 0; o < OUTPUT_NODES; ++o) {
        #pragma HLS PIPELINE II=1
        data_t acc = bias_l2[o];
        L2_ACC: for (int h = 0; h < HIDDEN_NODES; ++h) {
            #pragma HLS UNROLL
            acc += weights_l2[o][h] * hidden_layer[h];
        }
        out_vec[o] = acc;
    }
}
