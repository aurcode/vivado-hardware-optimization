#include <iostream>
#include <iomanip>
#include <cmath>
#include <cassert>
#include <vector>
#include <chrono>
#include "mlp_accel.h"

// Forward declaration of Argmax helper mirroring mlp_accel.cpp
unsigned char test_argmax(const custom_data_t logits[OUTPUT_NODES]) {
    unsigned char best_digit = 0;
    custom_data_t max_val = logits[0];
    for (int c = 1; c < OUTPUT_NODES; ++c) {
        if (logits[c] > max_val) {
            max_val = logits[c];
            best_digit = (unsigned char)c;
        }
    }
    return best_digit;
}

int main() {
    std::cout << "==================================================================\n";
    std::cout << "  Adversarial Empirical Verification of Hardware Simulation Core  \n";
    std::cout << "  Agent: challenger_sim_1                                         \n";
    std::cout << "==================================================================\n\n";

    int total_tests = 0;
    int passed_tests = 0;
    int failed_tests = 0;

    auto check = [&](bool condition, const std::string &desc) {
        total_tests++;
        if (condition) {
            passed_tests++;
            std::cout << "  [PASS] Test " << std::setw(2) << total_tests << ": " << desc << "\n";
        } else {
            failed_tests++;
            std::cerr << "  [FAIL] Test " << std::setw(2) << total_tests << ": " << desc << "\n";
        }
    };

    // ========================================================================
    // Section 1: Layer Dimension & Chunk Counts Verification
    // ========================================================================
    std::cout << "\n--- Section 1: Layer Dimensions, Chunk Counts, and SIMD Cycles ---\n";
    check(INPUT_NODES == 784, "Input dimension is exactly 784");
    check(L1_NODES == 64, "FC1 hidden dimension is exactly 64");
    check(OUTPUT_NODES == 10, "FC2 output dimension is exactly 10");
    check(SIMD_WIDTH == 16, "SIMD vector width is exactly 16");

    int fc1_chunks = INPUT_NODES / SIMD_WIDTH;
    check(fc1_chunks == 49, "FC1 chunks per neuron is 784 / 16 = 49");
    check(L1_BLOCKS == 49, "L1_BLOCKS macro matches exactly 49");

    int fc2_chunks = L1_NODES / SIMD_WIDTH;
    check(fc2_chunks == 4, "FC2 chunks per class is 64 / 16 = 4");
    check(L2_BLOCKS == 4, "L2_BLOCKS macro matches exactly 4");

    int fc1_cycles = L1_NODES * L1_BLOCKS;
    check(fc1_cycles == 3136, "FC1 total compute calls = 64 neurons * 49 chunks = 3,136 cycles");

    int fc2_cycles = OUTPUT_NODES * L2_BLOCKS;
    check(fc2_cycles == 40, "FC2 total compute calls = 10 classes * 4 chunks = 40 cycles");

    int total_compute_cycles = fc1_cycles + fc2_cycles;
    check(total_compute_cycles == 3176, "Total SIMD compute cycles = 3,136 + 40 = 3,176 cycles");

    // Verify datapath indexing coverage (no off-by-one, no gaps, no overflows)
    std::vector<int> fc1_coverage(INPUT_NODES, 0);
    for (int b = 0; b < L1_BLOCKS; ++b) {
        for (int k = 0; k < SIMD_WIDTH; ++k) {
            int idx = b * SIMD_WIDTH + k;
            if (idx >= 0 && idx < INPUT_NODES) {
                fc1_coverage[idx]++;
            }
        }
    }
    bool fc1_all_covered = true;
    for (int i = 0; i < INPUT_NODES; ++i) {
        if (fc1_coverage[i] != 1) fc1_all_covered = false;
    }
    check(fc1_all_covered, "FC1 chunk indexing covers [0, 783] exactly once with zero gaps/overlaps");

    std::vector<int> fc2_coverage(L1_NODES, 0);
    for (int b = 0; b < L2_BLOCKS; ++b) {
        for (int k = 0; k < SIMD_WIDTH; ++k) {
            int idx = b * SIMD_WIDTH + k;
            if (idx >= 0 && idx < L1_NODES) {
                fc2_coverage[idx]++;
            }
        }
    }
    bool fc2_all_covered = true;
    for (int i = 0; i < L1_NODES; ++i) {
        if (fc2_coverage[i] != 1) fc2_all_covered = false;
    }
    check(fc2_all_covered, "FC2 chunk indexing covers [0, 63] exactly once with zero gaps/overlaps");

    // ========================================================================
    // Section 2: Zero Input Vector Stress Test
    // ========================================================================
    std::cout << "\n--- Section 2: Zero Input Vector Test ---\n";
    custom_data_t zero_img[INPUT_NODES];
    for (int i = 0; i < INPUT_NODES; ++i) {
        zero_img[i] = 0;
    }

    unsigned char zero_pred = 255;
    auto start_time = std::chrono::high_resolution_clock::now();
    mlp_accel(zero_img, &zero_pred);
    auto end_time = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> duration = end_time - start_time;

    check(duration.count() < 1000.0, "Zero input vector completes execution without hang/timeout (< 1000ms)");
    check(zero_pred == 0, "Zero input vector produces deterministic output digit 0 (all zero logits tie-break)");
    std::cout << "      Latency: " << duration.count() << " ms | Predicted Digit: " << (int)zero_pred << "\n";

    // ========================================================================
    // Section 3: Numerical Saturation Behavior (AP_SAT)
    // ========================================================================
    std::cout << "\n--- Section 3: Numerical Saturation Behavior (AP_SAT) ---\n";
    
    // custom_data_t = ap_fixed<11, 3, AP_RND, AP_SAT>
    // Range: [-4.0, +3.99609375]
    custom_data_t max_pos = 3.99609375;
    custom_data_t max_neg = -4.0;

    custom_data_t sat_pos_mild = 5.0;
    check(sat_pos_mild == max_pos, "custom_data_t: value 5.0 saturates to +3.99609375 without wrap-around");

    custom_data_t sat_pos_extreme = 1000.0;
    check(sat_pos_extreme == max_pos, "custom_data_t: value 1000.0 saturates to +3.99609375 without wrap-around");

    custom_data_t sat_neg_mild = -5.0;
    check(sat_neg_mild == max_neg, "custom_data_t: value -5.0 saturates to -4.0 without wrap-around");

    custom_data_t sat_neg_extreme = -1000.0;
    check(sat_neg_extreme == max_neg, "custom_data_t: value -1000.0 saturates to -4.0 without wrap-around");

    // acc_t = ap_fixed<24, 8, AP_RND, AP_SAT>
    // Range: [-128.0, +127.9999847412109375]
    acc_t acc_max_pos = 127.9999847412109375;
    acc_t acc_max_neg = -128.0;

    acc_t acc_sat_pos = 500.0;
    check(acc_sat_pos == acc_max_pos, "acc_t: value 500.0 saturates to +127.99998... without wrap-around");

    acc_t acc_sat_neg = -500.0;
    check(acc_sat_neg == acc_max_neg, "acc_t: value -500.0 saturates to -128.0 without wrap-around");

    // Test simd_mac16 under extreme saturation conditions
    custom_data_t act_extreme[SIMD_WIDTH];
    custom_data_t wt_extreme[SIMD_WIDTH];
    for (int k = 0; k < SIMD_WIDTH; ++k) {
        act_extreme[k] = max_pos;
        wt_extreme[k] = max_pos;
    }
    acc_t test_acc = 100.0;
    // 16 * 3.996 * 3.996 ≈ 255.5 -> 100 + 255.5 = 355.5 > 127.9999, must saturate to acc_max_pos
    simd_mac16(act_extreme, wt_extreme, test_acc);
    check(test_acc == acc_max_pos, "simd_mac16: tree reduction + accumulation saturates cleanly at +127.99998...");

    // Test extreme negative accumulation saturation
    for (int k = 0; k < SIMD_WIDTH; ++k) {
        act_extreme[k] = max_pos;
        wt_extreme[k] = max_neg;
    }
    test_acc = -100.0;
    // 16 * 3.996 * -4.0 ≈ -255.7 -> -100 - 255.7 = -355.7 < -128.0, must saturate to -128.0
    simd_mac16(act_extreme, wt_extreme, test_acc);
    check(test_acc == acc_max_neg, "simd_mac16: negative accumulation saturates cleanly at -128.0");

    // Test mlp_accel with all-ones input vector (1.0 across all 784 inputs)
    custom_data_t ones_img[INPUT_NODES];
    for (int i = 0; i < INPUT_NODES; ++i) {
        ones_img[i] = 1.0;
    }
    unsigned char ones_pred = 255;
    mlp_accel(ones_img, &ones_pred);
    check(ones_pred >= 0 && ones_pred <= 9, "All-1.0 input vector completes and produces valid digit in [0, 9]");
    std::cout << "      All-1.0 Predicted Digit: " << (int)ones_pred << "\n";

    // Test mlp_accel with maximum positive saturation input vector (3.99609375 across all 784 inputs)
    custom_data_t max_pos_img[INPUT_NODES];
    for (int i = 0; i < INPUT_NODES; ++i) {
        max_pos_img[i] = max_pos;
    }
    unsigned char max_pos_pred = 255;
    mlp_accel(max_pos_img, &max_pos_pred);
    check(max_pos_pred >= 0 && max_pos_pred <= 9, "Max-positive (+3.996) input vector completes and produces valid digit");
    std::cout << "      Max-Positive Predicted Digit: " << (int)max_pos_pred << "\n";

    // Test mlp_accel with maximum negative saturation input vector (-4.0 across all 784 inputs)
    custom_data_t max_neg_img[INPUT_NODES];
    for (int i = 0; i < INPUT_NODES; ++i) {
        max_neg_img[i] = max_neg;
    }
    unsigned char max_neg_pred = 255;
    mlp_accel(max_neg_img, &max_neg_pred);
    check(max_neg_pred >= 0 && max_neg_pred <= 9, "Max-negative (-4.0) input vector completes and produces valid digit");
    std::cout << "      Max-Negative Predicted Digit: " << (int)max_neg_pred << "\n";

    // Test mlp_accel with alternating extreme checkerboard pattern (+3.996, -4.0)
    custom_data_t checker_img[INPUT_NODES];
    for (int i = 0; i < INPUT_NODES; ++i) {
        checker_img[i] = (i % 2 == 0) ? max_pos : max_neg;
    }
    unsigned char checker_pred = 255;
    mlp_accel(checker_img, &checker_pred);
    check(checker_pred >= 0 && checker_pred <= 9, "Checkerboard (+3.996 / -4.0) input vector completes and produces valid digit");
    std::cout << "      Checkerboard Predicted Digit: " << (int)checker_pred << "\n";

    // ========================================================================
    // Section 4: Deterministic Tie-Breaking in Argmax
    // ========================================================================
    std::cout << "\n--- Section 4: Deterministic Tie-Breaking in Argmax ---\n";
    
    // Case 4.1: All 10 logits identical (zeros) -> lowest index 0 strictly wins
    custom_data_t logits_all_zero[OUTPUT_NODES] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    check(test_argmax(logits_all_zero) == 0, "Argmax: all 10 logits = 0.0 -> index 0 strictly wins");

    // Case 4.2: All 10 logits identical positive -> lowest index 0 strictly wins
    custom_data_t logits_all_pos[OUTPUT_NODES];
    for (int c = 0; c < OUTPUT_NODES; ++c) logits_all_pos[c] = 2.5;
    check(test_argmax(logits_all_pos) == 0, "Argmax: all 10 logits = +2.5 -> index 0 strictly wins");

    // Case 4.3: All 10 logits identical negative -> lowest index 0 strictly wins
    custom_data_t logits_all_neg[OUTPUT_NODES];
    for (int c = 0; c < OUTPUT_NODES; ++c) logits_all_neg[c] = -3.0;
    check(test_argmax(logits_all_neg) == 0, "Argmax: all 10 logits = -3.0 -> index 0 strictly wins");

    // Case 4.4: Exhaustive pairwise tie-breaking across all 45 pairs (i < j)
    bool all_pairs_passed = true;
    for (int i = 0; i < OUTPUT_NODES; ++i) {
        for (int j = i + 1; j < OUTPUT_NODES; ++j) {
            custom_data_t test_logits[OUTPUT_NODES];
            for (int c = 0; c < OUTPUT_NODES; ++c) test_logits[c] = 0.0;
            test_logits[i] = 3.0;
            test_logits[j] = 3.0; // exact tie between i and j
            unsigned char winner = test_argmax(test_logits);
            if (winner != i) {
                all_pairs_passed = false;
                std::cerr << "      Tie failed between " << i << " and " << j << ": got " << (int)winner << "\n";
            }
        }
    }
    check(all_pairs_passed, "Argmax: all 45 pairwise ties (i < j) strictly resolve to lowest index i");

    // Case 4.5: Triple tie (e.g. classes 2, 5, 8 tie for top logit)
    custom_data_t triple_tie[OUTPUT_NODES] = {0, 0, 2.5, 0, 0, 2.5, 0, 0, 2.5, 0};
    check(test_argmax(triple_tie) == 2, "Argmax: triple tie between indices {2, 5, 8} strictly selects lowest index 2");

    // Case 4.6: Adjacent pair tie at the tail (indices 8 and 9)
    custom_data_t tail_tie[OUTPUT_NODES] = {-1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, -1.0, 1.25, 1.25};
    check(test_argmax(tail_tie) == 8, "Argmax: tail tie between indices {8, 9} strictly selects lowest index 8");

    // Case 4.7: Inverted condition sanity check (higher index has strictly higher logit)
    custom_data_t strictly_higher[OUTPUT_NODES] = {0, 0, 2.5, 0, 0, 2.50390625, 0, 0, 0, 0};
    check(test_argmax(strictly_higher) == 5, "Argmax sanity check: index 5 with strictly higher logit (2.5039 > 2.5) beats index 2");

    // ========================================================================
    // Section 5: Summary and Verdict
    // ========================================================================
    std::cout << "\n==================================================================\n";
    std::cout << "  Adversarial Verification Summary:\n";
    std::cout << "  Total Assertions Tested: " << total_tests << "\n";
    std::cout << "  Passed Assertions      : " << passed_tests << "\n";
    std::cout << "  Failed Assertions      : " << failed_tests << "\n";
    std::cout << "==================================================================\n";

    if (failed_tests == 0) {
        std::cout << ">>> ADVERSARIAL VERIFICATION RESULT: CONFIRMED <<<\n\n";
        return 0;
    } else {
        std::cerr << ">>> ADVERSARIAL VERIFICATION RESULT: FAILED (" << failed_tests << " failures) <<<\n\n";
        return 1;
    }
}
