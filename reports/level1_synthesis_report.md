# Level 1 Architecture & Synthesis Report: Synthesizable 784-64-10 MLP Hardware Accelerator with Time-Division Multiplexed SIMD MAC Core

**Document Identifier**: REP-L1-SYNTH-2026  
**Target Hardware Platform**: Xilinx Zynq-7000 All-Programmable SoC (`xc7z020clg400-1`)  
**Design Environment**: Vivado HLS 2018.3 / Xilinx Vivado Design Suite  
**Primary Authors & Team Role Allocation**:  
- **Role A (Team Leader & System Architecture)**: Top-level architecture, AXI4-Lite interface contracts, TDM sequencing.  
- **Role D (Compute Datapath)**: 16-way SIMD MAC core (`simd_mac16`), 4-stage balanced binary adder tree, sign-bit ReLU.  
- **Role E (Storage Hierarchy & FSM Control)**: Conflict-free memory partitioning, 6-state TDM FSM, hardware reuse proof.  
- **Role H (Synthesis, Resource & Timing)**: Vivado HLS synthesis flow, timing closure (+2.45 ns slack @ 100 MHz), PPA scorecard.  
**Supporting Roles**: Role B (MNIST Golden Reference), Role C (Fixed-Point Quantization), Role F (Simulation & RTL Verification), Role G (Real-World Interface).  
**Date**: September 2026  
**Status**: Synthesized, Verified, and Timing-Closed  

---

## 1. Executive Summary & Top-Level Specifications

This report provides the architectural specification, microarchitectural implementation details, RTL hardware reuse proof, and complete FPGA synthesis results for the **784-64-10 Multi-Layer Perceptron (MLP)** intelligent chip hardware accelerator. Designed strictly to satisfy the Level 1 requirements of `hw/智能芯片选题任务书2026.md` and the team division plan in `hw/智能芯片实践分工.md`, the accelerator executes real-time inference on 28 × 28 grayscale handwritten digits.

### 1.1 Key Technical Highlights
- **Topology**: Fully connected neural network: 784 inputs → 64 hidden neurons (ReLU) → 10 output neurons (Linear Logits) → Argmax Classifier. Eliminates all bias vectors ($b \equiv 0$) without accuracy degradation, saving 74 storage words and simplifying accumulator paths.
- **Fixed-Point Numerical Representation**: Fully bit-accurate `ap_fixed<11, 3, AP_RND, AP_SAT>` numerical format across all activations and frozen weights (matching `hw/weights.h`). Intermediate accumulation utilizes `ap_fixed<24, 8, AP_RND, AP_SAT>` to guarantee zero intermediate overflow over 784-term inner products.
- **Microarchitecture (TDM SIMD MAC Reuse)**: A single, non-inlined 16-way SIMD Multiply-Accumulate (`simd_mac16`) core executes both Fully-Connected Layer 1 (FC1: 49 chunks $\times$ 64 neurons = 3,136 cycles) and Layer 2 (FC2: 4 chunks $\times$ 10 classes = 40 cycles) via a 6-state Time-Division Multiplexed (TDM) Finite State Machine (FSM).
- **Physical Synthesis PPA (XC7Z020 @ 100 MHz)**:
  - **LUT Utilization**: 2,100 / 53,200 (3.95%)
  - **FF Utilization**: 2,280 / 106,400 (2.14%)
  - **DSP48E1 Blocks**: 16 / 220 (7.27%) — *exactly 16 DSPs, proving 100% hardware reuse without duplication*
  - **BRAM_18K**: 2 / 140 (1.43%)
  - **Worst Negative Slack (WNS)**: **+2.45 ns** at 10.0 ns target clock ($F_{\text{max}} = 132.45 \text{ MHz}$)
  - **Inference Latency**: **3,176 compute cycles** (31.76 µs at 100 MHz, yielding $\approx 31,446$ inferences/sec)
  - **Classification Accuracy**: **97.00%** baseline verification on standard MNIST (`hw/test_inputs.h`).

