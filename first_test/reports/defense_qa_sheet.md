# Professor Defense Q&A Sheet: Intelligent Chip & System Design

**Project:** Edge AI Hardware Accelerator on Xilinx Zynq-7000  
**Target:** Oral Defense & Evaluation Committee  
**Authors:** 8-Person Engineering Team

---

### Question 1: Architectural Selection
**"Why did you choose a Time-Division Multiplexed (TDM) SIMD compute core instead of a 2D Systolic Array or a Fully Unrolled Pipelined Architecture?"**

**Authoritative Answer:**
> "We selected a TDM SIMD architecture based on a rigorous quantitative analysis of the Multi-Layer Perceptron's operational characteristics and the resource constraints of the Xilinx XC7Z020:
> 
> 1. **Vs. Fully Unrolled Replication:** A fully unrolled design for ${784 \to 128 \to 64 \to 10}$ requires ${100,352 + 8,192 + 640 = 109,184}$ distinct multiplications. Even with aggressive resource sharing, an unrolled pipeline across all layers would exceed the 220 DSP48E1 slices available on the XC7Z020 by more than an order of magnitude.
> 2. **Vs. 2D Systolic Array:** Systolic arrays excel in convolutional workloads and matrix-matrix multiplications where weight stationary or output stationary data reuse is high ($O(N^3)$ compute vs. $O(N^2)$ memory bandwidth). However, single-image edge MLP inference is fundamentally a matrix-vector multiplication ($\mathbf{y} = \mathbf{W}\mathbf{x}$), which exhibits zero weight reuse across time—every weight is fetched exactly once per inference. A 2D systolic array would suffer from low processing element (PE) utilization and significant register pipeline draining overheads.
> 3. **The TDM Advantage:** By time-sharing a unified 16-way (or 32-way) SIMD MAC core across all layers, we achieved **100% PE utilization** during compute phases, constrained DSP consumption to just **48 DSP48E slices (21.8%)**, and kept the total latency under **82 microseconds**, which comfortably exceeds real-time frame rates."

---

### Question 2: Memory Port Contention & Loop Scheduling
**"How did you eliminate memory bank conflicts and guarantee an Initiation Interval of II = 1 in your HLS inner loops?"**

**Authoritative Answer:**
> "The primary obstacle to achieving $II = 1$ in Vivado HLS is memory port contention: standard FPGA Block RAMs are dual-port, meaning each BRAM primitive can provide at most two independent memory reads per clock cycle. A naive 16-way SIMD MAC requires 16 simultaneous activation operands and 16 simultaneous weight operands per cycle.
> 
> We resolved this via two key microarchitectural decisions:
> 
> 1. **Block-Aligned 3D Memory Mapping:** Instead of declaring flat 2D arrays (`weights[128][784]`) which trigger complex modulo address generators and dynamic multiplexing, we structured all arrays into 3D blocks matching the SIMD granularity: `weights[neurons][blocks][SIMD_WIDTH=16]`.
> 2. **Complete Partitioning Along the Inner Dimension:** We applied:
>    ```cpp
>    #pragma HLS ARRAY_PARTITION variable=weights_l1 complete dim=3
>    #pragma HLS ARRAY_PARTITION variable=input_buf complete dim=2
>    ```
>    This directive physically instantiates 16 distinct dual-port BRAM memory banks. When loop index `b` increments, the address presented to all 16 memory banks is identical, enabling all 16 weights and 16 activations to be fetched concurrently in a single clock cycle without port stalls, achieving a sustained **Initiation Interval II = 1**."

---

### Question 3: Quantization Theory & The 4-bit Cliff
**"Your Level 3 DSE report shows that 8-bit quantization achieved 97.67% accuracy (only 0.09% drop from FP32), while 4-bit quantization collapsed to 83.62% (a 14.14% drop). Mathematically and structurally, why does 4-bit Post-Training Quantization fail so severely?"**

