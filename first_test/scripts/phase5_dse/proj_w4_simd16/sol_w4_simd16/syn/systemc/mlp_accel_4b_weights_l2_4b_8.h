// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_8_H__
#define __mlp_accel_4b_weights_l2_4b_8_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_8_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_8_ram) {
        ram[0] = "0b000";
        ram[1] = "0b000";
        ram[2] = "0b001";
        ram[3] = "0b000";
        ram[4] = "0b000";
        ram[5] = "0b000";
        ram[6] = "0b001";
        for (unsigned i = 7; i < 14 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[14] = "0b001";
        ram[15] = "0b000";
        ram[16] = "0b000";
        ram[17] = "0b000";
        ram[18] = "0b111";
        for (unsigned i = 19; i < 24 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[24] = "0b001";
        ram[25] = "0b000";
        ram[26] = "0b111";
        for (unsigned i = 27; i < 34 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[34] = "0b111";
        for (unsigned i = 35; i < 42 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[42] = "0b111";
        ram[43] = "0b000";
        ram[44] = "0b001";
        ram[45] = "0b000";
        ram[46] = "0b000";
        ram[47] = "0b000";
        ram[48] = "0b111";
        ram[49] = "0b111";
        ram[50] = "0b000";
        ram[51] = "0b000";
        ram[52] = "0b000";
        ram[53] = "0b000";
        ram[54] = "0b001";
        ram[55] = "0b000";
        ram[56] = "0b000";
        ram[57] = "0b000";
        ram[58] = "0b001";
        for (unsigned i = 59; i < 66 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[66] = "0b001";
        for (unsigned i = 67; i < 72 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[72] = "0b001";
        ram[73] = "0b000";
        ram[74] = "0b001";
        for (unsigned i = 75; i < 85 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[85] = "0b111";
        ram[86] = "0b000";
        ram[87] = "0b000";
        ram[88] = "0b111";
        ram[89] = "0b000";
        ram[90] = "0b001";
        ram[91] = "0b001";
        ram[92] = "0b000";
        ram[93] = "0b001";
        ram[94] = "0b000";
        ram[95] = "0b000";
        ram[96] = "0b000";
        ram[97] = "0b000";
        ram[98] = "0b001";
        ram[99] = "0b000";
        ram[100] = "0b000";
        ram[101] = "0b111";
        ram[102] = "0b000";
        ram[103] = "0b000";
        ram[104] = "0b001";
        ram[105] = "0b000";
        ram[106] = "0b000";
        ram[107] = "0b000";
        ram[108] = "0b000";
        ram[109] = "0b111";
        ram[110] = "0b000";
        ram[111] = "0b000";
        ram[112] = "0b000";
        ram[113] = "0b010";
        ram[114] = "0b001";
        ram[115] = "0b001";
        ram[116] = "0b000";
        ram[117] = "0b001";
        ram[118] = "0b000";
        ram[119] = "0b000";
        ram[120] = "0b000";
        ram[121] = "0b001";
        ram[122] = "0b000";
        ram[123] = "0b001";
        for (unsigned i = 124; i < 146 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[146] = "0b001";
        ram[147] = "0b001";
        ram[148] = "0b000";
        ram[149] = "0b001";
        ram[150] = "0b000";
        ram[151] = "0b000";
        ram[152] = "0b000";
        ram[153] = "0b001";
        ram[154] = "0b000";
        ram[155] = "0b001";
        ram[156] = "0b000";
        ram[157] = "0b001";
        ram[158] = "0b000";
        ram[159] = "0b000";
        ram[160] = "0b000";
        ram[161] = "0b001";
        ram[162] = "0b001";
        ram[163] = "0b000";
        ram[164] = "0b000";
        ram[165] = "0b010";
        ram[166] = "0b000";
        ram[167] = "0b000";
        ram[168] = "0b000";
        ram[169] = "0b001";
        ram[170] = "0b001";
        for (unsigned i = 171; i < 177 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[177] = "0b111";
        ram[178] = "0b111";
        ram[179] = "0b111";
        for (unsigned i = 180; i < 192 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[192] = "0b001";
        ram[193] = "0b001";
        for (unsigned i = 194; i < 201 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[201] = "0b001";
        for (unsigned i = 202; i < 213 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[213] = "0b001";
        ram[214] = "0b000";
        ram[215] = "0b000";
        ram[216] = "0b111";
        ram[217] = "0b000";
        ram[218] = "0b001";
        ram[219] = "0b000";
        ram[220] = "0b000";
        ram[221] = "0b001";
        ram[222] = "0b000";
        ram[223] = "0b001";
        for (unsigned i = 224; i < 233 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[233] = "0b001";
        ram[234] = "0b000";
        ram[235] = "0b000";
        ram[236] = "0b001";
        ram[237] = "0b000";
        ram[238] = "0b001";
        ram[239] = "0b001";
        ram[240] = "0b000";
        ram[241] = "0b000";
        ram[242] = "0b000";
        ram[243] = "0b001";
        ram[244] = "0b000";
        ram[245] = "0b001";
        ram[246] = "0b000";
        ram[247] = "0b000";
        ram[248] = "0b000";
        ram[249] = "0b000";
        ram[250] = "0b001";
        ram[251] = "0b000";
        ram[252] = "0b000";
        ram[253] = "0b001";
        ram[254] = "0b000";
        ram[255] = "0b000";
        ram[256] = "0b000";
        ram[257] = "0b001";
        ram[258] = "0b001";
        ram[259] = "0b000";
        ram[260] = "0b000";
        ram[261] = "0b001";
        ram[262] = "0b000";
        ram[263] = "0b000";
        ram[264] = "0b000";
        ram[265] = "0b001";
        ram[266] = "0b000";
        ram[267] = "0b111";
        ram[268] = "0b000";
        ram[269] = "0b001";
        ram[270] = "0b000";
        ram[271] = "0b000";
        ram[272] = "0b001";
        for (unsigned i = 273; i < 281 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[281] = "0b111";
        for (unsigned i = 282; i < 288 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[288] = "0b001";
        ram[289] = "0b111";
        ram[290] = "0b000";
        ram[291] = "0b000";
        ram[292] = "0b000";
        ram[293] = "0b111";
        ram[294] = "0b001";
        ram[295] = "0b000";
        ram[296] = "0b001";
        ram[297] = "0b001";
        ram[298] = "0b001";
        for (unsigned i = 299; i < 305 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[305] = "0b111";
        ram[306] = "0b111";
        ram[307] = "0b000";
        ram[308] = "0b000";
        ram[309] = "0b111";
        ram[310] = "0b000";
        ram[311] = "0b000";
        ram[312] = "0b000";
        ram[313] = "0b000";
        ram[314] = "0b001";
        ram[315] = "0b001";
        for (unsigned i = 316; i < 321 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[321] = "0b111";
        ram[322] = "0b000";
        ram[323] = "0b000";
        ram[324] = "0b111";
        ram[325] = "0b111";
        ram[326] = "0b001";
        ram[327] = "0b000";
        ram[328] = "0b000";
        ram[329] = "0b000";
        ram[330] = "0b111";
        ram[331] = "0b000";
        ram[332] = "0b000";
        ram[333] = "0b111";
        ram[334] = "0b111";
        for (unsigned i = 335; i < 345 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[345] = "0b111";
        ram[346] = "0b000";
        ram[347] = "0b111";
        ram[348] = "0b001";
        ram[349] = "0b111";
        ram[350] = "0b001";
        ram[351] = "0b000";
        ram[352] = "0b000";
        ram[353] = "0b000";
        ram[354] = "0b111";
        for (unsigned i = 355; i < 361 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[361] = "0b001";
        ram[362] = "0b000";
        ram[363] = "0b001";
        for (unsigned i = 364; i < 371 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[371] = "0b111";
        for (unsigned i = 372; i < 380 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[380] = "0b111";
        ram[381] = "0b111";
        for (unsigned i = 382; i < 387 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[387] = "0b001";
        ram[388] = "0b001";
        for (unsigned i = 389; i < 396 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[396] = "0b001";
        ram[397] = "0b001";
        ram[398] = "0b000";
        ram[399] = "0b000";
        ram[400] = "0b001";
        ram[401] = "0b000";
        ram[402] = "0b000";
        ram[403] = "0b000";
        ram[404] = "0b000";
        ram[405] = "0b111";
        ram[406] = "0b001";
        for (unsigned i = 407; i < 416 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[416] = "0b001";
        ram[417] = "0b000";
        ram[418] = "0b000";
        ram[419] = "0b000";
        ram[420] = "0b001";
        ram[421] = "0b000";
        ram[422] = "0b000";
        ram[423] = "0b001";
        ram[424] = "0b001";
        ram[425] = "0b111";
        ram[426] = "0b111";
        ram[427] = "0b000";
        ram[428] = "0b000";
        ram[429] = "0b111";
        ram[430] = "0b000";
        ram[431] = "0b000";
        ram[432] = "0b000";
        ram[433] = "0b001";
        ram[434] = "0b001";
        ram[435] = "0b111";
        ram[436] = "0b000";
        ram[437] = "0b001";
        for (unsigned i = 438; i < 445 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[445] = "0b001";
        ram[446] = "0b000";
        ram[447] = "0b000";
        ram[448] = "0b001";
        ram[449] = "0b001";
        for (unsigned i = 450; i < 458 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[458] = "0b111";
        ram[459] = "0b000";
        ram[460] = "0b000";
        ram[461] = "0b111";
        for (unsigned i = 462; i < 469 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[469] = "0b001";
        ram[470] = "0b000";
        ram[471] = "0b000";
        ram[472] = "0b000";
        ram[473] = "0b000";
        ram[474] = "0b001";
        ram[475] = "0b000";
        ram[476] = "0b111";
        ram[477] = "0b000";
        ram[478] = "0b000";
        ram[479] = "0b000";
        ram[480] = "0b000";
        ram[481] = "0b111";
        ram[482] = "0b000";
        ram[483] = "0b000";
        ram[484] = "0b001";
        for (unsigned i = 485; i < 498 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[498] = "0b001";
        for (unsigned i = 499; i < 504 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[504] = "0b001";
        ram[505] = "0b001";
        for (unsigned i = 506; i < 511 ; i = i + 1) {
            ram[i] = "0b000";
        }
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


SC_MODULE(mlp_accel_4b_weights_l2_4b_8) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_8_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_8) {
meminst = new mlp_accel_4b_weights_l2_4b_8_ram("mlp_accel_4b_weights_l2_4b_8_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_8() {
    delete meminst;
}


};//endmodule
#endif