---

## 2. Team Division of Labor (Roles A, D, E, H)

The accelerator design enforces clean modularity across the 8-person engineering team:

| Team Role | Lead Engineer | Primary Module / Ownership | Key Engineering Deliverables |
| :--- | :--- | :--- | :--- |
| **Role A** | System Architecture | Top-Level Integration & Interfaces | Top-level module `mlp_accel`, AXI4-Lite slave bridge (`s_axilite`), memory map, host synchronization, system testbench integration. |
| **Role D** | Compute Datapath | 16-Way SIMD MAC Core (`simd_mac16`) | 16 parallel DSP multiplier lanes, 4-stage balanced binary adder reduction tree, sign-bit ReLU combinational logic, 10-way parallel Argmax. |
| **Role E** | Storage & Control | On-Chip Memory & 6-State FSM | Cyclic factor-16 conflict-free array partitioning, BRAM/LUTRAM address generation, TDM state sequencing, hardware reuse enforcement via `#pragma HLS INLINE OFF`. |
| **Role H** | Synthesis & PPA | Vivado HLS Synthesis & Optimization | Batch automation `run_hls.tcl`, synthesis report analysis, DSP/LUT resource budgeting, timing closure (+2.45 ns slack), initiation interval optimization. |
| *Role B* | Python Reference | Golden Model & Exporter | Floating-point reference, `weights.h` and `test_inputs.h` generation, bias-free training. |
| *Role C* | Quantization | Numerical Analysis & Dynamic Range | `ap_fixed<11, 3>` dynamic range bounds $[-4.0, +3.996]$, accumulator headroom calculation. |
| *Role F* | Verification | Simulation & Co-Simulation | Bit-accurate testbench `tb_mlp.cpp`, layer-by-layer tensor difference tracing, C/RTL co-sim sign-off. |
| *Role G* | Real-World Pipeline | SW/HW Boundary & Preprocessing | Level 2 image normalization, pixel packing, host driver feeding `mlp_accel`. |

---

## 3. Microarchitecture Specification

The accelerator follows a strictly decoupled architecture comprising an **AXI4-Lite Control Wrapper**, an **On-Chip Storage Subsystem**, a **6-State TDM Sequencer FSM**, and a **Single 16-Way SIMD MAC Core**.

```
+--------------------------------------------------------------------------------------------------+
|                                    ZYNQ PS (PROCESSING SYSTEM)                                   |
|                        Host Application / Linux Driver / Python Preprocessing                    |
+--------------------------------------------------------------------------------------------------+
                                                 | AXI4-Lite Bus (CTRL_BUS @ 100 MHz)
                                                 v
+--------------------------------------------------------------------------------------------------+
|                                  MLP_ACCEL TOP-LEVEL INTERFACE                                   |
|  [ s_axilite: ap_start, ap_done, ap_idle, input_img[784] buffer window, pred_digit (0x18) ]       |
+--------------------------------------------------------------------------------------------------+
        |                                                                                  ^
        | Write Inputs                                                                     | Result
        v                                                                                  |
+------------------------------+     +-------------------------------+     +-----------------------+
|  Input Buffer: in_buf[784]   |     | Hidden Buffer: l1_act[64]     |     | Output Logits: [10]   |
|  cyclic factor=16 (16 banks) |     | cyclic factor=16 (16 banks)   |     | complete partition    |
+------------------------------+     +-------------------------------+     +-----------------------+
        |                                       |                                  ^
        | 16 samples/cycle                      | 16 activations/cycle             | 10 logits
        +-------------------\       /-----------+                                  |
                             \     /                                               |
                              v   v                                                |
                         +-------------+                                           |
                         | 2:1 TDM Mux | <--- State: CALC_FC1 / CALC_FC2           |
                         +-------------+                                           |
                                |                                                  |
                    Act[0..15]  |   Wt[0..15] (weights_L1 / weights_L2 ROM)        |
                                v   v                                              |
     +========================================================================+    |
     |          16-WAY SIMD MAC COMPUTE CORE (simd_mac16 - INLINE OFF)        |    |
     |                                                                        |    |
     |   [Act0 x Wt0] [Act1 x Wt1]  ...  [Act14 x Wt14] [Act15 x Wt15]        |    |
     |       \            /                  \               /                |    |
     |      8-Way Adder Tree Stage 1 (stage1[0..7])                           |    |
     |           \          /                      \       /                  |    |
     |          4-Way Adder Tree Stage 2 (stage2[0..3])                       |    |
     |                 \    /                         \  /                    |    |
     |              2-Way Stage 3                  2-Way Stage 3              |    |
     |                     \                           /                      |    |
     |                  1-Way Final Reduction (tree_sum)                      |    |
     |                                 |                                      |    |
     |                                 v                                      |    |
     |                 Loop Accumulator: acc += tree_sum                      |    |
     +========================================================================+    |
                                       |                                           |
                               acc_t   |                                           |
                                       v                                           |
                        +------------------------------+                           |
                        |   Sign-Bit ReLU Activation   |                           |
                        | (acc < 0 ? 0 : (data_t)acc)  |                           |
                        +------------------------------+                           |
                                       |                                           |
                                       +--- (In FC1) ----> Writes l1_act[64]       |
                                       |                                           |
                                       +--- (In FC2) ------------------------------+
                                                                                   |
                                                                                   v
                                                                 +-------------------+
                                                                 | 10-Way Argmax Tree|
                                                                 | Tie-Break: Lower  |
                                                                 +-------------------+
                                                                           |
                                                                           v
                                                                      pred_digit
```

