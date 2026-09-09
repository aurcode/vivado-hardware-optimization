// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_3_H__
#define __mlp_accel_weights_l3_3_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_3_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_3_ram) {
        ram[0] = "0b11000001001001";
        ram[1] = "0b00000001101000";
        ram[2] = "0b10011111011010";
        ram[3] = "0b11111111110111";
        ram[4] = "0b10010100001011";
        ram[5] = "0b00011111001111";
        ram[6] = "0b01000001011010";
        ram[7] = "0b00000000000000";
        ram[8] = "0b11001101000110";
        ram[9] = "0b10000001100111";
        ram[10] = "0b01001100100110";
        ram[11] = "0b11111111111111";
        ram[12] = "0b01001100100010";
        ram[13] = "0b10100101110101";
        ram[14] = "0b11011011110110";
        ram[15] = "0b11111111111010";
        ram[16] = "0b11001110011110";
        ram[17] = "0b00111100010011";
        ram[18] = "0b00100101000100";
        ram[19] = "0b11111111111010";
        ram[20] = "0b10101010101100";
        ram[21] = "0b00100000100010";
        ram[22] = "0b10000101110010";
        ram[23] = "0b11111111111000";
        ram[24] = "0b00101100000101";
        ram[25] = "0b00000111100100";
        ram[26] = "0b00110001110101";
        ram[27] = "0b00000000000000";
        ram[28] = "0b00100101100100";
        ram[29] = "0b11101010100100";
        ram[30] = "0b01000101101011";
        ram[31] = "0b11111111111111";
        ram[32] = "0b11100111101010";
        ram[33] = "0b11110011000111";
        ram[34] = "0b11011110000100";
        ram[35] = "0b11111111111010";
        ram[36] = "0b01001111001010";
        ram[37] = "0b00010011011010";
        ram[38] = "0b10111011011001";
        ram[39] = "0b00000000101011";


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


SC_MODULE(mlp_accel_weights_l3_3) {


static const unsigned DataWidth = 14;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_3_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_3) {
meminst = new mlp_accel_weights_l3_3_ram("mlp_accel_weights_l3_3_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_3() {
    delete meminst;
}


};//endmodule
#endif
