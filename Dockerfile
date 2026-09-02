# ==============================================================================
# Dockerfile: Headless Vivado HLS 2018.3 on Ubuntu 18.04 LTS
# ==============================================================================
FROM ubuntu:18.04

LABEL maintainer="FPGA/Embedded DevOps"
LABEL description="Headless automated environment for Vivado HLS 2018.3"

# Avoid interactive apt prompts
ENV DEBIAN_FRONTEND=noninteractive
ENV LANG=en_US.UTF-8
ENV LC_ALL=en_US.UTF-8

# 1. Install system prerequisites and legacy libraries required by Vivado 2018.3
RUN apt-get update && apt-get install -y --no-install-recommends \
    build-essential \
    gcc \
    g++ \
    make \
    tcl \
    libtinfo5 \
    libncurses5 \
    libglib2.0-0 \
    libsm6 \
    libxrender1 \
    libxext6 \
    libxtst6 \
    libxi6 \
    ca-certificates \
    curl \
    locales \
    && locale-gen en_US.UTF-8 \
    && rm -rf /var/lib/apt/lists/*

# 2. Configure environment path for Xilinx Vivado HLS
ENV XILINX_VIVADO=/opt/Xilinx/Vivado/2018.3
ENV PATH="${XILINX_VIVADO}/bin:${PATH}"

# 3. Create workspace directory
WORKDIR /workspace

# Default command: show Vivado HLS version
CMD ["vivado_hls", "-version"]
