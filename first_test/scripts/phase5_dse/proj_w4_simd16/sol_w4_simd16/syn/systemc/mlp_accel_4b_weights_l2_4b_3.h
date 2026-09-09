// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_3_H__
#define __mlp_accel_4b_weights_l2_4b_3_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_3_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_3_ram) {
        ram[0] = "0b001";
        ram[1] = "0b111";
        ram[2] = "0b000";
        ram[3] = "0b000";
        ram[4] = "0b000";
        ram[5] = "0b000";
        ram[6] = "0b001";
        ram[7] = "0b000";
        ram[8] = "0b111";
        ram[9] = "0b000";
        ram[10] = "0b000";
        ram[11] = "0b111";
        ram[12] = "0b001";
        ram[13] = "0b000";
        ram[14] = "0b000";
        ram[15] = "0b000";
        ram[16] = "0b001";
        ram[17] = "0b000";
        ram[18] = "0b000";
        ram[19] = "0b001";
        ram[20] = "0b000";
        ram[21] = "0b000";
        ram[22] = "0b000";
        ram[23] = "0b010";
        ram[24] = "0b000";
        ram[25] = "0b111";
        ram[26] = "0b000";
        ram[27] = "0b000";
        ram[28] = "0b000";
        ram[29] = "0b000";
        ram[30] = "0b111";
        ram[31] = "0b111";
        ram[32] = "0b111";
        ram[33] = "0b000";
        ram[34] = "0b000";
        ram[35] = "0b111";
        ram[36] = "0b000";
        ram[37] = "0b000";
        ram[38] = "0b111";
        for (unsigned i = 39; i < 47 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[47] = "0b001";
        ram[48] = "0b111";
        for (unsigned i = 49; i < 54 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[54] = "0b001";
        ram[55] = "0b000";
        ram[56] = "0b000";
        ram[57] = "0b111";
        ram[58] = "0b000";
        ram[59] = "0b000";
        ram[60] = "0b000";
        ram[61] = "0b001";
        ram[62] = "0b001";
        for (unsigned i = 63; i < 69 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[69] = "0b001";
        ram[70] = "0b000";
        ram[71] = "0b111";
        ram[72] = "0b000";
        ram[73] = "0b010";
        ram[74] = "0b000";
        ram[75] = "0b111";
        ram[76] = "0b001";
        ram[77] = "0b001";
        ram[78] = "0b000";
        ram[79] = "0b001";
        ram[80] = "0b001";
        ram[81] = "0b000";
        ram[82] = "0b001";
        ram[83] = "0b001";
        ram[84] = "0b001";
        ram[85] = "0b000";
        ram[86] = "0b001";
        ram[87] = "0b000";
        ram[88] = "0b000";
        ram[89] = "0b111";
        ram[90] = "0b000";
        ram[91] = "0b001";
        ram[92] = "0b111";
        ram[93] = "0b000";
        ram[94] = "0b000";
        ram[95] = "0b111";
        ram[96] = "0b111";
        ram[97] = "0b000";
        ram[98] = "0b000";
        ram[99] = "0b000";
        ram[100] = "0b000";
        ram[101] = "0b001";
        ram[102] = "0b001";
        for (unsigned i = 103; i < 108 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[108] = "0b001";
        ram[109] = "0b001";
        ram[110] = "0b001";
        ram[111] = "0b000";
        ram[112] = "0b111";
        ram[113] = "0b000";
        ram[114] = "0b000";
        ram[115] = "0b000";
        ram[116] = "0b111";
        ram[117] = "0b000";
        ram[118] = "0b111";
        ram[119] = "0b000";
        ram[120] = "0b000";
        ram[121] = "0b111";
        ram[122] = "0b000";
        ram[123] = "0b001";
        ram[124] = "0b000";
        ram[125] = "0b111";
        for (unsigned i = 126; i < 136 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[136] = "0b111";
        ram[137] = "0b000";
        ram[138] = "0b000";
        ram[139] = "0b111";
        ram[140] = "0b000";
        ram[141] = "0b000";
        ram[142] = "0b000";
        ram[143] = "0b000";
        ram[144] = "0b001";
        ram[145] = "0b000";
        ram[146] = "0b000";
        ram[147] = "0b001";
        ram[148] = "0b000";
        ram[149] = "0b001";
        ram[150] = "0b000";
        ram[151] = "0b001";
        ram[152] = "0b010";
        ram[153] = "0b111";
        ram[154] = "0b000";
        ram[155] = "0b001";
        ram[156] = "0b111";
        ram[157] = "0b111";
        ram[158] = "0b001";
        ram[159] = "0b001";
        ram[160] = "0b001";
        ram[161] = "0b111";
        ram[162] = "0b000";
        ram[163] = "0b000";
        ram[164] = "0b000";
        ram[165] = "0b111";
        ram[166] = "0b110";
        ram[167] = "0b111";
        for (unsigned i = 168; i < 173 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[173] = "0b001";
        ram[174] = "0b000";
        ram[175] = "0b000";
        ram[176] = "0b000";
        ram[177] = "0b001";
        ram[178] = "0b000";
        ram[179] = "0b111";
        for (unsigned i = 180; i < 192 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[192] = "0b001";
        ram[193] = "0b000";
        ram[194] = "0b000";
        ram[195] = "0b001";
        ram[196] = "0b000";
        ram[197] = "0b000";
        ram[198] = "0b000";
        ram[199] = "0b000";
        ram[200] = "0b111";
        ram[201] = "0b001";
        ram[202] = "0b000";
        ram[203] = "0b000";
        ram[204] = "0b000";
        ram[205] = "0b111";
        ram[206] = "0b000";
        ram[207] = "0b000";
        ram[208] = "0b001";
        ram[209] = "0b001";
        ram[210] = "0b000";
        ram[211] = "0b001";
        ram[212] = "0b111";
        ram[213] = "0b001";
        ram[214] = "0b000";
        ram[215] = "0b001";
        ram[216] = "0b001";
        ram[217] = "0b111";
        ram[218] = "0b000";
        ram[219] = "0b001";
        for (unsigned i = 220; i < 233 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[233] = "0b111";
        ram[234] = "0b000";
        ram[235] = "0b000";
        ram[236] = "0b000";
        ram[237] = "0b000";
        ram[238] = "0b001";
        ram[239] = "0b001";
        ram[240] = "0b001";
        ram[241] = "0b111";
        ram[242] = "0b000";
        ram[243] = "0b001";
        ram[244] = "0b111";
        for (unsigned i = 245; i < 254 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[254] = "0b110";
        ram[255] = "0b111";
        ram[256] = "0b001";
        ram[257] = "0b000";
        ram[258] = "0b000";
        ram[259] = "0b000";
        ram[260] = "0b111";
        ram[261] = "0b000";
        ram[262] = "0b111";
        ram[263] = "0b111";
        ram[264] = "0b111";
        ram[265] = "0b001";
        for (unsigned i = 266; i < 272 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[272] = "0b001";
        for (unsigned i = 273; i < 279 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[279] = "0b001";
        ram[280] = "0b000";
        ram[281] = "0b001";
        ram[282] = "0b000";
        ram[283] = "0b000";
        ram[284] = "0b001";
        ram[285] = "0b001";
        ram[286] = "0b000";
        ram[287] = "0b001";
        ram[288] = "0b111";
        ram[289] = "0b001";
        ram[290] = "0b000";
        ram[291] = "0b111";
        ram[292] = "0b001";
        ram[293] = "0b001";
        for (unsigned i = 294; i < 304 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[304] = "0b111";
        ram[305] = "0b001";
        ram[306] = "0b000";
        ram[307] = "0b111";
        ram[308] = "0b001";
        ram[309] = "0b001";
        ram[310] = "0b001";
        ram[311] = "0b000";
        ram[312] = "0b001";
        ram[313] = "0b111";
        ram[314] = "0b000";
        ram[315] = "0b000";
        ram[316] = "0b001";
        ram[317] = "0b000";
        ram[318] = "0b000";
        ram[319] = "0b000";
        ram[320] = "0b000";
        ram[321] = "0b111";
        ram[322] = "0b000";
        ram[323] = "0b000";
        ram[324] = "0b001";
        ram[325] = "0b000";
        ram[326] = "0b000";
        ram[327] = "0b000";
        ram[328] = "0b000";
        ram[329] = "0b001";
        ram[330] = "0b000";
        ram[331] = "0b111";
        ram[332] = "0b000";
        ram[333] = "0b000";
        ram[334] = "0b000";
        ram[335] = "0b001";
        for (unsigned i = 336; i < 355 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[355] = "0b001";
        for (unsigned i = 356; i < 363 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[363] = "0b001";
        ram[364] = "0b111";
        ram[365] = "0b111";
        ram[366] = "0b000";
        ram[367] = "0b001";
        ram[368] = "0b000";
        ram[369] = "0b001";
        ram[370] = "0b000";
        ram[371] = "0b000";
        ram[372] = "0b001";
        ram[373] = "0b000";
        ram[374] = "0b111";
        ram[375] = "0b110";
        ram[376] = "0b000";
        ram[377] = "0b111";
        ram[378] = "0b000";
        ram[379] = "0b000";
        ram[380] = "0b001";
        ram[381] = "0b000";
        ram[382] = "0b111";
        for (unsigned i = 383; i < 392 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[392] = "0b111";
        ram[393] = "0b000";
        ram[394] = "0b000";
        ram[395] = "0b111";
        for (unsigned i = 396; i < 404 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[404] = "0b001";
        for (unsigned i = 405; i < 420 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[420] = "0b001";
        ram[421] = "0b000";
        ram[422] = "0b001";
        ram[423] = "0b000";
        ram[424] = "0b111";
        ram[425] = "0b001";
        ram[426] = "0b000";
        ram[427] = "0b000";
        ram[428] = "0b001";
        ram[429] = "0b000";
        ram[430] = "0b000";
        ram[431] = "0b111";
        ram[432] = "0b111";
        for (unsigned i = 433; i < 438 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[438] = "0b111";
        ram[439] = "0b110";
        ram[440] = "0b111";
        for (unsigned i = 441; i < 446 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[446] = "0b010";
        ram[447] = "0b000";
        ram[448] = "0b001";
        ram[449] = "0b111";
        ram[450] = "0b000";
        ram[451] = "0b001";
        ram[452] = "0b111";
        ram[453] = "0b111";
        ram[454] = "0b111";
        ram[455] = "0b000";
        ram[456] = "0b001";
        ram[457] = "0b000";
        ram[458] = "0b000";
        ram[459] = "0b001";
        ram[460] = "0b000";
        ram[461] = "0b111";
        ram[462] = "0b001";
        ram[463] = "0b001";
        ram[464] = "0b000";
        ram[465] = "0b001";
        ram[466] = "0b000";
        ram[467] = "0b000";
        ram[468] = "0b000";
        ram[469] = "0b000";
        ram[470] = "0b111";
        ram[471] = "0b111";
        ram[472] = "0b000";
        ram[473] = "0b000";
        ram[474] = "0b000";
        ram[475] = "0b000";
        ram[476] = "0b001";
        ram[477] = "0b000";
        ram[478] = "0b111";
        ram[479] = "0b111";
        ram[480] = "0b000";
        ram[481] = "0b001";
        ram[482] = "0b000";
        ram[483] = "0b111";
        for (unsigned i = 484; i < 502 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[502] = "0b111";
        ram[503] = "0b000";
        ram[504] = "0b000";
        ram[505] = "0b000";
        ram[506] = "0b000";
        ram[507] = "0b111";
        ram[508] = "0b001";
        ram[509] = "0b111";
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_3) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_3_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_3) {
meminst = new mlp_accel_4b_weights_l2_4b_3_ram("mlp_accel_4b_weights_l2_4b_3_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_3() {
    delete meminst;
}


};//endmodule
#endif
