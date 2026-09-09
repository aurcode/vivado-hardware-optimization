# BRIEFING — 2026-09-09T01:10:00Z

## Mission
Implement and verify the complete Level 1 synthesizable HLS accelerator core (784-64-10 MLP without bias) using a single 16-way SIMD MAC datapath with TDM FSM controller, achieving high accuracy (>=90%), meeting timing (slack > 0 at 10.0 ns), and strict resource bounds (DSP <= 32, BRAM <= 8, LUT <= 10,000) on xc7z020clg400-1.

## 🔒 My Identity
- Archetype: worker_m1
- Roles: implementer, qa, specialist
- Working directory: /home/coder/vivado/.agents/worker_m1_1
- Original parent: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa
- Milestone: Level 1 HLS Accelerator Core

## 🔒 Key Constraints
- Exclusively owned files: /home/coder/vivado/hw/mlp_accel.h, /home/coder/vivado/hw/mlp_accel.cpp, /home/coder/vivado/hw/tb_mlp.cpp, /home/coder/vivado/hw/run_hls.tcl, /home/coder/vivado/hw/Makefile.
- Do NOT touch files in preprocessing/ or e2e_tests/.
- DO NOT CHEAT. Genuine implementation only. No hardcoded test results.
- Fixed-point format: ap_fixed<11, 3, AP_RND, AP_SAT>.
- Single 16-way SIMD MAC core (`simd_mac16`) with balanced adder tree reduction and `#pragma HLS INLINE OFF`.
- TDM FSM controller reusing the exact same MAC core for FC1 and FC2.
- Sign-bit ReLU activation for FC1 output (`if (!val[10]) ... else 0`).
- Parallel Argmax over 10 class scores with deterministic tie-breaking.
- AXI4-Lite control interface (`s_axilite`) and memory-mapped buffers.
- Verification targets: `make host-sim` (accuracy >= 90%), Vivado HLS flow (csim, csynth, cosim) via Docker `fpgatools/vivado:latest`.
- Timing: slack > 0 at 100 MHz (10.0 ns) on `xc7z020clg400-1`.
- Resource bounds: DSP <= 32, BRAM <= 8, LUT <= 10,000.

## Current Parent
- Conversation ID: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa
- Updated: 2026-09-09T01:10:00Z

## Task Summary
- **What to build**: Synthesizable MLP accelerator HLS code, testbench, Makefile, and Vivado HLS TCL script.
- **Success criteria**: Accuracy >= 90% in host simulation and HLS csim/cosim, passing csynth with DSP <= 32, BRAM <= 8, LUT <= 10,000, slack > 0.
- **Interface contracts**: /home/coder/vivado/.agents/orchestrator_1/PROJECT.md
- **Code layout**: /home/coder/vivado/hw/

## Key Decisions Made
- [TBD] Initial analysis pending.

## Artifact Index
- /home/coder/vivado/.agents/worker_m1_1/DISPATCH.md — Assignment instructions
- /home/coder/vivado/.agents/worker_m1_1/progress.md — Liveness and progress heartbeat
- /home/coder/vivado/.agents/worker_m1_1/m1_report.md — Implementation & verification report
- /home/coder/vivado/.agents/worker_m1_1/handoff.md — 5-component handoff report

## Change Tracker
- **Files modified**: None yet
- **Build status**: Untested
- **Pending issues**: None

## Quality Status
- **Build/test result**: Not run yet
- **Lint status**: Not run yet
- **Tests added/modified**: Pending

## Loaded Skills
- None
