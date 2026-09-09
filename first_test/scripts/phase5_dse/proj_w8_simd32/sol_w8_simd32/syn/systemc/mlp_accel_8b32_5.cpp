#include "mlp_accel_8b32.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void mlp_accel_8b32::thread_tmp_22_fu_4967_p2() {
    tmp_22_fu_4967_p2 = (!tmp_22_fu_4967_p0.read().is_01() || !tmp_22_fu_4967_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_22_fu_4967_p0.read()) * sc_bigint<8>(tmp_22_fu_4967_p1.read());
}

void mlp_accel_8b32::thread_tmp_23_fu_9549_p4() {
    tmp_23_fu_9549_p4 = tmp_13_fu_9511_p2.read().range(13, 6);
}

void mlp_accel_8b32::thread_tmp_24_fu_11951_p1() {
    tmp_24_fu_11951_p1 = esl_zext<64,4>(i_reg_3714.read());
}

void mlp_accel_8b32::thread_tmp_25_dup_fu_11203_p2() {
    tmp_25_dup_fu_11203_p2 = (!ap_const_lv19_20.is_01() || !acc_assign_2_reg_3703.read().is_01())? sc_lv<19>(): (sc_biguint<19>(ap_const_lv19_20) + sc_biguint<19>(acc_assign_2_reg_3703.read()));
}

void mlp_accel_8b32::thread_tmp_25_fu_5436_p2() {
    tmp_25_fu_5436_p2 = (!tmp1090_cast_fu_5416_p1.read().is_01() || !tmp1105_cast_fu_5432_p1.read().is_01())? sc_lv<18>(): (sc_bigint<18>(tmp1090_cast_fu_5416_p1.read()) + sc_bigint<18>(tmp1105_cast_fu_5432_p1.read()));
}

void mlp_accel_8b32::thread_tmp_26_fu_10465_p3() {
    tmp_26_fu_10465_p3 = esl_concat<4,1>(tmp_12_mid2_v_fu_10457_p3.read(), ap_const_lv1_0);
}

void mlp_accel_8b32::thread_tmp_27_cast_fu_10477_p1() {
    tmp_27_cast_fu_10477_p1 = esl_zext<6,2>(b2_mid2_fu_10449_p3.read());
}

void mlp_accel_8b32::thread_tmp_28_cast_fu_4943_p1() {
    tmp_28_cast_fu_4943_p1 = esl_zext<64,12>(tmp_21_fu_4937_p2.read());
}

void mlp_accel_8b32::thread_tmp_28_fu_10481_p2() {
    tmp_28_fu_10481_p2 = (!tmp_60_cast_fu_10473_p1.read().is_01() || !tmp_27_cast_fu_10477_p1.read().is_01())? sc_lv<6>(): (sc_biguint<6>(tmp_60_cast_fu_10473_p1.read()) + sc_biguint<6>(tmp_27_cast_fu_10477_p1.read()));
}

void mlp_accel_8b32::thread_tmp_29_fu_10744_p0() {
    tmp_29_fu_10744_p0 = weights_l3_8b32_0_q0.read();
}

void mlp_accel_8b32::thread_tmp_29_fu_10744_p1() {
    tmp_29_fu_10744_p1 = pong_buf_load_0_phi_fu_10533_p3.read();
}

void mlp_accel_8b32::thread_tmp_29_fu_10744_p2() {
    tmp_29_fu_10744_p2 = (!tmp_29_fu_10744_p0.read().is_01() || !tmp_29_fu_10744_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_29_fu_10744_p0.read()) * sc_bigint<8>(tmp_29_fu_10744_p1.read());
}

void mlp_accel_8b32::thread_tmp_2_fu_8510_p3() {
    tmp_2_fu_8510_p3 = esl_concat<7,2>(n3_reg_3634.read(), ap_const_lv2_0);
}

void mlp_accel_8b32::thread_tmp_31_fu_11375_p2() {
    tmp_31_fu_11375_p2 = (!tmp1150_cast_fu_11346_p1.read().is_01() || !tmp1165_cast_fu_11371_p1.read().is_01())? sc_lv<18>(): (sc_bigint<18>(tmp1150_cast_fu_11346_p1.read()) + sc_bigint<18>(tmp1165_cast_fu_11371_p1.read()));
}

void mlp_accel_8b32::thread_tmp_32_fu_9517_p4() {
    tmp_32_fu_9517_p4 = tmp_13_fu_9511_p2.read().range(19, 6);
}

void mlp_accel_8b32::thread_tmp_33_fu_9567_p2() {
    tmp_33_fu_9567_p2 = (tmp_14_fu_9527_p2.read() | icmp2_fu_9543_p2.read());
}

void mlp_accel_8b32::thread_tmp_35_fu_9007_p0() {
    tmp_35_fu_9007_p0 = weights_l2_8b32_0_q0.read();
}

void mlp_accel_8b32::thread_tmp_35_fu_9007_p1() {
    tmp_35_fu_9007_p1 = tmp_37_fu_8583_p6.read();
}

void mlp_accel_8b32::thread_tmp_35_fu_9007_p2() {
    tmp_35_fu_9007_p2 = (!tmp_35_fu_9007_p0.read().is_01() || !tmp_35_fu_9007_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_35_fu_9007_p0.read()) * sc_bigint<8>(tmp_35_fu_9007_p1.read());
}

void mlp_accel_8b32::thread_tmp_36_dup_fu_11235_p2() {
    tmp_36_dup_fu_11235_p2 = (!tmp_134_dup_fu_11209_p4.read().is_01() || !ap_const_lv13_1F80.is_01())? sc_lv<1>(): (sc_bigint<13>(tmp_134_dup_fu_11209_p4.read()) < sc_bigint<13>(ap_const_lv13_1F80));
}

void mlp_accel_8b32::thread_tmp_36_fu_8538_p2() {
    tmp_36_fu_8538_p2 = (!tmp_16_cast_reg_14543.read().is_01() || !tmp_15_cast_fu_8534_p1.read().is_01())? sc_lv<10>(): (sc_biguint<10>(tmp_16_cast_reg_14543.read()) + sc_biguint<10>(tmp_15_cast_fu_8534_p1.read()));
}

void mlp_accel_8b32::thread_tmp_37_11_fu_5049_p0() {
    tmp_37_11_fu_5049_p0 = weights_l1_8b32_12_l_reg_14166.read();
}

void mlp_accel_8b32::thread_tmp_37_11_fu_5049_p1() {
    tmp_37_11_fu_5049_p1 = input_buf_12_load_reg_14161.read();
}

