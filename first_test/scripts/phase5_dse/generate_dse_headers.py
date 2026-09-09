#!/usr/bin/env python3
"""
Phase 5: DSE Weight & Vector Generator for Multi-Bitwidth Hardware Synthesis
Generates:
1. weights_mlp_8b.h & golden_test_data_8b.h   (8-bit signed int8_t)
2. weights_mlp_4b.h & golden_test_data_4b.h   (4-bit signed int8_t [-8, 7])
3. weights_mlp_8b_simd32.h                    (8-bit reshaped for SIMD-32 unroll)
"""

import os
import sys
import numpy as np
import torch
from torchvision import datasets, transforms

sys.path.append(os.path.join(os.path.dirname(__file__), "../phase1_ai"))
from models import HardwareMLP

def export_3d_c_array(f, name, tensor_np, blocks, simd_width, type_str="int8_t"):
    rows = tensor_np.shape[0]
    reshaped = tensor_np.reshape(rows, blocks, simd_width)
    f.write(f"static const {type_str} {name}[{rows}][{blocks}][{simd_width}] = {{\n")
    for r in range(rows):
        f.write("    {\n")
        for b in range(blocks):
            f.write("        {")
            for k in range(simd_width):
                f.write(f"{int(reshaped[r, b, k])}")
                if k < simd_width - 1:
                    f.write(", ")
            f.write("}")
            if b < blocks - 1:
                f.write(",\n")
            else:
                f.write("\n")
        f.write("    }")
        if r < rows - 1:
            f.write(",\n")
        else:
            f.write("\n")
    f.write("};\n\n")

def export_dse_headers(checkpoint_path="../phase1_ai/checkpoint_mlp.pt", output_dir="headers"):
    os.makedirs(output_dir, exist_ok=True)
    device = torch.device("cpu")

    model = HardwareMLP().to(device)
    if not os.path.exists(checkpoint_path):
        raise FileNotFoundError(f"Checkpoint not found at {checkpoint_path}")
    model.load_state_dict(torch.load(checkpoint_path, map_location=device))
    model.eval()

    w1_fp = model.fc1.weight.data.numpy() # (128, 784)
    w2_fp = model.fc2.weight.data.numpy() # (64, 128)
    w3_fp = model.fc3.weight.data.numpy() # (10, 64)

    # -------------------------------------------------------------------------
    # 1. Configuration: 8-bit (Scale: W=64 (2^6), Act=16 (2^4), Prod=2^10)
    # -------------------------------------------------------------------------
    w1_8b = np.clip(np.round(w1_fp * 64.0), -128, 127).astype(np.int8)
    w2_8b = np.clip(np.round(w2_fp * 64.0), -128, 127).astype(np.int8)
    w3_8b = np.clip(np.round(w3_fp * 64.0), -128, 127).astype(np.int8)

    # 8-bit @ SIMD-16
    h_path_8b = os.path.join(output_dir, "weights_mlp_8b.h")
    with open(h_path_8b, "w") as f:
        f.write("// Auto-generated 8-bit Quantized Weights (SIMD=16)\n#ifndef WEIGHTS_MLP_8B_H_\n#define WEIGHTS_MLP_8B_H_\n#include <stdint.h>\n\n")
        export_3d_c_array(f, "weights_l1_8b", w1_8b, 49, 16, type_str="int8_t")
        export_3d_c_array(f, "weights_l2_8b", w2_8b, 8, 16, type_str="int8_t")
        export_3d_c_array(f, "weights_l3_8b", w3_8b, 4, 16, type_str="int8_t")
        f.write("#endif\n")
    print(f"[+] Saved 8-bit SIMD-16 weights to: {h_path_8b}")

    # 8-bit @ SIMD-32 (Padding 784 to 800 for clean 25 blocks x 32)
    w1_8b_pad = np.pad(w1_8b, ((0, 0), (0, 16)), mode='constant') # (128, 800) -> 25 blocks of 32
    h_path_8b_simd32 = os.path.join(output_dir, "weights_mlp_8b_simd32.h")
    with open(h_path_8b_simd32, "w") as f:
        f.write("// Auto-generated 8-bit Quantized Weights (SIMD=32)\n#ifndef WEIGHTS_MLP_8B_SIMD32_H_\n#define WEIGHTS_MLP_8B_SIMD32_H_\n#include <stdint.h>\n\n")
        export_3d_c_array(f, "weights_l1_8b32", w1_8b_pad, 25, 32, type_str="int8_t")
        export_3d_c_array(f, "weights_l2_8b32", w2_8b, 4, 32, type_str="int8_t")
        export_3d_c_array(f, "weights_l3_8b32", w3_8b, 2, 32, type_str="int8_t")
        f.write("#endif\n")
    print(f"[+] Saved 8-bit SIMD-32 weights to: {h_path_8b_simd32}")

    # -------------------------------------------------------------------------
    # 2. Configuration: 4-bit (Scale: W=4 (2^2), Act=4 (2^2), Prod=2^4)
    # Clamped to signed 4-bit range [-8, +7]
    # -------------------------------------------------------------------------
    w1_4b = np.clip(np.round(w1_fp * 4.0), -8, 7).astype(np.int8)
    w2_4b = np.clip(np.round(w2_fp * 4.0), -8, 7).astype(np.int8)
    w3_4b = np.clip(np.round(w3_fp * 4.0), -8, 7).astype(np.int8)

    h_path_4b = os.path.join(output_dir, "weights_mlp_4b.h")
    with open(h_path_4b, "w") as f:
        f.write("// Auto-generated 4-bit Quantized Weights (SIMD=16, range [-8, 7])\n#ifndef WEIGHTS_MLP_4B_H_\n#define WEIGHTS_MLP_4B_H_\n#include <stdint.h>\n\n")
        export_3d_c_array(f, "weights_l1_4b", w1_4b, 49, 16, type_str="int8_t")
        export_3d_c_array(f, "weights_l2_4b", w2_4b, 8, 16, type_str="int8_t")
        export_3d_c_array(f, "weights_l3_4b", w3_4b, 4, 16, type_str="int8_t")
        f.write("#endif\n")
    print(f"[+] Saved 4-bit SIMD-16 weights to: {h_path_4b}")

    print("[+] All DSE Multi-Bitwidth headers generated successfully!")

if __name__ == "__main__":
    export_dse_headers()
