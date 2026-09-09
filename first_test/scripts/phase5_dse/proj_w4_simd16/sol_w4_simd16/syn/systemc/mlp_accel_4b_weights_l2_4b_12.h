// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_12_H__
#define __mlp_accel_4b_weights_l2_4b_12_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_12_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_12_ram) {
        ram[0] = "0b001";
        ram[1] = "0b111";
        for (unsigned i = 2; i < 8 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[8] = "0b001";
        ram[9] = "0b000";
        ram[10] = "0b000";
        ram[11] = "0b000";
        ram[12] = "0b000";
        ram[13] = "0b111";
        ram[14] = "0b110";
        for (unsigned i = 15; i < 22 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[22] = "0b010";
        ram[23] = "0b111";
        ram[24] = "0b111";
        ram[25] = "0b111";
        ram[26] = "0b000";
        ram[27] = "0b111";
        ram[28] = "0b001";
        ram[29] = "0b000";
        ram[30] = "0b111";
        ram[31] = "0b111";
        ram[32] = "0b000";
        ram[33] = "0b111";
        ram[34] = "0b000";
        ram[35] = "0b000";
        ram[36] = "0b000";
        ram[37] = "0b000";
        ram[38] = "0b110";
        ram[39] = "0b001";
        ram[40] = "0b000";
        ram[41] = "0b111";
        ram[42] = "0b000";
        ram[43] = "0b000";
        ram[44] = "0b000";
        ram[45] = "0b001";
        ram[46] = "0b000";
        ram[47] = "0b010";
        ram[48] = "0b111";
        ram[49] = "0b001";
        ram[50] = "0b000";
        ram[51] = "0b001";
        ram[52] = "0b000";
        ram[53] = "0b000";
        ram[54] = "0b111";
        ram[55] = "0b000";
        ram[56] = "0b000";
        ram[57] = "0b000";
        ram[58] = "0b000";
        ram[59] = "0b001";
        for (unsigned i = 60; i < 70 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[70] = "0b001";
        ram[71] = "0b000";
        ram[72] = "0b000";
        ram[73] = "0b001";
        ram[74] = "0b000";
        ram[75] = "0b000";
        ram[76] = "0b000";
        ram[77] = "0b000";
        ram[78] = "0b001";
        ram[79] = "0b001";
        ram[80] = "0b111";
        ram[81] = "0b000";
        ram[82] = "0b000";
        ram[83] = "0b111";
        ram[84] = "0b000";
        ram[85] = "0b000";
        ram[86] = "0b010";
        ram[87] = "0b111";
        ram[88] = "0b111";
        ram[89] = "0b000";
        ram[90] = "0b000";
        ram[91] = "0b000";
        ram[92] = "0b000";
        ram[93] = "0b001";
        ram[94] = "0b001";
        ram[95] = "0b000";
        ram[96] = "0b000";
        ram[97] = "0b001";
        ram[98] = "0b000";
        ram[99] = "0b001";
        ram[100] = "0b000";
        ram[101] = "0b111";
        ram[102] = "0b111";
        ram[103] = "0b111";
        ram[104] = "0b000";
        ram[105] = "0b001";
        ram[106] = "0b000";
        ram[107] = "0b000";
        ram[108] = "0b000";
        ram[109] = "0b111";
        ram[110] = "0b111";
        ram[111] = "0b000";
        ram[112] = "0b001";
        for (unsigned i = 113; i < 118 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[118] = "0b111";
        ram[119] = "0b111";
        for (unsigned i = 120; i < 127 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[127] = "0b111";
        for (unsigned i = 128; i < 136 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[136] = "0b001";
        for (unsigned i = 137; i < 142 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[142] = "0b110";
        ram[143] = "0b000";
        ram[144] = "0b000";
        ram[145] = "0b000";
        ram[146] = "0b000";
        ram[147] = "0b001";
        ram[148] = "0b000";
        ram[149] = "0b001";
        ram[150] = "0b001";
        ram[151] = "0b001";
        ram[152] = "0b000";
        ram[153] = "0b111";
        ram[154] = "0b000";
        ram[155] = "0b000";
        ram[156] = "0b000";
        ram[157] = "0b000";
        ram[158] = "0b010";
        ram[159] = "0b000";
        ram[160] = "0b000";
        ram[161] = "0b111";
        ram[162] = "0b000";
        ram[163] = "0b111";
        for (unsigned i = 164; i < 171 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[171] = "0b001";
        ram[172] = "0b000";
        ram[173] = "0b000";
        ram[174] = "0b001";
        ram[175] = "0b111";
        ram[176] = "0b000";
        ram[177] = "0b000";
        ram[178] = "0b000";
        ram[179] = "0b001";
        ram[180] = "0b000";
        ram[181] = "0b000";
        ram[182] = "0b001";
        ram[183] = "0b001";
        for (unsigned i = 184; i < 195 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[195] = "0b001";
        ram[196] = "0b000";
        ram[197] = "0b000";
        ram[198] = "0b001";
        ram[199] = "0b111";
        ram[200] = "0b001";
        ram[201] = "0b000";
        ram[202] = "0b000";
        ram[203] = "0b000";
        ram[204] = "0b000";
        ram[205] = "0b001";
        ram[206] = "0b111";
        ram[207] = "0b000";
        ram[208] = "0b000";
        ram[209] = "0b001";
        ram[210] = "0b000";
        ram[211] = "0b001";
        ram[212] = "0b000";
        ram[213] = "0b001";
        ram[214] = "0b001";
        ram[215] = "0b000";
        ram[216] = "0b000";
        ram[217] = "0b001";
        ram[218] = "0b000";
        ram[219] = "0b000";
        ram[220] = "0b000";
        ram[221] = "0b001";
        ram[222] = "0b001";
        ram[223] = "0b111";
        for (unsigned i = 224; i < 232 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[232] = "0b001";
        for (unsigned i = 233; i < 238 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[238] = "0b111";
        ram[239] = "0b000";
        ram[240] = "0b000";
        ram[241] = "0b111";
        for (unsigned i = 242; i < 254 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[254] = "0b001";
        ram[255] = "0b000";
        ram[256] = "0b001";
        ram[257] = "0b111";
        ram[258] = "0b000";
        ram[259] = "0b000";
        ram[260] = "0b000";
        ram[261] = "0b001";
        for (unsigned i = 262; i < 269 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[269] = "0b001";
        ram[270] = "0b000";
        ram[271] = "0b111";
        ram[272] = "0b000";
        ram[273] = "0b110";
        ram[274] = "0b000";
        ram[275] = "0b111";
        ram[276] = "0b000";
        ram[277] = "0b000";
        ram[278] = "0b001";
        ram[279] = "0b001";
        ram[280] = "0b111";
        ram[281] = "0b001";
        ram[282] = "0b000";
        ram[283] = "0b001";
        ram[284] = "0b000";
        ram[285] = "0b000";
        ram[286] = "0b001";
        ram[287] = "0b000";
        ram[288] = "0b000";
        ram[289] = "0b001";
        ram[290] = "0b000";
        ram[291] = "0b001";
        ram[292] = "0b001";
        ram[293] = "0b000";
        ram[294] = "0b110";
        ram[295] = "0b001";
        ram[296] = "0b001";
        ram[297] = "0b000";
        ram[298] = "0b000";
        ram[299] = "0b111";
        for (unsigned i = 300; i < 305 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[305] = "0b001";
        ram[306] = "0b000";
        ram[307] = "0b001";
        ram[308] = "0b000";
        ram[309] = "0b000";
        ram[310] = "0b111";
        ram[311] = "0b001";
        ram[312] = "0b000";
        ram[313] = "0b111";
        ram[314] = "0b000";
        ram[315] = "0b000";
        ram[316] = "0b000";
        ram[317] = "0b111";
        ram[318] = "0b010";
        ram[319] = "0b001";
        for (unsigned i = 320; i < 325 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[325] = "0b111";
        ram[326] = "0b111";
        ram[327] = "0b000";
        ram[328] = "0b001";
        ram[329] = "0b000";
        ram[330] = "0b000";
        ram[331] = "0b111";
        for (unsigned i = 332; i < 347 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[347] = "0b111";
        ram[348] = "0b000";
        ram[349] = "0b000";
        ram[350] = "0b001";
        ram[351] = "0b001";
        ram[352] = "0b000";
        ram[353] = "0b111";
        for (unsigned i = 354; i < 367 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[367] = "0b111";
        ram[368] = "0b111";
        for (unsigned i = 369; i < 374 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[374] = "0b001";
        ram[375] = "0b000";
        ram[376] = "0b000";
        ram[377] = "0b111";
        ram[378] = "0b000";
        ram[379] = "0b111";
        ram[380] = "0b000";
        ram[381] = "0b111";
        ram[382] = "0b000";
        ram[383] = "0b111";
        ram[384] = "0b000";
        ram[385] = "0b001";
        ram[386] = "0b000";
        ram[387] = "0b001";
        ram[388] = "0b000";
        ram[389] = "0b001";
        ram[390] = "0b111";
        ram[391] = "0b001";
        for (unsigned i = 392; i < 398 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[398] = "0b110";
        ram[399] = "0b111";
        ram[400] = "0b001";
        ram[401] = "0b111";
        ram[402] = "0b000";
        ram[403] = "0b111";
        ram[404] = "0b001";
        ram[405] = "0b111";
        ram[406] = "0b001";
        ram[407] = "0b001";
        for (unsigned i = 408; i < 416 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[416] = "0b001";
        for (unsigned i = 417; i < 422 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[422] = "0b111";
        for (unsigned i = 423; i < 430 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[430] = "0b111";
        for (unsigned i = 431; i < 438 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[438] = "0b111";
        ram[439] = "0b111";
        ram[440] = "0b111";
        ram[441] = "0b010";
        ram[442] = "0b000";
        ram[443] = "0b010";
        for (unsigned i = 444; i < 449 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[449] = "0b110";
        ram[450] = "0b000";
        ram[451] = "0b111";
        ram[452] = "0b000";
        ram[453] = "0b000";
        ram[454] = "0b001";
        for (unsigned i = 455; i < 471 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[471] = "0b001";
        ram[472] = "0b111";
        for (unsigned i = 473; i < 478 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[478] = "0b001";
        for (unsigned i = 479; i < 487 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[487] = "0b010";
        for (unsigned i = 488; i < 497 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[497] = "0b111";
        for (unsigned i = 498; i < 503 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[503] = "0b001";
        ram[504] = "0b000";
        ram[505] = "0b111";
        ram[506] = "0b000";
        ram[507] = "0b111";
        ram[508] = "0b000";
        ram[509] = "0b001";
        ram[510] = "0b111";
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_12) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_12_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_12) {
meminst = new mlp_accel_4b_weights_l2_4b_12_ram("mlp_accel_4b_weights_l2_4b_12_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_12() {
    delete meminst;
}


};//endmodule
#endif
