# Comprehensive Specification Survey Report: Intelligent Chip Hardware Accelerator Programming Project

- **Project Title**: Synthesizable 784-64-10 MLP Inference Accelerator on Xilinx Zynq-7000 (XC7Z020)
- **Authoritative Sources**:
  1. `hw/智能芯片选题任务书2026.md` (Course Task Book & Grading Rubrics)
  2. `hw/智能芯片实践分工.md` (8-Person Team Division Plan & Technical Specifications)
  3. `ORIGINAL_REQUEST.md` (User Request, Baseline Constraints & Acceptance Criteria)
  4. `hw/weights.h` (Verified 784-64-10 Fixed-Point Weights, `ap_fixed<11, 3, AP_RND, AP_SAT>`)
  5. `hw/test_inputs.h` (100 Verified MNIST Test Samples & Golden Labels, 97.00% Accuracy)
  6. `first_test/` (Prior Exploratory Framework, Real-World Data & Report Structure)
- **Author / Agent**: Specification Miner (`spec_miner_survey_1`)
- **Date**: 2026-09-09

---

## 1. Executive Summary & Specification Scope

This project entails the complete design, verification, synthesis, domain-gap evaluation, design-space exploration (DSE), and technical defense documentation for a hardware accelerator targeting the Multi-Layer Perceptron (MLP) on the Xilinx Zynq-7000 SoC (`xc7z020clg400-1`).

The technical roadmap follows **Route A (MLP Acceleration)** across three strictly graded levels:
1. **Level 1 (Core Synthesizable Accelerator & Flow)**:
   A synthesizable C++ HLS accelerator (`mlp_accel`) with explicit **Datapath / Controller separation**, a **16-way SIMD MAC compute core**, time-division multiplexed (**TDM FSM**) hardware reuse across both FC1 ($784 \to 64$) and FC2 ($64 \to 10$) layers, an **AXI4-Lite control interface** with memory-mapped feature buffers, a native `g++` host simulation flow, automated Vivado HLS batch synthesis/co-simulation, and post-synthesis PPA extraction meeting XC7Z020 resource budgets.
2. **Level 2 (Real-World Pipeline & Domain Gap Analysis)**:
   An end-to-end handwriting image acquisition and preprocessing pipeline (Python reference and bounded C++ model) addressing domain shift from real-world photography to MNIST formatting ($28 \times 28$, single channel, normalized $[0, 1)$), followed by inference accuracy benchmarking, $10 \times 10$ confusion matrix derivation, systematic error attribution, and background noise rejection (blank/clutter non-digit samples).
3. **Level 3 (Advanced Bonus - PTQ & DSE Pareto Optimization, 10 Points)**:
   Post-training quantization (PTQ) sensitivity analysis across four bit-width configurations (16-bit, 11-bit baseline, 8-bit, and 4-bit), mathematical identification of the saturation knee point (11 bits), Pareto frontier construction (Accuracy vs. Resource / Latency), boundary violation analysis under parallelism scaling, and deployment recommendations for edge computing.
4. **Deliverables & Defense**:
   Generation of modular reports in `reports/` (Synthesis, Domain Gap, DSE Pareto), presentation slide deck, and an 8-role defense Q&A cheat sheet mapping to Roles A through H.

---

## 2. Detailed System Requirements

### 2.1 Level 1: Synthesizable 784-64-10 MLP Accelerator & Flow

#### 2.1.1 Architectural Parameters & Network Topology
- **Topology**: Feedforward MLP with 784 input nodes, 64 hidden nodes, and 10 output nodes:
  $$\text{Input } (28 \times 28 = 784) \longrightarrow \text{FC1 } (784 \to 64) \longrightarrow \text{ReLU} \longrightarrow \text{FC2 } (64 \to 10) \longrightarrow \text{Argmax } (10 \to 1 \text{ class } [0..9])$$
- **Bias**: Explicitly **No Bias** in both FC1 and FC2 layers to save on-chip DSP, BRAM, and routing overhead.
- **Weights Shape & Arrangement**:
  - FC1 Weight Matrix: `weights_L1[64][784]` (50,176 elements).
  - FC2 Weight Matrix: `weights_L2[10][64]` (640 elements).
  - Arrangement in memory: row-major `W[out][in]` mapping directly to sequential SIMD MAC dot-products.
- **Target Device & Clock**:
  - Part: Xilinx Zynq-7000 `xc7z020clg400-1`.
  - Target Frequency: 100 MHz (Clock Period = 10.0 ns, uncertainty = 1.25 ns default).
  - Timing Constraint: Positive setup/hold slack required ($T_{\text{slack}} > 0$).
- **Resource Envelope**:
  - DSP48E slices $\le 32$ (out of 220 available on XC7Z020; allocation for 16-way SIMD MAC is $\approx 16$ DSPs).
  - Block RAM (BRAM_18K) $\le 8$ (out of 280 available).
  - LUT $\le 10,000$ (out of 53,200 available).
  - Flip-Flops (FF) $\le 10,000$ (out of 106,400 available).

#### 2.1.2 Datapath Specification
- **16-Way SIMD Vector MAC Unit**:
  - Single parallel compute core computing 16 multiply-accumulate operations per cycle:
    $$\text{VectorDot16}(\mathbf{x}_{16}, \mathbf{w}_{16}) = \sum_{k=0}^{15} x_k \cdot w_k$$
  - Balanced binary adder tree (depth $\lceil \log_2(16) \rceil = 4$) to minimize critical path delay and maximize clock frequency.
  - Fully pipelined execution with Initiation Interval $\text{II} = 1$ in the inner loop.
