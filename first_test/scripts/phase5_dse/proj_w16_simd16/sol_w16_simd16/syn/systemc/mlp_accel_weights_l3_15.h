// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_15_H__
#define __mlp_accel_weights_l3_15_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_15_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_15_ram) {
        ram[0] = "0b11010110101001";
        ram[1] = "0b10100111000100";
        ram[2] = "0b00010100001100";
        ram[3] = "0b01001000101001";
        ram[4] = "0b10010011101101";
        ram[5] = "0b01010001100101";
        ram[6] = "0b10111101111001";
        ram[7] = "0b11100110001101";
        ram[8] = "0b11111001010100";
        ram[9] = "0b11101001100011";
        ram[10] = "0b11100000100110";
        ram[11] = "0b10111101001100";
        ram[12] = "0b11101011110001";
        ram[13] = "0b00111101100111";
        ram[14] = "0b11001111111010";
        ram[15] = "0b00100010111000";
        ram[16] = "0b11101000010101";
        ram[17] = "0b00001001010100";
        ram[18] = "0b00000010101010";
        ram[19] = "0b10010010100101";
        ram[20] = "0b00110000010100";
        ram[21] = "0b00100000100100";
        ram[22] = "0b11011101011001";
        ram[23] = "0b11000100010000";
        ram[24] = "0b11000011010100";
        ram[25] = "0b11000000111010";
        ram[26] = "0b11001001111011";
        ram[27] = "0b00011010000010";
        ram[28] = "0b00100001000011";
        ram[29] = "0b00101011111100";
        ram[30] = "0b00110000010111";
        ram[31] = "0b11100111100110";
        ram[32] = "0b00100110001100";
        ram[33] = "0b10000100100011";
        ram[34] = "0b11101011010111";
        ram[35] = "0b11111001110100";
        ram[36] = "0b00110001011100";
        ram[37] = "0b00001011110110";
        ram[38] = "0b01000001000100";
        ram[39] = "0b11110111011111";


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


SC_MODULE(mlp_accel_weights_l3_15) {


static const unsigned DataWidth = 14;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_15_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_15) {
meminst = new mlp_accel_weights_l3_15_ram("mlp_accel_weights_l3_15_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_15() {
    delete meminst;
}


};//endmodule
#endif
