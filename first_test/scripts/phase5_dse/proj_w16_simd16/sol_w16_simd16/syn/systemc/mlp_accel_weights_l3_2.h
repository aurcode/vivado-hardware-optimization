// ==============================================================
// File generated on Wed Sep 02 16:35:40 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_weights_l3_2_H__
#define __mlp_accel_weights_l3_2_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_weights_l3_2_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_weights_l3_2_ram) {
        ram[0] = "0b000001000011110";
        ram[1] = "0b110110100000100";
        ram[2] = "0b000010001100011";
        ram[3] = "0b000111110110000";
        ram[4] = "0b000010101111011";
        ram[5] = "0b000010010110100";
        ram[6] = "0b111001100100010";
        ram[7] = "0b000000100110101";
        ram[8] = "0b111000110011001";
        ram[9] = "0b000001010010110";
        ram[10] = "0b111100101101110";
        ram[11] = "0b111111111110000";
        ram[12] = "0b110011110110011";
        ram[13] = "0b111000110111000";
        ram[14] = "0b110101111011011";
        ram[15] = "0b000011111010111";
        ram[16] = "0b000011111011010";
        ram[17] = "0b000010000001000";
        ram[18] = "0b000110011100111";
        ram[19] = "0b000110101101111";
        ram[20] = "0b000111110110101";
        ram[21] = "0b000100111001111";
        ram[22] = "0b111110001001111";
        ram[23] = "0b111001111000010";
        ram[24] = "0b000001010010001";
        ram[25] = "0b000110010110111";
        ram[26] = "0b000001111111001";
        ram[27] = "0b000011100100001";
        ram[28] = "0b000110001010010";
        ram[29] = "0b110111100110111";
        ram[30] = "0b111011010101100";
        ram[31] = "0b111110101010110";
        ram[32] = "0b111011111111101";
        ram[33] = "0b111111110011001";
        ram[34] = "0b110111011101111";
        ram[35] = "0b101111100001011";
        ram[36] = "0b111111111011110";
        ram[37] = "0b111000101101000";
        ram[38] = "0b000010001111111";
        ram[39] = "0b000100000111000";


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


SC_MODULE(mlp_accel_weights_l3_2) {


static const unsigned DataWidth = 15;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_weights_l3_2_ram* meminst;


SC_CTOR(mlp_accel_weights_l3_2) {
meminst = new mlp_accel_weights_l3_2_ram("mlp_accel_weights_l3_2_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_weights_l3_2() {
    delete meminst;
}


};//endmodule
#endif
