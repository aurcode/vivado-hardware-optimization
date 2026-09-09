# Handoff Report: Adversarial Verification of Hardware Simulation Core

- **Agent**: `challenger_sim_1`
- **Working Directory**: `/home/coder/vivado/.agents/challenger_sim_1`
- **Target**: Hardware Accelerator Compute Core (`hw/mlp_accel.cpp`, `hw/mlp_accel.h`, `hw/tb_mlp.cpp`, `hw/Makefile`)
- **Overall Verdict**: **CONFIRMED**

---

## 1. Observation

### 1.1 Host Simulation Accuracy & Test Execution
Execution of the project's native C++ testbench via `make -C /home/coder/vivado/hw host-sim`:
```text
make: Entering directory '/home/coder/vivado/hw'
==> Executing native host simulation...
./sim_mlp
==================================================================
  Starting 784-64-10 MLP Hardware Accelerator Testbench           
  Precision : ap_fixed<11, 3, AP_RND, AP_SAT> (Q3.8 format)        
  Datapath  : 16-way SIMD MAC (Balanced Tree, TDM Reused Core)   
  Topology  : 784 Inputs -> 64 Hidden (ReLU) -> 10 Logits (Argmax)
==================================================================
  [Sample   1] Ground Truth: 7 | Predicted: 7 --> [PASS]
  ...
  [Sample 100] Ground Truth: 9 | Predicted: 9 --> [PASS]
==================================================================
  Verification Summary:
  Total Samples Tested: 100
  Correct Classifications: 97
  Measured Accuracy: 97.00%
  Specification Minimum: >= 90.00% (Baseline Target: 97.00%)
==================================================================
>>> ACCELERATOR HARDWARE VERIFICATION PASSED SUCCESSFULLY! <<<
```

### 1.2 Dedicated Adversarial Stress Harness (`hw/tests/adversarial_sim_test.cpp`)
Compilation and execution of the independent 34-assertion adversarial suite:
```text
==================================================================
  Adversarial Empirical Verification of Hardware Simulation Core  
  Agent: challenger_sim_1                                         
==================================================================

--- Section 1: Layer Dimensions, Chunk Counts, and SIMD Cycles ---
  [PASS] Test  1: Input dimension is exactly 784
  [PASS] Test  2: FC1 hidden dimension is exactly 64
  [PASS] Test  3: FC2 output dimension is exactly 10
  [PASS] Test  4: SIMD vector width is exactly 16
  [PASS] Test  5: FC1 chunks per neuron is 784 / 16 = 49
  [PASS] Test  6: L1_BLOCKS macro matches exactly 49
  [PASS] Test  7: FC2 chunks per class is 64 / 16 = 4
  [PASS] Test  8: L2_BLOCKS macro matches exactly 4
  [PASS] Test  9: FC1 total compute calls = 64 neurons * 49 chunks = 3,136 cycles
  [PASS] Test 10: FC2 total compute calls = 10 classes * 4 chunks = 40 cycles
  [PASS] Test 11: Total SIMD compute cycles = 3,136 + 40 = 3,176 cycles
  [PASS] Test 12: FC1 chunk indexing covers [0, 783] exactly once with zero gaps/overlaps
  [PASS] Test 13: FC2 chunk indexing covers [0, 63] exactly once with zero gaps/overlaps

--- Section 2: Zero Input Vector Test ---
  [PASS] Test 14: Zero input vector completes execution without hang/timeout (< 1000ms)
  [PASS] Test 15: Zero input vector produces deterministic output digit 0 (all zero logits tie-break)
      Latency: 114.947 ms | Predicted Digit: 0

--- Section 3: Numerical Saturation Behavior (AP_SAT) ---
  [PASS] Test 16: custom_data_t: value 5.0 saturates to +3.99609375 without wrap-around
  [PASS] Test 17: custom_data_t: value 1000.0 saturates to +3.99609375 without wrap-around
  [PASS] Test 18: custom_data_t: value -5.0 saturates to -4.0 without wrap-around
  [PASS] Test 19: custom_data_t: value -1000.0 saturates to -4.0 without wrap-around
  [PASS] Test 20: acc_t: value 500.0 saturates to +127.99998... without wrap-around
  [PASS] Test 21: acc_t: value -500.0 saturates to -128.0 without wrap-around
  [PASS] Test 22: simd_mac16: tree reduction + accumulation saturates cleanly at +127.99998...
  [PASS] Test 23: simd_mac16: negative accumulation saturates cleanly at -128.0
  [PASS] Test 24: All-1.0 input vector completes and produces valid digit in [0, 9]
      All-1.0 Predicted Digit: 2
  [PASS] Test 25: Max-positive (+3.996) input vector completes and produces valid digit
      Max-Positive Predicted Digit: 2
  [PASS] Test 26: Max-negative (-4.0) input vector completes and produces valid digit
      Max-Negative Predicted Digit: 4
  [PASS] Test 27: Checkerboard (+3.996 / -4.0) input vector completes and produces valid digit
      Checkerboard Predicted Digit: 5

--- Section 4: Deterministic Tie-Breaking in Argmax ---
  [PASS] Test 28: Argmax: all 10 logits = 0.0 -> index 0 strictly wins
  [PASS] Test 29: Argmax: all 10 logits = +2.5 -> index 0 strictly wins
  [PASS] Test 30: Argmax: all 10 logits = -3.0 -> index 0 strictly wins
  [PASS] Test 31: Argmax: all 45 pairwise ties (i < j) strictly resolve to lowest index i
  [PASS] Test 32: Argmax: triple tie between indices {2, 5, 8} strictly selects lowest index 2
  [PASS] Test 33: Argmax: tail tie between indices {8, 9} strictly selects lowest index 8
  [PASS] Test 34: Argmax sanity check: index 5 with strictly higher logit (2.5039 > 2.5) beats index 2

==================================================================
  Adversarial Verification Summary:
  Total Assertions Tested: 34
  Passed Assertions      : 34
  Failed Assertions      : 0
==================================================================
>>> ADVERSARIAL VERIFICATION RESULT: CONFIRMED <<<
```