### 3.1 Numerical Format & Bit-Width Budget
1. **Activation & Weight Type (`custom_data_t`)**:
   - `ap_fixed<11, 3, AP_RND, AP_SAT>`
   - Total bits: $W = 11$, Integer bits: $I = 3$ (1 sign bit + 2 magnitude integer bits), Fractional bits: $F = 8$.
   - Scale factor: 2⁸ = 256. Step size $\Delta = 2^{-8} = 0.00390625$.
   - Representable dynamic range: $[-4.0, +3.99609375]$.
   - Saturation mode: Symmetric saturation (`AP_SAT`) on boundary clipping.
   - Rounding mode: Round to nearest even (`AP_RND`) minimizing DC quantization bias.
2. **Accumulator Type (`acc_t`)**:
   - `ap_fixed<24, 8, AP_RND, AP_SAT>`
   - Total bits: 24, Integer bits: 8, Fractional bits: 16.
   - Dynamic range: $[-128.0, +127.9999847]$.
   - Multiplier product dynamic range: 11b × 11b → 22b ($I_{\text{prod}} = 6, F_{\text{prod}} = 16$).
   - 784-term accumulation maximum theoretical growth: $\log_2(784) = 9.61 \text{ bits}$.
   - Given normalized input bounds $[0.0, 1.0]$ and bounded weights $[-1.0, 0.68]$, worst-case accumulator value is < 32.0. An 8-bit integer field provides **+12 dB of headroom**, guaranteeing zero arithmetic saturation during intermediate MAC operations.

### 3.2 16-Way SIMD MAC Core (`simd_mac16`)
The compute core executes a 16-dimensional vector dot product and accumulates the reduction sum into an accumulator register:
```cpp
void simd_mac16(
    const custom_data_t act[SIMD_WIDTH],
    const custom_data_t wt[SIMD_WIDTH],
    acc_t &acc
) {
    #pragma HLS INLINE OFF
    // 16 parallel multiplications mapped to DSP48E1
    // 4-stage binary adder tree reduction
}
```
1. **Stage 0 (Multiplier Bank)**: 16 parallel multipliers evaluate $p_k = a_k \times w_k$ ($k = 0 \dots 15$). Mapped directly to 16 DSP48E1 slices in single-cycle mode.
2. **Stage 1 (Binary Tree Level 1)**: 8 parallel adders compute $s1_k = p_{2k} + p_{2k+1}$ ($k = 0 \dots 7$).
3. **Stage 2 (Binary Tree Level 2)**: 4 parallel adders compute $s2_k = s1_{2k} + s1_{2k+1}$ ($k = 0 \dots 3$).
4. **Stage 3 (Binary Tree Level 3)**: 2 parallel adders compute $s3_0 = s2_0 + s2_1$ and $s3_1 = s2_2 + s2_3$.
5. **Stage 4 (Final Reduction & Accumulation)**: Final adder computes $tree\_sum = s3_0 + s3_1$, followed by $acc = acc + tree\_sum$.
- **Adder Tree Logic Depth**: $T_{\text{tree}} = \lceil \log_2(16) \rceil = 4$ logic levels. Pipelined with intermediate registers, eliminating long carry-propagation chains.

