# BRIEFING — 2026-09-09T01:00:00Z

## Mission
Lead and orchestrate the full execution of the Intelligent Chip Hardware Accelerator Programming Project (784-64-10 MLP accelerator, SIMD MAC reuse, simulation/synthesis, real-world preprocessing/domain gap, quantization DSE, and defense reports).

## 🔒 My Identity
- Archetype: Project Orchestrator
- Roles: orchestrator, user_liaison, human_reporter, successor
- Working directory: /home/coder/vivado/.agents/orchestrator_1
- Original parent: parent
- Original parent conversation ID: ab80de44-7686-459b-8cb2-6d2120f70c86

## 🔒 My Workflow
- **Pattern**: Project Pattern (Implementation Track + E2E Testing Track)
- **Scope document**: /home/coder/vivado/PROJECT.md
1. **Decompose**: Survey scope with Explorers -> compile PROJECT.md with Feature Inventory -> Milestone Decomposition & Interface Contracts
2. **Dispatch & Execute**:
   - **Delegate (sub-orchestrator)**: Delegate milestones to sub-orchestrators
   - **Direct (iteration loop)**: Explorer -> Worker -> Reviewers -> Challengers -> Forensic Auditor -> Gate
3. **On failure** (in this order):
   - Retry: nudge stuck agent or re-send task
   - Replace: spawn fresh agent with partial progress
   - Skip: proceed without (only if non-critical)
   - Redistribute: split stuck agent's remaining work
   - Redesign: re-partition decomposition
   - Escalate: report to parent (sub-orchestrators only, last resort)
4. **Succession**: At 16 spawns, write handoff.md, spawn successor
- **Work items**:
  1. Survey & Map Scope [in-progress]
  2. E2E Testing Track: Harness & Test Suite [pending]
  3. Milestone 1: Synthesizable HLS Core & Sim/Synth [pending]
  4. Milestone 2: Preprocessing & Domain Gap [pending]
  5. Milestone 3: Quantization & DSE [pending]
  6. Milestone 4: Reports & Presentation Defense [pending]
  7. Final Milestone: E2E Verification & Adversarial Hardening [pending]
- **Current phase**: 0 (Survey)
- **Current focus**: Surveying reference materials, existing assets in hw/ and first_test/

## 🔒 Key Constraints
- NEVER write, modify, or create source code files directly.
- NEVER run build/test commands yourself — require workers to do so.
- NEVER investigate or explore the problem at the code level — dispatch Explorers for technical investigation.
- Always enforce Forensic Auditor zero-tolerance integrity check (binary veto).
- Never reuse a subagent after it has delivered its handoff — always spawn fresh.

## Current Parent
- Conversation ID: ab80de44-7686-459b-8cb2-6d2120f70c86
- Updated: 2026-09-09T01:00:00Z

## Key Decisions Made
- Selected Project Pattern with dual track: Implementation Track + E2E Testing Track.
- Commencing Survey Phase with 3 Explorers / Spec Miners.

## Team Roster
| Agent | Type | Work Item | Status | Conv ID |
|-------|------|-----------|--------|---------|
| spec_miner_survey_1 | teamwork_preview_spec_miner | Survey task specs, rubrics, roles A-H | completed | f8563023-11e6-43de-9970-be6a6d9a224d |
| explorer_survey_2 | teamwork_preview_explorer | Survey hw/, weights, test_inputs, Vivado Docker | completed | 449079bd-5483-416e-8f3e-41133d622790 |
| explorer_survey_3 | teamwork_preview_explorer | Survey first_test/, real-world dataset, PTQ/DSE | completed | ec2dfc5d-cc42-45fa-8781-55cce481004d |
| test_writer_e2e_1 | teamwork_preview_test_writer | E2E Testing Track: Tiers 1-4 test suite & TEST_READY.md | completed | b063fd16-84ae-4896-9f7b-d3c72fa9793a |
| worker_m1_1 | teamwork_preview_worker | M1: Synthesizable HLS Core, host-sim & run_hls.tcl | in-progress | 157e730b-977b-4ee9-81b2-518b8dc54800 |
| worker_m2_1 | teamwork_preview_worker | M2: Preprocessing pipeline, 100-photo benchmark, confusion matrix | completed | 440aec21-efb1-47ce-b8cd-74363c6ea483 |
| worker_m3_1 | teamwork_preview_worker | M3: Quantization PTQ sweep, knee point proof, Pareto curves | in-progress | 19203656-8425-41b4-bd46-bb912c91dd46 |

## Succession Status
- Succession required: no
- Spawn count: 7 / 16
- Pending subagents: 157e730b-977b-4ee9-81b2-518b8dc54800, 19203656-8425-41b4-bd46-bb912c91dd46
- Predecessor: none
- Successor: not yet spawned

## Active Timers
- Heartbeat cron: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa/task-18
- Safety timer: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa/task-96
- On succession: kill all timers before spawning successor
- On context truncation: run manage_task(Action="list") — re-create if missing

## Artifact Index
- /home/coder/vivado/ORIGINAL_REQUEST.md — original user request
- /home/coder/vivado/.agents/orchestrator_1/DISPATCH.md — dispatch prompt
- /home/coder/vivado/.agents/orchestrator_1/BRIEFING.md — persistent working memory
- /home/coder/vivado/.agents/orchestrator_1/progress.md — liveness heartbeat and milestone tracking
