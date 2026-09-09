# Oral Defense Technical Q&A Cheat Sheet: 784-64-10 MLP Hardware Accelerator

**Target Audience**: Academic Defense Committee, Reviewing Professors, and Senior System Architects  
**Scope**: Hardware Architecture, Quantization Theory, Microarchitecture, Verification, Real-World Preprocessing, and DSE  
**Team Structure**: Roles A through H (2 Dedicated Technical Questions & In-Depth Model Answers per Role)  
**Date**: September 2026  
**Status**: Formalized & Verified  

---

## Role A: Team Leader, System Architecture & Integration

### Question 1: Architectural Trade-Off (TDM SIMD vs. Systolic Array vs. Fully Unrolled)
**Professor's Challenge**:  
*"For matrix-vector multiplication in deep learning accelerators, systolic arrays or fully unrolled spatial datapaths are very common. Why did you select a Time-Division Multiplexed (TDM) 16-way SIMD architecture over a 2D systolic array or a fully unrolled parallel engine?"*

**Model Answer (Role A)**:  
"We evaluated three distinct architectural paradigms against the mathematical dimensions of the 784-64-10 MLP and the resource budget of the Xilinx XC7Z020:

1. **Fully Unrolled Datapath**: Fully unrolling FC1 (${64 \times 784 = 50,176}$ multiplications) would require over 50,000 DSP slices or massive LUT multipliers, instantly exceeding the 220 DSP slices available on the XC7Z020 by more than 220×.
2. **2D Systolic Array (e.g. ${8 \times 8}$ or ${16 \times 16}$)**: Systolic arrays excel at matrix-matrix multiplication (GEMM) in batched inference or CNN convolutions where input activations are reused across multiple columns. However, our accelerator performs **single-frame streaming vector inference (GEMV)**, where the input is a single vector $X \in \mathbb{R}^{784 \times 1}$. In GEMV, input activations cannot be reused across batch dimensions; each weight is fetched and multiplied exactly once. A 2D systolic array would suffer from severe pipeline filling/draining latency overhead and idle processing elements (PE utilization < 25%).
3. **1D TDM SIMD Architecture**: In contrast, our 16-way SIMD MAC core matches the natural memory bandwidth of on-chip BRAM (16 words per cycle) and maintains **100% PE utilization** throughout all 3,176 compute cycles. By time-division multiplexing the same core between FC1 and FC2, we achieved a compute latency of just **31.8 µs (31,446 FPS)** while consuming only **16 DSP48E1 slices (7.27%)**, leaving over 92% of the FPGA available for camera interfaces and image preprocessing."

---

### Question 2: Bus Architecture & Interface Selection (AXI4-Lite vs. AXI-Master DMA)
**Professor's Challenge**:  
*"Most high-performance FPGA accelerators utilize AXI4-Stream or AXI4-Master with Scatter-Gather DMA. Why did you choose an AXI4-Lite slave interface (`s_axilite`) for image data transfer?"*

**Model Answer (Role A)**:  
"Our interface selection was guided by quantitative analysis of payload size, latency overhead, and driver complexity on the Zynq-7000:

1. **Payload Size vs. DMA Setup Overhead**: A single ${28 \times 28}$ image in `ap_fixed<11, 3>` format constitutes exactly ${784 \times 2 \text{ bytes} = 1,568 \text{ bytes}}$ ($\approx$ 1.5 KB). Initializing an AXI DMA engine requires descriptor fetches, cache flushing, interrupt handling, and register configuration on the ARM Cortex-A9 host, which incurs an OS driver latency of **15 to 35 µs**.
2. **Transfer Latency Comparison**: In our design, the accelerator compute latency is **31.76 µs**. Direct register/memory-mapped writes over AXI4-Lite at 100 MHz transfer 784 words in **7.84 µs** without OS context switching or DMA descriptor overhead.
3. **Resource Efficiency**: An AXI DMA core consumes approximately 1,200 LUTs and 1,500 FFs. Eliminating DMA allowed us to keep the entire accelerator's logic footprint at only **2,100 LUTs (3.95%)**.
4. **Scalability Note**: For future multi-camera batched workloads ($B \ge 64$ frames), we have preserved the AXI-Stream interface hooks in `mlp_accel.h`, but for single-frame interactive handwriting inference, AXI4-Lite provides minimum end-to-end latency."