- **Activation Function (ReLU)**:
  - Non-linear function: $f(z) = \max(0, z)$.
  - Hardware implementation: Sign-bit inspection or conditional zeroing; strictly executed after FC1 accumulation completes.
- **Classification Output (Argmax)**:
  - Parallel or pipelined comparator tracking `max_val` and `best_class` over 10 output logits.
  - Tie-breaking deterministic rule: Lowest class index wins upon tie (`if (val > max_val)`).

#### 2.1.3 Hardware Reuse via Time-Division Multiplexing (TDM FSM)
- **Strict Reuse Constraint**: Both FC1 ($784 \to 64$) and FC2 ($64 \to 10$) MUST sequentially execute on and reuse the **exact same physical 16-way SIMD MAC core**.
- **Architectural Proof Requirement**:
  - Synthesis report must demonstrate a single instance of the vector MAC operator/module.
  - Full unrolling of FC1 and FC2 is strictly forbidden.
- **TDM Controller FSM States**:
  1. `FSM_IDLE`: Wait for `ap_start` via AXI4-Lite control.
  2. `FSM_LOAD`: Ingest 784 input pixels into local input buffer.
  3. `FSM_FC1_COMPUTE`: Drive 49 chunks of 16-element dot products per hidden neuron ($49 \times 64 = 3,136$ SIMD cycles); accumulate into hidden register.
  4. `FSM_RELU`: Apply ReLU and store 64 activation values into intermediate buffer.
  5. `FSM_FC2_COMPUTE`: Drive 4 chunks of 16-element dot products per output neuron ($4 \times 10 = 40$ SIMD cycles); accumulate into output register.
  6. `FSM_ARGMAX`: Determine winning class index ($0..9$) and logit value.
  7. `FSM_DONE`: Assert `ap_done`, raise interrupt flag, present `prediction` on output register, wait for next start.

#### 2.1.4 Interface Contracts & Zynq PS-PL Integration
- **Control Interface**: AXI4-Lite slave (`s_axilite`, bundle `CTRL_BUS`):
  - Base Address Offset `0x00`: Control register (`bit 0: ap_start`, `bit 1: ap_done`, `bit 2: ap_idle`, `bit 3: ap_ready`, `bit 7: auto_restart`).
  - Base Address Offset `0x04`: Global Interrupt Enable (`GIE`).
  - Base Address Offset `0x08`: Interrupt Enable Register (`IER`).
  - Base Address Offset `0x0C`: Interrupt Status Register (`ISR`).
  - Base Address Offset `0x10`: Output prediction register (32-bit scalar, returning winning digit $0..9$).
  - Base Address Offset `0x14`: Output confidence/logit (optional fixed-point scalar).
- **Data Buffers**:
  - Memory-mapped BRAM/AXI slave buffers for 784 inputs (`in_vec[784]`) and 10 outputs (`out_vec[10]`).
  - Dual-port on-chip BRAM or array partition to sustain 16 reads/cycle for the SIMD MAC.

#### 2.1.5 Simulation & Build Toolchain
- **Host Native Simulation**:
  - Fast C++ simulation executable runnable with native Linux `g++` (`-std=c++11 -Iinclude_xilinx`).
  - Executes instant functional verification over the 100 MNIST golden samples in `hw/test_inputs.h`.
- **Vivado HLS Batch Flow**:
  - Scripted non-GUI batch execution via `run_hls.tcl` executed inside Docker container `fpgatools/vivado:latest`.
  - Supports discrete targets: `csim` (C simulation), `csynth` (C synthesis to RTL), `cosim` (C/RTL co-simulation), `export` (IP export).
- **PPA Extraction Requirement**:
  - Table of post-synthesis metrics: LUT, FF, DSP, BRAM, Min/Max Latency (cycles and microseconds), Initiation Interval (II), Clock Slack.

---

### 2.2 Level 2: Real-World Handwritten Digit Preprocessing & Domain Gap Analysis

#### 2.2.1 Real-World Data Ingestion & Physical Specifications
- **Data Cohort**: Real handwritten digits captured with mobile cameras/sensors under varying illumination, angles, and pen stroke widths.
- **Dataset Structure**:
  - Digit classes $0..9$, 10 samples per digit class per team member (cohort of $\ge 100$ total images).
  - Background noise cohort: $\ge 10$ non-digit images per member (blank paper, wooden desk, cloth, keyboard clutter).
  - Partitioning: Separation into Debug/Calibration set (2 writers) and Final Evaluation set (remaining writers) to prevent cross-contamination.

#### 2.2.2 End-to-End Preprocessing Pipeline
Raw photographs cannot be directly fed to the accelerator due to resolution, aspect ratio, color channel, and polarity mismatches. The pipeline executes:
1. **Image Decode**: Read raw RGB/BGR image (JPEG/PNG).
2. **Grayscale Conversion**:
   $$Y = 0.299 R + 0.587 G + 0.114 B$$
3. **Polarity Uniformity**:
   Standard MNIST has white digits on a black background ($\text{digit} \approx 1.0, \text{background} = 0.0$). Camera photos have dark ink on white paper ($\text{ink} \approx 0, \text{paper} \approx 255$). Polarity inversion:
   $$I_{\text{inv}}(x, y) = 255 - Y(x, y)$$