void mlp_accel_8b32::thread_tmp_37_13_fu_5068_p0() {
    tmp_37_13_fu_5068_p0 = weights_l1_8b32_14_l_reg_14186.read();
}

void mlp_accel_8b32::thread_tmp_37_13_fu_5068_p1() {
    tmp_37_13_fu_5068_p1 = input_buf_14_load_reg_14181.read();
}

void mlp_accel_8b32::thread_tmp_37_15_fu_5087_p0() {
    tmp_37_15_fu_5087_p0 = weights_l1_8b32_16_l_reg_14206.read();
}

void mlp_accel_8b32::thread_tmp_37_15_fu_5087_p1() {
    tmp_37_15_fu_5087_p1 = input_buf_16_load_reg_14201.read();
}

void mlp_accel_8b32::thread_tmp_37_17_fu_5106_p0() {
    tmp_37_17_fu_5106_p0 = weights_l1_8b32_18_l_reg_14226.read();
}

void mlp_accel_8b32::thread_tmp_37_17_fu_5106_p1() {
    tmp_37_17_fu_5106_p1 = input_buf_18_load_reg_14221.read();
}

void mlp_accel_8b32::thread_tmp_37_19_fu_5127_p0() {
    tmp_37_19_fu_5127_p0 = weights_l1_8b32_20_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_19_fu_5127_p1() {
    tmp_37_19_fu_5127_p1 = input_buf_20_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_19_fu_5127_p2() {
    tmp_37_19_fu_5127_p2 = (!tmp_37_19_fu_5127_p0.read().is_01() || !tmp_37_19_fu_5127_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_37_19_fu_5127_p0.read()) * sc_bigint<8>(tmp_37_19_fu_5127_p1.read());
}

void mlp_accel_8b32::thread_tmp_37_21_fu_5141_p0() {
    tmp_37_21_fu_5141_p0 = weights_l1_8b32_22_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_21_fu_5141_p1() {
    tmp_37_21_fu_5141_p1 = input_buf_22_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_21_fu_5141_p2() {
    tmp_37_21_fu_5141_p2 = (!tmp_37_21_fu_5141_p0.read().is_01() || !tmp_37_21_fu_5141_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_37_21_fu_5141_p0.read()) * sc_bigint<8>(tmp_37_21_fu_5141_p1.read());
}

void mlp_accel_8b32::thread_tmp_37_23_fu_5155_p0() {
    tmp_37_23_fu_5155_p0 = weights_l1_8b32_24_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_23_fu_5155_p1() {
    tmp_37_23_fu_5155_p1 = input_buf_24_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_23_fu_5155_p2() {
    tmp_37_23_fu_5155_p2 = (!tmp_37_23_fu_5155_p0.read().is_01() || !tmp_37_23_fu_5155_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_37_23_fu_5155_p0.read()) * sc_bigint<8>(tmp_37_23_fu_5155_p1.read());
}

void mlp_accel_8b32::thread_tmp_37_26_fu_5169_p0() {
    tmp_37_26_fu_5169_p0 = weights_l1_8b32_27_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_26_fu_5169_p1() {
    tmp_37_26_fu_5169_p1 = input_buf_27_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_26_fu_5169_p2() {
    tmp_37_26_fu_5169_p2 = (!tmp_37_26_fu_5169_p0.read().is_01() || !tmp_37_26_fu_5169_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_37_26_fu_5169_p0.read()) * sc_bigint<8>(tmp_37_26_fu_5169_p1.read());
}

void mlp_accel_8b32::thread_tmp_37_28_fu_5188_p0() {
    tmp_37_28_fu_5188_p0 = weights_l1_8b32_29_l_reg_14296.read();
}

void mlp_accel_8b32::thread_tmp_37_28_fu_5188_p1() {
    tmp_37_28_fu_5188_p1 = input_buf_29_load_reg_14291.read();
}

void mlp_accel_8b32::thread_tmp_37_29_fu_5200_p0() {
    tmp_37_29_fu_5200_p0 = weights_l1_8b32_30_l_reg_14306.read();
}

void mlp_accel_8b32::thread_tmp_37_29_fu_5200_p1() {
    tmp_37_29_fu_5200_p1 = input_buf_30_load_reg_14301.read();
}

void mlp_accel_8b32::thread_tmp_37_2_fu_4981_p0() {
    tmp_37_2_fu_4981_p0 = weights_l1_8b32_2_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_2_fu_4981_p1() {
    tmp_37_2_fu_4981_p1 = input_buf_2_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_2_fu_4981_p2() {
    tmp_37_2_fu_4981_p2 = (!tmp_37_2_fu_4981_p0.read().is_01() || !tmp_37_2_fu_4981_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_37_2_fu_4981_p0.read()) * sc_bigint<8>(tmp_37_2_fu_4981_p1.read());
}

void mlp_accel_8b32::thread_tmp_37_4_fu_4995_p0() {
    tmp_37_4_fu_4995_p0 = weights_l1_8b32_4_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_4_fu_4995_p1() {
    tmp_37_4_fu_4995_p1 = input_buf_4_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_4_fu_4995_p2() {
    tmp_37_4_fu_4995_p2 = (!tmp_37_4_fu_4995_p0.read().is_01() || !tmp_37_4_fu_4995_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_37_4_fu_4995_p0.read()) * sc_bigint<8>(tmp_37_4_fu_4995_p1.read());
}

void mlp_accel_8b32::thread_tmp_37_6_fu_5009_p0() {
    tmp_37_6_fu_5009_p0 = weights_l1_8b32_6_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_6_fu_5009_p1() {
    tmp_37_6_fu_5009_p1 = input_buf_6_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_6_fu_5009_p2() {
    tmp_37_6_fu_5009_p2 = (!tmp_37_6_fu_5009_p0.read().is_01() || !tmp_37_6_fu_5009_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_37_6_fu_5009_p0.read()) * sc_bigint<8>(tmp_37_6_fu_5009_p1.read());
}

void mlp_accel_8b32::thread_tmp_37_9_fu_5023_p0() {
    tmp_37_9_fu_5023_p0 = weights_l1_8b32_9_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_9_fu_5023_p1() {
    tmp_37_9_fu_5023_p1 = input_buf_9_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_9_fu_5023_p2() {
    tmp_37_9_fu_5023_p2 = (!tmp_37_9_fu_5023_p0.read().is_01() || !tmp_37_9_fu_5023_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_37_9_fu_5023_p0.read()) * sc_bigint<8>(tmp_37_9_fu_5023_p1.read());
}

void mlp_accel_8b32::thread_tmp_37_dup_fu_11241_p4() {
    tmp_37_dup_fu_11241_p4 = tmp_25_dup_fu_11203_p2.read().range(13, 6);
}

void mlp_accel_8b32::thread_tmp_37_s_fu_5037_p0() {
    tmp_37_s_fu_5037_p0 = weights_l1_8b32_10_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_s_fu_5037_p1() {
    tmp_37_s_fu_5037_p1 = input_buf_10_q0.read();
}

void mlp_accel_8b32::thread_tmp_37_s_fu_5037_p2() {
    tmp_37_s_fu_5037_p2 = (!tmp_37_s_fu_5037_p0.read().is_01() || !tmp_37_s_fu_5037_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_37_s_fu_5037_p0.read()) * sc_bigint<8>(tmp_37_s_fu_5037_p1.read());
}

void mlp_accel_8b32::thread_tmp_3_fu_5468_p2() {
    tmp_3_fu_5468_p2 = (!tmp_9_fu_5458_p4.read().is_01() || !ap_const_lv17_1.is_01())? sc_lv<1>(): (sc_bigint<17>(tmp_9_fu_5458_p4.read()) < sc_bigint<17>(ap_const_lv17_1));
}

void mlp_accel_8b32::thread_tmp_45_11_fu_9091_p0() {
    tmp_45_11_fu_9091_p0 = weights_l2_8b32_12_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_11_fu_9091_p1() {
    tmp_45_11_fu_9091_p1 = tmp_49_fu_8739_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_11_fu_9091_p2() {
    tmp_45_11_fu_9091_p2 = (!tmp_45_11_fu_9091_p0.read().is_01() || !tmp_45_11_fu_9091_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_11_fu_9091_p0.read()) * sc_bigint<8>(tmp_45_11_fu_9091_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_13_fu_9105_p0() {
    tmp_45_13_fu_9105_p0 = weights_l2_8b32_14_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_13_fu_9105_p1() {
    tmp_45_13_fu_9105_p1 = tmp_51_fu_8765_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_13_fu_9105_p2() {
    tmp_45_13_fu_9105_p2 = (!tmp_45_13_fu_9105_p0.read().is_01() || !tmp_45_13_fu_9105_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_45_13_fu_9105_p0.read()) * sc_bigint<8>(tmp_45_13_fu_9105_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_15_fu_9119_p0() {
    tmp_45_15_fu_9119_p0 = weights_l2_8b32_16_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_15_fu_9119_p1() {
    tmp_45_15_fu_9119_p1 = tmp_53_fu_8791_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_15_fu_9119_p2() {
    tmp_45_15_fu_9119_p2 = (!tmp_45_15_fu_9119_p0.read().is_01() || !tmp_45_15_fu_9119_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_45_15_fu_9119_p0.read()) * sc_bigint<8>(tmp_45_15_fu_9119_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_17_fu_9133_p0() {
    tmp_45_17_fu_9133_p0 = weights_l2_8b32_18_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_17_fu_9133_p1() {
    tmp_45_17_fu_9133_p1 = tmp_55_fu_8817_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_17_fu_9133_p2() {
    tmp_45_17_fu_9133_p2 = (!tmp_45_17_fu_9133_p0.read().is_01() || !tmp_45_17_fu_9133_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_17_fu_9133_p0.read()) * sc_bigint<8>(tmp_45_17_fu_9133_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_19_fu_9147_p0() {
    tmp_45_19_fu_9147_p0 = weights_l2_8b32_20_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_19_fu_9147_p1() {
    tmp_45_19_fu_9147_p1 = tmp_57_fu_8843_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_19_fu_9147_p2() {
    tmp_45_19_fu_9147_p2 = (!tmp_45_19_fu_9147_p0.read().is_01() || !tmp_45_19_fu_9147_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_19_fu_9147_p0.read()) * sc_bigint<8>(tmp_45_19_fu_9147_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_21_fu_9161_p0() {
    tmp_45_21_fu_9161_p0 = weights_l2_8b32_22_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_21_fu_9161_p1() {
    tmp_45_21_fu_9161_p1 = tmp_59_fu_8869_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_21_fu_9161_p2() {
    tmp_45_21_fu_9161_p2 = (!tmp_45_21_fu_9161_p0.read().is_01() || !tmp_45_21_fu_9161_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_21_fu_9161_p0.read()) * sc_bigint<8>(tmp_45_21_fu_9161_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_23_fu_9175_p0() {
    tmp_45_23_fu_9175_p0 = weights_l2_8b32_24_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_23_fu_9175_p1() {
    tmp_45_23_fu_9175_p1 = tmp_63_fu_8895_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_23_fu_9175_p2() {
    tmp_45_23_fu_9175_p2 = (!tmp_45_23_fu_9175_p0.read().is_01() || !tmp_45_23_fu_9175_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_23_fu_9175_p0.read()) * sc_bigint<8>(tmp_45_23_fu_9175_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_25_fu_9189_p0() {
    tmp_45_25_fu_9189_p0 = weights_l2_8b32_26_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_25_fu_9189_p1() {
    tmp_45_25_fu_9189_p1 = tmp_65_fu_8921_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_25_fu_9189_p2() {
    tmp_45_25_fu_9189_p2 = (!tmp_45_25_fu_9189_p0.read().is_01() || !tmp_45_25_fu_9189_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_25_fu_9189_p0.read()) * sc_bigint<8>(tmp_45_25_fu_9189_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_27_fu_9203_p0() {
    tmp_45_27_fu_9203_p0 = weights_l2_8b32_28_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_27_fu_9203_p1() {
    tmp_45_27_fu_9203_p1 = tmp_67_fu_8947_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_27_fu_9203_p2() {
    tmp_45_27_fu_9203_p2 = (!tmp_45_27_fu_9203_p0.read().is_01() || !tmp_45_27_fu_9203_p1.read().is_01())? sc_lv<14>(): sc_bigint<7>(tmp_45_27_fu_9203_p0.read()) * sc_bigint<8>(tmp_45_27_fu_9203_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_29_fu_9217_p0() {
    tmp_45_29_fu_9217_p0 = weights_l2_8b32_30_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_29_fu_9217_p1() {
    tmp_45_29_fu_9217_p1 = tmp_69_fu_8973_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_29_fu_9217_p2() {
    tmp_45_29_fu_9217_p2 = (!tmp_45_29_fu_9217_p0.read().is_01() || !tmp_45_29_fu_9217_p1.read().is_01())? sc_lv<14>(): sc_bigint<7>(tmp_45_29_fu_9217_p0.read()) * sc_bigint<8>(tmp_45_29_fu_9217_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_2_fu_9021_p0() {
    tmp_45_2_fu_9021_p0 = weights_l2_8b32_2_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_2_fu_9021_p1() {
    tmp_45_2_fu_9021_p1 = tmp_39_fu_8609_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_2_fu_9021_p2() {
    tmp_45_2_fu_9021_p2 = (!tmp_45_2_fu_9021_p0.read().is_01() || !tmp_45_2_fu_9021_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_2_fu_9021_p0.read()) * sc_bigint<8>(tmp_45_2_fu_9021_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_4_fu_9035_p0() {
    tmp_45_4_fu_9035_p0 = weights_l2_8b32_4_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_4_fu_9035_p1() {
    tmp_45_4_fu_9035_p1 = tmp_41_fu_8635_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_4_fu_9035_p2() {
    tmp_45_4_fu_9035_p2 = (!tmp_45_4_fu_9035_p0.read().is_01() || !tmp_45_4_fu_9035_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_4_fu_9035_p0.read()) * sc_bigint<8>(tmp_45_4_fu_9035_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_6_fu_9049_p0() {
    tmp_45_6_fu_9049_p0 = weights_l2_8b32_6_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_6_fu_9049_p1() {
    tmp_45_6_fu_9049_p1 = tmp_43_fu_8661_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_6_fu_9049_p2() {
    tmp_45_6_fu_9049_p2 = (!tmp_45_6_fu_9049_p0.read().is_01() || !tmp_45_6_fu_9049_p1.read().is_01())? sc_lv<14>(): sc_bigint<7>(tmp_45_6_fu_9049_p0.read()) * sc_bigint<8>(tmp_45_6_fu_9049_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_9_fu_9063_p0() {
    tmp_45_9_fu_9063_p0 = weights_l2_8b32_9_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_9_fu_9063_p1() {
    tmp_45_9_fu_9063_p1 = tmp_46_fu_8700_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_9_fu_9063_p2() {
    tmp_45_9_fu_9063_p2 = (!tmp_45_9_fu_9063_p0.read().is_01() || !tmp_45_9_fu_9063_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_9_fu_9063_p0.read()) * sc_bigint<8>(tmp_45_9_fu_9063_p1.read());
}

void mlp_accel_8b32::thread_tmp_45_s_fu_9077_p0() {
    tmp_45_s_fu_9077_p0 = weights_l2_8b32_10_q0.read();
}

void mlp_accel_8b32::thread_tmp_45_s_fu_9077_p1() {
    tmp_45_s_fu_9077_p1 = tmp_47_fu_8713_p6.read();
}

void mlp_accel_8b32::thread_tmp_45_s_fu_9077_p2() {
    tmp_45_s_fu_9077_p2 = (!tmp_45_s_fu_9077_p0.read().is_01() || !tmp_45_s_fu_9077_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_45_s_fu_9077_p0.read()) * sc_bigint<8>(tmp_45_s_fu_9077_p1.read());
}

void mlp_accel_8b32::thread_tmp_4_10_fu_4730_p2() {
    tmp_4_10_fu_4730_p2 = (!idx_24_fu_4725_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_24_fu_4725_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_11_fu_4754_p2() {
    tmp_4_11_fu_4754_p2 = (!idx_25_fu_4749_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_25_fu_4749_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_12_fu_4778_p2() {
    tmp_4_12_fu_4778_p2 = (!idx_26_fu_4773_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_26_fu_4773_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_13_fu_4802_p2() {
    tmp_4_13_fu_4802_p2 = (!idx_27_fu_4797_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_27_fu_4797_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_14_fu_4826_p2() {
    tmp_4_14_fu_4826_p2 = (!idx_28_fu_4821_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_28_fu_4821_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_15_fu_4850_p2() {
    tmp_4_15_fu_4850_p2 = (!idx_29_fu_4845_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_29_fu_4845_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_16_fu_4874_p2() {
    tmp_4_16_fu_4874_p2 = (!idx_30_fu_4869_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_30_fu_4869_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_1_fu_4363_p2() {
    tmp_4_1_fu_4363_p2 = (!tmp_reg_12366.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(tmp_reg_12366.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_2_fu_4538_p2() {
    tmp_4_2_fu_4538_p2 = (!idx_16_fu_4533_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_16_fu_4533_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_3_fu_4562_p2() {
    tmp_4_3_fu_4562_p2 = (!idx_17_fu_4557_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_17_fu_4557_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_4_fu_4586_p2() {
    tmp_4_4_fu_4586_p2 = (!idx_18_fu_4581_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_18_fu_4581_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_5_fu_4610_p2() {
    tmp_4_5_fu_4610_p2 = (!idx_19_fu_4605_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_19_fu_4605_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_6_fu_4634_p2() {
    tmp_4_6_fu_4634_p2 = (!idx_20_fu_4629_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_20_fu_4629_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_7_fu_4658_p2() {
    tmp_4_7_fu_4658_p2 = (!idx_21_fu_4653_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_21_fu_4653_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_8_fu_4682_p2() {
    tmp_4_8_fu_4682_p2 = (!idx_22_fu_4677_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_22_fu_4677_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_9_fu_4706_p2() {
    tmp_4_9_fu_4706_p2 = (!idx_23_fu_4701_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_23_fu_4701_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_4_s_fu_4514_p2() {
    tmp_4_s_fu_4514_p2 = (!idx_15_fu_4509_p2.read().is_01() || !ap_const_lv10_310.is_01())? sc_lv<1>(): (sc_biguint<10>(idx_15_fu_4509_p2.read()) < sc_biguint<10>(ap_const_lv10_310));
}

void mlp_accel_8b32::thread_tmp_55_11_fu_10835_p0() {
    tmp_55_11_fu_10835_p0 = weights_l3_8b32_12_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_11_fu_10835_p1() {
    tmp_55_11_fu_10835_p1 = pong_buf_load_12_phi_fu_10610_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_11_fu_10835_p2() {
    tmp_55_11_fu_10835_p2 = (!tmp_55_11_fu_10835_p0.read().is_01() || !tmp_55_11_fu_10835_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_11_fu_10835_p0.read()) * sc_bigint<8>(tmp_55_11_fu_10835_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_13_fu_10849_p0() {
    tmp_55_13_fu_10849_p0 = weights_l3_8b32_14_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_13_fu_10849_p1() {
    tmp_55_13_fu_10849_p1 = pong_buf_load_14_phi_fu_10624_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_13_fu_10849_p2() {
    tmp_55_13_fu_10849_p2 = (!tmp_55_13_fu_10849_p0.read().is_01() || !tmp_55_13_fu_10849_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_13_fu_10849_p0.read()) * sc_bigint<8>(tmp_55_13_fu_10849_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_15_fu_10863_p0() {
    tmp_55_15_fu_10863_p0 = weights_l3_8b32_16_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_15_fu_10863_p1() {
    tmp_55_15_fu_10863_p1 = pong_buf_load_16_phi_fu_10638_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_15_fu_10863_p2() {
    tmp_55_15_fu_10863_p2 = (!tmp_55_15_fu_10863_p0.read().is_01() || !tmp_55_15_fu_10863_p1.read().is_01())? sc_lv<14>(): sc_bigint<7>(tmp_55_15_fu_10863_p0.read()) * sc_bigint<8>(tmp_55_15_fu_10863_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_17_fu_10877_p0() {
    tmp_55_17_fu_10877_p0 = weights_l3_8b32_18_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_17_fu_10877_p1() {
    tmp_55_17_fu_10877_p1 = pong_buf_load_18_phi_fu_10652_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_17_fu_10877_p2() {
    tmp_55_17_fu_10877_p2 = (!tmp_55_17_fu_10877_p0.read().is_01() || !tmp_55_17_fu_10877_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_55_17_fu_10877_p0.read()) * sc_bigint<8>(tmp_55_17_fu_10877_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_19_fu_10898_p0() {
    tmp_55_19_fu_10898_p0 = weights_l3_8b32_20_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_19_fu_10898_p1() {
    tmp_55_19_fu_10898_p1 = pong_buf_load_20_phi_fu_10659_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_19_fu_10898_p2() {
    tmp_55_19_fu_10898_p2 = (!tmp_55_19_fu_10898_p0.read().is_01() || !tmp_55_19_fu_10898_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_19_fu_10898_p0.read()) * sc_bigint<8>(tmp_55_19_fu_10898_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_21_fu_10912_p0() {
    tmp_55_21_fu_10912_p0 = weights_l3_8b32_22_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_21_fu_10912_p1() {
    tmp_55_21_fu_10912_p1 = pong_buf_load_22_phi_fu_10673_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_21_fu_10912_p2() {
    tmp_55_21_fu_10912_p2 = (!tmp_55_21_fu_10912_p0.read().is_01() || !tmp_55_21_fu_10912_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_55_21_fu_10912_p0.read()) * sc_bigint<8>(tmp_55_21_fu_10912_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_23_fu_10926_p0() {
    tmp_55_23_fu_10926_p0 = weights_l3_8b32_24_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_23_fu_10926_p1() {
    tmp_55_23_fu_10926_p1 = pong_buf_load_24_phi_fu_10687_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_23_fu_10926_p2() {
    tmp_55_23_fu_10926_p2 = (!tmp_55_23_fu_10926_p0.read().is_01() || !tmp_55_23_fu_10926_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_55_23_fu_10926_p0.read()) * sc_bigint<8>(tmp_55_23_fu_10926_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_25_fu_10947_p0() {
    tmp_55_25_fu_10947_p0 = weights_l3_8b32_26_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_25_fu_10947_p1() {
    tmp_55_25_fu_10947_p1 = pong_buf_load_26_phi_fu_10694_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_25_fu_10947_p2() {
    tmp_55_25_fu_10947_p2 = (!tmp_55_25_fu_10947_p0.read().is_01() || !tmp_55_25_fu_10947_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_25_fu_10947_p0.read()) * sc_bigint<8>(tmp_55_25_fu_10947_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_27_fu_10961_p0() {
    tmp_55_27_fu_10961_p0 = weights_l3_8b32_28_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_27_fu_10961_p1() {
    tmp_55_27_fu_10961_p1 = pong_buf_load_28_phi_fu_10708_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_27_fu_10961_p2() {
    tmp_55_27_fu_10961_p2 = (!tmp_55_27_fu_10961_p0.read().is_01() || !tmp_55_27_fu_10961_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_27_fu_10961_p0.read()) * sc_bigint<8>(tmp_55_27_fu_10961_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_29_fu_10975_p0() {
    tmp_55_29_fu_10975_p0 = weights_l3_8b32_30_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_29_fu_10975_p1() {
    tmp_55_29_fu_10975_p1 = pong_buf_load_30_phi_fu_10722_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_29_fu_10975_p2() {
    tmp_55_29_fu_10975_p2 = (!tmp_55_29_fu_10975_p0.read().is_01() || !tmp_55_29_fu_10975_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_29_fu_10975_p0.read()) * sc_bigint<8>(tmp_55_29_fu_10975_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_2_fu_10758_p0() {
    tmp_55_2_fu_10758_p0 = weights_l3_8b32_2_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_2_fu_10758_p1() {
    tmp_55_2_fu_10758_p1 = pong_buf_load_2_phi_fu_10547_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_2_fu_10758_p2() {
    tmp_55_2_fu_10758_p2 = (!tmp_55_2_fu_10758_p0.read().is_01() || !tmp_55_2_fu_10758_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_2_fu_10758_p0.read()) * sc_bigint<8>(tmp_55_2_fu_10758_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_4_fu_10772_p0() {
    tmp_55_4_fu_10772_p0 = weights_l3_8b32_4_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_4_fu_10772_p1() {
    tmp_55_4_fu_10772_p1 = pong_buf_load_4_phi_fu_10561_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_4_fu_10772_p2() {
    tmp_55_4_fu_10772_p2 = (!tmp_55_4_fu_10772_p0.read().is_01() || !tmp_55_4_fu_10772_p1.read().is_01())? sc_lv<14>(): sc_bigint<7>(tmp_55_4_fu_10772_p0.read()) * sc_bigint<8>(tmp_55_4_fu_10772_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_6_fu_10786_p0() {
    tmp_55_6_fu_10786_p0 = weights_l3_8b32_6_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_6_fu_10786_p1() {
    tmp_55_6_fu_10786_p1 = pong_buf_load_6_phi_fu_10575_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_6_fu_10786_p2() {
    tmp_55_6_fu_10786_p2 = (!tmp_55_6_fu_10786_p0.read().is_01() || !tmp_55_6_fu_10786_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_6_fu_10786_p0.read()) * sc_bigint<8>(tmp_55_6_fu_10786_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_9_fu_10807_p0() {
    tmp_55_9_fu_10807_p0 = weights_l3_8b32_9_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_9_fu_10807_p1() {
    tmp_55_9_fu_10807_p1 = pong_buf_load_9_phi_fu_10589_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_9_fu_10807_p2() {
    tmp_55_9_fu_10807_p2 = (!tmp_55_9_fu_10807_p0.read().is_01() || !tmp_55_9_fu_10807_p1.read().is_01())? sc_lv<15>(): sc_bigint<7>(tmp_55_9_fu_10807_p0.read()) * sc_bigint<8>(tmp_55_9_fu_10807_p1.read());
}

void mlp_accel_8b32::thread_tmp_55_s_fu_10821_p0() {
    tmp_55_s_fu_10821_p0 = weights_l3_8b32_10_q0.read();
}

void mlp_accel_8b32::thread_tmp_55_s_fu_10821_p1() {
    tmp_55_s_fu_10821_p1 = pong_buf_load_10_phi_fu_10596_p3.read();
}

void mlp_accel_8b32::thread_tmp_55_s_fu_10821_p2() {
    tmp_55_s_fu_10821_p2 = (!tmp_55_s_fu_10821_p0.read().is_01() || !tmp_55_s_fu_10821_p1.read().is_01())? sc_lv<14>(): sc_bigint<6>(tmp_55_s_fu_10821_p0.read()) * sc_bigint<8>(tmp_55_s_fu_10821_p1.read());
}

void mlp_accel_8b32::thread_tmp_5_10_fu_4464_p1() {
    tmp_5_10_fu_4464_p1 = esl_zext<64,10>(idx_10_fu_4459_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_11_fu_4474_p1() {
    tmp_5_11_fu_4474_p1 = esl_zext<64,10>(idx_11_fu_4469_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_12_fu_4484_p1() {
    tmp_5_12_fu_4484_p1 = esl_zext<64,10>(idx_12_fu_4479_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_13_fu_4494_p1() {
    tmp_5_13_fu_4494_p1 = esl_zext<64,10>(idx_13_fu_4489_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_14_fu_4504_p1() {
    tmp_5_14_fu_4504_p1 = esl_zext<64,10>(idx_14_fu_4499_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_15_fu_4520_p1() {
    tmp_5_15_fu_4520_p1 = esl_zext<64,10>(idx_15_fu_4509_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_16_fu_4544_p1() {
    tmp_5_16_fu_4544_p1 = esl_zext<64,10>(idx_16_fu_4533_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_17_fu_4568_p1() {
    tmp_5_17_fu_4568_p1 = esl_zext<64,10>(idx_17_fu_4557_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_18_fu_4592_p1() {
    tmp_5_18_fu_4592_p1 = esl_zext<64,10>(idx_18_fu_4581_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_19_fu_4616_p1() {
    tmp_5_19_fu_4616_p1 = esl_zext<64,10>(idx_19_fu_4605_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_1_fu_4358_p1() {
    tmp_5_1_fu_4358_p1 = esl_zext<64,10>(idx_s_fu_4353_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_20_fu_4640_p1() {
    tmp_5_20_fu_4640_p1 = esl_zext<64,10>(idx_20_fu_4629_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_21_fu_4664_p1() {
    tmp_5_21_fu_4664_p1 = esl_zext<64,10>(idx_21_fu_4653_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_22_fu_4688_p1() {
    tmp_5_22_fu_4688_p1 = esl_zext<64,10>(idx_22_fu_4677_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_23_fu_4712_p1() {
    tmp_5_23_fu_4712_p1 = esl_zext<64,10>(idx_23_fu_4701_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_24_fu_4736_p1() {
    tmp_5_24_fu_4736_p1 = esl_zext<64,10>(idx_24_fu_4725_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_25_fu_4760_p1() {
    tmp_5_25_fu_4760_p1 = esl_zext<64,10>(idx_25_fu_4749_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_26_fu_4784_p1() {
    tmp_5_26_fu_4784_p1 = esl_zext<64,10>(idx_26_fu_4773_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_27_fu_4808_p1() {
    tmp_5_27_fu_4808_p1 = esl_zext<64,10>(idx_27_fu_4797_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_28_fu_4832_p1() {
    tmp_5_28_fu_4832_p1 = esl_zext<64,10>(idx_28_fu_4821_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_29_fu_4856_p1() {
    tmp_5_29_fu_4856_p1 = esl_zext<64,10>(idx_29_fu_4845_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_2_fu_4374_p1() {
    tmp_5_2_fu_4374_p1 = esl_zext<64,10>(idx_1_fu_4369_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_30_fu_4880_p1() {
    tmp_5_30_fu_4880_p1 = esl_zext<64,10>(idx_30_fu_4869_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_3_fu_4384_p1() {
    tmp_5_3_fu_4384_p1 = esl_zext<64,10>(idx_2_fu_4379_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_4_fu_4394_p1() {
    tmp_5_4_fu_4394_p1 = esl_zext<64,10>(idx_3_fu_4389_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_5_fu_4404_p1() {
    tmp_5_5_fu_4404_p1 = esl_zext<64,10>(idx_4_fu_4399_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_6_fu_4414_p1() {
    tmp_5_6_fu_4414_p1 = esl_zext<64,10>(idx_5_fu_4409_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_7_fu_4424_p1() {
    tmp_5_7_fu_4424_p1 = esl_zext<64,10>(idx_6_fu_4419_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_8_fu_4434_p1() {
    tmp_5_8_fu_4434_p1 = esl_zext<64,10>(idx_7_fu_4429_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_9_fu_4444_p1() {
    tmp_5_9_fu_4444_p1 = esl_zext<64,10>(idx_8_fu_4439_p2.read());
}

void mlp_accel_8b32::thread_tmp_5_fu_4343_p1() {
    tmp_5_fu_4343_p1 = esl_zext<64,10>(tmp_fu_4335_p3.read());
}

void mlp_accel_8b32::thread_tmp_5_s_fu_4454_p1() {
    tmp_5_s_fu_4454_p1 = esl_zext<64,10>(idx_9_fu_4449_p2.read());
}

void mlp_accel_8b32::thread_tmp_60_cast_fu_10473_p1() {
    tmp_60_cast_fu_10473_p1 = esl_zext<6,5>(tmp_26_fu_10465_p3.read());
}

void mlp_accel_8b32::thread_tmp_60_fu_11219_p4() {
    tmp_60_fu_11219_p4 = tmp_25_dup_fu_11203_p2.read().range(18, 13);
}

void mlp_accel_8b32::thread_tmp_61_cast_fu_10487_p1() {
    tmp_61_cast_fu_10487_p1 = esl_zext<64,6>(tmp_28_fu_10481_p2.read());
}

void mlp_accel_8b32::thread_tmp_61_fu_10523_p1() {
    tmp_61_fu_10523_p1 = b2_mid2_fu_10449_p3.read().range(1-1, 0);
}

void mlp_accel_8b32::thread_tmp_71_fu_9495_p2() {
    tmp_71_fu_9495_p2 = (!tmp1120_cast_fu_9475_p1.read().is_01() || !tmp1135_cast_fu_9491_p1.read().is_01())? sc_lv<18>(): (sc_bigint<18>(tmp1120_cast_fu_9475_p1.read()) + sc_bigint<18>(tmp1135_cast_fu_9491_p1.read()));
}

void mlp_accel_8b32::thread_tmp_77_fu_10792_p3() {
    tmp_77_fu_10792_p3 = (!tmp_61_reg_15280.read()[0].is_01())? sc_lv<8>(): ((tmp_61_reg_15280.read()[0].to_bool())? pong_buf_0_1_81_fu_1216.read(): pong_buf_0_1_80_fu_1212.read());
}

void mlp_accel_8b32::thread_tmp_78_fu_10883_p3() {
    tmp_78_fu_10883_p3 = (!tmp_61_reg_15280.read()[0].is_01())? sc_lv<8>(): ((tmp_61_reg_15280.read()[0].to_bool())? pong_buf_0_1_103_fu_1304.read(): pong_buf_0_1_102_fu_1300.read());
}

void mlp_accel_8b32::thread_tmp_79_fu_10932_p3() {
    tmp_79_fu_10932_p3 = (!tmp_61_reg_15280.read()[0].is_01())? sc_lv<8>(): ((tmp_61_reg_15280.read()[0].to_bool())? pong_buf_0_1_115_fu_1352.read(): pong_buf_0_1_114_fu_1348.read());
}

void mlp_accel_8b32::thread_tmp_8_cast_fu_4933_p1() {
    tmp_8_cast_fu_4933_p1 = esl_zext<12,5>(b1_reg_3611.read());
}

void mlp_accel_8b32::thread_tmp_8_fu_4923_p1() {
    tmp_8_fu_4923_p1 = esl_zext<64,5>(b1_reg_3611.read());
}

void mlp_accel_8b32::thread_tmp_92_fu_9533_p4() {
    tmp_92_fu_9533_p4 = tmp_13_fu_9511_p2.read().range(19, 13);
}

void mlp_accel_8b32::thread_tmp_93_fu_9581_p3() {
    tmp_93_fu_9581_p3 = n3_reg_3634.read().range(5, 5);
}

void mlp_accel_8b32::thread_tmp_94_fu_9589_p1() {
    tmp_94_fu_9589_p1 = n3_reg_3634.read().range(5-1, 0);
}

void mlp_accel_8b32::thread_tmp_95_fu_8579_p1() {
    tmp_95_fu_8579_p1 = b5_reg_3646.read().range(2-1, 0);
}

void mlp_accel_8b32::thread_tmp_97_cast_fu_8543_p1() {
    tmp_97_cast_fu_8543_p1 = esl_zext<64,10>(tmp_36_fu_8538_p2.read());
}

void mlp_accel_8b32::thread_tmp_9_fu_5458_p4() {
    tmp_9_fu_5458_p4 = tmp_s_fu_5452_p2.read().range(22, 6);
}

void mlp_accel_8b32::thread_tmp_fu_4335_p3() {
    tmp_fu_4335_p3 = esl_concat<5,5>(ap_phi_mux_b_phi_fu_3579_p4.read(), ap_const_lv5_0);
}

void mlp_accel_8b32::thread_tmp_s_fu_5452_p2() {
    tmp_s_fu_5452_p2 = (!ap_const_lv23_20.is_01() || !acc_assign_reg_3622.read().is_01())? sc_lv<23>(): (sc_biguint<23>(ap_const_lv23_20) + sc_biguint<23>(acc_assign_reg_3622.read()));
}

void mlp_accel_8b32::thread_weights_l1_8b32_0_address0() {
    weights_l1_8b32_0_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_0_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_0_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_0_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_10_address0() {
    weights_l1_8b32_10_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_10_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_10_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_10_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_11_address0() {
    weights_l1_8b32_11_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_11_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_11_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_11_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_12_address0() {
    weights_l1_8b32_12_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_12_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_12_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_12_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_13_address0() {
    weights_l1_8b32_13_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_13_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_13_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_13_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_14_address0() {
    weights_l1_8b32_14_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_14_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_14_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_14_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_15_address0() {
    weights_l1_8b32_15_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_15_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_15_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_15_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_16_address0() {
    weights_l1_8b32_16_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_16_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_16_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_16_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_17_address0() {
    weights_l1_8b32_17_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_17_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_17_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_17_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_18_address0() {
    weights_l1_8b32_18_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_18_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_18_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_18_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_19_address0() {
    weights_l1_8b32_19_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_19_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_19_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_19_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_1_address0() {
    weights_l1_8b32_1_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_1_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_1_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_1_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_20_address0() {
    weights_l1_8b32_20_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_20_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_20_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_20_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_21_address0() {
    weights_l1_8b32_21_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_21_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_21_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_21_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_22_address0() {
    weights_l1_8b32_22_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_22_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_22_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_22_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_23_address0() {
    weights_l1_8b32_23_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_23_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_23_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_23_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_24_address0() {
    weights_l1_8b32_24_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_24_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_24_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_24_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_25_address0() {
    weights_l1_8b32_25_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_25_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_25_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_25_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_26_address0() {
    weights_l1_8b32_26_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_26_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_26_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_26_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_27_address0() {
    weights_l1_8b32_27_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_27_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_27_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_27_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_28_address0() {
    weights_l1_8b32_28_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_28_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_28_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_28_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_29_address0() {
    weights_l1_8b32_29_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_29_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_29_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_29_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_2_address0() {
    weights_l1_8b32_2_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_2_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_2_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_2_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_30_address0() {
    weights_l1_8b32_30_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_30_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_30_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_30_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_31_address0() {
    weights_l1_8b32_31_address0 =  (sc_lv<12>) (tmp_28_cast_fu_4943_p1.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_31_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()))) {
        weights_l1_8b32_31_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_31_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_3_address0() {
    weights_l1_8b32_3_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_3_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_3_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_3_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_4_address0() {
    weights_l1_8b32_4_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_4_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_4_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_4_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_5_address0() {
    weights_l1_8b32_5_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_5_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_5_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_5_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_6_address0() {
    weights_l1_8b32_6_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_6_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_6_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_6_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_7_address0() {
    weights_l1_8b32_7_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_7_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_7_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_7_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_8_address0() {
    weights_l1_8b32_8_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_8_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_8_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_8_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l1_8b32_9_address0() {
    weights_l1_8b32_9_address0 =  (sc_lv<12>) (tmp_28_cast_reg_13887.read());
}

void mlp_accel_8b32::thread_weights_l1_8b32_9_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()))) {
        weights_l1_8b32_9_ce0 = ap_const_logic_1;
    } else {
        weights_l1_8b32_9_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_0_address0() {
    weights_l2_8b32_0_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_0_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_0_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_0_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_10_address0() {
    weights_l2_8b32_10_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_10_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_10_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_10_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_11_address0() {
    weights_l2_8b32_11_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_11_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_11_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_11_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_12_address0() {
    weights_l2_8b32_12_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_12_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_12_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_12_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_13_address0() {
    weights_l2_8b32_13_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_13_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_13_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_13_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_14_address0() {
    weights_l2_8b32_14_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_14_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_14_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_14_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_15_address0() {
    weights_l2_8b32_15_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_15_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_15_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_15_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_16_address0() {
    weights_l2_8b32_16_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_16_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_16_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_16_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_17_address0() {
    weights_l2_8b32_17_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_17_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_17_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_17_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_18_address0() {
    weights_l2_8b32_18_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_18_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_18_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_18_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_19_address0() {
    weights_l2_8b32_19_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_19_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_19_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_19_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_1_address0() {
    weights_l2_8b32_1_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_1_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_1_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_1_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_20_address0() {
    weights_l2_8b32_20_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_20_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_20_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_20_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_21_address0() {
    weights_l2_8b32_21_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_21_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_21_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_21_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_22_address0() {
    weights_l2_8b32_22_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_22_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_22_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_22_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_23_address0() {
    weights_l2_8b32_23_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_23_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_23_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_23_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_24_address0() {
    weights_l2_8b32_24_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_24_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_24_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_24_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_25_address0() {
    weights_l2_8b32_25_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_25_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_25_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_25_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_26_address0() {
    weights_l2_8b32_26_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_26_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_26_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_26_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_27_address0() {
    weights_l2_8b32_27_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_27_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_27_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_27_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_28_address0() {
    weights_l2_8b32_28_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_28_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_28_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_28_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_29_address0() {
    weights_l2_8b32_29_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_29_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_29_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_29_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_2_address0() {
    weights_l2_8b32_2_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_2_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_2_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_2_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_30_address0() {
    weights_l2_8b32_30_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_30_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_30_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_30_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_31_address0() {
    weights_l2_8b32_31_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_31_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_31_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_31_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_3_address0() {
    weights_l2_8b32_3_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_3_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_3_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_3_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_4_address0() {
    weights_l2_8b32_4_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_4_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_4_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_4_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_5_address0() {
    weights_l2_8b32_5_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_5_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_5_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_5_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_6_address0() {
    weights_l2_8b32_6_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_6_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_6_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_6_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_7_address0() {
    weights_l2_8b32_7_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_7_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_7_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_7_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_8_address0() {
    weights_l2_8b32_8_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_8_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_8_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_8_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l2_8b32_9_address0() {
    weights_l2_8b32_9_address0 =  (sc_lv<8>) (tmp_97_cast_fu_8543_p1.read());
}

void mlp_accel_8b32::thread_weights_l2_8b32_9_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()))) {
        weights_l2_8b32_9_ce0 = ap_const_logic_1;
    } else {
        weights_l2_8b32_9_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_0_address0() {
    weights_l3_8b32_0_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_0_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_0_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_0_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_10_address0() {
    weights_l3_8b32_10_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_10_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_10_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_10_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_11_address0() {
    weights_l3_8b32_11_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_11_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_11_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_11_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_12_address0() {
    weights_l3_8b32_12_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_12_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_12_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_12_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_13_address0() {
    weights_l3_8b32_13_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_13_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_13_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_13_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_14_address0() {
    weights_l3_8b32_14_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_14_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_14_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_14_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_15_address0() {
    weights_l3_8b32_15_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_15_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_15_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_15_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_16_address0() {
    weights_l3_8b32_16_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_16_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_16_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_16_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_17_address0() {
    weights_l3_8b32_17_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_17_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_17_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_17_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_18_address0() {
    weights_l3_8b32_18_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_18_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_18_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_18_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_19_address0() {
    weights_l3_8b32_19_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_19_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_19_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_19_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_1_address0() {
    weights_l3_8b32_1_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_1_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_1_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_1_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_20_address0() {
    weights_l3_8b32_20_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_20_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_20_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_20_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_21_address0() {
    weights_l3_8b32_21_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_21_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_21_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_21_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_22_address0() {
    weights_l3_8b32_22_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_22_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_22_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_22_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_23_address0() {
    weights_l3_8b32_23_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_23_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_23_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_23_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_24_address0() {
    weights_l3_8b32_24_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_24_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_24_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_24_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_25_address0() {
    weights_l3_8b32_25_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_25_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_25_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_25_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_26_address0() {
    weights_l3_8b32_26_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_26_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_26_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_26_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_27_address0() {
    weights_l3_8b32_27_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_27_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_27_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_27_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_28_address0() {
    weights_l3_8b32_28_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_28_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_28_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_28_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_29_address0() {
    weights_l3_8b32_29_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_29_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_29_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_29_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_2_address0() {
    weights_l3_8b32_2_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_2_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_2_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_2_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_30_address0() {
    weights_l3_8b32_30_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_30_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_30_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_30_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_31_address0() {
    weights_l3_8b32_31_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_31_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_31_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_31_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_3_address0() {
    weights_l3_8b32_3_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_3_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_3_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_3_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_4_address0() {
    weights_l3_8b32_4_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_4_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_4_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_4_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_5_address0() {
    weights_l3_8b32_5_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_5_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_5_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_5_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_6_address0() {
    weights_l3_8b32_6_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_6_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_6_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_6_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_7_address0() {
    weights_l3_8b32_7_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_7_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_7_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_7_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_8_address0() {
    weights_l3_8b32_8_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_8_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_8_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_8_ce0 = ap_const_logic_0;
    }
}

void mlp_accel_8b32::thread_weights_l3_8b32_9_address0() {
    weights_l3_8b32_9_address0 =  (sc_lv<5>) (tmp_61_cast_fu_10487_p1.read());
}

void mlp_accel_8b32::thread_weights_l3_8b32_9_ce0() {
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()))) {
        weights_l3_8b32_9_ce0 = ap_const_logic_1;
    } else {
        weights_l3_8b32_9_ce0 = ap_const_logic_0;
    }
}

}

