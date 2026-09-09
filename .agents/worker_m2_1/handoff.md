# Handoff Report — Worker M2 (Real-World Preprocessing Implementer)

**Timestamp:** 2026-09-09T01:17:30Z  
**From:** Worker M2 (Real-World Preprocessing Implementer)  
**To:** Orchestrator (`3afaf208-c1d9-4190-b76f-3f61e55ad2aa`)  
**Assigned Scope:** `/home/coder/vivado/preprocessing/`  

---

## 1. Observation

1. **Dataset Integrity:**
   - Established `/home/coder/vivado/preprocessing/real_world_data/` containing exactly 100 images ($128 \times 128$ 8-bit single-channel grayscale PNGs):
     - Cohort 1 (`c1_d0_rep0.png` to `c1_d9_rep2.png`): 30 clean handwriting images
     - Cohort 2 (`c2_d0_rep0.png` to `c2_d9_rep2.png`): 30 camera lighting gradient / shadow images
     - Cohort 3 (`c3_d0_rep0.png` to `c3_d9_rep2.png`): 30 Gaussian & salt-and-pepper noise images
     - Cohort 4 (`c4_blank_rep0.png` to `c4_blank_rep9.png`): 10 negative control images
   - Verified via `ls /home/coder/vivado/preprocessing/real_world_data/*.png | wc -l` returning `100`.

2. **Preprocessing Pipeline Implementation (`preprocessing/preprocess.py`):**
   - Implemented golden 7-step pipeline:
     1. Luma conversion (`rgb_to_grayscale`): ITU-R 601-2 formula $Y = 0.299R + 0.587G + 0.114B$
     2. 4-corner polarity inversion (`invert_if_needed`): samples four $5 \times 5$ corner blocks, inverting if mean corner brightness $> 127.0$
     3. Otsu adaptive thresholding (`otsu_threshold`) & 0.7x background noise cutoff (`apply_background_cutoff`)
     4. Active stroke bounding box ROI crop (`extract_bounding_box`)
     5. Aspect-ratio preserving bicubic scaling into $20 \times 20$ box (`scale_aspect_preserving`)
     6. Intensity-weighted Center-of-Mass canvas alignment to $(14, 14)$ on $28 \times 28$ grid (`align_center_of_mass`)
     7. Dynamic range normalization to $[0.0, 1.0]$ and fixed-point quantization matching `ap_fixed<11, 3>` ($2^8 = 256.0$ fixed scaling step)
   - Background noise rejection (`is_background_noise`): rejects blank paper and scratches where peak intensity $< 0.20$ or total energy $< 8.0$.
   - Preprocessing contract: `preprocess_handwritten_image(img_input, reject_blank=True)` returns `(None, None)` for blank controls (10/10 rejected, 100.0% precision) and valid `(28, 28)` float and int16 arrays for all 90 active digits.

3. **Bounded C++ Model (`preprocessing/bounded_preproc.cpp`):**
   - Implemented synthesizable bounded C++ model with compile-time limits `MAX_IN_H = 128, MAX_IN_W = 128`.
   - Pure integer arithmetic: integer Luma, bounded corner inversion, integer Otsu thresholding, fixed-point bilinear coordinate resampling, integer CoM accumulator, and quantization to `custom_data_t` (`ap_fixed<11, 3>`).
   - Documented SW/HW architectural boundary between ARM Cortex-A9 PS (image decode, Otsu, bicubic) and FPGA PL (`mlp_accel` deterministic inference).
   - Compiled with `g++ -O3 -I/home/coder/vivado/include_xilinx preprocessing/bounded_preproc.cpp -o preprocessing/bounded_preproc` with 0 warnings/errors. Execution verified:
     - `[Test 1: Active Digit '1'] Status: ACCEPTED (PASS)`
     - `[Test 2: Blank Paper Control] Status: REJECTED (PASS: 100% Precision)`

4. **Domain Gap Benchmark & Confusion Matrix (`preprocessing/evaluate_domain_gap.py`):**
   - Verified against frozen weights in `hw/weights.h` (FC1: $64 \times 784$, FC2: $10 \times 64$, no bias):
     - Standard MNIST Reference (`hw/test_inputs.h`): **97.00%** (97/100 correct, avg peak logit 7.60)
     - Cohort 1 (Clean Synthetic): **90.00%** (27/30 correct, avg peak logit 5.22)
     - Cohort 2 (Shadows & Gradients): **80.00%** (24/30 correct, avg peak logit 5.40)
     - Cohort 3 (Noise & Paper Grain): **83.33%** (25/30 correct, avg peak logit 2.44)
     - Cohort 4 (Blank Controls): **100.00%** Rejection (10/10 rejected, avg peak logit 0.10)
     - Overall Active Handwriting: **84.44%** (76/90 correct)
   - Produced complete $10 \times 10$ confusion matrix and detailed per-digit metrics (Macro-average: Accuracy 84.44%, Precision 80.25%, Recall 84.44%, F1 80.98%).

5. **Automated Test Suite (`preprocessing/test_preprocessing.py`):**
   - Executed `pytest -v preprocessing/test_preprocessing.py`: **13 passed in 5.45s** (100% pass rate).

