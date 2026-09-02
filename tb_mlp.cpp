#include <iostream>
#include <iomanip>
#include <cmath>
#include "mlp.hpp"
#include "golden_test_data.h"

int main() {
    std::cout << "==================================================================\n";
    std::cout << "  Starting MNIST MLP Hardware Accelerator Testbench Verification  \n";
    std::cout << "  Architecture: 784 -> 128 (ReLU) -> 64 (ReLU) -> 10 (Linear)     \n";
    std::cout << "  Arithmetic  : Fixed-Point Integer Scaling (16-bit POD Datapath) \n";
    std::cout << "  Hardware    : Time-Division Multiplexed (TDM) 16-SIMD Core      \n";
    std::cout << "==================================================================\n\n";

    int errors = 0;
    int correct_classifications = 0;
    const int TOLERANCE_LSB = 1; // Exactly bit-accurate within 1 LSB

    for (int t = 0; t < NUM_TEST_SAMPLES; ++t) {
        data_t hw_result[OUTPUT_NODES];

        // 1. Execute Hardware Accelerator Top-Level Function
        mlp_accel(golden_inputs[t], hw_result);

        // 2. Determine Predicted Class via Argmax
        int hw_pred = 0;
        data_t max_logit = hw_result[0];
        for (int k = 1; k < OUTPUT_NODES; ++k) {
            if (hw_result[k] > max_logit) {
                max_logit = hw_result[k];
                hw_pred = k;
            }
        }

        int true_label = golden_labels[t];
        bool class_match = (hw_pred == true_label);
        if (class_match) {
            correct_classifications++;
        }

        // 3. Compare Hardware Logits vs Bit-Accurate Golden Software Tensors
        int max_logit_diff = 0;
        for (int k = 0; k < OUTPUT_NODES; ++k) {
            int diff = std::abs((int)hw_result[k] - (int)golden_logits[t][k]);
            if (diff > max_logit_diff) {
                max_logit_diff = diff;
            }
        }

        std::cout << "[Test Sample " << std::setw(2) << (t + 1) << "/" << NUM_TEST_SAMPLES << "] "
                  << "Label: " << true_label << " | "
                  << "HW Pred: " << hw_pred << " | "
                  << "Max Logit Diff: " << std::setw(3) << max_logit_diff << " LSB"
                  << " --> " << (class_match ? "[MATCH]" : "[MISMATCH]");

        if (max_logit_diff > TOLERANCE_LSB) {
            std::cout << " [FAIL: Diff > " << TOLERANCE_LSB << " LSB]\n";
            errors++;
        } else {
            std::cout << " [PASS]\n";
        }
    }

    std::cout << "\n==================================================================\n";
    std::cout << "  Verification Summary:\n";
    std::cout << "  - Classification Accuracy : " << correct_classifications << "/" << NUM_TEST_SAMPLES 
              << " (" << (100.0f * correct_classifications / NUM_TEST_SAMPLES) << "%)\n";
    std::cout << "  - Logit Precision Errors  : " << errors << "\n";
    std::cout << "==================================================================\n";

    if (errors == 0 && correct_classifications >= (NUM_TEST_SAMPLES * 9 / 10)) {
        std::cout << "  LEVEL 1 VERIFICATION PASSED SUCCESSFULLY!\n";
        std::cout << "==================================================================\n";
        return 0; // Return 0 for Vivado HLS csim/cosim success
    } else {
        std::cerr << "  VERIFICATION FAILED!\n";
        std::cout << "==================================================================\n";
        return 1;
    }
}
