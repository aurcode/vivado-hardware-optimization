// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_7_H__
#define __mlp_accel_weights_l3_7_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_7_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_7_ram) {
        ram[0] = "0b111010101001000";
        ram[1] = "0b111111111111000";
        ram[2] = "0b000101101110111";
        ram[3] = "0b111011011111110";
        ram[4] = "0b000010100011111";
        ram[5] = "0b000000000000000";
        ram[6] = "0b000110010011100";
        ram[7] = "0b000100011111011";
        ram[8] = "0b111111100011111";
        ram[9] = "0b000000001100111";
        ram[10] = "0b000011011100001";
        ram[11] = "0b000110111000101";
        ram[12] = "0b111101001001001";
        ram[13] = "0b000000000000101";
        ram[14] = "0b110101101010111";
        ram[15] = "0b111010010010010";
        ram[16] = "0b000110001010101";
        ram[17] = "0b000000000100101";
        ram[18] = "0b000111011111101";
        ram[19] = "0b111010111100111";
        ram[20] = "0b110101011101011";
        ram[21] = "0b111111111111111";
        ram[22] = "0b111001100010000";
        ram[23] = "0b000000101100010";
        ram[24] = "0b000000011111101";
        ram[25] = "0b000000000000000";
        ram[26] = "0b111101001010110";
        ram[27] = "0b000010011100000";
        ram[28] = "0b110111100000111";
        ram[29] = "0b000000000000101";
        ram[30] = "0b111011000011011";
        ram[31] = "0b000000111001000";
        ram[32] = "0b001000101100111";
        ram[33] = "0b111111111111001";
        ram[34] = "0b110001000011000";
        ram[35] = "0b001000000000111";
        ram[36] = "0b111110100000101";
        ram[37] = "0b111111101001111";
        ram[38] = "0b000100101010000";
        ram[39] = "0b101110101110101";


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


SC_MODULE(mlp_accel_weights_l3_7) {


static const unsigned DataWidth = 15;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_7_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_7) {
meminst = new mlp_accel_weights_l3_7_ram("mlp_accel_weights_l3_7_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_7() {
    delete meminst;
}


};//endmodule
#endif
