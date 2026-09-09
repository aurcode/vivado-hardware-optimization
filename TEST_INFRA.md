# Test Infrastructure Specification: Intelligent Chip Hardware Accelerator

- **Project**: Intelligent Chip Hardware Accelerator Programming Project (784-64-10 MLP on Zynq-7000 XC7Z020)
- **Document**: `TEST_INFRA.md`
- **Owner**: E2E Test Writer (`test_writer_e2e_1`)
- **Date**: 2026-09-09
- **Status**: ACTIVE / PRODUCTION-READY

---

## 1. Overview & Architecture Philosophy

The E2E Test Suite provides an independent, requirement-driven, opaque-box verification framework for the entire intelligent chip edge computing system. It exercises the full pipeline from raw camera photo ingestion and 7-step preprocessing through fixed-point quantization, 16-way SIMD MAC datapath acceleration with TDM FSM reuse, AXI4-Lite register control, and post-synthesis PPA compliance.

### Core Principles
1. **Opaque-Box Verification**: Tests validate interfaces, numerical contracts, and behavioral requirements against specifications rather than matching internal implementation details.
2. **Explicit Authoritative Expected Outputs**: Every test case derives expected outputs from ground truth assets:
   - Verified 784-64-10 weights in `hw/weights.h` (`ap_fixed<11, 3, AP_RND, AP_SAT>`, no bias).
   - 100 verified MNIST vectors & golden labels in `hw/test_inputs.h` (baseline 97.00% accuracy).
   - 100 real-world handwriting and background noise photos across Cohorts 1–4.
   - Mathematical properties (balanced binary adder trees, sign-bit ReLU, monotonic Argmax tie-breaking).
   - Architectural register specifications from Xilinx Vivado HLS AXI4-Lite contracts.
3. **No Facade Testing**: Every test exercises real computational logic, image processing transforms, or fixed-point arithmetic without hardcoded bypasses.
4. **Progressive Testability**: The suite is self-contained and isolated. It operates standalone in the `E2E Testing Track` using the authoritative reference oracle, and directly verifies hardware and preprocessing deliverables as milestones M1–M4 are integrated.

---

## 2. Directory Layout

```
e2e_tests/
├── __init__.py                     # Python package marker
├── oracle.py                       # Authoritative reference oracle (fixed-point arithmetic, SIMD MAC, FSM, 7-step pipeline)
├── test_runner.py                  # Standalone CLI test harness with rich reporting & exit codes
├── run_tests.py                    # Entry point alias for test_runner.py
├── tier1_feature_tests.py          # Tier 1: Feature Coverage (110 tests: >=5 tests/feature for Features 1-22)
├── tier2_boundary_tests.py         # Tier 2: Boundary & Corner Cases (110 tests: >=5 tests/feature)
├── tier3_interaction_tests.py      # Tier 3: Cross-Feature Interactions (10 pairwise & system tests)
└── tier4_workload_tests.py         # Tier 4: Real-World Workload Scenarios (6 end-to-end cohort scenarios)
```

---

## 3. Test Hierarchy & Tier Architecture

The test suite is structured into four production tiers, with Tier 5 planned for final adversarial hardening:

| Tier | Name | Target Scope | Test Count | Pass Criteria |
| :---: | :--- | :--- | :---: | :--- |
| **Tier 1** | **Feature Coverage** | Isolated happy-path coverage for Features 1 through 22. | **110** | 100% Pass |
| **Tier 2** | **Boundary & Corner Cases** | Stress vectors, all-zeros, max-intensity, negative values, saturation, empty bbox, OOD. | **110** | 100% Pass |
| **Tier 3** | **Cross-Feature Interactions** | Pairwise module interactions: Preproc $\to$ Inference, Blank $\to$ Rejection, AXI Handshake. | **10** | 100% Pass |
| **Tier 4** | **Real-World Workloads** | End-to-end recognition on 100 photos across Cohorts 1–4, confusion matrix, streaming. | **6** | 100% Pass |
| **Tier 5** | **Adversarial Hardening** | White-box stress injection, timing/resource margin exploration (Final Milestone). | Planned | 100% Pass |
| **TOTAL** | | **Production Ready Test Cases** | **236** | **100% Pass** |

---

## 4. Authoritative Golden Oracle Specifications (`e2e_tests/oracle.py`)

The oracle implements bit-accurate software models matching Xilinx Vivado HLS hardware behavior:

