// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_1_H__
#define __mlp_accel_4b_weights_l2_4b_1_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_1_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_1_ram) {
        ram[0] = "0b001";
        ram[1] = "0b000";
        ram[2] = "0b111";
        ram[3] = "0b000";
        ram[4] = "0b000";
        ram[5] = "0b000";
        ram[6] = "0b001";
        ram[7] = "0b000";
        ram[8] = "0b000";
        ram[9] = "0b111";
        for (unsigned i = 10; i < 16 ; i = i + 1) {
            ram[i] = "0b001";
        }
        ram[16] = "0b000";
        ram[17] = "0b001";
        ram[18] = "0b000";
        ram[19] = "0b000";
        ram[20] = "0b111";
        ram[21] = "0b001";
        for (unsigned i = 22; i < 27 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[27] = "0b001";
        ram[28] = "0b001";
        ram[29] = "0b000";
        ram[30] = "0b000";
        ram[31] = "0b001";
        ram[32] = "0b000";
        ram[33] = "0b000";
        ram[34] = "0b000";
        ram[35] = "0b001";
        ram[36] = "0b001";
        ram[37] = "0b000";
        ram[38] = "0b000";
        ram[39] = "0b000";
        ram[40] = "0b000";
        ram[41] = "0b001";
        for (unsigned i = 42; i < 47 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[47] = "0b111";
        for (unsigned i = 48; i < 53 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[53] = "0b111";
        ram[54] = "0b001";
        ram[55] = "0b000";
        ram[56] = "0b000";
        ram[57] = "0b111";
        ram[58] = "0b000";
        ram[59] = "0b111";
        ram[60] = "0b000";
        ram[61] = "0b000";
        ram[62] = "0b000";
        ram[63] = "0b001";
        ram[64] = "0b000";
        ram[65] = "0b111";
        for (unsigned i = 66; i < 71 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[71] = "0b001";
        ram[72] = "0b000";
        ram[73] = "0b000";
        ram[74] = "0b111";
        for (unsigned i = 75; i < 80 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[80] = "0b001";
        for (unsigned i = 81; i < 90 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[90] = "0b001";
        ram[91] = "0b111";
        ram[92] = "0b000";
        ram[93] = "0b000";
        ram[94] = "0b000";
        ram[95] = "0b000";
        ram[96] = "0b111";
        ram[97] = "0b111";
        ram[98] = "0b000";
        ram[99] = "0b000";
        ram[100] = "0b000";
        ram[101] = "0b001";
        ram[102] = "0b000";
        ram[103] = "0b001";
        ram[104] = "0b000";
        ram[105] = "0b000";
        ram[106] = "0b111";
        for (unsigned i = 107; i < 113 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[113] = "0b111";
        ram[114] = "0b000";
        ram[115] = "0b000";
        ram[116] = "0b000";
        ram[117] = "0b010";
        ram[118] = "0b000";
        ram[119] = "0b000";
        ram[120] = "0b111";
        ram[121] = "0b000";
        ram[122] = "0b000";
        ram[123] = "0b000";
        ram[124] = "0b000";
        ram[125] = "0b001";
        for (unsigned i = 126; i < 137 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[137] = "0b110";
        ram[138] = "0b000";
        ram[139] = "0b000";
        ram[140] = "0b000";
        ram[141] = "0b001";
        ram[142] = "0b000";
        ram[143] = "0b001";
        ram[144] = "0b000";
        ram[145] = "0b001";
        ram[146] = "0b111";
        for (unsigned i = 147; i < 154 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[154] = "0b111";
        ram[155] = "0b111";
        for (unsigned i = 156; i < 161 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[161] = "0b111";
        ram[162] = "0b001";
        ram[163] = "0b000";
        ram[164] = "0b000";
        ram[165] = "0b001";
        ram[166] = "0b000";
        ram[167] = "0b000";
        ram[168] = "0b000";
        ram[169] = "0b111";
        ram[170] = "0b000";
        ram[171] = "0b111";
        ram[172] = "0b000";
        ram[173] = "0b000";
        ram[174] = "0b000";
        ram[175] = "0b001";
        ram[176] = "0b001";
        ram[177] = "0b111";
        ram[178] = "0b000";
        ram[179] = "0b000";
        ram[180] = "0b000";
        ram[181] = "0b111";
        for (unsigned i = 182; i < 195 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[195] = "0b111";
        ram[196] = "0b000";
        ram[197] = "0b000";
        ram[198] = "0b000";
        ram[199] = "0b001";
        ram[200] = "0b000";
        ram[201] = "0b001";
        ram[202] = "0b001";
        ram[203] = "0b001";
        ram[204] = "0b000";
        ram[205] = "0b001";
        ram[206] = "0b000";
        ram[207] = "0b000";
        ram[208] = "0b111";
        ram[209] = "0b000";
        ram[210] = "0b000";
        ram[211] = "0b111";
        ram[212] = "0b000";
        ram[213] = "0b000";
        ram[214] = "0b111";
        ram[215] = "0b000";
        ram[216] = "0b000";
        ram[217] = "0b000";
        ram[218] = "0b000";
        ram[219] = "0b111";
        ram[220] = "0b111";
        ram[221] = "0b111";
        for (unsigned i = 222; i < 234 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[234] = "0b111";
        ram[235] = "0b111";
        ram[236] = "0b000";
        ram[237] = "0b111";
        for (unsigned i = 238; i < 245 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[245] = "0b001";
        ram[246] = "0b000";
        ram[247] = "0b000";
        ram[248] = "0b111";
        ram[249] = "0b000";
        ram[250] = "0b000";
        ram[251] = "0b001";
        ram[252] = "0b000";
        ram[253] = "0b000";
        ram[254] = "0b000";
        ram[255] = "0b000";
        ram[256] = "0b111";
        ram[257] = "0b000";
        ram[258] = "0b000";
        ram[259] = "0b000";
        ram[260] = "0b111";
        ram[261] = "0b001";
        ram[262] = "0b111";
        ram[263] = "0b111";
        for (unsigned i = 264; i < 269 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[269] = "0b001";
        ram[270] = "0b000";
        ram[271] = "0b000";
        ram[272] = "0b001";
        ram[273] = "0b000";
        ram[274] = "0b111";
        for (unsigned i = 275; i < 289 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[289] = "0b001";
        ram[290] = "0b000";
        ram[291] = "0b001";
        for (unsigned i = 292; i < 307 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[307] = "0b001";
        ram[308] = "0b000";
        ram[309] = "0b000";
        ram[310] = "0b001";
        ram[311] = "0b001";
        ram[312] = "0b000";
        ram[313] = "0b000";
        ram[314] = "0b000";
        ram[315] = "0b001";
        for (unsigned i = 316; i < 324 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[324] = "0b001";
        ram[325] = "0b000";
        ram[326] = "0b001";
        for (unsigned i = 327; i < 344 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[344] = "0b001";
        ram[345] = "0b001";
        ram[346] = "0b111";
        ram[347] = "0b000";
        ram[348] = "0b000";
        ram[349] = "0b110";
        ram[350] = "0b000";
        ram[351] = "0b111";
        ram[352] = "0b001";
        ram[353] = "0b010";
        ram[354] = "0b000";
        ram[355] = "0b001";
        ram[356] = "0b000";
        ram[357] = "0b000";
        ram[358] = "0b000";
        ram[359] = "0b111";
        ram[360] = "0b000";
        ram[361] = "0b000";
        ram[362] = "0b001";
        ram[363] = "0b000";
        ram[364] = "0b000";
        ram[365] = "0b001";
        for (unsigned i = 366; i < 371 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[371] = "0b001";
        ram[372] = "0b000";
        ram[373] = "0b000";
        ram[374] = "0b000";
        ram[375] = "0b001";
        ram[376] = "0b001";
        ram[377] = "0b000";
        ram[378] = "0b000";
        ram[379] = "0b001";
        ram[380] = "0b001";
        ram[381] = "0b000";
        ram[382] = "0b001";
        ram[383] = "0b000";
        ram[384] = "0b000";
        ram[385] = "0b001";
        ram[386] = "0b001";
        for (unsigned i = 387; i < 393 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[393] = "0b110";
        ram[394] = "0b000";
        ram[395] = "0b000";
        ram[396] = "0b000";
        ram[397] = "0b001";
        ram[398] = "0b000";
        ram[399] = "0b001";
        for (unsigned i = 400; i < 405 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[405] = "0b111";
        for (unsigned i = 406; i < 419 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[419] = "0b111";
        ram[420] = "0b000";
        ram[421] = "0b111";
        ram[422] = "0b001";
        ram[423] = "0b000";
        ram[424] = "0b000";
        ram[425] = "0b001";
        ram[426] = "0b001";
        ram[427] = "0b001";
        ram[428] = "0b001";
        ram[429] = "0b000";
        ram[430] = "0b000";
        ram[431] = "0b000";
        ram[432] = "0b111";
        ram[433] = "0b000";
        ram[434] = "0b001";
        ram[435] = "0b001";
        ram[436] = "0b000";
        ram[437] = "0b001";
        ram[438] = "0b000";
        ram[439] = "0b001";
        ram[440] = "0b000";
        ram[441] = "0b001";
        ram[442] = "0b000";
        ram[443] = "0b111";
        ram[444] = "0b000";
        ram[445] = "0b111";
        ram[446] = "0b000";
        ram[447] = "0b000";
        ram[448] = "0b000";
        ram[449] = "0b001";
        ram[450] = "0b111";
        for (unsigned i = 451; i < 457 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[457] = "0b001";
        ram[458] = "0b001";
        ram[459] = "0b001";
        ram[460] = "0b000";
        ram[461] = "0b000";
        ram[462] = "0b000";
        ram[463] = "0b000";
        ram[464] = "0b111";
        ram[465] = "0b001";
        ram[466] = "0b001";
        ram[467] = "0b001";
        for (unsigned i = 468; i < 474 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[474] = "0b001";
        ram[475] = "0b001";
        ram[476] = "0b001";
        ram[477] = "0b001";
        ram[478] = "0b000";
        ram[479] = "0b001";
        ram[480] = "0b000";
        ram[481] = "0b001";
        ram[482] = "0b000";
        ram[483] = "0b001";
        ram[484] = "0b000";
        ram[485] = "0b111";
        ram[486] = "0b000";
        ram[487] = "0b111";
        for (unsigned i = 488; i < 497 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[497] = "0b111";
        ram[498] = "0b000";
        ram[499] = "0b001";
        ram[500] = "0b001";
        ram[501] = "0b001";
        ram[502] = "0b000";
        ram[503] = "0b000";
        ram[504] = "0b000";
        ram[505] = "0b001";
        for (unsigned i = 506; i < 512 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_1) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_1_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_1) {
meminst = new mlp_accel_4b_weights_l2_4b_1_ram("mlp_accel_4b_weights_l2_4b_1_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_1() {
    delete meminst;
}


};//endmodule
#endif
