# Original User Request

## Initial Request — 2026-09-09T00:59:24Z

Complete the entire intelligent chip hardware accelerator programming homework specified in `hw/智能芯片选题任务书2026.md` and `hw/智能芯片实践分工.md`, implementing, verifying, and documenting a synthesizable 784-64-10 Multi-Layer Perceptron (MLP) accelerator based on the verified weights in `hw/weights.h`.

Working directory: /home/coder/vivado
Integrity mode: development

## Reference Materials & Verified Assets
- Task Specifications: `hw/智能芯片选题任务书2026.md` (Level 1, Level 2, Level 3 requirements)
- Team Division Plan: `hw/智能芯片实践分工.md` (Roles A through H responsibilities)
- Verified Weights: `hw/weights.h` (784-64-10 architecture, `ap_fixed<11, 3, AP_RND, AP_SAT>`, no bias)
- MNIST Test Vectors: `hw/test_inputs.h` (100 test samples & labels, baseline achieves 97.00% accuracy)
- Existing Real-World Photos: `first_test/scripts/phase4_realworld/real_world_data/` (100 handwriting photos)
- FPGA Platform: Xilinx Zynq-7000 (`xc7z020clg400-1`), 100 MHz (10.0 ns target clock)
- HLS Tool: Vivado HLS 2018.3 via existing Docker image `fpgatools/vivado:latest`

## Requirements

### R1. Synthesizable HLS Accelerator Core with Verified Hardware Reuse (Level 1)
Implement a clean, synthesizable C++ HLS accelerator (`mlp_accel`) with clean separation between Datapath and Controller:
- **Datapath**: A single 16-way SIMD MAC compute core with balanced adder tree, sign-bit ReLU, and parallel Argmax.
- **Hardware Reuse (TDM)**: FC1 ($784 \to 64$) and FC2 ($64 \to 10$) must sequentially execute on and reuse the **exact same** SIMD MAC hardware core via FSM state switching, with architectural evidence of operator instance sharing.
- **Interfaces**: AXI4-Lite control interface (`s_axilite`) and memory-mapped buffers for seamless Zynq PS-PL coupling.

### R2. End-to-End Simulation, Synthesis & Verification Flow (Level 1)
Provide a unified Makefile and script flow:
- Fast host-level C++ simulation (`make host-sim`) runnable with native `g++` without launching Vivado.
- Automated Vivado HLS batch script (`run_hls.tcl`) executing C-simulation (`csim`), C-synthesis (`csynth`), and C/RTL co-simulation (`cosim`) inside the Docker environment.
- Extract complete PPA metrics (LUT, FF, DSP, BRAM, latency in cycles and microseconds, initiation interval, clock slack).

### R3. Real-World Handwritten Digit Preprocessing & Domain Gap Analysis (Level 2)
Implement the Level 2 real-world data pipeline:
- Python preprocessing pipeline converting raw photos to $28 \times 28$ normalized tensors matching MNIST format: RGB to grayscale $\to$ polarity inversion $\to$ binarization $\to$ bounding-box crop $\to$ aspect-ratio scale $\to$ padding/centering $\to$ normalization to $[0, 1)$.
- Synthesizable C++ bounded preprocessor module or clearly documented SW/HW boundary.
- Benchmark inference accuracy on real-world photo cohorts vs. standard MNIST.
- Output a $10 \times 10$ confusion matrix, structured explanation of domain gap error sources, and background noise rejection results.

### R4. Quantization & Design Space Exploration (Level 3 Bonus, 10 Points)
Conduct a systematic post-training quantization (PTQ) and architecture trade-off exploration:
- Sensitivity sweep across at least 3 bit-width tiers (16-bit, 11-bit baseline, 8-bit, 4-bit) reporting measured accuracy, latency, and resource utilization directly from synthesis reports.
- Plot Bit-width vs. Accuracy and Bit-width vs. Resource curves, mathematically identifying the saturation knee point (拐点 at 11 bits).
- Plot the Pareto frontier (Accuracy vs. Resource / Latency) and provide an engineering recommendation for edge deployment.

