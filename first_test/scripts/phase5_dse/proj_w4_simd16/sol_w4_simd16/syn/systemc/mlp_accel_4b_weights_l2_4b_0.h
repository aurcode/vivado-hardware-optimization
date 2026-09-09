// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_0_H__
#define __mlp_accel_4b_weights_l2_4b_0_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_0_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_0_ram) {
        ram[0] = "0b000";
        ram[1] = "0b001";
        ram[2] = "0b000";
        ram[3] = "0b101";
        ram[4] = "0b000";
        ram[5] = "0b000";
        ram[6] = "0b000";
        ram[7] = "0b111";
        ram[8] = "0b001";
        ram[9] = "0b001";
        ram[10] = "0b000";
        ram[11] = "0b001";
        ram[12] = "0b111";
        ram[13] = "0b000";
        ram[14] = "0b000";
        ram[15] = "0b001";
        ram[16] = "0b000";
        ram[17] = "0b000";
        ram[18] = "0b111";
        ram[19] = "0b000";
        ram[20] = "0b001";
        for (unsigned i = 21; i < 26 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[26] = "0b001";
        ram[27] = "0b001";
        ram[28] = "0b001";
        ram[29] = "0b000";
        ram[30] = "0b000";
        ram[31] = "0b000";
        ram[32] = "0b001";
        ram[33] = "0b000";
        ram[34] = "0b000";
        ram[35] = "0b001";
        ram[36] = "0b000";
        ram[37] = "0b001";
        ram[38] = "0b001";
        ram[39] = "0b001";
        ram[40] = "0b000";
        ram[41] = "0b000";
        ram[42] = "0b111";
        ram[43] = "0b000";
        ram[44] = "0b001";
        ram[45] = "0b000";
        ram[46] = "0b000";
        ram[47] = "0b000";
        ram[48] = "0b001";
        ram[49] = "0b000";
        ram[50] = "0b000";
        ram[51] = "0b001";
        ram[52] = "0b000";
        ram[53] = "0b000";
        ram[54] = "0b001";
        ram[55] = "0b000";
        ram[56] = "0b000";
        ram[57] = "0b001";
        ram[58] = "0b000";
        ram[59] = "0b111";
        ram[60] = "0b111";
        ram[61] = "0b000";
        ram[62] = "0b000";
        ram[63] = "0b111";
        ram[64] = "0b000";
        ram[65] = "0b000";
        ram[66] = "0b000";
        ram[67] = "0b000";
        ram[68] = "0b111";
        for (unsigned i = 69; i < 75 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[75] = "0b001";
        ram[76] = "0b110";
        ram[77] = "0b000";
        ram[78] = "0b111";
        ram[79] = "0b111";
        ram[80] = "0b000";
        ram[81] = "0b000";
        ram[82] = "0b000";
        ram[83] = "0b111";
        for (unsigned i = 84; i < 89 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[89] = "0b001";
        ram[90] = "0b000";
        ram[91] = "0b000";
        ram[92] = "0b001";
        ram[93] = "0b000";
        ram[94] = "0b001";
        ram[95] = "0b001";
        ram[96] = "0b000";
        ram[97] = "0b001";
        ram[98] = "0b000";
        ram[99] = "0b010";
        ram[100] = "0b111";
        for (unsigned i = 101; i < 106 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[106] = "0b001";
        ram[107] = "0b000";
        ram[108] = "0b000";
        ram[109] = "0b000";
        ram[110] = "0b000";
        ram[111] = "0b111";
        ram[112] = "0b000";
        ram[113] = "0b001";
        for (unsigned i = 114; i < 121 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[121] = "0b001";
        ram[122] = "0b000";
        ram[123] = "0b000";
        ram[124] = "0b010";
        ram[125] = "0b000";
        ram[126] = "0b000";
        ram[127] = "0b001";
        for (unsigned i = 128; i < 137 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[137] = "0b001";
        ram[138] = "0b000";
        ram[139] = "0b000";
        ram[140] = "0b111";
        ram[141] = "0b000";
        ram[142] = "0b000";
        ram[143] = "0b111";
        for (unsigned i = 144; i < 151 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[151] = "0b111";
        ram[152] = "0b000";
        ram[153] = "0b000";
        ram[154] = "0b000";
        ram[155] = "0b110";
        ram[156] = "0b000";
        ram[157] = "0b000";
        ram[158] = "0b000";
        ram[159] = "0b111";
        ram[160] = "0b000";
        ram[161] = "0b001";
        ram[162] = "0b001";
        ram[163] = "0b000";
        ram[164] = "0b001";
        ram[165] = "0b001";
        ram[166] = "0b000";
        ram[167] = "0b000";
        ram[168] = "0b000";
        ram[169] = "0b001";
        ram[170] = "0b000";
        ram[171] = "0b000";
        ram[172] = "0b111";
        ram[173] = "0b000";
        ram[174] = "0b000";
        ram[175] = "0b111";
        ram[176] = "0b000";
        ram[177] = "0b111";
        ram[178] = "0b111";
        ram[179] = "0b001";
        ram[180] = "0b000";
        ram[181] = "0b000";
        ram[182] = "0b000";
        ram[183] = "0b111";
        for (unsigned i = 184; i < 196 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[196] = "0b111";
        ram[197] = "0b000";
        ram[198] = "0b111";
        for (unsigned i = 199; i < 204 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[204] = "0b001";
        ram[205] = "0b001";
        ram[206] = "0b000";
        ram[207] = "0b010";
        ram[208] = "0b000";
        ram[209] = "0b000";
        ram[210] = "0b000";
        ram[211] = "0b000";
        ram[212] = "0b001";
        ram[213] = "0b111";
        ram[214] = "0b000";
        ram[215] = "0b000";
        ram[216] = "0b000";
        ram[217] = "0b001";
        ram[218] = "0b001";
        ram[219] = "0b111";
        ram[220] = "0b001";
        ram[221] = "0b000";
        ram[222] = "0b000";
        ram[223] = "0b111";
        for (unsigned i = 224; i < 235 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[235] = "0b110";
        ram[236] = "0b000";
        ram[237] = "0b000";
        ram[238] = "0b000";
        ram[239] = "0b111";
        ram[240] = "0b000";
        ram[241] = "0b001";
        ram[242] = "0b000";
        ram[243] = "0b111";
        ram[244] = "0b001";
        ram[245] = "0b000";
        ram[246] = "0b000";
        ram[247] = "0b111";
        ram[248] = "0b111";
        ram[249] = "0b000";
        ram[250] = "0b000";
        ram[251] = "0b001";
        ram[252] = "0b001";
        ram[253] = "0b000";
        ram[254] = "0b000";
        ram[255] = "0b001";
        ram[256] = "0b000";
        ram[257] = "0b000";
        ram[258] = "0b111";
        ram[259] = "0b000";
        ram[260] = "0b010";
        ram[261] = "0b000";
        ram[262] = "0b000";
        ram[263] = "0b001";
        ram[264] = "0b000";
        ram[265] = "0b000";
        ram[266] = "0b000";
        ram[267] = "0b001";
        ram[268] = "0b000";
        ram[269] = "0b001";
        for (unsigned i = 270; i < 275 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[275] = "0b110";
        ram[276] = "0b000";
        ram[277] = "0b000";
        ram[278] = "0b111";
        ram[279] = "0b111";
        ram[280] = "0b111";
        ram[281] = "0b111";
        ram[282] = "0b000";
        ram[283] = "0b001";
        ram[284] = "0b000";
        ram[285] = "0b000";
        ram[286] = "0b000";
        ram[287] = "0b111";
        ram[288] = "0b000";
        ram[289] = "0b000";
        ram[290] = "0b000";
        ram[291] = "0b001";
        ram[292] = "0b000";
        ram[293] = "0b000";
        ram[294] = "0b001";
        ram[295] = "0b001";
        ram[296] = "0b000";
        ram[297] = "0b000";
        ram[298] = "0b000";
        ram[299] = "0b111";
        ram[300] = "0b000";
        ram[301] = "0b001";
        ram[302] = "0b000";
        ram[303] = "0b000";
        ram[304] = "0b000";
        ram[305] = "0b000";
        ram[306] = "0b111";
        ram[307] = "0b001";
        ram[308] = "0b111";
        ram[309] = "0b000";
        ram[310] = "0b000";
        ram[311] = "0b000";
        ram[312] = "0b000";
        ram[313] = "0b001";
        ram[314] = "0b000";
        ram[315] = "0b111";
        ram[316] = "0b111";
        ram[317] = "0b111";
        ram[318] = "0b000";
        ram[319] = "0b111";
        ram[320] = "0b001";
        for (unsigned i = 321; i < 329 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[329] = "0b110";
        ram[330] = "0b000";
        ram[331] = "0b111";
        for (unsigned i = 332; i < 345 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[345] = "0b111";
        ram[346] = "0b000";
        ram[347] = "0b111";
        for (unsigned i = 348; i < 353 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[353] = "0b111";
        ram[354] = "0b000";
        ram[355] = "0b000";
        ram[356] = "0b010";
        ram[357] = "0b000";
        ram[358] = "0b000";
        ram[359] = "0b001";
        for (unsigned i = 360; i < 366 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[366] = "0b111";
        ram[367] = "0b000";
        ram[368] = "0b000";
        ram[369] = "0b000";
        ram[370] = "0b000";
        ram[371] = "0b001";
        ram[372] = "0b000";
        ram[373] = "0b000";
        ram[374] = "0b000";
        ram[375] = "0b001";
        for (unsigned i = 376; i < 382 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[382] = "0b111";
        ram[383] = "0b001";
        ram[384] = "0b000";
        ram[385] = "0b000";
        ram[386] = "0b000";
        ram[387] = "0b001";
        ram[388] = "0b001";
        ram[389] = "0b000";
        ram[390] = "0b000";
        ram[391] = "0b001";
        for (unsigned i = 392; i < 397 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[397] = "0b001";
        ram[398] = "0b001";
        ram[399] = "0b111";
        ram[400] = "0b000";
        ram[401] = "0b000";
        ram[402] = "0b000";
        ram[403] = "0b111";
        ram[404] = "0b111";
        for (unsigned i = 405; i < 419 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[419] = "0b111";
        ram[420] = "0b000";
        ram[421] = "0b000";
        ram[422] = "0b000";
        ram[423] = "0b111";
        ram[424] = "0b111";
        ram[425] = "0b111";
        ram[426] = "0b000";
        ram[427] = "0b001";
        ram[428] = "0b001";
        ram[429] = "0b000";
        ram[430] = "0b000";
        ram[431] = "0b010";
        ram[432] = "0b000";
        ram[433] = "0b000";
        ram[434] = "0b000";
        ram[435] = "0b001";
        ram[436] = "0b001";
        ram[437] = "0b000";
        ram[438] = "0b000";
        ram[439] = "0b010";
        ram[440] = "0b000";
        ram[441] = "0b000";
        ram[442] = "0b001";
        ram[443] = "0b000";
        ram[444] = "0b000";
        ram[445] = "0b000";
        ram[446] = "0b001";
        ram[447] = "0b000";
        ram[448] = "0b000";
        ram[449] = "0b000";
        ram[450] = "0b000";
        ram[451] = "0b111";
        ram[452] = "0b001";
        ram[453] = "0b000";
        ram[454] = "0b000";
        ram[455] = "0b000";
        ram[456] = "0b000";
        ram[457] = "0b111";
        ram[458] = "0b000";
        ram[459] = "0b000";
        ram[460] = "0b001";
        ram[461] = "0b001";
        ram[462] = "0b000";
        ram[463] = "0b001";
        ram[464] = "0b000";
        ram[465] = "0b000";
        ram[466] = "0b000";
        ram[467] = "0b010";
        ram[468] = "0b001";
        ram[469] = "0b000";
        ram[470] = "0b000";
        ram[471] = "0b010";
        ram[472] = "0b000";
        ram[473] = "0b000";
        ram[474] = "0b001";
        ram[475] = "0b001";
        ram[476] = "0b111";
        ram[477] = "0b000";
        ram[478] = "0b000";
        ram[479] = "0b000";
        ram[480] = "0b001";
        ram[481] = "0b111";
        ram[482] = "0b111";
        ram[483] = "0b000";
        ram[484] = "0b001";
        ram[485] = "0b000";
        ram[486] = "0b001";
        for (unsigned i = 487; i < 497 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[497] = "0b001";
        for (unsigned i = 498; i < 509 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[509] = "0b001";
        ram[510] = "0b000";
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_0) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_0_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_0) {
meminst = new mlp_accel_4b_weights_l2_4b_0_ram("mlp_accel_4b_weights_l2_4b_0_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_0() {
    delete meminst;
}


};//endmodule
#endif