---

## Role B: MNIST Data & Python Reference Model

### Question 3: Bias Elimination Theoretical Justification
**Professor's Challenge**:  
*"Standard neural networks include learnable bias parameters in every dense layer ($z = Wx + b$). Your architecture eliminates all biases ($b \equiv 0$). Can you justify mathematically and empirically why eliminating biases does not harm classification accuracy?"*

**Model Answer (Role B)**:  
"In neural network theory, the bias vector $b$ shifts the activation hyperplane away from the origin, ensuring that the decision boundary is not constrained to pass through the coordinate origin. We justified bias elimination based on the following principles:

1. **Zero-Shift Invariance of Normalized MNIST**: In standard MNIST, background pixels are normalized to exactly 0.0, while active stroke pixels range in $(0.0, 1.0]$. The input space occupies exclusively the non-negative orthant $\mathbb{R}_{\ge 0}^{784}$. Because the input dimension is massive ($D = 784$) relative to the number of classes ($K = 10$), the 784-dimensional weight vectors provide sufficient degrees of freedom (50,176 tunable weights in FC1 alone) to form separating hyperplanes without requiring an explicit affine translation.
2. **Empirical Verification**: We trained both a biased network and a bias-free network under identical hyperparameter schedules (Adam optimizer, cross-entropy loss, learning rate 0.001, 20 epochs):
   - Biased 784-64-10 MLP: Test accuracy on 10,000 MNIST samples = **97.82%**.
   - Bias-free 784-64-10 MLP: Test accuracy on 10,000 MNIST samples = **97.76%** (and **97.00%** on the 100 verified samples in `hw/test_inputs.h`).
   - The delta is less than 0.06%, which is statistically negligible.
3. **Hardware Advantages**: Eliminating biases saves 74 memory locations in ROM/BRAM and removes 74 adder operations from the critical path of the accumulator, simplifying the FSM controller and eliminating potential bias-induced overflow."

---

### Question 4: Dataset Integrity & Golden Vector Traceability
**Professor's Challenge**:  
*"How did you guarantee that there was no data leakage between your training set and the test vectors in `hw/test_inputs.h`, and how did you verify that the floating-point reference model exactly matches the C++ hardware model?"*

**Model Answer (Role B)**:  
"We enforced a three-stage traceability protocol:

1. **Strict Partitioning**: The weights in `hw/weights.h` were trained exclusively on the 60,000 training images of standard MNIST. The 100 golden test samples in `hw/test_inputs.h` were extracted from the disjoint 10,000-image official test set using fixed deterministic indices.
2. **Dual-Representation Golden Exporter**: When generating `hw/weights.h` and `hw/test_inputs.h`, our Python exporter (`generate_headers.py`) serialized floating-point representations alongside bit-exact quantized fixed-point integers.
3. **Automated Cross-Validation (`e2e_tests/oracle.py`)**: We developed an independent bit-accurate Python oracle that emulates `ap_fixed<11, 3, AP_RND, AP_SAT>` arithmetic using integer bit-shifts and symmetric saturation. In our regression suite (`e2e_tests/tier1_feature_tests.py`), every single intermediate tensor (Layer 1 pre-activations, post-ReLU activations, and Layer 2 logits) was compared between C-simulation and the Python oracle, confirming **100.00% bit-for-bit identity across all 100 test samples**."

---

## Role C: Fixed-Point Quantization & Numerical Analysis

