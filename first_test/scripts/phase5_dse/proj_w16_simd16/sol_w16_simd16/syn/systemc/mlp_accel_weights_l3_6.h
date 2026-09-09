// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_6_H__
#define __mlp_accel_weights_l3_6_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_6_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_6_ram) {
        ram[0] = "0b111100101100000";
        ram[1] = "0b001011001010110";
        ram[2] = "0b000111011101100";
        ram[3] = "0b110111100101111";
        ram[4] = "0b111111111100110";
        ram[5] = "0b001000011000001";
        ram[6] = "0b000000000111011";
        ram[7] = "0b000000001110111";
        ram[8] = "0b000110101100001";
        ram[9] = "0b001000111010000";
        ram[10] = "0b001001001101011";
        ram[11] = "0b111111010100100";
        ram[12] = "0b111101111111100";
        ram[13] = "0b111000110000010";
        ram[14] = "0b111100111101011";
        ram[15] = "0b000111101000001";
        ram[16] = "0b110010110011000";
        ram[17] = "0b000011101010101";
        ram[18] = "0b000100100011001";
        ram[19] = "0b110101100110010";
        ram[20] = "0b111101111011111";
        ram[21] = "0b110000101110001";
        ram[22] = "0b110111100011110";
        ram[23] = "0b000010101000010";
        ram[24] = "0b000000011110000";
        ram[25] = "0b111010110001100";
        ram[26] = "0b110110011011101";
        ram[27] = "0b101110010110100";
        ram[28] = "0b111000110000101";
        ram[29] = "0b000011000010011";
        ram[30] = "0b000100110011001";
        ram[31] = "0b000110101011101";
        ram[32] = "0b000100111101011";
        ram[33] = "0b110110000011101";
        ram[34] = "0b111101111011101";
        ram[35] = "0b111101110110110";
        ram[36] = "0b111010011011000";
        ram[37] = "0b000010100011100";
        ram[38] = "0b110110111011101";
        ram[39] = "0b000001001111100";


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


SC_MODULE(mlp_accel_weights_l3_6) {


static const unsigned DataWidth = 15;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_6_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_6) {
meminst = new mlp_accel_weights_l3_6_ram("mlp_accel_weights_l3_6_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_6() {
    delete meminst;
}


};//endmodule
#endif
