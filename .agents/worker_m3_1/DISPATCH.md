## 2026-09-09T01:22:24Z
You are the Quantization and DSE Implementer (Worker M3) for the Intelligent Chip Hardware Accelerator Programming Project.
Your working directory is: /home/coder/vivado/.agents/worker_m3_1

Required reading:
1. /home/coder/vivado/ORIGINAL_REQUEST.md
2. /home/coder/vivado/.agents/orchestrator_1/PROJECT.md
3. /home/coder/vivado/.agents/explorer_survey_3/survey_algo_report.md
4. /home/coder/vivado/hw/weights.h
5. /home/coder/vivado/hw/test_inputs.h
6. /home/coder/vivado/first_test/scripts/phase5_dse/

MANDATORY INTEGRITY WARNING:
DO NOT CHEAT. All implementations must be genuine. DO NOT hardcode test results, create dummy/facade implementations, or circumvent the intended task. A teamwork_preview_auditor will independently verify your work. Integrity violations WILL be detected and your work WILL be rejected.

Your Scope & Exclusively Owned Files:
- You exclusively own: /home/coder/vivado/dse/ (including ptq_sweep.py, plot_pareto.py, synth_results/, and generated figures/tables).
- Do NOT modify files in hw/, preprocessing/, or e2e_tests/.

Your Mission:
Implement and verify the Level 3 (10-Point Bonus) Post-Training Quantization & Design Space Exploration deliverables:
1. Post-Training Quantization (PTQ) Sensitivity Sweep:
   - Implement `dse/ptq_sweep.py` running sensitivity sweeps across bitwidths: 16-bit, 14-bit, 12-bit, 11-bit baseline (ap_fixed<11, 3>), 10-bit, 8-bit, 6-bit, and 4-bit.
   - Evaluate exact simulated accuracy on the 100 test samples in `hw/test_inputs.h` with frozen `hw/weights.h`.
2. Mathematical Proof of Saturation Knee Point:
   - Provide a formal mathematical proof showing that 11-bit (`ap_fixed<11, 3>`) is the saturation knee point (拐点), where the marginal accuracy improvement derivative is zero for W >= 11 bits (accuracy plateaus at 98.00%), and explain the degradation below 8 bits and catastrophic cliff at 4 bits (high-dimensional noise variance accumulation across 784 inputs).
3. FPGA Synthesis PPA Extraction:
   - Extract and organize the actual synthesis results from `first_test/scripts/phase5_dse/` into `/home/coder/vivado/dse/synth_results/` across configurations: W16_SIMD16, W8_SIMD16, W8_SIMD32, W4_SIMD16 (LUT, FF, DSP, BRAM, latency, clock slack).
4. Pareto Frontier & DSE Visualizations:
   - Implement `dse/plot_pareto.py` generating high-quality vector / PNG figures:
     - `dse/bitwidth_vs_accuracy.png`: Bit-width vs. Accuracy curve with highlighted 11-bit knee point.
     - `dse/bitwidth_vs_resources.png`: Bit-width vs. FPGA resource utilization (BRAM, DSP, LUT).
     - `dse/pareto_frontier.png`: Accuracy vs. Area / Latency Pareto frontier.
   - Formulate concrete, data-backed engineering recommendations for edge deployment on Zynq-7000 XC7Z020.
5. Verification:
   - Run all scripts and ensure all outputs (curves, CSV data tables, summaries) are generated without error.
6. Documentation:
   - Write your implementation report in `/home/coder/vivado/.agents/worker_m3_1/m3_report.md` and a 5-component handoff in `/home/coder/vivado/.agents/worker_m3_1/handoff.md`.
7. Send a message to the orchestrator (conversation ID: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa) when complete.