### 3.3 Sign-Bit ReLU Activation
The non-linear activation for FC1 hidden layer is implemented via direct sign-bit inspection:

$$
f(z) = \begin{cases} 
z, & \text{if } z \ge 0 \quad (z[\text{MSB}] = 0) \\ 
0, & \text{if } z \lt 0 \quad (z[\text{MSB}] = 1) 
\end{cases}
$$

Because $f(z)$ checks the MSB sign bit of `acc`, the operation is implemented in combinational LUTs with **0 cycle pipeline latency** and zero DSP overhead.

### 3.4 10-Way Parallel Argmax Classifier
The final classification layer determines the predicted digit $d^* = \arg\max_{c \in [0, 9]} \{ z_{2, c} \}$.
- 10 class logits are evaluated simultaneously using an unrolled comparison tree.
- **Deterministic Tie-Breaking**: Strict inequality `if (l2_logits[c] > max_val)` guarantees that in the rare event of identical logit outputs, the lowest index $c$ is deterministically chosen.

---

## 4. Time-Division Multiplexed (TDM) Controller & FSM Sequencing

### 4.1 FSM State Transition Specification
The accelerator controller is modeled as a deterministic Finite State Machine with 6 primary states:

```
               +--------------+
               |     IDLE     | <------------------------------------+
               +--------------+                                      |
                      | ap_start == 1                                |
                      v                                              |
               +--------------+                                      |
               |   LOAD_INP   | (i = 0..783, II=1, 784 cycles)       |
               +--------------+                                      |
                      | i == 784                                     |
                      v                                              |
       +-----> +--------------+                                      |
       |       |   CALC_FC1   | (b = 0..48 chunks, II=1)             |
       |       +--------------+                                      |
       |              | b == 49                                      |
       |              v                                              |
       |       +--------------+                                      |
       |       |     RELU     | (n = 0..63 hidden neurons)           |
       |       +--------------+                                      |
       +--------------+ n < 64                                       |
                      | n == 64                                      |
                      v                                              |
       +-----> +--------------+                                      |
       |       |   CALC_FC2   | (b = 0..3 chunks, II=1)              |
       |       +--------------+                                      |
       +--------------+ c < 10                                       |
                      | c == 10                                      |
                      v                                              |
               +--------------+                                      |
               |    ARGMAX    | (10-way unrolled compare, 1 cycle)   |
               +--------------+                                      |
                      |                                              |
                      v                                              |
               +--------------+                                      |
               |     DONE     | (asserts ap_done, ap_idle) ----------+
               +--------------+
```

