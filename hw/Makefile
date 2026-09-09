# ==============================================================================
# Makefile for 784-64-10 MLP Hardware Accelerator
# ==============================================================================

CXX         := g++
CXXFLAGS    := -O0 -Wall -Wno-unknown-pragmas -Wno-unused-parameter -Wno-unused-label -Wno-int-in-bool-context -std=c++11 -I. -I../include_xilinx

HLS_BIN     := vivado_hls
TCL_SCRIPT  := run_hls.tcl
DOCKER_IMG  := fpgatools/vivado:latest
ROOT_DIR    := $(shell cd .. && pwd)
SETUP_CMD   := mkdir -p ~/.Xilinx/Vivado && cp /workspace/Vivado_init.tcl ~/.Xilinx/Vivado/Vivado_init.tcl && source /opt/Xilinx/Vivado/2018.3/settings64.sh
DOCKER_RUN  := docker run --rm -v $(ROOT_DIR):/workspace -w /workspace/hw $(DOCKER_IMG)

.PHONY: help host-sim csim csynth cosim export all clean

help:
	@echo "Available Targets:"
	@echo "  make host-sim   - Fast native C++ simulation using host g++ and include_xilinx/"
	@echo "  make csim       - Run Vivado HLS C-simulation inside Docker"
	@echo "  make csynth     - Run Vivado HLS C-synthesis inside Docker"
	@echo "  make cosim      - Run Vivado HLS C/RTL co-simulation inside Docker"
	@echo "  make export     - Export synthesized IP Catalog package inside Docker"
	@echo "  make all        - Run complete flow (csim -> csynth -> cosim -> export)"
	@echo "  make clean      - Clean simulation binaries and HLS solution artifacts"

host-sim: sim_mlp
	@echo "==> Executing native host simulation..."
	./sim_mlp

sim_mlp: tb_mlp.o mlp_accel.o
	@echo "==> Linking native host simulation..."
	$(CXX) $(CXXFLAGS) tb_mlp.o mlp_accel.o -o sim_mlp

mlp_accel.o: mlp_accel.cpp mlp_accel.h weights.h
	@echo "==> Compiling mlp_accel.cpp..."
	$(CXX) $(CXXFLAGS) -c mlp_accel.cpp -o mlp_accel.o

tb_mlp.o: tb_mlp.cpp mlp_accel.h test_inputs.h
	@echo "==> Compiling tb_mlp.cpp..."
	$(CXX) $(CXXFLAGS) -c tb_mlp.cpp -o tb_mlp.o

csim:
	$(DOCKER_RUN) bash -c "$(SETUP_CMD) && $(HLS_BIN) -f $(TCL_SCRIPT) csim"

csynth:
	$(DOCKER_RUN) bash -c "$(SETUP_CMD) && $(HLS_BIN) -f $(TCL_SCRIPT) csynth"

cosim:
	$(DOCKER_RUN) bash -c "$(SETUP_CMD) && $(HLS_BIN) -f $(TCL_SCRIPT) cosim"

export:
	$(DOCKER_RUN) bash -c "$(SETUP_CMD) && $(HLS_BIN) -f $(TCL_SCRIPT) export"

all:
	$(DOCKER_RUN) bash -c "$(SETUP_CMD) && $(HLS_BIN) -f $(TCL_SCRIPT) all"

clean:
	rm -rf sim_mlp *.o
	rm -rf mlp_project vivado_hls.log hs_err_*.log

