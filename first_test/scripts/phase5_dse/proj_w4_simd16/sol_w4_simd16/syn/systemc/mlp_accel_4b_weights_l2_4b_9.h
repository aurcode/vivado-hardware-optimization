// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_9_H__
#define __mlp_accel_4b_weights_l2_4b_9_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_9_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 2;
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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_9_ram) {
        ram[0] = "0b01";
        ram[1] = "0b00";
        ram[2] = "0b11";
        ram[3] = "0b00";
        ram[4] = "0b00";
        ram[5] = "0b00";
        ram[6] = "0b11";
        ram[7] = "0b01";
        for (unsigned i = 8; i < 18 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[18] = "0b01";
        for (unsigned i = 19; i < 24 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[24] = "0b01";
        ram[25] = "0b00";
        ram[26] = "0b00";
        ram[27] = "0b11";
        ram[28] = "0b00";
        ram[29] = "0b00";
        ram[30] = "0b11";
        ram[31] = "0b00";
        ram[32] = "0b01";
        for (unsigned i = 33; i < 41 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[41] = "0b01";
        for (unsigned i = 42; i < 48 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[48] = "0b01";
        ram[49] = "0b00";
        ram[50] = "0b00";
        ram[51] = "0b01";
        for (unsigned i = 52; i < 59 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[59] = "0b01";
        ram[60] = "0b01";
        for (unsigned i = 61; i < 70 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[70] = "0b11";
        ram[71] = "0b00";
        ram[72] = "0b11";
        ram[73] = "0b00";
        ram[74] = "0b01";
        ram[75] = "0b00";
        ram[76] = "0b00";
        ram[77] = "0b00";
        ram[78] = "0b01";
        for (unsigned i = 79; i < 86 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[86] = "0b11";
        ram[87] = "0b00";
        ram[88] = "0b01";
        ram[89] = "0b00";
        ram[90] = "0b00";
        ram[91] = "0b00";
        ram[92] = "0b01";
        ram[93] = "0b00";
        ram[94] = "0b11";
        ram[95] = "0b00";
        ram[96] = "0b11";
        ram[97] = "0b00";
        ram[98] = "0b01";
        ram[99] = "0b01";
        for (unsigned i = 100; i < 110 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[110] = "0b01";
        for (unsigned i = 111; i < 116 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[116] = "0b01";
        for (unsigned i = 117; i < 124 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[124] = "0b01";
        for (unsigned i = 125; i < 141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[141] = "0b01";
        for (unsigned i = 142; i < 147 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[147] = "0b01";
        ram[148] = "0b00";
        ram[149] = "0b11";
        for (unsigned i = 150; i < 155 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[155] = "0b11";
        for (unsigned i = 156; i < 163 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[163] = "0b11";
        ram[164] = "0b00";
        ram[165] = "0b00";
        ram[166] = "0b00";
        ram[167] = "0b00";
        ram[168] = "0b11";
        ram[169] = "0b00";
        ram[170] = "0b01";
        ram[171] = "0b00";
        ram[172] = "0b00";
        ram[173] = "0b00";
        ram[174] = "0b11";
        ram[175] = "0b00";
        ram[176] = "0b01";
        ram[177] = "0b00";
        ram[178] = "0b00";
        ram[179] = "0b00";
        ram[180] = "0b11";
        ram[181] = "0b00";
        ram[182] = "0b01";
        for (unsigned i = 183; i < 192 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[192] = "0b10";
        ram[193] = "0b00";
        ram[194] = "0b01";
        for (unsigned i = 195; i < 202 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[202] = "0b01";
        ram[203] = "0b00";
        ram[204] = "0b00";
        ram[205] = "0b01";
        ram[206] = "0b01";
        ram[207] = "0b00";
        ram[208] = "0b11";
        ram[209] = "0b00";
        ram[210] = "0b01";
        ram[211] = "0b01";
        ram[212] = "0b00";
        ram[213] = "0b00";
        ram[214] = "0b00";
        ram[215] = "0b00";
        ram[216] = "0b01";
        for (unsigned i = 217; i < 222 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[222] = "0b11";
        for (unsigned i = 223; i < 232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[232] = "0b01";
        ram[233] = "0b00";
        ram[234] = "0b00";
        ram[235] = "0b00";
        ram[236] = "0b00";
        ram[237] = "0b01";
        ram[238] = "0b00";
        ram[239] = "0b00";
        ram[240] = "0b01";
        ram[241] = "0b00";
        ram[242] = "0b00";
        ram[243] = "0b00";
        ram[244] = "0b01";
        ram[245] = "0b00";
        ram[246] = "0b11";
        ram[247] = "0b00";
        ram[248] = "0b00";
        ram[249] = "0b00";
        ram[250] = "0b01";
        ram[251] = "0b00";
        ram[252] = "0b11";
        ram[253] = "0b00";
        ram[254] = "0b00";
        ram[255] = "0b11";
        ram[256] = "0b00";
        ram[257] = "0b01";
        ram[258] = "0b00";
        ram[259] = "0b11";
        for (unsigned i = 260; i < 272 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[272] = "0b01";
        ram[273] = "0b00";
        ram[274] = "0b11";
        ram[275] = "0b11";
        ram[276] = "0b00";
        ram[277] = "0b00";
        ram[278] = "0b00";
        ram[279] = "0b01";
        ram[280] = "0b11";
        ram[281] = "0b00";
        ram[282] = "0b01";
        ram[283] = "0b01";
        for (unsigned i = 284; i < 290 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[290] = "0b01";
        ram[291] = "0b00";
        ram[292] = "0b11";
        ram[293] = "0b00";
        ram[294] = "0b01";
        ram[295] = "0b01";
        ram[296] = "0b00";
        ram[297] = "0b00";
        ram[298] = "0b00";
        ram[299] = "0b11";
        ram[300] = "0b00";
        ram[301] = "0b00";
        ram[302] = "0b01";
        ram[303] = "0b00";
        ram[304] = "0b00";
        ram[305] = "0b00";
        ram[306] = "0b00";
        ram[307] = "0b01";
        ram[308] = "0b00";
        ram[309] = "0b00";
        ram[310] = "0b01";
        ram[311] = "0b00";
        ram[312] = "0b11";
        for (unsigned i = 313; i < 319 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[319] = "0b01";
        ram[320] = "0b00";
        ram[321] = "0b00";
        ram[322] = "0b00";
        ram[323] = "0b01";
        ram[324] = "0b00";
        ram[325] = "0b00";
        ram[326] = "0b00";
        ram[327] = "0b01";
        ram[328] = "0b01";
        ram[329] = "0b00";
        ram[330] = "0b11";
        ram[331] = "0b00";
        ram[332] = "0b01";
        ram[333] = "0b00";
        ram[334] = "0b01";
        for (unsigned i = 335; i < 344 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[344] = "0b01";
        ram[345] = "0b00";
        ram[346] = "0b00";
        ram[347] = "0b00";
        ram[348] = "0b11";
        ram[349] = "0b00";
        ram[350] = "0b01";
        ram[351] = "0b00";
        ram[352] = "0b01";
        for (unsigned i = 353; i < 364 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[364] = "0b01";
        ram[365] = "0b01";
        ram[366] = "0b00";
        ram[367] = "0b00";
        ram[368] = "0b00";
        ram[369] = "0b00";
        ram[370] = "0b01";
        ram[371] = "0b00";
        ram[372] = "0b11";
        ram[373] = "0b11";
        ram[374] = "0b00";
        ram[375] = "0b00";
        ram[376] = "0b00";
        ram[377] = "0b00";
        ram[378] = "0b11";
        ram[379] = "0b00";
        ram[380] = "0b00";
        ram[381] = "0b00";
        ram[382] = "0b11";
        ram[383] = "0b00";
        ram[384] = "0b01";
        ram[385] = "0b00";
        ram[386] = "0b00";
        ram[387] = "0b01";
        ram[388] = "0b01";
        ram[389] = "0b00";
        ram[390] = "0b00";
        ram[391] = "0b00";
        ram[392] = "0b01";
        for (unsigned i = 393; i < 403 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[403] = "0b11";
        ram[404] = "0b00";
        ram[405] = "0b00";
        ram[406] = "0b01";
        ram[407] = "0b01";
        for (unsigned i = 408; i < 416 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[416] = "0b01";
        ram[417] = "0b00";
        ram[418] = "0b00";
        ram[419] = "0b00";
        ram[420] = "0b00";
        ram[421] = "0b01";
        ram[422] = "0b00";
        ram[423] = "0b01";
        ram[424] = "0b00";
        ram[425] = "0b00";
        ram[426] = "0b01";
        ram[427] = "0b01";
        ram[428] = "0b00";
        ram[429] = "0b00";
        ram[430] = "0b01";
        for (unsigned i = 431; i < 442 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[442] = "0b01";
        ram[443] = "0b01";
        ram[444] = "0b00";
        ram[445] = "0b00";
        ram[446] = "0b11";
        ram[447] = "0b00";
        ram[448] = "0b01";
        ram[449] = "0b00";
        ram[450] = "0b11";
        ram[451] = "0b11";
        ram[452] = "0b00";
        ram[453] = "0b00";
        ram[454] = "0b00";
        ram[455] = "0b01";
        for (unsigned i = 456; i < 461 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[461] = "0b01";
        ram[462] = "0b00";
        ram[463] = "0b11";
        ram[464] = "0b00";
        ram[465] = "0b00";
        ram[466] = "0b01";
        ram[467] = "0b00";
        ram[468] = "0b11";
        for (unsigned i = 469; i < 480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[480] = "0b01";
        ram[481] = "0b01";
        ram[482] = "0b00";
        ram[483] = "0b00";
        ram[484] = "0b00";
        ram[485] = "0b00";
        ram[486] = "0b01";
        for (unsigned i = 487; i < 507 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[507] = "0b11";
        ram[508] = "0b00";
        ram[509] = "0b00";
        ram[510] = "0b00";
        ram[511] = "0b00";


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


SC_MODULE(mlp_accel_4b_weights_l2_4b_9) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_9_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_9) {
meminst = new mlp_accel_4b_weights_l2_4b_9_ram("mlp_accel_4b_weights_l2_4b_9_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_9() {
    delete meminst;
}


};//endmodule
#endif
