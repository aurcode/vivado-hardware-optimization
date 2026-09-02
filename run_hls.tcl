# ==============================================================================
# Vivado HLS 2018.3 Build Automation Script
#
# Specifications:
# - Project Name:         test
# - Top-Level Function:   mlp_accel
# - Design Files:         mlp.cpp, mlp.hpp
# - Testbench File:       tb_mlp.cpp
# - Solution Name:        solution1
# - Target Device Part:   xc7z020clg400-1
# ==============================================================================

# Determine flow stage from command-line argument:
# When invoked as: vivado_hls -f run_hls.tcl [stage]
# argv[0] = -f, argv[1] = run_hls.tcl, argv[2] = stage
set stage "all"
if {[info exists argv]} {
    if {[llength $argv] >= 3} {
        set stage [lindex $argv 2]
    } elseif {[llength $argv] == 1} {
        set stage [lindex $argv 0]
    }
}

puts "=================================================================="
puts "  Vivado HLS Build Automation - Target Stage: $stage"
puts "=================================================================="

# 1. Project Configuration
open_project -reset test
set_top mlp_accel

# 2. Add Design Files
add_files mlp.cpp -cflags "-I. -Igolden_vectors"
add_files mlp.hpp

# 3. Add Testbench Files
add_files -tb tb_mlp.cpp -cflags "-Wno-unknown-pragmas -I. -Igolden_vectors"

# 4. Solution Configuration
open_solution -reset "solution1"
set_part {xc7z020clg400-1}
create_clock -period 10 -name default

# 5. Execute Pipeline Stages
if {$stage == "csim" || $stage == "all"} {
    puts "\n==> Stage 1/4: Running C Simulation (csim_design)..."
    csim_design -clean
}

if {$stage == "csynth" || $stage == "all" || $stage == "cosim" || $stage == "export"} {
    puts "\n==> Stage 2/4: Running C Synthesis (csynth_design)..."
    csynth_design
}

if {$stage == "cosim" || $stage == "all"} {
    puts "\n==> Stage 3/4: Running C/RTL Co-simulation (cosim_design)..."
    cosim_design -trace_level all -rtl verilog
}

if {$stage == "export" || $stage == "all"} {
    puts "\n==> Stage 4/4: Exporting Vivado IP Catalog (export_design)..."
    export_design -format ip_catalog -description "MLP Neural Network Accelerator for Zynq-7000" -vendor "custom" -version "1.0"
}

puts "\n=================================================================="
puts "  Vivado HLS Flow Completed Successfully!"
puts "=================================================================="
exit 0