4. **Binarization & Background Noise Suppression**:
   Otsu's thresholding or adaptive Gaussian thresholding with morphological opening to eliminate isolated paper grain and sensor noise.
5. **Bounding Box (ROI) Extraction**:
   Locate foreground ink mass coordinates: $[y_{\min}, y_{\max}, x_{\min}, x_{\max}]$.
6. **Aspect-Ratio Preserving Scaling**:
   Scale the foreground bounding box so that the longest dimension equals 20 pixels, maintaining digit aspect ratio:
   $$s = \frac{20.0}{\max(H_{\text{box}}, W_{\text{box}})}$$
7. **Center-of-Mass / Geometric Padding**:
   Pad the $20 \times W'$ or $H' \times 20$ box to $28 \times 28$ by centering the center of mass (mass centroid) into the center $[14.0, 14.0]$ of the $28 \times 28$ grid, strictly matching the NIST/MNIST normalization standard.
8. **Range Normalization & Fixed-Point Casting**:
   Divide pixel values by $255.0$ to map to $[0.0, 1.0)$, cast to `ap_fixed<11, 3, AP_RND, AP_SAT>`.

#### 2.2.3 Hardware/Software Partition Boundary
- **Software Domain**: File I/O, variable-size JPEG decompression, multi-megapixel downscaling, and variable bounding-box detection on host PS.
- **Hardware/HLS Domain**: A bounded C++ module or direct accelerator streaming interface with defined maximum input dimensions (e.g. bounded $64 \times 64$ patch centering/downsampling or directly ingesting the $28 \times 28$ normalized vector into `mlp_accel`).

#### 2.2.4 Domain Gap Evaluation & Attribution
- **Accuracy Benchmarking**: Quantitative comparison of accuracy on standard MNIST (97.00%) vs. real-world photo dataset.
- **$10 \times 10$ Confusion Matrix**: Categorization of actual vs. predicted classes across all real-world test images.
- **Error Source Attribution Taxonomy**:
  1. *Stroke Width Disparity*: Ballpoint/fine pen creates 1-pixel thin strokes vs. MNIST 2-3 pixel anti-aliased brush strokes.
  2. *Illumination Gradients & Shadowing*: Non-uniform ambient light creates false foreground edges during thresholding.
  3. *Centering Discrepancies*: Off-by-one shifts drastically change dot products with hidden layer weights.
  4. *Aspect-Ratio Distortion*: Elongated digits (e.g. '1' or '7') distorted when improperly centered.
- **Background Noise Rejection**:
  - Evaluation on non-digit blank/clutter images.
  - Metrics: False Acceptance Rate (FAR, clutter classified as digit with high confidence) and False Rejection Rate (FRR, valid digit rejected).

---

### 2.3 Level 3: Advanced Post-Training Quantization (PTQ) & Design Space Exploration (10-Point Bonus)

#### 2.3.1 PTQ Theory & Numerical Foundation
- **PTQ Scope**: Post-training quantization only; no backpropagation or retraining.
- **Global Scaling & Monotonicity Preservation**:
  Because FC layers are linear transforms ($\mathbf{y} = \mathbf{W}\mathbf{x}$), uniform scaling by constant factor $\alpha$ yields $\alpha \mathbf{y}$. Since $\text{Softmax}$ and $\text{Argmax}$ are strictly monotonic:
  $$\arg\max_i (\alpha y_i) = \arg\max_i (y_i) \quad (\forall \alpha > 0)$$
  Decision boundaries are invariant to global scaling. Weights and activations are normalized into $[-1.0, 1.0]$.

#### 2.3.2 Bit-Width Sensitivity Sweep Across 4 Tiers
Synthesis and simulation must be executed and reported across at least 4 discrete bit-width configurations:
1. **Tier 1: 16-bit High Precision** (`ap_fixed<16, 4>`): Reference high-precision floating/fixed baseline.
2. **Tier 2: 11-bit Nominal Baseline** (`ap_fixed<11, 3, AP_RND, AP_SAT>`): Production operating baseline.
3. **Tier 3: 8-bit Compact Integer** (`ap_fixed<8, 2>` or `ap_fixed<8, 3>`): Common INT8 embedded edge format.
4. **Tier 4: 4-bit Aggressive Quantization** (`ap_fixed<4, 2>`): Sub-byte extreme quantization.

*Mandatory Reporting Rule*: For every bit-width tier, three concrete empirical metrics must be provided from actual simulation and Vivado HLS synthesis reports:
- **Accuracy (%)** on standard test set.
- **Hardware Resource Utilization** (LUT, FF, DSP, BRAM).
- **Inference Latency** (clock cycles and execution time in $\mu\text{s}$).
No theoretical approximations or hand-waving estimates are permitted.

#### 2.3.3 Saturation Knee Point (拐点) & Mathematical Criterion
- **Knee Point Proof**: Locate the point of diminishing returns where increasing word length yields zero or negligible accuracy gain ($\Delta \text{Acc} < 0.2\%$), while consuming linearly or quadratically higher LUT/DSP/BRAM resources.
- Authoritative target: 11-bit (`ap_fixed<11, 3>`) is the saturation knee point (achieving 97.00% accuracy, equal to float32). Below 8 bits, accuracy collapses due to insufficient dynamic range and cumulative truncation noise in the 784-element dot product.

