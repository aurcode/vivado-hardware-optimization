// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_9_H__
#define __mlp_accel_weights_l3_9_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_9_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_9_ram) {
        ram[0] = "0b111100000010010";
        ram[1] = "0b000001010011001";
        ram[2] = "0b000110110101111";
        ram[3] = "0b000101110001101";
        ram[4] = "0b000100011101110";
        ram[5] = "0b110100100000111";
        ram[6] = "0b111000110011101";
        ram[7] = "0b110111111101000";
        ram[8] = "0b000111000010001";
        ram[9] = "0b111110110111001";
        ram[10] = "0b110010111100110";
        ram[11] = "0b000011110000100";
        ram[12] = "0b000001101110000";
        ram[13] = "0b000101111000110";
        ram[14] = "0b110111101100100";
        ram[15] = "0b111001001101110";
        ram[16] = "0b000110000010001";
        ram[17] = "0b110011101101001";
        ram[18] = "0b000011100010011";
        ram[19] = "0b110000010101010";
        ram[20] = "0b111010111001011";
        ram[21] = "0b001000101001101";
        ram[22] = "0b110011111101000";
        ram[23] = "0b000110001100010";
        ram[24] = "0b000011010010000";
        ram[25] = "0b111110010000110";
        ram[26] = "0b111101110111100";
        ram[27] = "0b111010011001110";
        ram[28] = "0b000010010000000";
        ram[29] = "0b000001101110110";
        ram[30] = "0b001010010101101";
        ram[31] = "0b000101111010011";
        ram[32] = "0b111010101111010";
        ram[33] = "0b000001010100100";
        ram[34] = "0b111001101100101";
        ram[35] = "0b111101100001011";
        ram[36] = "0b101001011011000";
        ram[37] = "0b111101111001101";
        ram[38] = "0b111100110000001";
        ram[39] = "0b111110111001010";


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


SC_MODULE(mlp_accel_weights_l3_9) {


static const unsigned DataWidth = 15;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_9_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_9) {
meminst = new mlp_accel_weights_l3_9_ram("mlp_accel_weights_l3_9_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_9() {
    delete meminst;
}


};//endmodule
#endif
