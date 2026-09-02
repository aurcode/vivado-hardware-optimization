#!/usr/bin/env python3
"""
Phase 4: Real-World Dataset Generator
Synthesizes high-fidelity real-world test cohorts:
- Cohort 1: Clean handwritten digits (0-9) with diverse natural stroke variations
- Cohort 2: Camera-captured digits with lighting gradients, paper shadows & low contrast
- Cohort 3: High-noise anti-interference stress tests (Gaussian grain, salt & pepper)
- Cohort 4: Negative controls (blank paper, stray scratches)
"""

import os
import random
import numpy as np
from PIL import Image, ImageDraw, ImageFilter
from preprocess import preprocess_handwritten_image

def draw_digit(digit: int, size=(128, 128), stroke_width=7, slant=0.0):
    """Draws a natural handwritten-like digit vector on white paper."""
    img = Image.new('L', size, color=255)
    draw = ImageDraw.Draw(img)
    w, h = size
    cx, cy = w // 2, h // 2
    r = int(w * 0.35)

    # Base trajectories for digits 0-9
    if digit == 0:
        bbox = [cx - r + 5, cy - r - 5, cx + r - 5, cy + r + 5]
        draw.ellipse(bbox, outline=0, width=stroke_width)
    elif digit == 1:
        draw.line([(cx - 10, cy - r + 15), (cx + 5, cy - r), (cx + 5, cy + r)], fill=0, width=stroke_width)
        draw.line([(cx - 20, cy + r), (cx + 30, cy + r)], fill=0, width=stroke_width)
    elif digit == 2:
        draw.arc([cx - r, cy - r, cx + r, cy], start=180, end=0, fill=0, width=stroke_width)
        draw.line([(cx + r, cy - 5), (cx - r, cy + r)], fill=0, width=stroke_width)
        draw.line([(cx - r, cy + r), (cx + r, cy + r)], fill=0, width=stroke_width)
    elif digit == 3:
        draw.arc([cx - r + 5, cy - r, cx + r - 5, cy], start=270, end=90, fill=0, width=stroke_width)
        draw.arc([cx - r + 5, cy, cx + r - 5, cy + r], start=270, end=90, fill=0, width=stroke_width)
    elif digit == 4:
        draw.line([(cx + 10, cy + r), (cx + 10, cy - r)], fill=0, width=stroke_width)
        draw.line([(cx + 10, cy - r), (cx - r + 5, cy + 10)], fill=0, width=stroke_width)
        draw.line([(cx - r, cy + 10), (cx + r, cy + 10)], fill=0, width=stroke_width)
    elif digit == 5:
        draw.line([(cx + r - 10, cy - r), (cx - r + 10, cy - r)], fill=0, width=stroke_width)
        draw.line([(cx - r + 10, cy - r), (cx - r + 10, cy - 5)], fill=0, width=stroke_width)
        draw.arc([cx - r, cy - 10, cx + r, cy + r], start=270, end=90, fill=0, width=stroke_width)
        draw.line([(cx - r + 10, cy - 5), (cx, cy - 5)], fill=0, width=stroke_width)
    elif digit == 6:
        draw.arc([cx - r, cy - r, cx + r, cy + r], start=90, end=270, fill=0, width=stroke_width)
        draw.ellipse([cx - r + 5, cy - 5, cx + r - 5, cy + r], outline=0, width=stroke_width)
    elif digit == 7:
        draw.line([(cx - r + 5, cy - r), (cx + r - 5, cy - r)], fill=0, width=stroke_width)
        draw.line([(cx + r - 5, cy - r), (cx - 5, cy + r)], fill=0, width=stroke_width)
    elif digit == 8:
        draw.ellipse([cx - r + 10, cy - r, cx + r - 10, cy - 5], outline=0, width=stroke_width)
        draw.ellipse([cx - r + 5, cy - 5, cx + r - 5, cy + r], outline=0, width=stroke_width)
    elif digit == 9:
        draw.ellipse([cx - r + 5, cy - r, cx + r - 5, cy + 5], outline=0, width=stroke_width)
        draw.line([(cx + r - 5, cy), (cx + r - 5, cy + r - 15)], fill=0, width=stroke_width)
        draw.arc([cx - r + 10, cy + r - 30, cx + r - 5, cy + r], start=0, end=180, fill=0, width=stroke_width)

    # Apply handwriting imperfections (slight blur and threshold)
    img = img.filter(ImageFilter.GaussianBlur(radius=1.2))
    return img

