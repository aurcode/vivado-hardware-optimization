# Dispatch: Explorer HW 1

Task: Investigate `hw/` hardware accelerator files, specifications, and requirements.
Examine:
- `hw/weights.h`, `hw/test_inputs.h`, `hw/mlp_accel.h`
- Check what exists and what is needed for `hw/mlp_accel.cpp`:
  - 16-way SIMD MAC compute core (`simd_mac16`) with balanced adder tree reduction and `#pragma HLS INLINE OFF`.
  - Sequential TDM FSM controller: FC1 (784/16=49 chunks x 64 = 3136 cycles), FC2 (64/16=4 chunks x 10 = 40 cycles), total 3176 compute cycles reusing single simd_mac16 core.
  - Sign-bit ReLU activation for FC1 and 10-way parallel Argmax classifier with deterministic tie-breaking.
  - AXI4-Lite control interface (`s_axilite`) and memory-mapped buffers for Zynq PS-PL integration.
- Check what is needed for `hw/tb_mlp.cpp` and `hw/Makefile` enabling native host simulation (`make host-sim`) runnable with `g++` and `-Iinclude_xilinx`.
- Check what is needed for `hw/run_hls.tcl` for Dockerized Vivado HLS batch execution (`csim`, `csynth`, `cosim`).
- Check any existing implementations or artifacts in `first_test/` or previous work.

Write your findings and actionable implementation plan to `/home/coder/vivado/.agents/explorer_hw_1/handoff.md`.
Report back via send_message.

## 2026-09-09T01:48:31Z
Investigate the hardware accelerator status in `hw/`:
1. Check `hw/weights.h`, `hw/test_inputs.h`, `hw/mlp_accel.h`.
2. Check whether `hw/mlp_accel.cpp`, `hw/tb_mlp.cpp`, `hw/Makefile`, `hw/run_hls.tcl` exist or need implementation/modification.
3. Verify requirements for `mlp_accel.cpp`:
   - 16-way SIMD MAC compute core (`simd_mac16`) with balanced adder tree reduction and `#pragma HLS INLINE OFF`.
   - Sequential TDM FSM controller: FC1 (784/16=49 chunks x 64 = 3136 cycles), FC2 (64/16=4 chunks x 10 = 40 cycles), total 3176 compute cycles reusing single simd_mac16 core.
   - Sign-bit ReLU activation for FC1 and 10-way parallel Argmax classifier with deterministic tie-breaking.
   - AXI4-Lite control interface (`s_axilite`) and memory-mapped buffers for Zynq PS-PL integration.
4. Verify requirements for `hw/tb_mlp.cpp` and `hw/Makefile`:
   - Fast host-level simulation runnable with native `g++` via `make host-sim`, using `-Iinclude_xilinx`.
   - Check if `include_xilinx/` exists and has `ap_fixed.h` mock/header.
5. Verify requirements for `hw/run_hls.tcl` for Dockerized Vivado HLS batch execution (`csim`, `csynth`, `cosim`).
6. Check `first_test/` or any other directories for existing implementations, reference code, or synthesis logs.

Write a thorough analysis and actionable implementation specification in `/home/coder/vivado/.agents/explorer_hw_1/handoff.md`.
Send a completion message back to parent when finished.
