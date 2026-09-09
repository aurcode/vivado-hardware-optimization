// ==============================================================
// File generated on Wed Sep 02 16:31:16 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_8b_weights_l3_8b_0_H__
#define __mlp_accel_8b_weights_l3_8b_0_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_8b_weights_l3_8b_0_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 7;
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


   SC_CTOR(mlp_accel_8b_weights_l3_8b_0_ram) {
        ram[0] = "0b0000100";
        ram[1] = "0b1111110";
        ram[2] = "0b1110101";
        ram[3] = "0b1110000";
        ram[4] = "0b1111110";
        ram[5] = "0b0000000";
        ram[6] = "0b0000101";
        ram[7] = "0b1101111";
        ram[8] = "0b1110000";
        ram[9] = "0b0000010";
        ram[10] = "0b1100100";
        ram[11] = "0b0001010";
        ram[12] = "0b1110010";
        ram[13] = "0b1111110";
        ram[14] = "0b0001110";
        ram[15] = "0b0000010";
        ram[16] = "0b0001101";
        ram[17] = "0b0000001";
        ram[18] = "0b1110100";
        ram[19] = "0b1011111";
        ram[20] = "0b1110110";
        ram[21] = "0b1111111";
        ram[22] = "0b0010011";
        ram[23] = "0b0001101";
        ram[24] = "0b0001100";
        ram[25] = "0b0000011";
        ram[26] = "0b0001010";
        ram[27] = "0b1111111";
        ram[28] = "0b1101001";
        ram[29] = "0b1111111";
        ram[30] = "0b0000001";
        ram[31] = "0b1111011";
        ram[32] = "0b0000111";
        ram[33] = "0b1111100";
        ram[34] = "0b1110101";
        ram[35] = "0b0001000";
        ram[36] = "0b0010010";
        ram[37] = "0b0000001";
        ram[38] = "0b1111111";
        ram[39] = "0b1110011";


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


SC_MODULE(mlp_accel_8b_weights_l3_8b_0) {


static const unsigned DataWidth = 7;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_8b_weights_l3_8b_0_ram* meminst;


SC_CTOR(mlp_accel_8b_weights_l3_8b_0) {
meminst = new mlp_accel_8b_weights_l3_8b_0_ram("mlp_accel_8b_weights_l3_8b_0_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_8b_weights_l3_8b_0() {
    delete meminst;
}


};//endmodule
#endif