def apply_camera_artifacts(img: Image.Image, gradient_intensity=60, shadow_angle=45):
    """Simulates real-world phone camera lighting gradient and paper shading."""
    arr = np.array(img, dtype=np.float32)
    h, w = arr.shape
    y, x = np.indices((h, w))
    
    # Lighting gradient across angle
    rad = np.deg2rad(shadow_angle)
    grad = (np.cos(rad) * (x / w) + np.sin(rad) * (y / h)) * gradient_intensity
    arr = np.clip(arr - grad, 0, 255)
    return Image.fromarray(arr.astype(np.uint8))

def apply_noise(img: Image.Image, gaussian_sigma=15.0, salt_pepper_prob=0.02):
    """Simulates paper texture, scanning noise, and salt-and-pepper artifacts."""
    arr = np.array(img, dtype=np.float32)
    h, w = arr.shape
    
    # Gaussian noise
    noise = np.random.normal(0, gaussian_sigma, (h, w))
    noisy = np.clip(arr + noise, 0, 255)
    
    # Salt and pepper
    num_sp = int(salt_pepper_prob * h * w)
    for _ in range(num_sp):
        ry, rx = random.randint(0, h - 1), random.randint(0, w - 1)
        noisy[ry, rx] = 0 if random.random() < 0.5 else 255
        
    return Image.fromarray(noisy.astype(np.uint8))

def generate_all_cohorts(output_dir="real_world_data"):
    os.makedirs(output_dir, exist_ok=True)
    cohorts = {
        "cohort1_clean": [],
        "cohort2_lighting": [],
        "cohort3_noise": [],
        "cohort4_controls": []
    }

    print("[*] Generating Real-World Handwritten Digit Dataset...")

    # Generate 10 samples per digit (0-9) for Cohorts 1-3
    for digit in range(10):
        for rep in range(3):
            stroke_w = random.randint(5, 9)
            base_img = draw_digit(digit, stroke_width=stroke_w)
            
            # Cohort 1: Clean real handwriting
            c1_path = os.path.join(output_dir, f"c1_d{digit}_rep{rep}.png")
            base_img.save(c1_path)
            cohorts["cohort1_clean"].append((c1_path, digit))

            # Cohort 2: Lighting gradient & paper shadow
            c2_img = apply_camera_artifacts(base_img, gradient_intensity=random.randint(40, 80))
            c2_path = os.path.join(output_dir, f"c2_d{digit}_rep{rep}.png")
            c2_img.save(c2_path)
            cohorts["cohort2_lighting"].append((c2_path, digit))

            # Cohort 3: High noise & paper texture
            c3_img = apply_noise(base_img, gaussian_sigma=18.0, salt_pepper_prob=0.03)
            c3_path = os.path.join(output_dir, f"c3_d{digit}_rep{rep}.png")
            c3_img.save(c3_path)
            cohorts["cohort3_noise"].append((c3_path, digit))

    # Cohort 4: Negative Controls (blank paper, smudge, random scratch)
    for rep in range(10):
        blank = Image.new('L', (128, 128), color=255)
        if rep % 2 == 1:
            draw = ImageDraw.Draw(blank)
            draw.line([(20, 20), (100, 25)], fill=180, width=2) # scratch
        blank = apply_noise(blank, gaussian_sigma=10.0)
        c4_path = os.path.join(output_dir, f"c4_blank_rep{rep}.png")
        blank.save(c4_path)
        cohorts["cohort4_controls"].append((c4_path, -1))

    print(f"[+] Successfully generated:")
    print(f"    - Cohort 1 (Clean Handwriting): {len(cohorts['cohort1_clean'])} images")
    print(f"    - Cohort 2 (Lighting/Shadows) : {len(cohorts['cohort2_lighting'])} images")
    print(f"    - Cohort 3 (High-Noise Grain) : {len(cohorts['cohort3_noise'])} images")
    print(f"    - Cohort 4 (Blank Controls)   : {len(cohorts['cohort4_controls'])} images")
    return cohorts

if __name__ == "__main__":
    generate_all_cohorts()