### 1.3 Full Regression Test Suite Execution
`python3 e2e_tests/run_tests.py`:
- 236 out of 236 tests passed (100% pass rate across Tier 1, 2, 3, and 4).

---

## 2. Logic Chain

1. **Host-Level Simulation Accuracy**:
   - `hw/test_inputs.h` provides 100 test samples with ground truth labels.
   - Running `make host-sim` executes `hw/sim_mlp` (compiled from `tb_mlp.cpp` and `mlp_accel.cpp`).
   - 97 out of 100 predictions match ground truth (97.00% accuracy), satisfying and exceeding the requirement of $\ge 90\%$.

2. **Zero Input Vector Adversarial Challenge**:
   - When all 784 inputs are `custom_data_t(0)`, every SIMD product in FC1 evaluates to `0 * wt = 0`.
   - Balanced tree reduction produces `tree_sum = 0`, and accumulator remains `0`.
   - Sign-bit ReLU evaluates `acc < 0` (false), assigning `l1_act[n] = 0`.
   - FC2 inputs are all zero, producing all 10 logits equal to `0`.
   - Argmax begins with `max_val = l2_logits[0] = 0`.
   - For $c = 1 \dots 9$, `l2_logits[c] > max_val` (`0 > 0`) is false; `best_digit` remains `0`.
   - Hardware execution finishes in 114 ms without hanging, division by zero, or memory faults, returning `pred_digit = 0`.

3. **Numerical Saturation & `AP_SAT` Verification**:
   - `hw/mlp_accel.h` defines:
     `typedef ap_fixed<11, 3, AP_RND, AP_SAT> custom_data_t;` (Range $[-4.0, +3.99609375]$)
     `typedef ap_fixed<24, 8, AP_RND, AP_SAT> acc_t;` (Range $[-128.0, +127.9999847412109375]$)
   - Testing boundary assignments proves that `custom_data_t(5.0)` and `custom_data_t(1000.0)` clamp to `+3.99609375` (Q3.8 upper bound), and `custom_data_t(-5.0)` and `custom_data_t(-1000.0)` clamp to `-4.0` without wrap-around.
   - Tree accumulator saturation in `simd_mac16`: when 16 maximum products are accumulated onto large initial values, `acc_t` clamps cleanly at `+127.99998...` and `-128.0`.
   - Running inference on all-1.0, max-positive (`+3.99609375`), max-negative (`-4.0`), and checkerboard patterns produces valid digits in $[0, 9]$ without arithmetic exception or overflow wrap-around.

