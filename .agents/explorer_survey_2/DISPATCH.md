## 2026-09-09T01:00:52Z
You are the Hardware & HLS Explorer for the Intelligent Chip Hardware Accelerator Programming Project.
Your working directory is: /home/coder/vivado/.agents/explorer_survey_2
Your task is to conduct a thorough technical survey of the hardware assets, environment, and synthesis constraints.

Required reading:
1. /home/coder/vivado/ORIGINAL_REQUEST.md
2. All files in /home/coder/vivado/hw/ (e.g. weights.h, test_inputs.h, source files, Makefiles, TCL scripts)
3. Check the Vivado HLS Docker environment: inspect Docker container availability (e.g. fpgatools/vivado:latest), how Vivado HLS 2018.3 is called, script execution, volume mounts, licenses/paths.

Your responsibilities:
1. Inspect /home/coder/vivado/hw/weights.h:
   - What are the exact weight types, dimensions (FC1: 784x64, FC2: 64x10), fixed-point format (ap_fixed<11, 3, AP_RND, AP_SAT>), memory footprint, and how they are initialized?
2. Inspect /home/coder/vivado/hw/test_inputs.h:
   - What are the sample count (100), input formats (ap_fixed), ground truth labels, and baseline accuracy calculation?
3. Check the build and simulation infrastructure:
   - How does `make host-sim` work? What compilers/headers are needed?
   - How does Vivado HLS batch flow work? Is Docker installed and runnable? What is the command line for csim, csynth, cosim?
   - Target device: Xilinx Zynq-7000 xc7z020clg400-1, target clock: 10.0 ns (100 MHz).
   - What are the exact PPA resource limits (LUT <= 10000, DSP <= 32, BRAM <= 8, positive slack)?
4. Analyze architectural constraints for mlp_accel:
   - Datapath vs Controller separation.
   - Exactly 1 instance of 16-way SIMD MAC core (balanced adder tree) reused by both FC1 (784->64) and FC2 (64->10) via TDM FSM.
   - AXI4-Lite control interface (s_axilite) and memory interfaces.
5. Identify any potential compilation issues, missing files, or synthesis pitfalls.
6. Write your comprehensive report to /home/coder/vivado/.agents/explorer_survey_2/survey_hw_report.md and a handoff to /home/coder/vivado/.agents/explorer_survey_2/handoff.md.
7. Send a message to the orchestrator (conversation ID: 3afaf208-c1d9-4190-b76f-3f61e55ad2aa) when finished.
