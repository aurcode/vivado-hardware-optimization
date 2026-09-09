// ==============================================================
// File generated on Wed Sep 02 16:35:41 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
// CTRL_BUS
// 0x0000 : Control signals
//          bit 0  - ap_start (Read/Write/COH)
//          bit 1  - ap_done (Read/COR)
//          bit 2  - ap_idle (Read)
//          bit 3  - ap_ready (Read)
//          bit 7  - auto_restart (Read/Write)
//          others - reserved
// 0x0004 : Global Interrupt Enable Register
//          bit 0  - Global Interrupt Enable (Read/Write)
//          others - reserved
// 0x0008 : IP Interrupt Enable Register (Read/Write)
//          bit 0  - Channel 0 (ap_done)
//          bit 1  - Channel 1 (ap_ready)
//          others - reserved
// 0x000c : IP Interrupt Status Register (Read/TOW)
//          bit 0  - Channel 0 (ap_done)
//          bit 1  - Channel 1 (ap_ready)
//          others - reserved
// 0x0800 ~
// 0x0fff : Memory 'in_vec' (784 * 16b)
//          Word n : bit [15: 0] - in_vec[2n]
//                   bit [31:16] - in_vec[2n+1]
// 0x1000 ~
// 0x101f : Memory 'out_vec' (10 * 16b)
//          Word n : bit [15: 0] - out_vec[2n]
//                   bit [31:16] - out_vec[2n+1]
// (SC = Self Clear, COR = Clear on Read, TOW = Toggle on Write, COH = Clear on Handshake)

#define XMLP_ACCEL_CTRL_BUS_ADDR_AP_CTRL      0x0000
#define XMLP_ACCEL_CTRL_BUS_ADDR_GIE          0x0004
#define XMLP_ACCEL_CTRL_BUS_ADDR_IER          0x0008
#define XMLP_ACCEL_CTRL_BUS_ADDR_ISR          0x000c
#define XMLP_ACCEL_CTRL_BUS_ADDR_IN_VEC_BASE  0x0800
#define XMLP_ACCEL_CTRL_BUS_ADDR_IN_VEC_HIGH  0x0fff
#define XMLP_ACCEL_CTRL_BUS_WIDTH_IN_VEC      16
#define XMLP_ACCEL_CTRL_BUS_DEPTH_IN_VEC      784
#define XMLP_ACCEL_CTRL_BUS_ADDR_OUT_VEC_BASE 0x1000
#define XMLP_ACCEL_CTRL_BUS_ADDR_OUT_VEC_HIGH 0x101f
#define XMLP_ACCEL_CTRL_BUS_WIDTH_OUT_VEC     16
#define XMLP_ACCEL_CTRL_BUS_DEPTH_OUT_VEC     10

