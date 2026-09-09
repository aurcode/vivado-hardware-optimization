// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_1_H__
#define __mlp_accel_weights_l3_1_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_1_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_1_ram) {
        ram[0] = "0b111100000110001";
        ram[1] = "0b000001011000000";
        ram[2] = "0b000101011001101";
        ram[3] = "0b000101010110101";
        ram[4] = "0b110101111011000";
        ram[5] = "0b111001110011011";
        ram[6] = "0b000100000001111";
        ram[7] = "0b111110111011011";
        ram[8] = "0b000011000101100";
        ram[9] = "0b000000001011100";
        ram[10] = "0b111100001101101";
        ram[11] = "0b111111110110011";
        ram[12] = "0b000111110110010";
        ram[13] = "0b000111010000101";
        ram[14] = "0b000101101101000";
        ram[15] = "0b000101101010110";
        ram[16] = "0b000100110111101";
        ram[17] = "0b000100110111001";
        ram[18] = "0b110110100010101";
        ram[19] = "0b110101011010000";
        ram[20] = "0b111000111111011";
        ram[21] = "0b111110000100110";
        ram[22] = "0b000000010110100";
        ram[23] = "0b000000011101001";
        ram[24] = "0b101111101101111";
        ram[25] = "0b110111001010101";
        ram[26] = "0b111011011011110";
        ram[27] = "0b111100110000011";
        ram[28] = "0b000000000110111";
        ram[29] = "0b110100000111111";
        ram[30] = "0b111111000001011";
        ram[31] = "0b110001100000111";
        ram[32] = "0b000011001110111";
        ram[33] = "0b000100000011100";
        ram[34] = "0b000011111011101";
        ram[35] = "0b000100010010001";
        ram[36] = "0b000100110101001";
        ram[37] = "0b111101001000010";
        ram[38] = "0b111011101010010";
        ram[39] = "0b111011101110001";


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


SC_MODULE(mlp_accel_weights_l3_1) {


static const unsigned DataWidth = 15;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_1_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_1) {
meminst = new mlp_accel_weights_l3_1_ram("mlp_accel_weights_l3_1_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_1() {
    delete meminst;
}


};//endmodule
#endif