1. **Fixed-Point Datapath (`FixedPoint11_3`)**:
   - Format: `ap_fixed<11, 3, AP_RND, AP_SAT>` (1 sign bit, 2 integer bits, 8 fractional bits).
   - Scale factor: $S = 2^8 = 256.0$.
   - Valid integer range: $[-1024, 1023]$ corresponding to $[-4.0, +3.99609375]$.
   - Rounding mode `AP_RND`: Half-LSB rounding ($+128$ in scale $65536$).
   - Overflow mode `AP_SAT`: Symmetric saturation at $[-1024, 1023]$.
2. **16-Way SIMD MAC Core (`simd_mac16_balanced_tree`)**:
   - Computes 16 simultaneous $11\text{-bit} \times 11\text{-bit}$ multiplications.
   - 4-level balanced binary adder tree reduction: Depth $1$ (8 adders) $\to$ Depth $2$ (4 adders) $\to$ Depth $3$ (2 adders) $\to$ Depth $4$ (1 adder).
3. **Sign-Bit ReLU (`sign_bit_relu`)**:
   - Inspects MSB sign bit (bit 10). If negative ($< 0$), clamped to $0$.
   - If positive, rescaled from accumulator scale $65536$ to activation scale $256$ with `AP_RND` and `AP_SAT`.
4. **Parallel Argmax (`parallel_argmax`)**:
   - 10-way comparator network identifying winning class index in $[0..9]$.
   - Deterministic tie-breaking: Strictly lower class index wins upon equal logit scores (`val > max_val`).
5. **AXI4-Lite Register File (`AXILiteRegisters`)**:
   - `0x00 CTRL_REG`: Bit 0 = `ap_start`, Bit 1 = `ap_done`, Bit 2 = `ap_idle`, Bit 3 = `ap_ready`, Bit 7 = `auto_restart`.
   - `0x04 GIE`: Global Interrupt Enable.
   - `0x08 IER`: Interrupt Enable Register.
   - `0x0C ISR`: Interrupt Status Register (Toggle-on-write to clear).
   - `0x10 PRED_REG`: Winning class prediction ($0..9$).
   - `0x14 SCORE_REG`: Winning logit score in `ap_fixed<11, 3>`.
6. **7-Step Preprocessing Pipeline (`preprocess_image_7step`)**:
   - Step 1: Luma conversion ($Y = 0.299R + 0.587G + 0.114B$).
   - Step 2: 4-corner polarity detection & background inversion (white digit on dark background).
   - Step 3: Otsu bimodal thresholding & background noise suppression ($< 0.7 \times \text{otsu} \to 0$).
   - Step 4: Minimum bounding-box ROI localization ($[y_{\min}, y_{\max}, x_{\min}, x_{\max}]$).
   - Step 5: Aspect-ratio bicubic scaling into $20 \times 20$ box ($s = 20.0 / \max(H, W)$).
   - Step 6: Intensity-weighted Center-of-Mass alignment onto $28 \times 28$ grid.
   - Step 7: Normalization to $[0.0, 1.0)$ and fixed-point quantization (scale $256$, integers $[0, 255]$).

---

## 5. Execution Instructions & CLI Interface

### Running Tests via Python Runner
```bash
# Run all 236 test cases across Tiers 1 through 4
python3 e2e_tests/test_runner.py --all

# Run individual test tiers
python3 e2e_tests/test_runner.py --tier 1    # Tier 1: Feature Coverage (110 tests)
python3 e2e_tests/test_runner.py --tier 2    # Tier 2: Boundary & Corner Cases (110 tests)
python3 e2e_tests/test_runner.py --tier 3    # Tier 3: Cross-Feature Interactions (10 tests)
python3 e2e_tests/test_runner.py --tier 4    # Tier 4: Real-World Workload Scenarios (6 tests)

# Run tests specifically for a given feature (Features 1 through 22)
python3 e2e_tests/test_runner.py --feature 1   # Topology tests across Tiers 1 and 2
python3 e2e_tests/test_runner.py --feature 10  # Preprocessing tests

# List all registered test cases without running
python3 e2e_tests/test_runner.py --list

# Verbose execution with per-test execution times
python3 e2e_tests/test_runner.py --all -v
```

### Standard Exit Codes
- `0`: All tests passed successfully (100% pass rate).
- `1`: One or more test failures or errors detected.

---

## 6. Feature-by-Feature Traceability Matrix

