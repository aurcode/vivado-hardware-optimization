// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_7_H__
#define __mlp_accel_4b_weights_l2_4b_7_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_7_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_7_ram) {
        ram[0] = "0b000";
        ram[1] = "0b000";
        ram[2] = "0b111";
        for (unsigned i = 3; i < 10 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[10] = "0b111";
        ram[11] = "0b111";
        ram[12] = "0b000";
        ram[13] = "0b000";
        ram[14] = "0b000";
        ram[15] = "0b001";
        ram[16] = "0b000";
        ram[17] = "0b000";
        ram[18] = "0b001";
        ram[19] = "0b001";
        ram[20] = "0b000";
        ram[21] = "0b000";
        ram[22] = "0b111";
        ram[23] = "0b000";
        ram[24] = "0b000";
        ram[25] = "0b000";
        ram[26] = "0b111";
        ram[27] = "0b000";
        ram[28] = "0b000";
        ram[29] = "0b000";
        ram[30] = "0b000";
        ram[31] = "0b001";
        ram[32] = "0b000";
        ram[33] = "0b000";
        ram[34] = "0b000";
        ram[35] = "0b111";
        ram[36] = "0b000";
        ram[37] = "0b000";
        ram[38] = "0b000";
        ram[39] = "0b000";
        ram[40] = "0b111";
        ram[41] = "0b000";
        ram[42] = "0b000";
        ram[43] = "0b111";
        ram[44] = "0b000";
        ram[45] = "0b000";
        ram[46] = "0b000";
        ram[47] = "0b111";
        ram[48] = "0b000";
        ram[49] = "0b000";
        ram[50] = "0b000";
        ram[51] = "0b000";
        ram[52] = "0b001";
        ram[53] = "0b000";
        ram[54] = "0b001";
        ram[55] = "0b000";
        ram[56] = "0b000";
        ram[57] = "0b111";
        ram[58] = "0b111";
        for (unsigned i = 59; i < 70 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[70] = "0b001";
        ram[71] = "0b001";
        ram[72] = "0b000";
        ram[73] = "0b000";
        ram[74] = "0b001";
        ram[75] = "0b000";
        ram[76] = "0b111";
        ram[77] = "0b000";
        ram[78] = "0b111";
        ram[79] = "0b000";
        ram[80] = "0b000";
        ram[81] = "0b001";
        ram[82] = "0b111";
        ram[83] = "0b001";
        ram[84] = "0b000";
        ram[85] = "0b000";
        ram[86] = "0b000";
        ram[87] = "0b001";
        ram[88] = "0b001";
        ram[89] = "0b000";
        ram[90] = "0b000";
        ram[91] = "0b000";
        ram[92] = "0b001";
        ram[93] = "0b000";
        ram[94] = "0b001";
        ram[95] = "0b111";
        ram[96] = "0b001";
        for (unsigned i = 97; i < 103 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[103] = "0b001";
        ram[104] = "0b111";
        for (unsigned i = 105; i < 111 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[111] = "0b001";
        ram[112] = "0b000";
        ram[113] = "0b111";
        ram[114] = "0b111";
        ram[115] = "0b111";
        ram[116] = "0b000";
        ram[117] = "0b000";
        ram[118] = "0b000";
        ram[119] = "0b111";
        ram[120] = "0b000";
        ram[121] = "0b001";
        ram[122] = "0b111";
        ram[123] = "0b000";
        ram[124] = "0b000";
        ram[125] = "0b000";
        ram[126] = "0b000";
        ram[127] = "0b111";
        for (unsigned i = 128; i < 138 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[138] = "0b111";
        ram[139] = "0b111";
        for (unsigned i = 140; i < 145 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[145] = "0b111";
        ram[146] = "0b000";
        ram[147] = "0b000";
        ram[148] = "0b000";
        ram[149] = "0b000";
        ram[150] = "0b111";
        ram[151] = "0b111";
        ram[152] = "0b000";
        ram[153] = "0b111";
        ram[154] = "0b111";
        ram[155] = "0b000";
        ram[156] = "0b000";
        ram[157] = "0b000";
        ram[158] = "0b000";
        ram[159] = "0b111";
        for (unsigned i = 160; i < 167 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[167] = "0b111";
        ram[168] = "0b000";
        ram[169] = "0b111";
        ram[170] = "0b111";
        for (unsigned i = 171; i < 178 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[178] = "0b001";
        ram[179] = "0b000";
        ram[180] = "0b000";
        ram[181] = "0b000";
        ram[182] = "0b000";
        ram[183] = "0b010";
        for (unsigned i = 184; i < 192 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[192] = "0b001";
        ram[193] = "0b000";
        ram[194] = "0b000";
        ram[195] = "0b000";
        ram[196] = "0b111";
        ram[197] = "0b000";
        ram[198] = "0b000";
        ram[199] = "0b001";
        for (unsigned i = 200; i < 206 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[206] = "0b001";
        ram[207] = "0b111";
        ram[208] = "0b000";
        ram[209] = "0b000";
        ram[210] = "0b001";
        ram[211] = "0b001";
        for (unsigned i = 212; i < 218 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[218] = "0b111";
        ram[219] = "0b001";
        ram[220] = "0b001";
        ram[221] = "0b001";
        ram[222] = "0b001";
        ram[223] = "0b111";
        for (unsigned i = 224; i < 234 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[234] = "0b111";
        ram[235] = "0b000";
        ram[236] = "0b000";
        ram[237] = "0b001";
        ram[238] = "0b000";
        ram[239] = "0b111";
        ram[240] = "0b000";
        ram[241] = "0b111";
        ram[242] = "0b111";
        ram[243] = "0b000";
        ram[244] = "0b000";
        ram[245] = "0b001";
        ram[246] = "0b111";
        ram[247] = "0b111";
        ram[248] = "0b000";
        ram[249] = "0b000";
        ram[250] = "0b001";
        for (unsigned i = 251; i < 258 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[258] = "0b001";
        ram[259] = "0b000";
        ram[260] = "0b001";
        ram[261] = "0b000";
        ram[262] = "0b000";
        ram[263] = "0b110";
        ram[264] = "0b000";
        ram[265] = "0b000";
        ram[266] = "0b001";
        ram[267] = "0b000";
        ram[268] = "0b000";
        ram[269] = "0b000";
        ram[270] = "0b001";
        ram[271] = "0b000";
        ram[272] = "0b000";
        ram[273] = "0b000";
        ram[274] = "0b000";
        ram[275] = "0b001";
        for (unsigned i = 276; i < 282 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[282] = "0b001";
        ram[283] = "0b001";
        ram[284] = "0b111";
        ram[285] = "0b000";
        ram[286] = "0b111";
        ram[287] = "0b001";
        ram[288] = "0b000";
        ram[289] = "0b000";
        ram[290] = "0b000";
        ram[291] = "0b111";
        for (unsigned i = 292; i < 302 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[302] = "0b001";
        ram[303] = "0b000";
        ram[304] = "0b000";
        ram[305] = "0b000";
        ram[306] = "0b001";
        ram[307] = "0b000";
        ram[308] = "0b000";
        ram[309] = "0b000";
        ram[310] = "0b000";
        ram[311] = "0b001";
        ram[312] = "0b000";
        ram[313] = "0b111";
        ram[314] = "0b111";
        ram[315] = "0b000";
        ram[316] = "0b111";
        ram[317] = "0b000";
        ram[318] = "0b111";
        ram[319] = "0b000";
        ram[320] = "0b000";
        ram[321] = "0b000";
        ram[322] = "0b111";
        ram[323] = "0b000";
        ram[324] = "0b000";
        ram[325] = "0b001";
        ram[326] = "0b111";
        ram[327] = "0b001";
        ram[328] = "0b000";
        ram[329] = "0b000";
        ram[330] = "0b001";
        ram[331] = "0b001";
        ram[332] = "0b000";
        ram[333] = "0b001";
        ram[334] = "0b000";
        ram[335] = "0b001";
        for (unsigned i = 336; i < 344 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[344] = "0b110";
        ram[345] = "0b000";
        ram[346] = "0b001";
        for (unsigned i = 347; i < 353 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[353] = "0b001";
        ram[354] = "0b000";
        ram[355] = "0b000";
        ram[356] = "0b000";
        ram[357] = "0b000";
        ram[358] = "0b001";
        ram[359] = "0b111";
        ram[360] = "0b001";
        ram[361] = "0b000";
        ram[362] = "0b000";
        ram[363] = "0b000";
        ram[364] = "0b000";
        ram[365] = "0b001";
        ram[366] = "0b000";
        ram[367] = "0b111";
        ram[368] = "0b000";
        ram[369] = "0b000";
        ram[370] = "0b001";
        ram[371] = "0b001";
        ram[372] = "0b000";
        ram[373] = "0b000";
        ram[374] = "0b000";
        ram[375] = "0b001";
        ram[376] = "0b000";
        ram[377] = "0b001";
        ram[378] = "0b111";
        ram[379] = "0b001";
        ram[380] = "0b000";
        ram[381] = "0b001";
        ram[382] = "0b111";
        ram[383] = "0b001";
        ram[384] = "0b000";
        ram[385] = "0b000";
        ram[386] = "0b000";
        ram[387] = "0b111";
        ram[388] = "0b000";
        ram[389] = "0b000";
        ram[390] = "0b000";
        ram[391] = "0b111";
        ram[392] = "0b001";
        ram[393] = "0b000";
        ram[394] = "0b000";
        ram[395] = "0b000";
        ram[396] = "0b001";
        ram[397] = "0b000";
        ram[398] = "0b000";
        ram[399] = "0b000";
        ram[400] = "0b111";
        ram[401] = "0b000";
        ram[402] = "0b000";
        ram[403] = "0b000";
        ram[404] = "0b111";
        ram[405] = "0b000";
        ram[406] = "0b000";
        ram[407] = "0b001";
        for (unsigned i = 408; i < 419 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[419] = "0b111";
        ram[420] = "0b000";
        ram[421] = "0b000";
        ram[422] = "0b001";
        ram[423] = "0b000";
        ram[424] = "0b000";
        ram[425] = "0b001";
        ram[426] = "0b001";
        for (unsigned i = 427; i < 435 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[435] = "0b001";
        ram[436] = "0b000";
        ram[437] = "0b000";
        ram[438] = "0b000";
        ram[439] = "0b111";
        for (unsigned i = 440; i < 446 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[446] = "0b001";
        for (unsigned i = 447; i < 455 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[455] = "0b111";
        for (unsigned i = 456; i < 462 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[462] = "0b001";
        ram[463] = "0b000";
        ram[464] = "0b000";
        ram[465] = "0b000";
        ram[466] = "0b001";
        ram[467] = "0b000";
        ram[468] = "0b000";
        ram[469] = "0b000";
        ram[470] = "0b000";
        ram[471] = "0b001";
        ram[472] = "0b001";
        ram[473] = "0b000";
        ram[474] = "0b000";
        ram[475] = "0b001";
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
        for (unsigned i = 487; i < 498 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[498] = "0b111";
        ram[499] = "0b000";
        ram[500] = "0b111";
        ram[501] = "0b000";
        ram[502] = "0b111";
        for (unsigned i = 503; i < 510 ; i = i + 1) {
            ram[i] = "0b000";
        }
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_7) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_7_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_7) {
meminst = new mlp_accel_4b_weights_l2_4b_7_ram("mlp_accel_4b_weights_l2_4b_7_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_7() {
    delete meminst;
}


};//endmodule
#endif
