# Vivado HLS 2018.3 Headless Automation: MLP Accelerator

This project implements an automated, headless build and simulation flow for a Multi-Layer Perceptron (MLP) accelerator (`mlp_accel`) targeting the Xilinx Zynq-7000 (`xc7z020clg400-1`).

---

## Quick Start (Fast Host Simulation)

To verify the C++ accelerator logic without launching Vivado:

```bash
make host-sim
```

This compiles `tb_mlp.cpp` and `mlp.cpp` using the native Linux `g++` compiler, verifies all test cases against the golden mathematical reference, and validates zero arithmetic error.

---

## Step 2 Specifications: `run_hls.tcl`

The automation script `run_hls.tcl` is configured exactly to your specifications:
- **Project Name:** `test`
- **Top-Level Function:** `mlp_accel`
- **Design Files:** `mlp.cpp`, `mlp.hpp`
- **Testbench File:** `tb_mlp.cpp`
- **Solution Name:** `solution1`
- **Target Device Part:** `xc7z020clg400-1`
- **Target Clock:** 10 ns (100 MHz)

### Running Vivado HLS Stages

```bash
# Run all stages sequentially (csim -> csynth -> cosim -> export)
vivado_hls -f run_hls.tcl all
# or simply: make all

# Run specific stages individually:
make csim      # or: vivado_hls -f run_hls.tcl csim
make csynth    # or: vivado_hls -f run_hls.tcl csynth
make cosim     # or: vivado_hls -f run_hls.tcl cosim
make export    # or: vivado_hls -f run_hls.tcl export
```

---

## Windows GUI vs. Headless Linux Server

| Feature | Windows GUI (Teacher Recommendation) | Headless Linux Server (DevOps Setup) |
| :--- | :--- | :--- |
| **Interface** | Windows desktop, mouse clicks | Headless CLI / SSH / VS Code Server |
| **Automation** | Manual project creation & menus | 100% script-driven (`run_hls.tcl`, `Makefile`) |
| **License** | Recommends HL Design Edition | Free **HL WebPACK** fully supports `xc7z020` |
| **Reproducibility** | Machine-dependent | 100% reproducible for CI/CD |
| **Disk/RAM Overhead**| Heavy GUI & OS overhead | Lightweight, dedicated to compute |

---

## Headless Installation & Docker Setup

Because the host server runs **Ubuntu 24.04 LTS (Noble Numbat)** with `glibc 2.39`, running legacy Vivado 2018.3 natively risks library clashes (`libtinfo5`, internal Clang crashes).

### Minimal Headless Install Config (`install_config.txt`)
To minimize disk usage on limited partitions (selecting only Vivado HLS and Zynq-7000):

```ini
Edition=Vivado HL WebPACK
Product=Vivado
Modules=Vivado High-Level Synthesis:1,Zynq-7000:1,DocNav:0,Software Development Kit (SDK):0
InstallPath=/opt/Xilinx
```

Install silently in batch mode:
```bash
./xsetup --agree XilinxEULA,3rdPartyEULA,WebTalkTerms --batch Install --config install_config.txt
```

### Docker Commands
```bash
# Build the compatible Ubuntu 18.04 container
make docker-build

# Run synthesis inside the container
make docker-synth

# Run full flow inside the container
make docker-all
```
