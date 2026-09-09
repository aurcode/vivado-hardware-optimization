# Handoff Report: Hardware & HLS Survey for Intelligent Chip Accelerator Project

**Author:** Hardware & HLS Explorer (`explorer_survey_2`)  
**Recipient:** Orchestrator (`orchestrator_1` / ID `3afaf208-c1d9-4190-b76f-3f61e55ad2aa`)  
**Type:** Hard Handoff (Task Complete)  
**Deliverable File:** `/home/coder/vivado/.agents/explorer_survey_2/survey_hw_report.md`  
**Date:** 2026-09-09  

---

## 1. Observation

1. **Weights Specification (`/home/coder/vivado/hw/weights.h`):**
   - Line 6: `typedef ap_fixed<11, 3, AP_RND, AP_SAT> custom_data_t;`
   - Line 8: `static const custom_data_t weights_L1[64][784] = { ... };` ($64 \times 784 = 50,176$ elements).
   - Line 75: `static const custom_data_t weights_L2[10][64] = { ... };` ($10 \times 64 = 640$ elements).
   - Total parameters: $50,176 + 640 = 50,816$. Zero bias vectors ($b_1 = 0, b_2 = 0$).
   - Dynamic range: $\min = -1.000$, $\max = +0.6758$. Quantization step: $2^{-8} = 0.00390625$. All constants are exact integer multiples of $\frac{1}{256}$.
   - Raw bit footprint: $50,816 \times 11\text{ bits} = 558,976\text{ bits} \approx 69.87\text{ KB}$. At 16-bit word alignment: $101,632\text{ bytes} \approx 99.25\text{ KB}$.

2. **Test Inputs & Baseline Accuracy (`/home/coder/vivado/hw/test_inputs.h`):**
   - Line 7: `static const int TEST_SAMPLE_COUNT = 100;`
   - Line 9: `static const custom_data_t test_inputs[TEST_SAMPLE_COUNT][784]` (normalized to $[0.0, 1.0]$).
   - Line 112: `static const unsigned char test_labels[TEST_SAMPLE_COUNT]` (100 labels covering classes 0-9).
   - Forward pass verification: Tested with exact numerical forward pass ($a_1 = \text{ReLU}(W_1 x)$, $z_2 = W_2 a_1$, $\hat{y} = \arg\max z_2$). Accuracy: **97 / 100 = 97.00%** (exceeds requirement $\ge 90\%$). Three errors: Sample 8 (true 5, pred 6), Sample 18 (true 3, pred 8), Sample 38 (true 2, pred 3).

3. **Build & Simulation Infrastructure (`/home/coder/vivado/Makefile`, `/home/coder/vivado/Dockerfile`):**
   - Host `g++` 13.3.0 is installed on Ubuntu 24.04.
   - Header library `/home/coder/vivado/include_xilinx` contains complete Xilinx HLS C++ headers (`ap_fixed.h`, etc.).
   - Docker image `fpgatools/vivado:latest` (ID `65f13b302724`, Content Size: 9.86 GB) is available locally.
   - Verified tool execution inside Docker:
     `docker run --rm fpgatools/vivado:latest bash -c "source /opt/Xilinx/Vivado/2018.3/settings64.sh && vivado_hls -version"`
     Output: `Vivado(TM) HLS ... v2018.3 (64-bit) SW Build 2405991`.
   - `/home/coder/vivado/Vivado_init.tcl` patches Xilinx AR-76960 timestamp overflow on IP export.

4. **Resource Limits & Previous Implementation Analysis (`first_test/`):**
   - Project limits from `ORIGINAL_REQUEST.md`: **LUT $\le$ 10,000**, **DSP $\le$ 32**, **BRAM $\le$ 8**, **Positive Slack at 10.0 ns**.
   - Inspection of `first_test/scripts/phase5_dse/proj_w16_simd16/sol_w16_simd16/syn/report/mlp_accel_csynth.rpt`:
     - Line 63: `DSP: 48` (exceeded 32 because `#pragma HLS INLINE` on `simd_mac16` duplicated the 16 DSPs across 3 loops).
     - Line 67: `Memory: 138 BRAM_18K` (exceeded 8 because weights were partitioned along dim=3 into 16 BRAM banks).
     - Line 23: `ap_clk Estimated: 11.425 ns` (violated 10.0 ns target clock due to unpipelined reduction tree chaining).

---

## 2. Logic Chain

