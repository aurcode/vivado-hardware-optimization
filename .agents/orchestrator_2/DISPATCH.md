## 2026-09-09T01:36:30Z

You are the Project Orchestrator for the Intelligent Chip Hardware Accelerator Programming Project at /home/coder/vivado.
Your working directory is /home/coder/vivado/.agents/orchestrator_2.

Authoritative Request:
Read /home/coder/vivado/ORIGINAL_REQUEST.md (specifically the latest follow-up request).

The user requires:
1. Generate the 5 comprehensive engineering reports, synthesis analysis, real-world domain gap documentation, quantization DSE analysis, and team defense presentation materials in `reports/`:
   - `reports/level1_synthesis_report.md`
   - `reports/level2_domain_gap_report.md`
   - `reports/level3_dse_pareto_report.md`
   - `reports/presentation_slides.md`
   - `reports/defense_qa_sheet.md`
2. Strictly align with the 8-person team roles (A through H) in `hw/智能芯片实践分工.md` and criteria in `hw/智能芯片选题任务书2026.md`.
3. Directly reference the verified 784-64-10 network and `ap_fixed<11, 3, AP_RND, AP_SAT>` numerical format in `hw/weights.h`.
4. Include quantitative backing: PPA tables on Zynq-7000 (`xc7z020clg400-1`) at 100 MHz with hardware reuse proof (`#pragma HLS INLINE OFF`), 7-step preprocessing dataflow, real-world 10x10 confusion matrix, negative noise rejection, multi-tier PTQ evaluation (16-bit, 11-bit baseline, 8-bit, 4-bit) with mathematical knee point proof, and Pareto curves.
5. Provide complete slide deck and defense Q&A sheets for all roles A~H.

Prior project assets and progress:
- E2E tests and oracle in `e2e_tests/` (all 236 tests pass, see `TEST_READY.md`).
- Hardware headers and specifications in `hw/`.
- Preprocessing and domain gap evaluations in `preprocessing/` (and `.agents/worker_m2_1/m2_report.md`).
- Prior exploration notes and architecture inventory in `.agents/orchestrator_1/PROJECT.md` and `first_test/`.

Instructions:
- Maintain your persistent working memory in `/home/coder/vivado/.agents/orchestrator_2/BRIEFING.md` and heartbeat in `/home/coder/vivado/.agents/orchestrator_2/progress.md`.
- Dispatch specialized workers/reviewers as needed to produce, rigorously verify, and validate the 5 deliverable reports.
- Ensure all acceptance criteria are met and all tests pass before reporting completion to the Sentinel.
