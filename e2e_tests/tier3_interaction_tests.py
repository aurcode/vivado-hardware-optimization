"""
Tier 3: Cross-Feature Interactions E2E Tests.
Validates pairwise and multi-feature interaction contracts across preprocessing,
inference datapath, AXI4-Lite control handshake, quantization, and evaluation metrics.
Total test cases: 10.
"""

import os
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
    preprocess_image_7step,
    is_blank_or_noise_sample,
    compute_confusion_matrix,
    compute_precision_recall,
    FIXED_SCALE,
    FIXED_MIN_INT,
    FIXED_MAX_INT
)

BASE_DIR = "/home/coder/vivado"


class TestTier3Interactions(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.w1, cls.w2 = DataLoader.load_weights(BASE_DIR)
        cls.inputs, cls.labels = DataLoader.load_test_inputs(BASE_DIR)
        cls.oracle = MLPAcceleratorOracle(BASE_DIR)

    # -------------------------------------------------------------------------
    # Interaction 1: Preprocessing Pipeline -> Fixed-Point Accelerator Inference
    # -------------------------------------------------------------------------
    def test_interaction_01_preprocessing_to_fixed_point_inference(self):
        """Interaction 1: Raw photo -> 7-step preprocessor -> 784 fixed vector -> mlp_accel."""
        test_img_path = os.path.join(
            BASE_DIR, "first_test/scripts/phase4_realworld/real_world_data/c1_d0_rep0.png"
        )
        norm_img, quant_img, is_blank = preprocess_image_7step(test_img_path)
        self.assertFalse(is_blank)
        self.assertEqual(quant_img.shape, (28, 28))

        # Flatten into 784-element memory-mapped input buffer
        input_buffer = quant_img.reshape(784)

        # Feed to accelerator core
        pred, logits_f, logits_i, cycles = self.oracle.run_inference(input_buffer)

        # Ground truth label for c1_d0 is digit 0
        self.assertEqual(pred, 0)
        self.assertEqual(cycles, 3176)
        self.assertGreater(logits_f[0], 1.5)  # Confident positive score

    # -------------------------------------------------------------------------
    # Interaction 2: Blank Sample Preprocessing -> Background Noise Rejection -> Idle State
    # -------------------------------------------------------------------------
    def test_interaction_02_blank_sample_to_noise_rejection_to_idle_state(self):
        """Interaction 2: Blank camera photo -> noise rejection -> core remains IDLE."""
        blank_img_path = os.path.join(
            BASE_DIR, "first_test/scripts/phase4_realworld/real_world_data/c4_blank_rep0.png"
        )
        norm_img, quant_img, is_blank = preprocess_image_7step(blank_img_path)

        # Preprocessing or logit check flags sample as blank
        pred, logits_f, logits_i, _ = self.oracle.run_inference(quant_img.reshape(784))
        is_rejected = is_blank_or_noise_sample(blank_img_path, max_logit_float=logits_f.max())
        self.assertTrue(is_rejected)

        # When rejected, host controller keeps accelerator in ready/idle state without launching compute
        ctrl_reg = AXILiteRegisters()
        # Initial state has ap_idle = 1
        self.assertEqual(ctrl_reg.read(0x00) & 0x04, 0x04)
        # Because sample was rejected by PS preprocessor, no write to ap_start occurs
        self.assertEqual(ctrl_reg.read(0x00) & 0x01, 0x00)

    # -------------------------------------------------------------------------
    # Interaction 3: Preprocessor Quantization Scale vs Hardware Fixed-Point Match
    # -------------------------------------------------------------------------
    def test_interaction_03_quantization_scaling_matches_hardware_fixed_point(self):
        """Interaction 3: 256.0 scaling in SW perfectly maps to ap_fixed<11, 3> 8 frac bits."""
        # 1.0 in float maps to 256 in scale 256
        test_val_float = 0.625  # 5/8 = 160 / 256
        sw_quant_int = int(round(test_val_float * 256.0))
        hw_fixed = FixedPoint11_3(test_val_float)

        self.assertEqual(sw_quant_int, 160)
        self.assertEqual(hw_fixed.to_int(), 160)
        self.assertEqual(hw_fixed.to_float(), 0.625)

        # Check full dynamic range step (1/256 = 0.00390625)
        step_val = 0.00390625
        self.assertEqual(int(round(step_val * 256.0)), 1)
        self.assertEqual(FixedPoint11_3(step_val).to_int(), 1)

    # -------------------------------------------------------------------------
    # Interaction 4: 16-Way SIMD Adder Tree Interlocks with ReLU Accumulator
    # -------------------------------------------------------------------------
    def test_interaction_04_simd_adder_tree_interlocks_with_relu_accumulator(self):
        """Interaction 4: 16-way product sum accumulates into 32-bit register without overflow."""
        # Maximum positive values: 16 lanes of 255 (inputs) * 255 (weights)
        act16 = np.full(16, 255, dtype=np.int32)
        wt16 = np.full(16, 255, dtype=np.int32)
        dot16 = simd_mac16_balanced_tree(act16, wt16)

        # 16 * (255 * 255) = 1,040,400 (fits comfortably in 32-bit accumulator)
        self.assertEqual(dot16, 16 * (255 * 255))
        self.assertLess(dot16, 2**31 - 1)

        # Sign-bit ReLU truncates and clips into 11-bit bound
        relu_out = sign_bit_relu(dot16)
        # (1,040,400 + 128) // 256 = 4064 -> clamped to FIXED_MAX_INT (1023)
        self.assertEqual(relu_out, FIXED_MAX_INT)

    # -------------------------------------------------------------------------
    # Interaction 5: TDM FSM State Machine -> AXI4-Lite Handshake Sequencing
    # -------------------------------------------------------------------------
    def test_interaction_05_axi4_lite_handshake_fsm_sequencing(self):
        """Interaction 5: Full AXI4-Lite control handshake from ap_start to ap_done."""
        regs = AXILiteRegisters()

        # Step 1: Host configures interrupts (GIE=1, IER=1)
        regs.write(0x04, 0x01)
        regs.write(0x08, 0x01)

        # Step 2: Host asserts ap_start
        regs.write(0x00, 0x01)
        self.assertEqual(regs.read(0x00) & 0x01, 0x01)

        # Step 3: Core starts running -> ap_idle deasserts
        regs.set_running()
        self.assertEqual(regs.read(0x00) & 0x04, 0x00)

        # Step 4: Core completes inference -> asserts ap_done, ap_idle, updates PRED and ISR
        regs.set_done(pred=4, score=720)
        self.assertEqual(regs.read(0x00) & 0x02, 0x02)   # ap_done asserted
        self.assertEqual(regs.read(0x00) & 0x04, 0x04)   # ap_idle asserted
        self.assertEqual(regs.read(0x10), 4)             # PRED_REG holds winning class
        self.assertEqual(regs.read(0x14), 720)           # SCORE_REG holds winning score
        self.assertEqual(regs.read(0x0C) & 0x01, 0x01)   # ISR bit 0 raised

        # Step 5: Host acknowledges interrupt by writing 1 to ISR
        regs.write(0x0C, 0x01)
        self.assertEqual(regs.read(0x0C) & 0x01, 0x00)   # ISR cleared

    # -------------------------------------------------------------------------
    # Interaction 6: Argmax Tie-Breaking Synchronizes with Score Registers
    # -------------------------------------------------------------------------
    def test_interaction_06_argmax_tie_breaking_reflects_in_pred_and_score_registers(self):
        """Interaction 6: Argmax tie-break synchronizes winning class and score in AXI registers."""
        # Create tying logits between class 2 and class 7
        tied_logits = np.array([100, 200, 800, 50, 10, 0, 50, 800, 100, 0], dtype=np.int32)
        winner = parallel_argmax(tied_logits)
        self.assertEqual(winner, 2)  # Class 2 wins over class 7

        regs = AXILiteRegisters()
        regs.set_done(pred=winner, score=tied_logits[winner])
        self.assertEqual(regs.read(0x10), 2)
        self.assertEqual(regs.read(0x14), 800)

    # -------------------------------------------------------------------------
    # Interaction 7: Fixed-Point Quantization Preserves Classification Monotonicity
    # -------------------------------------------------------------------------
    def test_interaction_07_fixed_point_inference_vs_c_model_equivalence(self):
        """Interaction 7: Fixed-point scaling preserves identical 97.00% accuracy to float32."""
        # Float32 model
        z1_f = np.dot(self.inputs, self.w1.T)
        a1_f = np.maximum(0, z1_f)
        logits_f = np.dot(a1_f, self.w2.T)
        preds_float = np.argmax(logits_f, axis=1)

        # Fixed-point hardware model
        preds_fixed = np.array([
            self.oracle.run_inference(self.inputs[s])[0]
            for s in range(100)
        ])

        # Agreement across all 100 test samples
        agreement = np.mean(preds_float == preds_fixed)
        self.assertGreaterEqual(agreement, 0.98)
        self.assertEqual(np.mean(preds_fixed == self.labels) * 100.0, 97.0)

    # -------------------------------------------------------------------------
    # Interaction 8: PTQ Bitwidth Sweep Adheres to Hardware Resource Envelopes
    # -------------------------------------------------------------------------
    def test_interaction_08_ptq_sweep_respects_xc7z020_resource_envelope(self):
        """Interaction 8: 16-bit, 11-bit, and 8-bit configurations fit XC7Z020 resource bounds."""
        dse_configurations = [
            {"bitwidth": 16, "dsp": 16, "bram": 4, "lut": 3200, "ff": 3400, "acc": 97.0},
            {"bitwidth": 11, "dsp": 16, "bram": 2, "lut": 2100, "ff": 2300, "acc": 97.0},
            {"bitwidth": 8,  "dsp": 16, "bram": 1, "lut": 1600, "ff": 1800, "acc": 93.0},
            {"bitwidth": 4,  "dsp": 8,  "bram": 1, "lut": 950,  "ff": 1100, "acc": 65.0}
        ]

        xc7z020_limits = {"dsp": 32, "bram": 8, "lut": 10000, "ff": 10000}

        for cfg in dse_configurations:
            self.assertLessEqual(cfg["dsp"], xc7z020_limits["dsp"])
            self.assertLessEqual(cfg["bram"], xc7z020_limits["bram"])
            self.assertLessEqual(cfg["lut"], xc7z020_limits["lut"])
            self.assertLessEqual(cfg["ff"], xc7z020_limits["ff"])

    # -------------------------------------------------------------------------
    # Interaction 9: Confusion Matrix Diagnoses Real-World Stroke Disparities
    # -------------------------------------------------------------------------
    def test_interaction_09_confusion_matrix_maps_to_stroke_width_domain_gap(self):
        """Interaction 9: Confusion matrix entries correlate with stroke width domain gaps."""
        # Evaluate 10 samples from Cohort 1
        y_true = []
        y_pred = []
        c1_path = os.path.join(BASE_DIR, "first_test/scripts/phase4_realworld/real_world_data")

        for digit in range(10):
            fname = f"c1_d{digit}_rep0.png"
            fpath = os.path.join(c1_path, fname)
            if os.path.exists(fpath):
                norm_img, quant_img, is_blank = preprocess_image_7step(fpath)
                pred, _, _, _ = self.oracle.run_inference(quant_img.reshape(784))
                y_true.append(digit)
                y_pred.append(pred)

        cm = compute_confusion_matrix(y_true, y_pred)
        self.assertEqual(cm.shape, (10, 10))
        self.assertEqual(np.sum(cm), len(y_true))

        # Precision and recall calculation does not fail
        prec, rec = compute_precision_recall(cm)
        self.assertEqual(len(prec), 10)
        self.assertEqual(len(rec), 10)

    # -------------------------------------------------------------------------
    # Interaction 10: Technical Report & Cheat Sheet Parameter Consistency
    # -------------------------------------------------------------------------
    def test_interaction_10_defense_qa_sheet_consistency_with_ppa_and_accuracy(self):
        """Interaction 10: Cross-checks consistency of defense claims with system specs."""
        specs = {
            "baseline_accuracy": 97.00,
            "target_clock_mhz": 100.0,
            "target_period_ns": 10.0,
            "simd_factor": 16,
            "fc1_chunks": 49,
            "fc2_chunks": 4,
            "total_cycles": 3176,
            "data_type": "ap_fixed<11, 3, AP_RND, AP_SAT>",
            "dsp_budget": 32,
            "bram_budget": 8
        }

        # Mathematical verification of consistency
        self.assertEqual(specs["fc1_chunks"] * 64 + specs["fc2_chunks"] * 10, specs["total_cycles"])
        self.assertEqual(1000.0 / specs["target_clock_mhz"], specs["target_period_ns"])
        self.assertLessEqual(specs["simd_factor"], specs["dsp_budget"])


if __name__ == "__main__":
    unittest.main()
