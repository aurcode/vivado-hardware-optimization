// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_10_H__
#define __mlp_accel_4b_weights_l2_4b_10_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_10_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_10_ram) {
        ram[0] = "0b110";
        ram[1] = "0b000";
        ram[2] = "0b111";
        ram[3] = "0b111";
        ram[4] = "0b000";
        ram[5] = "0b000";
        ram[6] = "0b000";
        ram[7] = "0b111";
        ram[8] = "0b001";
        ram[9] = "0b001";
        ram[10] = "0b111";
        for (unsigned i = 11; i < 18 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[18] = "0b001";
        for (unsigned i = 19; i < 30 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[30] = "0b111";
        ram[31] = "0b111";
        for (unsigned i = 32; i < 38 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[38] = "0b001";
        ram[39] = "0b111";
        ram[40] = "0b111";
        ram[41] = "0b000";
        ram[42] = "0b001";
        ram[43] = "0b001";
        ram[44] = "0b000";
        ram[45] = "0b000";
        ram[46] = "0b001";
        ram[47] = "0b111";
        ram[48] = "0b000";
        ram[49] = "0b000";
        ram[50] = "0b111";
        ram[51] = "0b000";
        ram[52] = "0b000";
        ram[53] = "0b000";
        ram[54] = "0b111";
        ram[55] = "0b000";
        ram[56] = "0b000";
        ram[57] = "0b000";
        ram[58] = "0b111";
        ram[59] = "0b000";
        ram[60] = "0b000";
        ram[61] = "0b000";
        ram[62] = "0b111";
        ram[63] = "0b000";
        ram[64] = "0b000";
        ram[65] = "0b000";
        ram[66] = "0b111";
        ram[67] = "0b111";
        ram[68] = "0b000";
        ram[69] = "0b000";
        ram[70] = "0b000";
        ram[71] = "0b000";
        ram[72] = "0b010";
        ram[73] = "0b000";
        ram[74] = "0b001";
        ram[75] = "0b001";
        ram[76] = "0b000";
        ram[77] = "0b000";
        ram[78] = "0b001";
        ram[79] = "0b010";
        ram[80] = "0b000";
        ram[81] = "0b000";
        ram[82] = "0b001";
        ram[83] = "0b111";
        ram[84] = "0b000";
        ram[85] = "0b001";
        ram[86] = "0b111";
        ram[87] = "0b000";
        ram[88] = "0b000";
        ram[89] = "0b000";
        ram[90] = "0b111";
        ram[91] = "0b000";
        ram[92] = "0b000";
        ram[93] = "0b000";
        ram[94] = "0b000";
        ram[95] = "0b111";
        ram[96] = "0b010";
        ram[97] = "0b000";
        ram[98] = "0b111";
        ram[99] = "0b001";
        ram[100] = "0b000";
        ram[101] = "0b000";
        ram[102] = "0b111";
        for (unsigned i = 103; i < 111 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[111] = "0b001";
        for (unsigned i = 112; i < 120 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[120] = "0b111";
        for (unsigned i = 121; i < 127 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[127] = "0b111";
        for (unsigned i = 128; i < 140 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[140] = "0b001";
        ram[141] = "0b000";
        ram[142] = "0b001";
        ram[143] = "0b000";
        ram[144] = "0b000";
        ram[145] = "0b000";
        ram[146] = "0b000";
        ram[147] = "0b001";
        ram[148] = "0b000";
        ram[149] = "0b000";
        ram[150] = "0b000";
        ram[151] = "0b000";
        ram[152] = "0b111";
        for (unsigned i = 153; i < 160 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[160] = "0b111";
        ram[161] = "0b000";
        ram[162] = "0b001";
        ram[163] = "0b111";
        ram[164] = "0b000";
        ram[165] = "0b000";
        ram[166] = "0b001";
        ram[167] = "0b000";
        ram[168] = "0b001";
        ram[169] = "0b000";
        ram[170] = "0b111";
        for (unsigned i = 171; i < 178 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[178] = "0b001";
        ram[179] = "0b111";
        ram[180] = "0b000";
        ram[181] = "0b000";
        ram[182] = "0b001";
        for (unsigned i = 183; i < 192 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[192] = "0b001";
        ram[193] = "0b001";
        ram[194] = "0b001";
        ram[195] = "0b000";
        ram[196] = "0b000";
        ram[197] = "0b000";
        ram[198] = "0b000";
        ram[199] = "0b001";
        ram[200] = "0b000";
        ram[201] = "0b000";
        ram[202] = "0b001";
        ram[203] = "0b000";
        ram[204] = "0b000";
        ram[205] = "0b000";
        ram[206] = "0b001";
        ram[207] = "0b000";
        ram[208] = "0b001";
        ram[209] = "0b000";
        ram[210] = "0b000";
        ram[211] = "0b001";
        ram[212] = "0b000";
        ram[213] = "0b000";
        ram[214] = "0b000";
        ram[215] = "0b001";
        ram[216] = "0b111";
        ram[217] = "0b000";
        ram[218] = "0b111";
        ram[219] = "0b001";
        ram[220] = "0b000";
        ram[221] = "0b000";
        ram[222] = "0b111";
        ram[223] = "0b001";
        for (unsigned i = 224; i < 232 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[232] = "0b111";
        ram[233] = "0b000";
        ram[234] = "0b111";
        for (unsigned i = 235; i < 240 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[240] = "0b111";
        ram[241] = "0b000";
        ram[242] = "0b111";
        ram[243] = "0b000";
        ram[244] = "0b000";
        ram[245] = "0b000";
        ram[246] = "0b000";
        ram[247] = "0b111";
        ram[248] = "0b001";
        ram[249] = "0b000";
        ram[250] = "0b001";
        ram[251] = "0b000";
        ram[252] = "0b000";
        ram[253] = "0b000";
        ram[254] = "0b010";
        for (unsigned i = 255; i < 262 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[262] = "0b001";
        for (unsigned i = 263; i < 271 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[271] = "0b001";
        ram[272] = "0b111";
        for (unsigned i = 273; i < 279 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[279] = "0b111";
        ram[280] = "0b001";
        ram[281] = "0b000";
        ram[282] = "0b000";
        ram[283] = "0b001";
        ram[284] = "0b111";
        ram[285] = "0b111";
        ram[286] = "0b000";
        ram[287] = "0b001";
        ram[288] = "0b001";
        ram[289] = "0b000";
        ram[290] = "0b000";
        ram[291] = "0b001";
        ram[292] = "0b000";
        ram[293] = "0b000";
        ram[294] = "0b000";
        ram[295] = "0b001";
        ram[296] = "0b000";
        ram[297] = "0b000";
        ram[298] = "0b000";
        ram[299] = "0b001";
        ram[300] = "0b000";
        ram[301] = "0b000";
        ram[302] = "0b000";
        ram[303] = "0b001";
        ram[304] = "0b001";
        for (unsigned i = 305; i < 315 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[315] = "0b111";
        for (unsigned i = 316; i < 329 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[329] = "0b111";
        ram[330] = "0b001";
        for (unsigned i = 331; i < 352 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[352] = "0b111";
        ram[353] = "0b000";
        ram[354] = "0b001";
        ram[355] = "0b000";
        ram[356] = "0b000";
        ram[357] = "0b000";
        ram[358] = "0b000";
        ram[359] = "0b111";
        for (unsigned i = 360; i < 367 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[367] = "0b111";
        ram[368] = "0b001";
        ram[369] = "0b000";
        ram[370] = "0b000";
        ram[371] = "0b111";
        ram[372] = "0b111";
        ram[373] = "0b000";
        ram[374] = "0b000";
        ram[375] = "0b000";
        ram[376] = "0b111";
        ram[377] = "0b000";
        ram[378] = "0b000";
        ram[379] = "0b111";
        ram[380] = "0b000";
        ram[381] = "0b000";
        ram[382] = "0b000";
        ram[383] = "0b000";
        ram[384] = "0b001";
        ram[385] = "0b000";
        ram[386] = "0b000";
        ram[387] = "0b001";
        ram[388] = "0b001";
        for (unsigned i = 389; i < 400 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[400] = "0b111";
        ram[401] = "0b000";
        ram[402] = "0b000";
        ram[403] = "0b111";
        ram[404] = "0b000";
        ram[405] = "0b000";
        ram[406] = "0b001";
        ram[407] = "0b001";
        for (unsigned i = 408; i < 416 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[416] = "0b111";
        ram[417] = "0b000";
        ram[418] = "0b000";
        ram[419] = "0b001";
        ram[420] = "0b000";
        ram[421] = "0b001";
        ram[422] = "0b111";
        ram[423] = "0b001";
        ram[424] = "0b001";
        ram[425] = "0b000";
        ram[426] = "0b001";
        ram[427] = "0b000";
        ram[428] = "0b111";
        ram[429] = "0b000";
        ram[430] = "0b111";
        ram[431] = "0b000";
        ram[432] = "0b001";
        ram[433] = "0b000";
        ram[434] = "0b001";
        ram[435] = "0b000";
        ram[436] = "0b000";
        ram[437] = "0b000";
        ram[438] = "0b001";
        ram[439] = "0b000";
        ram[440] = "0b000";
        ram[441] = "0b000";
        ram[442] = "0b111";
        ram[443] = "0b001";
        ram[444] = "0b000";
        ram[445] = "0b000";
        ram[446] = "0b111";
        ram[447] = "0b001";
        ram[448] = "0b111";
        for (unsigned i = 449; i < 455 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[455] = "0b111";
        ram[456] = "0b000";
        ram[457] = "0b000";
        ram[458] = "0b001";
        ram[459] = "0b000";
        ram[460] = "0b000";
        ram[461] = "0b000";
        ram[462] = "0b000";
        ram[463] = "0b111";
        ram[464] = "0b001";
        ram[465] = "0b000";
        ram[466] = "0b001";
        ram[467] = "0b000";
        ram[468] = "0b000";
        ram[469] = "0b000";
        ram[470] = "0b001";
        ram[471] = "0b000";
        ram[472] = "0b001";
        ram[473] = "0b000";
        ram[474] = "0b000";
        ram[475] = "0b111";
        ram[476] = "0b000";
        ram[477] = "0b000";
        ram[478] = "0b000";
        ram[479] = "0b001";
        ram[480] = "0b000";
        ram[481] = "0b000";
        ram[482] = "0b001";
        ram[483] = "0b000";
        ram[484] = "0b000";
        ram[485] = "0b000";
        ram[486] = "0b001";
        for (unsigned i = 487; i < 497 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[497] = "0b001";
        ram[498] = "0b001";
        ram[499] = "0b000";
        ram[500] = "0b000";
        ram[501] = "0b000";
        ram[502] = "0b001";
        ram[503] = "0b000";
        ram[504] = "0b111";
        for (unsigned i = 505; i < 511 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[511] = "0b001";


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


SC_MODULE(mlp_accel_4b_weights_l2_4b_10) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_10_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_10) {
meminst = new mlp_accel_4b_weights_l2_4b_10_ram("mlp_accel_4b_weights_l2_4b_10_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_10() {
    delete meminst;
}


};//endmodule
#endif