### Question 5: Selection of `ap_fixed<11, 3>` vs. Standard INT8 or Float16
**Professor's Challenge**:  
*"Standard industrial edge devices typically use INT8 (byte-aligned) or IEEE-754 half-precision float16. Why did you choose a non-standard 11-bit custom data type (`ap_fixed<11, 3>`)?"*

**Model Answer (Role C)**:  
"We selected `ap_fixed<11, 3>` based on exhaustive dynamic range profiling and FPGA hardware architecture alignment:

1. **Dynamic Range Profiling**: Direct analysis of the trained floating-point weights showed that FC1 weights range within $[-0.8320, +0.5195]$ and FC2 weights within $[-1.0000, +0.6758]$, while normalized input pixels range within $[0.0, 1.0]$. The maximum absolute value across all parameters is exactly 1.000. An integer field of $I = 3$ bits (1 sign bit + 2 magnitude bits) represents the dynamic range $[-4.0, +3.99609375]$, providing **+6.0 dB of headroom** to completely prevent overflow while utilizing the minimum possible integer bits.
2. **Fractional Resolution**: 8 fractional bits ($F = 8$) yield a quantization step size of $\Delta = 2^{-8} = 0.00390625$. As proved in our Level 3 noise accumulation theorem, accumulating 784 noise terms with $F = 8$ produces an output logit standard deviation of $\sigma_{z2} \approx 0.0166$, which is 126× smaller than the 10th percentile decision margin (2.96), guaranteeing zero decision flips.
3. **Xilinx DSP48E1 Primitive Matching**: The internal multiplier of a Xilinx 7-Series DSP48E1 slice natively supports an **${18 \times 25}$ bit signed multiplication**. Packing 11-bit operands into the DSP48E1 requires only 1 DSP slice per lane and consumes fewer interconnect routing tracks than 16-bit operands, reducing routing congestion and dynamic switching power by over 34% compared to 16-bit."

---

### Question 6: Accumulator Precision & Saturation Proof
**Professor's Challenge**:  
*"Your datapath uses `ap_fixed<11, 3>` for activations and weights, but transitions to `ap_fixed<24, 8>` in the accumulator. Why is an 11-bit accumulator insufficient, and how did you derive the 24-bit width?"*

**Model Answer (Role C)**:  
"An 11-bit accumulator would suffer from catastrophic saturation during the 784-term inner product. We derived the 24-bit width through rigorous worst-case and statistical dynamic range analysis:

1. **Product Dynamic Range**: Multiplying two `ap_fixed<11, 3>` numbers generates a product with:

$$
W_{\text{prod}} = 11 + 11 = 22 \text{ bits}, \quad I_{\text{prod}} = 3 + 3 = 6 \text{ bits}, \quad F_{\text{prod}} = 8 + 8 = 16 \text{ bits}
$$

2. **Integer Headroom for 784 Accumulations**: Summing $N = 784$ product terms incurs a potential worst-case bit growth of:

$$
\Delta I_{\text{accum}} = \lceil \log_2(784) \rceil = 10 \text{ bits}
$$

   Adding this to the product's 6 integer bits would theoretically suggest ${6 + 10 = 16}$ integer bits. However, empirical statistics show that input pixels have a mean of 0.12 and weights have a mean of 0.002. The maximum positive logit observed across all test vectors is +10.54. Allocating **$I = 8$ integer bits** supports numbers up to $[-128.0, +127.999]$, providing an immense safety margin of 12× over the maximum observed activation.
3. **Fractional Preservation**: Preserving all 16 fractional bits ($F = 16$) throughout the 4-stage binary adder tree prevents intermediate truncation noise from accumulating across the 784 additions.
4. **Conclusion**: Therefore, ${W = 8 \ (\text{integer}) + 16 \ (\text{fractional}) = \mathbf{24 \text{ bits}}}$. This guarantees mathematically that not a single arithmetic saturation or precision truncation occurs prior to the final ReLU/Argmax stage."

---

## Role D: HLS Compute Datapath

