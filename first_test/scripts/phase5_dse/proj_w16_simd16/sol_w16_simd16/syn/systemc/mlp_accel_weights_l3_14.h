// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_14_H__
#define __mlp_accel_weights_l3_14_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_14_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_14_ram) {
        ram[0] = "0b10101100011111";
        ram[1] = "0b10101011110011";
        ram[2] = "0b11100111100101";
        ram[3] = "0b10010011110100";
        ram[4] = "0b10100011101111";
        ram[5] = "0b11010111000100";
        ram[6] = "0b01001001110001";
        ram[7] = "0b11100000011100";
        ram[8] = "0b10110011011111";
        ram[9] = "0b11111011000110";
        ram[10] = "0b00001110111011";
        ram[11] = "0b00001110001011";
        ram[12] = "0b00110011001100";
        ram[13] = "0b10111111101100";
        ram[14] = "0b00010110111110";
        ram[15] = "0b00011100001100";
        ram[16] = "0b00100001101100";
        ram[17] = "0b00100100110110";
        ram[18] = "0b11000011110001";
        ram[19] = "0b00100100101001";
        ram[20] = "0b00100001101111";
        ram[21] = "0b00110000001110";
        ram[22] = "0b10110100101100";
        ram[23] = "0b00011100000111";
        ram[24] = "0b11010010100000";
        ram[25] = "0b00100100111101";
        ram[26] = "0b10110010111101";
        ram[27] = "0b10111111001100";
        ram[28] = "0b11111100110001";
        ram[29] = "0b10010011010110";
        ram[30] = "0b00100110010001";
        ram[31] = "0b00000000100000";
        ram[32] = "0b00101000000001";
        ram[33] = "0b00110110011011";
        ram[34] = "0b11000010110011";
        ram[35] = "0b11001111100110";
        ram[36] = "0b00010111000111";
        ram[37] = "0b00110010001100";
        ram[38] = "0b00010010000010";
        ram[39] = "0b00100010111100";


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


SC_MODULE(mlp_accel_weights_l3_14) {


static const unsigned DataWidth = 14;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_14_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_14) {
meminst = new mlp_accel_weights_l3_14_ram("mlp_accel_weights_l3_14_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_14() {
    delete meminst;
}


};//endmodule
#endif
