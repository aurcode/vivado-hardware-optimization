#include <iostream>
#include <iomanip>
#include <cmath>
#include "mlp.hpp"

// Golden software reference model for validation
void mlp_golden_ref(const data_t in[INPUT_NODES], data_t out[OUTPUT_NODES]) {
    // Replicate same weights/biases
    static const data_t w1[HIDDEN_NODES][INPUT_NODES] = {
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
    static const data_t b1[HIDDEN_NODES] = {
        0.05f, -0.02f, 0.08f, -0.04f, 0.01f, 0.07f, -0.06f, 0.03f,
        -0.01f, 0.04f, -0.03f, 0.06f, -0.05f, 0.02f, -0.07f, 0.09f
    };
    static const data_t w2[OUTPUT_NODES][HIDDEN_NODES] = {
        { 0.15f, -0.22f,  0.31f, -0.14f,  0.28f, -0.09f,  0.18f,  0.25f,
         -0.30f,  0.12f, -0.17f,  0.21f,  0.08f, -0.26f,  0.34f, -0.11f},
        {-0.19f,  0.35f, -0.12f,  0.27f, -0.16f,  0.33f, -0.21f,  0.14f,
          0.22f, -0.31f,  0.15f, -0.08f,  0.29f,  0.17f, -0.25f,  0.19f},
        { 0.28f, -0.11f,  0.24f,  0.30f, -0.20f,  0.15f,  0.36f, -0.18f,
          0.11f,  0.26f, -0.29f,  0.13f, -0.22f,  0.31f,  0.07f, -0.24f},
        {-0.25f,  0.18f, -0.33f,  0.09f,  0.24f, -0.28f,  0.12f,  0.30f,
         -0.14f,  0.19f,  0.27f, -0.32f,  0.16f, -0.10f,  0.23f,  0.35f}
    };
    static const data_t b2[OUTPUT_NODES] = {
        0.02f, -0.05f, 0.03f, -0.01f
    };

    data_t h[HIDDEN_NODES];
    for (int j = 0; j < HIDDEN_NODES; ++j) {
        data_t sum = b1[j];
        for (int i = 0; i < INPUT_NODES; ++i) {
            sum += w1[j][i] * in[i];
        }
        h[j] = (sum > 0.0f) ? sum : 0.0f;
    }

    for (int k = 0; k < OUTPUT_NODES; ++k) {
        data_t sum = b2[k];
        for (int j = 0; j < HIDDEN_NODES; ++j) {
            sum += w2[k][j] * h[j];
        }
        out[k] = sum;
    }
}

int main() {
    std::cout << "========================================================\n";
    std::cout << "  Starting MLP Accelerator Testbench Verification       \n";
    std::cout << "========================================================\n";

    const int NUM_TESTS = 3;
    const data_t test_inputs[NUM_TESTS][INPUT_NODES] = {
        {0.5f, -0.2f,  0.8f,  0.1f, -0.4f,  0.6f, -0.1f,  0.3f},
        {1.0f,  0.0f, -0.5f,  0.7f,  0.2f, -0.8f,  0.4f, -0.6f},
        {-0.3f, 0.9f,  0.1f, -0.7f,  0.5f,  0.0f, -0.2f,  0.8f}
    };

    int errors = 0;
    const float TOLERANCE = 1e-4f;

    for (int t = 0; t < NUM_TESTS; ++t) {
        data_t hw_result[OUTPUT_NODES];
        data_t sw_result[OUTPUT_NODES];

        // Run Hardware Accelerator implementation
        mlp_accel(test_inputs[t], hw_result);

        // Run Golden Software reference model
        mlp_golden_ref(test_inputs[t], sw_result);

        std::cout << "\n[Test Case " << (t + 1) << "]\n";
        bool test_passed = true;
        for (int k = 0; k < OUTPUT_NODES; ++k) {
            float diff = std::fabs(hw_result[k] - sw_result[k]);
            std::cout << "  Output[" << k << "]: HW = " << std::setw(9) << std::fixed << std::setprecision(5) << hw_result[k]
                      << " | SW = " << std::setw(9) << sw_result[k]
                      << " | Diff = " << diff;
            if (diff > TOLERANCE) {
                std::cout << " --> [FAIL]\n";
                test_passed = false;
                errors++;
            } else {
                std::cout << " --> [PASS]\n";
            }
        }

        if (test_passed) {
            std::cout << ">> Test Case " << (t + 1) << " PASSED.\n";
        } else {
            std::cout << ">> Test Case " << (t + 1) << " FAILED.\n";
        }
    }

    std::cout << "\n========================================================\n";
    if (errors == 0) {
        std::cout << "  ALL TEST CASES PASSED! Verification Successful.   \n";
        std::cout << "========================================================\n";
        return 0; // Return 0 to indicate SUCCESS to Vivado HLS
    } else {
        std::cout << "  VERIFICATION FAILED with " << errors << " error(s)! \n";
        std::cout << "========================================================\n";
        return 1; // Return non-zero to fail the build in Vivado HLS
    }
}
