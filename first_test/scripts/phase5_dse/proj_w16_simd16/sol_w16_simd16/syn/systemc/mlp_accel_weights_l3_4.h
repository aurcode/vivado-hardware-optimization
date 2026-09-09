// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_4_H__
#define __mlp_accel_weights_l3_4_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_4_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_4_ram) {
        ram[0] = "0b000000111110010";
        ram[1] = "0b111001100101100";
        ram[2] = "0b111011111001010";
        ram[3] = "0b001001000100010";
        ram[4] = "0b111001000010001";
        ram[5] = "0b000100010110011";
        ram[6] = "0b111010011011110";
        ram[7] = "0b111100011101101";
        ram[8] = "0b000101001101100";
        ram[9] = "0b110010111010011";
        ram[10] = "0b001000001100100";
        ram[11] = "0b111100110101111";
        ram[12] = "0b000011011101101";
        ram[13] = "0b000110101001111";
        ram[14] = "0b000010110100011";
        ram[15] = "0b111100000100011";
        ram[16] = "0b110011110010100";
        ram[17] = "0b111101000111111";
        ram[18] = "0b111000110100100";
        ram[19] = "0b110111001010000";
        ram[20] = "0b000001011101110";
        ram[21] = "0b000110111011101";
        ram[22] = "0b111011000101000";
        ram[23] = "0b111001111110001";
        ram[24] = "0b111000110100100";
        ram[25] = "0b111110010000010";
        ram[26] = "0b000100110111110";
        ram[27] = "0b001010010101110";
        ram[28] = "0b110100110111100";
        ram[29] = "0b101111111000010";
        ram[30] = "0b000100010011000";
        ram[31] = "0b110101001100100";
        ram[32] = "0b111011000001111";
        ram[33] = "0b111111100101010";
        ram[34] = "0b111110111111010";
        ram[35] = "0b000101110100000";
        ram[36] = "0b000010011011011";
        ram[37] = "0b000111110111001";
        ram[38] = "0b101101010110100";
        ram[39] = "0b110111110001111";


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


SC_MODULE(mlp_accel_weights_l3_4) {


static const unsigned DataWidth = 15;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_4_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_4) {
meminst = new mlp_accel_weights_l3_4_ram("mlp_accel_weights_l3_4_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_4() {
    delete meminst;
}


};//endmodule
#endif