#### 2.3.4 Pareto Frontier Analysis & Optimization Dimension
- Construct the multi-objective Pareto Frontier:
  - Objective 1: Maximize Accuracy.
  - Objective 2: Minimize Resource Area (LUT/DSP product or equivalent gate count).
  - Objective 3: Minimize Latency (Cycles).
- Identify the set of non-dominated solutions.
- **Advanced Exploration Dimension**:
  - *Bitwidth $\times$ Parallelism scaling boundary*: Evaluate unrolled/parallel configurations (e.g. 16-way vs 32-way vs 64-way SIMD), identifying the boundary where DSP or BRAM exhaustion prevents synthesis or routing on XC7Z020.
  - *Heterogeneous allocation*: Different bitwidths for weights vs. input activations (e.g. 8-bit weights, 11-bit activations).

#### 2.3.5 Edge Deployment Engineering Recommendation
- Provide a rigorous, evidence-based synthesis recommendation:
  - Which configuration is optimal for an edge IoT sensor (ultra-low power, strict area budget)?
  - Which configuration is optimal for a real-time smart surveillance camera (low latency, high accuracy)?

---

## 3. Grading Rubrics & Scoring Breakdown

Extracted directly from `hw/智能芯片选题任务书2026.md`:

### 3.1 Course Overall Grade Breakdown (100 Points Base + 10 Points Bonus)

| Item | Component (考核项目) | Weight / Points | Key Criteria |
| :---: | :--- | :---: | :--- |
| 1 | **Attendance (出勤)** | **20%** (20 pts) | Daily practice attendance, laboratory discipline, schedule adherence. |
| 2 | **Midterm Defense (中期答辩)** | **10%** (10 pts) | Presentation of baseline progress, architecture definition, interface freezing. |
| 3 | **Final Defense (期末答辩)** | **20%** (20 pts) | Live simulation demonstration, technical Q&A, cross-team mastery. |
| 4 | **Midterm Report (中期报告)** | **20%** (20 pts) | Structural documentation, initial C-sim results, interface specifications. |
| 5 | **Final Report (期末报告)** | **20%** (20 pts) | Full engineering report, synthesis PPA, domain gap analysis, DSE results. |
| 6 | **Instructor Evaluation (教师评估)** | **10%** (10 pts) | Code cleanliness, engineering rigor, Git commit traceability, teamwork. |
| -- | **Total Base Score (基础总分)** | **100 pts** | Cap for standard course evaluation. |
| **+** | **Level 3 Extra Bonus (附加分)** | **+10 pts** | Advanced PTQ and DSE exploration (capped at 100 total overall grade). |

### 3.2 Level 3 Advanced Bonus Rubric Breakdown (10 Points Total)

| Sub-item | Criteria & Standards (达成标准) | Score |
| :--- | :--- | :---: |
| **Bit-width Sweep Experiment**<br>(位宽扫描实验) | In addition to baseline, perform experiments on no fewer than 3 bit-width tiers (e.g. 16, 8, 4 bit). Every tier must provide three measured figures: **Accuracy**, **Resource Utilization**, and **Latency**. Figures must originate from simulation and synthesis reports, **no estimation permitted**. | **3 pts** |
| **Results Analysis**<br>(结果分析) | Plot two curves: **Bitwidth vs. Accuracy** and **Bitwidth vs. Resources**. Identify where the saturation knee point lies ("no further accuracy gain with higher bitwidth"). Provide physical explanations for low bit-width accuracy degradation (11-bit knee point; degradation below 8 bits). | **3 pts** |
| **Advanced Exploration**<br>(进阶实验，选做其一) | Choose at least one advanced exploration:<br>1. **Bitwidth $\times$ Parallelism cross-experiment**: Identify "cannot fit" boundary where resource capacity is exceeded on XC7Z020.<br>2. **Heterogeneous Bit-width Allocation**: Different bit-widths for weights vs. pixels with architectural justification.<br>3. **Binarization Experiment**: Evaluate BNN using XNOR and popcount instead of DSP multipliers. | **2 pts** |
| **Engineering Conclusion**<br>(工程结论) | Formulate a concise conclusion answering: "If this design were to be deployed in a real-world edge product, which configuration do you recommend and why?" Conclusion must be backed by empirical synthesis data. | **2 pts** |
| **Level 3 Total** | | **10 pts** |

---

## 4. Acceptance Criteria Matrix

