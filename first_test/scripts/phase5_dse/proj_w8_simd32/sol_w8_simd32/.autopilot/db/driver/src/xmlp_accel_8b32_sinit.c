// ==============================================================
// File generated on Wed Sep 02 16:32:49 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __linux__

#include "xstatus.h"
#include "xparameters.h"
#include "xmlp_accel_8b32.h"

extern XMlp_accel_8b32_Config XMlp_accel_8b32_ConfigTable[];

XMlp_accel_8b32_Config *XMlp_accel_8b32_LookupConfig(u16 DeviceId) {
	XMlp_accel_8b32_Config *ConfigPtr = NULL;

	int Index;

	for (Index = 0; Index < XPAR_XMLP_ACCEL_8B32_NUM_INSTANCES; Index++) {
		if (XMlp_accel_8b32_ConfigTable[Index].DeviceId == DeviceId) {
			ConfigPtr = &XMlp_accel_8b32_ConfigTable[Index];
			break;
		}
	}

	return ConfigPtr;
}

int XMlp_accel_8b32_Initialize(XMlp_accel_8b32 *InstancePtr, u16 DeviceId) {
	XMlp_accel_8b32_Config *ConfigPtr;

	Xil_AssertNonvoid(InstancePtr != NULL);

	ConfigPtr = XMlp_accel_8b32_LookupConfig(DeviceId);
	if (ConfigPtr == NULL) {
		InstancePtr->IsReady = 0;
		return (XST_DEVICE_NOT_FOUND);
	}

	return XMlp_accel_8b32_CfgInitialize(InstancePtr, ConfigPtr);
}

#endif

