#!/usr/bin/env python3
"""
Phase 4: Real-World Handwritten Image Preprocessing Pipeline
Strictly adheres to MNIST normalization standards (LeCun et al.):
1. Luminance conversion (RGB -> Grayscale)
2. Background Inversion (Black ink on white paper -> White digit on black background)
3. Noise filtration & Otsu thresholding
4. Bounding box ROI cropping
5. Aspect-ratio preserving scaling into a 20x20 bounding box
6. Center-of-Mass (CoM) alignment into a 28x28 canvas
7. Fixed-point integer quantization matching hardware data_t (scale: 2^10 = 1024)
"""

import numpy as np
from PIL import Image, ImageOps, ImageFilter

def rgb_to_grayscale(img: Image.Image) -> Image.Image:
    """Converts RGB image to grayscale using ITU-R 601-2 luma transform."""
    if img.mode != 'L':
        return img.convert('L')
    return img

def invert_if_needed(gray_arr: np.ndarray, bg_threshold: float = 127.0) -> np.ndarray:
    """
    Ensures digit is foreground (bright) and background is dark.
    If four image corners are bright, the background is paper, so we invert.
    """
    h, w = gray_arr.shape
    corner_pixels = [
        gray_arr[0:5, 0:5],
        gray_arr[0:5, w-5:w],
        gray_arr[h-5:h, 0:5],
        gray_arr[h-5:h, w-5:w]
    ]
    mean_corner = np.mean([np.mean(c) for c in corner_pixels])
    if mean_corner > bg_threshold:
        return 255 - gray_arr
    return gray_arr

def otsu_threshold(gray_arr: np.ndarray) -> int:
    """Computes optimal global threshold using Otsu's bimodal histogram method."""
    hist, _ = np.histogram(gray_arr, bins=256, range=(0, 256))
    total = gray_arr.size
    current_max = 0
    threshold = 0
    sum_total = np.dot(np.arange(256), hist)
    sum_bg = 0
    weight_bg = 0

    for t in range(256):
        weight_bg += hist[t]
        if weight_bg == 0:
            continue
        weight_fg = total - weight_bg
        if weight_fg == 0:
            break
        sum_bg += t * hist[t]
        mean_bg = sum_bg / weight_bg
        mean_fg = (sum_total - sum_bg) / weight_fg
        between_class_var = weight_bg * weight_fg * ((mean_bg - mean_fg) ** 2)
        if between_class_var > current_max:
            current_max = between_class_var
            threshold = t

    return threshold

def extract_bounding_box(arr: np.ndarray, threshold: int = 30):
    """Finds bounding box [ymin, ymax, xmin, xmax] of active digit strokes."""
    mask = arr > threshold
    if not np.any(mask):
        return 0, arr.shape[0], 0, arr.shape[1]
    rows = np.any(mask, axis=1)
    cols = np.any(mask, axis=0)
    ymin, ymax = np.where(rows)[0][[0, -1]]
    xmin, xmax = np.where(cols)[0][[0, -1]]
    return ymin, ymax, xmin, xmax

def compute_center_of_mass(arr: np.ndarray):
    """Calculates intensity-weighted center of mass (cy, cx)."""
    total_mass = np.sum(arr)
    if total_mass == 0:
        return arr.shape[0] / 2.0, arr.shape[1] / 2.0
    y_coords, x_coords = np.indices(arr.shape)
    cy = np.sum(y_coords * arr) / total_mass
    cx = np.sum(x_coords * arr) / total_mass
    return cy, cx

def preprocess_handwritten_image(img_input, target_box_size=20, canvas_size=28):
    """
    Executes the complete end-to-end preprocessing pipeline.
    Returns:
    - canvas_normalized: float array in [0.0, 1.0]
    - canvas_fixed: int16 array in [0, 1024] (ready for mlp_accel hardware)
    """
    if isinstance(img_input, str):
        pil_img = Image.open(img_input)
    elif isinstance(img_input, Image.Image):
        pil_img = img_input
    elif isinstance(img_input, np.ndarray):
        pil_img = Image.fromarray(img_input)
    else:
        raise TypeError("Unsupported image input type")

    # Step 1: Grayscale conversion
    gray_img = rgb_to_grayscale(pil_img)
    gray_arr = np.array(gray_img, dtype=np.uint8)

    # Step 2: Inversion (Black digit on white paper -> White on Black)
    inverted_arr = invert_if_needed(gray_arr)

    # Step 3: Contrast enhancement & background noise suppression
    otsu_th = otsu_threshold(inverted_arr)
    suppressed = np.where(inverted_arr < otsu_th * 0.7, 0, inverted_arr).astype(np.uint8)

    # Step 4: Extract digit ROI bounding box
    ymin, ymax, xmin, xmax = extract_bounding_box(suppressed, threshold=int(otsu_th * 0.5))
    cropped = suppressed[ymin:ymax+1, xmin:xmax+1]

    # Step 5: Fit into 20x20 box preserving aspect ratio
    crop_h, crop_w = cropped.shape
    if crop_h > 0 and crop_w > 0:
        scale = float(target_box_size) / max(crop_h, crop_w)
        new_w = max(1, int(round(crop_w * scale)))
        new_h = max(1, int(round(crop_h * scale)))
        cropped_pil = Image.fromarray(cropped).resize((new_w, new_h), Image.Resampling.BICUBIC)
        resized_arr = np.array(cropped_pil, dtype=np.float32)
    else:
        resized_arr = np.zeros((target_box_size, target_box_size), dtype=np.float32)

    # Step 6: Center-of-Mass alignment onto 28x28 canvas
    canvas = np.zeros((canvas_size, canvas_size), dtype=np.float32)
    r_h, r_w = resized_arr.shape
    # Place roughly at center
    start_y = (canvas_size - r_h) // 2
    start_x = (canvas_size - r_w) // 2
    canvas[start_y:start_y + r_h, start_x:start_x + r_w] = resized_arr

    # Fine-tune translation by Center-of-Mass
    cy, cx = compute_center_of_mass(canvas)
    shift_y = int(round(canvas_size / 2.0 - cy))
    shift_x = int(round(canvas_size / 2.0 - cx))
    shifted_canvas = np.roll(canvas, shift_y, axis=0)
    shifted_canvas = np.roll(shifted_canvas, shift_x, axis=1)

    # Step 7: Dynamic Range normalization and fixed-point quantization
    max_val = np.max(shifted_canvas)
    if max_val > 0:
        norm_canvas = shifted_canvas / 255.0
    else:
        norm_canvas = shifted_canvas

    # Quantize to scale 2^10 = 1024 (ap_fixed<16, 6> equivalent in int16_t)
    fixed_canvas = np.clip(np.round(norm_canvas * 1024.0), 0, 1024).astype(np.int16)

    return norm_canvas, fixed_canvas

if __name__ == "__main__":
    print("[*] Preprocessing module compiled successfully.")
