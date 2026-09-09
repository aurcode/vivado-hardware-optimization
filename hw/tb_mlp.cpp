#include <iostream>
#include <iomanip>
#include "mlp_accel.h"
#include "test_inputs.h"

int main() {
    std::cout << "==================================================================\n";
    std::cout << "  Starting 784-64-10 MLP Hardware Accelerator Testbench           \n";
    std::cout << "  Precision : ap_fixed<11, 3, AP_RND, AP_SAT> (Q3.8 format)        \n";
    std::cout << "  Datapath  : 16-way SIMD MAC (Balanced Tree, TDM Reused Core)   \n";
    std::cout << "  Topology  : 784 Inputs -> 64 Hidden (ReLU) -> 10 Logits (Argmax)\n";
    std::cout << "==================================================================\n\n";

    int correct = 0;
    int total_samples = TEST_SAMPLE_COUNT;

    for (int t = 0; t < total_samples; ++t) {
        unsigned char pred = 0;
        mlp_accel(test_inputs[t], &pred);

        unsigned char actual = test_labels[t];
        bool is_match = (pred == actual);
        if (is_match) {
            correct++;
        }

        std::cout << "  [Sample " << std::setw(3) << (t + 1) << "] "
                  << "Ground Truth: " << (int)actual << " | Predicted: " << (int)pred
                  << " --> " << (is_match ? "[PASS]" : "[FAIL]") << "\n";
    }

    float accuracy = (100.0f * correct) / total_samples;
    std::cout << "\n==================================================================\n";
    std::cout << "  Verification Summary:\n";
    std::cout << "  Total Samples Tested: " << total_samples << "\n";
    std::cout << "  Correct Classifications: " << correct << "\n";
    std::cout << "  Measured Accuracy: " << std::fixed << std::setprecision(2) << accuracy << "%\n";
    std::cout << "  Specification Minimum: >= 90.00% (Baseline Target: 97.00%)\n";
    std::cout << "==================================================================\n";

    if (accuracy >= 90.0f) {
        std::cout << ">>> ACCELERATOR HARDWARE VERIFICATION PASSED SUCCESSFULLY! <<<\n\n";
        return 0;
    } else {
        std::cerr << ">>> ERROR: ACCURACY BELOW THRESHOLD (" << accuracy << "% < 90.00%) <<<\n\n";
        return 1;
    }
}
