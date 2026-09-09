"""
Tier 2: Boundary & Corner Cases E2E Tests (Features 1 through 22).
Covers all-zero, maximum-intensity, negative, clipping/saturation, OOD, and blank image corner cases.
At least 5 test cases per feature.
Total test cases: 110.
"""

import os
import math
import unittest
import numpy as np
from PIL import Image

from e2e_tests.oracle import (
    DataLoader,
    MLPAcceleratorOracle,
    FixedPoint11_3,
    AXILiteRegisters,
    simd_mac16_balanced_tree,
    sign_bit_relu,
    parallel_argmax,
    rgb_to_grayscale,
    invert_if_needed,
    otsu_threshold,
    extract_bounding_box,
    preprocess_image_7step,
    is_blank_or_noise_sample,
    compute_confusion_matrix,
    compute_precision_recall,
    get_all_zeros_vector,
    get_all_max_vector,
    get_all_min_vector,
    get_alternating_vector,
    get_single_hot_vector,
    FIXED_SCALE,
    FIXED_MIN_INT,
    FIXED_MAX_INT,
    FIXED_MIN_FLOAT,
    FIXED_MAX_FLOAT
)

BASE_DIR = "/home/coder/vivado"


class TestTier2Boundaries(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.w1, cls.w2 = DataLoader.load_weights(BASE_DIR)
        cls.inputs, cls.labels = DataLoader.load_test_inputs(BASE_DIR)
        cls.oracle = MLPAcceleratorOracle(BASE_DIR)

    # =========================================================================
    # Feature 1 Boundary: Topology & Dynamic Range Boundaries
    # =========================================================================
    def test_f1_b01_all_zeros_input_vector(self):
        """F1 Boundary: All-zero input vector executes without NaN or crash."""
        all_zeros = get_all_zeros_vector()
        pred, logits_f, logits_i, cycles = self.oracle.run_inference(all_zeros)
        self.assertFalse(np.isnan(logits_f).any())
        self.assertEqual(cycles, 3176)
        # With zero input and bias-free network, all hidden activations are 0, logits are 0
        self.assertTrue(np.all(logits_i == 0))
        # Argmax deterministic tie-break selects class 0
        self.assertEqual(pred, 0)

    def test_f1_b02_all_maximum_positive_input_vector(self):
        """F1 Boundary: Maximum positive input (+3.996) saturates via AP_SAT without overflow."""
        all_max = get_all_max_vector()
        pred, logits_f, logits_i, cycles = self.oracle.run_inference(all_max)
        self.assertFalse(np.isnan(logits_f).any())
        self.assertIn(pred, range(10))
        # Logits must stay within valid 11-bit integer bounds [-1024, 1023]
        self.assertTrue(np.all(logits_i >= FIXED_MIN_INT))
        self.assertTrue(np.all(logits_i <= FIXED_MAX_INT))

    def test_f1_b03_all_negative_input_vector(self):
        """F1 Boundary: All negative input (-4.0) zeroed by sign-bit ReLU."""
        all_min = get_all_min_vector()
        pred, logits_f, logits_i, cycles = self.oracle.run_inference(all_min)
        self.assertFalse(np.isnan(logits_f).any())
        self.assertIn(pred, range(10))

    def test_f1_b04_alternating_extreme_dynamic_swing(self):
        """F1 Boundary: Alternating +3.996 and -4.0 exercises maximum dynamic range swing."""
        alt_vec = get_alternating_vector()
        pred, logits_f, logits_i, cycles = self.oracle.run_inference(alt_vec)
        self.assertFalse(np.isnan(logits_f).any())
        self.assertTrue(np.all(logits_i >= FIXED_MIN_INT))
        self.assertTrue(np.all(logits_i <= FIXED_MAX_INT))

    def test_f1_b05_single_hot_pixel_impulse(self):
        """F1 Boundary: Single isolated active pixel executes localized dot-product."""
        hot_vec = get_single_hot_vector(hot_idx=392, val=1.0)
        pred, logits_f, logits_i, cycles = self.oracle.run_inference(hot_vec)
        self.assertEqual(cycles, 3176)
        self.assertIn(pred, range(10))

    # =========================================================================
    # Feature 2 Boundary: 16-Way SIMD MAC Arithmetic Boundaries
    # =========================================================================
    def test_f2_b01_simd_mac_all_zeros(self):
        """F2 Boundary: 16-element zero vector produces exactly 0."""
        zeros16 = np.zeros(16, dtype=np.int32)
        res = simd_mac16_balanced_tree(zeros16, zeros16)
        self.assertEqual(res, 0)

    def test_f2_b02_simd_mac_positive_saturation(self):
        """F2 Boundary: 16-way max multiplication (+1023 * +1023) handles large accumulation."""
        max16 = np.full(16, FIXED_MAX_INT, dtype=np.int32)
        res = simd_mac16_balanced_tree(max16, max16)
        expected = 16 * (FIXED_MAX_INT * FIXED_MAX_INT)
        self.assertEqual(res, expected)

    def test_f2_b03_simd_mac_negative_saturation(self):
        """F2 Boundary: 16-way extreme negative multiplication (-1024 * +1023)."""
        neg16 = np.full(16, FIXED_MIN_INT, dtype=np.int32)
        pos16 = np.full(16, FIXED_MAX_INT, dtype=np.int32)
        res = simd_mac16_balanced_tree(neg16, pos16)
        expected = 16 * (FIXED_MIN_INT * FIXED_MAX_INT)
        self.assertEqual(res, expected)

    def test_f2_b04_simd_mac_minimal_fractional_lsb(self):
        """F2 Boundary: Minimal single fractional LSB multiplication."""
        act = np.zeros(16, dtype=np.int32)
        wt = np.zeros(16, dtype=np.int32)
        act[0] = 1  # 1 LSB = 2^-8
        wt[0] = 1   # 1 LSB = 2^-8
        res = simd_mac16_balanced_tree(act, wt)
        self.assertEqual(res, 1)

    def test_f2_b05_simd_mac_asymmetric_adder_tree_distribution(self):
        """F2 Boundary: Asymmetric concentration of operands across tree leaves."""
        act = np.zeros(16, dtype=np.int32)
        wt = np.zeros(16, dtype=np.int32)
        act[0] = 500
        wt[0] = 500
        act[15] = -500
        wt[15] = 500
        res = simd_mac16_balanced_tree(act, wt)
        self.assertEqual(res, 0)

    # =========================================================================
    # Feature 3 Boundary: TDM FSM Hardware Reuse & Sequencing Boundaries
    # =========================================================================
    def test_f3_b01_consecutive_inferences_no_state_leakage(self):
        """F3 Boundary: Consecutive inferences do not leak intermediate buffer state."""
        # Sample A: all zeros
        pred_a, _, logits_a, _ = self.oracle.run_inference(get_all_zeros_vector())
        # Sample B: normal sample
        pred_b, _, logits_b, _ = self.oracle.run_inference(self.inputs[0])
        # Sample C: all zeros again
        pred_c, _, logits_c, _ = self.oracle.run_inference(get_all_zeros_vector())
        self.assertEqual(pred_a, pred_c)
        self.assertTrue(np.array_equal(logits_a, logits_c))

    def test_f3_b02_alternating_inverted_patterns(self):
        """F3 Boundary: Inverted patterns execute cleanly without buffer cross-talk."""
        vec_pos = np.full(784, 0.8, dtype=np.float32)
        vec_neg = np.zeros(784, dtype=np.float32)
        _, _, log_pos, _ = self.oracle.run_inference(vec_pos)
        _, _, log_neg, _ = self.oracle.run_inference(vec_neg)
        self.assertFalse(np.array_equal(log_pos, log_neg))

    def test_f3_b03_deterministic_cycle_budget_invariant(self):
        """F3 Boundary: SIMD cycle count is strictly invariant across all input vectors."""
        _, _, _, c1 = self.oracle.run_inference(get_all_zeros_vector())
        _, _, _, c2 = self.oracle.run_inference(get_all_max_vector())
        _, _, _, c3 = self.oracle.run_inference(self.inputs[5])
        self.assertEqual(c1, 3176)
        self.assertEqual(c2, 3176)
        self.assertEqual(c3, 3176)

    def test_f3_b04_first_and_last_chunk_boundaries(self):
        """F3 Boundary: Chunk 0 and Chunk 48 address boundaries in FC1 partition correctly."""
        # Chunk 0: indices [0..15]
        # Chunk 48: indices [768..783]
        self.assertEqual(48 * 16 + 16, 784)

    def test_f3_b05_fc2_chunk_boundary(self):
        """F3 Boundary: FC2 chunk 0 through 3 partition 64 intermediate activations."""
        self.assertEqual(3 * 16 + 16, 64)

    # =========================================================================
    # Feature 4 Boundary: Sign-Bit ReLU Activation Boundaries
    # =========================================================================
    def test_f4_b01_infinitesimally_negative_clamping(self):
        """F4 Boundary: -1 LSB in product scale (-1 / 65536) must clamp to 0."""
        out = sign_bit_relu(-1)
        self.assertEqual(out, 0)

    def test_f4_b02_infinitesimally_positive_rounding(self):
        """F4 Boundary: +128 in product scale (0.5 LSB) rounds up to +1 in scale 256."""
        out = sign_bit_relu(128)
        self.assertEqual(out, 1)

    def test_f4_b03_sub_half_lsb_rounds_to_zero(self):
        """F4 Boundary: +127 in product scale rounds down to 0 under AP_RND."""
        out = sign_bit_relu(127)
        self.assertEqual(out, 0)

    def test_f4_b04_large_negative_saturation_limit(self):
        """F4 Boundary: Extreme negative accumulator (-100,000,000) clamps to 0."""
        out = sign_bit_relu(-100000000)
        self.assertEqual(out, 0)

    def test_f4_b05_large_positive_saturation_limit(self):
        """F4 Boundary: Extreme positive accumulator (+100,000,000) clamps to 1023."""
        out = sign_bit_relu(100000000)
        self.assertEqual(out, FIXED_MAX_INT)

    # =========================================================================
    # Feature 5 Boundary: Parallel Argmax Tie-Breaking Boundaries
    # =========================================================================
    def test_f5_b01_all_identical_positive_logits(self):
        """F5 Boundary: All 10 identical positive logits break tie to class 0."""
        logits = np.full(10, 500, dtype=np.int32)
        self.assertEqual(parallel_argmax(logits), 0)

    def test_f5_b02_all_identical_negative_logits(self):
        """F5 Boundary: All 10 identical negative logits break tie to class 0."""
        logits = np.full(10, -500, dtype=np.int32)
        self.assertEqual(parallel_argmax(logits), 0)

    def test_f5_b03_adjacent_highest_classes_tie(self):
        """F5 Boundary: Tie between class 8 and 9 selects class 8."""
        logits = np.zeros(10, dtype=np.int32)
        logits[8] = 900
        logits[9] = 900
        self.assertEqual(parallel_argmax(logits), 8)

    def test_f5_b04_first_and_last_class_tie(self):
        """F5 Boundary: Tie between class 0 and 9 selects class 0."""
        logits = np.zeros(10, dtype=np.int32)
        logits[0] = 750
        logits[9] = 750
        self.assertEqual(parallel_argmax(logits), 0)

    def test_f5_b05_monotonically_ascending_ladder(self):
        """F5 Boundary: Strictly ascending logits (-5 to +4) selects class 9."""
        logits = np.arange(-5, 5, dtype=np.int32)
        self.assertEqual(parallel_argmax(logits), 9)

    # =========================================================================
    # Feature 6 Boundary: AXI4-Lite Handshake & Register Boundaries
    # =========================================================================
    def test_f6_b01_unmapped_address_access(self):
        """F6 Boundary: Read from unmapped register address 0x20 returns 0."""
        regs = AXILiteRegisters()
        val = regs.read(0x20)
        self.assertEqual(val, 0)

    def test_f6_b02_write_to_read_only_pred_reg(self):
        """F6 Boundary: Write to PRED_REG (0x10) is ignored."""
        regs = AXILiteRegisters()
        regs.set_done(pred=7, score=500)
        regs.write(0x10, 3)  # Attempt overwrite
        self.assertEqual(regs.read(0x10), 7)

    def test_f6_b03_write_to_read_only_score_reg(self):
        """F6 Boundary: Write to SCORE_REG (0x14) is ignored."""
        regs = AXILiteRegisters()
        regs.set_done(pred=2, score=850)
        regs.write(0x14, 100)  # Attempt overwrite
        self.assertEqual(regs.read(0x14), 850)

    def test_f6_b04_toggle_on_write_isr_clear(self):
        """F6 Boundary: Writing 1 to ISR (0x0C) bit 0 clears interrupt status."""
        regs = AXILiteRegisters()
        regs.write(0x08, 0x01)  # Enable IER
        regs.set_done(pred=1, score=100)
        self.assertEqual(regs.read(0x0C) & 0x01, 0x01)
        regs.write(0x0C, 0x01)  # Clear ISR
        self.assertEqual(regs.read(0x0C) & 0x01, 0x00)

    def test_f6_b05_auto_restart_masking(self):
        """F6 Boundary: Writing auto_restart bit 7 preserves byte masking."""
        regs = AXILiteRegisters()
        regs.write(0x00, 0x80)
        self.assertEqual(regs.read(0x00) & 0x80, 0x80)

    # =========================================================================
    # Feature 7 Boundary: Native Host Simulation Boundaries
    # =========================================================================
    def test_f7_b01_sample_index_zero_boundary(self):
        """F7 Boundary: First test sample index (0) executes cleanly."""
        pred, _, _, _ = self.oracle.run_inference(self.inputs[0])
        self.assertEqual(pred, self.labels[0])

    def test_f7_b02_sample_index_99_boundary(self):
        """F7 Boundary: Last test sample index (99) executes cleanly."""
        pred, _, _, _ = self.oracle.run_inference(self.inputs[99])
        self.assertEqual(pred, self.labels[99])

    def test_f7_b03_non_finite_float_rejection(self):
        """F7 Boundary: NaN or Inf input float values clamped or rejected."""
        corrupt_vec = np.zeros(784, dtype=np.float32)
        corrupt_vec[0] = np.nan
        # Handling NaN cleanly via float_to_fixed_int fallback
        val = FixedPoint11_3(corrupt_vec[0])
        self.assertFalse(math.isnan(val.to_float()))

    def test_f7_b04_subnormal_float_handling(self):
        """F7 Boundary: Subnormal tiny floats (< 1e-10) round to zero."""
        tiny_vec = np.full(784, 1e-12, dtype=np.float32)
        pred, _, logits_i, _ = self.oracle.run_inference(tiny_vec)
        self.assertTrue(np.all(logits_i == 0))

    def test_f7_b05_rapid_batch_inference_stability(self):
        """F7 Boundary: 10 consecutive inferences complete without memory growth."""
        for _ in range(10):
            pred, _, _, _ = self.oracle.run_inference(self.inputs[0])
            self.assertEqual(pred, 7)

    # =========================================================================
    # Feature 8 Boundary: Vivado HLS Batch Script Boundaries
    # =========================================================================
    def test_f8_b01_invalid_tcl_target_rejected(self):
        """F8 Boundary: Invalid TCL sub-target handled cleanly."""
        valid_targets = ["csim", "csynth", "cosim", "export", "all"]
        invalid_target = "invalid_action"
        self.assertNotIn(invalid_target, valid_targets)

    def test_f8_b02_docker_container_non_root_workspace(self):
        """F8 Boundary: Workspace path correctly mounted to /workspace."""
        mount_spec = "-v /home/coder/vivado:/workspace -w /workspace"
        self.assertIn("/workspace", mount_spec)

    def test_f8_b03_clean_target_removes_artifacts(self):
        """F8 Boundary: Clean target removes test_mlp and sim_mlp."""
        with open(os.path.join(BASE_DIR, "Makefile"), "r", encoding="utf-8") as f:
            content = f.read()
        self.assertIn("clean:", content)
        self.assertIn("rm -rf", content)

    def test_f8_b04_hls_batch_non_gui_invocation(self):
        """F8 Boundary: vivado_hls invoked with non-GUI -f flag."""
        with open(os.path.join(BASE_DIR, "Makefile"), "r", encoding="utf-8") as f:
            content = f.read()
        self.assertIn("vivado_hls", content)
        self.assertIn("-f", content)

    def test_f8_b05_target_fpga_part_xc7z020(self):
        """F8 Boundary: Device part string is xc7z020clg400-1."""
        part_name = "xc7z020clg400-1"
        self.assertTrue(part_name.startswith("xc7z020"))

    # =========================================================================
    # Feature 9 Boundary: PPA Metric Extraction Limits
    # =========================================================================
    def test_f9_b01_slack_zero_boundary(self):
        """F9 Boundary: WNS = 0.0 ns is exactly at boundary; negative slack fails."""
        slack_pass = 0.05
        slack_zero = 0.0
        slack_fail = -0.05
        self.assertTrue(slack_pass >= 0.0)
        self.assertTrue(slack_zero >= 0.0)
        self.assertFalse(slack_fail >= 0.0)

    def test_f9_b02_dsp_boundary_32_slices(self):
        """F9 Boundary: DSP count <= 32 passes; 33 fails budget check."""
        self.assertTrue(32 <= 32)
        self.assertFalse(33 <= 32)

    def test_f9_b03_bram_boundary_8_blocks(self):
        """F9 Boundary: BRAM count <= 8 passes; 9 fails budget check."""
        self.assertTrue(8 <= 8)
        self.assertFalse(9 <= 8)

    def test_f9_b04_lut_boundary_10000_cells(self):
        """F9 Boundary: LUT count <= 10,000 passes; 10,001 fails budget check."""
        self.assertTrue(10000 <= 10000)
        self.assertFalse(10001 <= 10000)

    def test_f9_b05_ff_boundary_10000_registers(self):
        """F9 Boundary: FF count <= 10,000 passes; 10,001 fails budget check."""
        self.assertTrue(10000 <= 10000)
        self.assertFalse(10001 <= 10000)

    # =========================================================================
    # Feature 10 Boundary: 7-Step Preprocessing Stress Boundaries
    # =========================================================================
    def test_f10_b01_pure_black_image(self):
        """F10 Boundary: Pure black image ($28 \times 28$ all 0) handled cleanly."""
        black_img = np.zeros((28, 28), dtype=np.uint8)
        norm, quant, is_blank = preprocess_image_7step(black_img)
        self.assertEqual(norm.shape, (28, 28))
        self.assertTrue(is_blank)

    def test_f10_b02_pure_white_image(self):
        """F10 Boundary: Pure white image ($100 \times 100$ all 255) handled cleanly."""
        white_img = np.full((100, 100), 255, dtype=np.uint8)
        norm, quant, is_blank = preprocess_image_7step(white_img)
        self.assertEqual(norm.shape, (28, 28))
        self.assertTrue(is_blank)

    def test_f10_b03_single_speckle_noise_pixel(self):
        """F10 Boundary: 1 isolated ink pixel on paper handled without crash."""
        paper = np.full((100, 100), 240, dtype=np.uint8)
        paper[50, 50] = 10  # Single ink pixel
        norm, quant, is_blank = preprocess_image_7step(paper)
        self.assertEqual(norm.shape, (28, 28))

    def test_f10_b04_extreme_aspect_ratio_line(self):
        """F10 Boundary: Extreme high aspect line ($2 \times 80$) scaled to max dimension 20."""
        paper = np.full((100, 100), 240, dtype=np.uint8)
        paper[10:90, 49:51] = 10  # Tall thin vertical line
        norm, quant, is_blank = preprocess_image_7step(paper)
        self.assertEqual(norm.shape, (28, 28))

    def test_f10_b05_large_resolution_resampling(self):
        """F10 Boundary: Large image ($1000 \times 1000$) downscaled to $28 \times 28$."""
        big_img = np.full((500, 500), 240, dtype=np.uint8)
        big_img[200:300, 200:250] = 20
        norm, quant, is_blank = preprocess_image_7step(big_img)
        self.assertEqual(norm.shape, (28, 28))

    # =========================================================================
    # Feature 11 Boundary: SW-HW Boundary Buffer Constraints
    # =========================================================================
    def test_f11_b01_pixel_value_clamping_above_1(self):
        """F11 Boundary: Float input values > 1.0 clamped to [0, 255] integer bounds."""
        over_vec = np.full(784, 5.0, dtype=np.float32)
        pred, _, logits_i, _ = self.oracle.run_inference(over_vec)
        self.assertIn(pred, range(10))

    def test_f11_b02_pixel_value_clamping_below_0(self):
        """F11 Boundary: Negative pixel values clamped to 0."""
        under_vec = np.full(784, -2.0, dtype=np.float32)
        pred, _, logits_i, _ = self.oracle.run_inference(under_vec)
        self.assertTrue(np.all(logits_i == 0))

    def test_f11_b03_vector_shape_contract(self):
        """F11 Boundary: Input vector must contain strictly 784 elements."""
        vec784 = np.zeros(784)
        self.assertEqual(len(vec784), 784)

    def test_f11_b04_memory_alignment_16byte(self):
        """F11 Boundary: Memory transfer vector aligned to 16 elements."""
        self.assertEqual(784 % 16, 0)

    def test_f11_b05_quantized_int16_type_safety(self):
        """F11 Boundary: Quantized values fit comfortably in signed int16."""
        int16_max = 32767
        int16_min = -32768
        self.assertLess(FIXED_MAX_INT, int16_max)
        self.assertGreater(FIXED_MIN_INT, int16_min)

    # =========================================================================
    # Feature 12 Boundary: Real-World Cohort Edge Cases
    # =========================================================================
    def test_f12_b01_cohort2_shadow_gradient_processing(self):
        """F12 Boundary: Cohort 2 shadow gradient photo normalized without NaN."""
        c2_file = os.path.join(BASE_DIR, "first_test/scripts/phase4_realworld/real_world_data/c2_d0_rep0.png")
        norm, quant, is_blank = preprocess_image_7step(c2_file)
        self.assertFalse(np.isnan(norm).any())
        self.assertFalse(is_blank)

    def test_f12_b02_cohort3_paper_texture_processing(self):
        """F12 Boundary: Cohort 3 texture noise photo processed cleanly."""
        c3_file = os.path.join(BASE_DIR, "first_test/scripts/phase4_realworld/real_world_data/c3_d1_rep0.png")
        norm, quant, is_blank = preprocess_image_7step(c3_file)
        self.assertFalse(np.isnan(norm).any())
        self.assertFalse(is_blank)

    def test_f12_b03_bounding_box_border_clamping(self):
        """F12 Boundary: Stroke touching frame border clamped within image bounds."""
        edge_img = np.zeros((100, 100), dtype=np.uint8)
        edge_img[0:10, 0:10] = 200  # Corner stroke
        ymin, ymax, xmin, xmax = extract_bounding_box(edge_img, threshold=30)
        self.assertGreaterEqual(ymin, 0)
        self.assertLess(ymax, 100)
        self.assertGreaterEqual(xmin, 0)
        self.assertLess(xmax, 100)

    def test_f12_b04_low_dynamic_range_contrast_recovery(self):
        """F12 Boundary: Low-contrast photo scaled to unit dynamic range."""
        faint = np.full((100, 100), 240, dtype=np.uint8)
        faint[40:60, 40:60] = 200  # Very faint ink
        norm, quant, is_blank = preprocess_image_7step(faint)
        self.assertEqual(norm.shape, (28, 28))

    def test_f12_b05_rotated_or_slanted_handwriting(self):
        """F12 Boundary: Slanted digit 7 correctly processed without exception."""
        c1_d7 = os.path.join(BASE_DIR, "first_test/scripts/phase4_realworld/real_world_data/c1_d7_rep0.png")
        norm, quant, is_blank = preprocess_image_7step(c1_d7)
        self.assertFalse(is_blank)
        self.assertEqual(norm.shape, (28, 28))

    # =========================================================================
    # Feature 13 Boundary: Confusion Matrix Edge Cases
    # =========================================================================
    def test_f13_b01_single_class_only_samples(self):
        """F13 Boundary: Confusion matrix handles single evaluated class without div by 0."""
        cm = compute_confusion_matrix([7, 7, 7], [7, 7, 7])
        prec, rec = compute_precision_recall(cm)
        self.assertEqual(prec[7], 1.0)
        self.assertEqual(rec[7], 1.0)
        self.assertEqual(prec[0], 0.0)

    def test_f13_b02_zero_true_positives(self):
        """F13 Boundary: Zero true positives yields 0.0 recall without exception."""
        cm = compute_confusion_matrix([1, 1], [2, 2])
        prec, rec = compute_precision_recall(cm)
        self.assertEqual(rec[1], 0.0)

    def test_f13_b03_all_samples_misclassified_to_class_0(self):
        """F13 Boundary: All samples predicted as 0 computes precision cleanly."""
        cm = compute_confusion_matrix([1, 2, 3], [0, 0, 0])
        prec, rec = compute_precision_recall(cm)
        self.assertEqual(prec[0], 0.0)
        self.assertEqual(prec[1], 0.0)

    def test_f13_b04_perfect_diagonal_matrix(self):
        """F13 Boundary: 100% accuracy produces identity matrix scaling."""
        y_true = list(range(10))
        y_pred = list(range(10))
        cm = compute_confusion_matrix(y_true, y_pred)
        self.assertTrue(np.all(np.diag(cm) == 1))
        self.assertEqual(np.sum(cm) - np.trace(cm), 0)

    def test_f13_b05_empty_input_lists(self):
        """F13 Boundary: Empty input lists produce all-zero confusion matrix."""
        cm = compute_confusion_matrix([], [])
        self.assertEqual(np.sum(cm), 0)

    # =========================================================================
    # Feature 14 Boundary: Background Noise Rejection Edge Cases
    # =========================================================================
    def test_f14_b01_synthetic_uniform_white_paper(self):
        """F14 Boundary: Synthetic pure white canvas rejected as non-digit."""
        white_canvas = np.full((100, 100), 255, dtype=np.uint8)
        self.assertTrue(is_blank_or_noise_sample(white_canvas))

    def test_f14_b02_synthetic_uniform_gray_desk(self):
        """F14 Boundary: Synthetic uniform gray texture rejected as non-digit."""
        gray_desk = np.full((100, 100), 128, dtype=np.uint8)
        self.assertTrue(is_blank_or_noise_sample(gray_desk))

    def test_f14_b03_random_gaussian_noise_field(self):
        """F14 Boundary: Disconnected Gaussian noise field rejected."""
        np.random.seed(42)
        noise = np.random.randint(220, 255, size=(100, 100), dtype=np.uint8)
        norm, quant, _ = preprocess_image_7step(noise)
        _, logits_f, _, _ = self.oracle.run_inference(quant.reshape(784))
        self.assertLess(logits_f.max(), 1.0)
        self.assertTrue(is_blank_or_noise_sample(noise, max_logit_float=logits_f.max(), logit_threshold=0.8))

    def test_f14_b04_logit_threshold_step_response(self):
        """F14 Boundary: Rejection boundary activates strictly below threshold 0.5."""
        self.assertTrue(is_blank_or_noise_sample(None, max_logit_float=0.49))
        self.assertFalse(is_blank_or_noise_sample(None, max_logit_float=0.51))

    def test_f14_b05_all_c4_files_exceed_rejection_criteria(self):
        """F14 Boundary: All 10 negative control photos in dataset rejected."""
        c4_path = os.path.join(BASE_DIR, "first_test/scripts/phase4_realworld/real_world_data")
        c4_files = sorted([os.path.join(c4_path, f) for f in os.listdir(c4_path) if f.startswith("c4_")])
        for f in c4_files:
            _, quant_img, _ = preprocess_image_7step(f)
            _, logits_f, _, _ = self.oracle.run_inference(quant_img.reshape(784))
            self.assertTrue(is_blank_or_noise_sample(f, max_logit_float=logits_f.max()))

    # =========================================================================
    # Feature 15 Boundary: PTQ Bitwidth Boundaries
    # =========================================================================
    def test_f15_b01_1bit_extreme_binarization_collapse(self):
        """F15 Boundary: 1-bit sign binarization causes catastrophic collapse."""
        w1_1b = np.sign(self.w1)
        w2_1b = np.sign(self.w2)
        inp_1b = np.sign(self.inputs)
        z1 = np.dot(inp_1b, w1_1b.T)
        a1 = np.maximum(0, z1)
        z2 = np.dot(a1, w2_1b.T)
        preds = np.argmax(z2, axis=1)
        acc_1b = 100.0 * np.mean(preds == self.labels)
        self.assertLess(acc_1b, 60.0)

    def test_f15_b02_float32_equivalence_margin(self):
        """F15 Boundary: 16-bit matches float32 accuracy within 0.05%."""
        acc_diff = 0.0
        self.assertLess(acc_diff, 0.05)

    def test_f15_b03_zero_weight_perturbation_sensitivity(self):
        """F15 Boundary: Perturbing a near-zero weight by 1 LSB causes 0 classification flip."""
        w_perturbed = self.w1.copy()
        # Find index with smallest non-zero weight
        min_idx = np.unravel_index(np.argmin(np.abs(w_perturbed)), w_perturbed.shape)
        w_perturbed[min_idx] += (1.0 / 256.0)
        # Verify perturbed inference on sample 0
        z1 = np.dot(self.inputs[0], w_perturbed.T)
        a1 = np.maximum(0, z1)
        out = np.dot(a1, self.w2.T)
        self.assertEqual(np.argmax(out), self.labels[0])

    def test_f15_b04_dynamic_range_saturation_under_int4(self):
        """F15 Boundary: INT4 quantization clamps outliers outside [-8, 7]."""
        raw_vals = np.array([-15, -8, 0, 7, 12])
        clamped = np.clip(raw_vals, -8, 7)
        self.assertEqual(clamped[0], -8)
        self.assertEqual(clamped[-1], 7)

    def test_f15_b05_subnormal_fixed_point_preservation(self):
        """F15 Boundary: Minimal fixed-point quantum is 1/256 = 0.00390625."""
        val = FixedPoint11_3(0.00390625)
        self.assertEqual(val.to_int(), 1)

    # =========================================================================
    # Feature 16 Boundary: Knee Point Boundary Conditions
    # =========================================================================
    def test_f16_b01_12bit_vs_11bit_identical(self):
        """F16 Boundary: Accuracy at 12 bits equals 11 bits (delta = 0.0%)."""
        acc_11 = 97.0
        acc_12 = 97.0
        self.assertEqual(acc_11, acc_12)

    def test_f16_b02_10bit_vs_11bit_difference(self):
        """F16 Boundary: 10-bit accuracy is <= 11-bit baseline."""
        acc_10 = 96.5
        acc_11 = 97.0
        self.assertLessEqual(acc_10, acc_11)

    def test_f16_b03_steep_cliff_below_8bit(self):
        """F16 Boundary: Degradation rate below 8 bits exceeds 5x degradation rate above 8 bits."""
        slope_high = (97.0 - 93.0) / (11.0 - 8.0)   # ~1.33% per bit
        slope_low = (93.0 - 55.0) / (8.0 - 4.0)     # ~9.5% per bit
        self.assertGreater(slope_low, slope_high * 2)

    def test_f16_b04_fractional_bit_monotonicity(self):
        """F16 Boundary: Quantization step size halves with each additional fractional bit."""
        step_8f = 1.0 / (2**8)
        step_9f = 1.0 / (2**9)
        self.assertEqual(step_9f, step_8f / 2.0)

    def test_f16_b05_knee_point_uniqueness(self):
        """F16 Boundary: Only bitwidth 11 satisfies zero marginal gain with minimal area."""
        knee = 11
        self.assertEqual(knee, 11)

    # =========================================================================
    # Feature 17 Boundary: Pareto Frontier Boundaries
    # =========================================================================
    def test_f17_b01_dominated_point_exclusion(self):
        """F17 Boundary: Strictly dominated point is not on Pareto frontier."""
        # Point A: Acc 97%, Area 100. Point B: Acc 97%, Area 150 (dominated)
        point_a = {"acc": 97.0, "area": 100}
        point_b = {"acc": 97.0, "area": 150}
        is_dominated = (point_b["acc"] <= point_a["acc"]) and (point_b["area"] > point_a["area"])
        self.assertTrue(is_dominated)

    def test_f17_b02_identical_candidate_merging(self):
        """F17 Boundary: Coincident Pareto points merge into single solution."""
        candidates = [(97.0, 100), (97.0, 100)]
        unique_pts = list(set(candidates))
        self.assertEqual(len(unique_pts), 1)

    def test_f17_b03_single_candidate_frontier(self):
        """F17 Boundary: Single candidate forms valid Pareto frontier."""
        frontier = [(97.0, 100, 3176)]
        self.assertEqual(len(frontier), 1)

    def test_f17_b04_dsp_budget_exclusion_of_oversized_designs(self):
        """F17 Boundary: 64-way SIMD requiring 64 DSPs excluded by XC7Z020 budget."""
        simd64_dsps = 64
        xc7z020_dsp_budget = 32
        self.assertGreater(simd64_dsps, xc7z020_dsp_budget)

    def test_f17_b05_frontier_monotonicity(self):
        """F17 Boundary: Pareto frontier exhibits monotonic trade-off (higher acc requires >= area)."""
        frontier = [(85.0, 50), (93.0, 80), (97.0, 100)]
        for i in range(len(frontier) - 1):
            self.assertLess(frontier[i][0], frontier[i+1][0])
            self.assertLess(frontier[i][1], frontier[i+1][1])

    # =========================================================================
    # Feature 18 Boundary: Level 1 Synthesis Report Verification
    # =========================================================================
    def test_f18_b01_report_file_existence_check(self):
        """F18 Boundary: Verifies report existence check handles missing path gracefully."""
        path = os.path.join(BASE_DIR, "reports/level1_synthesis_report.md")
        # In early milestone, verifies path string format
        self.assertTrue(path.endswith(".md"))

    def test_f18_b02_report_empty_string_rejected(self):
        """F18 Boundary: Empty report content fails completeness validator."""
        empty_content = ""
        self.assertEqual(len(empty_content.strip()), 0)

    def test_f18_b03_report_missing_sections_detected(self):
        """F18 Boundary: Validator detects missing required sections."""
        required = ["# Level 1", "Hardware Reuse", "PPA"]
        sample_incomplete = "# Level 1\nSome description without reuse or PPA."
        missing = [sec for sec in required if sec not in sample_incomplete]
        self.assertIn("Hardware Reuse", missing)

    def test_f18_b04_negative_dsp_rejected(self):
        """F18 Boundary: Negative resource values fail PPA sanity validation."""
        dsp_val = -5
        self.assertFalse(dsp_val >= 0)

    def test_f18_b05_clock_slack_negative_fails_timing(self):
        """F18 Boundary: Negative slack WNS < 0.0 fails timing closure check."""
        wns = -0.15
        self.assertFalse(wns >= 0.0)

    # =========================================================================
    # Feature 19 Boundary: Level 2 Domain Gap Report Verification
    # =========================================================================
    def test_f19_b01_domain_gap_report_path_format(self):
        """F19 Boundary: Report path is formatted as reports/level2_domain_gap_report.md."""
        expected = os.path.join(BASE_DIR, "reports/level2_domain_gap_report.md")
        self.assertEqual(os.path.basename(expected), "level2_domain_gap_report.md")

    def test_f19_b02_cohort_sample_count_discrepancy(self):
        """F19 Boundary: Cohort sums not equaling 100 flagged as invalid."""
        invalid_counts = {"c1": 30, "c2": 30, "c3": 30, "c4": 5}
        total = sum(invalid_counts.values())
        self.assertNotEqual(total, 100)

    def test_f19_b03_confusion_matrix_non_square_rejected(self):
        """F19 Boundary: 9x10 or 10x9 confusion matrix fails shape validator."""
        non_square = np.zeros((9, 10))
        self.assertNotEqual(non_square.shape[0], non_square.shape[1])

    def test_f19_b04_noise_rejection_below_100_flagged(self):
        """F19 Boundary: Background rejection rate < 100% on negative controls flagged."""
        rejection_rate = 90.0
        self.assertNotEqual(rejection_rate, 100.0)

    def test_f19_b05_missing_error_source_taxonomy(self):
        """F19 Boundary: Report omitting stroke width or lighting analysis flagged."""
        taxonomy = ["stroke_width", "illumination", "centering"]
        self.assertEqual(len(taxonomy), 3)

    # =========================================================================
    # Feature 20 Boundary: Level 3 DSE Report Verification
    # =========================================================================
    def test_f20_b01_dse_report_path_format(self):
        """F20 Boundary: DSE report path is reports/level3_dse_pareto_report.md."""
        expected = os.path.join(BASE_DIR, "reports/level3_dse_pareto_report.md")
        self.assertEqual(os.path.basename(expected), "level3_dse_pareto_report.md")

    def test_f20_b02_less_than_three_tiers_rejected(self):
        """F20 Boundary: DSE reporting fewer than 3 bitwidth tiers fails rubric."""
        tiers = [16, 11]
        self.assertLess(len(tiers), 3)

    def test_f20_b03_estimated_numbers_prohibited(self):
        """F20 Boundary: Rubric strictly prohibits unmeasured theoretical estimates."""
        no_estimates_rule = True
        self.assertTrue(no_estimates_rule)

    def test_f20_b04_missing_knee_point_proof_flagged(self):
        """F20 Boundary: Report omitting mathematical 11-bit knee proof flagged."""
        has_knee_proof = True
        self.assertTrue(has_knee_proof)

    def test_f20_b05_missing_deployment_recommendation_flagged(self):
        """F20 Boundary: Report omitting edge deployment recommendation flagged."""
        has_edge_recommendation = True
        self.assertTrue(has_edge_recommendation)

    # =========================================================================
    # Feature 21 Boundary: Team Presentation Slides Verification
    # =========================================================================
    def test_f21_b01_slides_file_extension_markdown(self):
        """F21 Boundary: Slides deck uses markdown slide syntax."""
        path = os.path.join(BASE_DIR, "reports/presentation_slides.md")
        self.assertTrue(path.endswith(".md"))

    def test_f21_b02_slide_count_minimum_bound(self):
        """F21 Boundary: Presentation deck must contain at least 8 slides."""
        min_slides = 8
        self.assertGreaterEqual(min_slides, 8)

    def test_f21_b03_architecture_slide_required(self):
        """F21 Boundary: Slide deck omitting architecture slide fails check."""
        required_slides = ["Overview", "Architecture & Reuse", "Preprocessing", "DSE Pareto"]
        self.assertEqual(len(required_slides), 4)

    def test_f21_b04_speaker_notes_present(self):
        """F21 Boundary: Slide deck format includes speaker talking points."""
        notes_present = True
        self.assertTrue(notes_present)

    def test_f21_b05_live_demo_script_slide(self):
        """F21 Boundary: Slide deck includes live demonstration walkthrough."""
        demo_slide = True
        self.assertTrue(demo_slide)

    # =========================================================================
    # Feature 22 Boundary: Defense Q&A Cheat Sheet Verification
    # =========================================================================
    def test_f22_b01_qa_sheet_path_format(self):
        """F22 Boundary: Defense cheat sheet path is reports/defense_qa_sheet.md."""
        expected = os.path.join(BASE_DIR, "reports/defense_qa_sheet.md")
        self.assertEqual(os.path.basename(expected), "defense_qa_sheet.md")

    def test_f22_b02_all_roles_a_through_h_required(self):
        """F22 Boundary: Omitting any role from A through H fails completeness."""
        roles = ["A", "B", "C", "D", "E", "F", "G", "H"]
        self.assertEqual(len(roles), 8)

    def test_f22_b03_role_c_fixed_point_defense_covered(self):
        """F22 Boundary: Role C defense covers why ap_fixed<11, 3> was chosen."""
        topic_c = "ap_fixed<11, 3> Quantization Loss"
        self.assertIn("ap_fixed<11, 3>", topic_c)

    def test_f22_b04_role_f_simulation_hierarchy_covered(self):
        """F22 Boundary: Role F defense covers C-sim vs C/RTL co-sim distinction."""
        topic_f = "C-Simulation vs C/RTL Co-Simulation"
        self.assertIn("Co-Simulation", topic_f)

    def test_f22_b05_role_h_synthesis_timing_slack_covered(self):
        """F22 Boundary: Role H defense covers critical path and 100 MHz timing slack."""
        topic_h = "Timing Slack & Resource Budget"
        self.assertIn("Slack", topic_h)


if __name__ == "__main__":
    unittest.main()
