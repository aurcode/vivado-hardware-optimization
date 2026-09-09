// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_0_H__
#define __mlp_accel_weights_l3_0_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_0_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 15;
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


   SC_CTOR(mlp_accel_weights_l3_0_ram) {
        ram[0] = "0b000010001001111";
        ram[1] = "0b111111001101100";
        ram[2] = "0b111010100011010";
        ram[3] = "0b111000001001110";
        ram[4] = "0b111110111100110";
        ram[5] = "0b111111111010101";
        ram[6] = "0b000010011101111";
        ram[7] = "0b110111100111111";
        ram[8] = "0b111000001101110";
        ram[9] = "0b000001001111010";
        ram[10] = "0b110001110100101";
        ram[11] = "0b000101001001111";
        ram[12] = "0b111000111111101";
        ram[13] = "0b111110111101010";
        ram[14] = "0b000110110110100";
        ram[15] = "0b000001000011000";
        ram[16] = "0b000110011010111";
        ram[17] = "0b000000011101011";
        ram[18] = "0b111010000100011";
        ram[19] = "0b101111010111000";
        ram[20] = "0b111010110110011";
        ram[21] = "0b111111101010011";
        ram[22] = "0b001001100000111";
        ram[23] = "0b000110011101011";
        ram[24] = "0b000101110000110";
        ram[25] = "0b000001010001001";
        ram[26] = "0b000101001100011";
        ram[27] = "0b111111100000010";
        ram[28] = "0b110100100101000";
        ram[29] = "0b111111010100111";
        ram[30] = "0b000000011100100";
        ram[31] = "0b111101011010100";
        ram[32] = "0b000011101000010";
        ram[33] = "0b111101110110010";
        ram[34] = "0b111010011101110";
        ram[35] = "0b000011111001111";
        ram[36] = "0b001001000101100";
        ram[37] = "0b000000101111101";
        ram[38] = "0b111111101000111";
        ram[39] = "0b111001010000001";


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


SC_MODULE(mlp_accel_weights_l3_0) {


static const unsigned DataWidth = 15;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_0_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_0) {
meminst = new mlp_accel_weights_l3_0_ram("mlp_accel_weights_l3_0_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_0() {
    delete meminst;
}


};//endmodule
#endif
