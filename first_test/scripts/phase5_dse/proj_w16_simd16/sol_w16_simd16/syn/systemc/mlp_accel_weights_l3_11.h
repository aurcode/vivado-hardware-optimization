// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_11_H__
#define __mlp_accel_weights_l3_11_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_11_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 14;
  static const unsigned AddressRange = 40;
  static const unsigned AddressWidth = 6;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(mlp_accel_weights_l3_11_ram) {
        ram[0] = "0b10111111001010";
        ram[1] = "0b11001000101010";
        ram[2] = "0b00101101111000";
        ram[3] = "0b11101011110111";
        ram[4] = "0b00110000100110";
        ram[5] = "0b00011011110110";
        ram[6] = "0b11100010001101";
        ram[7] = "0b00100101110110";
        ram[8] = "0b00000011101111";
        ram[9] = "0b11001100111100";
        ram[10] = "0b00001110011110";
        ram[11] = "0b11111101110100";
        ram[12] = "0b11110011001011";
        ram[13] = "0b10110111101111";
        ram[14] = "0b11001100111110";
        ram[15] = "0b00110001111001";
        ram[16] = "0b10011100110010";
        ram[17] = "0b10111001101000";
        ram[18] = "0b00001000101110";
        ram[19] = "0b11111010100001";
        ram[20] = "0b00101000101011";
        ram[21] = "0b11101001101110";
        ram[22] = "0b11101100111111";
        ram[23] = "0b10110101010010";
        ram[24] = "0b11100000110101";
        ram[25] = "0b01000110100011";
        ram[26] = "0b01010000010010";
        ram[27] = "0b10011101000111";
        ram[28] = "0b10111100010011";
        ram[29] = "0b11100010010111";
        ram[30] = "0b10011001111011";
        ram[31] = "0b00101010001001";
        ram[32] = "0b00100101011000";
        ram[33] = "0b01000101101111";
        ram[34] = "0b10111110101001";
        ram[35] = "0b11101100010101";
        ram[36] = "0b00000110001000";
        ram[37] = "0b00010001011011";
        ram[38] = "0b00000110000100";
        ram[39] = "0b00101100101100";


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


SC_MODULE(mlp_accel_weights_l3_11) {


static const unsigned DataWidth = 14;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_11_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_11) {
meminst = new mlp_accel_weights_l3_11_ram("mlp_accel_weights_l3_11_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_11() {
    delete meminst;
}


};//endmodule
#endif