| # | Criterion | Verification Target | Pass/Fail Condition |
|---|---|---|---|
| **AC-1** | Host Functional Simulation | Host C++ `make host-sim` | Accuracy $\ge 90\%$ (Baseline 97.00% on 100 test samples in `hw/test_inputs.h`) |
| **AC-2** | Vivado HLS C-Simulation | `vivado_hls -f run_hls.tcl csim` | Exact bit-level accuracy match against Host C++ simulation |
| **AC-3** | Vivado HLS C-Synthesis | `vivado_hls -f run_hls.tcl csynth` | Synthesizes successfully on `xc7z020clg400-1` at 10.0 ns target clock |
| **AC-4** | Timing Closure | Post-synthesis timing report | Worst Negative Slack $\text{WNS} \ge 0.0$ ns ($T_{\text{slack}} > 0$) at 100 MHz |
| **AC-5** | Proven Hardware Reuse | Synthesis hierarchy & operator report | Exactly **ONE** instance of 16-way SIMD MAC core generated for both FC1 and FC2 |
| **AC-6** | XC7Z020 Resource Envelope | Post-synthesis utilization report | $\text{DSP} \le 32$ ($\le 15\%$), $\text{BRAM} \le 8$ ($\le 3\%$), $\text{LUT} \le 10,000$ ($\le 19\%$), $\text{FF} \le 10,000$ ($\le 9\%$) |
| **AC-7** | C/RTL Co-Simulation | `vivado_hls -f run_hls.tcl cosim` | Co-simulation passes with bit-level match between C model and generated Verilog/VHDL RTL |
| **AC-8** | Real-World Image Preprocessing | Python & C++ preprocessing scripts | Converts raw camera photos into $28 \times 28$ normalized tensors matching MNIST conventions |
| **AC-9** | Domain Gap Evaluation | Python benchmark script & report | Outputs quantitative comparison, $10 \times 10$ confusion matrix, and noise rejection rates |
| **AC-10** | DSE Multi-Bitwidth Sweep | HLS synthesis across 16, 11, 8, 4 bit | Real synthesis reports for all 4 tiers, accuracy vs bitwidth curve, resource vs bitwidth curve |
| **AC-11** | Saturation Knee Identification | Mathematical analysis in DSE report | Demonstrates 11-bit saturation knee with plateau above and sharp drop below 8-bit |
| **AC-12** | Pareto Frontier & Recommendation | DSE report & plots | Visualizes Accuracy-Resource-Latency trade-off curve and provides edge deployment recommendation |
| **AC-13** | Documentation & Defense Assets | `reports/` folder | Complete Markdown reports, slide deck (`presentation_slides.md`), and Q&A cheat sheet (`defense_qa_sheet.md`) |

---

## 5. 8-Person Role Division Matrix (Roles A through H)

Extracted from `hw/智能芯片实践分工.md`:

| Role | Title / Focus | Core Deliverables (技术交付物) | Acceptance Evidence & Verification | Defense Focus (答辩防线) |
| :---: | :--- | :--- | :--- | :--- |
| **A** | **Team Leader, System Architecture & Integration**<br>(组长、系统架构与集成) | • Project schedule & task board<br>• Interface specification contract<br>• Overall architecture & dataflow diagrams<br>• Top-level accelerator integration (`mlp_accel`)<br>• Integrated presentation slides & report collation | Reproducibility by F on clean environment; all rubric items mapped to owner and evidence path; top-level clean compilation. | Overall architecture rationale, PS-PL memory mapping, interface contract freezing, scheduling, risk mitigation. |
| **B** | **MNIST Data & Python Float Reference**<br>(MNIST 与 Python 参考模型) | • Dataset download script & verification<br>• Train/Val/Test split (55k/5k/10k)<br>• PyTorch float32 MLP model (no bias)<br>• Exported golden weights (`weights.h`)<br>• Layer-by-layer reference vectors | Verification set accuracy $> 95\%$; zero transposition or sign mismatch in exported C++ headers; bit-level alignment. | Model topology justification, no-bias rationale, PyTorch vs C array indexing alignment, validation methodology. |
| **C** | **Fixed-Point Quantization & Numerical Analysis**<br>(定点量化与数值分析) | • Dynamic range statistics across layers<br>• Fixed-point type specification table<br>• Bit-accurate Python/C++ quantization model<br>• Scaling factor & saturation rules<br>• Quantization loss analysis | Hardware simulation accuracy $\ge 90\%$ (target within 1% of float32); identical arithmetic behavior with HLS bit types (`ap_fixed`). | Why `ap_fixed<11, 3>`, integer vs fractional bit allocation, accumulator overflow margin, rounding vs truncation trade-off. |
| **D** | **HLS Compute Datapath**<br>(HLS 运算数据通路) | • 16-way SIMD MAC core implementation<br>• Balanced adder tree in C++<br>• Sign-bit ReLU module<br>• Parallel Argmax comparator<br>• Unit testbenches with boundary vectors | Zero numerical discrepancy vs bit-accurate C model; passes unit tests with zero/max/negative inputs; passes HLS synthesis. | SIMD parallelization factor, adder tree latency, sign-bit extraction vs branching, tie-breaking rule in Argmax. |
| **E** | **HLS Storage & Control Architecture**<br>(HLS 存储与控制) | • Weight array storage mapping<br>• Input & intermediate feature buffers<br>• Address generation logic for FC1/FC2<br>• TDM state machine controller<br>• Ping-pong buffer coordination | No state corruption across consecutive inferences; zero out-of-bounds memory accesses; verified single MAC instantiation. | FSM state transition diagram, address generation formulas, memory partitioning (`complete` vs `cyclic`), TDM sharing proof. |
| **F** | **Simulation Verification & Fault Localization**<br>(仿真验证与故障定位) | • Unified testbench (`tb_mlp.cpp`)<br>• Multi-tier test suite (10-sample, 100-sample, 10k)<br>• Layer-by-layer mismatch localization tool<br>• Confusion matrix generator<br>• Live defense demonstration script | Formal test run achieving 97.00% on 100 samples; C-sim vs C/RTL co-sim distinction; error log catalog. | Simulation hierarchy (C vs Co-sim vs RTL), layer-wise discrepancy isolation, co-simulation waveforms, demo reproducibility. |
| **G** | **Real-World Data & Preprocessing**<br>(自采数据与预处理) | • Photography & acquisition specification<br>• Cohort dataset (100 digit + 10 background images)<br>• Python 8-step preprocessing pipeline<br>• Bounded C++ preprocessing model<br>• Domain gap report & confusion matrix | End-to-end execution of camera photo $\to 28 \times 28 \to$ accelerator; transparent reporting of real-world accuracy and error causes. | Preprocessing pipeline design, centroid centering vs bounding-box, noise filtering, domain gap error attribution, background rejection. |
| **H** | **Synthesis, Resource & Performance Analysis**<br>(综合实现与性能分析) | • Automated Vivado HLS Tcl scripts (`run_hls.tcl`)<br>• Multi-configuration synthesis logs<br>• PPA comparison tables (LUT, FF, DSP, BRAM, Latency)<br>• Bitwidth sweep & Pareto frontier plots<br>• Resource overflow boundary identification | Synthesis passes on XC7Z020 with positive slack; all figures sourced directly from raw synthesis reports; reproducible Tcl scripts. | Resource budget adherence, DSP utilization breakdown, critical path timing analysis, II and latency formulas, DSE curves. |