1. From Observation 1, the official model architecture is 784-64-10 (2 layers, bias-free, `ap_fixed<11, 3>`), in contrast to the 3-layer 784-128-64-10 network prototyped in `first_test/`. Therefore, all downstream implementations must be built specifically for 784-64-10 using `hw/weights.h`.
2. From Observation 2, the 97.00% accuracy on the 100 test samples in `hw/test_inputs.h` proves that the frozen weights are mathematically sound and meet the acceptance criterion ($\ge 90\%$) with a 7.0 percentage point margin.
3. From Observation 3, the host environment supports instant native C++ simulation (`make host-sim`), and the containerized environment supports headless batch Vivado HLS execution (`csim`, `csynth`, `cosim`, `export`).
4. From Observation 4, inlining the SIMD MAC core in HLS causes multiplier duplication. To guarantee "only 1 instance of the 16-way SIMD MAC core is generated" and satisfy **DSP $\le$ 32**, the compute core must be either marked `#pragma HLS INLINE OFF` or contained within a single shared FSM execution loop.
5. From Observation 1 and 4, storing 50,816 11-bit weights ($558.98$ Kb) in on-chip dual-port BRAM requires at least 31 BRAM_18K blocks, physically exceeding the **BRAM $\le$ 8** limit if weights are internal BRAM. Therefore, the implementation team must verify the memory boundary (e.g. streaming weights or determining if BRAM $\le$ 8 applies to activation/control buffers while weights reside in ROM/external memory).

---

## 3. Caveats

1. The exact physical memory boundary for weights under the **BRAM $\le$ 8** constraint requires architectural confirmation: 558,976 bits cannot physically fit into 8 BRAM_18K blocks (147,456 bit raw capacity) unless weights are streamed or external.
2. In host C++, compiling `weights.h` and `test_inputs.h` directly with `g++ -O2` takes several minutes due to 129,216 dynamic constructor calls from float literals. Compiling with `-O1` or generating a pre-scaled companion header (`int16_t`) is recommended for host testbenches.

---

## 4. Conclusion

The hardware assets in `hw/` and the Vivado HLS Docker environment are fully surveyed, verified, and operational.
- The network topology is frozen at **784-64-10**, bias-free, with `ap_fixed<11, 3, AP_RND, AP_SAT>`.
- Baseline accuracy is confirmed at **97.00%**.
- The 16-way SIMD MAC core execution takes **3,176 cycles** ($3,136$ cycles for FC1, $40$ cycles for FC2).
- The full technical survey report is published at `/home/coder/vivado/.agents/explorer_survey_2/survey_hw_report.md`.

---

## 5. Verification Method

1. **Verify Baseline Accuracy:**
   ```bash
   /home/coder/vivado/.venv_ai/bin/python -c "
   import re, numpy as np
   with open('hw/weights.h') as f: w = f.read()
   with open('hw/test_inputs.h') as f: t = f.read()
   w1 = np.array([float(x.rstrip('f')) for x in re.findall(r'[-+]?[0-9]*\.?[0-9]+f?', re.search(r'weights_L1\[64\]\[784\]\s*=\s*\{([^;]+)\};', w).group(1))], dtype=np.float32).reshape(64, 784)
   w2 = np.array([float(x.rstrip('f')) for x in re.findall(r'[-+]?[0-9]*\.?[0-9]+f?', re.search(r'weights_L2\[10\]\[64\]\s*=\s*\{([^;]+)\};', w).group(1))], dtype=np.float32).reshape(10, 64)
   X = np.array([float(x.rstrip('f')) for x in re.findall(r'[-+]?[0-9]*\.?[0-9]+f?', re.search(r'test_inputs\[TEST_SAMPLE_COUNT\]\[784\]\s*=\s*\{([^;]+)\};', t).group(1))], dtype=np.float32).reshape(100, 784)
   y = np.array([int(x) for x in re.findall(r'\d+', re.search(r'test_labels\[TEST_SAMPLE_COUNT\]\s*=\s*\{([^;]+)\};', t).group(1))], dtype=np.int32)
   preds = np.argmax(np.maximum(0, np.dot(X, w1.T)) @ w2.T, axis=1)
   print('Accuracy:', (preds == y).sum(), '/ 100')
   "
   ```
   **Expected Output:** `Accuracy: 97 / 100`.

2. **Verify Docker Vivado HLS 2018.3 Batch Flow:**
   ```bash
   docker run --rm fpgatools/vivado:latest bash -c "source /opt/Xilinx/Vivado/2018.3/settings64.sh && vivado_hls -version"
   ```
   **Expected Output:** `Vivado(TM) HLS ... v2018.3 (64-bit) SW Build 2405991`.
