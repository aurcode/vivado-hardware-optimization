# BRIEFING — 2026-09-09T01:10:00Z

## Mission
Conduct a thorough, precise specification survey across Level 1, Level 2, Level 3, project deliverables/defense, grading rubrics, and Roles A-H分工 for the Intelligent Chip Hardware Accelerator Programming Project.

## 🔒 My Identity
- Archetype: Specification Miner
- Roles: Specification Mining, Requirement Analysis, Hardware/Software Interface & Rubric Extraction
- Working directory: /home/coder/vivado/.agents/spec_miner_survey_1
- Original parent: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa
- Milestone: Phase 0 Specification Survey & Requirement Extraction

## 🔒 Key Constraints
- Sole job is to discover and document features by probing authoritative specification; do NOT implement anything.
- Do NOT skip any feature, no matter how obscure.
- Output detailed report to /home/coder/vivado/.agents/spec_miner_survey_1/survey_spec_report.md.
- Output 5-component handoff report to /home/coder/vivado/.agents/spec_miner_survey_1/handoff.md.
- Send completion message to parent (3afaf208-c1d9-4190-b76f-3f61e55ad2aa) via send_message.

## Current Parent
- Conversation ID: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa
- Updated: 2026-09-09T01:07:47Z

## Task Summary
- **What to build**: Comprehensive specification survey document `survey_spec_report.md` covering all 3 project levels, grading rubrics, acceptance criteria, and role assignments A through H.
- **Success criteria**: Every requirement, formula, bitwidth, interface protocol, testcase, artifact requirement, rubric weight, and role boundary is extracted and categorized.
- **Interface contracts**: Specified in ORIGINAL_REQUEST.md and 智能芯片选题任务书2026.md.
- **Code layout**: Specified in ORIGINAL_REQUEST.md.

## Key Decisions Made
- Validated baseline 784-64-10 MLP floating/fixed model on 100 test samples in `hw/test_inputs.h`, confirming exact 97.00% accuracy.
- Cataloged complete 100-point course breakdown + 10-point Level 3 bonus rubric in `survey_spec_report.md`.
- Mapped all 8 project roles (A through H) with specific deliverables, verification criteria, and defense questions.
- Formatted Discovered Features and Edge Cases per Specification Miner schema.

## Artifact Index
- `/home/coder/vivado/.agents/spec_miner_survey_1/survey_spec_report.md` — Full specification survey report
- `/home/coder/vivado/.agents/spec_miner_survey_1/handoff.md` — 5-component handoff report