---

## 6. Features Discovered Table

Per the Specification Miner guidelines, all discovered features across the authoritative sources are cataloged below:

| # | Category | Feature | Description | Inputs | Outputs | Error Behavior | Discovered Via |
|---|---|---|---|---|---|---|---|
| 1 | Compute | 16-way SIMD MAC Core | Parallel dot-product engine computing 16 multiplications and summing via 4-level balanced adder tree | 16 data inputs, 16 weight inputs (`custom_data_t`) | Partial sum accumulator | Saturation on overflow (`AP_SAT`) | `智能芯片选题任务书2026.md` §1.3.2, `ORIGINAL_REQUEST.md` R1 |
| 2 | Compute | Sign-Bit ReLU | Computes non-linear activation $\max(0, z)$ via sign-bit inspection | Single accumulator logit | Non-negative activated value | Negative values clamped to 0 | `智能芯片选题任务书2026.md` §1.3.2, `智能芯片实践分工.md` §D |
| 3 | Compute | Parallel Argmax | Parallel/pipelined comparator finding the index of the maximum logit across 10 classes | 10 output logits | Scalar digit index $0..9$ | Deterministic tie-breaking: lower index wins | `智能芯片实践分工.md` §D |
| 4 | Architecture | TDM Hardware Reuse | FC1 ($784 \to 64$) and FC2 ($64 \to 10$) sequentially share the single 16-way SIMD MAC core | Layer control signals, weight pointers | Completed layer feature map | Single MAC operator instance generated | `智能芯片选题任务书2026.md` §1.3.2, `ORIGINAL_REQUEST.md` R1 |
| 5 | Storage | On-Chip Ping-Pong Buffers | Dual-port BRAM / partitioned array buffering 784 inputs and 64 hidden activations | Memory-mapped writes from PS or previous layer | 16 parallel operands/cycle to MAC | Out-of-bounds address protection | `智能芯片实践分工.md` §E |
| 6 | Control | AXI4-Lite Control Bus | Standard memory-mapped slave interface (`s_axilite`) for control registers and interrupt status | AXI4-Lite read/write transactions (`ap_start`, etc.) | `ap_done`, `ap_idle`, `prediction` | Bus timeout on invalid offset | `ORIGINAL_REQUEST.md` R1 |
| 7 | Numerical | Fixed-Point Format | Numerical representation `ap_fixed<11, 3, AP_RND, AP_SAT>` (1 sign, 2 int, 8 frac bits) | Float weights/pixels | 11-bit quantized representation | Symmetric saturation on overflow, round to nearest | `hw/weights.h`, `hw/test_inputs.h` |
| 8 | Build | Host C++ Fast Simulation | Native compile target (`make host-sim`) runnable with host `g++` without Vivado license | 100 MNIST samples in `hw/test_inputs.h` | Console accuracy output ($\ge 90\%$) | Non-zero exit code if accuracy $< 90\%$ | `Makefile`, `ORIGINAL_REQUEST.md` R2 |
| 9 | Build | Vivado HLS Batch Script | Automated non-GUI Tcl execution (`run_hls.tcl`) inside Docker container `fpgatools/vivado:latest` | Tcl command (`csim`, `csynth`, `cosim`, `export`) | Synthesis reports, RTL netlists, co-sim logs | Halts on syntax/timing errors with non-zero exit | `Makefile`, `ORIGINAL_REQUEST.md` R2 |
| 10 | Data / L2 | Image Grayscale & Polarity Inversion | Converts 3-channel RGB camera photo to inverted single-channel luminance ($255 - Y$) | Raw RGB image array | Grayscale array with white digit on black background | Rejects non-image files gracefully | `智能芯片实践分工.md` §G |
| 11 | Data / L2 | Bounding-Box ROI Cropping | Identifies minimum bounding rectangle containing the digit ink mass | Inverted grayscale image | Cropped foreground sub-image | Fallback to full frame if bounding box empty | `智能芯片选题任务书2026.md` §1.3.2, `智能芯片实践分工.md` §G |
| 12 | Data / L2 | Aspect-Ratio Preserving Scaling | Resizes longest dimension of cropped digit to 20 pixels, keeping aspect ratio | Cropped sub-image | Rescaled digit ($20 \times W'$ or $H' \times 20$) | Avoids division by zero if $H=0$ or $W=0$ | `智能芯片实践分工.md` §G |
| 13 | Data / L2 | Center-of-Mass Centering | Computes pixel mass centroid and places it at center $[14.0, 14.0]$ of $28 \times 28$ image | Rescaled digit | $28 \times 28$ normalized image | Defaults to geometric center if mass is zero | `智能芯片实践分工.md` §G |
| 14 | Evaluation / L2 | Confusion Matrix Generation | Generates $10 \times 10$ matrix tabulating true labels vs predicted digits for real-world cohort | Predictions and ground truth labels | Markdown table & text confusion matrix | Flag unclassified/rejected samples | `智能芯片实践分工.md` §G |
| 15 | Evaluation / L2 | Background Noise Rejection | Evaluates non-digit blank/clutter images against confidence threshold | Non-digit background images | Rejection rate, FAR, FRR | Backgrounds must not be forced into $0..9$ | `智能芯片实践分工.md` §G |
| 16 | DSE / L3 | Multi-Tier Bitwidth Sweep | Quantization sweep across 16, 11, 8, and 4-bit word lengths | Fixed-point model configs | Accuracy, LUT, FF, DSP, BRAM, Latency | Extreme degradation below 8 bits | `智能芯片选题任务书2026.md` 任务3 §3 |
| 17 | DSE / L3 | Saturation Knee Identification | Mathematical proof that 11-bit is the point of diminishing returns | Bitwidth sweep results | Knee point coordinate $(11, \text{Acc})$ | Highlights precision-resource plateau | `智能芯片选题任务书2026.md` 任务3 §3 |
| 18 | DSE / L3 | Pareto Frontier Construction | Computes multi-objective non-dominated solutions across Accuracy, Resources, Latency | PPA extraction records | Pareto trade-off curve | Discards dominated inferior solutions | `智能芯片选题任务书2026.md` 任务3 §3 |
| 19 | DSE / L3 | Parallelism Boundary Check | Evaluates scaling SIMD parallelism (16 vs 32 vs 64) against XC7Z020 resource limit | Parallel hardware configurations | Feasibility boundary report | Synthesizer errors on DSP/BRAM exhaustion | `智能芯片选题任务书2026.md` 任务3 §3 |
| 20 | Deliverables | 8-Role Defense Q&A Sheet | Structured Q&A document arming team members with defense arguments | Architecture & synthesis data | `reports/defense_qa_sheet.md` | Maps every member to specific defense questions | `hw/智能芯片实践分工.md` |

