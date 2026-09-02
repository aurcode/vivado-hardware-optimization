# =============================================================================
# Vivado HLS Design Space Exploration (DSE) Synthesis Script
# Target Device: Xilinx Zynq-7000 (xc7z020clg400-1)
# =============================================================================

set target_config [lindex $argv 2]
if {$target_config == ""} {
    set target_config "all"
}

puts "=================================================================="
puts "  Vivado HLS DSE Synthesis Sweep: Target = $target_config"
puts "=================================================================="

proc run_synth {proj_name top_func src_file sol_name} {
    puts "\n==> Synthesizing Configuration: $sol_name (Top: $top_func) ..."
    open_project -reset $proj_name
    set_top $top_func
    add_files $src_file -cflags "-I. -Iheaders -I../.. -I../../golden_vectors -std=c++11"
    open_solution -reset $sol_name
    set_part {xc7z020clg400-1}
    create_clock -period 10 -name default
    csynth_design
    close_solution
    close_project
    puts "==> Finished Configuration: $sol_name\n"
}

if {$target_config == "w16_simd16" || $target_config == "all"} {
    run_synth "proj_w16_simd16" "mlp_accel" "../../mlp.cpp" "sol_w16_simd16"
}

if {$target_config == "w8_simd16" || $target_config == "all"} {
    run_synth "proj_w8_simd16" "mlp_accel_8b" "src/mlp_8b.cpp" "sol_w8_simd16"
}

if {$target_config == "w8_simd32" || $target_config == "all"} {
    run_synth "proj_w8_simd32" "mlp_accel_8b32" "src/mlp_8b_simd32.cpp" "sol_w8_simd32"
}

if {$target_config == "w4_simd16" || $target_config == "all"} {
    run_synth "proj_w4_simd16" "mlp_accel_4b" "src/mlp_4b.cpp" "sol_w4_simd16"
}

puts "=================================================================="
puts "  Vivado HLS DSE Synthesis Sweep Complete!"
puts "=================================================================="
exit
