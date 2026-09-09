// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_12_H__
#define __mlp_accel_weights_l3_12_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_12_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_12_ram) {
        ram[0] = "0b10111111110011";
        ram[1] = "0b00000000000000";
        ram[2] = "0b00101110110011";
        ram[3] = "0b00101010101111";
        ram[4] = "0b11100111001111";
        ram[5] = "0b00000000000000";
        ram[6] = "0b11011000001010";
        ram[7] = "0b00011111111010";
        ram[8] = "0b00110000101100";
        ram[9] = "0b00000000000000";
        ram[10] = "0b11111111101100";
        ram[11] = "0b00110100001011";
        ram[12] = "0b00011000000001";
        ram[13] = "0b00000000000000";
        ram[14] = "0b11001001110011";
        ram[15] = "0b11111000010111";
        ram[16] = "0b00101111001101";
        ram[17] = "0b00000000000000";
        ram[18] = "0b10011011111010";
        ram[19] = "0b11000101101011";
        ram[20] = "0b10100001001010";
        ram[21] = "0b00000000000001";
        ram[22] = "0b00111010000011";
        ram[23] = "0b00100111101101";
        ram[24] = "0b10101011010110";
        ram[25] = "0b00000000000000";
        ram[26] = "0b00000001101101";
        ram[27] = "0b00010000010011";
        ram[28] = "0b00110011111110";
        ram[29] = "0b00000000000000";
        ram[30] = "0b00000111010100";
        ram[31] = "0b10100110000100";
        ram[32] = "0b00111111011101";
        ram[33] = "0b00000000000001";
        ram[34] = "0b11100010011010";
        ram[35] = "0b11010011100111";
        ram[36] = "0b11000110100000";
        ram[37] = "0b00000000000000";
        ram[38] = "0b00010110010000";
        ram[39] = "0b11000011111011";


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


SC_MODULE(mlp_accel_weights_l3_12) {


static const unsigned DataWidth = 14;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_12_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_12) {
meminst = new mlp_accel_weights_l3_12_ram("mlp_accel_weights_l3_12_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_12() {
    delete meminst;
}


};//endmodule
#endif