---

## 7. Edge Cases Table

| # | Feature | Input / Condition | Observed / Required Behavior |
|---|---|---|---|
| 1 | 16-way SIMD MAC | All-zero input vector ($\mathbf{x} = \mathbf{0}$) | Accumulator remains exactly 0; no spurious activation; zero DSP toggle. |
| 2 | 16-way SIMD MAC | Maximum positive inputs and weights ($+3.99 \times +3.99$) | Accumulator saturated gracefully via `AP_SAT` without numerical wrap-around. |
| 3 | 16-way SIMD MAC | Extreme negative inputs ($x_k < 0, w_k > 0$) | Sign handled correctly in two's complement; product is negative. |
| 4 | Sign-Bit ReLU | Strictly negative pre-activation ($z = -0.0001$) | Output forced strictly to $0.0$; sign-bit detection avoids floating branch. |
| 5 | Sign-Bit ReLU | Exactly zero pre-activation ($z = 0.0$) | Output remains $0.0$. |
| 6 | Argmax | Exactly identical logit values for two or more classes | Deterministic tie-breaking: selects the lowest class index (e.g. if 3 and 7 tie, choose 3). |
| 7 | TDM FSM Sequencing | Consecutive inference requests without reset | Input/intermediate buffers must clear or overwrite cleanly; zero state leakage between samples. |
| 8 | Image Preprocessing | Completely blank/white paper photo (no ink) | Bounding box detection returns empty; triggers rejection or default zero frame without crash. |
| 9 | Image Preprocessing | Single speck of dust / noise pixel | Morphological filter suppresses single-pixel noise; does not falsely enlarge bounding box. |
| 10 | Image Preprocessing | High aspect-ratio digit (e.g., thin vertical '1') | Scales height to 20 pixels; width scaled proportionally; padded symmetrically to 28 width. |
| 11 | Quantization Sweep | Extreme low bitwidth (INT4: `ap_fixed<4, 2>`) | Dynamic range severely truncated; output logits cluster; accuracy drops to random guess (~10%). |
| 12 | Parallelism Scaling | High parallelism (e.g. 64-way SIMD + full unroll) | DSP requirement exceeds XC7Z020 budget ($> 220$ DSPs); synthesis / placement fails with resource overflow. |

---

## 8. Detailed Interface Contracts & Numerical Specifications

### 8.1 Data Types & Bit Allocation Table

