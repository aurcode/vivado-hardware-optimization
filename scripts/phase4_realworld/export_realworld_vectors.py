#!/usr/bin/env python3
"""
Phase 4: Export Real-World Preprocessed Images as C++ Header
Generates:
golden_vectors/realworld_test_data.h
Includes:
- realworld_inputs[20][784]
- realworld_labels[20]
- realworld_preds[20]
"""

import os
import sys
import numpy as np
import torch

sys.path.append(os.path.join(os.path.dirname(__file__), "../phase1_ai"))
from models import HardwareMLP
from preprocess import preprocess_handwritten_image
from evaluate_domain_gap import run_hardware_sim

def export_c_array(f, name, arr, type_str="data_t", items_per_line=16):
    if arr.ndim == 1:
        f.write(f"static const {type_str} {name}[{len(arr)}] = {{\n    ")
        for i, val in enumerate(arr):
            f.write(f"{int(val)}")
            if i < len(arr) - 1:
                f.write(", ")
                if (i + 1) % items_per_line == 0:
                    f.write("\n    ")
        f.write("\n};\n\n")
    elif arr.ndim == 2:
        rows, cols = arr.shape
        f.write(f"static const {type_str} {name}[{rows}][{cols}] = {{\n")
        for r in range(rows):
            f.write("    {")
            for c in range(cols):
                f.write(f"{int(arr[r, c])}")
                if c < cols - 1:
                    f.write(", ")
                    if (c + 1) % items_per_line == 0:
                        f.write("\n     ")
            f.write("}")
            if r < rows - 1:
                f.write(",\n")
            else:
                f.write("\n")
        f.write("};\n\n")

def export_realworld(checkpoint_path="../phase1_ai/checkpoint_mlp.pt", output_dir="../../golden_vectors"):
    os.makedirs(output_dir, exist_ok=True)
    
    # Load weights
    model = HardwareMLP()
    model.load_state_dict(torch.load(checkpoint_path, map_location="cpu"))
    model.eval()
    w1_int = torch.round(model.fc1.weight.data * 16384.0).clamp(-32768, 32767).to(torch.int16)
    w2_int = torch.round(model.fc2.weight.data * 16384.0).clamp(-32768, 32767).to(torch.int16)
    w3_int = torch.round(model.fc3.weight.data * 16384.0).clamp(-32768, 32767).to(torch.int16)

    # Select 20 real-world samples across digits 0-9 from Cohort 1 & Cohort 2
    data_dir = "real_world_data"
    selected_inputs = []
    selected_labels = []
    selected_preds = []

    for d in range(10):
        # 1 clean, 1 with lighting/shadow
        p1 = os.path.join(data_dir, f"c1_d{d}_rep0.png")
        p2 = os.path.join(data_dir, f"c2_d{d}_rep0.png")
        for p, label in [(p1, d), (p2, d)]:
            _, fixed = preprocess_handwritten_image(p)
            flat = fixed.reshape(784)
            pred, _, _ = run_hardware_sim(flat, w1_int, w2_int, w3_int)
            selected_inputs.append(flat)
            selected_labels.append(label)
            selected_preds.append(pred)

    inputs_np = np.array(selected_inputs, dtype=np.int16)
    labels_np = np.array(selected_labels, dtype=np.int32)
    preds_np = np.array(selected_preds, dtype=np.int32)

    out_file = os.path.join(output_dir, "realworld_test_data.h")
    print(f"[*] Exporting Real-World Test Header to: {out_file}...")
    with open(out_file, "w") as f:
        f.write("// =============================================================================\n")
        f.write("// Real-World Camera & Handwritten Preprocessed Test Data (int16_t)\n")
        f.write("// Samples Count: 20 (Clean + Shadow/Lighting across Digits 0-9)\n")
        f.write("// =============================================================================\n\n")
        f.write("#ifndef REALWORLD_TEST_DATA_H_\n#define REALWORLD_TEST_DATA_H_\n\n")
        f.write('#include "mlp.hpp"\n\n')
        f.write(f"#define NUM_REALWORLD_SAMPLES {len(selected_labels)}\n\n")

        export_c_array(f, "realworld_inputs", inputs_np, type_str="data_t", items_per_line=16)
        export_c_array(f, "realworld_labels", labels_np, type_str="int", items_per_line=10)
        export_c_array(f, "realworld_preds", preds_np, type_str="int", items_per_line=10)

        f.write("#endif // REALWORLD_TEST_DATA_H_\n")

    matches = (labels_np == preds_np).sum()
    print(f"[+] Export verification: {matches}/{len(selected_labels)} real-world samples correctly predicted ({100.0 * matches / len(selected_labels):.1f}%).")

if __name__ == "__main__":
    export_realworld()
