# Handoff Report: Specification Survey for Intelligent Chip Hardware Accelerator Programming Project

- **Agent ID**: `spec_miner_survey_1`
- **Role**: Specification Miner
- **Target Recipient / Orchestrator**: `3afaf208-c1d9-4190-b76f-3f61e55ad2aa`
- **Handoff Type**: Hard Handoff (Task Complete)
- **Timestamp**: 2026-09-09T01:09:00Z

---

## 1. Observation

1. **Source Documents & Files**:
   - `ORIGINAL_REQUEST.md`: Lines 1–67. Outlines high-level tasks R1 to R5 and acceptance criteria AC-1 to AC-13. Explicitly specifies synthesizable 784-64-10 MLP accelerator (`mlp_accel`), Datapath/Controller separation, 16-way SIMD MAC core, TDM FSM hardware reuse, AXI4-Lite control interface, `xc7z020clg400-1` target at 100 MHz (10.0 ns), and baseline weights in `hw/weights.h`.
   - `hw/智能芯片选题任务书2026.md`: Lines 1–137. Details 100-point course grade breakdown: Attendance (20), Midterm Defense (10), Final Defense (20), Midterm Report (20), Final Report (20), Teacher Evaluation (10). Defines Level 1 (MNIST verification $\ge 90\%$, synthesis on XC7Z020), Level 2 (Self-collected data, preprocessing dataflow, domain gap analysis), and Level 3 (10-point bonus: 3 pts bitwidth sweep, 3 pts results analysis with 11-bit knee point, 2 pts advanced exploration, 2 pts engineering conclusion).
   - `hw/智能芯片实践分工.md`: Lines 1–177. Provides exhaustive 8-person team division (Roles A through H), technical deliverables, acceptance criteria, interface freeze tables, and schedule from Sept 3 to Sept 18.
   - `hw/weights.h`: Lines 1–25. Declares `typedef ap_fixed<11, 3, AP_RND, AP_SAT> custom_data_t;`, `weights_L1[64][784]`, and `weights_L2[10][64]`. Confirms no bias terms exist.
   - `hw/test_inputs.h`: Lines 1–30. Declares `TEST_SAMPLE_COUNT = 100`, `test_inputs[TEST_SAMPLE_COUNT][784]`, and `test_labels[TEST_SAMPLE_COUNT]`.
   - `first_test/scripts/phase4_realworld/real_world_data/`: Contains 100 real-world handwriting PNG images (`c1_d0_rep0.png` through `c1_d9_rep9.png`).
2. **Environment & Toolchains Directly Observed**:
   - Compiler: `g++ (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0` supporting `-std=c++11`.
   - Headers: `include_xilinx/` contains Xilinx HLS C-simulation headers including `ap_fixed.h`, `ap_int.h`, and `hls_stream.h`.
   - Python Virtual Environment: `/home/coder/vivado/.venv_ai/bin/python` has `torch 2.14.0+cpu`, `torchvision 0.29.0+cpu`, `numpy 2.5.2`, `PIL 12.3.0`, and `matplotlib 3.11.1`.
   - Containerization: Docker 29.3.0 installed; Docker image `fpgatools/vivado:latest` (30.3 GB) is locally resident.
3. **Empirical Baseline Verification**:
   - Python baseline script executed matrix multiplication with `weights_L1[64][784]`, ReLU, and `weights_L2[10][64]` on the 100 test samples in `hw/test_inputs.h`.
   - Result: Exactly `97/100 correct (97.00%)`, validating baseline model convergence and data integrity.

---

## 2. Logic Chain

1. **Premise 1 (Model Definition)**: From `hw/weights.h` and `hw/智能芯片实践分工.md`, the network architecture is strictly 784-64-10 with no bias, using `ap_fixed<11, 3, AP_RND, AP_SAT>`.
2. **Premise 2 (Accuracy Baseline)**: The python forward pass validates that `weights_L1` and `weights_L2` produce 97.00% accuracy on `test_inputs.h`, comfortably exceeding the course acceptance threshold ($\ge 90\%$).
3. **Premise 3 (Hardware Constraints & Reuse)**: From `hw/智能芯片选题任务书2026.md` §1.3.2 and `ORIGINAL_REQUEST.md` R1, an unrolled design is forbidden. Time-division multiplexing (TDM) must schedule both FC1 and FC2 through a single 16-way SIMD MAC core ($16 \times \text{MAC}$). In FC1, 784 inputs are processed in $784 / 16 = 49$ chunks per neuron ($49 \times 64 = 3,136$ iterations); in FC2, 64 hidden activations are processed in $64 / 16 = 4$ chunks per neuron ($4 \times 10 = 40$ iterations).
4. **Premise 4 (Level 2 Domain Gap)**: From `hw/智能芯片选题任务书2026.md` §1.3.2 and `hw/智能芯片实践分工.md` §G, real camera photos suffer from polarity inversion, background noise, aspect ratio distortion, and centering offsets. An 8-step preprocessing pipeline (RGB to grayscale $\to$ invert $\to$ threshold $\to$ bounding box crop $\to$ aspect ratio scale $\to$ centroid center into $28 \times 28 \to$ normalize) bridges this gap. A $10 \times 10$ confusion matrix and background rejection metrics are explicitly required.
5. **Premise 5 (Level 3 DSE Rubric)**: From `hw/智能芯片选题任务书2026.md` 任务3 §3, the 10-point bonus requires:
   - 3 pts: $\ge 3$ bitwidth tiers in addition to baseline (16, 11, 8, 4 bit), reporting simulated accuracy, synthesis resources, and latency.
   - 3 pts: Bitwidth vs Accuracy and Bitwidth vs Resource curves, pinpointing the 11-bit saturation knee point and explaining low-bit drop.
   - 2 pts: Advanced experiment (parallelism overflow boundary or heterogeneous bitwidth).
   - 2 pts: Engineering deployment recommendation with data backing.
