// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l2_4b_4_H__
#define __mlp_accel_4b_weights_l2_4b_4_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l2_4b_4_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 2;
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


   SC_CTOR(mlp_accel_4b_weights_l2_4b_4_ram) {
        ram[0] = "0b00";
        ram[1] = "0b00";
        ram[2] = "0b00";
        ram[3] = "0b01";
        ram[4] = "0b01";
        for (unsigned i = 5; i < 12 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[12] = "0b01";
        ram[13] = "0b00";
        ram[14] = "0b00";
        ram[15] = "0b01";
        for (unsigned i = 16; i < 22 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[22] = "0b01";
        for (unsigned i = 23; i < 30 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[30] = "0b11";
        for (unsigned i = 31; i < 38 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[38] = "0b11";
        ram[39] = "0b00";
        ram[40] = "0b11";
        for (unsigned i = 41; i < 52 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[52] = "0b01";
        ram[53] = "0b00";
        ram[54] = "0b00";
        ram[55] = "0b01";
        ram[56] = "0b00";
        ram[57] = "0b01";
        ram[58] = "0b00";
        ram[59] = "0b00";
        ram[60] = "0b01";
        ram[61] = "0b00";
        ram[62] = "0b00";
        ram[63] = "0b00";
        ram[64] = "0b00";
        ram[65] = "0b01";
        ram[66] = "0b00";
        ram[67] = "0b00";
        ram[68] = "0b00";
        ram[69] = "0b00";
        ram[70] = "0b11";
        ram[71] = "0b01";
        for (unsigned i = 72; i < 78 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[78] = "0b01";
        for (unsigned i = 79; i < 84 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[84] = "0b11";
        ram[85] = "0b00";
        ram[86] = "0b11";
        ram[87] = "0b01";
        ram[88] = "0b00";
        ram[89] = "0b00";
        ram[90] = "0b00";
        ram[91] = "0b01";
        ram[92] = "0b01";
        for (unsigned i = 93; i < 102 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[102] = "0b01";
        ram[103] = "0b00";
        ram[104] = "0b00";
        ram[105] = "0b01";
        for (unsigned i = 106; i < 111 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[111] = "0b01";
        ram[112] = "0b01";
        ram[113] = "0b00";
        ram[114] = "0b00";
        ram[115] = "0b01";
        ram[116] = "0b01";
        ram[117] = "0b01";
        for (unsigned i = 118; i < 125 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[125] = "0b01";
        for (unsigned i = 126; i < 141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[141] = "0b01";
        for (unsigned i = 142; i < 147 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[147] = "0b01";
        ram[148] = "0b00";
        ram[149] = "0b11";
        ram[150] = "0b01";
        ram[151] = "0b00";
        ram[152] = "0b01";
        for (unsigned i = 153; i < 158 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[158] = "0b01";
        for (unsigned i = 159; i < 165 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[165] = "0b01";
        ram[166] = "0b10";
        for (unsigned i = 167; i < 173 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[173] = "0b01";
        for (unsigned i = 174; i < 182 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[182] = "0b11";
        for (unsigned i = 183; i < 192 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[192] = "0b01";
        for (unsigned i = 193; i < 198 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[198] = "0b01";
        ram[199] = "0b00";
        ram[200] = "0b00";
        ram[201] = "0b11";
        ram[202] = "0b11";
        for (unsigned i = 203; i < 214 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[214] = "0b01";
        ram[215] = "0b00";
        ram[216] = "0b01";
        ram[217] = "0b01";
        ram[218] = "0b01";
        ram[219] = "0b00";
        ram[220] = "0b01";
        for (unsigned i = 221; i < 235 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[235] = "0b01";
        ram[236] = "0b01";
        ram[237] = "0b00";
        ram[238] = "0b01";
        ram[239] = "0b00";
        ram[240] = "0b00";
        ram[241] = "0b00";
        ram[242] = "0b01";
        ram[243] = "0b01";
        ram[244] = "0b01";
        ram[245] = "0b11";
        ram[246] = "0b00";
        ram[247] = "0b00";
        ram[248] = "0b00";
        ram[249] = "0b11";
        ram[250] = "0b00";
        ram[251] = "0b01";
        ram[252] = "0b11";
        ram[253] = "0b00";
        ram[254] = "0b11";
        for (unsigned i = 255; i < 262 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[262] = "0b11";
        for (unsigned i = 263; i < 287 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[287] = "0b01";
        for (unsigned i = 288; i < 295 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[295] = "0b01";
        ram[296] = "0b00";
        ram[297] = "0b00";
        ram[298] = "0b00";
        ram[299] = "0b01";
        for (unsigned i = 300; i < 311 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[311] = "0b01";
        ram[312] = "0b00";
        ram[313] = "0b01";
        for (unsigned i = 314; i < 319 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[319] = "0b01";
        for (unsigned i = 320; i < 327 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[327] = "0b01";
        for (unsigned i = 328; i < 334 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[334] = "0b01";
        for (unsigned i = 335; i < 344 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[344] = "0b11";
        ram[345] = "0b01";
        for (unsigned i = 346; i < 360 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[360] = "0b01";
        ram[361] = "0b11";
        ram[362] = "0b00";
        ram[363] = "0b00";
        ram[364] = "0b00";
        ram[365] = "0b01";
        ram[366] = "0b01";
        for (unsigned i = 367; i < 374 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[374] = "0b11";
        for (unsigned i = 375; i < 388 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[388] = "0b01";
        for (unsigned i = 389; i < 401 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[401] = "0b01";
        for (unsigned i = 402; i < 418 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[418] = "0b01";
        ram[419] = "0b01";
        ram[420] = "0b00";
        ram[421] = "0b01";
        ram[422] = "0b01";
        ram[423] = "0b01";
        ram[424] = "0b00";
        ram[425] = "0b01";
        ram[426] = "0b00";
        ram[427] = "0b00";
        ram[428] = "0b11";
        for (unsigned i = 429; i < 434 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[434] = "0b11";
        ram[435] = "0b00";
        ram[436] = "0b00";
        ram[437] = "0b00";
        ram[438] = "0b11";
        for (unsigned i = 439; i < 446 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[446] = "0b01";
        for (unsigned i = 447; i < 458 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[458] = "0b11";
        ram[459] = "0b00";
        ram[460] = "0b11";
        for (unsigned i = 461; i < 468 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[468] = "0b11";
        ram[469] = "0b00";
        ram[470] = "0b11";
        ram[471] = "0b00";
        ram[472] = "0b00";
        ram[473] = "0b01";
        ram[474] = "0b00";
        ram[475] = "0b00";
        ram[476] = "0b00";
        ram[477] = "0b00";
        ram[478] = "0b11";
        ram[479] = "0b00";
        ram[480] = "0b11";
        for (unsigned i = 481; i < 502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[502] = "0b11";
        for (unsigned i = 503; i < 509 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[509] = "0b01";
        ram[510] = "0b00";
        ram[511] = "0b00";


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


SC_MODULE(mlp_accel_4b_weights_l2_4b_4) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 512;
static const unsigned AddressWidth = 9;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l2_4b_4_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l2_4b_4) {
meminst = new mlp_accel_4b_weights_l2_4b_4_ram("mlp_accel_4b_weights_l2_4b_4_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l2_4b_4() {
    delete meminst;
}


};//endmodule
#endif
