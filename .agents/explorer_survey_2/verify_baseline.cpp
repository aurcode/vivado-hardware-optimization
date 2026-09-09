#include <iostream>
#include <ap_fixed.h>
#include "../../hw/weights.h"
#include "../../hw/test_inputs.h"

int main() {
    int correct = 0;
    for (int s = 0; s < TEST_SAMPLE_COUNT; ++s) {
        custom_data_t a1[64];
        for (int j = 0; j < 64; ++j) {
            ap_fixed<22, 6, AP_RND, AP_SAT> sum1 = 0;
            for (int i = 0; i < 784; ++i) {
                sum1 += test_inputs[s][i] * weights_L1[j][i];
            }
            // ReLU
            if (sum1 > 0) {
                a1[j] = (custom_data_t)sum1;
            } else {
                a1[j] = 0;
            }
        }

        custom_data_t z2[10];
        for (int k = 0; k < 10; ++k) {
            ap_fixed<22, 6, AP_RND, AP_SAT> sum2 = 0;
            for (int j = 0; j < 64; ++j) {
                sum2 += a1[j] * weights_L2[k][j];
            }
            z2[k] = (custom_data_t)sum2;
        }

        int pred = 0;
        custom_data_t max_val = z2[0];
        for (int k = 1; k < 10; ++k) {
            if (z2[k] > max_val) {
                max_val = z2[k];
                pred = k;
            }
        }

        if (pred == test_labels[s]) {
            correct++;
        } else {
            std::cout << "Sample " << s << " MISMATCH: pred=" << pred << ", label=" << (int)test_labels[s] << std::endl;
        }
    }
    std::cout << "Accuracy: " << correct << " / " << TEST_SAMPLE_COUNT << " = " << (double)correct / TEST_SAMPLE_COUNT * 100.0 << "%" << std::endl;
    return 0;
}