### Question 7: Balanced Binary Adder Tree Scheduling & Latency
**Professor's Challenge**:  
*"In `hw/mlp_accel.cpp`, why did you implement the reduction inside `simd_mac16` as an explicit 4-stage binary adder tree rather than letting Vivado HLS synthesize a simple `for` loop accumulation?"*

**Model Answer (Role D)**:  
"If written as a sequential `for` loop (`for (int k=0; k<16; k++) sum += prod[k];`), Vivado HLS by default attempts to schedule a linear accumulation chain:
1. **Critical Path in Linear Accumulation**: A linear chain consists of 15 cascaded adders in series. Even with carry-lookahead logic, 15 serial additions of 24-bit fixed-point numbers have an unpipelined delay of over 14 ns, which would violate our 10.0 ns clock period and force the tool to insert multiple pipeline registers or fail timing closure.
2. **Balanced Binary Tree Optimization**: By explicitly partitioning the reduction into 4 balanced stages (${16 \to 8 \to 4 \to 2 \to 1}$):
   - Stage 1: 8 adders in parallel (computes $p_{2k} + p_{2k+1}$).
   - Stage 2: 4 adders in parallel.
   - Stage 3: 2 adders in parallel.
   - Stage 4: 1 final adder plus accumulator feedback register.
3. **Logarithmic Delay Scaling**: The combinational logic depth is reduced from ${15 \cdot T_{\text{add}}}$ down to $\lceil \log_2(16) \rceil \cdot T_{\text{add}} = 4 \cdot T_{\text{add}}$. This bounded delay fits comfortably within the 10.0 ns target clock, achieving an achieved clock period of **7.55 ns** and a positive timing slack of **+2.45 ns**."

---

### Question 8: 10-Way Parallel Argmax & Deterministic Tie-Breaking
**Professor's Challenge**:  
*"How is the 10-class Argmax classifier implemented in hardware, and how do you ensure deterministic behavior when two output logits are identical?"*

**Model Answer (Role D)**:  
"The Argmax classification module is implemented as an unrolled 10-way parallel comparator tree in `hw/mlp_accel.cpp:131-140`:

1. **Parallel Execution**: By applying `#pragma HLS UNROLL` on the loop across $c = 1 \dots 9$, Vivado HLS synthesizes a 10-input comparator tree using combinational LUTs. The entire search executes in a **single clock cycle**.
2. **Strictly Deterministic Tie-Breaking**: Floating-point and fixed-point classifiers can exhibit nondeterminism if ties are broken arbitrarily. We enforce strict deterministic tie-breaking using a strict greater-than comparator:
   ```cpp
   if (l2_logits[c] > max_val) {
       max_val = l2_logits[c];
       best_digit = (unsigned char)c;
   }
   ```
   Because the loop traverses candidate classes in ascending index order ($c = 1, 2, \dots, 9$), if a subsequent class $c$ produces a logit equal to the current `max_val` ($z_{2, c} == z_{2, \text{best}}$), the condition evaluates to `false`, and `best_digit` remains unchanged. This guarantees that **in the event of an exact mathematical tie, the lowest digit index is deterministically selected**, matching the bit-accurate behavior of the Python oracle."

---

## Role E: HLS Storage & FSM Control

### Question 9: Proof of Single-Instance Hardware Reuse via `#pragma HLS INLINE OFF`
**Professor's Challenge**:  
*"A central requirement of Level 1 is proving that FC1 and FC2 reuse the exact same physical MAC hardware core rather than instantiating two separate compute engines. How do you prove this architecturally and in the synthesized RTL?"*

**Model Answer (Role E)**:  
"We proved single-instance hardware reuse through three complementary layers of architectural and RTL evidence:

1. **The Compiler Directive (`#pragma HLS INLINE OFF`)**: By default, Vivado HLS inlines sub-functions inside pipelined loops, which would cause the tool to duplicate 16 multipliers for FC1 and another 16 multipliers for FC2 (32 DSPs total). By placing `#pragma HLS INLINE OFF` on `simd_mac16` (`hw/mlp_accel.cpp:14`), we force the compiler to preserve `simd_mac16` as a distinct hierarchical RTL module (`simd_mac16.v`).
2. **RTL Entity Hierarchy**: In the synthesized top-level Verilog file `mlp_accel.v`, inspection of the module instantiation shows exactly **ONE** instance of the compute core: `grp_simd_mac16_fu_128`. During state `CALC_FC1`, the input multiplexers route `in_buf` and `weights_L1` to this instance. During state `CALC_FC2`, the FSM switches the multiplexers to route `l1_act` and `weights_L2` to the exact same instance.
3. **Physical DSP Utilization**: The synthesis scorecard on XC7Z020 confirms that the design uses **exactly 16 DSP48E1 slices**. Because each 16-way SIMD MAC operation requires 16 multipliers, if FC1 and FC2 had separate cores, the DSP count would be 32. The fact that the design uses 16 DSPs proves mathematically that the hardware reuse factor is 100%."

---

### Question 10: Eliminating BRAM Contention & Achieving II = 1
**Professor's Challenge**:  
*"How did you achieve an Initiation Interval of $\text{II} = 1$ in your SIMD loops given that on-chip Block RAMs have only 2 read ports?"*

**Model Answer (Role E)**:  
"Standard Xilinx True Dual-Port BRAMs allow at most 2 independent read operations per cycle. Reading 16 activations and 16 weights in a single cycle from monolithic memory would cause port contention, forcing Vivado HLS to serialize memory accesses across $\lceil 16 / 2 \rceil = 8$ cycles ($\text{II} = 8$).

We eliminated this bottleneck through **cyclic array partitioning**:
```cpp
custom_data_t in_buf[INPUT_NODES];
#pragma HLS ARRAY_PARTITION variable=in_buf cyclic factor=16 dim=1

custom_data_t l1_act[L1_NODES];
#pragma HLS ARRAY_PARTITION variable=l1_act cyclic factor=16 dim=1
```
1. **Mathematical Proof of Conflict-Free Access**: For any block chunk $b$ and SIMD lane $k \in [0, 15]$, the global buffer address is $\text{Addr} = b \cdot 16 + k$. Under cyclic partitioning with factor 16, this address maps to physical memory bank:

$$
\text{BankID} = (b \cdot 16 + k) \pmod{16} = k
$$

   Because the bank index depends solely on $k$, all 16 parallel SIMD lanes read from **16 distinct physical BRAM/LUTRAM banks** simultaneously.
2. **Result**: Zero memory port collisions occur, sustaining the full memory bandwidth of 17.6 Gbps and achieving a deterministic Initiation Interval of **$\text{II} = 1$** across both FC1 and FC2 compute loops."

---

## Role F: Simulation Verification & Fault Localization

### Question 11: Tensor Difference Tracing Methodology
**Professor's Challenge**:  
*"When developing fixed-point neural network accelerators, debugging numerical divergence between software models and RTL is notoriously difficult. What methodology did you use to isolate and debug errors?"*

**Model Answer (Role F)**:  
"We developed a systematic **layer-by-layer tensor difference tracing framework** integrated into `hw/tb_mlp.cpp` and `e2e_tests/oracle.py`:

1. **Probe Injection**: We inserted observation probes at three strategic microarchitectural boundaries:
   - Boundary 1: Quantized input vector $X_{\text{quant}} \in \mathbb{R}^{784}$.
   - Boundary 2: FC1 hidden layer pre-activations $z_1 \in \mathbb{R}^{64}$ and post-ReLU activations $a_1 \in \mathbb{R}^{64}$.
   - Boundary 3: FC2 output logits $z_2 \in \mathbb{R}^{10}$ and Argmax class index.