### R5. Comprehensive Deliverables & Defense Documentation
Create structured reports and presentation materials aligned with team roles A through H:
- Level 1 Synthesis Report with block diagrams, FSM charts, and hardware reuse evidence.
- Level 2 Real-World Preprocessing & Domain Gap Report.
- Level 3 Quantization & DSE Pareto Report.
- Team Defense Presentation slide deck and Q&A cheat sheet.

## Acceptance Criteria

### Functional & Hardware Verification
- [ ] Native host simulation (`make host-sim`) completes and verifies accuracy $\ge 90\%$ (baseline 97.00%) on the 100 test samples in `hw/test_inputs.h`.
- [ ] Vivado HLS synthesis on `xc7z020clg400-1` passes timing at 10.0 ns (100 MHz) with positive slack.
- [ ] Hardware reuse is architecturally proven: only 1 instance of the 16-way SIMD MAC core is generated, serving both FC1 and FC2.
- [ ] Resource utilization fits comfortably within XC7Z020 budget: DSP $\le 32$, BRAM $\le 8$, LUT $\le 10,000$.
- [ ] C/RTL co-simulation passes with bit-level match against C simulation.

### Level 2 & Level 3 Deliverables
- [ ] Real-world preprocessing script successfully processes handwritten photo samples into $28 \times 28$ images.
- [ ] Domain gap evaluation reports accuracy comparison, confusion matrix, and background rejection rate.
- [ ] DSE synthesis data covers 16, 11, and 8 bit configurations with Pareto frontier visualization and deployment conclusion.
- [ ] Complete markdown documentation and defense slides are generated in `reports/`.

## Follow-up — 2026-09-09T01:35:22Z

Generate the comprehensive engineering reports, synthesis analysis, real-world domain gap documentation, quantization DSE analysis, and team defense presentation materials for the 784-64-10 MLP hardware accelerator in `reports/`, strictly aligned with the 8-person team roles (A~H) in `hw/智能芯片实践分工.md` and criteria in `hw/智能芯片选题任务书2026.md`.

Working directory: /home/coder/vivado
Integrity mode: development

## Requirements

### R1. Level 1 Architecture & Synthesis Report (`reports/level1_synthesis_report.md`)
Document the complete 784-64-10 MLP accelerator architecture:
- Time-Division Multiplexed (TDM) FSM controller states (`LOAD`, `FC1`, `RELU`, `FC2`, `ARGMAX`, `DONE`).
- Architectural and RTL proof of 16-way SIMD MAC core sharing between FC1 (49 chunks x 64 neurons) and FC2 (4 chunks x 10 classes) using `#pragma HLS INLINE OFF`.
- Full PPA table on Xilinx Zynq-7000 (`xc7z020clg400-1`) at 100 MHz (LUT, FF, DSP, BRAM, latency, initiation interval, clock slack).

### R2. Level 2 Real-World Preprocessing & Domain Gap Report (`reports/level2_domain_gap_report.md`)
Document the Level 2 real-world data validation:
- 7-step preprocessing dataflow (RGB to grayscale -> polarity inversion -> Otsu binarization -> bounding box crop -> aspect-ratio scale -> center of mass padding to 28x28 -> normalization).
- Experimental results comparing MNIST (97.00%) against real-world photo cohorts across lighting, stroke width, and noise variations (from `preprocessing/evaluate_domain_gap.py`).
- 10x10 confusion matrix, structured explanation of domain gap error causes, and negative background noise rejection analysis.

### R3. Level 3 Post-Training Quantization & DSE Report (`reports/level3_dse_pareto_report.md`)
Document the Level 3 (10 bonus points) quantization trade-off study:
- Multi-tier PTQ evaluation (16-bit, 11-bit baseline, 8-bit, 4-bit) with measured accuracy, resource utilization, and latency.
- Mathematical proof of the 11-bit saturation knee point (where >= 11 bits yields zero marginal accuracy gain, but < 8 bits suffers sharp degradation).
- Pareto frontier analysis (Accuracy vs. Resource / Latency) and concrete edge deployment recommendation.

