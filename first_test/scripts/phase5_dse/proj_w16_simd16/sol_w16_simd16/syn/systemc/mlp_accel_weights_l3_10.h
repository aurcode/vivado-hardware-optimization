// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_10_H__
#define __mlp_accel_weights_l3_10_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_10_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_10_ram) {
        ram[0] = "0b00011010000110";
        ram[1] = "0b10110100010001";
        ram[2] = "0b00000111001000";
        ram[3] = "0b10110101001110";
        ram[4] = "0b00110000000011";
        ram[5] = "0b01000111010111";
        ram[6] = "0b11111110011111";
        ram[7] = "0b00111101000011";
        ram[8] = "0b11100000110010";
        ram[9] = "0b11100001101101";
        ram[10] = "0b00001001011100";
        ram[11] = "0b00011110100101";
        ram[12] = "0b10110000111100";
        ram[13] = "0b11001000101010";
        ram[14] = "0b11111010110010";
        ram[15] = "0b00011010111111";
        ram[16] = "0b11011000010110";
        ram[17] = "0b00011110000011";
        ram[18] = "0b11110111001101";
        ram[19] = "0b11001111101100";
        ram[20] = "0b11100000110010";
        ram[21] = "0b00101110100000";
        ram[22] = "0b00000111010110";
        ram[23] = "0b00011011100010";
        ram[24] = "0b10100111100110";
        ram[25] = "0b00101000100101";
        ram[26] = "0b11111100000000";
        ram[27] = "0b10110010101001";
        ram[28] = "0b00101001111011";
        ram[29] = "0b00100100110100";
        ram[30] = "0b11111101101000";
        ram[31] = "0b00100110000101";
        ram[32] = "0b11111111111011";
        ram[33] = "0b11100000111100";
        ram[34] = "0b11111100011101";
        ram[35] = "0b10111001111010";
        ram[36] = "0b00110110111001";
        ram[37] = "0b10000010101101";
        ram[38] = "0b11111110011000";
        ram[39] = "0b00000011001111";


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


SC_MODULE(mlp_accel_weights_l3_10) {


static const unsigned DataWidth = 14;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_10_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_10) {
meminst = new mlp_accel_weights_l3_10_ram("mlp_accel_weights_l3_10_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_10() {
    delete meminst;
}


};//endmodule
#endif