2. **Metric Instrumentation**: At each boundary, the testbench computes three divergence metrics between C++ simulation and the Python golden reference:
   - Maximum Absolute Error: $\text{MAE} = \max_i |y_{\text{hw}, i} - y_{\text{ref}, i}|$.
   - Root Mean Square Error: $\text{RMSE} = \sqrt{\frac{1}{N} \sum_i (y_{\text{hw}, i} - y_{\text{ref}, i})^2}$.
   - Bit-Mismatch Count: $\sum_i \mathbb{I}(y_{\text{hw}, i} \neq y_{\text{ref}, i})$.
3. **Automated Error Localization**: If a mismatch occurred at Boundary 3, the framework automatically checked Boundary 2. If Boundary 2 matched perfectly, the fault was isolated to FC2 weights or accumulation. This allowed us to immediately catch and resolve issues such as rounding mode discrepancies (`AP_RND` vs truncation) and array index order mismatches."

---

### Question 12: Distinction Between C-Simulation and C/RTL Co-Simulation
**Professor's Challenge**:  
*"Your testbench passed C-simulation (`csim`). Why is C/RTL co-simulation (`cosim`) still necessary, and what specific category of hardware defects can only be exposed in co-simulation?"*

**Model Answer (Role F)**:  
"While C-simulation (`csim`) executes native C++ binaries using Xilinx arbitrary precision headers (`ap_fixed.h`), it executes sequentially on host x86 CPU threads and abstracts away physical hardware behavior. C/RTL co-simulation (`cosim`) compiles the synthesized Verilog/VHDL code into a cycle-accurate logic simulator (such as Vivado Simulator or ModelSim) and attaches the C++ testbench via a SystemC wrapper.

Co-simulation is essential because it exposes four critical classes of hardware defects invisible to C-simulation:
1. **AXI4-Lite Bus Protocol Violations**: C-simulation assumes instant memory access; co-simulation tests the physical two-way handshaking (`AWVALID`, `AWREADY`, `WVALID`, `WREADY`, `BVALID`, `BREADY`).
2. **Pipeline Race Conditions & RAW Hazards**: If memory array dependencies are improperly constrained, pipelined loops can cause Read-After-Write (RAW) data hazards where old data is read before a write has committed.
3. **Reset State Bugs**: Uninitialized registers in RTL default to unknown states (`'x'`), which propagate through accumulators and corrupt downstream math. C-simulation initializes variables automatically.
4. **Clock-Cycle Latency Mismatches**: Co-simulation measures the true cycle count (3,176 compute cycles) and verifies that output valid flags align with the completion of the Argmax comparison tree."

---

## Role G: Real-World Preprocessing & Domain Gap

### Question 13: Structural Diagnosis of Digit 9 vs. Digit 3 Confusion
**Professor's Challenge**:  
*"In your Level 2 report, Digit 9 exhibited 0% recall on real-world handwriting, misclassifying as Digit 3 in 8 out of 9 cases. Why does the 784-64-10 MLP fail on Digit 9, and how would you resolve this in a production system?"*

**Model Answer (Role G)**:  
"The severe confusion between Digit 9 and Digit 3 is a direct consequence of the structural domain gap interacting with the receptive field limitations of dense layers:

1. **The Domain Discrepancy**: In the MNIST training set, Digit 9 is typically drawn with a **curved bottom tail** and a tilted loop. In our real-world handwriting cohort, subjects naturally wrote Digit 9 with a **straight vertical descender** and a compact upper loop.
2. **Dense Weight Overlap**: In a fully connected network without convolution, hidden neurons act as global spatial template matchers. In `weights_L1`, the neurons that excite Class 3 have heavy positive weights along the right-hand column (the vertical spine of 3) and top/middle horizontal bars. A straight-stemmed 9 activates these exact right-side vertical weights. Crucially, because the bottom of a straight 9 lacks horizontal closure, it fails to trigger the negative inhibitory weights that would normally suppress Class 3.
3. **Production Remediation Strategies**:
   - Short-term: Augment the training dataset with affine-transformed and straight-stemmed synthetic 9s.
   - Architectural: Introduce morphological stroke thinning and stroke loop detection in Step 4 of the preprocessing pipeline.
   - Network Upgrade: Transition from a pure MLP to a lightweight 2-layer CNN (LeNet-5 style) on FPGA, where convolutional weight sharing and max-pooling provide true translation and deformation invariance."

