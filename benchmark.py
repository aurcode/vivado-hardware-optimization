#!/usr/bin/env python3
"""
Environment & Simulation Benchmark Suite for Vivado HLS MLP Accelerator
Compares performance between the Linux Server environment and your Local Computer.

Usage:
  python3 benchmark.py                    # Run local CPU simulation benchmark
  python3 benchmark.py --hls              # Run both CPU benchmark and full Vivado HLS pipeline
  python3 benchmark.py --compare server.json local.json  # Compare two benchmark runs side-by-side
"""

import sys
import os
import platform
import subprocess
import time
import json
import socket
import shutil

def get_cpu_info():
    """Returns human-readable CPU model and core count."""
    cpu_model = "Unknown CPU"
    cores = os.cpu_count() or 1
    system = platform.system()

    try:
        if system == "Linux":
            with open("/proc/cpuinfo", "r") as f:
                for line in f:
                    if "model name" in line:
                        cpu_model = line.split(":")[1].strip()
                        break
        elif system == "Darwin": # macOS
            cpu_model = subprocess.check_output(["sysctl", "-n", "machdep.cpu.brand_string"]).decode().strip()
        elif system == "Windows":
            cpu_model = platform.processor()
    except Exception:
        pass

    return {
        "model": cpu_model,
        "cores": cores,
        "arch": platform.machine()
    }

def get_memory_info():
    """Returns approximate total RAM in GB."""
    try:
        if platform.system() == "Linux":
            with open("/proc/meminfo", "r") as f:
                for line in f:
                    if "MemTotal" in line:
                        kb = int(line.split()[1])
                        return round(kb / (1024 * 1024), 2)
        elif platform.system() == "Darwin":
            bytes_mem = int(subprocess.check_output(["sysctl", "-n", "hw.memsize"]).decode().strip())
            return round(bytes_mem / (1024**3), 2)
    except Exception:
        pass
    return "N/A"

def run_command(cmd, cwd=None):
    """Executes a shell command and returns execution time and stdout."""
    start = time.time()
    res = subprocess.run(cmd, shell=True, cwd=cwd, stdout=subprocess.PIPE, stderr=subprocess.PIPE, text=True)
    elapsed = time.time() - start
    return elapsed, res.returncode, res.stdout, res.stderr

def benchmark_cpu_simulation(iterations=10000000):
    """Compiles and benchmarks the C++ accelerator inference logic."""
    print(f"\n[*] Benchmarking Native C++ Simulation ({iterations:,} inferences)...")
    cxx = "g++"
    if shutil.which("clang++") and not shutil.which("g++"):
        cxx = "clang++"

    compile_cmd = f"{cxx} -O3 -std=c++11 -Wall -Wno-unknown-pragmas bench_mlp.cpp mlp.cpp -o bench_mlp"
    c_time, rc, out, err = run_command(compile_cmd)
    if rc != 0:
        print(f"[!] Compilation failed:\n{err}")
        return None

    run_cmd = f"./bench_mlp {iterations}"
    r_time, rc, out, err = run_command(run_cmd)
    if rc != 0:
        print(f"[!] Execution failed:\n{err}")
        return None

    results = {}
    for line in out.strip().split("\n"):
        if line.startswith("BENCHMARK_RESULT:"):
            k, v = line.replace("BENCHMARK_RESULT:", "").split("=")
            results[k] = float(v)

    # Clean up binary
    if os.path.exists("bench_mlp"):
        os.remove("bench_mlp")

    results["compile_time_sec"] = round(c_time, 3)
    return results

def benchmark_hls_pipeline():
    """Runs and profiles the Vivado HLS 2018.3 Docker pipeline stages."""
    print("\n[*] Benchmarking Vivado HLS Pipeline Stages...")
    stages = ["csim", "csynth", "cosim", "export"]
    results = {}

    for stg in stages:
        print(f"  -> Running Stage: {stg} ... ", end="", flush=True)
        t, rc, out, err = run_command(f"make {stg}")
        if rc == 0:
            print(f"SUCCESS ({t:.2f}s)")
            results[stg + "_time_sec"] = round(t, 2)
            results[stg + "_status"] = "PASS"
        else:
            print(f"FAILED (code {rc})")
            results[stg + "_time_sec"] = round(t, 2)
            results[stg + "_status"] = "FAIL"

    return results

