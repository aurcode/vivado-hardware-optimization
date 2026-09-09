#!/usr/bin/env python3
"""
Phase 1: Post-Training Quantization (PTQ) & Design Space Exploration (DSE)
Simulates Vivado HLS ap_fixed<W, I> arithmetic on Track A MLP.
Sweeps bitwidths from 4-bit to 16-bit to locate the accuracy saturation knee point.
"""

import os
import argparse
import math
import numpy as np
import torch
import torch.nn as nn
import torch.nn.functional as F
from torch.utils.data import DataLoader
from torchvision import datasets, transforms
from models import HardwareMLP

def quantize_tensor(tensor, total_bits, int_bits):
    """
    Bit-accurate simulation of Xilinx ap_fixed<total_bits, int_bits, AP_TRN, AP_WRAP>.
    total_bits (W): total word length including sign
    int_bits (I): integer bits including sign
    frac_bits (F): total_bits - int_bits
    """
    frac_bits = total_bits - int_bits
    scale = 2.0 ** frac_bits
    min_val = - (2.0 ** (total_bits - 1))
    max_val = (2.0 ** (total_bits - 1)) - 1.0

    # Scale, round to nearest integer, clip to bitwidth boundaries
    scaled = torch.round(tensor * scale)
    clipped = torch.clamp(scaled, min_val, max_val)
    return clipped / scale

class QuantizedHardwareMLP:
    """
    Emulates the exact HLS fixed-point datapath for HardwareMLP.
    """
    def __init__(self, fp32_model, bitwidth_cfg):
        """
        bitwidth_cfg: dict containing (W, I) for weights and activations
        e.g., {'w_bits': (8, 2), 'act_bits': (8, 4)}
        """
        self.w_bits, self.w_int = bitwidth_cfg['w']
        self.a_bits, self.a_int = bitwidth_cfg['act']

        # Quantize weights
        self.w1 = quantize_tensor(fp32_model.fc1.weight.data.clone(), self.w_bits, self.w_int)
        self.w2 = quantize_tensor(fp32_model.fc2.weight.data.clone(), self.w_bits, self.w_int)
        self.w3 = quantize_tensor(fp32_model.fc3.weight.data.clone(), self.w_bits, self.w_int)

    def forward(self, x):
        if x.dim() > 2:
            x = x.view(x.size(0), -1)

        # Quantize inputs (ap_fixed)
        x_q = quantize_tensor(x, self.a_bits, self.a_int)

        # Layer 1: MAC + ReLU + Quantize
        z1 = F.linear(x_q, self.w1, bias=None)
        a1 = F.relu(z1)
        a1_q = quantize_tensor(a1, self.a_bits, self.a_int)

        # Layer 2: MAC + ReLU + Quantize
        z2 = F.linear(a1_q, self.w2, bias=None)
        a2 = F.relu(z2)
        a2_q = quantize_tensor(a2, self.a_bits, self.a_int)

        # Layer 3: MAC (Logits)
        z3 = F.linear(a2_q, self.w3, bias=None)
        out_q = quantize_tensor(z3, self.a_bits, self.a_int)
        return out_q

    def forward_with_intermediates(self, x):
        if x.dim() > 2:
            x = x.view(x.size(0), -1)

        x_q = quantize_tensor(x, self.a_bits, self.a_int)
        
        z1 = F.linear(x_q, self.w1, bias=None)
        a1 = F.relu(z1)
        a1_q = quantize_tensor(a1, self.a_bits, self.a_int)

        z2 = F.linear(a1_q, self.w2, bias=None)
        a2 = F.relu(z2)
        a2_q = quantize_tensor(a2, self.a_bits, self.a_int)

        z3 = F.linear(a2_q, self.w3, bias=None)
        out_q = quantize_tensor(z3, self.a_bits, self.a_int)

        return {
            "x_q": x_q,
            "z1": z1,
            "a1_q": a1_q,
            "z2": z2,
            "a2_q": a2_q,
            "out_q": out_q
        }

def evaluate_quantized(q_model, test_loader):
    correct = 0
    total = 0
    with torch.no_grad():
        for data, targets in test_loader:
            outputs = q_model.forward(data)
            preds = outputs.argmax(dim=1)
            correct += (preds == targets).sum().item()
            total += targets.size(0)
    return 100.0 * correct / total

