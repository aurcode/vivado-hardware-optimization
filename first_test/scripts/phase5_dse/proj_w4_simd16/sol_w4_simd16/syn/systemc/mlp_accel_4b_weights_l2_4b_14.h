// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_14_H__
#define __mlp_accel_4b_weights_l2_4b_14_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_14_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_14_ram) {
        for (unsigned i = 0; i < 12 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[12] = "0b001";
        ram[13] = "0b111";
        ram[14] = "0b001";
        ram[15] = "0b001";
        for (unsigned i = 16; i < 21 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[21] = "0b001";
        ram[22] = "0b000";
        ram[23] = "0b000";
        ram[24] = "0b110";
        ram[25] = "0b000";
        ram[26] = "0b000";
        ram[27] = "0b001";
        ram[28] = "0b001";
        ram[29] = "0b000";
        ram[30] = "0b001";
        ram[31] = "0b000";
        ram[32] = "0b000";
        ram[33] = "0b001";
        ram[34] = "0b000";
        ram[35] = "0b000";
        ram[36] = "0b001";
        ram[37] = "0b000";
        ram[38] = "0b001";
        ram[39] = "0b001";
        ram[40] = "0b001";
        ram[41] = "0b001";
        ram[42] = "0b000";
        ram[43] = "0b000";
        ram[44] = "0b000";
        ram[45] = "0b001";
        ram[46] = "0b001";
        ram[47] = "0b000";
        ram[48] = "0b000";
        ram[49] = "0b001";
        ram[50] = "0b000";
        ram[51] = "0b000";
        ram[52] = "0b111";
        ram[53] = "0b001";
        ram[54] = "0b111";
        ram[55] = "0b001";
        ram[56] = "0b001";
        for (unsigned i = 57; i < 63 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[63] = "0b001";
        ram[64] = "0b000";
        ram[65] = "0b001";
        ram[66] = "0b000";
        ram[67] = "0b000";
        ram[68] = "0b001";
        ram[69] = "0b111";
        ram[70] = "0b000";
        ram[71] = "0b000";
        ram[72] = "0b001";
        ram[73] = "0b000";
        ram[74] = "0b000";
        ram[75] = "0b000";
        ram[76] = "0b000";
        ram[77] = "0b111";
        ram[78] = "0b111";
        ram[79] = "0b000";
        ram[80] = "0b111";
        ram[81] = "0b000";
        ram[82] = "0b000";
        ram[83] = "0b111";
        ram[84] = "0b111";
        ram[85] = "0b000";
        ram[86] = "0b000";
        ram[87] = "0b000";
        ram[88] = "0b000";
        ram[89] = "0b001";
        ram[90] = "0b000";
        ram[91] = "0b000";
        ram[92] = "0b000";
        ram[93] = "0b001";
        ram[94] = "0b000";
        ram[95] = "0b001";
        ram[96] = "0b000";
        ram[97] = "0b000";
        ram[98] = "0b000";
        ram[99] = "0b001";
        ram[100] = "0b000";
        ram[101] = "0b111";
        ram[102] = "0b111";
        for (unsigned i = 103; i < 108 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[108] = "0b111";
        ram[109] = "0b000";
        ram[110] = "0b111";
        ram[111] = "0b000";
        ram[112] = "0b111";
        ram[113] = "0b000";
        ram[114] = "0b000";
        ram[115] = "0b000";
        ram[116] = "0b010";
        ram[117] = "0b000";
        ram[118] = "0b001";
        ram[119] = "0b000";
        ram[120] = "0b111";
        ram[121] = "0b000";
        ram[122] = "0b000";
        ram[123] = "0b000";
        ram[124] = "0b000";
        ram[125] = "0b001";
        ram[126] = "0b001";
        for (unsigned i = 127; i < 136 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[136] = "0b001";
        ram[137] = "0b000";
        ram[138] = "0b000";
        ram[139] = "0b000";
        ram[140] = "0b001";
        ram[141] = "0b110";
        ram[142] = "0b000";
        ram[143] = "0b000";
        ram[144] = "0b001";
        ram[145] = "0b000";
        ram[146] = "0b000";
        ram[147] = "0b001";
        ram[148] = "0b000";
        ram[149] = "0b001";
        ram[150] = "0b111";
        for (unsigned i = 151; i < 156 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[156] = "0b001";
        for (unsigned i = 157; i < 164 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[164] = "0b010";
        ram[165] = "0b001";
        ram[166] = "0b001";
        for (unsigned i = 167; i < 172 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[172] = "0b001";
        ram[173] = "0b111";
        ram[174] = "0b000";
        ram[175] = "0b000";
        ram[176] = "0b001";
        ram[177] = "0b000";
        ram[178] = "0b000";
        ram[179] = "0b000";
        ram[180] = "0b110";
        ram[181] = "0b111";
        ram[182] = "0b000";
        ram[183] = "0b001";
        for (unsigned i = 184; i < 192 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[192] = "0b111";
        ram[193] = "0b000";
        ram[194] = "0b000";
        ram[195] = "0b000";
        ram[196] = "0b001";
        ram[197] = "0b111";
        ram[198] = "0b000";
        ram[199] = "0b000";
        ram[200] = "0b111";
        ram[201] = "0b000";
        ram[202] = "0b000";
        ram[203] = "0b000";
        ram[204] = "0b000";
        ram[205] = "0b001";
        ram[206] = "0b001";
        ram[207] = "0b000";
        ram[208] = "0b001";
        ram[209] = "0b000";
        ram[210] = "0b000";
        ram[211] = "0b000";
        ram[212] = "0b001";
        ram[213] = "0b000";
        ram[214] = "0b000";
        ram[215] = "0b111";
        ram[216] = "0b000";
        ram[217] = "0b000";
        ram[218] = "0b000";
        ram[219] = "0b000";
        ram[220] = "0b111";
        ram[221] = "0b001";
        ram[222] = "0b111";
        for (unsigned i = 223; i < 236 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[236] = "0b111";
        ram[237] = "0b001";
        ram[238] = "0b111";
        for (unsigned i = 239; i < 244 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[244] = "0b001";
        ram[245] = "0b010";
        ram[246] = "0b001";
        for (unsigned i = 247; i < 252 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[252] = "0b010";
        ram[253] = "0b000";
        ram[254] = "0b001";
        for (unsigned i = 255; i < 260 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[260] = "0b001";
        ram[261] = "0b010";
        ram[262] = "0b001";
        for (unsigned i = 263; i < 269 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[269] = "0b111";
        ram[270] = "0b000";
        ram[271] = "0b001";
        for (unsigned i = 272; i < 281 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[281] = "0b111";
        ram[282] = "0b000";
        ram[283] = "0b001";
        ram[284] = "0b111";
        ram[285] = "0b000";
        ram[286] = "0b111";
        ram[287] = "0b000";
        ram[288] = "0b000";
        ram[289] = "0b000";
        ram[290] = "0b000";
        ram[291] = "0b001";
        ram[292] = "0b111";
        ram[293] = "0b000";
        ram[294] = "0b000";
        ram[295] = "0b000";
        ram[296] = "0b000";
        ram[297] = "0b001";
        ram[298] = "0b000";
        ram[299] = "0b000";
        ram[300] = "0b000";
        ram[301] = "0b001";
        for (unsigned i = 302; i < 308 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[308] = "0b111";
        ram[309] = "0b110";
        ram[310] = "0b000";
        ram[311] = "0b000";
        ram[312] = "0b001";
        ram[313] = "0b000";
        ram[314] = "0b000";
        ram[315] = "0b000";
        ram[316] = "0b001";
        ram[317] = "0b111";
        ram[318] = "0b000";
        ram[319] = "0b001";
        ram[320] = "0b000";
        ram[321] = "0b000";
        ram[322] = "0b000";
        ram[323] = "0b000";
        ram[324] = "0b111";
        for (unsigned i = 325; i < 332 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[332] = "0b111";
        ram[333] = "0b000";
        ram[334] = "0b000";
        ram[335] = "0b111";
        for (unsigned i = 336; i < 344 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[344] = "0b001";
        ram[345] = "0b001";
        ram[346] = "0b000";
        ram[347] = "0b000";
        ram[348] = "0b110";
        ram[349] = "0b001";
        for (unsigned i = 350; i < 357 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[357] = "0b001";
        ram[358] = "0b001";
        ram[359] = "0b000";
        ram[360] = "0b111";
        for (unsigned i = 361; i < 366 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[366] = "0b001";
        for (unsigned i = 367; i < 373 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[373] = "0b111";
        ram[374] = "0b000";
        ram[375] = "0b000";
        ram[376] = "0b111";
        for (unsigned i = 377; i < 382 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[382] = "0b001";
        ram[383] = "0b000";
        ram[384] = "0b000";
        ram[385] = "0b000";
        ram[386] = "0b000";
        ram[387] = "0b001";
        ram[388] = "0b000";
        ram[389] = "0b001";
        ram[390] = "0b000";
        ram[391] = "0b000";
        ram[392] = "0b111";
        for (unsigned i = 393; i < 400 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[400] = "0b001";
        for (unsigned i = 401; i < 406 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[406] = "0b001";
        for (unsigned i = 407; i < 417 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[417] = "0b001";
        ram[418] = "0b000";
        ram[419] = "0b000";
        ram[420] = "0b110";
        ram[421] = "0b000";
        ram[422] = "0b111";
        ram[423] = "0b000";
        ram[424] = "0b111";
        ram[425] = "0b000";
        ram[426] = "0b000";
        ram[427] = "0b000";
        ram[428] = "0b111";
        ram[429] = "0b111";
        ram[430] = "0b001";
        ram[431] = "0b000";
        ram[432] = "0b111";
        ram[433] = "0b000";
        ram[434] = "0b000";
        ram[435] = "0b000";
        ram[436] = "0b001";
        ram[437] = "0b000";
        ram[438] = "0b001";
        ram[439] = "0b000";
        ram[440] = "0b001";
        ram[441] = "0b001";
        ram[442] = "0b000";
        ram[443] = "0b000";
        ram[444] = "0b111";
        ram[445] = "0b000";
        ram[446] = "0b111";
        for (unsigned i = 447; i < 452 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[452] = "0b001";
        ram[453] = "0b001";
        for (unsigned i = 454; i < 459 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[459] = "0b111";
        ram[460] = "0b111";
        ram[461] = "0b000";
        ram[462] = "0b001";
        for (unsigned i = 463; i < 468 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[468] = "0b001";
        ram[469] = "0b000";
        ram[470] = "0b000";
        ram[471] = "0b000";
        ram[472] = "0b111";
        ram[473] = "0b000";
        ram[474] = "0b000";
        ram[475] = "0b000";
        ram[476] = "0b001";
        ram[477] = "0b111";
        ram[478] = "0b001";
        ram[479] = "0b001";
        ram[480] = "0b001";
        for (unsigned i = 481; i < 500 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[500] = "0b010";
        ram[501] = "0b000";
        ram[502] = "0b001";
        for (unsigned i = 503; i < 508 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[508] = "0b111";
        ram[509] = "0b000";
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_14) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_14_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_14) {
meminst = new mlp_accel_4b_weights_l2_4b_14_ram("mlp_accel_4b_weights_l2_4b_14_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_14() {
    delete meminst;
}


};//endmodule
#endif