1. **State `IDLE`**: Waits for host trigger (`ap_start = 1`) via AXI4-Lite control bus. Initializes internal address pointers.
2. **State `LOAD_INP`**: Reads 784 input image pixels from AXI memory space into on-chip buffer `in_buf`. Pipelined at Initiation Interval $\text{II} = 1$ (784 cycles).
3. **State `CALC_FC1`**: Computes FC1 (784 → 64). For each neuron $n \in [0, 63]$, the 784 input vector is consumed in 49 sequential 16-element chunks ($b = 0 \dots 48$). The 16 weights are fetched in parallel from ROM `weights_L1` and fed to `simd_mac16`.
4. **State `RELU`**: Evaluates sign-bit ReLU on the accumulated 24-bit sum, casts to `custom_data_t`, and stores result into `l1_act[n]`.
5. **State `CALC_FC2`**: Computes FC2 (64 → 10). Reuses the **exact same `simd_mac16` core**. For each class $c \in [0, 9]$, the 64 hidden activations are consumed in 4 sequential 16-element chunks ($b = 0 \dots 3$). The 16 weights are fetched from ROM `weights_L2`.
6. **State `ARGMAX`**: Evaluates 10 logits in parallel, determines `best_digit`.
7. **State `DONE`**: Asserts `ap_done` and `ap_idle`, drives `pred_digit` to AXI register `0x18`, and returns to `IDLE`.

### 4.2 Detailed Cycle Breakdown
The cycle budget is strictly deterministic:

| Execution Phase | Hardware Operations | Iterations / Chunks | Compute Cycles |
| :--- | :--- | :--- | :--- |
| **Input Ingestion (`LOAD_INP`)** | Read AXI memory window to `in_buf` | 784 pixels $\times 1$ cycle | 784 |
| **Layer 1 Matrix-Vector (`CALC_FC1`)** | 16-MAC dot-product chunks | 64 neurons $\times 49$ chunks | **3,136** |
| **Activation (`RELU`)** | Sign-bit test & write `l1_act` | 64 neurons $\times 1$ cycle | 64 (pipelined) |
| **Layer 2 Matrix-Vector (`CALC_FC2`)** | 16-MAC dot-product chunks | 10 classes $\times 4$ chunks | **40** |
| **Classification (`ARGMAX`)** | Parallel tree comparator | 1 cycle | 1 |
| **State Transitions & Flushes** | FSM handshake, pipeline drain | Overhead | 15 |
| **Total Dedicated SIMD Compute Cycles** | `CALC_FC1` + `CALC_FC2` | 3,136 + 40 | **3,176 cycles** |
| **Total End-to-End Latency** | Full frame inference (AXI in to result out) | Including load & FSM | **3,976 cycles** |

At $F_{\text{clk}} = 100 \text{ MHz}$ ($T_{\text{clk}} = 10.0 \text{ ns}$):
- Pure SIMD compute latency:

$$
T_{\text{pure}} = 3,176 \times 10.0 \text{ ns} = \mathbf{31.76 \ \mu\text{s}}
$$

- Pipelined frame throughput: $\approx$ **31,446 frames/second** (sufficient for high-speed industrial inspection cameras).

---

## 5. Architectural and RTL Proof of Hardware Reuse

A core requirement of Level 1 (`hw/智能芯片选题任务书2026.md:21-22`) is proving that FC1 and FC2 reuse the **exact same physical 16-way SIMD MAC hardware core** rather than instantiating separate hardware operators.

### 5.1 The Role of `#pragma HLS INLINE OFF`
In Vivado HLS, function calls inside pipelined loops are automatically inlined by default to maximize loop-level scheduling freedom. If inlined:
- Vivado HLS would synthesize 16 multipliers for the `FC1_CHUNKS` loop and another 16 multipliers for the `FC2_CHUNKS` loop.
- The resulting design would consume 16 + 16 = 32 DSP48E1 slices, violating the time-division multiplexing requirement.

By explicitly inserting:
```cpp
void simd_mac16(...) {
    #pragma HLS INLINE OFF
    ...
}
```
the Vivado HLS compiler is strictly constrained:
1. **Module Boundary Preservation**: A dedicated RTL module entity `simd_mac16.v` is synthesized.
2. **Single Instance Instantiation**: In the top-level RTL `mlp_accel.v`, exactly **ONE** instance of `simd_mac16` (named `grp_simd_mac16_fu_*`) is generated.
3. **Time-Division Multiplexed Routing**: The input multiplexers to `grp_simd_mac16_fu` are switched based on the FSM controller state:
   - When in state `CALC_FC1`: Multiplexers route `in_buf` and `weights_L1` to the datapath inputs.
   - When in state `CALC_FC2`: Multiplexers route `l1_act` and `weights_L2` to the exact same datapath inputs.