def compare_results(file1, file2):
    """Compares two JSON benchmark result files and outputs a formatted table."""
    with open(file1, "r") as f:
        d1 = json.load(f)
    with open(file2, "r") as f:
        d2 = json.load(f)

    h1 = d1.get("hostname", "Environment 1")
    h2 = d2.get("hostname", "Environment 2")

    print("\n" + "=" * 78)
    print(f"  PERFORMANCE BENCHMARK COMPARISON: {h1} vs. {h2}")
    print("=" * 78)

    # Hardware Info
    print(f"{'Metric':<32} | {h1:<20} | {h2:<20}")
    print("-" * 78)
    print(f"{'OS Platform':<32} | {d1.get('os','N/A'):<20} | {d2.get('os','N/A'):<20}")
    print(f"{'CPU Model':<32} | {d1.get('cpu',{}).get('model','N/A')[:20]:<20} | {d2.get('cpu',{}).get('model','N/A')[:20]:<20}")
    print(f"{'CPU Cores':<32} | {str(d1.get('cpu',{}).get('cores','N/A')):<20} | {str(d2.get('cpu',{}).get('cores','N/A')):<20}")
    print(f"{'RAM (GB)':<32} | {str(d1.get('ram_gb','N/A')):<20} | {str(d2.get('ram_gb','N/A')):<20}")
    print("-" * 78)

    # Simulation Benchmark
    cpu1 = d1.get("cpu_benchmark", {})
    cpu2 = d2.get("cpu_benchmark", {})

    if cpu1 and cpu2:
        t1 = cpu1.get("TOTAL_TIME_SEC", 0)
        t2 = cpu2.get("TOTAL_TIME_SEC", 0)
        speedup = (t1 / t2) if t2 > 0 else 0
        faster_env = h2 if speedup > 1.0 else h1
        ratio = speedup if speedup >= 1.0 else (1.0 / speedup if speedup > 0 else 0)

        lat1 = cpu1.get("AVG_LATENCY_NS", 0)
        lat2 = cpu2.get("AVG_LATENCY_NS", 0)
        ips1 = cpu1.get("THROUGHPUT_IPS", 0)
        ips2 = cpu2.get("THROUGHPUT_IPS", 0)

        print(f"{'Total Sim Time (10M inf)':<32} | {f'{t1:.3f} s':<20} | {f'{t2:.3f} s':<20}")
        print(f"{'Latency per Inference':<32} | {f'{lat1:.2f} ns':<20} | {f'{lat2:.2f} ns':<20}")
        print(f"{'Throughput (inf/sec)':<32} | {f'{ips1:,.0f}':<20} | {f'{ips2:,.0f}':<20}")
        print("-" * 78)
        print(f"  --> Winner: {faster_env} is {ratio:.2f}x FASTER in simulation throughput!")
        print("-" * 78)

    # Vivado HLS Pipeline Comparison (if available)
    hls1 = d1.get("hls_pipeline", {})
    hls2 = d2.get("hls_pipeline", {})
    if hls1 or hls2:
        print(f"{'Vivado HLS Build Stages':<32} | {'Time (Server)':<20} | {'Time (Local)':<20}")
        print("-" * 78)
        for stg in ["csim_time_sec", "csynth_time_sec", "cosim_time_sec", "export_time_sec", "total_flow_sec"]:
            label = stg.replace("_time_sec", "").replace("_", " ").upper()
            v1 = f"{hls1.get(stg, 'N/A')} s" if stg in hls1 else "N/A"
            v2 = f"{hls2.get(stg, 'N/A')} s" if stg in hls2 else "N/A"
            print(f"{label:<32} | {v1:<20} | {v2:<20}")
        print("-" * 78)

    # FPGA Reference
    print(f"{'FPGA Hardware Core (Target)':<32} | 151 cycles @ 100MHz = 1.51 us (Deterministic)")
    print(f"{'FPGA Hardware Throughput':<32} | 662,251 inferences/sec (Dedicated Hardware)")
    print("=" * 78)

def main():
    if "--compare" in sys.argv:
        idx = sys.argv.index("--compare")
        if len(sys.argv) > idx + 2:
            compare_results(sys.argv[idx + 1], sys.argv[idx + 2])
            return
        else:
            print("Usage: python3 benchmark.py --compare <results1.json> <results2.json>")
            return

    hostname = socket.gethostname()
    print("=" * 60)
    print(f"  Starting Simulation Performance Benchmark on: {hostname}")
    print("=" * 60)

    cpu_info = get_cpu_info()
    ram_gb = get_memory_info()

    print(f"  OS Platform : {platform.system()} {platform.release()}")
    print(f"  CPU Model   : {cpu_info['model']} ({cpu_info['cores']} cores)")
    print(f"  Memory (RAM): {ram_gb} GB")

    data = {
        "hostname": hostname,
        "os": f"{platform.system()} {platform.release()}",
        "cpu": cpu_info,
        "ram_gb": ram_gb,
        "timestamp": time.strftime("%Y-%m-%d %H:%M:%S")
    }

    # 1. Native C++ simulation benchmark
    cpu_bench = benchmark_cpu_simulation(iterations=10000000)
    if cpu_bench:
        data["cpu_benchmark"] = cpu_bench
        print("\n  [CPU Simulation Results (10,000,000 Inferences)]")
        print(f"    - Total Time    : {cpu_bench['TOTAL_TIME_SEC']:.4f} s")
        print(f"    - Avg Latency   : {cpu_bench['AVG_LATENCY_NS']:.2f} ns ({cpu_bench['AVG_LATENCY_US']:.4f} us)")
        print(f"    - Throughput    : {cpu_bench['THROUGHPUT_IPS']:,.0f} inferences/second")

    # 2. Vivado HLS pipeline benchmark (if --hls flag passed)
    if "--hls" in sys.argv:
        hls_bench = benchmark_hls_pipeline()
        data["hls_pipeline"] = hls_bench

    # Save results to JSON file
    filename = f"benchmark_{hostname}.json"
    with open(filename, "w") as f:
        json.dump(data, f, indent=2)

    print("\n" + "=" * 60)
    print(f"  Benchmark complete! Saved results to: {filename}")
    print(f"  To compare with another machine, run:")
    print(f"    python3 benchmark.py --compare {filename} <local_results.json>")
    print("=" * 60)

if __name__ == "__main__":
    main()
