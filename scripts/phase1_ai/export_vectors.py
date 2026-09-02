#!/usr/bin/env python3
"""
Phase 1: Golden Vector & Synthesizable Header Exporter
Generates:
1. weights_mlp_q.h       - Quantized fixed-point weight matrices for Vivado HLS
2. test_samples.h / .dat - Normalized test image batches (all 10 digits represented)
3. golden_activations.h  - Layer-by-layer bit-accurate intermediate activation vectors
"""

import os
import argparse
import numpy as np
import torch
from torchvision import datasets, transforms
from models import HardwareMLP
from ptq_sweep import QuantizedHardwareMLP, quantize_tensor

def export_c_array(f, name, tensor, type_str="data_t", format_spec="{:.8f}f", items_per_line=8):
    """Writes a 1D or 2D PyTorch/NumPy array as a clean C++ array."""
    arr = tensor.detach().cpu().numpy()
    if arr.ndim == 1:
        f.write(f"const {type_str} {name}[{len(arr)}] = {{\n    ")
        for i, val in enumerate(arr):
            f.write(format_spec.format(val))
            if i < len(arr) - 1:
                f.write(", ")
                if (i + 1) % items_per_line == 0:
                    f.write("\n    ")
        f.write("\n};\n\n")
    elif arr.ndim == 2:
        rows, cols = arr.shape
        f.write(f"const {type_str} {name}[{rows}][{cols}] = {{\n")
        for r in range(rows):
            f.write("    {")
            for c in range(cols):
                f.write(format_spec.format(arr[r, c]))
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

def export_all(checkpoint_path="checkpoint_mlp.pt", output_dir="../../golden_vectors", num_test_samples=20, W=16, I_w=2, I_a=6):
    os.makedirs(output_dir, exist_ok=True)
    device = torch.device("cpu")

    # 1. Load Model & Apply PTQ
    fp32_model = HardwareMLP().to(device)
    if not os.path.exists(checkpoint_path):
        raise FileNotFoundError(f"Checkpoint not found at {checkpoint_path}.")
    fp32_model.load_state_dict(torch.load(checkpoint_path, map_location=device))
    fp32_model.eval()

    cfg = {'w': (W, I_w), 'act': (W, I_a)}
    q_model = QuantizedHardwareMLP(fp32_model, cfg)

    print(f"[*] Exporting Quantized Weights for W={W}, I_w={I_w}, I_a={I_a}...")
    weights_header_path = os.path.join(output_dir, "weights_mlp_q.h")
    with open(weights_header_path, "w") as f:
        f.write("// =============================================================================\n")
        f.write(f"// Auto-generated Quantized Weights for Track A HardwareMLP (MNIST)\n")
        f.write(f"// Bitwidth Configuration: W={W}, I_w={I_w} (Weights), I_a={I_a} (Activations)\n")
        f.write("// Architecture: 784 -> 128 (ReLU) -> 64 (ReLU) -> 10 (Linear)\n")
        f.write("// Note: 100% Bias-free network pruned for minimal FPGA DSP48/LUT footprint\n")
        f.write("// =============================================================================\n\n")
        f.write("#ifndef WEIGHTS_MLP_Q_H_\n#define WEIGHTS_MLP_Q_H_\n\n")
        f.write('#include "mlp.hpp"\n\n')
        
        export_c_array(f, "weights_l1", q_model.w1, type_str="data_t", format_spec="{:.8f}f", items_per_line=8)
        export_c_array(f, "weights_l2", q_model.w2, type_str="data_t", format_spec="{:.8f}f", items_per_line=8)
        export_c_array(f, "weights_l3", q_model.w3, type_str="data_t", format_spec="{:.8f}f", items_per_line=8)
        
        f.write("#endif // WEIGHTS_MLP_Q_H_\n")
    print(f"[+] Saved weights header to: {weights_header_path}")

    # 2. Select diverse test samples from MNIST test set
    transform = transforms.Compose([transforms.ToTensor()])
    test_dataset = datasets.MNIST(root="./data", train=False, download=True, transform=transform)

    # Collect at least 2 samples per digit 0-9
    samples_by_digit = {d: [] for d in range(10)}
    for img, label in test_dataset:
        if len(samples_by_digit[label]) < (num_test_samples // 10):
            samples_by_digit[label].append(img)
        if all(len(v) >= (num_test_samples // 10) for v in samples_by_digit.values()):
            break

    selected_images = []
    selected_labels = []
    for d in range(10):
        for img in samples_by_digit[d]:
            selected_images.append(img.view(784))
            selected_labels.append(d)

    test_imgs_tensor = torch.stack(selected_images)
    test_labels_tensor = torch.tensor(selected_labels, dtype=torch.int32)

    # 3. Compute Layer-by-Layer Intermediates
    intermediates = q_model.forward_with_intermediates(test_imgs_tensor)

    golden_header_path = os.path.join(output_dir, "golden_test_data.h")
    print(f"[*] Exporting Golden Verification Vectors ({len(selected_labels)} test images)...")
    with open(golden_header_path, "w") as f:
        f.write("// =============================================================================\n")
        f.write("// Auto-generated Golden Test Vectors & Intermediate Activation Tensors\n")
        f.write(f"// Samples Count: {len(selected_labels)} across all 10 digit classes (0-9)\n")
        f.write("// Used by Vivado HLS testbench (tb_mlp.cpp) for bit-accurate verification\n")
        f.write("// =============================================================================\n\n")
        f.write("#ifndef GOLDEN_TEST_DATA_H_\n#define GOLDEN_TEST_DATA_H_\n\n")
        f.write('#include "mlp.hpp"\n\n')
        f.write(f"#define NUM_TEST_SAMPLES {len(selected_labels)}\n\n")

        export_c_array(f, "golden_inputs", intermediates["x_q"], type_str="data_t", format_spec="{:.8f}f", items_per_line=8)
        export_c_array(f, "golden_labels", test_labels_tensor, type_str="int", format_spec="{}", items_per_line=10)
        export_c_array(f, "golden_layer1_out", intermediates["a1_q"], type_str="data_t", format_spec="{:.8f}f", items_per_line=8)
        export_c_array(f, "golden_layer2_out", intermediates["a2_q"], type_str="data_t", format_spec="{:.8f}f", items_per_line=8)
        export_c_array(f, "golden_logits", intermediates["out_q"], type_str="data_t", format_spec="{:.8f}f", items_per_line=5)

        preds = intermediates["out_q"].argmax(dim=1).to(torch.int32)
        export_c_array(f, "golden_preds", preds, type_str="int", format_spec="{}", items_per_line=10)

        f.write("#endif // GOLDEN_TEST_DATA_H_\n")
    print(f"[+] Saved golden test vectors header to: {golden_header_path}")

    # 4. Summary metrics
    matches = (preds == test_labels_tensor).sum().item()
    batch_acc = 100.0 * matches / len(selected_labels)
    print(f"[+] Export verification: {matches}/{len(selected_labels)} sample images correctly classified ({batch_acc:.1f}% accuracy).")
    print("[+] Golden vector generation complete!")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--checkpoint", type=str, default="checkpoint_mlp.pt")
    parser.add_argument("--output-dir", type=str, default="../../golden_vectors")
    parser.add_argument("--num-samples", type=int, default=20)
    parser.add_argument("-W", type=int, default=16)
    parser.add_argument("--Iw", type=int, default=2)
    parser.add_argument("--Ia", type=int, default=6)
    args = parser.parse_args()

    export_all(checkpoint_path=args.checkpoint, output_dir=args.output_dir, num_test_samples=args.num_samples, W=args.W, I_w=args.Iw, I_a=args.Ia)
