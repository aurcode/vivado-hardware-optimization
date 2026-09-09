set moduleName mlp_accel_8b32
set isTaskLevelControl 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {mlp_accel_8b32}
set C_modelType { void 0 }
set C_modelArgList {
	{ in_vec int 8 regular {axi_slave 0}  }
	{ out_vec int 8 regular {axi_slave 1}  }
}
set C_modelArgMapList {[ 
	{ "Name" : "in_vec", "interface" : "axi_slave", "bundle":"CTRL_BUS","type":"ap_memory","bitwidth" : 8, "direction" : "READONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "in_vec","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 783,"step" : 1}]}]}], "offset" : {"in":1024}, "offset_end" : {"in":2047}} , 
 	{ "Name" : "out_vec", "interface" : "axi_slave", "bundle":"CTRL_BUS","type":"ap_memory","bitwidth" : 8, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":7,"cElement": [{"cName": "out_vec","cData": "signed char","bit_use": { "low": 0,"up": 7},"cArray": [{"low" : 0,"up" : 9,"step" : 1}]}]}], "offset" : {"out":2048}, "offset_end" : {"out":2063}} ]}
# RTL Port declarations: 
set portNum 20
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst_n sc_in sc_logic 1 reset -1 active_low_sync } 
	{ s_axi_CTRL_BUS_AWVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_AWREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_AWADDR sc_in sc_lv 12 signal -1 } 
	{ s_axi_CTRL_BUS_WVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_WREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_WDATA sc_in sc_lv 32 signal -1 } 
	{ s_axi_CTRL_BUS_WSTRB sc_in sc_lv 4 signal -1 } 
	{ s_axi_CTRL_BUS_ARVALID sc_in sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_ARREADY sc_out sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_ARADDR sc_in sc_lv 12 signal -1 } 
	{ s_axi_CTRL_BUS_RVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_RREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_RDATA sc_out sc_lv 32 signal -1 } 
	{ s_axi_CTRL_BUS_RRESP sc_out sc_lv 2 signal -1 } 
	{ s_axi_CTRL_BUS_BVALID sc_out sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_BREADY sc_in sc_logic 1 signal -1 } 
	{ s_axi_CTRL_BUS_BRESP sc_out sc_lv 2 signal -1 } 
	{ interrupt sc_out sc_logic 1 signal -1 } 
}
set NewPortList {[ 
	{ "name": "s_axi_CTRL_BUS_AWADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "AWADDR" },"address":[{"name":"mlp_accel_8b32","role":"start","value":"0","valid_bit":"0"},{"name":"mlp_accel_8b32","role":"continue","value":"0","valid_bit":"4"},{"name":"mlp_accel_8b32","role":"auto_start","value":"0","valid_bit":"7"},{"name":"in_vec","role":"data","value":"1024"}] },
	{ "name": "s_axi_CTRL_BUS_AWVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "AWVALID" } },
	{ "name": "s_axi_CTRL_BUS_AWREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "AWREADY" } },
	{ "name": "s_axi_CTRL_BUS_WVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "WVALID" } },
	{ "name": "s_axi_CTRL_BUS_WREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "WREADY" } },
	{ "name": "s_axi_CTRL_BUS_WDATA", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "WDATA" } },
	{ "name": "s_axi_CTRL_BUS_WSTRB", "direction": "in", "datatype": "sc_lv", "bitwidth":4, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "WSTRB" } },
	{ "name": "s_axi_CTRL_BUS_ARADDR", "direction": "in", "datatype": "sc_lv", "bitwidth":12, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "ARADDR" },"address":[{"name":"mlp_accel_8b32","role":"start","value":"0","valid_bit":"0"},{"name":"mlp_accel_8b32","role":"done","value":"0","valid_bit":"1"},{"name":"mlp_accel_8b32","role":"idle","value":"0","valid_bit":"2"},{"name":"mlp_accel_8b32","role":"ready","value":"0","valid_bit":"3"},{"name":"mlp_accel_8b32","role":"auto_start","value":"0","valid_bit":"7"},{"name":"out_vec","role":"data","value":"2048"}] },
	{ "name": "s_axi_CTRL_BUS_ARVALID", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "ARVALID" } },
	{ "name": "s_axi_CTRL_BUS_ARREADY", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "ARREADY" } },
	{ "name": "s_axi_CTRL_BUS_RVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "RVALID" } },
	{ "name": "s_axi_CTRL_BUS_RREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "RREADY" } },
	{ "name": "s_axi_CTRL_BUS_RDATA", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "RDATA" } },
	{ "name": "s_axi_CTRL_BUS_RRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "RRESP" } },
	{ "name": "s_axi_CTRL_BUS_BVALID", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "BVALID" } },
	{ "name": "s_axi_CTRL_BUS_BREADY", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "BREADY" } },
	{ "name": "s_axi_CTRL_BUS_BRESP", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "BRESP" } },
	{ "name": "interrupt", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "CTRL_BUS", "role": "interrupt" } }, 
 	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst_n", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst_n", "role": "default" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2", "3", "4", "5", "6", "7", "8", "9", "10", "11", "12", "13", "14", "15", "16", "17", "18", "19", "20", "21", "22", "23", "24", "25", "26", "27", "28", "29", "30", "31", "32", "33", "34", "35", "36", "37", "38", "39", "40", "41", "42", "43", "44", "45", "46", "47", "48", "49", "50", "51", "52", "53", "54", "55", "56", "57", "58", "59", "60", "61", "62", "63", "64", "65", "66", "67", "68", "69", "70", "71", "72", "73", "74", "75", "76", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "89", "90", "91", "92", "93", "94", "95", "96", "97", "98", "99", "100", "101", "102", "103", "104", "105", "106", "107", "108", "109", "110", "111", "112", "113", "114", "115", "116", "117", "118", "119", "120", "121", "122", "123", "124", "125", "126", "127", "128", "129", "130", "131", "132", "133", "134", "135", "136", "137", "138", "139", "140", "141", "142", "143", "144", "145", "146", "147", "148", "149", "150", "151", "152", "153", "154", "155", "156", "157", "158", "159", "160", "161", "162", "163", "164", "165", "166", "167", "168", "169", "170", "171", "172", "173", "174", "175", "176", "177", "178", "179", "180", "181", "182", "183", "184", "185", "186", "187", "188", "189", "190", "191", "192", "193", "194", "195", "196", "197", "198", "199", "200", "201", "202", "203", "204", "205", "206", "207", "208", "209", "210"],
		"CDFG" : "mlp_accel_8b32",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "5578", "EstimateLatencyMax" : "5578",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "in_vec", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "out_vec", "Type" : "Memory", "Direction" : "O"},
			{"Name" : "weights_l1_8b32_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_10", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_11", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_12", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_13", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_14", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_15", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_16", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_17", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_18", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_19", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_20", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_21", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_22", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_23", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_24", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_25", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_26", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_27", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_28", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_29", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_30", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l1_8b32_31", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_10", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_11", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_12", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_13", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_14", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_15", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_16", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_17", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_18", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_19", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_20", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_21", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_22", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_23", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_24", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_25", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_26", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_27", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_28", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_29", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_30", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l2_8b32_31", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_2", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_3", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_4", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_5", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_6", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_7", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_8", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_9", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_10", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_11", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_12", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_13", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_14", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_15", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_16", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_17", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_18", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_19", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_20", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_21", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_22", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_23", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_24", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_25", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_26", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_27", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_28", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_29", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_30", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "weights_l3_8b32_31", "Type" : "Memory", "Direction" : "I"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_0_U", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_1_U", "Parent" : "0"},
	{"ID" : "3", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_2_U", "Parent" : "0"},
	{"ID" : "4", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_3_U", "Parent" : "0"},
	{"ID" : "5", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_4_U", "Parent" : "0"},
	{"ID" : "6", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_5_U", "Parent" : "0"},
	{"ID" : "7", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_6_U", "Parent" : "0"},
	{"ID" : "8", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_7_U", "Parent" : "0"},
	{"ID" : "9", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_8_U", "Parent" : "0"},
	{"ID" : "10", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_9_U", "Parent" : "0"},
	{"ID" : "11", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_10_U", "Parent" : "0"},
	{"ID" : "12", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_11_U", "Parent" : "0"},
	{"ID" : "13", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_12_U", "Parent" : "0"},
	{"ID" : "14", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_13_U", "Parent" : "0"},
	{"ID" : "15", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_14_U", "Parent" : "0"},
	{"ID" : "16", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_15_U", "Parent" : "0"},
	{"ID" : "17", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_16_U", "Parent" : "0"},
	{"ID" : "18", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_17_U", "Parent" : "0"},
	{"ID" : "19", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_18_U", "Parent" : "0"},
	{"ID" : "20", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_19_U", "Parent" : "0"},
	{"ID" : "21", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_20_U", "Parent" : "0"},
	{"ID" : "22", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_21_U", "Parent" : "0"},
	{"ID" : "23", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_22_U", "Parent" : "0"},
	{"ID" : "24", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_23_U", "Parent" : "0"},
	{"ID" : "25", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_24_U", "Parent" : "0"},
	{"ID" : "26", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_25_U", "Parent" : "0"},
	{"ID" : "27", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_26_U", "Parent" : "0"},
	{"ID" : "28", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_27_U", "Parent" : "0"},
	{"ID" : "29", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_28_U", "Parent" : "0"},
	{"ID" : "30", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_29_U", "Parent" : "0"},
	{"ID" : "31", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_30_U", "Parent" : "0"},
	{"ID" : "32", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l1_8b32_31_U", "Parent" : "0"},
	{"ID" : "33", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_0_U", "Parent" : "0"},
	{"ID" : "34", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_1_U", "Parent" : "0"},
	{"ID" : "35", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_2_U", "Parent" : "0"},
	{"ID" : "36", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_3_U", "Parent" : "0"},
	{"ID" : "37", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_4_U", "Parent" : "0"},
	{"ID" : "38", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_5_U", "Parent" : "0"},
	{"ID" : "39", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_6_U", "Parent" : "0"},
	{"ID" : "40", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_7_U", "Parent" : "0"},
	{"ID" : "41", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_8_U", "Parent" : "0"},
	{"ID" : "42", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_9_U", "Parent" : "0"},
	{"ID" : "43", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_10_U", "Parent" : "0"},
	{"ID" : "44", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_11_U", "Parent" : "0"},
	{"ID" : "45", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_12_U", "Parent" : "0"},
	{"ID" : "46", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_13_U", "Parent" : "0"},
	{"ID" : "47", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_14_U", "Parent" : "0"},
	{"ID" : "48", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_15_U", "Parent" : "0"},
	{"ID" : "49", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_16_U", "Parent" : "0"},
	{"ID" : "50", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_17_U", "Parent" : "0"},
	{"ID" : "51", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_18_U", "Parent" : "0"},
	{"ID" : "52", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_19_U", "Parent" : "0"},
	{"ID" : "53", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_20_U", "Parent" : "0"},
	{"ID" : "54", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_21_U", "Parent" : "0"},
	{"ID" : "55", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_22_U", "Parent" : "0"},
	{"ID" : "56", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_23_U", "Parent" : "0"},
	{"ID" : "57", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_24_U", "Parent" : "0"},
	{"ID" : "58", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_25_U", "Parent" : "0"},
	{"ID" : "59", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_26_U", "Parent" : "0"},
	{"ID" : "60", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_27_U", "Parent" : "0"},
	{"ID" : "61", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_28_U", "Parent" : "0"},
	{"ID" : "62", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_29_U", "Parent" : "0"},
	{"ID" : "63", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_30_U", "Parent" : "0"},
	{"ID" : "64", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l2_8b32_31_U", "Parent" : "0"},
	{"ID" : "65", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_0_U", "Parent" : "0"},
	{"ID" : "66", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_1_U", "Parent" : "0"},
	{"ID" : "67", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_2_U", "Parent" : "0"},
	{"ID" : "68", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_3_U", "Parent" : "0"},
	{"ID" : "69", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_4_U", "Parent" : "0"},
	{"ID" : "70", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_5_U", "Parent" : "0"},
	{"ID" : "71", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_6_U", "Parent" : "0"},
	{"ID" : "72", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_7_U", "Parent" : "0"},
	{"ID" : "73", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_8_U", "Parent" : "0"},
	{"ID" : "74", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_9_U", "Parent" : "0"},
	{"ID" : "75", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_10_U", "Parent" : "0"},
	{"ID" : "76", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_11_U", "Parent" : "0"},
	{"ID" : "77", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_12_U", "Parent" : "0"},
	{"ID" : "78", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_13_U", "Parent" : "0"},
	{"ID" : "79", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_14_U", "Parent" : "0"},
	{"ID" : "80", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_15_U", "Parent" : "0"},
	{"ID" : "81", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_16_U", "Parent" : "0"},
	{"ID" : "82", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_17_U", "Parent" : "0"},
	{"ID" : "83", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_18_U", "Parent" : "0"},
	{"ID" : "84", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_19_U", "Parent" : "0"},
	{"ID" : "85", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_20_U", "Parent" : "0"},
	{"ID" : "86", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_21_U", "Parent" : "0"},
	{"ID" : "87", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_22_U", "Parent" : "0"},
	{"ID" : "88", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_23_U", "Parent" : "0"},
	{"ID" : "89", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_24_U", "Parent" : "0"},
	{"ID" : "90", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_25_U", "Parent" : "0"},
	{"ID" : "91", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_26_U", "Parent" : "0"},
	{"ID" : "92", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_27_U", "Parent" : "0"},
	{"ID" : "93", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_28_U", "Parent" : "0"},
	{"ID" : "94", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_29_U", "Parent" : "0"},
	{"ID" : "95", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_30_U", "Parent" : "0"},
	{"ID" : "96", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.weights_l3_8b32_31_U", "Parent" : "0"},
	{"ID" : "97", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_CTRL_BUS_s_axi_U", "Parent" : "0"},
	{"ID" : "98", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_0_U", "Parent" : "0"},
	{"ID" : "99", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_1_U", "Parent" : "0"},
	{"ID" : "100", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_2_U", "Parent" : "0"},
	{"ID" : "101", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_3_U", "Parent" : "0"},
	{"ID" : "102", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_4_U", "Parent" : "0"},
	{"ID" : "103", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_5_U", "Parent" : "0"},
	{"ID" : "104", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_6_U", "Parent" : "0"},
	{"ID" : "105", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_7_U", "Parent" : "0"},
	{"ID" : "106", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_8_U", "Parent" : "0"},
	{"ID" : "107", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_9_U", "Parent" : "0"},
	{"ID" : "108", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_10_U", "Parent" : "0"},
	{"ID" : "109", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_11_U", "Parent" : "0"},
	{"ID" : "110", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_12_U", "Parent" : "0"},
	{"ID" : "111", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_13_U", "Parent" : "0"},
	{"ID" : "112", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_14_U", "Parent" : "0"},
	{"ID" : "113", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_15_U", "Parent" : "0"},
	{"ID" : "114", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_16_U", "Parent" : "0"},
	{"ID" : "115", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_17_U", "Parent" : "0"},
	{"ID" : "116", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_18_U", "Parent" : "0"},
	{"ID" : "117", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_19_U", "Parent" : "0"},
	{"ID" : "118", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_20_U", "Parent" : "0"},
	{"ID" : "119", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_21_U", "Parent" : "0"},
	{"ID" : "120", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_22_U", "Parent" : "0"},
	{"ID" : "121", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_23_U", "Parent" : "0"},
	{"ID" : "122", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_24_U", "Parent" : "0"},
	{"ID" : "123", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_25_U", "Parent" : "0"},
	{"ID" : "124", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_26_U", "Parent" : "0"},
	{"ID" : "125", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_27_U", "Parent" : "0"},
	{"ID" : "126", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_28_U", "Parent" : "0"},
	{"ID" : "127", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_29_U", "Parent" : "0"},
	{"ID" : "128", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_30_U", "Parent" : "0"},
	{"ID" : "129", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.input_buf_31_U", "Parent" : "0"},
	{"ID" : "130", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U1", "Parent" : "0"},
	{"ID" : "131", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U2", "Parent" : "0"},
	{"ID" : "132", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U3", "Parent" : "0"},
	{"ID" : "133", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U4", "Parent" : "0"},
	{"ID" : "134", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U5", "Parent" : "0"},
	{"ID" : "135", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U6", "Parent" : "0"},
	{"ID" : "136", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U7", "Parent" : "0"},
	{"ID" : "137", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U8", "Parent" : "0"},
	{"ID" : "138", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U9", "Parent" : "0"},
	{"ID" : "139", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U10", "Parent" : "0"},
	{"ID" : "140", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U11", "Parent" : "0"},
	{"ID" : "141", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U12", "Parent" : "0"},
	{"ID" : "142", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U13", "Parent" : "0"},
	{"ID" : "143", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U14", "Parent" : "0"},
	{"ID" : "144", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U15", "Parent" : "0"},
	{"ID" : "145", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U16", "Parent" : "0"},
	{"ID" : "146", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U17", "Parent" : "0"},
	{"ID" : "147", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U18", "Parent" : "0"},
	{"ID" : "148", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U19", "Parent" : "0"},
	{"ID" : "149", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U20", "Parent" : "0"},
	{"ID" : "150", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U21", "Parent" : "0"},
	{"ID" : "151", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U22", "Parent" : "0"},
	{"ID" : "152", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U23", "Parent" : "0"},
	{"ID" : "153", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U24", "Parent" : "0"},
	{"ID" : "154", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U25", "Parent" : "0"},
	{"ID" : "155", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U26", "Parent" : "0"},
	{"ID" : "156", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U27", "Parent" : "0"},
	{"ID" : "157", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U28", "Parent" : "0"},
	{"ID" : "158", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U29", "Parent" : "0"},
	{"ID" : "159", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U30", "Parent" : "0"},
	{"ID" : "160", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U31", "Parent" : "0"},
	{"ID" : "161", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_42_8_1_1_U32", "Parent" : "0"},
	{"ID" : "162", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mux_104_8_1_1_U33", "Parent" : "0"},
	{"ID" : "163", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U34", "Parent" : "0"},
	{"ID" : "164", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U35", "Parent" : "0"},
	{"ID" : "165", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U36", "Parent" : "0"},
	{"ID" : "166", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U37", "Parent" : "0"},
	{"ID" : "167", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U38", "Parent" : "0"},
	{"ID" : "168", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U39", "Parent" : "0"},
	{"ID" : "169", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_7s_8s_15ns_15_1_1_U40", "Parent" : "0"},
	{"ID" : "170", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U41", "Parent" : "0"},
	{"ID" : "171", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_7s_8s_14ns_14_1_1_U42", "Parent" : "0"},
	{"ID" : "172", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U43", "Parent" : "0"},
	{"ID" : "173", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U44", "Parent" : "0"},
	{"ID" : "174", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U45", "Parent" : "0"},
	{"ID" : "175", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_7s_8s_14ns_14_1_1_U46", "Parent" : "0"},
	{"ID" : "176", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_7s_8s_15ns_15_1_1_U47", "Parent" : "0"},
	{"ID" : "177", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U48", "Parent" : "0"},
	{"ID" : "178", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U49", "Parent" : "0"},
	{"ID" : "179", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U50", "Parent" : "0"},
	{"ID" : "180", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U51", "Parent" : "0"},
	{"ID" : "181", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U52", "Parent" : "0"},
	{"ID" : "182", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U53", "Parent" : "0"},
	{"ID" : "183", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U54", "Parent" : "0"},
	{"ID" : "184", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U55", "Parent" : "0"},
	{"ID" : "185", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U56", "Parent" : "0"},
	{"ID" : "186", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U57", "Parent" : "0"},
	{"ID" : "187", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_7s_8s_15ns_15_1_1_U58", "Parent" : "0"},
	{"ID" : "188", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U59", "Parent" : "0"},
	{"ID" : "189", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U60", "Parent" : "0"},
	{"ID" : "190", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U61", "Parent" : "0"},
	{"ID" : "191", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U62", "Parent" : "0"},
	{"ID" : "192", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U63", "Parent" : "0"},
	{"ID" : "193", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U64", "Parent" : "0"},
	{"ID" : "194", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U65", "Parent" : "0"},
	{"ID" : "195", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_7s_8s_14ns_14_1_1_U66", "Parent" : "0"},
	{"ID" : "196", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U67", "Parent" : "0"},
	{"ID" : "197", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U68", "Parent" : "0"},
	{"ID" : "198", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U69", "Parent" : "0"},
	{"ID" : "199", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U70", "Parent" : "0"},
	{"ID" : "200", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U71", "Parent" : "0"},
	{"ID" : "201", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U72", "Parent" : "0"},
	{"ID" : "202", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U73", "Parent" : "0"},
	{"ID" : "203", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U74", "Parent" : "0"},
	{"ID" : "204", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U75", "Parent" : "0"},
	{"ID" : "205", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U76", "Parent" : "0"},
	{"ID" : "206", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_7s_8s_15ns_15_1_1_U77", "Parent" : "0"},
	{"ID" : "207", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_15ns_15_1_1_U78", "Parent" : "0"},
	{"ID" : "208", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U79", "Parent" : "0"},
	{"ID" : "209", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U80", "Parent" : "0"},
	{"ID" : "210", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.mlp_accel_8b32_mac_muladd_6s_8s_14ns_14_1_1_U81", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	mlp_accel_8b32 {
		in_vec {Type I LastRead 32 FirstWrite -1}
		out_vec {Type O LastRead -1 FirstWrite 11}
		weights_l1_8b32_0 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_1 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_2 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_3 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_4 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_5 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_6 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_7 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_8 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_9 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_10 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_11 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_12 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_13 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_14 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_15 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_16 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_17 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_18 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_19 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_20 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_21 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_22 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_23 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_24 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_25 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_26 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_27 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_28 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_29 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_30 {Type I LastRead -1 FirstWrite -1}
		weights_l1_8b32_31 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_0 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_1 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_2 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_3 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_4 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_5 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_6 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_7 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_8 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_9 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_10 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_11 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_12 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_13 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_14 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_15 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_16 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_17 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_18 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_19 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_20 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_21 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_22 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_23 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_24 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_25 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_26 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_27 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_28 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_29 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_30 {Type I LastRead -1 FirstWrite -1}
		weights_l2_8b32_31 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_0 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_1 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_2 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_3 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_4 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_5 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_6 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_7 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_8 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_9 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_10 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_11 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_12 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_13 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_14 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_15 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_16 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_17 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_18 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_19 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_20 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_21 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_22 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_23 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_24 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_25 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_26 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_27 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_28 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_29 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_30 {Type I LastRead -1 FirstWrite -1}
		weights_l3_8b32_31 {Type I LastRead -1 FirstWrite -1}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "5578", "Max" : "5578"}
	, {"Name" : "Interval", "Min" : "5579", "Max" : "5579"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
	{"Pipeline" : "1", "EnableSignal" : "ap_enable_pp1"}
	{"Pipeline" : "2", "EnableSignal" : "ap_enable_pp2"}
	{"Pipeline" : "3", "EnableSignal" : "ap_enable_pp3"}
]}

set Spec2ImplPortList { 
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
