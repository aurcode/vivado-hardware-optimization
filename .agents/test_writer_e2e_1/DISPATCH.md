## 2026-09-09T01:10:00Z
You are the E2E Test Writer for the Intelligent Chip Hardware Accelerator Programming Project.
Your working directory is: /home/coder/vivado/.agents/test_writer_e2e_1

Required reading:
1. /home/coder/vivado/ORIGINAL_REQUEST.md
2. /home/coder/vivado/.agents/orchestrator_1/PROJECT.md
3. /home/coder/vivado/.agents/spec_miner_survey_1/survey_spec_report.md
4. /home/coder/vivado/hw/test_inputs.h

Your Scope & Exclusively Owned Files:
- You exclusively own: /home/coder/vivado/e2e_tests/ (all test files and harnesses), /home/coder/vivado/TEST_INFRA.md, and /home/coder/vivado/TEST_READY.md.
- You must NOT modify any implementation code in hw/ or preprocessing/.

Your Mission:
Design and implement a comprehensive, requirement-driven, opaque-box E2E test suite covering Features 1-22 documented in PROJECT.md:
1. Tier 1: Feature Coverage (>=5 test cases per feature covering isolated happy paths and baseline expectations).
2. Tier 2: Boundary & Corner Cases (>=5 test cases per feature: all-zero inputs, maximum-intensity inputs, negative values, clipping/saturation, OOD inputs, blank images).
3. Tier 3: Cross-Feature Interactions (pairwise combinations: preprocessing -> inference, noise rejection on blank samples, quantization scale vs hardware fixed-point match, AXI4-Lite handshake sequence).
4. Tier 4: Real-World Workload Scenarios (end-to-end photo recognition through preprocessing and 784-64-10 inference across clean, shadow, and noise cohorts; background rejection verification).
5. Build an executable test runner e2e_tests/test_runner.py with clean CLI flags (e.g. `--tier 1`, `--tier 2`, `--tier 3`, `--tier 4`, `--all`) and standard exit codes (0 on success, 1 on failure).
6. Create /home/coder/vivado/TEST_INFRA.md following the template in PROJECT.md.
7. Once the test framework and test cases are verified, publish /home/coder/vivado/TEST_READY.md.
8. Document all findings and test suite architecture in /home/coder/vivado/.agents/test_writer_e2e_1/handoff.md and notify the orchestrator (conversation ID: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa).
