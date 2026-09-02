#!/usr/bin/env python3
"""
Phase 1: Golden Vector & Synthesizable Header Exporter (Integer Scaled)
Features:
- Produces Plain Old Data (POD) int16_t arrays for instantaneous C++ compilation and BRAM synthesis
- Weights scaled by 2^14 (16384)
- Activations and inputs scaled by 2^10 (1024)
- Exact bit-accurate intermediate activations and logits
"""

import os
import argparse
import numpy as np
import torch
from torchvision import datasets, transforms
from models import HardwareMLP

def export_c_array(f, name, tensor, type_str="data_t", format_spec="{:d}", items_per_line=16):
    """Writes a 1D or 2D array as a clean C++ array of integers."""
    arr = tensor.detach().cpu().numpy()
    if arr.ndim == 1:
        f.write(f"static const {type_str} {name}[{len(arr)}] = {{\n    ")
        for i, val in enumerate(arr):
            f.write(format_spec.format(int(val)))
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
                f.write(format_spec.format(int(arr[r, c])))
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

def export_3d_c_array(f, name, tensor, simd_width=16, type_str="weight_t", format_spec="{:d}"):
    """Writes a 2D weight matrix reshaped into [neurons][blocks][SIMD] for conflict-free BRAM synthesis."""
    arr = tensor.detach().cpu().numpy()
    rows, cols = arr.shape
    assert cols % simd_width == 0, f"Cols {cols} must be divisible by {simd_width}"
    blocks = cols // simd_width
    reshaped = arr.reshape(rows, blocks, simd_width)
    f.write(f"static const {type_str} {name}[{rows}][{blocks}][{simd_width}] = {{\n")
    for r in range(rows):
        f.write("    {\n")
        for b in range(blocks):
            f.write("        {")
            for k in range(simd_width):
                f.write(format_spec.format(int(reshaped[r, b, k])))
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

