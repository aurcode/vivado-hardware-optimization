#include <iostream>
#include <iomanip>
#include <cmath>
#include "mlp.hpp"
#include "golden_test_data.h"
#include "realworld_test_data.h"

int main() {
    std::cout << "==================================================================\n";
    std::cout << "  Starting MNIST MLP Hardware Accelerator Testbench Verification  \n";
    std::cout << "  Architecture: 784 -> 128 (ReLU) -> 64 (ReLU) -> 10 (Linear)     \n";
    std::cout << "  Arithmetic  : Fixed-Point Integer Scaling (16-bit POD Datapath) \n";
    std::cout << "  Hardware    : Time-Division Multiplexed (TDM) 16-SIMD Core      \n";
    std::cout << "==================================================================\n\n";

    // -------------------------------------------------------------------------
    // PART 1: Level 1 Standard MNIST Dataset Verification
    // -------------------------------------------------------------------------
    std::cout << "--- [PART 1: Level 1 Standard MNIST Verification (20 Samples)] ---\n";
    int errors_l1 = 0;
    int correct_l1 = 0;
    const int TOLERANCE_LSB = 1;

    for (int t = 0; t < NUM_TEST_SAMPLES; ++t) {
        data_t hw_result[OUTPUT_NODES];
        mlp_accel(golden_inputs[t], hw_result);

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
            correct_l1++;
        }

        int max_logit_diff = 0;
        for (int k = 0; k < OUTPUT_NODES; ++k) {
            int diff = std::abs((int)hw_result[k] - (int)golden_logits[t][k]);
            if (diff > max_logit_diff) {
                max_logit_diff = diff;
            }
        }

        std::cout << "  [MNIST Sample " << std::setw(2) << (t + 1) << "] "
                  << "Label: " << true_label << " | Pred: " << hw_pred
                  << " | Diff: " << max_logit_diff << " LSB --> "
                  << (class_match ? "[MATCH]" : "[MISMATCH]")
                  << (max_logit_diff <= TOLERANCE_LSB ? " [PASS]\n" : " [FAIL]\n");
        if (max_logit_diff > TOLERANCE_LSB) {
            errors_l1++;
        }
    }

    // -------------------------------------------------------------------------
    // PART 2: Level 2 Real-World Camera & Handwriting Preprocessed Dataset
    // -------------------------------------------------------------------------
    std::cout << "\n--- [PART 2: Level 2 Real-World Handwritten Verification (20 Samples)] ---\n";
    int correct_realworld = 0;
    for (int t = 0; t < NUM_REALWORLD_SAMPLES; ++t) {
        data_t hw_result[OUTPUT_NODES];
        mlp_accel(realworld_inputs[t], hw_result);

        int hw_pred = 0;
        data_t max_logit = hw_result[0];
        for (int k = 1; k < OUTPUT_NODES; ++k) {
            if (hw_result[k] > max_logit) {
                max_logit = hw_result[k];
                hw_pred = k;
            }
        }

        int true_label = realworld_labels[t];
        bool class_match = (hw_pred == true_label);
        if (class_match) {
            correct_realworld++;
        }

        std::cout << "  [RealWorld " << std::setw(2) << (t + 1) << "] "
                  << "Label: " << true_label << " | Pred: " << hw_pred
                  << " | SoftPred: " << realworld_preds[t]
                  << " --> " << (class_match ? "[MATCH PASS]\n" : "[MISMATCH]\n");
    }

    float acc_l1 = 100.0f * correct_l1 / NUM_TEST_SAMPLES;
    float acc_rw = 100.0f * correct_realworld / NUM_REALWORLD_SAMPLES;

    std::cout << "\n==================================================================\n";
    std::cout << "  Verification Summary:\n";
    std::cout << "  - Level 1 MNIST Accuracy     : " << correct_l1 << "/" << NUM_TEST_SAMPLES << " (" << acc_l1 << "%)\n";
    std::cout << "  - Level 2 Real-World Accuracy: " << correct_realworld << "/" << NUM_REALWORLD_SAMPLES << " (" << acc_rw << "%)\n";
    std::cout << "  - Bit-Accurate Logit Errors  : " << errors_l1 << "\n";
    std::cout << "==================================================================\n";

    if (errors_l1 == 0 && acc_l1 >= 90.0f && acc_rw >= 85.0f) {
        std::cout << "  LEVEL 1 & LEVEL 2 VERIFICATION PASSED SUCCESSFULLY!\n";
        std::cout << "==================================================================\n";
        return 0; // Return 0 for Vivado HLS csim/cosim success
    } else {
        std::cerr << "  VERIFICATION FAILED!\n";
        std::cout << "==================================================================\n";
        return 1;
    }
}