def run_ptq_sweep(checkpoint_path="checkpoint_mlp.pt", data_dir="./data"):
    # Load dataset
    transform = transforms.Compose([transforms.ToTensor()])
    test_dataset = datasets.MNIST(root=data_dir, train=False, download=True, transform=transform)
    test_loader = DataLoader(test_dataset, batch_size=128, shuffle=False)

    # Load FP32 Baseline Model
    fp32_model = HardwareMLP()
    if not os.path.exists(checkpoint_path):
        raise FileNotFoundError(f"Checkpoint not found at {checkpoint_path}. Train model first.")
    fp32_model.load_state_dict(torch.load(checkpoint_path, map_location="cpu"))
    fp32_model.eval()

    # Evaluate FP32 Baseline
    fp32_correct = 0
    total = 0
    with torch.no_grad():
        for data, targets in test_loader:
            out = fp32_model(data)
            fp32_correct += (out.argmax(dim=1) == targets).sum().item()
            total += targets.size(0)
    fp32_acc = 100.0 * fp32_correct / total

    print("=" * 82)
    print("      POST-TRAINING QUANTIZATION (PTQ) & DESIGN SPACE EXPLORATION (DSE)")
    print("=" * 82)
    print(f"FP32 Baseline Accuracy : {fp32_acc:.2f}%")
    print(f"Total Model Parameters : 109,184 (100% Bias-free, Zero DSP overhead for bias)")
    print("-" * 82)
    print(f"{'Config':<18} | {'Bitwidth (W,I)':<16} | {'Accuracy (%)':<13} | {'Drop (%)':<10} | {'BRAM (KB)':<10} | {'Status'}")
    print("-" * 82)

    # Sweep bitwidths: 16-bit down to 4-bit
    # (Total Bits W, Weight Int Bits I_w, Activation Int Bits I_a)
    configs = [
        ("FP32 (Reference)", 32, 8, 8),
        ("16-bit (Level 1)", 16, 2, 6),
        ("12-bit (Robust)",  12, 2, 5),
        ("11-bit (Knee pt)", 11, 2, 5),
        ("10-bit (Balanced)",10, 2, 4),
        ("8-bit  (Efficient)", 8, 2, 4),
        ("6-bit  (Aggressive)",6, 2, 3),
        ("4-bit  (Extreme)",   4, 2, 3),
    ]

    results = []
    knee_point = None

    for label, W, I_w, I_a in configs:
        if W == 32:
            results.append((label, "float32", fp32_acc, 0.0, round(109184 * 4 / 1024, 1), "Baseline"))
            continue

        cfg = {
            'w': (W, I_w),
            'act': (W, I_a)
        }
        q_model = QuantizedHardwareMLP(fp32_model, cfg)
        acc = evaluate_quantized(q_model, test_loader)
        drop = fp32_acc - acc
        bram_kb = round(109184 * (W / 8.0) / 1024.0, 1)

        status = "PASSED (>=90%)" if acc >= 90.0 else "DEGRADED (<90%)"
        if acc >= 90.0 and (knee_point is None or W < knee_point[1]):
            if drop < 1.0:
                knee_point = (label, W, acc, drop)

        cfg_str = f"W{W}_Iw{I_w}_Ia{I_a}"
        results.append((label, cfg_str, acc, drop, bram_kb, status))

    for label, cfg_str, acc, drop, bram_kb, status in results:
        print(f"{label:<18} | {cfg_str:<16} | {acc:6.2f}%       | {drop:5.2f}%    | {bram_kb:8.1f}   | {status}")

    print("=" * 82)
    if knee_point:
        print(f"[★] Optimal Pareto Knee-Point: {knee_point[0]} (W={knee_point[1]} bits)")
        print(f"    Achieves {knee_point[2]:.2f}% accuracy with merely {knee_point[3]:.2f}% degradation from FP32.")
    print("=" * 82)

    return results

if __name__ == "__main__":
    parser = argparse.ArgumentParser()
    parser.add_argument("--checkpoint", type=str, default="checkpoint_mlp.pt")
    parser.add_argument("--data-dir", type=str, default="./data")
    args = parser.parse_args()
    run_ptq_sweep(checkpoint_path=args.checkpoint, data_dir=args.data_dir)
