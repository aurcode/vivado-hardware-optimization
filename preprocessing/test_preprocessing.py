#!/usr/bin/env python3
"""
Unit and Integration Test Suite for Level 2 Preprocessing & Domain Gap Pipeline
"""

import os
import sys
import glob
import subprocess
import numpy as np
import pytest
from PIL import Image

repo_root = os.path.abspath(os.path.join(os.path.dirname(__file__), ".."))
if repo_root not in sys.path:
    sys.path.insert(0, repo_root)

from preprocessing.preprocess import (
    rgb_to_grayscale,
    invert_if_needed,
    otsu_threshold,
    apply_background_cutoff,
    extract_bounding_box,
    scale_aspect_preserving,
    compute_center_of_mass,
    align_center_of_mass,
    is_background_noise,
    preprocess_handwritten_image,
)
from preprocessing.evaluate_domain_gap import (
    load_hardware_weights,
    load_mnist_test_vectors,
    simulate_hardware_mlp,
    run_domain_gap_analysis,
)

DATA_DIR = "/home/coder/vivado/preprocessing/real_world_data"
WEIGHTS_PATH = "/home/coder/vivado/hw/weights.h"
TEST_INPUTS_PATH = "/home/coder/vivado/hw/test_inputs.h"
BOUNDED_CPP_PATH = "/home/coder/vivado/preprocessing/bounded_preproc.cpp"

def test_rgb_to_grayscale():
    # Test RGB image
    rgb_arr = np.zeros((32, 32, 3), dtype=np.uint8)
    rgb_arr[:, :, 0] = 255  # Pure red -> Luma = 0.299 * 255 = 76
    gray = rgb_to_grayscale(rgb_arr)
    assert gray.shape == (32, 32)
    assert abs(int(gray[0, 0]) - 76) <= 2

    # Test PIL Image
    pil_img = Image.new("RGB", (20, 20), color=(100, 150, 200))
    gray_pil = rgb_to_grayscale(pil_img)
    assert gray_pil.shape == (20, 20)

def test_polarity_inversion():
    # White paper (values ~250) with dark ink (values ~20)
    img = np.full((50, 50), 240, dtype=np.uint8)
    img[20:30, 20:30] = 30
    inv = invert_if_needed(img)
    # Background should now be dark (~15), ink stroke bright (~225)
    assert inv[0, 0] == 15
    assert inv[25, 25] == 225

    # Already dark background (MNIST style) should not be inverted
    dark_img = np.zeros((50, 50), dtype=np.uint8)
    dark_img[20:30, 20:30] = 200
    not_inv = invert_if_needed(dark_img)
    assert not_inv[0, 0] == 0
    assert not_inv[25, 25] == 200

def test_otsu_threshold():
    # Construct distinct bimodal distribution: modes at 40 and 200
    arr = np.zeros((100, 100), dtype=np.uint8)
    arr[:50, :] = 40
    arr[50:, :] = 200
    th = otsu_threshold(arr)
    # Optimal threshold must lie cleanly between 40 and 200
    assert 40 <= th < 200

def test_background_cutoff():
    arr = np.array([[10, 50, 80], [100, 150, 200]], dtype=np.uint8)
    otsu_th = 100
    # cutoff = 0.7 * 100 = 70. Values < 70 become 0, values >= 70 remain
    supp = apply_background_cutoff(arr, otsu_th, cutoff_factor=0.7)
    assert supp[0, 0] == 0   # 10 < 70 -> 0
    assert supp[0, 1] == 0   # 50 < 70 -> 0
    assert supp[0, 2] == 80  # 80 >= 70 -> 80
    assert supp[1, 0] == 100 # 100 >= 70 -> 100

def test_extract_bounding_box():
    arr = np.zeros((50, 60), dtype=np.uint8)
    arr[15:35, 20:45] = 100
    ymin, ymax, xmin, xmax = extract_bounding_box(arr, threshold=50)
    assert ymin == 15 and ymax == 34
    assert xmin == 20 and xmax == 44

def test_aspect_ratio_scaling():
    # Tall stroke (height 40, width 10)
    stroke = np.full((40, 10), 200, dtype=np.uint8)
    res = scale_aspect_preserving(stroke, target_box_size=20)
    # Height should scale to 20, width to round(10 * 20 / 40) = 5
    assert res.shape == (20, 5)

