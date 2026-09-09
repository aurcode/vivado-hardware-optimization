# Project: Intelligent Chip Hardware Accelerator Programming Project

## Architecture
The system implements an end-to-end intelligent edge computing system accelerating a 784-64-10 Multi-Layer Perceptron (MLP) on a Xilinx Zynq-7000 SoC (`xc7z020clg400-1`).

```
+-----------------------------------------------------------------------------+
|                                ARM PS / Host Software                        |
|  - Real-World Camera Capture & 7-Step Image Preprocessing (Python / C++)    |
|  - AXI4-Lite Driver & Control Register Interface (start, done, idle, ready) |
|  - Floating-point / Fixed-point Input Vector Buffering                       |
+-----------------------------------------------------------------------------+
                                       |
                   AXI4-Lite & Memory-Mapped Handshake
                                       |
                                       v
+-----------------------------------------------------------------------------+
|                          FPGA PL Accelerator (mlp_accel)                     |
|                                                                             |
|  +-----------------------------------------------------------------------+  |
|  | Controller (TDM FSM)                                                  |  |
|  |  - IDLE -> LOAD_INP -> CALC_FC1 -> RELU -> CALC_FC2 -> ARGMAX -> DONE |  |
|  |  - FC1: 64 neurons x (784 / 16 = 49 chunks) = 3,136 cycles           |  |
|  |  - FC2: 10 neurons x (64 / 16 = 4 chunks) = 40 cycles                 |  |
|  +-----------------------------------------------------------------------+  |
|                                       |                                     |
|  +-----------------------------------------------------------------------+  |
|  | Datapath                                                              |  |
|  |  - Single 16-way SIMD MAC Core (Balanced Adder Tree, pragma INLINE OFF)|  |
|  |  - Intermediate Activation Buffer (64 x ap_fixed<11, 3>)              |  |
|  |  - Activation: Sign-bit ReLU (zero if negative)                       |  |
|  |  - Classifier: 10-way Parallel Argmax with tie-breaking               |  |
|  +-----------------------------------------------------------------------+  |
+-----------------------------------------------------------------------------+
```

