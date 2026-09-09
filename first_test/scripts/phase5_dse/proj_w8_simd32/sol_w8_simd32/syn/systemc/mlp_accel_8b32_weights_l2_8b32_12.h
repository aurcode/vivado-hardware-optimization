// ==============================================================
// File generated on Wed Sep 02 16:32:48 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_8b32_weights_l2_8b32_12_H__
#define __mlp_accel_8b32_weights_l2_8b32_12_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_8b32_weights_l2_8b32_12_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 6;
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


   SC_CTOR(mlp_accel_8b32_weights_l2_8b32_12_ram) {
        ram[0] = "0b001000";
        ram[1] = "0b111111";
        ram[2] = "0b001000";
        ram[3] = "0b111110";
        ram[4] = "0b001011";
        ram[5] = "0b000001";
        ram[6] = "0b000010";
        ram[7] = "0b100110";
        ram[8] = "0b000001";
        ram[9] = "0b111111";
        ram[10] = "0b000000";
        ram[11] = "0b011011";
        ram[12] = "0b110110";
        ram[13] = "0b000000";
        ram[14] = "0b001000";
        ram[15] = "0b111000";
        ram[16] = "0b111111";
        ram[17] = "0b000101";
        ram[18] = "0b000011";
        ram[19] = "0b100111";
        ram[20] = "0b000110";
        ram[21] = "0b000100";
        ram[22] = "0b111111";
        ram[23] = "0b000000";
        ram[24] = "0b110111";
        ram[25] = "0b000001";
        ram[26] = "0b000001";
        ram[27] = "0b110001";
        ram[28] = "0b000001";
        ram[29] = "0b000101";
        ram[30] = "0b000000";
        ram[31] = "0b111010";
        ram[32] = "0b111101";
        ram[33] = "0b000011";
        ram[34] = "0b111001";
        ram[35] = "0b001001";
        ram[36] = "0b000101";
        ram[37] = "0b000000";
        ram[38] = "0b001000";
        ram[39] = "0b001100";
        ram[40] = "0b110111";
        ram[41] = "0b000001";
        ram[42] = "0b000110";
        ram[43] = "0b011011";
        ram[44] = "0b110101";
        ram[45] = "0b111110";
        ram[46] = "0b111101";
        ram[47] = "0b001000";
        ram[48] = "0b111110";
        ram[49] = "0b000101";
        ram[50] = "0b000011";
        ram[51] = "0b101101";
        ram[52] = "0b000111";
        ram[53] = "0b000111";
        ram[54] = "0b000111";
        ram[55] = "0b110111";
        ram[56] = "0b001101";
        ram[57] = "0b001000";
        ram[58] = "0b000101";
        ram[59] = "0b101110";
        ram[60] = "0b111100";
        ram[61] = "0b000111";
        ram[62] = "0b000011";
        ram[63] = "0b111000";
        ram[64] = "0b000000";
        ram[65] = "0b000000";
        ram[66] = "0b000010";
        ram[67] = "0b111101";
        ram[68] = "0b001110";
        ram[69] = "0b000101";
        ram[70] = "0b000011";
        ram[71] = "0b100110";
        ram[72] = "0b000001";
        ram[73] = "0b000101";
        ram[74] = "0b000001";
        ram[75] = "0b010010";
        ram[76] = "0b000011";
        ram[77] = "0b000100";
        ram[78] = "0b000101";
        ram[79] = "0b011111";
        ram[80] = "0b000000";
        ram[81] = "0b111101";
        ram[82] = "0b111101";
        ram[83] = "0b111101";
        ram[84] = "0b111001";
        ram[85] = "0b000101";
        ram[86] = "0b000101";
        ram[87] = "0b001011";
        ram[88] = "0b111011";
        ram[89] = "0b000011";
        ram[90] = "0b111110";
        ram[91] = "0b001010";
        ram[92] = "0b000000";
        ram[93] = "0b000000";
        ram[94] = "0b000000";
        ram[95] = "0b000000";
        ram[96] = "0b111111";
        ram[97] = "0b000100";
        ram[98] = "0b000010";
        ram[99] = "0b011000";
        ram[100] = "0b001011";
        ram[101] = "0b000110";
        ram[102] = "0b111111";
        ram[103] = "0b110000";
        ram[104] = "0b111110";
        ram[105] = "0b000100";
        ram[106] = "0b111011";
        ram[107] = "0b010111";
        ram[108] = "0b111101";
        ram[109] = "0b000000";
        ram[110] = "0b111111";
        ram[111] = "0b001001";
        ram[112] = "0b000000";
        ram[113] = "0b000000";
        ram[114] = "0b000000";
        ram[115] = "0b000000";
        ram[116] = "0b001110";
        ram[117] = "0b000000";
        ram[118] = "0b000011";
        ram[119] = "0b111000";
        ram[120] = "0b111110";
        ram[121] = "0b000000";
        ram[122] = "0b000001";
        ram[123] = "0b111001";
        ram[124] = "0b000101";
        ram[125] = "0b000000";
        ram[126] = "0b111011";
        ram[127] = "0b001011";
        ram[128] = "0b001100";
        ram[129] = "0b000011";
        ram[130] = "0b111011";
        ram[131] = "0b000000";
        ram[132] = "0b000010";
        ram[133] = "0b111111";
        ram[134] = "0b000110";
        ram[135] = "0b000100";
        ram[136] = "0b000001";
        ram[137] = "0b000101";
        ram[138] = "0b000100";
        ram[139] = "0b001111";
        ram[140] = "0b110100";
        ram[141] = "0b111101";
        ram[142] = "0b111010";
        ram[143] = "0b001110";
        ram[144] = "0b000010";
        ram[145] = "0b000101";
        ram[146] = "0b001001";
        ram[147] = "0b101000";
        ram[148] = "0b010011";
        ram[149] = "0b000011";
        ram[150] = "0b000101";
        ram[151] = "0b111000";
        ram[152] = "0b000001";
        ram[153] = "0b000111";
        ram[154] = "0b000101";
        ram[155] = "0b111000";
        ram[156] = "0b111100";
        ram[157] = "0b000110";
        ram[158] = "0b000110";
        ram[159] = "0b011111";
        ram[160] = "0b111111";
        ram[161] = "0b000101";
        ram[162] = "0b000111";
        ram[163] = "0b110011";
        ram[164] = "0b001100";
        ram[165] = "0b111101";
        ram[166] = "0b111111";
        ram[167] = "0b111111";
        ram[168] = "0b000001";
        ram[169] = "0b000000";
        ram[170] = "0b111111";
        ram[171] = "0b000000";
        ram[172] = "0b001000";
        ram[173] = "0b111101";
        ram[174] = "0b000111";
        ram[175] = "0b001000";
        ram[176] = "0b111100";
        ram[177] = "0b000101";
        ram[178] = "0b000000";
        ram[179] = "0b000101";
        ram[180] = "0b000001";
        ram[181] = "0b000111";
        ram[182] = "0b000011";
        ram[183] = "0b111001";
        ram[184] = "0b110010";
        ram[185] = "0b111100";
        ram[186] = "0b111110";
        ram[187] = "0b010000";
        ram[188] = "0b111111";
        ram[189] = "0b111110";
        ram[190] = "0b000011";
        ram[191] = "0b111111";
        ram[192] = "0b000101";
        ram[193] = "0b000100";
        ram[194] = "0b000001";
        ram[195] = "0b101001";
        ram[196] = "0b000011";
        ram[197] = "0b000100";
        ram[198] = "0b111101";
        ram[199] = "0b100000";
        ram[200] = "0b001001";
        ram[201] = "0b000011";
        ram[202] = "0b001010";
        ram[203] = "0b001011";
        ram[204] = "0b000000";
        ram[205] = "0b000000";
        ram[206] = "0b000000";
        ram[207] = "0b000000";
        ram[208] = "0b001001";
        ram[209] = "0b000001";
        ram[210] = "0b000110";
        ram[211] = "0b110100";
        ram[212] = "0b000001";
        ram[213] = "0b111000";
        ram[214] = "0b000111";
        ram[215] = "0b110101";
        ram[216] = "0b111010";
        ram[217] = "0b000010";
        ram[218] = "0b000011";
        ram[219] = "0b110111";
        ram[220] = "0b110101";
        ram[221] = "0b111100";
        ram[222] = "0b001000";
        ram[223] = "0b111100";
        ram[224] = "0b000101";
        ram[225] = "0b111101";
        ram[226] = "0b000011";
        ram[227] = "0b010100";
        ram[228] = "0b111011";
        ram[229] = "0b000011";
        ram[230] = "0b111000";
        ram[231] = "0b111101";
        ram[232] = "0b111011";
        ram[233] = "0b111110";
        ram[234] = "0b111010";
        ram[235] = "0b001000";
        ram[236] = "0b110011";
        ram[237] = "0b111101";
        ram[238] = "0b000000";
        ram[239] = "0b001000";
        ram[240] = "0b111111";
        ram[241] = "0b111110";
        ram[242] = "0b000000";
        ram[243] = "0b000111";
        ram[244] = "0b000000";
        ram[245] = "0b000000";
        ram[246] = "0b000001";
        ram[247] = "0b111111";
        ram[248] = "0b000101";
        ram[249] = "0b000011";
        ram[250] = "0b000011";
        ram[251] = "0b111000";
        ram[252] = "0b000011";
        ram[253] = "0b000101";
        ram[254] = "0b000101";
        ram[255] = "0b110010";


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


SC_MODULE(mlp_accel_8b32_weights_l2_8b32_12) {


static const unsigned DataWidth = 6;
static const unsigned AddressRange = 256;
static const unsigned AddressWidth = 8;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_8b32_weights_l2_8b32_12_ram* meminst;


SC_CTOR(mlp_accel_8b32_weights_l2_8b32_12) {
meminst = new mlp_accel_8b32_weights_l2_8b32_12_ram("mlp_accel_8b32_weights_l2_8b32_12_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_8b32_weights_l2_8b32_12() {
    delete meminst;
}


};//endmodule
#endif
