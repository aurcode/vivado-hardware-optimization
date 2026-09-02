# ==============================================================================
# Makefile for Vivado HLS 2018.3 MLP Accelerator Flow
# ==============================================================================

CXX         := g++
CXXFLAGS    := -O3 -Wall -Wextra -Wno-unknown-pragmas -std=c++11

HLS_BIN     := vivado_hls
TCL_SCRIPT  := run_hls.tcl
DOCKER_IMG  := fpgatools/vivado:latest
WORKSPACE   := $(shell pwd)

SETUP_CMD   := mkdir -p ~/.Xilinx/Vivado && cp /workspace/Vivado_init.tcl ~/.Xilinx/Vivado/Vivado_init.tcl && source /opt/Xilinx/Vivado/2018.3/settings64.sh
DOCKER_RUN  := docker run --rm -v $(WORKSPACE):/workspace -w /workspace $(DOCKER_IMG)

.PHONY: help all host-sim csim csynth cosim export clean docker-sim docker-synth docker-cosim docker-export docker-all

help:
	@echo "Available targets:"
	@echo "  make host-sim      - Quick native C++ simulation using host g++ (instant verification)"
	@echo "  make csim          - Run Vivado HLS C simulation inside Docker (csim_design)"
	@echo "  make csynth        - Run Vivado HLS synthesis inside Docker (csynth_design)"
	@echo "  make cosim         - Run Vivado HLS C/RTL co-simulation inside Docker (cosim_design)"
	@echo "  make export        - Export synthesized design to Vivado IP catalog inside Docker"
	@echo "  make all           - Run complete Vivado HLS flow inside Docker (csim -> csynth -> cosim -> export)"
	@echo "  make clean         - Remove test builds, logs, and generated HLS solutions"

# 1. Fast Host-level C++ Simulation
host-sim: tb_mlp.cpp mlp.cpp mlp.hpp
	@echo "==> Compiling host simulation..."
	$(CXX) $(CXXFLAGS) tb_mlp.cpp mlp.cpp -o sim_mlp
	@echo "==> Running host simulation..."
	./sim_mlp

# 2. Docker Vivado HLS Execution Targets
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

# Aliases for docker-*
docker-sim: csim
docker-synth: csynth
docker-cosim: cosim
docker-export: export
docker-all: all

# 3. Clean Artifacts
clean:
	rm -rf sim_mlp test_mlp
	rm -rf test vivado_hls.log hs_err_*.log