## Feature Inventory
Every feature from the survey phase appears here with its assigned milestone.
| # | Feature | Description | Milestone | Source |
|---|---------|-------------|-----------|--------|
| 1 | Bias-free 784-64-10 MLP Topology | 784 inputs, 64 hidden neurons, 10 output classes, ap_fixed<11, 3, AP_RND, AP_SAT> weights | M1 | ORIGINAL_REQUEST §R1, hw/weights.h |
| 2 | 16-Way SIMD MAC Core | Single compute engine with 16 parallel multipliers and balanced adder reduction tree | M1 | ORIGINAL_REQUEST §R1, hw/智能芯片选题任务书2026.md |
| 3 | TDM FSM Hardware Reuse | Sequential operator sharing: FC1 and FC2 reuse exact same 16-way MAC core (3,176 total compute cycles) | M1 | ORIGINAL_REQUEST §R1, hw/智能芯片实践分工.md |
| 4 | Sign-Bit ReLU Unit | Hardware activation function zeroing negative activations based on MSB sign bit | M1 | hw/智能芯片选题任务书2026.md §1.3.2 |
| 5 | Parallel Argmax Unit | High-speed comparator network identifying winning class 0-9 with deterministic tie-breaking | M1 | hw/智能芯片选题任务书2026.md §1.3.2 |
| 6 | AXI4-Lite & Memory Interface | Standard control registers (AP_START, AP_DONE, AP_IDLE) and I/O buffer integration | M1 | ORIGINAL_REQUEST §R1, hw/智能芯片实践分工.md |
| 7 | Native Host C++ Simulation | Instant simulation (`make host-sim`) using native g++ and include_xilinx/ | M1 | ORIGINAL_REQUEST §R2 |
| 8 | Vivado HLS Batch Script Flow | Dockerized execution (`fpgatools/vivado:latest`) of csim, csynth, cosim via run_hls.tcl | M1 | ORIGINAL_REQUEST §R2 |
| 9 | PPA Metric Extraction & Budget Verification | Target xc7z020clg400-1 @ 100 MHz (10.0 ns, positive slack); LUT <= 10,000, DSP <= 32, BRAM <= 8 | M1 | ORIGINAL_REQUEST §R2, hw/智能芯片实践分工.md |
| 10 | 7-Step Real-World Preprocessing Pipeline | RGB -> Grayscale -> Inversion -> Otsu Threshold -> BBox Crop -> Aspect Scale -> CoM Centering -> Normalize | M2 | ORIGINAL_REQUEST §R3, first_test/scripts/phase4_realworld |
| 11 | Bounded C++ Model / SW-HW Boundary | Specification of PS/PL division: PS handles image decode/filtering, PL handles fixed-point inference | M2 | ORIGINAL_REQUEST §R3, hw/智能芯片实践分工.md |
| 12 | Real-World Cohort Benchmarking | Evaluation on 100 real handwriting photos across 4 cohorts (clean, lighting, noise, blank) vs MNIST | M2 | ORIGINAL_REQUEST §R3, first_test/scripts/phase4_realworld |
| 13 | 10x10 Confusion Matrix & Error Analysis | Quantified per-digit precision, recall, and systematic stroke domain gap diagnosis | M2 | ORIGINAL_REQUEST §R3, hw/智能芯片实践分工.md |
| 14 | Background Noise Rejection | Thresholding mechanism rejecting blank/scratch negative controls with 100% precision | M2 | ORIGINAL_REQUEST §R3, hw/智能芯片选题任务书2026.md |
| 15 | PTQ Sensitivity Sweep (16/11/8/4-bit) | Post-training quantization accuracy evaluation across bitwidth tiers | M3 | ORIGINAL_REQUEST §R4, hw/智能芯片选题任务书2026.md |
| 16 | Saturation Knee Point Identification | Mathematical and empirical proof of 11-bit knee point (拐点) with zero marginal gain >= 11 bits | M3 | ORIGINAL_REQUEST §R4, hw/智能芯片选题任务书2026.md |
| 17 | Pareto Frontier & Edge Recommendation | Accuracy vs Area / Latency Pareto curve construction and Zynq edge deployment trade-off analysis | M3 | ORIGINAL_REQUEST §R4, hw/智能芯片选题任务书2026.md |
| 18 | Level 1 Synthesis Report | reports/level1_synthesis_report.md covering architecture, FSM, reuse proof, and PPA | M4 | ORIGINAL_REQUEST §R5, hw/智能芯片实践分工.md |
| 19 | Level 2 Domain Gap Report | reports/level2_domain_gap_report.md covering preprocessing, cohort results, and noise rejection | M4 | ORIGINAL_REQUEST §R5, hw/智能芯片实践分工.md |
| 20 | Level 3 Quantization & DSE Report | reports/level3_dse_pareto_report.md covering PTQ curves, knee point, and Pareto frontier | M4 | ORIGINAL_REQUEST §R5, hw/智能芯片实践分工.md |
| 21 | Team Defense Presentation Slides | reports/presentation_slides.md covering project overview, architecture, and live defense slides | M4 | ORIGINAL_REQUEST §R5, hw/智能芯片实践分工.md |
| 22 | Defense Q&A Cheat Sheet (Roles A-H) | reports/defense_qa_sheet.md aligned with individual role defense questions | M4 | ORIGINAL_REQUEST §R5, hw/智能芯片实践分工.md |
| 23 | Opaque-Box E2E Test Suite (Tiers 1-4) | Independent 4-tier test runner validating all features against specifications | E2E Track | ORIGINAL_REQUEST §Acceptance Criteria |
| 24 | Adversarial Coverage Hardening (Tier 5) | White-box stress testing, boundary injection, and timing/resource robustness verification | Final Milestone | Project Pattern Phase 2 |

## Milestones
| # | Name | Scope | Dependencies | Status |
|---|------|-------|-------------|--------|
| E2E | E2E Testing Track | Requirement-driven test harness, Tiers 1-4 test cases, TEST_INFRA.md, TEST_READY.md | none | IN_PROGRESS |
| M1 | Level 1 HLS Core & Sim/Synth | Synthesizable mlp_accel (16-way SIMD MAC reuse, TDM FSM), native host-sim, run_hls.tcl batch flow, PPA extraction | none | PLANNED |
| M2 | Level 2 Preprocessing & Domain Gap | 7-step Python pipeline, bounded C++ model, 100-photo cohort benchmark, 10x10 confusion matrix, noise rejection | none | PLANNED |
| M3 | Level 3 Quantization & DSE Pareto | PTQ across 16b/11b/8b/4b, knee point proof, synthesis-backed Pareto curve, edge deployment recommendation | M1 | PLANNED |
| M4 | Level 4 Reports & Defense Package | reports/ folder deliverables: synthesis report, domain gap report, DSE report, slides, Roles A-H Q&A sheet | M1, M2, M3 | PLANNED |
| M5 | Final Milestone: E2E Pass & Tier 5 Hardening | Phase 1: 100% pass of E2E Tiers 1-4; Phase 2: Tier 5 adversarial coverage hardening | E2E, M1, M2, M3, M4 | PLANNED |

