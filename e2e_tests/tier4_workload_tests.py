"""
Tier 4: Real-World Workload Scenarios E2E Tests.
Validates end-to-end photo recognition through preprocessing and 784-64-10 inference
across clean, shadow, and noise cohorts, background rejection verification, and streaming workloads.
Total test cases: 6 comprehensive scenarios.
"""

import os
import unittest
import numpy as np
from PIL import Image

from e2e_tests.oracle import (
    DataLoader,
    MLPAcceleratorOracle,
    preprocess_image_7step,
    is_blank_or_noise_sample,
    compute_confusion_matrix,
    compute_precision_recall
)

BASE_DIR = "/home/coder/vivado"
DATA_DIR = os.path.join(BASE_DIR, "first_test/scripts/phase4_realworld/real_world_data")


class TestTier4Workloads(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.w1, cls.w2 = DataLoader.load_weights(BASE_DIR)
        cls.inputs, cls.labels = DataLoader.load_test_inputs(BASE_DIR)
        cls.oracle = MLPAcceleratorOracle(BASE_DIR)

    # -------------------------------------------------------------------------
    # Workload 1: Cohort 1 Clean Real Handwriting Photo Recognition
    # -------------------------------------------------------------------------
    def test_workload_01_cohort1_clean_photo_recognition(self):
        """Workload 1: Full evaluation of 30 clean handwriting photos in Cohort 1."""
        c1_files = sorted([
            os.path.join(DATA_DIR, f) for f in os.listdir(DATA_DIR)
            if f.startswith("c1_d") and f.endswith(".png")
        ])
        self.assertEqual(len(c1_files), 30, f"Expected 30 Cohort 1 files, found {len(c1_files)}")

        correct = 0
        confidences = []

        for fpath in c1_files:
            fname = os.path.basename(fpath)
            true_digit = int(fname.split("_d")[1].split("_")[0])

            norm_img, quant_img, is_blank = preprocess_image_7step(fpath)
            self.assertFalse(is_blank, f"Valid clean digit {fname} was falsely marked blank")

            pred, logits_f, logits_i, cycles = self.oracle.run_inference(quant_img.reshape(784))
            conf = float(logits_f.max())
            confidences.append(conf)

            if pred == true_digit:
                correct += 1

        accuracy = 100.0 * correct / len(c1_files)
        mean_conf = np.mean(confidences)

        # Baseline expected accuracy on clean handwriting photos >= 80% (typically ~86.67%)
        self.assertGreaterEqual(accuracy, 80.0)
        self.assertGreater(mean_conf, 1.5)

    # -------------------------------------------------------------------------
    # Workload 2: Cohort 2 Lighting & Shadow Gradient Robustness
    # -------------------------------------------------------------------------
    def test_workload_02_cohort2_lighting_and_shadow_robustness(self):
        """Workload 2: Full evaluation of 30 lighting gradient & shadow photos in Cohort 2."""
        c2_files = sorted([
            os.path.join(DATA_DIR, f) for f in os.listdir(DATA_DIR)
            if f.startswith("c2_d") and f.endswith(".png")
        ])
        self.assertEqual(len(c2_files), 30, f"Expected 30 Cohort 2 files, found {len(c2_files)}")

        correct = 0
        processed_count = 0

        for fpath in c2_files:
            fname = os.path.basename(fpath)
            true_digit = int(fname.split("_d")[1].split("_")[0])

            norm_img, quant_img, is_blank = preprocess_image_7step(fpath)
            if not is_blank:
                processed_count += 1
                pred, logits_f, logits_i, _ = self.oracle.run_inference(quant_img.reshape(784))
                if pred == true_digit:
                    correct += 1

        # Shadows degrade recognition, but Otsu should segment > 90% of samples
        self.assertGreaterEqual(processed_count, 27)
        accuracy = 100.0 * correct / len(c2_files)
        # Expect at least 60% accuracy under shadows
        self.assertGreaterEqual(accuracy, 60.0)

    # -------------------------------------------------------------------------
    # Workload 3: Cohort 3 Paper Noise & Texture Suppression
    # -------------------------------------------------------------------------
    def test_workload_03_cohort3_paper_texture_and_noise_suppression(self):
        """Workload 3: Full evaluation of 30 paper noise and texture photos in Cohort 3."""
        c3_files = sorted([
            os.path.join(DATA_DIR, f) for f in os.listdir(DATA_DIR)
            if f.startswith("c3_d") and f.endswith(".png")
        ])
        self.assertEqual(len(c3_files), 30, f"Expected 30 Cohort 3 files, found {len(c3_files)}")

        correct = 0
        processed_count = 0

        for fpath in c3_files:
            fname = os.path.basename(fpath)
            true_digit = int(fname.split("_d")[1].split("_")[0])

            norm_img, quant_img, is_blank = preprocess_image_7step(fpath)
            if not is_blank:
                processed_count += 1
                pred, logits_f, logits_i, _ = self.oracle.run_inference(quant_img.reshape(784))
                if pred == true_digit:
                    correct += 1

        self.assertGreaterEqual(processed_count, 27)
        accuracy = 100.0 * correct / len(c3_files)
        self.assertGreaterEqual(accuracy, 50.0)

    # -------------------------------------------------------------------------
    # Workload 4: Cohort 4 Negative Control Background Noise Rejection
    # -------------------------------------------------------------------------
    def test_workload_04_cohort4_negative_control_background_rejection(self):
        """Workload 4: Full evaluation of 10 non-digit blank/scratch photos in Cohort 4."""
        c4_files = sorted([
            os.path.join(DATA_DIR, f) for f in os.listdir(DATA_DIR)
            if f.startswith("c4_blank") and f.endswith(".png")
        ])
        self.assertEqual(len(c4_files), 10, f"Expected 10 Cohort 4 files, found {len(c4_files)}")

        rejected_count = 0
        max_confidences = []

        for fpath in c4_files:
            norm_img, quant_img, is_blank = preprocess_image_7step(fpath)
            pred, logits_f, logits_i, _ = self.oracle.run_inference(quant_img.reshape(784))
            conf = float(logits_f.max())
            max_confidences.append(conf)

            # Rejection rule: low energy or max logit < 0.5
            if is_blank_or_noise_sample(fpath, max_logit_float=conf, logit_threshold=0.5):
                rejected_count += 1

        rejection_rate = 100.0 * rejected_count / len(c4_files)

        # Requirement: 100% precision on blank/scratch negative controls
        self.assertEqual(rejection_rate, 100.0)
        self.assertEqual(rejected_count, 10)
        # All blank samples should have very low confidence (< 0.3)
        self.assertLess(max(max_confidences), 0.3)

    # -------------------------------------------------------------------------
    # Workload 5: End-to-End 100-Photo Benchmark & Confusion Matrix
    # -------------------------------------------------------------------------
    def test_workload_05_end_to_end_100_photo_benchmark_and_confusion_matrix(self):
        """Workload 5: Comprehensive 100-photo benchmark, confusion matrix, and domain gap."""
        all_files = sorted([
            os.path.join(DATA_DIR, f) for f in os.listdir(DATA_DIR)
            if f.endswith(".png")
        ])
        self.assertEqual(len(all_files), 100, f"Expected exactly 100 photo files, found {len(all_files)}")

        y_true = []
        y_pred = []
        negative_controls_rejected = 0

        for fpath in all_files:
            fname = os.path.basename(fpath)
            if fname.startswith("c4_"):
                # Negative control
                norm_img, quant_img, is_blank = preprocess_image_7step(fpath)
                _, logits_f, _, _ = self.oracle.run_inference(quant_img.reshape(784))
                if is_blank_or_noise_sample(fpath, max_logit_float=logits_f.max(), logit_threshold=0.5):
                    negative_controls_rejected += 1
            else:
                # Digit sample (c1, c2, c3)
                true_digit = int(fname.split("_d")[1].split("_")[0])
                norm_img, quant_img, is_blank = preprocess_image_7step(fpath)
                pred, logits_f, _, _ = self.oracle.run_inference(quant_img.reshape(784))
                y_true.append(true_digit)
                y_pred.append(pred)

        self.assertEqual(len(y_true), 90)
        self.assertEqual(negative_controls_rejected, 10)

        # Construct 10x10 confusion matrix
        cm = compute_confusion_matrix(y_true, y_pred, num_classes=10)
        self.assertEqual(cm.shape, (10, 10))
        self.assertEqual(np.sum(cm), 90)

        # Compute per-class precision and recall
        precision, recall = compute_precision_recall(cm)
        self.assertEqual(len(precision), 10)
        self.assertEqual(len(recall), 10)

        overall_acc = 100.0 * np.sum(np.diag(cm)) / len(y_true)
        # Real-world accuracy across all 90 digits should exceed 65%
        self.assertGreaterEqual(overall_acc, 65.0)

        # Domain gap degradation vs standard MNIST (97.00%)
        domain_gap = 97.00 - overall_acc
        self.assertGreater(domain_gap, 0.0)  # Measurable domain shift

    # -------------------------------------------------------------------------
    # Workload 6: Continuous Streaming Mixed-Cohort Workload
    # -------------------------------------------------------------------------
    def test_workload_06_continuous_streaming_mixed_cohort_workload(self):
        """Workload 6: Continuous interleaved streaming across MNIST, photos, and blank controls."""
        # Stream 15 alternating samples: MNIST -> C1 photo -> C4 blank -> repeat
        stream_results = []

        for i in range(5):
            # 1. Standard MNIST vector
            mnist_inp = self.inputs[i]
            mnist_lbl = self.labels[i]
            pred_m, _, _, _ = self.oracle.run_inference(mnist_inp)
            stream_results.append(("mnist", pred_m == mnist_lbl))

            # 2. Real-world C1 photo
            c1_file = os.path.join(DATA_DIR, f"c1_d{i}_rep0.png")
            _, quant_img, _ = preprocess_image_7step(c1_file)
            pred_c, _, _, _ = self.oracle.run_inference(quant_img.reshape(784))
            stream_results.append(("c1", pred_c == i))

            # 3. Blank control
            c4_file = os.path.join(DATA_DIR, f"c4_blank_rep{i}.png")
            _, q_blank, _ = preprocess_image_7step(c4_file)
            _, l_blank, _, _ = self.oracle.run_inference(q_blank.reshape(784))
            rej = is_blank_or_noise_sample(c4_file, max_logit_float=l_blank.max(), logit_threshold=0.5)
            stream_results.append(("c4_blank", rej))

        self.assertEqual(len(stream_results), 15)
        # All 5 blank controls in stream must be rejected
        blank_checks = [res[1] for res in stream_results if res[0] == "c4_blank"]
        self.assertTrue(all(blank_checks))


if __name__ == "__main__":
    unittest.main()