### R4. Team Defense Presentation & Q&A Package (`reports/presentation_slides.md` & `reports/defense_qa_sheet.md`)
Provide defense materials formatted for presentation:
- Complete slide deck mapping project background, datapath, controller, preprocessing, and DSE to the 8 team members (Roles A through H).
- Comprehensive defense Q&A cheat sheet providing tailored technical questions and rigorous answers for each member (A through H).

## Acceptance Criteria

### Completeness & Alignment
- [ ] All 5 deliverable documents (`level1_synthesis_report.md`, `level2_domain_gap_report.md`, `level3_dse_pareto_report.md`, `presentation_slides.md`, `defense_qa_sheet.md`) exist in `reports/`.
- [ ] Reports directly reference the verified 784-64-10 network and `ap_fixed<11, 3, AP_RND, AP_SAT>` numerical format in `hw/weights.h`.
- [ ] Individual contributions and technical evidence are clearly allocated across all 8 roles (A: Architecture, B: Python/MNIST, C: Quantization, D: Datapath, E: Storage/FSM, F: Verification, G: Preprocessing, H: Synthesis/DSE).
- [ ] Real-world confusion matrix, domain gap error diagnosis, and DSE Pareto curves are included with quantitative backing.

## Follow-up — 2026-09-09T01:45:19Z

Resume and complete the 784-64-10 Multi-Layer Perceptron (MLP) hardware accelerator project on Xilinx Zynq-7000 (`xc7z020clg400-1`), continuing from Milestone 3 (Quantization & DSE) through Milestone 4 (the 5 defense deliverables in `reports/`) and Milestone 5 (final verification).

Working directory: /home/coder/vivado
Integrity mode: demo

## Prior Verified Context & Assets
- E2E Test Suite: All 236 tests in `e2e_tests/run_tests.py` pass 100% (`TEST_READY.md`).
- Milestone 2 (Preprocessing): Complete (`preprocessing/preprocess.py`, `preprocessing/evaluate_domain_gap.py`, 100 real-world photos in `preprocessing/real_world_data/`).
- Milestone 3 (DSE): Scripts `dse/ptq_sweep.py`, `dse/plot_pareto.py`, and figures in `reports/assets/` are implemented, ready for synthesis PPA correlation and formal documentation.
- Hardware Specifications: `hw/weights.h` (frozen weights in `ap_fixed<11, 3, AP_RND, AP_SAT>`), `hw/test_inputs.h` (100 MNIST samples with 97.00% baseline accuracy), `hw/mlp_accel.h`.
- Team Division Reference: `hw/智能芯片实践分工.md` (Roles A through H).
- Project Task Book: `hw/智能芯片选题任务书2026.md`.

## Requirements

### R1. Complete Milestone 3 (Quantization & DSE Deliverables)
Finalize the Level 3 PTQ and Design Space Exploration analysis:
- Execute `dse/ptq_sweep.py` evaluating quantized accuracy across bitwidths (16-bit, 11-bit baseline, 8-bit, 6-bit, 4-bit) on the 100 test samples in `hw/test_inputs.h`.
- Provide formal mathematical proof of the 11-bit saturation knee point ($\Delta \text{Acc} = 0$ for $W \ge 11$, degradation below 8 bits, and catastrophic collapse at 4 bits due to noise variance accumulation across 784 dimensions).
- Correlate FPGA synthesis metrics (LUT, FF, DSP, BRAM, latency) across bitwidth tiers from `dse/synth_results/dse_summary.json` and generate trade-off plots (`bitwidth_vs_accuracy.png`, `bitwidth_vs_resources.png`, `pareto_frontier.png`) in `reports/assets/`.

