// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_5_H__
#define __mlp_accel_4b_weights_l2_4b_5_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_5_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 3;
  static const unsigned AddressRange = 512;
  static const unsigned AddressWidth = 9;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(mlp_accel_4b_weights_l2_4b_5_ram) {
        ram[0] = "0b000";
        ram[1] = "0b000";
        ram[2] = "0b000";
        ram[3] = "0b000";
        ram[4] = "0b111";
        ram[5] = "0b111";
        ram[6] = "0b000";
        ram[7] = "0b000";
        ram[8] = "0b000";
        ram[9] = "0b001";
        ram[10] = "0b000";
        ram[11] = "0b001";
        ram[12] = "0b001";
        ram[13] = "0b001";
        ram[14] = "0b000";
        ram[15] = "0b000";
        ram[16] = "0b000";
        ram[17] = "0b111";
        ram[18] = "0b000";
        ram[19] = "0b000";
        ram[20] = "0b111";
        ram[21] = "0b000";
        ram[22] = "0b001";
        ram[23] = "0b000";
        ram[24] = "0b000";
        ram[25] = "0b000";
        ram[26] = "0b001";
        ram[27] = "0b000";
        ram[28] = "0b010";
        ram[29] = "0b000";
        ram[30] = "0b000";
        ram[31] = "0b001";
        ram[32] = "0b000";
        ram[33] = "0b000";
        ram[34] = "0b000";
        ram[35] = "0b000";
        ram[36] = "0b001";
        ram[37] = "0b001";
        ram[38] = "0b000";
        ram[39] = "0b000";
        ram[40] = "0b000";
        ram[41] = "0b111";
        ram[42] = "0b111";
        ram[43] = "0b111";
        ram[44] = "0b000";
        ram[45] = "0b001";
        ram[46] = "0b000";
        ram[47] = "0b000";
        ram[48] = "0b000";
        ram[49] = "0b000";
        ram[50] = "0b001";
        for (unsigned i = 51; i < 57 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[57] = "0b001";
        ram[58] = "0b000";
        ram[59] = "0b000";
        ram[60] = "0b000";
        ram[61] = "0b111";
        ram[62] = "0b000";
        ram[63] = "0b000";
        ram[64] = "0b000";
        ram[65] = "0b001";
        ram[66] = "0b000";
        ram[67] = "0b001";
        for (unsigned i = 68; i < 74 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[74] = "0b111";
        ram[75] = "0b000";
        ram[76] = "0b111";
        for (unsigned i = 77; i < 83 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[83] = "0b001";
        ram[84] = "0b000";
        ram[85] = "0b111";
        ram[86] = "0b000";
        ram[87] = "0b000";
        ram[88] = "0b000";
        ram[89] = "0b000";
        ram[90] = "0b001";
        ram[91] = "0b111";
        ram[92] = "0b001";
        ram[93] = "0b001";
        for (unsigned i = 94; i < 111 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[111] = "0b001";
        ram[112] = "0b000";
        ram[113] = "0b000";
        ram[114] = "0b000";
        ram[115] = "0b000";
        ram[116] = "0b001";
        ram[117] = "0b001";
        ram[118] = "0b000";
        ram[119] = "0b000";
        ram[120] = "0b000";
        ram[121] = "0b000";
        ram[122] = "0b001";
        ram[123] = "0b000";
        ram[124] = "0b000";
        ram[125] = "0b001";
        for (unsigned i = 126; i < 137 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[137] = "0b001";
        ram[138] = "0b111";
        for (unsigned i = 139; i < 145 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[145] = "0b111";
        ram[146] = "0b000";
        ram[147] = "0b111";
        ram[148] = "0b111";
        ram[149] = "0b000";
        ram[150] = "0b000";
        ram[151] = "0b001";
        ram[152] = "0b000";
        ram[153] = "0b000";
        ram[154] = "0b000";
        ram[155] = "0b000";
        ram[156] = "0b111";
        ram[157] = "0b000";
        ram[158] = "0b001";
        ram[159] = "0b001";
        ram[160] = "0b000";
        ram[161] = "0b000";
        ram[162] = "0b000";
        ram[163] = "0b000";
        ram[164] = "0b001";
        ram[165] = "0b001";
        ram[166] = "0b000";
        ram[167] = "0b000";
        ram[168] = "0b000";
        ram[169] = "0b001";
        ram[170] = "0b000";
        ram[171] = "0b000";
        ram[172] = "0b000";
        ram[173] = "0b000";
        ram[174] = "0b001";
        ram[175] = "0b000";
        ram[176] = "0b001";
        for (unsigned i = 177; i < 182 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[182] = "0b111";
        ram[183] = "0b111";
        for (unsigned i = 184; i < 194 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[194] = "0b111";
        ram[195] = "0b001";
        ram[196] = "0b000";
        ram[197] = "0b111";
        ram[198] = "0b001";
        ram[199] = "0b001";
        ram[200] = "0b000";
        ram[201] = "0b000";
        ram[202] = "0b000";
        ram[203] = "0b000";
        ram[204] = "0b001";
        ram[205] = "0b001";
        for (unsigned i = 206; i < 212 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[212] = "0b111";
        ram[213] = "0b000";
        ram[214] = "0b001";
        ram[215] = "0b000";
        ram[216] = "0b000";
        ram[217] = "0b000";
        ram[218] = "0b001";
        ram[219] = "0b000";
        ram[220] = "0b000";
        ram[221] = "0b111";
        ram[222] = "0b001";
        ram[223] = "0b001";
        for (unsigned i = 224; i < 236 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[236] = "0b111";
        ram[237] = "0b111";
        ram[238] = "0b000";
        ram[239] = "0b000";
        ram[240] = "0b000";
        ram[241] = "0b000";
        ram[242] = "0b001";
        ram[243] = "0b000";
        ram[244] = "0b000";
        ram[245] = "0b001";
        ram[246] = "0b000";
        ram[247] = "0b001";
        ram[248] = "0b000";
        ram[249] = "0b000";
        ram[250] = "0b000";
        ram[251] = "0b001";
        ram[252] = "0b000";
        ram[253] = "0b001";
        ram[254] = "0b000";
        ram[255] = "0b000";
        ram[256] = "0b000";
        ram[257] = "0b111";
        for (unsigned i = 258; i < 268 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[268] = "0b001";
        ram[269] = "0b000";
        ram[270] = "0b001";
        ram[271] = "0b000";
        ram[272] = "0b000";
        ram[273] = "0b000";
        ram[274] = "0b111";
        ram[275] = "0b000";
        ram[276] = "0b111";
        for (unsigned i = 277; i < 282 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[282] = "0b001";
        for (unsigned i = 283; i < 299 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[299] = "0b001";
        ram[300] = "0b000";
        ram[301] = "0b000";
        ram[302] = "0b001";
        ram[303] = "0b000";
        ram[304] = "0b000";
        ram[305] = "0b001";
        ram[306] = "0b111";
        ram[307] = "0b000";
        ram[308] = "0b111";
        ram[309] = "0b000";
        ram[310] = "0b000";
        ram[311] = "0b000";
        ram[312] = "0b000";
        ram[313] = "0b001";
        ram[314] = "0b111";
        ram[315] = "0b001";
        ram[316] = "0b111";
        ram[317] = "0b111";
        ram[318] = "0b000";
        ram[319] = "0b000";
        ram[320] = "0b000";
        ram[321] = "0b001";
        for (unsigned i = 322; i < 329 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[329] = "0b111";
        ram[330] = "0b000";
        ram[331] = "0b000";
        ram[332] = "0b111";
        ram[333] = "0b111";
        ram[334] = "0b000";
        ram[335] = "0b111";
        for (unsigned i = 336; i < 346 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[346] = "0b001";
        ram[347] = "0b000";
        ram[348] = "0b000";
        ram[349] = "0b111";
        for (unsigned i = 350; i < 366 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[366] = "0b001";
        ram[367] = "0b000";
        ram[368] = "0b000";
        ram[369] = "0b000";
        ram[370] = "0b001";
        ram[371] = "0b001";
        ram[372] = "0b001";
        for (unsigned i = 373; i < 379 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[379] = "0b001";
        ram[380] = "0b000";
        ram[381] = "0b001";
        ram[382] = "0b000";
        ram[383] = "0b000";
        ram[384] = "0b000";
        ram[385] = "0b000";
        ram[386] = "0b001";
        ram[387] = "0b000";
        ram[388] = "0b001";
        ram[389] = "0b001";
        for (unsigned i = 390; i < 396 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[396] = "0b001";
        for (unsigned i = 397; i < 402 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[402] = "0b111";
        ram[403] = "0b000";
        ram[404] = "0b111";
        ram[405] = "0b111";
        for (unsigned i = 406; i < 421 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[421] = "0b111";
        ram[422] = "0b000";
        ram[423] = "0b000";
        ram[424] = "0b000";
        ram[425] = "0b000";
        ram[426] = "0b001";
        ram[427] = "0b000";
        ram[428] = "0b001";
        for (unsigned i = 429; i < 434 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[434] = "0b001";
        ram[435] = "0b000";
        ram[436] = "0b001";
        ram[437] = "0b010";
        for (unsigned i = 438; i < 443 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[443] = "0b111";
        ram[444] = "0b000";
        ram[445] = "0b000";
        ram[446] = "0b000";
        ram[447] = "0b001";
        ram[448] = "0b000";
        ram[449] = "0b000";
        ram[450] = "0b000";
        ram[451] = "0b000";
        ram[452] = "0b111";
        for (unsigned i = 453; i < 463 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[463] = "0b111";
        for (unsigned i = 464; i < 469 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[469] = "0b001";
        ram[470] = "0b111";
        ram[471] = "0b000";
        ram[472] = "0b000";
        ram[473] = "0b001";
        ram[474] = "0b001";
        ram[475] = "0b001";
        ram[476] = "0b001";
        for (unsigned i = 477; i < 483 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[483] = "0b111";
        for (unsigned i = 484; i < 501 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[501] = "0b001";
        ram[502] = "0b000";
        ram[503] = "0b000";
        ram[504] = "0b000";
        ram[505] = "0b000";
        ram[506] = "0b111";
        ram[507] = "0b000";
        ram[508] = "0b000";
        ram[509] = "0b111";
        ram[510] = "0b001";
        ram[511] = "0b000";


SC_METHOD(prc_write_0);
  sensitive<<clk.pos();
   }


void prc_write_0()
{
    if (ce0.read() == sc_dt::Log_1) 
    {
            if(address0.read().is_01() && address0.read().to_uint()<AddressRange)
              q0 = ram[address0.read().to_uint()];
            else
              q0 = sc_lv<DataWidth>();
    }
}


}; //endmodule


SC_MODULE(mlp_accel_4b_weights_l2_4b_5) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_5_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_5) {
meminst = new mlp_accel_4b_weights_l2_4b_5_ram("mlp_accel_4b_weights_l2_4b_5_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_5() {
    delete meminst;
}


};//endmodule
#endif