**Authoritative Answer:**
> "This phenomenon represents the well-documented **quantization noise-to-signal ratio cliff**:
> 
> 1. **Step-Size Discretization Noise:** Under uniform affine quantization with bitwidth $W$, the quantization step size $\Delta = \frac{x_{\max} - x_{\min}}{2^W - 1}$. The expected quantization error variance is:
>
> $$
> \sigma_q^2 = \frac{\Delta^2}{12}
> $$
>
>    Comparing 8-bit (${2^8 = 256}$ bins) to 4-bit (${2^4 = 16}$ bins), the step size $\Delta$ increases by a factor of 16, meaning the quantization noise power increases by a factor of ${16^2 = 256}$ ($+24 \text{ dB}$ of noise).
> 2. **High-Dimensional Error Accumulation in Layer 1:** In Layer 1, each neuron computes a dot product of 784 dimensions:
>
> $$
> \tilde{z} = \sum_{k=1}^{784} (x_k + \epsilon_{x,k})(w_k + \epsilon_{w,k})
> $$
>
>    While individual quantization errors $\epsilon$ are mean-zero, their variances accumulate linearly across the 784 inputs. At 4-bit, the accumulated noise variance $\sum 784 \cdot \sigma_q^2$ exceeds the inter-class decision boundary margin, causing the sign of $\tilde{z}$ to flip frequently, corrupting ReLU activations.
> 3. **Lack of Retraining:** In Post-Training Quantization (PTQ), weights are frozen. To recover accuracy at 4-bit, Quantization-Aware Training (QAT) with Straight-Through Estimators (STE) is required so the optimizer can adapt the weight distribution to the coarse 16-bin grid."

---

### Question 4: Timing Closure & Adder Tree Critical Path
**"In your synthesis report, the estimated clock period is 11.42 ns, slightly exceeding the 10.0 ns target. What constitutes the critical path, and how would you close timing at 100 MHz?"**

**Authoritative Answer:**
> "From line 23 of our synthesis report (`mlp_accel_csynth.rpt`), Vivado HLS identified the critical path:
> - DSP Multiplier: 3.36 ns
> - DSP Internal Adder: 3.02 ns
> - LUT Adder Stage 2: 2.52 ns
> - LUT Adder Stage 3: 2.52 ns
> - Total Path Delay: **11.42 ns**
> 
> This delay arises because Vivado HLS scheduled the multi-operand balanced reduction tree (`16 -> 8 -> 4 -> 2 -> 1`) and the loop-carried accumulation in a single cycle to achieve an iteration latency of 5 cycles with $II=1$.
> 
> **How to close timing at 100 MHz (10.0 ns):**
> 1. **Pipeline Register Insertion in Tree:** Insert intermediate pipeline registers between Stage 2 and Stage 3 of the adder tree:
>    ```cpp
>    acc_t stage2_reg[4];
>    #pragma HLS PIPELINE
>    ```
>    This splits the 11.42 ns path into two independent stages of ~5.8 ns and ~5.6 ns, achieving a maximum operating frequency of **~175 MHz** on the -1 speed grade XC7Z020.
> 2. **Relax Target Clock Uncertainty:** In `run_hls.tcl`, Vivado HLS applies a conservative default clock uncertainty of 1.25 ns (effective budget: 8.75 ns). In Vivado Implementation (Place & Route), the actual routing delay on the XC7Z020 with dedicated DSP cascade chains (`PCOUT -> PCIN`) comfortably closes timing at 100 MHz."

---

### Question 5: PS-PL Interface Architecture
**"You used an AXI4-Lite slave interface (`s_axilite port=return bundle=CTRL_BUS`). Why did you choose AXI4-Lite over an AXI-Master DMA interface, and how does this affect system performance?"**

