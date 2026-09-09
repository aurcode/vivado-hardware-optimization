# Dispatch: Explorer DSE 2

## 2026-09-09T01:48:31Z
Investigate the Quantization and DSE status:
1. Examine `dse/ptq_sweep.py`, `dse/plot_pareto.py`, and `dse/synth_results/`.
2. Check what is needed to run `dse/ptq_sweep.py` across bitwidths (16-bit, 11-bit baseline, 8-bit, 6-bit, 4-bit) on 100 test samples in `hw/test_inputs.h`.
3. Check what is required for the formal mathematical proof of the 11-bit saturation knee point ($\Delta \text{Acc} = 0$ for $W \ge 11$, degradation below 8 bits, and catastrophic collapse at 4 bits due to noise variance accumulation across 784 dimensions).
4. Check synthesis data in `dse/synth_results/dse_summary.json` (LUT, FF, DSP, BRAM, latency) across bitwidths.
5. Check plot generation scripts and target files in `reports/assets/` (`bitwidth_vs_accuracy.png`, `bitwidth_vs_resources.png`, `pareto_frontier.png`).
6. Check `first_test/` or other dirs for prior results or scripts.

Write your findings and step-by-step execution plan in `/home/coder/vivado/.agents/explorer_dse_2/handoff.md`.
Send a completion message back to parent when finished.
