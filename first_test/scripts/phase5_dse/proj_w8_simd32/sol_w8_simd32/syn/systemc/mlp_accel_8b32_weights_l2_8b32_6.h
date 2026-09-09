// ==============================================================
// File generated on Wed Sep 02 16:32:47 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_8b32_weights_l2_8b32_6_H__
#define __mlp_accel_8b32_weights_l2_8b32_6_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_8b32_weights_l2_8b32_6_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_8b32_weights_l2_8b32_6_ram) {
        ram[0] = "0b0000100";
        ram[1] = "0b0000110";
        ram[2] = "0b1011111";
        ram[3] = "0b0001000";
        ram[4] = "0b1111101";
        ram[5] = "0b0000001";
        ram[6] = "0b0000000";
        ram[7] = "0b1111101";
        ram[8] = "0b0001111";
        ram[9] = "0b0000111";
        ram[10] = "0b0000000";
        ram[11] = "0b1111011";
        ram[12] = "0b0000010";
        ram[13] = "0b1111000";
        ram[14] = "0b0001010";
        ram[15] = "0b1111111";
        ram[16] = "0b1111010";
        ram[17] = "0b0000100";
        ram[18] = "0b0000010";
        ram[19] = "0b0000110";
        ram[20] = "0b0000110";
        ram[21] = "0b0000110";
        ram[22] = "0b1111101";
        ram[23] = "0b0000001";
        ram[24] = "0b0000001";
        ram[25] = "0b0000001";
        ram[26] = "0b0000011";
        ram[27] = "0b0001100";
        ram[28] = "0b0000110";
        ram[29] = "0b0000111";
        ram[30] = "0b1110010";
        ram[31] = "0b0000101";
        ram[32] = "0b1110011";
        ram[33] = "0b0000101";
        ram[34] = "0b1111011";
        ram[35] = "0b0000110";
        ram[36] = "0b1111001";
        ram[37] = "0b1111101";
        ram[38] = "0b0010010";
        ram[39] = "0b0000100";
        ram[40] = "0b0000000";
        ram[41] = "0b1111100";
        ram[42] = "0b1111001";
        ram[43] = "0b1111010";
        ram[44] = "0b1111110";
        ram[45] = "0b1111110";
        ram[46] = "0b1111011";
        ram[47] = "0b0001010";
        ram[48] = "0b1111101";
        ram[49] = "0b0000100";
        ram[50] = "0b0010011";
        ram[51] = "0b1111011";
        ram[52] = "0b0000110";
        ram[53] = "0b0000100";
        ram[54] = "0b0001000";
        ram[55] = "0b0000011";
        ram[56] = "0b0001100";
        ram[57] = "0b0000001";
        ram[58] = "0b1111000";
        ram[59] = "0b1111100";
        ram[60] = "0b0001000";
        ram[61] = "0b0000010";
        ram[62] = "0b1111001";
        ram[63] = "0b1111110";
        ram[64] = "0b1111111";
        ram[65] = "0b1111101";
        ram[66] = "0b1111100";
        ram[67] = "0b1111101";
        ram[68] = "0b0000000";
        ram[69] = "0b0000011";
        ram[70] = "0b1111011";
        ram[71] = "0b0000010";
        ram[72] = "0b0000100";
        ram[73] = "0b0000000";
        ram[74] = "0b0000100";
        ram[75] = "0b0001000";
        ram[76] = "0b0001101";
        ram[77] = "0b0000100";
        ram[78] = "0b1101010";
        ram[79] = "0b1111111";
        ram[80] = "0b1111101";
        ram[81] = "0b0000011";
        ram[82] = "0b1110101";
        ram[83] = "0b0000000";
        ram[84] = "0b0000100";
        ram[85] = "0b0000000";
        ram[86] = "0b1111100";
        ram[87] = "0b0000011";
        ram[88] = "0b1111100";
        ram[89] = "0b0001010";
        ram[90] = "0b0001100";
        ram[91] = "0b0000111";
        ram[92] = "0b0000000";
        ram[93] = "0b0000000";
        ram[94] = "0b0000000";
        ram[95] = "0b0000000";
        ram[96] = "0b0001011";
        ram[97] = "0b1111010";
        ram[98] = "0b0010001";
        ram[99] = "0b1110111";
        ram[100] = "0b0000000";
        ram[101] = "0b0000100";
        ram[102] = "0b0001010";
        ram[103] = "0b0000010";
        ram[104] = "0b0001111";
        ram[105] = "0b0000000";
        ram[106] = "0b0010010";
        ram[107] = "0b1111110";
        ram[108] = "0b0000010";
        ram[109] = "0b0000110";
        ram[110] = "0b1101110";
        ram[111] = "0b0000110";
        ram[112] = "0b0000000";
        ram[113] = "0b0000000";
        ram[114] = "0b0000000";
        ram[115] = "0b0000000";
        ram[116] = "0b0001101";
        ram[117] = "0b0000101";
        ram[118] = "0b1101110";
        ram[119] = "0b0000110";
        ram[120] = "0b0000011";
        ram[121] = "0b0000110";
        ram[122] = "0b1100111";
        ram[123] = "0b0000001";
        ram[124] = "0b1110111";
        ram[125] = "0b1111110";
        ram[126] = "0b0001111";
        ram[127] = "0b0000010";
        ram[128] = "0b0000000";
        ram[129] = "0b0001011";
        ram[130] = "0b0000000";
        ram[131] = "0b0000101";
        ram[132] = "0b1111100";
        ram[133] = "0b1111110";
        ram[134] = "0b0000101";
        ram[135] = "0b0000010";
        ram[136] = "0b0001110";
        ram[137] = "0b0000010";
        ram[138] = "0b1100111";
        ram[139] = "0b0000000";
        ram[140] = "0b0000110";
        ram[141] = "0b1111010";
        ram[142] = "0b0011000";
        ram[143] = "0b0001001";
        ram[144] = "0b1101110";
        ram[145] = "0b0000011";
        ram[146] = "0b0010101";
        ram[147] = "0b0000000";
        ram[148] = "0b1111011";
        ram[149] = "0b0000111";
        ram[150] = "0b1111001";
        ram[151] = "0b1111110";
        ram[152] = "0b1111110";
        ram[153] = "0b0000110";
        ram[154] = "0b0001111";
        ram[155] = "0b1111011";
        ram[156] = "0b0000001";
        ram[157] = "0b1111001";
        ram[158] = "0b1101100";
        ram[159] = "0b1111101";
        ram[160] = "0b0000111";
        ram[161] = "0b1111110";
        ram[162] = "0b1111001";
        ram[163] = "0b0000010";
        ram[164] = "0b0010011";
        ram[165] = "0b0001000";
        ram[166] = "0b1110111";
        ram[167] = "0b1110111";
        ram[168] = "0b1111111";
        ram[169] = "0b0000000";
        ram[170] = "0b0000000";
        ram[171] = "0b0000000";
        ram[172] = "0b1111110";
        ram[173] = "0b0000000";
        ram[174] = "0b0000010";
        ram[175] = "0b0001010";
        ram[176] = "0b0001001";
        ram[177] = "0b0000000";
        ram[178] = "0b1111101";
        ram[179] = "0b0000100";
        ram[180] = "0b0010010";
        ram[181] = "0b0000000";
        ram[182] = "0b1110100";
        ram[183] = "0b1111100";
        ram[184] = "0b1110010";
        ram[185] = "0b0000011";
        ram[186] = "0b0010011";
        ram[187] = "0b0001000";
        ram[188] = "0b0000111";
        ram[189] = "0b1111011";
        ram[190] = "0b1111010";
        ram[191] = "0b1111100";
        ram[192] = "0b0000000";
        ram[193] = "0b0000010";
        ram[194] = "0b0001011";
        ram[195] = "0b0000101";
        ram[196] = "0b1111111";
        ram[197] = "0b0000111";
        ram[198] = "0b0000000";
        ram[199] = "0b1111111";
        ram[200] = "0b1111011";
        ram[201] = "0b1111101";
        ram[202] = "0b1110001";
        ram[203] = "0b1111010";
        ram[204] = "0b0000000";
        ram[205] = "0b0000000";
        ram[206] = "0b0000000";
        ram[207] = "0b0000000";
        ram[208] = "0b0000001";
        ram[209] = "0b0000111";
        ram[210] = "0b1111100";
        ram[211] = "0b0000100";
        ram[212] = "0b1111011";
        ram[213] = "0b1111001";
        ram[214] = "0b0011000";
        ram[215] = "0b1111100";
        ram[216] = "0b1110101";
        ram[217] = "0b1111110";
        ram[218] = "0b0010110";
        ram[219] = "0b0000010";
        ram[220] = "0b1111011";
        ram[221] = "0b1111011";
        ram[222] = "0b0001011";
        ram[223] = "0b0001100";
        ram[224] = "0b0001010";
        ram[225] = "0b0000001";
        ram[226] = "0b1011110";
        ram[227] = "0b1111101";
        ram[228] = "0b0000011";
        ram[229] = "0b0000100";
        ram[230] = "0b0000111";
        ram[231] = "0b1111100";
        ram[232] = "0b1110100";
        ram[233] = "0b0000000";
        ram[234] = "0b0010011";
        ram[235] = "0b0000001";
        ram[236] = "0b1110010";
        ram[237] = "0b1111100";
        ram[238] = "0b0000110";
        ram[239] = "0b0000011";
        ram[240] = "0b1111010";
        ram[241] = "0b0000101";
        ram[242] = "0b0000111";
        ram[243] = "0b0001010";
        ram[244] = "0b1111110";
        ram[245] = "0b1111110";
        ram[246] = "0b1111110";
        ram[247] = "0b1111111";
        ram[248] = "0b0000001";
        ram[249] = "0b0001000";
        ram[250] = "0b0000011";
        ram[251] = "0b0000010";
        ram[252] = "0b1111101";
        ram[253] = "0b1111101";
        ram[254] = "0b1110110";
        ram[255] = "0b1111100";


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


SC_MODULE(mlp_accel_8b32_weights_l2_8b32_6) {


static const unsigned DataWidth = 7;
static const unsigned AddressRange = 256;
static const unsigned AddressWidth = 8;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_8b32_weights_l2_8b32_6_ram* meminst;


SC_CTOR(mlp_accel_8b32_weights_l2_8b32_6) {
meminst = new mlp_accel_8b32_weights_l2_8b32_6_ram("mlp_accel_8b32_weights_l2_8b32_6_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_8b32_weights_l2_8b32_6() {
    delete meminst;
}


};//endmodule
#endif
