// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l3_4b_4_H__
#define __mlp_accel_4b_weights_l3_4b_4_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l3_4b_4_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 2;
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


   SC_CTOR(mlp_accel_4b_weights_l3_4b_4_ram) {
        ram[0] = "0b00";
        ram[1] = "0b11";
        ram[2] = "0b11";
        ram[3] = "0b01";
        ram[4] = "0b11";
        ram[5] = "0b01";
        ram[6] = "0b11";
        ram[7] = "0b00";
        ram[8] = "0b01";
        ram[9] = "0b10";
        ram[10] = "0b01";
        ram[11] = "0b00";
        ram[12] = "0b00";
        ram[13] = "0b01";
        ram[14] = "0b00";
        ram[15] = "0b00";
        ram[16] = "0b10";
        ram[17] = "0b00";
        ram[18] = "0b11";
        ram[19] = "0b11";
        ram[20] = "0b00";
        ram[21] = "0b01";
        ram[22] = "0b11";
        ram[23] = "0b11";
        ram[24] = "0b11";
        ram[25] = "0b00";
        ram[26] = "0b01";
        ram[27] = "0b01";
        ram[28] = "0b11";
        ram[29] = "0b10";
        ram[30] = "0b01";
        ram[31] = "0b11";
        ram[32] = "0b11";
        ram[33] = "0b00";
        ram[34] = "0b00";
        ram[35] = "0b01";
        ram[36] = "0b00";
        ram[37] = "0b01";
        ram[38] = "0b10";
        ram[39] = "0b11";


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


SC_MODULE(mlp_accel_4b_weights_l3_4b_4) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 40;
static const unsigned AddressWidth = 6;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l3_4b_4_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l3_4b_4) {
meminst = new mlp_accel_4b_weights_l3_4b_4_ram("mlp_accel_4b_weights_l3_4b_4_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l3_4b_4() {
    delete meminst;
}


};//endmodule
#endif
