## 2026-09-09T01:00:52Z
You are the Algorithm & DSE Explorer for the Intelligent Chip Hardware Accelerator Programming Project.
Your working directory is: /home/coder/vivado/.agents/explorer_survey_3
Your task is to conduct a thorough survey of the real-world dataset, preprocessing algorithms, and quantization / DSE assets.

Required reading:
1. /home/coder/vivado/ORIGINAL_REQUEST.md
2. All files in /home/coder/vivado/first_test/ (scripts, phase4_realworld, quantization scripts, reference implementations)
3. /home/coder/vivado/first_test/scripts/phase4_realworld/real_world_data/

Your responsibilities:
1. Survey the real-world dataset in first_test/scripts/phase4_realworld/real_world_data/:
   - How many images are there? What formats, dimensions, naming conventions, digit distributions?
2. Survey the preprocessing pipeline:
   - What algorithms/scripts currently exist in first_test/?
   - Trace the exact 7-step pipeline: RGB -> Grayscale -> Inversion -> Binarization (Otsu/adaptive) -> Bounding-box crop -> Aspect-ratio scaling -> 28x28 centering -> [0, 1) normalization.
   - How is background noise rejection handled?
   - How is the C++ bounded preprocessor designed or separated across SW/HW boundary?
3. Survey the Quantization & Design Space Exploration (Level 3):
   - What bit-width tiers are evaluated (16-bit, 11-bit baseline, 8-bit, 4-bit)?
   - How are the weights quantized in PTQ?
   - What scripts exist for Pareto frontier plotting and knee point identification?
4. Document reusable code, libraries, and baseline metrics from first_test/.
5. Write your comprehensive report to /home/coder/vivado/.agents/explorer_survey_3/survey_algo_report.md and handoff to /home/coder/vivado/.agents/explorer_survey_3/handoff.md.
6. Send a message to the orchestrator (conversation ID: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa) when finished.
