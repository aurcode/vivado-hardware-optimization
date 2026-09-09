## 2026-09-09T01:09:59Z

You are the Real-World Preprocessing Implementer (Worker M2) for the Intelligent Chip Hardware Accelerator Programming Project.
Your working directory is: /home/coder/vivado/.agents/worker_m2_1

Required reading:
1. /home/coder/vivado/ORIGINAL_REQUEST.md
2. /home/coder/vivado/.agents/orchestrator_1/PROJECT.md
3. /home/coder/vivado/.agents/explorer_survey_3/survey_algo_report.md
4. /home/coder/vivado/first_test/scripts/phase4_realworld/

MANDATORY INTEGRITY WARNING:
DO NOT CHEAT. All implementations must be genuine. DO NOT hardcode test results, create dummy/facade implementations, or circumvent the intended task. A teamwork_preview_auditor will independently verify your work. Integrity violations WILL be detected and your work WILL be rejected.

Your Scope & Exclusively Owned Files:
- You exclusively own: /home/coder/vivado/preprocessing/ (including preprocess.py, bounded_preproc.cpp, evaluate_domain_gap.py, and real_world_data/).
- Do NOT touch files in hw/ or e2e_tests/.

Your Mission:
Implement, benchmark, and verify the Level 2 real-world handwritten digit preprocessing pipeline:
1. Dataset & Preprocessing Pipeline:
   - Establish `/home/coder/vivado/preprocessing/real_world_data/` containing the 100 real handwriting photos from `first_test/scripts/phase4_realworld/real_world_data/` across all 4 cohorts (c1 clean, c2 lighting/shadows, c3 noise, c4 blank controls).
   - Implement `preprocessing/preprocess.py`:
     - 7-step pipeline: Luma conversion (ITU-R 601-2) -> 4-corner polarity check & inversion -> Otsu adaptive thresholding with 0.7x cutoff -> Active stroke bounding-box crop -> Aspect-ratio bicubic scaling into 20x20 box -> Intensity-weighted Center-of-Mass canvas alignment to (14, 14) on a 28x28 grid -> [0, 1) normalization and fixed-point quantization matching `ap_fixed<11, 3>`.
     - Background noise rejection: reject blank/scratch controls with 100% precision using logit/energy thresholding.
2. Bounded C++ Preprocessing Model:
   - Implement `preprocessing/bounded_preproc.cpp` demonstrating bounded integer/fixed-point image transformations, documenting the SW/HW boundary between ARM PS (image decode, Otsu, scaling) and FPGA PL (deterministic MLP inference).
3. Domain Gap Benchmark & Confusion Matrix:
   - Implement `preprocessing/evaluate_domain_gap.py` evaluating the 100 real-world photo cohort against standard MNIST baseline using `hw/weights.h`.
   - Output the complete 10x10 confusion matrix, per-digit accuracy, precision, recall, and structured explanation of domain gap error sources (e.g. stroke thickness differences, slant, synthetic artifact vs natural pen stroke).
   - Execute the evaluation script and verify all outputs.
4. Write your implementation report in /home/coder/vivado/.agents/worker_m2_1/m2_report.md and a 5-component handoff in /home/coder/vivado/.agents/worker_m2_1/handoff.md.
5. Send a message to the orchestrator (conversation ID: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa) when complete.