### R2. Complete Synthesizable HLS Core & Verification Flow in `hw/`
Implement the Level 1 synthesizable hardware accelerator and native simulation:
- Implement `hw/mlp_accel.cpp` with Datapath and Controller separation:
  - 16-way SIMD MAC compute core (`simd_mac16`) with balanced adder tree reduction and `#pragma HLS INLINE OFF`.
  - Sequential TDM FSM controller: FC1 ($784 / 16 = 49$ chunks $\times 64$ neurons = 3,136 cycles) and FC2 ($64 / 16 = 4$ chunks $\times 10$ neurons = 40 cycles) sequentially reuse the single 16-way SIMD MAC core (3,176 total compute cycles).
  - Sign-bit ReLU activation for FC1 and 10-way parallel Argmax classifier with deterministic tie-breaking.
  - AXI4-Lite control interface (`s_axilite`) and memory-mapped buffers for Zynq PS-PL integration.
- Implement `hw/tb_mlp.cpp` and `hw/Makefile` enabling native host simulation (`make host-sim`) runnable with `g++` and `-Iinclude_xilinx`.
- Implement `hw/run_hls.tcl` for Dockerized Vivado HLS batch execution (`csim`, `csynth`, `cosim`).

### R3. Comprehensive Defense Documentation & Slides in `reports/`
Generate the 5 required engineering deliverables strictly aligned with the 8-person team division (Roles A through H) in `hw/智能芯片实践分工.md`:
1. `reports/level1_synthesis_report.md`: Architecture specification, TDM FSM state transitions, RTL proof of SIMD MAC reuse (`#pragma HLS INLINE OFF`), and complete PPA table on XC7Z020 at 100 MHz (timing slack > 0, DSP $\le 32$, BRAM $\le 8$, LUT $\le 10,000$).
2. `reports/level2_domain_gap_report.md`: 7-step real-world image preprocessing flow, 100-sample cohort benchmark vs. MNIST, $10 \times 10$ confusion matrix, per-digit precision/recall, error diagnosis, and negative background noise rejection analysis.
3. `reports/level3_dse_pareto_report.md`: Multi-tier PTQ evaluation, mathematical knee point proof, synthesis-backed Pareto frontier curve, and edge deployment trade-off recommendations for Zynq-7000.
4. `reports/presentation_slides.md`: Oral defense presentation slide deck covering background, datapath, controller, preprocessing, DSE, and individual contributions structured for Roles A through H.
5. `reports/defense_qa_sheet.md`: Comprehensive defense Q&A cheat sheet providing challenging technical questions and rigorous, model-backed answers for each role (A~H).

### R4. Regression Testing & Final Pass (Milestone 5)
Run the full verification suite to ensure zero regressions:
- Run `python3 e2e_tests/run_tests.py` and ensure all 236 tests across Tiers 1-4 pass (100% pass rate).
- Run `make host-sim` in `hw/` and ensure native simulation passes with accuracy $\ge 90\%$.

## Acceptance Criteria

### Execution & Programmatic Verification
- [ ] `python3 dse/ptq_sweep.py` and `python3 dse/plot_pareto.py` run without error, and generated figures exist in `reports/assets/`.
- [ ] Native simulation in `hw/` compiles via `g++` and achieves $\ge 90\%$ accuracy (expected 97.00% or 98.00%) on the 100 test samples in `hw/test_inputs.h`.
- [ ] All 236 test cases in `python3 e2e_tests/run_tests.py` pass with 100% success rate and 0 failures.

### Deliverables Completeness & Traceability
- [ ] All 5 deliverable documents (`reports/level1_synthesis_report.md`, `reports/level2_domain_gap_report.md`, `reports/level3_dse_pareto_report.md`, `reports/presentation_slides.md`, `reports/defense_qa_sheet.md`) exist.
- [ ] All reports reference the verified 784-64-10 MLP topology and `ap_fixed<11, 3, AP_RND, AP_SAT>` numerical representation in `hw/weights.h`.
- [ ] All 8 roles (A: Architecture, B: Python/MNIST, C: Quantization, D: Datapath, E: Storage/FSM, F: Verification, G: Preprocessing, H: Synthesis/DSE) have dedicated contribution sections and defense Q&A coverage.
- [ ] Quantitative data (PPA table, confusion matrix, precision/recall, DSE numbers, Pareto curve) are embedded directly in the markdown reports.

