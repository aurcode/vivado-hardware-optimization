# Dispatch: Worker HW 1

Role: teamwork_preview_worker (Hardware Implementation Specialist)
Working Directory: /home/coder/vivado/.agents/worker_hw_1
Exclusive File Ownership:
- `hw/mlp_accel.cpp`
- `hw/tb_mlp.cpp`
- `hw/Makefile`
- `hw/run_hls.tcl`

MANDATORY INTEGRITY WARNING:
DO NOT CHEAT. All implementations must be genuine. DO NOT hardcode test results, create dummy/facade implementations, or circumvent the intended task. A teamwork_preview_auditor will independently verify your work. Integrity violations WILL be detected and your work WILL be rejected.

Mission:
Implement the synthesizable HLS accelerator core and host simulation flow in `hw/`:
1. `hw/mlp_accel.cpp`:
   - 16-way SIMD MAC compute core (`simd_mac16`) with 4-stage balanced binary adder tree reduction and `#pragma HLS INLINE OFF`.
   - Sequential TDM FSM controller: FC1 ($784/16=49$ chunks $\times 64 = 3136$ cycles), FC2 ($64/16=4$ chunks $\times 10 = 40$ cycles), total 3176 compute cycles reusing single `simd_mac16` core.
   - Local on-chip buffers partitioned appropriately (`cyclic factor=16` for input buffer and hidden activation buffer).
   - Sign-bit ReLU activation for FC1 (`acc < 0 ? 0 : (custom_data_t)acc`).
   - 10-way parallel Argmax classifier with deterministic tie-breaking (strictly greater, lowest index wins).
   - AXI4-Lite control interface (`s_axilite` bundle `CTRL_BUS` for return, `input_img`, `pred_digit`).
2. `hw/tb_mlp.cpp`:
   - Verification testbench iterating through 100 samples in `hw/test_inputs.h`.
   - Calls `mlp_accel()`, compares prediction against `test_labels`, computes measured accuracy.
   - Exits 0 if accuracy $\ge 90\%$, exits 1 otherwise.
3. `hw/Makefile`:
   - Fast host-level simulation (`make host-sim`) using `g++ -O0 -Wall -Wno-unknown-pragmas -Wno-unused-parameter -std=c++11 -I. -I../include_xilinx`.
   - Dockerized Vivado HLS targets: `csim`, `csynth`, `cosim`, `export`, `all`, `clean`.
4. `hw/run_hls.tcl`:
   - Automated batch script for Vivado HLS 2018.3 targeting `xc7z020clg400-1` at 10.0 ns (100 MHz).
   - Supports `csim`, `csynth`, `cosim`, `export`, and `all`.

Verification:
- Run `cd /home/coder/vivado/hw && make host-sim`. Ensure it compiles cleanly and achieves $\ge 90\%$ accuracy (expected 97% or 98%).

Write your completion report to `/home/coder/vivado/.agents/worker_hw_1/handoff.md`.
Report back via send_message.

## 2026-09-09T01:53:29Z
Task assignment confirmed:
Implement hw/mlp_accel.cpp, hw/tb_mlp.cpp, hw/Makefile, hw/run_hls.tcl according to explorer_hw_1/handoff.md and DISPATCH.md.
Verify via `make host-sim` (accuracy >= 90%).
Generate handoff.md and report to parent.

