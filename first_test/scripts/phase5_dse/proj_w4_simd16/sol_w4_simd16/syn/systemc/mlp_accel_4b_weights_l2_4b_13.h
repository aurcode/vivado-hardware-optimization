// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_13_H__
#define __mlp_accel_4b_weights_l2_4b_13_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_13_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_13_ram) {
        ram[0] = "0b000";
        ram[1] = "0b001";
        ram[2] = "0b000";
        ram[3] = "0b001";
        ram[4] = "0b000";
        ram[5] = "0b000";
        ram[6] = "0b111";
        ram[7] = "0b000";
        ram[8] = "0b000";
        ram[9] = "0b001";
        for (unsigned i = 10; i < 15 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[15] = "0b111";
        ram[16] = "0b000";
        ram[17] = "0b000";
        ram[18] = "0b001";
        ram[19] = "0b001";
        for (unsigned i = 20; i < 25 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[25] = "0b111";
        ram[26] = "0b111";
        ram[27] = "0b001";
        ram[28] = "0b001";
        ram[29] = "0b111";
        ram[30] = "0b000";
        ram[31] = "0b111";
        ram[32] = "0b001";
        ram[33] = "0b001";
        ram[34] = "0b111";
        ram[35] = "0b111";
        ram[36] = "0b000";
        ram[37] = "0b000";
        ram[38] = "0b000";
        ram[39] = "0b111";
        ram[40] = "0b000";
        ram[41] = "0b001";
        ram[42] = "0b000";
        ram[43] = "0b111";
        ram[44] = "0b000";
        ram[45] = "0b001";
        ram[46] = "0b000";
        ram[47] = "0b000";
        ram[48] = "0b001";
        ram[49] = "0b000";
        ram[50] = "0b111";
        ram[51] = "0b111";
        ram[52] = "0b001";
        ram[53] = "0b000";
        ram[54] = "0b000";
        ram[55] = "0b001";
        for (unsigned i = 56; i < 63 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[63] = "0b001";
        for (unsigned i = 64; i < 72 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[72] = "0b111";
        ram[73] = "0b001";
        ram[74] = "0b001";
        ram[75] = "0b000";
        ram[76] = "0b110";
        ram[77] = "0b000";
        ram[78] = "0b010";
        ram[79] = "0b010";
        ram[80] = "0b001";
        ram[81] = "0b000";
        ram[82] = "0b000";
        ram[83] = "0b001";
        ram[84] = "0b001";
        ram[85] = "0b110";
        ram[86] = "0b000";
        ram[87] = "0b111";
        ram[88] = "0b000";
        ram[89] = "0b000";
        ram[90] = "0b000";
        ram[91] = "0b111";
        ram[92] = "0b001";
        ram[93] = "0b000";
        ram[94] = "0b111";
        for (unsigned i = 95; i < 105 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[105] = "0b001";
        ram[106] = "0b000";
        ram[107] = "0b000";
        ram[108] = "0b000";
        ram[109] = "0b000";
        ram[110] = "0b001";
        ram[111] = "0b000";
        ram[112] = "0b111";
        ram[113] = "0b000";
        ram[114] = "0b000";
        ram[115] = "0b000";
        ram[116] = "0b000";
        ram[117] = "0b001";
        ram[118] = "0b111";
        ram[119] = "0b000";
        ram[120] = "0b000";
        ram[121] = "0b000";
        ram[122] = "0b111";
        ram[123] = "0b000";
        ram[124] = "0b001";
        ram[125] = "0b000";
        ram[126] = "0b111";
        ram[127] = "0b111";
        for (unsigned i = 128; i < 139 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[139] = "0b111";
        ram[140] = "0b000";
        ram[141] = "0b001";
        ram[142] = "0b111";
        ram[143] = "0b000";
        ram[144] = "0b111";
        ram[145] = "0b000";
        ram[146] = "0b000";
        ram[147] = "0b000";
        ram[148] = "0b111";
        ram[149] = "0b001";
        ram[150] = "0b001";
        ram[151] = "0b001";
        ram[152] = "0b111";
        ram[153] = "0b000";
        ram[154] = "0b000";
        ram[155] = "0b001";
        for (unsigned i = 156; i < 161 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[161] = "0b111";
        ram[162] = "0b000";
        ram[163] = "0b000";
        ram[164] = "0b000";
        ram[165] = "0b001";
        ram[166] = "0b111";
        ram[167] = "0b000";
        ram[168] = "0b000";
        ram[169] = "0b111";
        ram[170] = "0b001";
        ram[171] = "0b001";
        ram[172] = "0b000";
        ram[173] = "0b000";
        ram[174] = "0b000";
        ram[175] = "0b000";
        ram[176] = "0b001";
        ram[177] = "0b001";
        ram[178] = "0b000";
        ram[179] = "0b000";
        ram[180] = "0b001";
        for (unsigned i = 181; i < 193 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[193] = "0b111";
        ram[194] = "0b001";
        ram[195] = "0b001";
        ram[196] = "0b000";
        ram[197] = "0b111";
        for (unsigned i = 198; i < 203 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[203] = "0b111";
        ram[204] = "0b000";
        ram[205] = "0b000";
        ram[206] = "0b111";
        ram[207] = "0b111";
        ram[208] = "0b111";
        ram[209] = "0b000";
        ram[210] = "0b001";
        ram[211] = "0b000";
        ram[212] = "0b111";
        ram[213] = "0b001";
        ram[214] = "0b001";
        ram[215] = "0b001";
        for (unsigned i = 216; i < 232 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[232] = "0b111";
        ram[233] = "0b000";
        ram[234] = "0b000";
        ram[235] = "0b000";
        ram[236] = "0b000";
        ram[237] = "0b001";
        ram[238] = "0b000";
        ram[239] = "0b000";
        ram[240] = "0b111";
        ram[241] = "0b001";
        ram[242] = "0b000";
        ram[243] = "0b000";
        ram[244] = "0b000";
        ram[245] = "0b000";
        ram[246] = "0b111";
        ram[247] = "0b000";
        ram[248] = "0b000";
        ram[249] = "0b111";
        ram[250] = "0b000";
        ram[251] = "0b001";
        ram[252] = "0b111";
        ram[253] = "0b000";
        ram[254] = "0b000";
        ram[255] = "0b000";
        ram[256] = "0b111";
        ram[257] = "0b000";
        ram[258] = "0b001";
        ram[259] = "0b000";
        ram[260] = "0b000";
        ram[261] = "0b001";
        ram[262] = "0b000";
        ram[263] = "0b000";
        ram[264] = "0b000";
        ram[265] = "0b111";
        ram[266] = "0b001";
        ram[267] = "0b000";
        ram[268] = "0b000";
        ram[269] = "0b000";
        ram[270] = "0b111";
        ram[271] = "0b000";
        ram[272] = "0b000";
        ram[273] = "0b001";
        ram[274] = "0b000";
        ram[275] = "0b001";
        for (unsigned i = 276; i < 283 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[283] = "0b001";
        ram[284] = "0b111";
        ram[285] = "0b111";
        ram[286] = "0b010";
        ram[287] = "0b001";
        ram[288] = "0b000";
        ram[289] = "0b001";
        ram[290] = "0b111";
        ram[291] = "0b111";
        ram[292] = "0b111";
        ram[293] = "0b001";
        ram[294] = "0b001";
        ram[295] = "0b000";
        ram[296] = "0b000";
        ram[297] = "0b000";
        ram[298] = "0b001";
        ram[299] = "0b000";
        ram[300] = "0b000";
        ram[301] = "0b001";
        ram[302] = "0b000";
        ram[303] = "0b000";
        ram[304] = "0b001";
        for (unsigned i = 305; i < 310 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[310] = "0b001";
        ram[311] = "0b001";
        ram[312] = "0b111";
        ram[313] = "0b001";
        ram[314] = "0b000";
        ram[315] = "0b001";
        ram[316] = "0b000";
        ram[317] = "0b000";
        ram[318] = "0b001";
        ram[319] = "0b000";
        ram[320] = "0b001";
        ram[321] = "0b000";
        ram[322] = "0b111";
        ram[323] = "0b001";
        for (unsigned i = 324; i < 335 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[335] = "0b111";
        for (unsigned i = 336; i < 345 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[345] = "0b001";
        ram[346] = "0b000";
        ram[347] = "0b111";
        ram[348] = "0b000";
        ram[349] = "0b000";
        ram[350] = "0b001";
        ram[351] = "0b000";
        ram[352] = "0b001";
        for (unsigned i = 353; i < 359 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[359] = "0b111";
        ram[360] = "0b000";
        ram[361] = "0b000";
        ram[362] = "0b000";
        ram[363] = "0b000";
        ram[364] = "0b001";
        ram[365] = "0b000";
        ram[366] = "0b111";
        ram[367] = "0b000";
        ram[368] = "0b001";
        ram[369] = "0b111";
        ram[370] = "0b000";
        ram[371] = "0b000";
        ram[372] = "0b000";
        ram[373] = "0b111";
        ram[374] = "0b000";
        ram[375] = "0b000";
        ram[376] = "0b001";
        ram[377] = "0b000";
        ram[378] = "0b000";
        ram[379] = "0b001";
        ram[380] = "0b000";
        ram[381] = "0b111";
        ram[382] = "0b000";
        ram[383] = "0b111";
        ram[384] = "0b000";
        ram[385] = "0b000";
        ram[386] = "0b111";
        ram[387] = "0b110";
        ram[388] = "0b001";
        for (unsigned i = 389; i < 395 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[395] = "0b111";
        ram[396] = "0b000";
        ram[397] = "0b000";
        ram[398] = "0b111";
        ram[399] = "0b000";
        ram[400] = "0b000";
        ram[401] = "0b001";
        ram[402] = "0b000";
        ram[403] = "0b001";
        ram[404] = "0b111";
        ram[405] = "0b000";
        ram[406] = "0b001";
        for (unsigned i = 407; i < 420 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[420] = "0b001";
        ram[421] = "0b000";
        ram[422] = "0b000";
        ram[423] = "0b000";
        ram[424] = "0b001";
        ram[425] = "0b111";
        ram[426] = "0b000";
        ram[427] = "0b000";
        ram[428] = "0b000";
        ram[429] = "0b000";
        ram[430] = "0b001";
        ram[431] = "0b111";
        ram[432] = "0b000";
        ram[433] = "0b111";
        for (unsigned i = 434; i < 439 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[439] = "0b111";
        ram[440] = "0b000";
        ram[441] = "0b000";
        ram[442] = "0b000";
        ram[443] = "0b111";
        ram[444] = "0b000";
        ram[445] = "0b000";
        ram[446] = "0b001";
        ram[447] = "0b001";
        ram[448] = "0b000";
        ram[449] = "0b001";
        ram[450] = "0b000";
        ram[451] = "0b001";
        ram[452] = "0b000";
        ram[453] = "0b000";
        ram[454] = "0b000";
        ram[455] = "0b000";
        ram[456] = "0b001";
        ram[457] = "0b000";
        ram[458] = "0b000";
        ram[459] = "0b000";
        ram[460] = "0b001";
        ram[461] = "0b111";
        ram[462] = "0b000";
        ram[463] = "0b111";
        ram[464] = "0b001";
        for (unsigned i = 465; i < 470 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[470] = "0b001";
        ram[471] = "0b000";
        ram[472] = "0b001";
        ram[473] = "0b111";
        ram[474] = "0b000";
        ram[475] = "0b001";
        ram[476] = "0b000";
        ram[477] = "0b111";
        ram[478] = "0b000";
        ram[479] = "0b000";
        ram[480] = "0b000";
        ram[481] = "0b001";
        ram[482] = "0b000";
        ram[483] = "0b111";
        ram[484] = "0b001";
        ram[485] = "0b001";
        ram[486] = "0b000";
        ram[487] = "0b001";
        for (unsigned i = 488; i < 501 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[501] = "0b001";
        ram[502] = "0b000";
        ram[503] = "0b111";
        ram[504] = "0b001";
        ram[505] = "0b000";
        ram[506] = "0b000";
        ram[507] = "0b000";
        ram[508] = "0b001";
        ram[509] = "0b000";
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_13) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_13_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_13) {
meminst = new mlp_accel_4b_weights_l2_4b_13_ram("mlp_accel_4b_weights_l2_4b_13_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_13() {
    delete meminst;
}


};//endmodule
#endif
