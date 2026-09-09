// ==============================================================
// File generated on Wed Sep 02 16:32:49 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_8b32_weights_l3_8b32_20_H__
#define __mlp_accel_8b32_weights_l3_8b32_20_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_8b32_weights_l3_8b32_20_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 6;
  static const unsigned AddressRange = 20;
  static const unsigned AddressWidth = 5;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(mlp_accel_8b32_weights_l3_8b32_20_ram) {
        ram[0] = "0b110011";
        ram[1] = "0b010010";
        ram[2] = "0b001001";
        ram[3] = "0b111001";
        ram[4] = "0b100110";
        ram[5] = "0b111010";
        ram[6] = "0b001101";
        ram[7] = "0b111000";
        ram[8] = "0b111010";
        ram[9] = "0b101110";
        ram[10] = "0b001110";
        ram[11] = "0b110100";
        ram[12] = "0b111101";
        ram[13] = "0b010101";
        ram[14] = "0b100000";
        ram[15] = "0b101010";
        ram[16] = "0b111111";
        ram[17] = "0b001100";
        ram[18] = "0b010000";
        ram[19] = "0b110000";


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


SC_MODULE(mlp_accel_8b32_weights_l3_8b32_20) {


static const unsigned DataWidth = 6;
static const unsigned AddressRange = 20;
static const unsigned AddressWidth = 5;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_8b32_weights_l3_8b32_20_ram* meminst;


SC_CTOR(mlp_accel_8b32_weights_l3_8b32_20) {
meminst = new mlp_accel_8b32_weights_l3_8b32_20_ram("mlp_accel_8b32_weights_l3_8b32_20_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_8b32_weights_l3_8b32_20() {
    delete meminst;
}


};//endmodule
#endif
