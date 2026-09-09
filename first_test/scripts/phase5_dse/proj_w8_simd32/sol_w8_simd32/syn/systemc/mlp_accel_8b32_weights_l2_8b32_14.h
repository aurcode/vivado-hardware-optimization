// ==============================================================
// File generated on Wed Sep 02 16:32:48 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_8b32_weights_l2_8b32_14_H__
#define __mlp_accel_8b32_weights_l2_8b32_14_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_8b32_weights_l2_8b32_14_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 7;
  static const unsigned AddressRange = 256;
  static const unsigned AddressWidth = 8;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(mlp_accel_8b32_weights_l2_8b32_14_ram) {
        ram[0] = "0b0000000";
        ram[1] = "0b0000000";
        ram[2] = "0b1111111";
        ram[3] = "0b0000001";
        ram[4] = "0b1111110";
        ram[5] = "0b0000000";
        ram[6] = "0b0001110";
        ram[7] = "0b0010000";
        ram[8] = "0b1111111";
        ram[9] = "0b0000000";
        ram[10] = "0b0000100";
        ram[11] = "0b1111111";
        ram[12] = "0b1100111";
        ram[13] = "0b0000000";
        ram[14] = "0b0001011";
        ram[15] = "0b0010000";
        ram[16] = "0b0000000";
        ram[17] = "0b0000000";
        ram[18] = "0b0001001";
        ram[19] = "0b0010010";
        ram[20] = "0b0001101";
        ram[21] = "0b0000000";
        ram[22] = "0b0000001";
        ram[23] = "0b0001110";
        ram[24] = "0b0000100";
        ram[25] = "0b0000000";
        ram[26] = "0b1101011";
        ram[27] = "0b1110111";
        ram[28] = "0b0001100";
        ram[29] = "0b0000000";
        ram[30] = "0b1111101";
        ram[31] = "0b1111100";
        ram[32] = "0b1111111";
        ram[33] = "0b0000000";
        ram[34] = "0b0001001";
        ram[35] = "0b0000010";
        ram[36] = "0b0010011";
        ram[37] = "0b0000000";
        ram[38] = "0b0000001";
        ram[39] = "0b1110110";
        ram[40] = "0b1110111";
        ram[41] = "0b0000000";
        ram[42] = "0b1110110";
        ram[43] = "0b0000010";
        ram[44] = "0b0000010";
        ram[45] = "0b0000000";
        ram[46] = "0b0000100";
        ram[47] = "0b0000100";
        ram[48] = "0b0000001";
        ram[49] = "0b0000000";
        ram[50] = "0b1111001";
        ram[51] = "0b1110101";
        ram[52] = "0b0000010";
        ram[53] = "0b0000000";
        ram[54] = "0b1110011";
        ram[55] = "0b1101111";
        ram[56] = "0b1110101";
        ram[57] = "0b0000000";
        ram[58] = "0b0011111";
        ram[59] = "0b0001001";
        ram[60] = "0b1110001";
        ram[61] = "0b0000000";
        ram[62] = "0b0000000";
        ram[63] = "0b0001110";
        ram[64] = "0b0000000";
        ram[65] = "0b0000000";
        ram[66] = "0b1111110";
        ram[67] = "0b0000011";
        ram[68] = "0b0001001";
        ram[69] = "0b0000000";
        ram[70] = "0b0010000";
        ram[71] = "0b0000101";
        ram[72] = "0b0010000";
        ram[73] = "0b0000000";
        ram[74] = "0b0000111";
        ram[75] = "0b1110111";
        ram[76] = "0b0000010";
        ram[77] = "0b0000000";
        ram[78] = "0b0001100";
        ram[79] = "0b1111110";
        ram[80] = "0b1111100";
        ram[81] = "0b0000000";
        ram[82] = "0b0100110";
        ram[83] = "0b0001001";
        ram[84] = "0b1111101";
        ram[85] = "0b0000000";
        ram[86] = "0b0010010";
        ram[87] = "0b1111001";
        ram[88] = "0b0001001";
        ram[89] = "0b0000000";
        ram[90] = "0b1100001";
        ram[91] = "0b0000010";
        ram[92] = "0b0000000";
        ram[93] = "0b0000000";
        ram[94] = "0b0000000";
        ram[95] = "0b0000000";
        ram[96] = "0b1110110";
        ram[97] = "0b0000000";
        ram[98] = "0b0001011";
        ram[99] = "0b0000001";
        ram[100] = "0b1110101";
        ram[101] = "0b0000000";
        ram[102] = "0b0000111";
        ram[103] = "0b0010111";
        ram[104] = "0b0010001";
        ram[105] = "0b0000000";
        ram[106] = "0b0001000";
        ram[107] = "0b1111110";
        ram[108] = "0b1111100";
        ram[109] = "0b0000000";
        ram[110] = "0b1110011";
        ram[111] = "0b1101111";
        ram[112] = "0b0000000";
        ram[113] = "0b0000000";
        ram[114] = "0b0000000";
        ram[115] = "0b0000000";
        ram[116] = "0b0000011";
        ram[117] = "0b0000000";
        ram[118] = "0b1110101";
        ram[119] = "0b1110001";
        ram[120] = "0b0000111";
        ram[121] = "0b0000000";
        ram[122] = "0b0010001";
        ram[123] = "0b0001001";
        ram[124] = "0b1111110";
        ram[125] = "0b0000000";
        ram[126] = "0b0011011";
        ram[127] = "0b0001011";
        ram[128] = "0b1111100";
        ram[129] = "0b0000000";
        ram[130] = "0b0010100";
        ram[131] = "0b0001101";
        ram[132] = "0b1111100";
        ram[133] = "0b0000000";
        ram[134] = "0b0000011";
        ram[135] = "0b0000101";
        ram[136] = "0b0000011";
        ram[137] = "0b0000000";
        ram[138] = "0b0000110";
        ram[139] = "0b0000010";
        ram[140] = "0b0000111";
        ram[141] = "0b0000000";
        ram[142] = "0b1110111";
        ram[143] = "0b1110011";
        ram[144] = "0b0000100";
        ram[145] = "0b0000000";
        ram[146] = "0b1110101";
        ram[147] = "0b1111001";
        ram[148] = "0b1111101";
        ram[149] = "0b0000000";
        ram[150] = "0b1111011";
        ram[151] = "0b0000010";
        ram[152] = "0b0000111";
        ram[153] = "0b0000000";
        ram[154] = "0b1101111";
        ram[155] = "0b1111101";
        ram[156] = "0b0010000";
        ram[157] = "0b0000000";
        ram[158] = "0b0001001";
        ram[159] = "0b0001000";
        ram[160] = "0b1111101";
        ram[161] = "0b0000000";
        ram[162] = "0b1110111";
        ram[163] = "0b1111011";
        ram[164] = "0b0000100";
        ram[165] = "0b0000000";
        ram[166] = "0b1110010";
        ram[167] = "0b0000111";
        ram[168] = "0b0000001";
        ram[169] = "0b0000000";
        ram[170] = "0b0000000";
        ram[171] = "0b1111111";
        ram[172] = "0b0001101";
        ram[173] = "0b0000000";
        ram[174] = "0b1100000";
        ram[175] = "0b1111110";
        ram[176] = "0b1111010";
        ram[177] = "0b0000000";
        ram[178] = "0b1111100";
        ram[179] = "0b0001001";
        ram[180] = "0b1110111";
        ram[181] = "0b0000000";
        ram[182] = "0b0000010";
        ram[183] = "0b0001110";
        ram[184] = "0b1111110";
        ram[185] = "0b0000000";
        ram[186] = "0b0000101";
        ram[187] = "0b0000111";
        ram[188] = "0b1110101";
        ram[189] = "0b0000000";
        ram[190] = "0b0000001";
        ram[191] = "0b0001011";
        ram[192] = "0b0000000";
        ram[193] = "0b0000000";
        ram[194] = "0b1111110";
        ram[195] = "0b0000010";
        ram[196] = "0b1110111";
        ram[197] = "0b0000000";
        ram[198] = "0b0001000";
        ram[199] = "0b0000011";
        ram[200] = "0b0001001";
        ram[201] = "0b0000000";
        ram[202] = "0b1111001";
        ram[203] = "0b0001001";
        ram[204] = "0b0000000";
        ram[205] = "0b0000000";
        ram[206] = "0b0000000";
        ram[207] = "0b0000000";
        ram[208] = "0b0000110";
        ram[209] = "0b0000000";
        ram[210] = "0b1100011";
        ram[211] = "0b1101100";
        ram[212] = "0b1110000";
        ram[213] = "0b0000000";
        ram[214] = "0b1101110";
        ram[215] = "0b0001011";
        ram[216] = "0b1101110";
        ram[217] = "0b0000000";
        ram[218] = "0b0001110";
        ram[219] = "0b0001111";
        ram[220] = "0b0001011";
        ram[221] = "0b0000000";
        ram[222] = "0b1110010";
        ram[223] = "0b1111000";
        ram[224] = "0b1111111";
        ram[225] = "0b0000000";
        ram[226] = "0b0001101";
        ram[227] = "0b0000110";
        ram[228] = "0b1111000";
        ram[229] = "0b0000000";
        ram[230] = "0b1110110";
        ram[231] = "0b0001100";
        ram[232] = "0b0000010";
        ram[233] = "0b0000000";
        ram[234] = "0b0010101";
        ram[235] = "0b0000010";
        ram[236] = "0b1110010";
        ram[237] = "0b0000000";
        ram[238] = "0b0001010";
        ram[239] = "0b0001010";
        ram[240] = "0b0010000";
        ram[241] = "0b0000000";
        ram[242] = "0b1111101";
        ram[243] = "0b0000101";
        ram[244] = "0b0000001";
        ram[245] = "0b0000000";
        ram[246] = "0b0000000";
        ram[247] = "0b1111111";
        ram[248] = "0b0000101";
        ram[249] = "0b0000000";
        ram[250] = "0b0011000";
        ram[251] = "0b0010000";
        ram[252] = "0b1111100";
        ram[253] = "0b0000000";
        ram[254] = "0b1110111";
        ram[255] = "0b0000100";


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


SC_MODULE(mlp_accel_8b32_weights_l2_8b32_14) {


static const unsigned DataWidth = 7;
static const unsigned AddressRange = 256;
static const unsigned AddressWidth = 8;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_8b32_weights_l2_8b32_14_ram* meminst;


SC_CTOR(mlp_accel_8b32_weights_l2_8b32_14) {
meminst = new mlp_accel_8b32_weights_l2_8b32_14_ram("mlp_accel_8b32_weights_l2_8b32_14_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_8b32_weights_l2_8b32_14() {
    delete meminst;
}


};//endmodule
#endif