| Feature | Description | Tier 1 Tests | Tier 2 Tests | Tier 3/4 Coverage | Authoritative Expected Source |
| :--- | :--- | :---: | :---: | :---: | :--- |
| **F1** | 784-64-10 MLP Topology | `test_f1_01..05` | `test_f1_b01..b05` | `test_interaction_01, 07` | `hw/weights.h`, `hw/test_inputs.h` |
| **F2** | 16-Way SIMD MAC Core | `test_f2_01..05` | `test_f2_b01..b05` | `test_interaction_04` | 4-Level Binary Tree Math Spec |
| **F3** | TDM FSM Hardware Reuse | `test_f3_01..05` | `test_f3_b01..b05` | `test_interaction_05` | 3,176 Compute Cycle Budget Formula |
| **F4** | Sign-Bit ReLU Unit | `test_f4_01..05` | `test_f4_b01..b05` | `test_interaction_04` | Two's complement MSB sign check |
| **F5** | Parallel Argmax Unit | `test_f5_01..05` | `test_f5_b01..b05` | `test_interaction_06` | Lowest-index tie-breaking rule |
| **F6** | AXI4-Lite & Memory Interface | `test_f6_01..05` | `test_f6_b01..b05` | `test_interaction_05, 06` | HLS `s_axilite` Register Map |
| **F7** | Native Host C++ Simulation | `test_f7_01..05` | `test_f7_b01..b05` | `test_interaction_07` | `hw/Makefile`, `include_xilinx/` |
| **F8** | Vivado HLS Batch Script Flow | `test_f8_01..05` | `test_f8_b01..b05` | `test_interaction_08` | `Makefile`, `fpgatools/vivado:latest` |
| **F9** | PPA Metric Extraction & Budget | `test_f9_01..05` | `test_f9_b01..b05` | `test_interaction_08, 10` | XC7Z020 Budget: DSP<=32, BRAM<=8 |
| **F10** | 7-Step Preprocessing Pipeline | `test_f10_01..05` | `test_f10_b01..b05` | `test_interaction_01, 03` | 7-step ITU/Otsu/Centroid Spec |
| **F11** | Bounded Model & SW/HW Boundary | `test_f11_01..05` | `test_f11_b01..b05` | `test_interaction_01, 03` | PS/PL Fixed 784 Vector Contract |
| **F12** | Real-World Cohort Benchmarking | `test_f12_01..05` | `test_f12_b01..b05` | `test_workload_01..03, 05` | 100-Photo Cohorts 1-4 Dataset |
| **F13** | 10x10 Confusion Matrix & Analysis | `test_f13_01..05` | `test_f13_b01..b05` | `test_interaction_09, test_workload_05` | Statistical Precision/Recall Formulas |
| **F14** | Background Noise Rejection | `test_f14_01..05` | `test_f14_b01..b05` | `test_interaction_02, test_workload_04` | 100% Precision on Cohort 4 Controls |
| **F15** | PTQ Sensitivity Sweep | `test_f15_01..05` | `test_f15_b01..b05` | `test_interaction_08` | 16/11/8/4-bit Quantization Models |
| **F16** | Saturation Knee Point Proof | `test_f16_01..05` | `test_f16_b01..b05` | `test_interaction_08` | 11-bit Marginal Gain Plateau (<0.2%) |
| **F17** | Pareto Frontier & Recommendation | `test_f17_01..05` | `test_f17_b01..b05` | `test_interaction_08, 10` | Non-dominated Set & Edge Criteria |
| **F18** | Level 1 Synthesis Report | `test_f18_01..05` | `test_f18_b01..b05` | `test_interaction_10` | `reports/level1_synthesis_report.md` |
| **F19** | Level 2 Domain Gap Report | `test_f19_01..05` | `test_f19_b01..b05` | `test_interaction_09` | `reports/level2_domain_gap_report.md` |
| **F20** | Level 3 DSE Pareto Report | `test_f20_01..05` | `test_f20_b01..b05` | `test_interaction_08` | `reports/level3_dse_pareto_report.md` |
| **F21** | Presentation Slide Deck | `test_f21_01..05` | `test_f21_b01..b05` | `test_interaction_10` | `reports/presentation_slides.md` |
| **F22** | Defense Q&A Sheet (Roles A-H) | `test_f22_01..05` | `test_f22_b01..b05` | `test_interaction_10` | `reports/defense_qa_sheet.md` |

---

## 7. Maintenance & Integration Guidelines

When milestone implementers add or modify modules in `hw/`, `preprocessing/`, `dse/`, or `reports/`:
1. **Never modify tests to fit bugs**: Tests encode the authoritative specifications from the course task book and `PROJECT.md`.
2. **Execute regression runs**:
   - Run `python3 e2e_tests/test_runner.py --tier 1` to verify baseline functionality.
   - Run `python3 e2e_tests/test_runner.py --tier 2` to verify boundary resilience.
   - Run `python3 e2e_tests/test_runner.py --tier 3` to verify cross-module handshake.
   - Run `python3 e2e_tests/test_runner.py --tier 4` to verify photo benchmark accuracy.
3. **Escalate Discrepancies**: If an implementation produces unexpected numerical divergence, compare against `e2e_tests/oracle.py` to localize the offending layer or operator.