## Interface Contracts

### C++ HLS Accelerator Interface (`mlp_accel`)
- Top-level function: `void mlp_accel(custom_data_t input_img[784], unsigned char *pred_digit)`
- Data types:
  - Input: `custom_data_t input_img[784]` where `typedef ap_fixed<11, 3, AP_RND, AP_SAT> custom_data_t;`
  - Output: `unsigned char *pred_digit` (range 0–9)
  - Control Interface: `#pragma HLS INTERFACE s_axilite port=return bundle=CTRL_BUS`
  - Port Interfaces:
    - `#pragma HLS INTERFACE s_axilite port=input_img bundle=CTRL_BUS` or memory-mapped BRAM
    - `#pragma HLS INTERFACE s_axilite port=pred_digit bundle=CTRL_BUS`
- Compute Core:
  - `void simd_mac16(const custom_data_t act[16], const custom_data_t wt[16], custom_data_t &acc)`
  - Directives: `#pragma HLS INLINE OFF` to guarantee single-instance instantiation.

### Preprocessing Pipeline Output Contract
- Python function: `preprocess_handwritten_image(image_path: str) -> Tuple[np.ndarray, np.ndarray]`
  - Returns:
    - `norm_img`: $(28, 28)$ float array normalized to $[0.0, 1.0)$.
    - `quant_img`: $(28, 28)$ integer/fixed-point array matching `ap_fixed<11, 3>` representation ($2^8 = 256$ fixed scaling).
  - Noise Rejection: Returns `(None, None)` or negative status flag if mean background energy / stroke connectivity fails threshold.

### E2E Test Suite Contract
- Entry point: `python3 e2e_tests/run_tests.py` or `make e2e-test`
- Exit codes: 0 = ALL PASS, 1 = TEST FAILURE.
- Artifacts: Publishes `TEST_READY.md` summarizing coverage across Tiers 1–4.

## Code Layout
```
/home/coder/vivado/
├── hw/                                 # Hardware accelerator sources & weights
│   ├── weights.h                       # 784-64-10 frozen weights (ap_fixed<11, 3>)
│   ├── test_inputs.h                   # 100 test samples & labels (97.00% baseline)
│   ├── mlp_accel.h                     # Accelerator declarations & interfaces
│   ├── mlp_accel.cpp                   # Synthesizable accelerator implementation
│   ├── tb_mlp.cpp                      # Simulation testbench
│   ├── run_hls.tcl                     # Automated Vivado HLS batch script (Docker)
│   └── Makefile                        # Native simulation & Docker flow automation
├── preprocessing/                      # Real-world preprocessing & domain gap
│   ├── preprocess.py                   # 7-step Python preprocessing pipeline
│   ├── bounded_preproc.cpp             # Bounded C++ preprocessing model
│   ├── evaluate_domain_gap.py          # 100-sample benchmark & confusion matrix
│   └── real_world_data/                # 100 real handwriting photos (Cohorts 1-4)
├── dse/                                # Quantization & Design Space Exploration
│   ├── ptq_sweep.py                    # PTQ simulation across 16/11/8/4-bit
│   ├── plot_pareto.py                  # Knee point & Pareto frontier plotting
│   └── synth_results/                  # Synthesis extraction logs & PPA metrics
├── reports/                            # Comprehensive defense deliverables
│   ├── level1_synthesis_report.md      # Level 1 synthesis, architecture, PPA
│   ├── level2_domain_gap_report.md     # Level 2 preprocessing & domain gap
│   ├── level3_dse_pareto_report.md     # Level 3 PTQ, knee point, Pareto
│   ├── presentation_slides.md          # Team defense presentation deck
│   └── defense_qa_sheet.md             # Defense Q&A cheat sheet (Roles A-H)
├── e2e_tests/                          # Independent E2E verification track
│   ├── test_runner.py                  # Opaque-box test harness
│   ├── tier1_feature_tests.py          # Tier 1 tests (>=5 per feature)
│   ├── tier2_boundary_tests.py         # Tier 2 boundary & corner tests
│   ├── tier3_interaction_tests.py      # Tier 3 cross-feature tests
│   └── tier4_workload_tests.py         # Tier 4 real-world workload tests
├── TEST_INFRA.md                       # E2E test infrastructure specification
└── TEST_READY.md                       # E2E test readiness signal
```
