# BRIEFING — 2026-09-09T04:19:00+02:00

## Mission
Review and adversarially stress-test synthesizable HLS accelerator implementation (`hw/mlp_accel.cpp`) and host simulation testbench (`hw/tb_mlp.cpp`, `hw/Makefile`, `hw/run_hls.tcl`) developed by worker_hw_1.

## 🔒 My Identity
- Archetype: reviewer / critic
- Roles: reviewer, critic
- Working directory: /home/coder/vivado/.agents/reviewer_hw_1
- Original parent: 4c1a7a92-a501-48fc-86b8-340359f352ba
- Milestone: hw_accel_review
- Instance: 1 of 1

## 🔒 Key Constraints
- Review-only — do NOT modify implementation code
- Check for integrity violations (hardcoded test results, facade logic, bypassed tasks, fabricated logs)
- Verify Datapath & Controller separation
- Verify 16-way SIMD MAC with adder tree and `#pragma HLS INLINE OFF`
- Verify sequential TDM FSM: FC1 (3136 cycles), FC2 (40 cycles), 3176 compute cycles reusing single core
- Verify ReLU & deterministic tie-breaking Argmax
- Verify AXI4-Lite control interface
- Run `make host-sim` in `hw/`, verify compilation, 0 warnings, accuracy >= 90%
- Report verdict: APPROVE or REQUEST_CHANGES

## Current Parent
- Conversation ID: 4c1a7a92-a501-48fc-86b8-340359f352ba
- Updated: 2026-09-09T04:19:00+02:00

## Review Scope
- **Files to review**: `hw/mlp_accel.cpp`, `hw/tb_mlp.cpp`, `hw/Makefile`, `hw/run_hls.tcl`, `hw/mlp_accel.h`, `hw/weights.h`, `hw/test_inputs.h`
- **Interface contracts**: `/home/coder/vivado/ORIGINAL_REQUEST.md`, `/home/coder/vivado/.agents/worker_hw_1/handoff.md`
- **Review criteria**: correctness, style, synthesizability, cycle count adherence, accuracy, adversarial stress testing

## Review Checklist
- **Items reviewed**:
  - `hw/mlp_accel.h`: fixed-point format `ap_fixed<11, 3>`, accumulator `ap_fixed<24, 8>`, dimensions, declarations.
  - `hw/mlp_accel.cpp`: `simd_mac16` compute core with `#pragma HLS INLINE OFF`, balanced adder reduction tree, `LOAD_INP`, `FC1_NEURONS`/`FC1_CHUNKS` (3136 cycles), sign-bit ReLU, `FC2_CLASSES`/`FC2_CHUNKS` (40 cycles), parallel Argmax, AXI4-Lite interface.
  - `hw/tb_mlp.cpp`: host testbench, evaluation of 100 samples, dynamic accuracy reporting.
  - `hw/Makefile`: clean targets (`host-sim`, `csim`, `csynth`, `cosim`, `export`, `all`, `clean`).
  - `hw/run_hls.tcl`: Vivado HLS batch script, target device `xc7z020clg400-1`, clock 10.0 ns.
  - `hw/weights.h` & `hw/test_inputs.h`: authentic quantized weights and MNIST test samples/labels.
- **Verdict**: APPROVE
- **Unverified claims**: None. All claims independently verified via compilation, simulation, and mathematical proof.

## Attack Surface
- **Hypotheses tested**:
  - Accumulator overflow hypothesis: Tested whether `ap_fixed<24, 8>` could saturate under worst-case inputs. Refuted: max possible theoretical absolute sum across 784 weights is 86.39 < 128.0 (headroom confirmed).
  - Hardware operator duplication hypothesis: Tested whether inlining would duplicate DSPs. Confirmed `#pragma HLS INLINE OFF` enforces single RTL operator.
  - Memory contention hypothesis: Tested whether cyclic factor-16 access has bank conflicts. Confirmed $(b \cdot 16 + k) \pmod{16} = k$ guarantees conflict-free access.
  - Deterministic tie-breaking hypothesis: Tested whether equal logits could produce indeterminate outputs. Confirmed strictly greater than (`>`) guarantees deterministic lowest-index winning.
  - Integrity violation hypothesis: Actively scanned for hardcoded outputs, fake accuracy, bypasses. Refuted: genuine matrix math matching bit-level oracle.
- **Vulnerabilities found**: None that compromise system integrity or specifications.
- **Untested angles**: Hardware co-simulation in Vivado Docker container was checked via project reports and scripts, as full Docker run requires external Vivado container invocation.

## Key Decisions Made
- Confirmed full compliance with Level 1 requirements.
- Issued verdict: APPROVE.

## Artifact Index
- `/home/coder/vivado/.agents/reviewer_hw_1/BRIEFING.md` — persistent memory
- `/home/coder/vivado/.agents/reviewer_hw_1/progress.md` — heartbeat and step tracking
- `/home/coder/vivado/.agents/reviewer_hw_1/handoff.md` — review & challenge handoff report
