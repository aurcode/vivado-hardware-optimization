// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_8_H__
#define __mlp_accel_weights_l3_8_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_8_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_8_ram) {
        ram[0] = "0b000000100000100";
        ram[1] = "0b110111100110111";
        ram[2] = "0b000000011100000";
        ram[3] = "0b000011001101000";
        ram[4] = "0b000110101110100";
        ram[5] = "0b001000111010010";
        ram[6] = "0b110110110001100";
        ram[7] = "0b111000110111001";
        ram[8] = "0b000000101001101";
        ram[9] = "0b101101010110000";
        ram[10] = "0b000011011100011";
        ram[11] = "0b111000101000001";
        ram[12] = "0b000100000001110";
        ram[13] = "0b111111110011000";
        ram[14] = "0b111010111100101";
        ram[15] = "0b110110010100000";
        ram[16] = "0b000000001001110";
        ram[17] = "0b001000111101000";
        ram[18] = "0b000010101101011";
        ram[19] = "0b000011111000111";
        ram[20] = "0b110101000100101";
        ram[21] = "0b111100101011101";
        ram[22] = "0b110110000000110";
        ram[23] = "0b000110111110101";
        ram[24] = "0b111011001111110";
        ram[25] = "0b111101001101011";
        ram[26] = "0b111110111010110";
        ram[27] = "0b000101111110000";
        ram[28] = "0b111010010111000";
        ram[29] = "0b001000000101100";
        ram[30] = "0b000001011000011";
        ram[31] = "0b111100100010111";
        ram[32] = "0b000011001110000";
        ram[33] = "0b111111000101111";
        ram[34] = "0b000000001111101";
        ram[35] = "0b110110011101000";
        ram[36] = "0b000100101011011";
        ram[37] = "0b111110100101100";
        ram[38] = "0b000101001111110";
        ram[39] = "0b000111011011101";


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


SC_MODULE(mlp_accel_weights_l3_8) {


static const unsigned DataWidth = 15;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_8_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_8) {
meminst = new mlp_accel_weights_l3_8_ram("mlp_accel_weights_l3_8_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_8() {
    delete meminst;
}


};//endmodule
#endif
