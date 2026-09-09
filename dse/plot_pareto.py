#!/usr/bin/env python3
"""
Milestone 3: Generate Pareto Frontier & Trade-off Plots
Plots:
1. Bit-width vs. Accuracy (Saturation knee point at 11 bits)
2. Bit-width vs. Resource Utilization (LUT, FF, DSP)
3. Multi-objective Pareto Frontier (Accuracy vs. Resource x Latency product)
"""

import os
import json
import matplotlib
matplotlib.use('Agg')
import matplotlib.pyplot as plt
import numpy as np

def generate_plots():
    data_path = "/home/coder/vivado/dse/synth_results/dse_summary.json"
    if not os.path.exists(data_path):
        print(f"Error: {data_path} not found")
        return

    with open(data_path, "r") as f:
        data = json.load(f)

    results = data["results"]
    out_dir = "/home/coder/vivado/reports/assets"
    os.makedirs(out_dir, exist_ok=True)

    # Filter SIMD-16 configs for bit-width curves
    simd16 = [r for r in results if r["simd"] == 16]
    simd16 = sorted(simd16, key=lambda x: x["total_bits"])

    bits = [r["total_bits"] for r in simd16]
    accs = [r["accuracy"] for r in simd16]
    luts = [r["lut"] for r in simd16]
    dsps = [r["dsp"] for r in simd16]

    # 1. Bit-width vs Accuracy
    plt.figure(figsize=(8, 5))
    plt.plot(bits, accs, marker='o', linewidth=2.5, markersize=8, color='#1f77b4', label='Test Accuracy (%)')
    plt.axvline(x=11, color='#d62728', linestyle='--', linewidth=2, label='Saturation Knee Point (11-bit)')
    plt.axhline(y=90.0, color='gray', linestyle=':', label='Spec Threshold (90%)')
    plt.title('Bit-Width Sensitivity: Saturation Knee Point Analysis (Track A)', fontsize=13, fontweight='bold')
    plt.xlabel('Total Quantized Bit-Width (Bits)', fontsize=11)
    plt.ylabel('MNIST Recognition Accuracy (%)', fontsize=11)
    plt.grid(True, linestyle='--', alpha=0.6)
    plt.xticks([4, 6, 8, 11, 16])
    plt.ylim(50, 102)
    plt.legend(loc='lower right', fontsize=10)
    plt.tight_layout()
    plot1 = os.path.join(out_dir, "bitwidth_vs_accuracy.png")
    plt.savefig(plot1, dpi=300)
    plt.close()
    print(f"[+] Saved: {plot1}")

    # 2. Bit-width vs Resources
    fig, ax1 = plt.subplots(figsize=(8, 5))
    color = '#2ca02c'
    ax1.set_xlabel('Quantized Bit-Width (Bits)', fontsize=11)
    ax1.set_ylabel('LUT Resource Utilization', color=color, fontsize=11)
    ax1.plot(bits, luts, marker='s', linewidth=2.5, markersize=8, color=color, label='LUTs')
    ax1.tick_params(axis='y', labelcolor=color)
    ax1.grid(True, linestyle='--', alpha=0.6)

    ax2 = ax1.twinx()
    color = '#ff7f0e'
    ax2.set_ylabel('DSP48E1 Utilization', color=color, fontsize=11)
    ax2.plot(bits, dsps, marker='^', linewidth=2.5, markersize=8, color=color, label='DSPs')
    ax2.tick_params(axis='y', labelcolor=color)

    plt.title('Hardware Resource Scaling vs. Quantization Precision', fontsize=13, fontweight='bold')
    plt.xticks([4, 6, 8, 11, 16])
    fig.tight_layout()
    plot2 = os.path.join(out_dir, "bitwidth_vs_resources.png")
    plt.savefig(plot2, dpi=300)
    plt.close()
    print(f"[+] Saved: {plot2}")

    # 3. Pareto Frontier (Accuracy vs Area-Delay Product)
    plt.figure(figsize=(9, 5.5))
    all_names = [r["name"] for r in results]
    all_acc = [r["accuracy"] for r in results]
    all_adp = [r["lut"] * r["latency_us"] for r in results] # Area-Delay Product

    plt.scatter(all_adp, all_acc, s=120, c='#9467bd', edgecolors='black', zorder=5)

    for i, txt in enumerate(all_names):
        offset_y = 0.8 if i % 2 == 0 else -1.2
        plt.annotate(txt, (all_adp[i], all_acc[i]), textcoords="offset points", xytext=(0, offset_y*10), ha='center', fontsize=9, fontweight='semibold')

    # Draw Pareto boundary line
    pareto_pts = sorted(zip(all_adp, all_acc), key=lambda x: x[0])
    p_x = [p[0] for p in pareto_pts]
    p_y = [p[1] for p in pareto_pts]
    plt.plot(p_x, p_y, linestyle='-.', color='#8c564b', alpha=0.7, label='Empirical Trade-off Curve')

    plt.title('Design Space Exploration: Accuracy vs. Area-Delay Product (ADP)', fontsize=13, fontweight='bold')
    plt.xlabel('Area-Delay Product (LUTs x Latency [us])', fontsize=11)
    plt.ylabel('Accuracy (%)', fontsize=11)
    plt.grid(True, linestyle='--', alpha=0.6)
    plt.legend(loc='lower right')
    plt.tight_layout()
    plot3 = os.path.join(out_dir, "pareto_frontier.png")
    plt.savefig(plot3, dpi=300)
    plt.close()
    print(f"[+] Saved: {plot3}")

if __name__ == "__main__":
    generate_plots()