def export_all(checkpoint_path="checkpoint_mlp.pt", output_dir="../../golden_vectors", num_test_samples=20):
    os.makedirs(output_dir, exist_ok=True)
    device = torch.device("cpu")

    # 1. Load Model Checkpoint
    fp32_model = HardwareMLP().to(device)
    if not os.path.exists(checkpoint_path):
        raise FileNotFoundError(f"Checkpoint not found at {checkpoint_path}.")
    fp32_model.load_state_dict(torch.load(checkpoint_path, map_location=device))
    fp32_model.eval()

    # Scale weights by 2^14 = 16384 (14 fractional bits, range [-2, 2))
    w1_int = torch.round(fp32_model.fc1.weight.data * 16384.0).clamp(-32768, 32767).to(torch.int16)
    w2_int = torch.round(fp32_model.fc2.weight.data * 16384.0).clamp(-32768, 32767).to(torch.int16)
    w3_int = torch.round(fp32_model.fc3.weight.data * 16384.0).clamp(-32768, 32767).to(torch.int16)

    print("[*] Exporting Integer-Scaled Weights (W_scale=16384, POD int16_t)...")
    weights_header_path = os.path.join(output_dir, "weights_mlp_q.h")
    with open(weights_header_path, "w") as f:
        f.write("// =============================================================================\n")
        f.write("// Auto-generated Fixed-Point Quantized Weights (Integer Scaled POD int16_t)\n")
        f.write("// Architecture: 784 -> 128 (ReLU) -> 64 (ReLU) -> 10 (Linear)\n")
        f.write("// Weights Scale: 2^14 = 16384 | Bias-Free: 100% | Zero Template Bloat\n")
        f.write("// =============================================================================\n\n")
        f.write("#ifndef WEIGHTS_MLP_Q_H_\n#define WEIGHTS_MLP_Q_H_\n\n")
        f.write('#include "mlp.hpp"\n\n')

        export_3d_c_array(f, "weights_l1", w1_int, simd_width=16, type_str="weight_t")
        export_3d_c_array(f, "weights_l2", w2_int, simd_width=16, type_str="weight_t")
        export_3d_c_array(f, "weights_l3", w3_int, simd_width=16, type_str="weight_t")

        f.write("#endif // WEIGHTS_MLP_Q_H_\n")
    print(f"[+] Saved weights header to: {weights_header_path}")

    # 2. Select diverse test samples from MNIST test set
    transform = transforms.Compose([transforms.ToTensor()])
    test_dataset = datasets.MNIST(root="./data", train=False, download=True, transform=transform)

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

    # Scale inputs by 2^10 = 1024 (10 fractional bits, range [0, 1.0])
    x_int = torch.round(test_imgs_tensor * 1024.0).clamp(0, 1024).to(torch.int16)

    # 3. Simulate hardware integer scaling arithmetic
    # Layer 1: (B, 784) @ (784, 128) -> sum of products at scale 2^24
    z1 = torch.matmul(x_int.float(), w1_int.t().float()) # scale 2^24
    # Rescale to scale 2^10: (z1 + 8192) >> 14
    a1 = torch.clamp(torch.floor((z1 + 8192.0) / 16384.0), 0, 32767).to(torch.int16)

    # Layer 2: (B, 128) @ (128, 64)
    z2 = torch.matmul(a1.float(), w2_int.t().float())
    a2 = torch.clamp(torch.floor((z2 + 8192.0) / 16384.0), 0, 32767).to(torch.int16)

    # Layer 3: (B, 64) @ (64, 10)
    z3 = torch.matmul(a2.float(), w3_int.t().float())
    out_logits = torch.clamp(torch.floor((z3 + 8192.0) / 16384.0), -32768, 32767).to(torch.int16)

    preds = out_logits.argmax(dim=1).to(torch.int32)

    golden_header_path = os.path.join(output_dir, "golden_test_data.h")
    print(f"[*] Exporting Golden Verification Vectors ({len(selected_labels)} test images)...")
    with open(golden_header_path, "w") as f:
        f.write("// =============================================================================\n")
        f.write("// Auto-generated Golden Test Vectors & Intermediate Activation Tensors (int16_t)\n")
        f.write(f"// Samples Count: {len(selected_labels)} across all 10 digit classes (0-9)\n")
        f.write("// =============================================================================\n\n")
        f.write("#ifndef GOLDEN_TEST_DATA_H_\n#define GOLDEN_TEST_DATA_H_\n\n")
        f.write('#include "mlp.hpp"\n\n')
        f.write(f"#define NUM_TEST_SAMPLES {len(selected_labels)}\n\n")

        export_c_array(f, "golden_inputs", x_int, type_str="data_t", items_per_line=16)
        export_c_array(f, "golden_labels", test_labels_tensor, type_str="int", items_per_line=10)
        export_c_array(f, "golden_layer1_out", a1, type_str="data_t", items_per_line=16)
        export_c_array(f, "golden_layer2_out", a2, type_str="data_t", items_per_line=16)
        export_c_array(f, "golden_logits", out_logits, type_str="data_t", items_per_line=10)
        export_c_array(f, "golden_preds", preds, type_str="int", items_per_line=10)

        f.write("#endif // GOLDEN_TEST_DATA_H_\n")
    print(f"[+] Saved golden test vectors header to: {golden_header_path}")

    matches = (preds == test_labels_tensor).sum().item()
    batch_acc = 100.0 * matches / len(selected_labels)
    print(f"[+] Export verification: {matches}/{len(selected_labels)} sample images correctly classified ({batch_acc:.1f}% accuracy).")
    print("[+] Golden vector generation complete!")

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--checkpoint", type=str, default="checkpoint_mlp.pt")
    parser.add_argument("--output-dir", type=str, default="../../golden_vectors")
    parser.add_argument("--num-samples", type=int, default=20)
    args = parser.parse_args()

    export_all(checkpoint_path=args.checkpoint, output_dir=args.output_dir, num_test_samples=args.num_samples)