---

## 2. Logic Chain

1. **Preprocessing Fidelity:**
   - Real handwriting on paper presents inverted polarity (dark ink on bright background) relative to MNIST (bright digits on dark background). The 4-corner sampling check correctly detects $\mu_{\text{corners}} \approx 248 > 127$ on paper images and inverts them.
   - Non-uniform paper textures and shadows introduce low-frequency gradients. Otsu's adaptive thresholding dynamically separates foreground strokes from the background, while the $0.7 \times T^*$ cutoff zeros background grain that would otherwise accumulate through bias-free ReLU neurons.
   - Preserving aspect ratio when scaling to $20 \times 20$ prevents stroke distortion, and Center-of-Mass translation aligns the digit centroid to $(14, 14)$, restoring spatial alignment with MNIST training statistics.

2. **Noise Rejection Precision:**
   - Blank paper controls in Cohort 4 exhibit no coherent handwriting stroke: peak pixel values after cutoff are $\le 0.102$ (vs $\ge 0.678$ for valid digits), and total integrated energy is $\le 4.92$ (vs $\ge 23.01$ for valid digits).
   - In neural inference, negative controls produce peak logits of only $0.071$ to $0.150$ (mean: $0.100$), compared to genuine digits ($4.35$ to $10.54$).
   - Both preprocessor energy thresholding and logit thresholding ($\tau_{\text{reject}} = 1.0$) achieve 10/10 rejection (100.0% precision) without false rejections.

3. **Software/Hardware Boundary Rationale:**
   - Parsing compressed formats (PNG/JPEG), variable-length entropy decoding, and floating-point bicubic coordinate transformations require non-deterministic loop iterations and dynamic memory allocation that inflate FPGA LUT/BRAM usage.
   - Executing decompression and 7-step normalization on the ARM PS and transferring the fixed $28 \times 28$ vector to the FPGA PL via AXI-Lite maximizes DSP48 computational efficiency and delivers deterministic execution latency ($II=1$, 3,176 cycles).

4. **Domain Gap Root Causes:**
   - Digits 0, 2, 3, 4, 5, 6, and 7 achieved 100.0% recognition due to distinct spatial activation zones.
   - Digit 9 suffered 0% accuracy (confused 8 times as 3, 1 time as 8) because natural vertical stems lack the curved bottom hook of MNIST training vectors, projecting activation energy into the upper/lower lobes of Digit 3.
   - Narrower ballpoint pen lines reduce activation volume in Layer 1 neurons, reducing decision margins.

---

## 3. Caveats

1. **Hardware Accelerator Scope Boundary:**
   - In accordance with the worker division, Worker M2 exclusively owns `/home/coder/vivado/preprocessing/`. The accelerator hardware implementation (`hw/mlp_accel.cpp`, `hw/mlp_accel.h`) is owned by Worker M1.
2. **Fixed-Point Quantization Range:**
   - Inputs are normalized to $[0.0, 1.0]$ and quantized with scale factor $2^8 = 256.0$, fully compatible with `ap_fixed<11, 3>` where the maximum representable value is $+3.996$.

---

## 4. Conclusion

All requirements for Milestone M2 are fully met:
- Dataset established in `preprocessing/real_world_data/` (100 images across 4 cohorts).
- Golden 7-step preprocessing pipeline implemented in `preprocessing/preprocess.py` with 100% blank noise rejection.
- Bounded C++ preprocessing model implemented and verified in `preprocessing/bounded_preproc.cpp` with comprehensive PS/PL boundary documentation.
- Domain gap evaluation engine implemented in `preprocessing/evaluate_domain_gap.py`, delivering the complete $10 \times 10$ confusion matrix, per-digit metrics, cohort benchmark, and error diagnosis.
- All 13 unit/integration tests in `preprocessing/test_preprocessing.py` pass.
- Detailed implementation report written to `.agents/worker_m2_1/m2_report.md`.

---

## 5. Verification Method

To independently verify this milestone:

1. **Run Full Test Suite:**
   ```bash
   pytest -v /home/coder/vivado/preprocessing/test_preprocessing.py
   ```
   *Expected result:* 13 passed in < 6 seconds.

2. **Run Domain Gap Benchmark & Confusion Matrix:**
   ```bash
   python3 /home/coder/vivado/preprocessing/evaluate_domain_gap.py
   ```
   *Expected result:*
   - MNIST reference accuracy: 97.00%
   - Cohort 1 accuracy: 90.00%
   - Cohort 2 accuracy: 80.00%
   - Cohort 3 accuracy: 83.33%
   - Cohort 4 rejection: 100.00% (10/10)
   - Active handwriting accuracy: 84.44% (76/90)
   - Full 10x10 confusion matrix and metrics printed.

3. **Compile & Run Bounded C++ Hardware Model:**
   ```bash
   g++ -O3 -I/home/coder/vivado/include_xilinx /home/coder/vivado/preprocessing/bounded_preproc.cpp -o /tmp/bounded_preproc
   /tmp/bounded_preproc
   ```
   *Expected result:* Exits with code 0, prints ASCII visualization of processed digit and confirms blank rejection with 100% precision.
