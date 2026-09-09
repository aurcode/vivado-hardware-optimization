// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_6_H__
#define __mlp_accel_4b_weights_l2_4b_6_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_6_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_6_ram) {
        ram[0] = "0b000";
        ram[1] = "0b000";
        ram[2] = "0b000";
        ram[3] = "0b000";
        ram[4] = "0b110";
        ram[5] = "0b000";
        ram[6] = "0b001";
        ram[7] = "0b000";
        ram[8] = "0b000";
        ram[9] = "0b000";
        ram[10] = "0b000";
        ram[11] = "0b001";
        ram[12] = "0b000";
        ram[13] = "0b000";
        ram[14] = "0b000";
        ram[15] = "0b000";
        ram[16] = "0b001";
        for (unsigned i = 17; i < 26 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[26] = "0b111";
        ram[27] = "0b000";
        ram[28] = "0b001";
        for (unsigned i = 29; i < 54 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[54] = "0b001";
        ram[55] = "0b001";
        ram[56] = "0b000";
        ram[57] = "0b000";
        ram[58] = "0b000";
        ram[59] = "0b000";
        ram[60] = "0b111";
        ram[61] = "0b000";
        ram[62] = "0b000";
        ram[63] = "0b000";
        ram[64] = "0b111";
        for (unsigned i = 65; i < 76 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[76] = "0b001";
        for (unsigned i = 77; i < 94 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[94] = "0b001";
        ram[95] = "0b001";
        ram[96] = "0b000";
        ram[97] = "0b000";
        ram[98] = "0b000";
        ram[99] = "0b001";
        ram[100] = "0b001";
        for (unsigned i = 101; i < 108 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[108] = "0b001";
        ram[109] = "0b000";
        ram[110] = "0b000";
        ram[111] = "0b000";
        ram[112] = "0b001";
        ram[113] = "0b000";
        ram[114] = "0b000";
        ram[115] = "0b001";
        for (unsigned i = 116; i < 123 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[123] = "0b001";
        for (unsigned i = 124; i < 139 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[139] = "0b001";
        for (unsigned i = 140; i < 152 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[152] = "0b001";
        ram[153] = "0b001";
        ram[154] = "0b000";
        ram[155] = "0b000";
        ram[156] = "0b111";
        ram[157] = "0b000";
        ram[158] = "0b000";
        ram[159] = "0b111";
        ram[160] = "0b000";
        ram[161] = "0b001";
        ram[162] = "0b000";
        ram[163] = "0b000";
        ram[164] = "0b111";
        ram[165] = "0b000";
        ram[166] = "0b000";
        ram[167] = "0b000";
        ram[168] = "0b000";
        ram[169] = "0b001";
        for (unsigned i = 170; i < 177 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[177] = "0b111";
        ram[178] = "0b001";
        ram[179] = "0b000";
        ram[180] = "0b001";
        for (unsigned i = 181; i < 192 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[192] = "0b001";
        ram[193] = "0b001";
        ram[194] = "0b000";
        ram[195] = "0b000";
        ram[196] = "0b001";
        ram[197] = "0b000";
        ram[198] = "0b111";
        ram[199] = "0b111";
        ram[200] = "0b000";
        ram[201] = "0b000";
        ram[202] = "0b000";
        ram[203] = "0b001";
        ram[204] = "0b001";
        ram[205] = "0b000";
        ram[206] = "0b000";
        ram[207] = "0b000";
        ram[208] = "0b001";
        ram[209] = "0b001";
        ram[210] = "0b000";
        ram[211] = "0b000";
        ram[212] = "0b001";
        ram[213] = "0b000";
        ram[214] = "0b000";
        ram[215] = "0b000";
        ram[216] = "0b000";
        ram[217] = "0b001";
        ram[218] = "0b000";
        ram[219] = "0b000";
        ram[220] = "0b111";
        for (unsigned i = 221; i < 232 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[232] = "0b001";
        ram[233] = "0b000";
        ram[234] = "0b000";
        ram[235] = "0b001";
        ram[236] = "0b111";
        ram[237] = "0b001";
        for (unsigned i = 238; i < 244 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[244] = "0b110";
        ram[245] = "0b000";
        ram[246] = "0b000";
        ram[247] = "0b000";
        ram[248] = "0b111";
        ram[249] = "0b001";
        ram[250] = "0b000";
        ram[251] = "0b001";
        ram[252] = "0b001";
        for (unsigned i = 253; i < 258 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[258] = "0b001";
        ram[259] = "0b000";
        ram[260] = "0b000";
        ram[261] = "0b001";
        for (unsigned i = 262; i < 269 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[269] = "0b001";
        ram[270] = "0b000";
        ram[271] = "0b001";
        ram[272] = "0b001";
        ram[273] = "0b000";
        ram[274] = "0b000";
        ram[275] = "0b000";
        ram[276] = "0b110";
        ram[277] = "0b000";
        ram[278] = "0b000";
        ram[279] = "0b111";
        ram[280] = "0b000";
        ram[281] = "0b000";
        ram[282] = "0b000";
        ram[283] = "0b000";
        ram[284] = "0b010";
        ram[285] = "0b111";
        ram[286] = "0b001";
        ram[287] = "0b000";
        ram[288] = "0b111";
        ram[289] = "0b001";
        ram[290] = "0b000";
        ram[291] = "0b001";
        ram[292] = "0b001";
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
        ram[308] = "0b001";
        ram[309] = "0b000";
        ram[310] = "0b000";
        ram[311] = "0b001";
        ram[312] = "0b000";
        ram[313] = "0b000";
        ram[314] = "0b000";
        ram[315] = "0b000";
        ram[316] = "0b111";
        ram[317] = "0b111";
        ram[318] = "0b000";
        ram[319] = "0b111";
        for (unsigned i = 320; i < 325 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[325] = "0b111";
        ram[326] = "0b000";
        ram[327] = "0b000";
        ram[328] = "0b001";
        ram[329] = "0b000";
        ram[330] = "0b000";
        ram[331] = "0b111";
        ram[332] = "0b111";
        ram[333] = "0b000";
        ram[334] = "0b111";
        for (unsigned i = 335; i < 349 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[349] = "0b001";
        ram[350] = "0b001";
        ram[351] = "0b000";
        ram[352] = "0b001";
        for (unsigned i = 353; i < 359 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[359] = "0b001";
        ram[360] = "0b001";
        ram[361] = "0b000";
        ram[362] = "0b000";
        ram[363] = "0b000";
        ram[364] = "0b111";
        ram[365] = "0b000";
        ram[366] = "0b000";
        ram[367] = "0b000";
        ram[368] = "0b111";
        ram[369] = "0b000";
        ram[370] = "0b000";
        ram[371] = "0b000";
        ram[372] = "0b001";
        for (unsigned i = 373; i < 381 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[381] = "0b111";
        for (unsigned i = 382; i < 388 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[388] = "0b001";
        ram[389] = "0b000";
        ram[390] = "0b000";
        ram[391] = "0b001";
        for (unsigned i = 392; i < 399 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[399] = "0b001";
        ram[400] = "0b000";
        ram[401] = "0b000";
        ram[402] = "0b000";
        ram[403] = "0b000";
        ram[404] = "0b111";
        ram[405] = "0b000";
        ram[406] = "0b000";
        ram[407] = "0b111";
        for (unsigned i = 408; i < 421 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[421] = "0b001";
        ram[422] = "0b000";
        ram[423] = "0b001";
        ram[424] = "0b000";
        ram[425] = "0b000";
        ram[426] = "0b000";
        ram[427] = "0b000";
        ram[428] = "0b001";
        ram[429] = "0b000";
        ram[430] = "0b000";
        ram[431] = "0b001";
        ram[432] = "0b111";
        ram[433] = "0b000";
        ram[434] = "0b000";
        ram[435] = "0b000";
        ram[436] = "0b001";
        for (unsigned i = 437; i < 444 ; i = i + 1) {
            ram[i] = "0b000";
        }
        for (unsigned i = 444; i < 449 ; i = i + 1) {
            ram[i] = "0b001";
        }
        ram[449] = "0b000";
        ram[450] = "0b000";
        ram[451] = "0b000";
        ram[452] = "0b110";
        ram[453] = "0b000";
        ram[454] = "0b000";
        ram[455] = "0b000";
        ram[456] = "0b000";
        ram[457] = "0b111";
        for (unsigned i = 458; i < 464 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[464] = "0b111";
        ram[465] = "0b000";
        ram[466] = "0b000";
        ram[467] = "0b000";
        ram[468] = "0b001";
        ram[469] = "0b000";
        ram[470] = "0b000";
        ram[471] = "0b001";
        ram[472] = "0b111";
        for (unsigned i = 473; i < 486 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[486] = "0b001";
        ram[487] = "0b001";
        for (unsigned i = 488; i < 498 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[498] = "0b001";
        ram[499] = "0b001";
        ram[500] = "0b000";
        ram[501] = "0b000";
        ram[502] = "0b000";
        ram[503] = "0b111";
        ram[504] = "0b000";
        ram[505] = "0b000";
        ram[506] = "0b000";
        ram[507] = "0b000";
        ram[508] = "0b111";
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_6) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_6_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_6) {
meminst = new mlp_accel_4b_weights_l2_4b_6_ram("mlp_accel_4b_weights_l2_4b_6_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_6() {
    delete meminst;
}


};//endmodule
#endif
