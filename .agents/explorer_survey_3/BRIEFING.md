# BRIEFING — 2026-09-09T03:04:30+02:00

## Mission
Conduct a thorough survey of the real-world dataset, preprocessing algorithms, and quantization / DSE assets in first_test/ and related repositories.

## 🔒 My Identity
- Archetype: explorer
- Roles: Algorithm & DSE Explorer
- Working directory: /home/coder/vivado/.agents/explorer_survey_3
- Original parent: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa
- Milestone: Survey Phase

## 🔒 Key Constraints
- Read-only investigation — do NOT implement
- Survey real-world dataset in first_test/scripts/phase4_realworld/real_world_data/
- Survey preprocessing pipeline (7-step pipeline, noise rejection, C++ bounded SW/HW design)
- Survey Quantization & DSE (Level 3: bit-width tiers, PTQ, Pareto frontier, knee point identification)
- Write comprehensive report to survey_algo_report.md and handoff.md in working directory
- Notify parent orchestrator upon completion

## Current Parent
- Conversation ID: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa
- Updated: 2026-09-09T03:04:30+02:00

## Investigation State
- **Explored paths**:
  - `/home/coder/vivado/ORIGINAL_REQUEST.md`
  - `/home/coder/vivado/hw/智能芯片选题任务书2026.md`
  - `/home/coder/vivado/hw/智能芯片实践分工.md`
  - `/home/coder/vivado/hw/weights.h` & `/home/coder/vivado/hw/test_inputs.h`
  - `first_test/` (mlp.cpp, mlp.hpp, tb_mlp.cpp, run_hls.tcl, reports/)
  - `first_test/scripts/phase4_realworld/` (generate_dataset.py, preprocess.py, evaluate_domain_gap.py, export_realworld_vectors.py, real_world_data/)
  - `first_test/scripts/phase1_ai/` (models.py, ptq_sweep.py, export_vectors.py)
  - `first_test/scripts/phase5_dse/` (generate_dse_headers.py, parse_and_plot_pareto.py, run_dse_hls.tcl, src/, proj_*/ reports)
- **Key findings**:
  - Real-world dataset contains exactly 100 images: 128x128 8-bit grayscale PNGs across 4 cohorts (c1: 30 clean, c2: 30 lighting/shadow, c3: 30 noise, c4: 10 blank controls). Digits 0-9 each have 9 images.
  - Preprocessing pipeline executes exact 7-step sequence: Luma conversion -> 4-corner background inversion -> Otsu adaptive thresholding (0.7x cutoff noise suppression) -> ROI bounding-box crop (0.5x threshold) -> Aspect-ratio preserving bicubic resize to 20x20 -> Intensity Center-of-Mass translation & canvas roll to 28x28 -> [0, 1) normalization and fixed-point quantization.
  - Background noise rejection: Corner inversion handles bright background; Otsu rejects shadows/gradients; sub-threshold cutoff zeroes low-intensity texture; logit confidence thresholding (< 1.0) achieves 100% rejection on blank/scratch controls.
  - SW/HW partitioning: Complex file I/O, format decoding, Otsu histogramming, bicubic interpolation, and CoM shifts are assigned to Host CPU/PS software; fixed-point tensor inference is mapped to PL hardware accelerator.
  - DSE & Quantization: Task book identifies 11-bit (`ap_fixed<11, 3>`) as the saturation knee point (98.00% accuracy on hw/test_inputs.h, 0.00% drop vs 16-bit). Below 8-bit accuracy degrades, and 4-bit suffers catastrophic cliff (28.00% without QAT).
  - Synthesis reports from XC7Z020 in first_test show PPA across 16b SIMD16 (8,173 cyc, 142 BRAM, 48 DSP), 8b SIMD16 (8,782 cyc, 77 BRAM, 24 DSP), 8b SIMD32 (5,578 cyc, 100 BRAM, 48 DSP), and 4b SIMD16 (8,782 cyc, 37 BRAM, 24 DSP).
  - Top-level homework requirement uses 784-64-10 architecture (weights in hw/weights.h) rather than 784-128-64-10, meaning parameter count is 50,816 vs 109,184, significantly easing BRAM utilization.
- **Unexplored areas**: None. All survey objectives investigated.

## Key Decisions Made
- Validated real-world dataset directly using PIL / numpy script.
- Verified 784-64-10 baseline accuracy with NumPy bit-accurate emulation of `ap_fixed<11, 3>` achieving 98.00% on `hw/test_inputs.h`.
- Evaluated real-world cohorts on 784-64-10 yielding 90.0% (c1), 80.0% (c2), 83.3% (c3), and 100% OOD rejection (c4).
- Extracted exact synthesis metrics from physical Vivado HLS report files in `proj_*`.

## Artifact Index
- `/home/coder/vivado/.agents/explorer_survey_3/DISPATCH.md` — Task request record
- `/home/coder/vivado/.agents/explorer_survey_3/BRIEFING.md` — Working memory & state tracker
- `/home/coder/vivado/.agents/explorer_survey_3/progress.md` — Milestone progress tracker
- `/home/coder/vivado/.agents/explorer_survey_3/survey_algo_report.md` — Comprehensive Algorithm, Preprocessing & DSE Survey Report
- `/home/coder/vivado/.agents/explorer_survey_3/handoff.md` — Structured 5-component handoff report