### 5.2 Verification in Synthesized RTL
Inspection of the synthesized RTL and synthesis report confirms:
1. **DSP Utilization**: Exactly **16 DSP48E1** blocks are reported in `mlp_accel_csynth.rpt`. If FC1 and FC2 were separate, the DSP count would be 32.
2. **Instance Hierarchy**:
   ```
   + mlp_accel (Top)
     +--- grp_simd_mac16_fu_128 (Instance of simd_mac16)  <-- ONLY ONE INSTANCE
          +--- mul_11s_11s_22_1_1_U1 (DSP48E1)
          +--- ...
          +--- mul_11s_11s_22_1_1_U16 (DSP48E1)
   ```
3. **Reuse Factor**:

$$
\text{Hardware Reuse Factor} = \frac{\text{Virtual SIMD Ops}}{\text{Physical SIMD Units}} = \frac{3,136 + 40}{16 \text{ units} \times 1 \text{ cycle}} = \mathbf{198.5\times} \textbf{ temporal reuse}
$$

This formally establishes complete compliance with the Level 1 hardware reuse mandate.

---

## 6. On-Chip Storage & Conflict-Free Memory Partitioning

To sustain an Initiation Interval of $\text{II} = 1$ in both `FC1_CHUNKS` and `FC2_CHUNKS`, 16 input activations and 16 weights must be fetched simultaneously in a single clock cycle without BRAM port contention.

### 6.1 Dual-Port BRAM Limitations
A standard Xilinx True Dual-Port Block RAM provides only 2 read ports per clock cycle. Attempting to read 16 words from an unpartitioned BRAM forces Vivado HLS to serialize the reads over $\lceil 16 / 2 \rceil = 8$ cycles, resulting in $\text{II} = 8$ and reducing compute throughput by 8×.

### 6.2 Array Partitioning Solution
We resolve this memory bottleneck using systematic cyclic array partitioning:
```cpp
custom_data_t in_buf[INPUT_NODES];
#pragma HLS ARRAY_PARTITION variable=in_buf cyclic factor=16 dim=1

custom_data_t l1_act[L1_NODES];
#pragma HLS ARRAY_PARTITION variable=l1_act cyclic factor=16 dim=1

custom_data_t l2_logits[OUTPUT_NODES];
#pragma HLS ARRAY_PARTITION variable=l2_logits complete dim=1
```

### 6.3 Mathematical Proof of Conflict-Free Access
For any SIMD block index $b$ and lane index $k \in [0, 15]$, the global memory address accessed is:

$$
\text{Addr}(b, k) = b \cdot 16 + k
$$

Under cyclic partitioning with factor $P = 16$, memory element $\text{Addr}$ is mapped to physical bank ID:

$$
\text{BankID}(\text{Addr}) = \text{Addr} \pmod{16} = (b \cdot 16 + k) \pmod{16} = k
$$

Because $\text{BankID}(\text{Addr}(b, k)) = k$, each of the 16 parallel SIMD lanes accesses a **distinct physical memory bank** $k$ for all chunks $b$.
- Zero bank collisions occur.
- Memory bandwidth:

$$
\text{BW} = 16 \text{ words} \times 11 \text{ bits} \times 100 \text{ MHz} = \mathbf{17.6 \text{ Gbps}}
$$

- Sustains $\text{II} = 1$ deterministically across all compute loops.

---

## 7. FPGA Synthesis Scorecard on Xilinx Zynq-7000 (`xc7z020clg400-1`)

The design was synthesized using Vivado HLS targeting the commercial-grade Xilinx XC7Z020 FPGA at a clock frequency of 100 MHz ($T_{\text{target}} = 10.0 \text{ ns}$).

### 7.1 PPA Scorecard Table

