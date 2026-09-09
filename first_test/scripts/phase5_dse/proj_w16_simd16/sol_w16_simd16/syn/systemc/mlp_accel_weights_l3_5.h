// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_5_H__
#define __mlp_accel_weights_l3_5_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_5_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_5_ram) {
        ram[0] = "0b00011001101100";
        ram[1] = "0b00001111001101";
        ram[2] = "0b00100110100100";
        ram[3] = "0b00100111001101";
        ram[4] = "0b10101110111001";
        ram[5] = "0b00101100101001";
        ram[6] = "0b10101100100100";
        ram[7] = "0b11010111011011";
        ram[8] = "0b00011110100011";
        ram[9] = "0b10101000011101";
        ram[10] = "0b10110101000010";
        ram[11] = "0b00110010110100";
        ram[12] = "0b11101100001001";
        ram[13] = "0b00000111111110";
        ram[14] = "0b00111110010011";
        ram[15] = "0b00010111110110";
        ram[16] = "0b11111011100000";
        ram[17] = "0b00111111000101";
        ram[18] = "0b11001100010100";
        ram[19] = "0b10001100000101";
        ram[20] = "0b01001001000010";
        ram[21] = "0b10101001101011";
        ram[22] = "0b00000110100111";
        ram[23] = "0b11101101011101";
        ram[24] = "0b00001101111010";
        ram[25] = "0b11000101011110";
        ram[26] = "0b00111111110011";
        ram[27] = "0b11011111000110";
        ram[28] = "0b11010000101001";
        ram[29] = "0b11100110100000";
        ram[30] = "0b11101011111010";
        ram[31] = "0b01001010010101";
        ram[32] = "0b11001110100000";
        ram[33] = "0b00101001011000";
        ram[34] = "0b00010001110000";
        ram[35] = "0b11011100000110";
        ram[36] = "0b11101111100000";
        ram[37] = "0b11110111011010";
        ram[38] = "0b11101000110110";
        ram[39] = "0b11100100101100";


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


SC_MODULE(mlp_accel_weights_l3_5) {


static const unsigned DataWidth = 14;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_5_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_5) {
meminst = new mlp_accel_weights_l3_5_ram("mlp_accel_weights_l3_5_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_5() {
    delete meminst;
}


};//endmodule
#endif