| Signal / Variable | HLS Type | Total Bits ($W$) | Integer Bits ($I$) | Frac Bits ($F$) | Quantization / Overflow Mode | Dynamic Range |
|---|---|:---:|:---:|:---:|:---:|:---:|
| `test_inputs[s][j]` | `ap_fixed<11, 3>` | 11 | 3 | 8 | `AP_RND, AP_SAT` | $[-4.0, +3.996]$ |
| `weights_L1[i][j]` | `ap_fixed<11, 3>` | 11 | 3 | 8 | `AP_RND, AP_SAT` | $[-4.0, +3.996]$ |
| `weights_L2[i][j]` | `ap_fixed<11, 3>` | 11 | 3 | 8 | `AP_RND, AP_SAT` | $[-4.0, +3.996]$ |
| Multiplier Product | `ap_fixed<22, 6>` | 22 | 6 | 16 | Full Precision | $[-16.0, +15.99]$ |
| MAC Accumulator | `ap_fixed<26, 10>` | 26 | 10 | 16 | `AP_RND, AP_SAT` | $[-512.0, +511.99]$ |
| Hidden Activation `a1[i]` | `ap_fixed<11, 3>` | 11 | 3 | 8 | `AP_RND, AP_SAT` | $[0.0, +3.996]$ |
| Output Logit `out_vec[i]` | `ap_fixed<11, 3>` | 11 | 3 | 8 | `AP_RND, AP_SAT` | $[-4.0, +3.996]$ |
| Classification Result | `ap_uint<4>` / `uint8_t` | 4 / 8 | 4 / 8 | 0 | Unsigned Integer | $[0..9]$ |

### 8.2 Register Map for AXI4-Lite Control Slave (`s_axilite`)

| Register Name | Offset | Access | Bit Field Definitions |
|---|:---:|:---:|---|
| `CTRL_REG` | `0x00` | R/W | `[0]`: `ap_start` (Write 1 to initiate inference)<br>`[1]`: `ap_done` (Read 1 when inference complete)<br>`[2]`: `ap_idle` (Read 1 when accelerator is ready for new sample)<br>`[3]`: `ap_ready` (Read 1 when core ready for input)<br>`[7]`: `auto_restart` |
| `GIE` | `0x04` | R/W | `[0]`: Global Interrupt Enable |
| `IER` | `0x08` | R/W | `[0]`: Interrupt Enable for `ap_done` |
| `ISR` | `0x0C` | R/TOW | `[0]`: Interrupt Status (Toggle-on-write to clear) |
| `PRED_REG` | `0x10` | R | `[3:0]`: Winning digit class prediction ($0..9$) |
| `SCORE_REG` | `0x14` | R | `[10:0]`: Maximum logit value (`ap_fixed<11, 3>`) |

---

## 9. Deliverables Architecture & Organization

The final project repository must provide complete artifacts organized as follows:

```
vivado/
├── hw/
│   ├── weights.h              # Verified 784-64-10 fixed-point weights
│   ├── test_inputs.h           # 100 verified MNIST test samples & labels
│   ├── 智能芯片选题任务书2026.md # Authoritative task book
│   └── 智能芯片实践分工.md       # Authoritative team division plan
├── src/                       # Accelerator HLS source code
│   ├── mlp_accel.cpp          # Top-level accelerator & TDM FSM
│   ├── mlp_accel.h            # Architecture parameters & datapath interfaces
│   ├── datapath.cpp           # 16-way SIMD MAC core, adder tree, ReLU, Argmax
│   └── tb_mlp_accel.cpp       # Comprehensive verification testbench
├── scripts/                   # Workflow & evaluation scripts
│   ├── run_hls.tcl            # Vivado HLS batch flow (csim, csynth, cosim)
│   ├── preprocess.py          # Real-world photo 8-step preprocessing pipeline
│   ├── evaluate_domain_gap.py # Confusion matrix & domain gap evaluation
│   └── dse_ptq_sweep.py       # Bitwidth sweep & Pareto frontier analysis
├── reports/                   # Technical reports & defense assets
│   ├── level1_synthesis_report.md     # Level 1 hardware synthesis & PPA report
│   ├── level2_domain_gap_report.md    # Level 2 preprocessing & domain gap report
│   ├── level3_dse_pareto_report.md    # Level 3 PTQ & DSE Pareto optimization report
│   ├── presentation_slides.md         # Team defense presentation slide deck
│   └── defense_qa_sheet.md            # Role-by-role (A-H) defense Q&A cheat sheet
├── Makefile                   # Host-sim, csim, csynth, cosim targets
└── README.md                  # Unified project entry point & execution instructions
```

---

## 10. Conclusion & Strategic Guidance for Execution

1. **Foundational Integrity**:
   The baseline weights in `hw/weights.h` and test samples in `hw/test_inputs.h` have been validated in Python to achieve exactly **97.00% accuracy**. This eliminates algorithmic risk; our implementation must ensure exact numerical bit-alignment so that hardware simulation replicates this $\ge 90\%$ baseline.
2. **Hardware Reuse Proof**:
   The most scrutinized rubric requirement in Level 1 is the **TDM hardware reuse**. The implementation must explicitly prove that only **one** 16-way SIMD MAC block exists, alternating between FC1 and FC2 through FSM state transitions and address swapping.
3. **Rigorous Level 3 Execution**:
   To secure the full 10 bonus points, the DSE study must incorporate real numbers from synthesis reports across 16-bit, 11-bit, 8-bit, and 4-bit configurations, prove the 11-bit saturation knee point mathematically, demonstrate resource overflow under parallelism, and provide an evidence-backed edge deployment recommendation.
4. **Defense Alignment (Roles A-H)**:
   All deliverables and documentation must distinctly identify contributions and defense arguments for each team member (Roles A through H), ensuring full mastery during oral defense.