4. **Deterministic Tie-Breaking in Argmax**:
   - `hw/mlp_accel.cpp` lines 130-140 implement:
     ```cpp
     unsigned char best_digit = 0;
     custom_data_t max_val = l2_logits[0];
     ARGMAX_TREE: for (int c = 1; c < OUTPUT_NODES; ++c) {
         if (l2_logits[c] > max_val) {
             max_val = l2_logits[c];
             best_digit = (unsigned char)c;
         }
     }
     *pred_digit = best_digit;
     ```
   - Because strict inequality `>` is utilized rather than `>=`, any subsequent class with a logit equal to the current maximum does NOT overwrite `best_digit`.
   - Empirical sweep across all $\binom{10}{2} = 45$ pairwise ties confirms that for every pair $(i < j)$ where `l2_logits[i] == l2_logits[j] == max`, class `i` strictly wins.
   - All-equal logits (all 0.0, all +2.5, all -3.0) and multi-way ties ({2, 5, 8}, {8, 9}) strictly select the lowest index.

5. **Layer Dimension & SIMD Compute Cycle Math**:
   - FC1: 784 inputs / 16 SIMD lane width = exactly 49 chunks per neuron.
   - 64 hidden neurons $\times$ 49 chunks = 3,136 compute cycles.
   - FC2: 64 hidden activations / 16 SIMD lane width = exactly 4 chunks per class.
   - 10 output classes $\times$ 4 chunks = 40 compute cycles.
   - Total compute cycles = $3136 + 40 = 3176$ SIMD MAC cycles.
   - Chunk indexing coverage check proves that $b \times 16 + k$ covers $[0, 783]$ and $[0, 63]$ with zero gaps, zero overlaps, and zero off-by-one errors.

---

## 3. Caveats

- **Vivado HLS RTL Co-Simulation**: The empirical tests executed here were performed using the native Xilinx fixed-point C++ library (`include_xilinx`) and native host compilation (`g++ -std=c++11`). Full RTL co-simulation (`cosim`) inside the Docker container is managed by the HLS synthesis pipeline.
- No other caveats.

---

## 4. Conclusion

**Final Verdict**: **CONFIRMED**

The hardware simulation core (`hw/mlp_accel.cpp`, `hw/mlp_accel.h`, `hw/tb_mlp.cpp`):
1. Safely and deterministically handles zero input vectors without crashes or hangs, predicting digit `0`.
2. Fully enforces `AP_SAT` fixed-point saturation across both activation and accumulator tiers with zero wrap-around.
3. Implements strictly deterministic tie-breaking where the lowest class index strictly wins.
4. Correctly implements 49 FC1 chunks, 4 FC2 chunks, and 3,176 total SIMD compute cycles without indexing flaws.
5. Achieves 97.00% accuracy on the 100 test samples in native simulation, easily surpassing the $\ge 90.00\%$ requirement.

---

## 5. Verification Method

To independently reproduce and verify these findings:

```bash
# 1. Run native host simulation testbench
cd /home/coder/vivado/hw && make host-sim

# 2. Compile and run standalone adversarial stress test suite
g++ -O0 -Wall -Wno-unknown-pragmas -Wno-unused-parameter -Wno-unused-label \
    -Wno-int-in-bool-context -std=c++11 -I/home/coder/vivado/hw \
    -I/home/coder/vivado/include_xilinx \
    /home/coder/vivado/hw/tests/adversarial_sim_test.cpp \
    /home/coder/vivado/hw/mlp_accel.o -o /home/coder/vivado/hw/tests/adversarial_sim_test

/home/coder/vivado/hw/tests/adversarial_sim_test

# 3. Run full project regression suite
cd /home/coder/vivado && python3 e2e_tests/run_tests.py
```

**Invalidation Conditions**:
- Any assertion in `adversarial_sim_test` evaluates to `[FAIL]`.
- Measured accuracy in `make host-sim` drops below 90.00%.
- Any tie between two equal top logits selects the higher index.
