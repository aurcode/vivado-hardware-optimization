# BRIEFING — 2026-09-09T03:53:00Z

## Mission
Investigate hardware accelerator status in hw/, verify requirements, examine existing artifacts, and produce an actionable implementation spec.

## 🔒 My Identity
- Archetype: explorer
- Roles: hardware investigator, specification analyst
- Working directory: /home/coder/vivado/.agents/explorer_hw_1
- Original parent: 4c1a7a92-a501-48fc-86b8-340359f352ba
- Milestone: M1 Hardware Investigation

## 🔒 Key Constraints
- Read-only investigation — do NOT implement source code directly (only write in .agents/explorer_hw_1)
- Produce structured 5-component handoff report
- Accurate citations of files, lines, commands, tool results

## Current Parent
- Conversation ID: 4c1a7a92-a501-48fc-86b8-340359f352ba
- Updated: 2026-09-09T01:48:31Z

## Investigation State
- **Explored paths**:
  - `hw/weights.h`: Verified 784-64-10 bias-free weights in `ap_fixed<11, 3, AP_RND, AP_SAT>` (50,816 parameters, 69.87 KB).
  - `hw/test_inputs.h`: Verified 100 test samples and labels (97.00% baseline accuracy).
  - `hw/mlp_accel.h`: Verified dimensions, types, and function signatures.
  - `hw/mlp_accel.cpp`, `hw/tb_mlp.cpp`, `hw/Makefile`, `hw/run_hls.tcl`: Identified as missing; formulated complete drop-in implementations.
  - `include_xilinx/`: Verified genuine Xilinx HLS C++ headers (`ap_fixed.h`, `ap_int.h`, etc.).
  - `first_test/`: Inspected prior 3-layer prototype; identified that `#pragma HLS INLINE` caused DSP and BRAM overutilization (48 DSPs, 142 BRAMs), proving `#pragma HLS INLINE OFF` is mandatory.
  - `e2e_tests/run_tests.py`: Executed and verified 100% pass rate (236/236 tests).
  - Docker environment: Verified `fpgatools/vivado:latest` present locally with `xc7z020clg400-1` support and AR-76960 patch.
- **Key findings**:
  - Hardware reuse requirement: Exactly one 16-way SIMD MAC core (`simd_mac16`) with balanced binary adder reduction tree and `#pragma HLS INLINE OFF`.
  - Sequential TDM FSM: FC1 (64 x 49 = 3136 cycles) + FC2 (10 x 4 = 40 cycles) = 3176 total compute cycles.
  - Complete drop-in code specifications created in `handoff.md`.
- **Unexplored areas**: None within the scope of hardware accelerator investigation.

## Key Decisions Made
- Confirmed `#pragma HLS INLINE OFF` is required for single instance `simd_mac16` reuse.
- Formulated `-O0` host compiler flag recommendation in `Makefile` to prevent slow template instantiation of 129,216 `ap_fixed` float constants during native host simulation.

## Artifact Index
- handoff.md — Complete 5-component hardware investigation report and drop-in code specification for `mlp_accel.cpp`, `tb_mlp.cpp`, `Makefile`, and `run_hls.tcl`.
- progress.md — Liveness and execution progress tracker.