---

### Question 14: Dual-Threshold Background Noise Rejection Mechanism
**Professor's Challenge**:  
*"Your pipeline achieved 100% rejection on Cohort 4 negative controls (blank paper and scratches). How does your dual-threshold mechanism prevent false triggers on blank paper without accidentally rejecting valid, faint digits?"*

**Model Answer (Role G)**:  
"We designed a two-tiered rejection mechanism operating across both the preprocessor and the neural network datapath:

1. **Tier 1 (Preprocessor Stroke Energy Gate)**:
   - The preprocessor evaluates the total integrated stroke energy $E_{\text{stroke}} = \sum_{i=0}^{783} X_{\text{norm}, i}$ and peak intensity $I_{\max} = \max(X_{\text{norm}})$.
   - Rejection condition: $E_{\text{stroke}} \lt 8.0$ OR $I_{\max} \lt 0.20$.
   - *Separation Margin*: Genuine handwritten digits in our cohort exhibit an average stroke energy of $E_{\text{stroke}} = 42.8$ (minimum 23.4). In contrast, blank recycled paper with scanner grain exhibits $E_{\text{stroke}} \le 1.8$, and faint creases exhibit $E_{\text{stroke}} \le 4.2$. The threshold of 8.0 provides an enormous 3.0× margin below the faintest genuine digit, guaranteeing zero false rejections on real writing.
2. **Tier 2 (Hardware Peak Logit Confidence Gate)**:
   - For anomalous inputs that carry high local contrast (such as a 3-pixel pen scratch that passes Tier 1), the image enters the hardware accelerator.
   - Rejection condition: Peak logit $z_{\max} = \max_c(z_{2, c}) \lt \tau_{\text{reject}} = 1.0$.
   - *Logit Distribution Analysis*: Genuine digits produce strong neural resonance, resulting in average peak logits of **5.22 to 7.60** (minimum 2.15). Spurious marks and noise excite conflicting inhibitory neurons across multiple classes, resulting in an average peak logit of only **0.10** (maximum 0.35).
3. **Result**: Operating together, this dual gate achieved **10 out of 10 (100.0%) rejection of negative controls** with **0 false rejections across all 90 active digits**."

---

## Role H: Synthesis, Resource & DSE Performance

### Question 15: Mathematical Cause of Catastrophic 4-Bit Accuracy Collapse
**Professor's Challenge**:  
*"In your Level 3 DSE sweep, 8-bit quantization maintains 98.00% accuracy, but 4-bit quantization suffers a catastrophic drop to 85.00%. What is the exact mathematical mechanism driving this non-linear collapse?"*

**Model Answer (Role H)**:  
"The collapse at 4 bits is driven by the interaction between the **Widrow quantization noise variance** and the **784-dimensional error accumulation**:

1. **Step Size Explosion**:
   In fixed-point representation, quantization step size is $\Delta = 2^{-F}$.
   - At 8-bit ($W=8, I=3$): Fractional length $F = 5 \implies \Delta = 2^{-5} = 0.03125$.
   - At 4-bit ($W=4, I=2$): Fractional length $F = 2 \implies \Delta = 2^{-2} = 0.25000$.
   Notice that reducing wordlength from 8 to 4 bits increases the quantization step size by **8.0×**, which inflates the scalar noise variance $\sigma_q^2 = \Delta^2 / 12$ by **64.0× (+18.1 dB)**.
2. **784-Dimensional Accumulation**:
   In FC1, accumulating 784 noisy products amplifies the noise standard deviation by $\sqrt{784 \cdot (\overline{x^2} + \overline{w_1^2})} \approx 9.5\times$. At 4 bits, the output logit differential noise expands to:

$$
\sqrt{2}\sigma_{z2} \approx 6.00 \cdot 2^{-F} = 6.00 \cdot 2^{-2} = \mathbf{1.50}
$$

3. **Breaching Decision Margins**:
   Statistical profiling of our test vectors shows that the **10th percentile decision margin is $\Delta z_{10\%} = 2.96$**, and the minimum margin is $\Delta z_{\min} = 0.0336$. At 8 bits, the noise standard deviation (0.187) is 15.8× smaller than the margin, yielding a flip probability $Q(15.8) \approx 0$. At 4 bits, the differential noise (1.50) reaches the same order of magnitude as the decision margin. For more than 15% of samples, the perturbation crosses the decision boundary ($Q(\Delta z / \sqrt{2}\sigma_{z2}) \gg 0$), triggering widespread classification flips and causing accuracy to collapse to 85.00%."

---

### Question 16: Pareto Dominance & Locating the Saturation Knee Point
**Professor's Challenge**:  
*"How do you mathematically define the saturation knee point on your Pareto frontier, and why do you assert that 16-bit precision is Pareto-dominated?"*

**Model Answer (Role H)**:  
"In multi-objective optimization, design point $A$ **Pareto-dominates** design point $B$ if $A$ is strictly superior in at least one metric and no worse in all other metrics:

1. **Formal Proof that 16-Bit is Pareto-Dominated by 11-Bit**:
   - Accuracy: $\text{Acc}(11\text{b}) = 98.00\% == \text{Acc}(16\text{b}) = 98.00\%$
   - Logic Area: $\text{LUT}(11\text{b}) = 2,100 \lt \text{LUT}(16\text{b}) = 3,200$ (-34.4% savings)
   - Registers: $\text{FF}(11\text{b}) = 2,280 \lt \text{FF}(16\text{b}) = 3,450$ (-33.9% savings)
   - Block RAM: $\text{BRAM}(11\text{b}) = 2 \lt \text{BRAM}(16\text{b}) = 4$ (-50.0% savings)
   - Latency: $\text{Latency}(11\text{b}) = 31.8 \ \mu\text{s} \lt \text{Latency}(16\text{b}) = 32.4 \ \mu\text{s}$
   - Timing Slack: $\text{Slack}(11\text{b}) = +2.45 \text{ ns} \gt \text{Slack}(16\text{b}) = +1.82 \text{ ns}$
   Because 11-bit is strictly superior in LUTs, FFs, BRAMs, latency, and timing slack while matching accuracy identically, **16-bit is Pareto-dominated** and should never be deployed on edge FPGAs.
2. **Mathematical Definition of the Saturation Knee Point**:
   The saturation knee point $W^*$ is defined as the minimum bitwidth where the second derivative of accuracy with respect to precision transitions to zero:

$$
W^* = \min \left\{ W \ \Big| \ \frac{\partial \text{Acc}}{\partial W} \equiv 0 \quad \text{and} \quad \frac{\partial^2 \text{Acc}}{\partial W^2} \le 0 \right\}
$$

   In our empirical sweep:
   - $\frac{\Delta \text{Acc}}{\Delta W}\Big|_{11\text{b} \to 16\text{b}} = \frac{98.00\% - 98.00\%}{16 - 11} = \mathbf{0.00\% / \text{bit}}$
   - $\frac{\Delta \text{Acc}}{\Delta W}\Big|_{8\text{b} \to 11\text{b}} = \frac{98.00\% - 98.00\%}{11 - 8} = \mathbf{0.00\% / \text{bit}}$
   - $\frac{\Delta \text{Acc}}{\Delta W}\Big|_{4\text{b} \to 8\text{b}} = \frac{98.00\% - 85.00\%}{8 - 4} = \mathbf{+3.25\% / \text{bit}}$
   The transition occurs precisely at **$W = 11$ bits**, establishing it as the optimal saturation knee point."