**Authoritative Answer:**
> "Our interface choice was driven by data volume vs. protocol overhead tradeoffs:
> 
> 1. **Data Volume Analysis:**
>    - Input vector: 784 `int16_t` pixels = **1,568 bytes**.
>    - Output vector: 10 `int16_t` logits = **20 bytes**.
>    - Total payload per inference: **1,588 bytes (1.55 KB)**.
> 2. **AXI-Lite vs. AXI DMA:** Setting up an AXI DMA transaction requires the ARM Cortex-A9 processor to write to DMA source/destination registers, configure buffer descriptors, flush L1/L2 data caches, and handle interrupt service routines (ISRs). The software driver overhead of DMA initiation is typically **5 to 15 microseconds**.
> 3. **System Latency Comparison:** At 100 MHz on a 32-bit AXI-Lite bus, burst-writing 784 pixels takes approximately 392 clock cycles = **3.92 microseconds**. Since 3.92 $\mu$s is significantly lower than the DMA setup latency, AXI-Lite provides lower end-to-end CPU-to-Accelerator latency for single-frame inference.
> 4. **Scalability:** If batching thousands of images from DDR memory (e.g., continuous video streaming), transitioning to an AXI-Stream interface coupled with an AXI DMA engine in scatter-gather mode would be optimal."

---

### Question 6: Real-World Degradation & Domain Shift
**"Why does an MLP model experience performance degradation on real-world camera images (Cohort 2: 90.0%, Cohort 3: 86.67%) even when trained to 97.76% accuracy on MNIST, and how does your preprocessing pipeline address this?"**

**Authoritative Answer:**
> "The performance degradation is driven by three structural and statistical domain shifts:
> 
> 1. **No Translation Invariance (MLP vs. CNN):** Unlike Convolutional Neural Networks (CNNs) that feature weight sharing and translation invariance via spatial sliding kernels, an MLP is a fully connected dense projection ($\mathbf{W} \in \mathbb{R}^{128 \times 784}$). Every input feature corresponds to an absolute spatial coordinate $(x, y)$. If a digit is shifted by just 2 pixels, stroke pixels activate weights trained for background margins, drastically altering the dot-product sum.
> 2. **Stroke Thickness Discrepancy:** Synthetic MNIST digits were normalized with antialiased ~3-pixel strokes. Real ballpoint handwriting produces 1-pixel high-frequency lines, reducing total integrated energy in the hidden layer.
> 3. **Our Preprocessing Mitigation:**
>    - **Otsu Thresholding:** Dynamically computes the bimodal intensity cutoff, rejecting shadows and ambient paper lighting gradients.
>    - **Aspect-Ratio Preserved Rescaling:** Fits the digit into a ${20\times 20}$ bounding box before placing it into the ${28\times 28}$ canvas, restoring the expected stroke density.
>    - **Center-of-Mass Alignment:** Translates the intensity-weighted center $(\bar{y}, \bar{x})$ to $(14, 14)$, restoring spatial alignment with the trained MLP weights."

---

### Question 7: Hardware Power & Energy Efficiency
**"How does your accelerator minimize dynamic power consumption on the FPGA?"**

**Authoritative Answer:**
> "Dynamic power on CMOS FPGAs is governed by $P_{\text{dyn}} = \alpha \cdot C \cdot V_{\text{dd}}^2 \cdot f$, where $\alpha$ is the switching activity factor and $C$ is capacitance:
> 
> 1. **Zero Dynamic Switching on Inactive Layers:** Because our architecture is FSM-driven, only the memory banks and compute paths of the active layer switch; the remaining memory blocks remain clock-enabled but inactive.
> 2. **Pruning Bias Parameters:** Removing biases eliminated 202 additions, avoiding spurious toggling of carry-chain registers.
> 3. **Word-Level Quantization (8-bit):** In our `W8_SIMD32` configuration, transitioning from 16-bit to 8-bit operands reduced the multiplier bitwidth by half. Multiplier dynamic switching scales quadratically ($O(W^2)$) with bitwidth, resulting in an estimated **~70% reduction in multiplier switching energy**.
> 4. **Low Clock Frequency:** Running at 100 MHz achieves 17,928 FPS while maintaining total chip dynamic power below **~0.35 Watts** on the Zynq PL, enabling passive cooling in embedded enclosures."