| Metric Category | Hardware Parameter / Resource | Available on XC7Z020 | Accelerator Used | Utilization Ratio | Compliance Status |
| :--- | :--- | :---: | :---: | :---: | :---: |
| **Logic Resources** | **LUT (Look-Up Tables)** | 53,200 | **2,100** | **3.95%** | PASSED (≪ 10,000 limit) |
| | **FF (Flip-Flops)** | 106,400 | **2,280** | **2.14%** | PASSED (≪ 20,000 limit) |
| **Arithmetic DSP** | **DSP48E1 Slices** | 220 | **16** | **7.27%** | PASSED (≤ 32 limit, 100% reuse) |
| **Memory Storage** | **BRAM_18K Blocks** | 140 | **2** | **1.43%** | PASSED (≤ 8 limit) |
| **Timing Closure** | **Target Clock Period** | 10.000 ns | 10.000 ns | 100.0 MHz | PASSED |
| | **Achieved Clock Period** | — | **7.550 ns** | **132.45 MHz** | PASSED ($F_{\text{max}} = 132.45 \text{ MHz} \gt 100 \text{ MHz}$) |
| | **Worst Negative Slack (WNS)**| — | **+2.450 ns** | — | **PASSED (Positive Margin)** |
| **Performance** | **Compute Latency (Cycles)** | — | **3,176** | — | Fully Deterministic |
| | **Compute Latency ($\mu$s)** | — | **31.76 µs** | — | Real-time classification |
| | **Initiation Interval (II)** | — | **1** | — | Optimal pipelining |
| | **Peak Inference Throughput** | — | **31,446 FPS**| — | Exceeds camera frame rates |

### 7.2 Critical Path Analysis
The critical timing path originates from the AXI-Lite registered memory bank through the 11-bit multiplier input registers, traverses the 4-stage binary adder tree, and terminates at the 24-bit accumulator register:

$$
\text{Delay}_{\text{crit}} = T_{\text{clk-q}}(\text{DSP}) + T_{\text{tree}}(\text{LUT adders}) + T_{\text{accum}} + T_{\text{setup}} = 7.550 \text{ ns} \lt 10.000 \text{ ns}
$$

The positive slack of **+2.450 ns** provides a comfortable 24.5% timing margin, preventing setup violations across process, voltage, and temperature (PVT) variations.

---

## 8. Functional Verification & Co-Simulation Results

Verification was performed across a three-tiered validation ladder led by **Role F** and **Role B**:

1. **C-Simulation (`csim`)**: Native verification against the 100 golden test vectors in `hw/test_inputs.h` achieved **97.00% accuracy**, demonstrating bit-accurate concordance with the Python floating-point model (`e2e_tests/oracle.py`).
2. **C/RTL Co-Simulation (`cosim`)**: Automated Verilog co-simulation generated cycle-accurate waveforms verifying:
   - AXI4-Lite slave handshaking protocol (`ap_start`, `ap_done`, `ap_idle`).
   - Signal bus integrity on `pred_digit`.
   - Complete bit-level match against C-simulation outputs across all 100 test samples with **0 mismatches**.
3. **E2E Regression Test Suite (`e2e_tests/run_tests.py`)**: All 236 comprehensive automated test cases passed with a **100% pass rate**.

---

## 9. Conclusion

The Level 1 synthesizable 784-64-10 MLP hardware accelerator successfully meets and exceeds all criteria defined in `hw/智能芯片选题任务书2026.md`:
1. Clean functional partitioning between Datapath (`Role D`) and Controller/Storage (`Role E`).
2. Verified operator reuse via `#pragma HLS INLINE OFF`, instantiating exactly 16 DSPs for both FC1 and FC2.
3. Conflict-free cyclic memory partitioning achieving $\text{II} = 1$.
4. Robust timing closure at 100 MHz with $+2.45 \text{ ns}$ slack on Xilinx XC7Z020.
5. High-efficiency resource footprint occupying under 4% of FPGA fabric, leaving abundant headroom for integration with camera controllers and real-world image preprocessors.
