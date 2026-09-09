// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_15_H__
#define __mlp_accel_4b_weights_l2_4b_15_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_15_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_15_ram) {
        ram[0] = "0b000";
        ram[1] = "0b000";
        ram[2] = "0b000";
        ram[3] = "0b111";
        ram[4] = "0b000";
        ram[5] = "0b000";
        ram[6] = "0b001";
        ram[7] = "0b001";
        ram[8] = "0b000";
        ram[9] = "0b000";
        ram[10] = "0b001";
        ram[11] = "0b000";
        ram[12] = "0b000";
        ram[13] = "0b000";
        ram[14] = "0b111";
        ram[15] = "0b000";
        ram[16] = "0b000";
        ram[17] = "0b001";
        ram[18] = "0b001";
        ram[19] = "0b000";
        ram[20] = "0b001";
        ram[21] = "0b000";
        ram[22] = "0b111";
        ram[23] = "0b000";
        ram[24] = "0b000";
        ram[25] = "0b000";
        ram[26] = "0b000";
        ram[27] = "0b110";
        ram[28] = "0b000";
        ram[29] = "0b001";
        ram[30] = "0b001";
        for (unsigned i = 31; i < 36 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[36] = "0b111";
        ram[37] = "0b000";
        ram[38] = "0b000";
        ram[39] = "0b000";
        ram[40] = "0b001";
        ram[41] = "0b001";
        for (unsigned i = 42; i < 49 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[49] = "0b111";
        ram[50] = "0b111";
        ram[51] = "0b001";
        ram[52] = "0b111";
        ram[53] = "0b000";
        ram[54] = "0b001";
        ram[55] = "0b000";
        ram[56] = "0b000";
        ram[57] = "0b000";
        ram[58] = "0b000";
        ram[59] = "0b001";
        ram[60] = "0b000";
        ram[61] = "0b111";
        for (unsigned i = 62; i < 75 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[75] = "0b001";
        ram[76] = "0b000";
        ram[77] = "0b111";
        ram[78] = "0b000";
        ram[79] = "0b000";
        ram[80] = "0b000";
        ram[81] = "0b001";
        ram[82] = "0b000";
        ram[83] = "0b111";
        ram[84] = "0b001";
        ram[85] = "0b000";
        ram[86] = "0b111";
        ram[87] = "0b001";
        ram[88] = "0b001";
        ram[89] = "0b000";
        ram[90] = "0b111";
        ram[91] = "0b000";
        ram[92] = "0b000";
        ram[93] = "0b001";
        ram[94] = "0b001";
        ram[95] = "0b000";
        ram[96] = "0b000";
        ram[97] = "0b000";
        ram[98] = "0b000";
        ram[99] = "0b001";
        ram[100] = "0b111";
        ram[101] = "0b000";
        ram[102] = "0b111";
        ram[103] = "0b000";
        ram[104] = "0b000";
        ram[105] = "0b111";
        ram[106] = "0b000";
        ram[107] = "0b000";
        ram[108] = "0b001";
        for (unsigned i = 109; i < 114 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[114] = "0b001";
        ram[115] = "0b000";
        ram[116] = "0b000";
        ram[117] = "0b000";
        ram[118] = "0b111";
        ram[119] = "0b000";
        ram[120] = "0b000";
        ram[121] = "0b000";
        ram[122] = "0b001";
        for (unsigned i = 123; i < 136 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[136] = "0b001";
        ram[137] = "0b000";
        ram[138] = "0b001";
        ram[139] = "0b000";
        ram[140] = "0b111";
        ram[141] = "0b000";
        ram[142] = "0b000";
        ram[143] = "0b000";
        ram[144] = "0b000";
        ram[145] = "0b001";
        ram[146] = "0b000";
        ram[147] = "0b001";
        ram[148] = "0b000";
        ram[149] = "0b000";
        ram[150] = "0b001";
        ram[151] = "0b000";
        ram[152] = "0b000";
        ram[153] = "0b001";
        ram[154] = "0b001";
        ram[155] = "0b000";
        ram[156] = "0b001";
        ram[157] = "0b000";
        ram[158] = "0b000";
        ram[159] = "0b001";
        for (unsigned i = 160; i < 166 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[166] = "0b001";
        for (unsigned i = 167; i < 174 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[174] = "0b111";
        ram[175] = "0b000";
        ram[176] = "0b001";
        ram[177] = "0b000";
        ram[178] = "0b111";
        ram[179] = "0b111";
        ram[180] = "0b001";
        for (unsigned i = 181; i < 194 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[194] = "0b001";
        ram[195] = "0b001";
        ram[196] = "0b000";
        ram[197] = "0b000";
        ram[198] = "0b110";
        ram[199] = "0b001";
        ram[200] = "0b000";
        ram[201] = "0b000";
        ram[202] = "0b001";
        ram[203] = "0b000";
        ram[204] = "0b000";
        ram[205] = "0b001";
        ram[206] = "0b111";
        ram[207] = "0b000";
        ram[208] = "0b000";
        ram[209] = "0b000";
        ram[210] = "0b000";
        ram[211] = "0b010";
        ram[212] = "0b001";
        ram[213] = "0b000";
        ram[214] = "0b000";
        ram[215] = "0b001";
        ram[216] = "0b000";
        ram[217] = "0b111";
        ram[218] = "0b111";
        ram[219] = "0b000";
        ram[220] = "0b000";
        ram[221] = "0b000";
        ram[222] = "0b001";
        for (unsigned i = 223; i < 233 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[233] = "0b111";
        ram[234] = "0b000";
        ram[235] = "0b000";
        ram[236] = "0b000";
        ram[237] = "0b000";
        ram[238] = "0b001";
        ram[239] = "0b000";
        ram[240] = "0b000";
        ram[241] = "0b000";
        ram[242] = "0b001";
        ram[243] = "0b000";
        ram[244] = "0b000";
        ram[245] = "0b111";
        ram[246] = "0b001";
        ram[247] = "0b000";
        ram[248] = "0b000";
        ram[249] = "0b000";
        ram[250] = "0b001";
        for (unsigned i = 251; i < 258 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[258] = "0b001";
        ram[259] = "0b000";
        ram[260] = "0b000";
        ram[261] = "0b000";
        ram[262] = "0b000";
        ram[263] = "0b111";
        ram[264] = "0b000";
        ram[265] = "0b111";
        ram[266] = "0b000";
        ram[267] = "0b000";
        ram[268] = "0b000";
        ram[269] = "0b001";
        ram[270] = "0b000";
        ram[271] = "0b000";
        ram[272] = "0b000";
        ram[273] = "0b000";
        ram[274] = "0b001";
        ram[275] = "0b111";
        ram[276] = "0b001";
        ram[277] = "0b000";
        ram[278] = "0b000";
        ram[279] = "0b001";
        ram[280] = "0b000";
        ram[281] = "0b000";
        ram[282] = "0b000";
        ram[283] = "0b001";
        ram[284] = "0b001";
        ram[285] = "0b000";
        ram[286] = "0b000";
        ram[287] = "0b001";
        ram[288] = "0b000";
        ram[289] = "0b111";
        ram[290] = "0b111";
        ram[291] = "0b000";
        ram[292] = "0b111";
        ram[293] = "0b111";
        ram[294] = "0b000";
        ram[295] = "0b111";
        ram[296] = "0b000";
        ram[297] = "0b111";
        ram[298] = "0b000";
        ram[299] = "0b111";
        ram[300] = "0b000";
        ram[301] = "0b000";
        ram[302] = "0b000";
        ram[303] = "0b001";
        ram[304] = "0b000";
        ram[305] = "0b001";
        ram[306] = "0b000";
        ram[307] = "0b000";
        ram[308] = "0b000";
        ram[309] = "0b000";
        ram[310] = "0b111";
        ram[311] = "0b000";
        ram[312] = "0b000";
        ram[313] = "0b001";
        ram[314] = "0b000";
        ram[315] = "0b111";
        ram[316] = "0b001";
        ram[317] = "0b111";
        ram[318] = "0b111";
        ram[319] = "0b000";
        ram[320] = "0b000";
        ram[321] = "0b001";
        ram[322] = "0b000";
        ram[323] = "0b111";
        ram[324] = "0b000";
        ram[325] = "0b000";
        ram[326] = "0b000";
        ram[327] = "0b000";
        ram[328] = "0b001";
        ram[329] = "0b000";
        ram[330] = "0b000";
        ram[331] = "0b000";
        ram[332] = "0b001";
        ram[333] = "0b000";
        ram[334] = "0b000";
        ram[335] = "0b001";
        for (unsigned i = 336; i < 346 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[346] = "0b110";
        ram[347] = "0b000";
        ram[348] = "0b001";
        ram[349] = "0b000";
        ram[350] = "0b001";
        ram[351] = "0b001";
        ram[352] = "0b000";
        ram[353] = "0b001";
        ram[354] = "0b000";
        ram[355] = "0b111";
        ram[356] = "0b001";
        ram[357] = "0b001";
        ram[358] = "0b000";
        ram[359] = "0b000";
        ram[360] = "0b000";
        ram[361] = "0b001";
        ram[362] = "0b001";
        ram[363] = "0b000";
        ram[364] = "0b000";
        ram[365] = "0b000";
        ram[366] = "0b111";
        for (unsigned i = 367; i < 377 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[377] = "0b001";
        ram[378] = "0b001";
        ram[379] = "0b111";
        ram[380] = "0b001";
        ram[381] = "0b000";
        ram[382] = "0b111";
        ram[383] = "0b000";
        ram[384] = "0b000";
        ram[385] = "0b000";
        ram[386] = "0b000";
        ram[387] = "0b001";
        ram[388] = "0b111";
        ram[389] = "0b000";
        ram[390] = "0b000";
        ram[391] = "0b111";
        ram[392] = "0b000";
        ram[393] = "0b111";
        ram[394] = "0b000";
        ram[395] = "0b001";
        ram[396] = "0b000";
        ram[397] = "0b001";
        ram[398] = "0b000";
        ram[399] = "0b000";
        ram[400] = "0b000";
        ram[401] = "0b001";
        ram[402] = "0b000";
        ram[403] = "0b111";
        ram[404] = "0b001";
        ram[405] = "0b111";
        ram[406] = "0b000";
        ram[407] = "0b001";
        for (unsigned i = 408; i < 417 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[417] = "0b111";
        ram[418] = "0b111";
        ram[419] = "0b000";
        ram[420] = "0b000";
        ram[421] = "0b000";
        ram[422] = "0b001";
        ram[423] = "0b001";
        ram[424] = "0b111";
        ram[425] = "0b000";
        ram[426] = "0b000";
        ram[427] = "0b111";
        ram[428] = "0b000";
        ram[429] = "0b000";
        ram[430] = "0b000";
        ram[431] = "0b001";
        for (unsigned i = 432; i < 437 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[437] = "0b001";
        ram[438] = "0b000";
        ram[439] = "0b000";
        ram[440] = "0b000";
        ram[441] = "0b111";
        ram[442] = "0b111";
        ram[443] = "0b001";
        ram[444] = "0b111";
        ram[445] = "0b000";
        ram[446] = "0b001";
        ram[447] = "0b000";
        ram[448] = "0b000";
        ram[449] = "0b001";
        ram[450] = "0b000";
        ram[451] = "0b000";
        ram[452] = "0b001";
        ram[453] = "0b000";
        ram[454] = "0b001";
        ram[455] = "0b001";
        ram[456] = "0b000";
        ram[457] = "0b001";
        ram[458] = "0b000";
        ram[459] = "0b000";
        ram[460] = "0b001";
        ram[461] = "0b001";
        ram[462] = "0b000";
        ram[463] = "0b001";
        ram[464] = "0b000";
        ram[465] = "0b001";
        for (unsigned i = 466; i < 478 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[478] = "0b111";
        ram[479] = "0b000";
        ram[480] = "0b000";
        ram[481] = "0b000";
        ram[482] = "0b111";
        ram[483] = "0b001";
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
        ram[502] = "0b111";
        ram[503] = "0b111";
        ram[504] = "0b000";
        ram[505] = "0b111";
        ram[506] = "0b111";
        ram[507] = "0b111";
        ram[508] = "0b000";
        ram[509] = "0b001";
        ram[510] = "0b001";
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_15) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_15_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_15) {
meminst = new mlp_accel_4b_weights_l2_4b_15_ram("mlp_accel_4b_weights_l2_4b_15_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_15() {
    delete meminst;
}


};//endmodule
#endif
