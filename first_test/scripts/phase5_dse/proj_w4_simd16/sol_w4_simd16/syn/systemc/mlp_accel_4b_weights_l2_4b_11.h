// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_11_H__
#define __mlp_accel_4b_weights_l2_4b_11_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_11_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_11_ram) {
        ram[0] = "0b001";
        ram[1] = "0b000";
        ram[2] = "0b111";
        ram[3] = "0b000";
        ram[4] = "0b000";
        ram[5] = "0b000";
        ram[6] = "0b001";
        ram[7] = "0b111";
        ram[8] = "0b001";
        ram[9] = "0b000";
        ram[10] = "0b110";
        ram[11] = "0b001";
        ram[12] = "0b000";
        ram[13] = "0b000";
        ram[14] = "0b001";
        ram[15] = "0b000";
        ram[16] = "0b000";
        ram[17] = "0b000";
        ram[18] = "0b001";
        ram[19] = "0b000";
        ram[20] = "0b000";
        ram[21] = "0b001";
        ram[22] = "0b000";
        ram[23] = "0b001";
        ram[24] = "0b000";
        ram[25] = "0b000";
        ram[26] = "0b000";
        ram[27] = "0b000";
        ram[28] = "0b001";
        ram[29] = "0b111";
        ram[30] = "0b000";
        ram[31] = "0b000";
        ram[32] = "0b001";
        ram[33] = "0b000";
        ram[34] = "0b000";
        ram[35] = "0b000";
        ram[36] = "0b001";
        ram[37] = "0b001";
        ram[38] = "0b001";
        ram[39] = "0b000";
        ram[40] = "0b000";
        ram[41] = "0b000";
        ram[42] = "0b001";
        ram[43] = "0b000";
        ram[44] = "0b001";
        ram[45] = "0b000";
        ram[46] = "0b000";
        ram[47] = "0b001";
        for (unsigned i = 48; i < 53 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[53] = "0b001";
        ram[54] = "0b000";
        ram[55] = "0b111";
        ram[56] = "0b000";
        ram[57] = "0b000";
        ram[58] = "0b111";
        ram[59] = "0b000";
        ram[60] = "0b111";
        ram[61] = "0b000";
        ram[62] = "0b000";
        ram[63] = "0b111";
        ram[64] = "0b001";
        ram[65] = "0b000";
        ram[66] = "0b111";
        ram[67] = "0b000";
        ram[68] = "0b000";
        ram[69] = "0b000";
        ram[70] = "0b000";
        ram[71] = "0b111";
        ram[72] = "0b000";
        ram[73] = "0b000";
        ram[74] = "0b111";
        ram[75] = "0b111";
        ram[76] = "0b000";
        ram[77] = "0b000";
        ram[78] = "0b000";
        ram[79] = "0b001";
        ram[80] = "0b001";
        ram[81] = "0b001";
        ram[82] = "0b000";
        ram[83] = "0b001";
        ram[84] = "0b000";
        ram[85] = "0b001";
        for (unsigned i = 86; i < 93 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[93] = "0b001";
        ram[94] = "0b000";
        ram[95] = "0b111";
        ram[96] = "0b000";
        ram[97] = "0b000";
        ram[98] = "0b110";
        ram[99] = "0b000";
        ram[100] = "0b111";
        for (unsigned i = 101; i < 116 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[116] = "0b111";
        ram[117] = "0b111";
        ram[118] = "0b001";
        ram[119] = "0b000";
        ram[120] = "0b000";
        ram[121] = "0b000";
        ram[122] = "0b000";
        ram[123] = "0b001";
        for (unsigned i = 124; i < 138 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[138] = "0b111";
        ram[139] = "0b000";
        ram[140] = "0b000";
        ram[141] = "0b111";
        ram[142] = "0b000";
        ram[143] = "0b111";
        ram[144] = "0b000";
        ram[145] = "0b000";
        ram[146] = "0b001";
        ram[147] = "0b111";
        ram[148] = "0b000";
        ram[149] = "0b001";
        ram[150] = "0b000";
        ram[151] = "0b001";
        for (unsigned i = 152; i < 157 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[157] = "0b001";
        for (unsigned i = 158; i < 164 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[164] = "0b001";
        ram[165] = "0b111";
        ram[166] = "0b111";
        ram[167] = "0b000";
        ram[168] = "0b000";
        ram[169] = "0b000";
        ram[170] = "0b111";
        ram[171] = "0b000";
        ram[172] = "0b111";
        ram[173] = "0b000";
        ram[174] = "0b000";
        ram[175] = "0b111";
        ram[176] = "0b001";
        ram[177] = "0b001";
        ram[178] = "0b000";
        ram[179] = "0b000";
        ram[180] = "0b010";
        ram[181] = "0b001";
        for (unsigned i = 182; i < 196 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[196] = "0b111";
        for (unsigned i = 197; i < 202 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[202] = "0b001";
        ram[203] = "0b000";
        ram[204] = "0b000";
        ram[205] = "0b111";
        ram[206] = "0b000";
        ram[207] = "0b001";
        ram[208] = "0b111";
        ram[209] = "0b000";
        ram[210] = "0b010";
        ram[211] = "0b111";
        ram[212] = "0b000";
        ram[213] = "0b001";
        ram[214] = "0b000";
        ram[215] = "0b001";
        ram[216] = "0b000";
        ram[217] = "0b001";
        ram[218] = "0b000";
        ram[219] = "0b000";
        ram[220] = "0b111";
        ram[221] = "0b000";
        ram[222] = "0b000";
        ram[223] = "0b111";
        for (unsigned i = 224; i < 237 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[237] = "0b111";
        ram[238] = "0b000";
        ram[239] = "0b000";
        ram[240] = "0b000";
        ram[241] = "0b000";
        ram[242] = "0b111";
        for (unsigned i = 243; i < 250 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[250] = "0b001";
        ram[251] = "0b000";
        ram[252] = "0b001";
        ram[253] = "0b000";
        ram[254] = "0b000";
        ram[255] = "0b001";
        ram[256] = "0b111";
        ram[257] = "0b000";
        ram[258] = "0b001";
        ram[259] = "0b000";
        ram[260] = "0b000";
        ram[261] = "0b111";
        ram[262] = "0b111";
        ram[263] = "0b001";
        for (unsigned i = 264; i < 269 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[269] = "0b111";
        ram[270] = "0b000";
        ram[271] = "0b111";
        ram[272] = "0b000";
        ram[273] = "0b000";
        ram[274] = "0b000";
        ram[275] = "0b000";
        ram[276] = "0b001";
        for (unsigned i = 277; i < 282 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[282] = "0b001";
        ram[283] = "0b000";
        ram[284] = "0b000";
        ram[285] = "0b001";
        ram[286] = "0b000";
        ram[287] = "0b001";
        for (unsigned i = 288; i < 295 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[295] = "0b001";
        for (unsigned i = 296; i < 301 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[301] = "0b110";
        ram[302] = "0b000";
        ram[303] = "0b111";
        for (unsigned i = 304; i < 309 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[309] = "0b001";
        ram[310] = "0b000";
        ram[311] = "0b000";
        ram[312] = "0b001";
        ram[313] = "0b000";
        ram[314] = "0b111";
        ram[315] = "0b000";
        ram[316] = "0b000";
        ram[317] = "0b001";
        ram[318] = "0b000";
        ram[319] = "0b000";
        ram[320] = "0b001";
        ram[321] = "0b000";
        ram[322] = "0b111";
        ram[323] = "0b001";
        ram[324] = "0b000";
        ram[325] = "0b000";
        ram[326] = "0b001";
        ram[327] = "0b000";
        ram[328] = "0b000";
        ram[329] = "0b000";
        ram[330] = "0b001";
        ram[331] = "0b000";
        ram[332] = "0b000";
        ram[333] = "0b000";
        ram[334] = "0b000";
        ram[335] = "0b111";
        for (unsigned i = 336; i < 346 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[346] = "0b001";
        ram[347] = "0b111";
        ram[348] = "0b000";
        ram[349] = "0b001";
        ram[350] = "0b000";
        ram[351] = "0b000";
        ram[352] = "0b000";
        ram[353] = "0b000";
        ram[354] = "0b001";
        ram[355] = "0b000";
        ram[356] = "0b001";
        ram[357] = "0b001";
        ram[358] = "0b000";
        ram[359] = "0b001";
        for (unsigned i = 360; i < 368 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[368] = "0b001";
        ram[369] = "0b000";
        ram[370] = "0b000";
        ram[371] = "0b000";
        ram[372] = "0b000";
        ram[373] = "0b001";
        ram[374] = "0b000";
        ram[375] = "0b000";
        ram[376] = "0b000";
        ram[377] = "0b000";
        ram[378] = "0b111";
        ram[379] = "0b001";
        ram[380] = "0b001";
        ram[381] = "0b000";
        ram[382] = "0b001";
        ram[383] = "0b001";
        for (unsigned i = 384; i < 391 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[391] = "0b001";
        ram[392] = "0b000";
        ram[393] = "0b000";
        ram[394] = "0b000";
        ram[395] = "0b000";
        ram[396] = "0b001";
        ram[397] = "0b111";
        ram[398] = "0b000";
        ram[399] = "0b111";
        ram[400] = "0b000";
        ram[401] = "0b000";
        ram[402] = "0b000";
        ram[403] = "0b000";
        ram[404] = "0b001";
        for (unsigned i = 405; i < 416 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[416] = "0b001";
        ram[417] = "0b000";
        ram[418] = "0b000";
        ram[419] = "0b000";
        ram[420] = "0b000";
        ram[421] = "0b111";
        ram[422] = "0b000";
        ram[423] = "0b110";
        ram[424] = "0b000";
        ram[425] = "0b000";
        ram[426] = "0b001";
        ram[427] = "0b001";
        for (unsigned i = 428; i < 439 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[439] = "0b001";
        ram[440] = "0b000";
        ram[441] = "0b000";
        ram[442] = "0b000";
        ram[443] = "0b000";
        ram[444] = "0b111";
        ram[445] = "0b001";
        ram[446] = "0b000";
        ram[447] = "0b000";
        ram[448] = "0b001";
        ram[449] = "0b000";
        ram[450] = "0b001";
        ram[451] = "0b000";
        ram[452] = "0b001";
        for (unsigned i = 453; i < 459 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[459] = "0b001";
        for (unsigned i = 460; i < 466 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[466] = "0b001";
        ram[467] = "0b000";
        ram[468] = "0b000";
        ram[469] = "0b001";
        ram[470] = "0b000";
        ram[471] = "0b001";
        ram[472] = "0b001";
        for (unsigned i = 473; i < 482 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[482] = "0b001";
        ram[483] = "0b000";
        ram[484] = "0b001";
        ram[485] = "0b001";
        for (unsigned i = 486; i < 500 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[500] = "0b001";
        ram[501] = "0b000";
        ram[502] = "0b000";
        ram[503] = "0b010";
        for (unsigned i = 504; i < 509 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[509] = "0b110";
        ram[510] = "0b000";
        ram[511] = "0b111";


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


SC_MODULE(mlp_accel_4b_weights_l2_4b_11) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_11_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_11) {
meminst = new mlp_accel_4b_weights_l2_4b_11_ram("mlp_accel_4b_weights_l2_4b_11_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_11() {
    delete meminst;
}


};//endmodule
#endif
