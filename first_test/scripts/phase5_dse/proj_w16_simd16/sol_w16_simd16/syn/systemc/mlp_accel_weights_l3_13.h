// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_13_H__
#define __mlp_accel_weights_l3_13_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_13_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_13_ram) {
        ram[0] = "0b11111010101011";
        ram[1] = "0b00001100101001";
        ram[2] = "0b00010110100100";
        ram[3] = "0b00001001101000";
        ram[4] = "0b11101011010101";
        ram[5] = "0b11000011011110";
        ram[6] = "0b10110011101101";
        ram[7] = "0b11110011001110";
        ram[8] = "0b00010100010101";
        ram[9] = "0b10111011110111";
        ram[10] = "0b11000000010100";
        ram[11] = "0b00000000111001";
        ram[12] = "0b11101000011111";
        ram[13] = "0b11010100110010";
        ram[14] = "0b11011100101011";
        ram[15] = "0b00000101110100";
        ram[16] = "0b00001100001010";
        ram[17] = "0b00001100010011";
        ram[18] = "0b00001101111011";
        ram[19] = "0b11111010110100";
        ram[20] = "0b10011111010001";
        ram[21] = "0b11111100001111";
        ram[22] = "0b00110010011110";
        ram[23] = "0b11111101110101";
        ram[24] = "0b00110110001100";
        ram[25] = "0b00111111000000";
        ram[26] = "0b10110100101100";
        ram[27] = "0b00000110110001";
        ram[28] = "0b00010110101111";
        ram[29] = "0b10111000100010";
        ram[30] = "0b00010111110101";
        ram[31] = "0b11111000111000";
        ram[32] = "0b00001000001010";
        ram[33] = "0b00100110110001";
        ram[34] = "0b00101001010010";
        ram[35] = "0b00000000110101";
        ram[36] = "0b11110010000110";
        ram[37] = "0b11111011100011";
        ram[38] = "0b00010001000100";
        ram[39] = "0b11111100101110";


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


SC_MODULE(mlp_accel_weights_l3_13) {


static const unsigned DataWidth = 14;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_13_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_13) {
meminst = new mlp_accel_weights_l3_13_ram("mlp_accel_weights_l3_13_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_13() {
    delete meminst;
}


};//endmodule
#endif