6. **Premise 6 (Deliverable Alignment)**: To satisfy the grading rubric and team division plan (Roles A through H), the project deliverables in `reports/` must be strictly decoupled into:
   - `level1_synthesis_report.md`
   - `level2_domain_gap_report.md`
   - `level3_dse_pareto_report.md`
   - `presentation_slides.md`
   - `defense_qa_sheet.md` (mapping directly to the individual defense responsibilities of Roles A through H).

---

## 3. Caveats

1. **Template Instantiation Overhead with Host `g++`**: When compiling `weights.h` (50,176 elements) and `test_inputs.h` (78,400 elements) directly inside C++ source files using `ap_fixed` templates, `g++` memory and compilation time can be high. In production HLS design and testbench, inputs and weights should either be loaded dynamically from binary/hex files or cleanly separated into translation units to keep compile times fast.
2. **Vivado Version Compatibility**: Vivado HLS 2018.3 runs inside the Docker container `fpgatools/vivado:latest`. When executing GUI-less batch runs, `automg_patch_20220104.tcl` and `Vivado_init.tcl` must be sourced to prevent known Y2K22 HLS timestamp parsing bugs.
3. **No Biases in Hardware**: Attention must be paid to ensure no biases are added in HLS or software testbenches, as the pre-trained weights strictly omit biases.

---

## 4. Conclusion

The specification survey is fully complete and authoritative. All requirements across Level 1 (synthesizable core, TDM FSM reuse, SIMD MAC, AXI4-Lite), Level 2 (real-world preprocessing, confusion matrix, domain gap error analysis), Level 3 (PTQ sweep, 11-bit knee point proof, Pareto frontier, edge recommendation), grading rubrics (100 base + 10 bonus points), acceptance criteria, and 8-member role assignments (Roles A through H) have been thoroughly cataloged into:
`/home/coder/vivado/.agents/spec_miner_survey_1/survey_spec_report.md`

All prerequisites, interfaces, formulas, and constraints are defined with sufficient clarity for downstream implementation, verification, and documentation agents to execute without ambiguity.

---

## 5. Verification Method

1. **Verify Report Existence & Completeness**:
   ```bash
   test -f /home/coder/vivado/.agents/spec_miner_survey_1/survey_spec_report.md && echo "REPORT_EXISTS"
   grep -E "16-Way SIMD|TDM|AXI4-Lite|ap_fixed<11, 3>|Knee Point|Roles A through H" /home/coder/vivado/.agents/spec_miner_survey_1/survey_spec_report.md
   ```
2. **Verify Python Baseline Accuracy**:
   ```bash
   python3 -c '
   import re, numpy as np
   def get_arr(path, name):
       with open(path) as f: c = f.read()
       m = re.search(rf"{name}\s*\[.*?\]\s*\[.*?\]\s*=\s*\{{(.*?)\}};", c, re.DOTALL)
       return np.array([float(x) for x in re.findall(r"([-+]?[0-9]*\.?[0-9]+(?:[eE][-+]?[0-9]+)?)f?", m.group(1))])
   w1 = get_arr("/home/coder/vivado/hw/weights.h", "weights_L1").reshape(64, 784)
   w2 = get_arr("/home/coder/vivado/hw/weights.h", "weights_L2").reshape(10, 64)
   inp = get_arr("/home/coder/vivado/hw/test_inputs.h", "test_inputs").reshape(100, 784)
   with open("/home/coder/vivado/hw/test_inputs.h") as f: c = f.read()
   lbls = np.array([int(x) for x in re.findall(r"\b\d+\b", re.search(r"test_labels\s*\[.*?\]\s*=\s*\{(.*?)\};", c, re.DOTALL).group(1))])
   acc = np.mean(np.argmax(np.dot(np.maximum(0, np.dot(inp, w1.T)), w2.T), axis=1) == lbls)
   print(f"VERIFIED ACCURACY: {acc * 100:.2f}%")
   assert acc == 0.97
   '
   ```
3. **Invalidation Conditions**:
   - If any requirement from `hw/智能芯片选题任务书2026.md` or `hw/智能芯片实践分工.md` is omitted.
   - If the baseline weights fail to reproduce $\ge 90\%$ accuracy.
   - If the hardware architecture violates single SIMD MAC operator instantiation.
