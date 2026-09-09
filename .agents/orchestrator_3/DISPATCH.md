# Dispatch: Project Orchestrator 3

Timestamp: 2026-09-09T01:45:19Z
Working directory: /home/coder/vivado/.agents/orchestrator_3
Identity: teamwork_preview_orchestrator

## Mission
Resume and complete the 784-64-10 Multi-Layer Perceptron (MLP) hardware accelerator project on Xilinx Zynq-7000 (`xc7z020clg400-1`), continuing from Milestone 3 (Quantization & DSE) through Milestone 4 (the 5 defense deliverables in `reports/`) and Milestone 5 (final verification).

Authoritative User Request:
Read `/home/coder/vivado/ORIGINAL_REQUEST.md` (specifically the latest follow-up request from 2026-09-09T01:45:19Z).

## Scope & Core Requirements
1. **Milestone 3 (Quantization & DSE Deliverables)**:
   - Execute `dse/ptq_sweep.py` across bitwidths (16-bit, 11-bit baseline, 8-bit, 6-bit, 4-bit) on 100 test samples in `hw/test_inputs.h`.
   - Provide formal mathematical proof of the 11-bit saturation knee point.
   - Correlate FPGA synthesis metrics (LUT, FF, DSP, BRAM, latency) from `dse/synth_results/dse_summary.json` and generate trade-off plots (`bitwidth_vs_accuracy.png`, `bitwidth_vs_resources.png`, `pareto_frontier.png`) in `reports/assets/`.
2. **Synthesizable HLS Core & Verification Flow in `hw/` (Milestones 1 & 4)**:
   - Implement `hw/mlp_accel.cpp` with Datapath and Controller separation:
     - 16-way SIMD MAC compute core (`simd_mac16`) with balanced adder tree reduction and `#pragma HLS INLINE OFF`.
     - Sequential TDM FSM controller: FC1 ($784/16=49$ chunks $\times 64 = 3136$ cycles), FC2 ($64/16=4$ chunks $\times 10 = 40$ cycles), total 3176 compute cycles reusing the single `simd_mac16` core.
     - Sign-bit ReLU activation for FC1 and 10-way parallel Argmax classifier with deterministic tie-breaking.
     - AXI4-Lite control interface (`s_axilite`) and memory-mapped buffers for Zynq PS-PL integration.
   - Implement `hw/tb_mlp.cpp` and `hw/Makefile` enabling native host simulation (`make host-sim`) runnable with `g++` and `-Iinclude_xilinx`.
   - Implement `hw/run_hls.tcl` for Dockerized Vivado HLS batch execution (`csim`, `csynth`, `cosim`).
3. **Comprehensive Defense Documentation & Slides in `reports/`**:
   - `reports/level1_synthesis_report.md`
   - `reports/level2_domain_gap_report.md`
   - `reports/level3_dse_pareto_report.md`
   - `reports/presentation_slides.md`
   - `reports/defense_qa_sheet.md`
   - Strictly aligned with the 8-person team division (Roles A through H) in `hw/智能芯片实践分工.md` and criteria in `hw/智能芯片选题任务书2026.md`.
4. **Milestone 5 Regression Testing & Final Pass**:
   - Run `python3 e2e_tests/run_tests.py` and ensure all 236 tests pass (100%).
   - Run `make host-sim` in `hw/` and ensure native simulation passes with accuracy $\ge 90\%$.

## Coordination Rules
- Keep `BRIEFING.md` and `progress.md` updated in your working directory (`/home/coder/vivado/.agents/orchestrator_3/`).
- Only report victory when all acceptance criteria are met and all tests pass.
