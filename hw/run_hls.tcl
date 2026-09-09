# ==============================================================================
# Vivado HLS 2018.3 Batch Automation Script for 784-64-10 MLP Accelerator
# Target: Xilinx Zynq-7000 SoC (xc7z020clg400-1) @ 100 MHz (10.0 ns period)
# ==============================================================================

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
puts "  Target Device : xc7z020clg400-1 @ 100 MHz (10.0 ns)"
puts "=================================================================="

# 1. Project Configuration
open_project -reset mlp_project
set_top mlp_accel

# 2. Add Synthesizable Core Files
add_files mlp_accel.cpp -cflags "-I. -I../include_xilinx"
add_files mlp_accel.h

# 3. Add Testbench Files
add_files -tb tb_mlp.cpp -cflags "-Wno-unknown-pragmas -I. -I../include_xilinx"

# 4. Solution & Clock Configuration
open_solution -reset "solution1"
set_part {xc7z020clg400-1}
create_clock -period 10.0 -name default

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
    export_design -format ip_catalog -description "784-64-10 MLP Hardware Accelerator Core" -vendor "intelligent_chip" -version "1.0"
}

puts "\n=================================================================="
puts "  Vivado HLS Flow Completed Successfully!"
puts "=================================================================="
exit 0
