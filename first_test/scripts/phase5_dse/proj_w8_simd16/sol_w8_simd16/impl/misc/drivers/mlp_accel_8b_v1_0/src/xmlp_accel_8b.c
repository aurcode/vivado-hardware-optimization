// ==============================================================
// File generated on Wed Sep 02 16:31:16 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
/***************************** Include Files *********************************/
#include "xmlp_accel_8b.h"

/************************** Function Implementation *************************/
#ifndef __linux__
int XMlp_accel_8b_CfgInitialize(XMlp_accel_8b *InstancePtr, XMlp_accel_8b_Config *ConfigPtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(ConfigPtr != NULL);

    InstancePtr->Ctrl_bus_BaseAddress = ConfigPtr->Ctrl_bus_BaseAddress;
    InstancePtr->IsReady = XIL_COMPONENT_IS_READY;

    return XST_SUCCESS;
}
#endif

void XMlp_accel_8b_Start(XMlp_accel_8b *InstancePtr) {
    u32 Data;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMlp_accel_8b_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_AP_CTRL) & 0x80;
    XMlp_accel_8b_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_AP_CTRL, Data | 0x01);
}

u32 XMlp_accel_8b_IsDone(XMlp_accel_8b *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMlp_accel_8b_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_AP_CTRL);
    return (Data >> 1) & 0x1;
}

u32 XMlp_accel_8b_IsIdle(XMlp_accel_8b *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMlp_accel_8b_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_AP_CTRL);
    return (Data >> 2) & 0x1;
}

u32 XMlp_accel_8b_IsReady(XMlp_accel_8b *InstancePtr) {
    u32 Data;

    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Data = XMlp_accel_8b_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_AP_CTRL);
    // check ap_start to see if the pcore is ready for next input
    return !(Data & 0x1);
}

void XMlp_accel_8b_EnableAutoRestart(XMlp_accel_8b *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMlp_accel_8b_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_AP_CTRL, 0x80);
}

void XMlp_accel_8b_DisableAutoRestart(XMlp_accel_8b *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMlp_accel_8b_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_AP_CTRL, 0);
}

u32 XMlp_accel_8b_Get_in_vec_BaseAddress(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE);
}

u32 XMlp_accel_8b_Get_in_vec_HighAddress(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_HIGH);
}

u32 XMlp_accel_8b_Get_in_vec_TotalBytes(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + 1);
}

u32 XMlp_accel_8b_Get_in_vec_BitWidth(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMLP_ACCEL_8B_CTRL_BUS_WIDTH_IN_VEC;
}

u32 XMlp_accel_8b_Get_in_vec_Depth(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMLP_ACCEL_8B_CTRL_BUS_DEPTH_IN_VEC;
}

u32 XMlp_accel_8b_Write_in_vec_Words(XMlp_accel_8b *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMlp_accel_8b_Read_in_vec_Words(XMlp_accel_8b *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMlp_accel_8b_Write_in_vec_Bytes(XMlp_accel_8b *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMlp_accel_8b_Read_in_vec_Bytes(XMlp_accel_8b *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_IN_VEC_BASE + offset + i);
    }
    return length;
}

u32 XMlp_accel_8b_Get_out_vec_BaseAddress(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE);
}

u32 XMlp_accel_8b_Get_out_vec_HighAddress(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_HIGH);
}

u32 XMlp_accel_8b_Get_out_vec_TotalBytes(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return (XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + 1);
}

u32 XMlp_accel_8b_Get_out_vec_BitWidth(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMLP_ACCEL_8B_CTRL_BUS_WIDTH_OUT_VEC;
}

u32 XMlp_accel_8b_Get_out_vec_Depth(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMLP_ACCEL_8B_CTRL_BUS_DEPTH_OUT_VEC;
}

u32 XMlp_accel_8b_Write_out_vec_Words(XMlp_accel_8b *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(int *)(InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + (offset + i)*4) = *(data + i);
    }
    return length;
}

u32 XMlp_accel_8b_Read_out_vec_Words(XMlp_accel_8b *InstancePtr, int offset, int *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length)*4 > (XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(int *)(InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + (offset + i)*4);
    }
    return length;
}

u32 XMlp_accel_8b_Write_out_vec_Bytes(XMlp_accel_8b *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(char *)(InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + offset + i) = *(data + i);
    }
    return length;
}

u32 XMlp_accel_8b_Read_out_vec_Bytes(XMlp_accel_8b *InstancePtr, int offset, char *data, int length) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr -> IsReady == XIL_COMPONENT_IS_READY);

    int i;

    if ((offset + length) > (XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_HIGH - XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + 1))
        return 0;

    for (i = 0; i < length; i++) {
        *(data + i) = *(char *)(InstancePtr->Ctrl_bus_BaseAddress + XMLP_ACCEL_8B_CTRL_BUS_ADDR_OUT_VEC_BASE + offset + i);
    }
    return length;
}

void XMlp_accel_8b_InterruptGlobalEnable(XMlp_accel_8b *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMlp_accel_8b_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_GIE, 1);
}

void XMlp_accel_8b_InterruptGlobalDisable(XMlp_accel_8b *InstancePtr) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMlp_accel_8b_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_GIE, 0);
}

void XMlp_accel_8b_InterruptEnable(XMlp_accel_8b *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMlp_accel_8b_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_IER);
    XMlp_accel_8b_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_IER, Register | Mask);
}

void XMlp_accel_8b_InterruptDisable(XMlp_accel_8b *InstancePtr, u32 Mask) {
    u32 Register;

    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    Register =  XMlp_accel_8b_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_IER);
    XMlp_accel_8b_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_IER, Register & (~Mask));
}

void XMlp_accel_8b_InterruptClear(XMlp_accel_8b *InstancePtr, u32 Mask) {
    Xil_AssertVoid(InstancePtr != NULL);
    Xil_AssertVoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    XMlp_accel_8b_WriteReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_ISR, Mask);
}

u32 XMlp_accel_8b_InterruptGetEnabled(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMlp_accel_8b_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_IER);
}

u32 XMlp_accel_8b_InterruptGetStatus(XMlp_accel_8b *InstancePtr) {
    Xil_AssertNonvoid(InstancePtr != NULL);
    Xil_AssertNonvoid(InstancePtr->IsReady == XIL_COMPONENT_IS_READY);

    return XMlp_accel_8b_ReadReg(InstancePtr->Ctrl_bus_BaseAddress, XMLP_ACCEL_8B_CTRL_BUS_ADDR_ISR);
}

