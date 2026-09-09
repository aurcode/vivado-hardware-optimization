// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_2_H__
#define __mlp_accel_4b_weights_l2_4b_2_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_2_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_2_ram) {
        ram[0] = "0b001";
        for (unsigned i = 1; i < 8 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[8] = "0b001";
        ram[9] = "0b001";
        ram[10] = "0b001";
        ram[11] = "0b111";
        for (unsigned i = 12; i < 19 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[19] = "0b001";
        for (unsigned i = 20; i < 37 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[37] = "0b001";
        for (unsigned i = 38; i < 49 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[49] = "0b001";
        ram[50] = "0b000";
        ram[51] = "0b000";
        ram[52] = "0b000";
        ram[53] = "0b000";
        ram[54] = "0b001";
        ram[55] = "0b000";
        ram[56] = "0b001";
        ram[57] = "0b001";
        ram[58] = "0b000";
        ram[59] = "0b000";
        ram[60] = "0b000";
        ram[61] = "0b000";
        ram[62] = "0b001";
        ram[63] = "0b000";
        ram[64] = "0b001";
        ram[65] = "0b000";
        ram[66] = "0b111";
        for (unsigned i = 67; i < 72 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[72] = "0b001";
        ram[73] = "0b000";
        ram[74] = "0b001";
        ram[75] = "0b000";
        ram[76] = "0b000";
        ram[77] = "0b111";
        for (unsigned i = 78; i < 83 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[83] = "0b001";
        ram[84] = "0b000";
        ram[85] = "0b000";
        ram[86] = "0b000";
        ram[87] = "0b000";
        ram[88] = "0b001";
        ram[89] = "0b000";
        ram[90] = "0b000";
        ram[91] = "0b111";
        ram[92] = "0b000";
        ram[93] = "0b000";
        ram[94] = "0b001";
        for (unsigned i = 95; i < 107 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[107] = "0b001";
        for (unsigned i = 108; i < 139 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[139] = "0b111";
        ram[140] = "0b000";
        ram[141] = "0b000";
        ram[142] = "0b000";
        ram[143] = "0b000";
        ram[144] = "0b001";
        for (unsigned i = 145; i < 155 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[155] = "0b001";
        for (unsigned i = 156; i < 163 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[163] = "0b111";
        ram[164] = "0b000";
        ram[165] = "0b111";
        ram[166] = "0b000";
        ram[167] = "0b000";
        ram[168] = "0b000";
        ram[169] = "0b001";
        ram[170] = "0b000";
        ram[171] = "0b000";
        ram[172] = "0b000";
        ram[173] = "0b111";
        ram[174] = "0b001";
        for (unsigned i = 175; i < 181 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[181] = "0b001";
        for (unsigned i = 182; i < 192 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[192] = "0b001";
        ram[193] = "0b000";
        ram[194] = "0b000";
        ram[195] = "0b001";
        ram[196] = "0b000";
        ram[197] = "0b111";
        ram[198] = "0b000";
        ram[199] = "0b000";
        ram[200] = "0b111";
        ram[201] = "0b000";
        ram[202] = "0b000";
        ram[203] = "0b111";
        ram[204] = "0b000";
        ram[205] = "0b001";
        for (unsigned i = 206; i < 211 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[211] = "0b001";
        for (unsigned i = 212; i < 234 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[234] = "0b001";
        ram[235] = "0b000";
        ram[236] = "0b000";
        ram[237] = "0b001";
        ram[238] = "0b000";
        ram[239] = "0b000";
        ram[240] = "0b001";
        for (unsigned i = 241; i < 256 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[256] = "0b111";
        ram[257] = "0b000";
        ram[258] = "0b000";
        ram[259] = "0b111";
        ram[260] = "0b000";
        ram[261] = "0b000";
        ram[262] = "0b000";
        ram[263] = "0b000";
        ram[264] = "0b111";
        ram[265] = "0b000";
        ram[266] = "0b000";
        ram[267] = "0b111";
        for (unsigned i = 268; i < 275 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[275] = "0b001";
        ram[276] = "0b000";
        ram[277] = "0b000";
        ram[278] = "0b000";
        ram[279] = "0b000";
        ram[280] = "0b001";
        ram[281] = "0b000";
        ram[282] = "0b000";
        ram[283] = "0b001";
        ram[284] = "0b000";
        ram[285] = "0b111";
        ram[286] = "0b000";
        ram[287] = "0b000";
        ram[288] = "0b000";
        ram[289] = "0b000";
        ram[290] = "0b001";
        ram[291] = "0b111";
        ram[292] = "0b000";
        ram[293] = "0b000";
        ram[294] = "0b000";
        ram[295] = "0b000";
        ram[296] = "0b111";
        ram[297] = "0b000";
        ram[298] = "0b001";
        ram[299] = "0b111";
        for (unsigned i = 300; i < 305 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[305] = "0b001";
        ram[306] = "0b000";
        ram[307] = "0b001";
        ram[308] = "0b000";
        ram[309] = "0b000";
        ram[310] = "0b000";
        ram[311] = "0b000";
        ram[312] = "0b001";
        ram[313] = "0b000";
        ram[314] = "0b000";
        ram[315] = "0b001";
        ram[316] = "0b000";
        ram[317] = "0b111";
        ram[318] = "0b000";
        ram[319] = "0b000";
        ram[320] = "0b001";
        ram[321] = "0b000";
        ram[322] = "0b000";
        ram[323] = "0b001";
        for (unsigned i = 324; i < 329 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[329] = "0b111";
        ram[330] = "0b000";
        ram[331] = "0b001";
        ram[332] = "0b000";
        ram[333] = "0b000";
        ram[334] = "0b111";
        for (unsigned i = 335; i < 346 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[346] = "0b001";
        for (unsigned i = 347; i < 352 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[352] = "0b111";
        ram[353] = "0b000";
        ram[354] = "0b000";
        ram[355] = "0b000";
        ram[356] = "0b000";
        ram[357] = "0b001";
        ram[358] = "0b000";
        ram[359] = "0b000";
        ram[360] = "0b111";
        for (unsigned i = 361; i < 368 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[368] = "0b001";
        ram[369] = "0b000";
        ram[370] = "0b111";
        ram[371] = "0b001";
        ram[372] = "0b000";
        ram[373] = "0b111";
        for (unsigned i = 374; i < 379 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[379] = "0b001";
        ram[380] = "0b000";
        ram[381] = "0b000";
        ram[382] = "0b111";
        ram[383] = "0b000";
        ram[384] = "0b000";
        ram[385] = "0b000";
        ram[386] = "0b000";
        ram[387] = "0b111";
        for (unsigned i = 388; i < 395 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[395] = "0b111";
        ram[396] = "0b000";
        ram[397] = "0b000";
        ram[398] = "0b000";
        ram[399] = "0b000";
        ram[400] = "0b001";
        for (unsigned i = 401; i < 416 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[416] = "0b111";
        ram[417] = "0b000";
        ram[418] = "0b001";
        ram[419] = "0b000";
        ram[420] = "0b000";
        ram[421] = "0b001";
        ram[422] = "0b000";
        ram[423] = "0b000";
        ram[424] = "0b111";
        ram[425] = "0b000";
        ram[426] = "0b000";
        ram[427] = "0b000";
        ram[428] = "0b000";
        ram[429] = "0b001";
        for (unsigned i = 430; i < 439 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[439] = "0b001";
        ram[440] = "0b000";
        ram[441] = "0b000";
        ram[442] = "0b000";
        ram[443] = "0b111";
        for (unsigned i = 444; i < 451 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[451] = "0b001";
        for (unsigned i = 452; i < 459 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[459] = "0b001";
        ram[460] = "0b000";
        ram[461] = "0b001";
        for (unsigned i = 462; i < 467 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[467] = "0b001";
        ram[468] = "0b000";
        ram[469] = "0b111";
        ram[470] = "0b000";
        ram[471] = "0b000";
        ram[472] = "0b001";
        ram[473] = "0b000";
        ram[474] = "0b111";
        ram[475] = "0b001";
        ram[476] = "0b000";
        ram[477] = "0b111";
        ram[478] = "0b000";
        ram[479] = "0b001";
        ram[480] = "0b000";
        ram[481] = "0b000";
        ram[482] = "0b000";
        ram[483] = "0b111";
        ram[484] = "0b000";
        ram[485] = "0b001";
        for (unsigned i = 486; i < 496 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[496] = "0b010";
        for (unsigned i = 497; i < 504 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[504] = "0b111";
        for (unsigned i = 505; i < 512 ; i = i + 1) {
            ram[i] = "0b000";
        }


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


SC_MODULE(mlp_accel_4b_weights_l2_4b_2) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_2_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_2) {
meminst = new mlp_accel_4b_weights_l2_4b_2_ram("mlp_accel_4b_weights_l2_4b_2_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_2() {
    delete meminst;
}


};//endmodule
#endif