def test_center_of_mass_alignment():
    digit = np.zeros((10, 10), dtype=np.float32)
    digit[3:7, 3:7] = 200.0
    aligned = align_center_of_mass(digit, canvas_size=28)
    assert aligned.shape == (28, 28)
    cy, cx = compute_center_of_mass(aligned)
    # Center of mass should be aligned to ~14.0
    assert abs(cy - 14.0) < 1.0
    assert abs(cx - 14.0) < 1.0

def test_quantization_ap_fixed():
    f = os.path.join(DATA_DIR, "c1_d0_rep0.png")
    norm, quant = preprocess_handwritten_image(f, reject_blank=False)
    assert norm.shape == (28, 28)
    assert quant.shape == (28, 28)
    assert norm.min() >= 0.0
    assert norm.max() <= 1.0
    assert quant.min() >= 0
    assert quant.max() <= 256

def test_all_10_negative_controls_rejected():
    c4_files = sorted(glob.glob(os.path.join(DATA_DIR, "c4_*.png")))
    assert len(c4_files) == 10, f"Expected 10 negative controls, found {len(c4_files)}"
    for f in c4_files:
        norm, quant = preprocess_handwritten_image(f, reject_blank=True)
        assert norm is None and quant is None, f"Failed to reject negative control: {f}"

def test_all_90_active_digits_accepted():
    for c in ["c1", "c2", "c3"]:
        files = sorted(glob.glob(os.path.join(DATA_DIR, f"{c}_*.png")))
        assert len(files) == 30, f"Expected 30 files in {c}, found {len(files)}"
        for f in files:
            norm, quant = preprocess_handwritten_image(f, reject_blank=True)
            assert norm is not None and quant is not None, f"False rejection on active digit: {f}"
            assert norm.shape == (28, 28)

def test_hardware_weights_and_mnist_baseline():
    w1, w2 = load_hardware_weights(WEIGHTS_PATH)
    assert w1.shape == (64, 784)
    assert w2.shape == (10, 64)

    x_test, y_test = load_mnist_test_vectors(TEST_INPUTS_PATH)
    assert x_test.shape == (100, 784)
    assert y_test.shape == (100,)

    correct = 0
    for i in range(100):
        pred, _, _ = simulate_hardware_mlp(x_test[i], w1, w2)
        if pred == y_test[i]:
            correct += 1
    acc = correct / 100.0 * 100.0
    assert acc == 97.00, f"Expected 97.00% MNIST baseline accuracy, got {acc}%"

def test_bounded_cpp_model():
    out_bin = "/tmp/test_bounded_preproc_bin"
    inc_dir = "/home/coder/vivado/include_xilinx"
    compile_cmd = [
        "g++", "-O3", f"-I{inc_dir}", BOUNDED_CPP_PATH, "-o", out_bin
    ]
    res_comp = subprocess.run(compile_cmd, capture_output=True, text=True)
    assert res_comp.returncode == 0, f"C++ compilation failed: {res_comp.stderr}"

    res_exec = subprocess.run([out_bin], capture_output=True, text=True)
    assert res_exec.returncode == 0, f"Execution failed: {res_exec.stderr}"
    assert "ACCEPTED (PASS)" in res_exec.stdout
    assert "REJECTED (PASS: 100% Precision)" in res_exec.stdout
    if os.path.exists(out_bin):
        os.remove(out_bin)

def test_domain_gap_analysis_execution():
    res = run_domain_gap_analysis(data_dir=DATA_DIR, weights_path=WEIGHTS_PATH, test_inputs_path=TEST_INPUTS_PATH)
    assert res["mnist_acc"] == 97.00
    assert abs(res["active_accuracy"] - 84.44) < 0.01
    assert res["cohort_results"]["c1"]["accuracy"] == 90.00
    assert res["cohort_results"]["c2"]["accuracy"] == 80.00
    assert abs(res["cohort_results"]["c3"]["accuracy"] - 83.33) < 0.01
    assert res["cohort_results"]["c4"]["accuracy"] == 100.00
    assert len(res["metrics"]) == 10
