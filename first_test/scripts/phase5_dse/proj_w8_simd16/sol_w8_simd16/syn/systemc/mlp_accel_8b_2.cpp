#include "mlp_accel_8b.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void mlp_accel_8b::thread_ap_clk_no_reset_() {
    if ((esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter3.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7408_pp2_iter2_reg.read()))) {
        acc_assign_1_reg_2220 = acc_1_fu_3421_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3102_p2.read()))) {
        acc_assign_1_reg_2220 = ap_const_lv20_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
         esl_seteq<1,1,1>(exitcond6_fu_3102_p2.read(), ap_const_lv1_1))) {
        acc_assign_2_reg_2266 = ap_const_lv20_0;
    } else if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter3.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7747_pp3_iter2_reg.read()))) {
        acc_assign_2_reg_2266 = acc_2_fu_5678_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter3.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_6980_pp1_iter2_reg.read()))) {
        acc_assign_reg_2185 = acc_fu_2976_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond9_fu_2666_p2.read()))) {
        acc_assign_reg_2185 = ap_const_lv23_0;
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_CS_fsm = ap_ST_fsm_state1;
    } else {
        ap_CS_fsm = ap_NS_fsm.read();
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
             esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp0_exit_iter0_state2.read()))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                    esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
            ap_enable_reg_pp0_iter0 = ap_const_logic_1;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp0_iter1 = ap_const_logic_0;
    } else {
        if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
              esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0)) || 
             (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage15.read()) && 
              esl_seteq<1,1,1>(ap_block_pp0_stage15_subdone.read(), ap_const_boolean_0)))) {
            ap_enable_reg_pp0_iter1 = ap_enable_reg_pp0_iter0.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                    esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
            ap_enable_reg_pp0_iter1 = ap_const_logic_0;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp1_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
             esl_seteq<1,1,1>(ap_block_pp1_stage0_subdone.read(), ap_const_boolean_0) && 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp1_exit_iter0_state21.read()))) {
            ap_enable_reg_pp1_iter0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read()) && 
                    esl_seteq<1,1,1>(ap_const_lv1_0, exitcond9_fu_2666_p2.read()))) {
            ap_enable_reg_pp1_iter0 = ap_const_logic_1;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp1_iter1 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp1_stage0_subdone.read(), ap_const_boolean_0)) {
            if (esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp1_exit_iter0_state21.read())) {
                ap_enable_reg_pp1_iter1 = (ap_condition_pp1_exit_iter0_state21.read() ^ ap_const_logic_1);
            } else if (esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1)) {
                ap_enable_reg_pp1_iter1 = ap_enable_reg_pp1_iter0.read();
            }
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp1_iter2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp1_stage0_subdone.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp1_iter2 = ap_enable_reg_pp1_iter1.read();
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp1_iter3 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp1_stage0_subdone.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp1_iter3 = ap_enable_reg_pp1_iter2.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read()) && 
                    esl_seteq<1,1,1>(ap_const_lv1_0, exitcond9_fu_2666_p2.read()))) {
            ap_enable_reg_pp1_iter3 = ap_const_logic_0;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp2_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
             esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && 
             esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp2_exit_iter0_state28.read()))) {
            ap_enable_reg_pp2_iter0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                    esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3102_p2.read()))) {
            ap_enable_reg_pp2_iter0 = ap_const_logic_1;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp2_iter1 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0)) {
            if (esl_seteq<1,1,1>(ap_const_logic_1, ap_condition_pp2_exit_iter0_state28.read())) {
                ap_enable_reg_pp2_iter1 = (ap_condition_pp2_exit_iter0_state28.read() ^ ap_const_logic_1);
            } else if (esl_seteq<1,1,1>(ap_const_boolean_1, ap_const_boolean_1)) {
                ap_enable_reg_pp2_iter1 = ap_enable_reg_pp2_iter0.read();
            }
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp2_iter2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp2_iter2 = ap_enable_reg_pp2_iter1.read();
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp2_iter3 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp2_iter3 = ap_enable_reg_pp2_iter2.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                    esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3102_p2.read()))) {
            ap_enable_reg_pp2_iter3 = ap_const_logic_0;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp3_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
             esl_seteq<1,1,1>(ap_block_pp3_stage0_subdone.read(), ap_const_boolean_0) && 
             esl_seteq<1,1,1>(exitcond_flatten_fu_5001_p2.read(), ap_const_lv1_1))) {
            ap_enable_reg_pp3_iter0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                    esl_seteq<1,1,1>(exitcond6_fu_3102_p2.read(), ap_const_lv1_1))) {
            ap_enable_reg_pp3_iter0 = ap_const_logic_1;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp3_iter1 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp3_stage0_subdone.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp3_iter1 = ap_enable_reg_pp3_iter0.read();
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp3_iter2 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp3_stage0_subdone.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp3_iter2 = ap_enable_reg_pp3_iter1.read();
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp3_iter3 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp3_stage0_subdone.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp3_iter3 = ap_enable_reg_pp3_iter2.read();
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp3_iter4 = ap_const_logic_0;
    } else {
        if (esl_seteq<1,1,1>(ap_block_pp3_stage0_subdone.read(), ap_const_boolean_0)) {
            ap_enable_reg_pp3_iter4 = ap_enable_reg_pp3_iter3.read();
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                    esl_seteq<1,1,1>(exitcond6_fu_3102_p2.read(), ap_const_lv1_1))) {
            ap_enable_reg_pp3_iter4 = ap_const_logic_0;
        }
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_fu_2678_p2.read()))) {
        b1_reg_2174 = b_2_fu_2684_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond9_fu_2666_p2.read()))) {
        b1_reg_2174 = ap_const_lv6_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
         esl_seteq<1,1,1>(exitcond6_fu_3102_p2.read(), ap_const_lv1_1))) {
        b2_reg_2255 = ap_const_lv3_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
                esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_5001_p2.read()))) {
        b2_reg_2255 = b_4_fu_5087_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_fu_3126_p2.read()))) {
        b5_reg_2209 = b_3_fu_3132_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3102_p2.read()))) {
        b5_reg_2209 = ap_const_lv4_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(exitcond1_reg_6455.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        b_reg_2138 = b_1_reg_6459.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        b_reg_2138 = ap_const_lv6_0;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state39.read())) {
        i_reg_2277 = ap_const_lv4_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state40.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_fu_6232_p2.read()))) {
        i_reg_2277 = i_1_fu_6238_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
         esl_seteq<1,1,1>(exitcond6_fu_3102_p2.read(), ap_const_lv1_1))) {
        indvar_flatten_reg_2232 = ap_const_lv6_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
                esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_5001_p2.read()))) {
        indvar_flatten_reg_2232 = indvar_flatten_next_fu_5007_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read()) && 
         esl_seteq<1,1,1>(exitcond9_fu_2666_p2.read(), ap_const_lv1_1))) {
        n3_reg_2197 = ap_const_lv7_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state33.read())) {
        n3_reg_2197 = n_2_reg_7328.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
         esl_seteq<1,1,1>(exitcond6_fu_3102_p2.read(), ap_const_lv1_1))) {
        n9_reg_2243 = ap_const_lv4_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
                esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7747.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()))) {
        n9_reg_2243 = tmp_11_mid2_v_reg_7771.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state19.read())) {
        n_reg_2150 = ap_const_lv8_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state26.read())) {
        n_reg_2150 = n_1_reg_6591.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state19.read())) {
        phi_mul_reg_2162 = ap_const_lv13_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state26.read())) {
        phi_mul_reg_2162 = next_mul_reg_6582.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()))) {
        b_1_reg_6459 = b_1_fu_2486_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond1_reg_6455 = exitcond1_fu_2480_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_5001_p2.read()))) {
        exitcond2_reg_7756 = exitcond2_fu_5019_p2.read();
        tmp_42_reg_7856 = tmp_42_fu_5083_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond2_reg_7756_pp3_iter1_reg = exitcond2_reg_7756.read();
        exitcond_flatten_reg_7747 = exitcond_flatten_fu_5001_p2.read();
        exitcond_flatten_reg_7747_pp3_iter1_reg = exitcond_flatten_reg_7747.read();
        n9_reg_2243_pp3_iter1_reg = n9_reg_2243.read();
        tmp_42_reg_7856_pp3_iter1_reg = tmp_42_reg_7856.read();
    }
    if (esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0)) {
        exitcond2_reg_7756_pp3_iter2_reg = exitcond2_reg_7756_pp3_iter1_reg.read();
        exitcond2_reg_7756_pp3_iter3_reg = exitcond2_reg_7756_pp3_iter2_reg.read();
        exitcond_flatten_reg_7747_pp3_iter2_reg = exitcond_flatten_reg_7747_pp3_iter1_reg.read();
        exitcond_flatten_reg_7747_pp3_iter3_reg = exitcond_flatten_reg_7747_pp3_iter2_reg.read();
        n9_reg_2243_pp3_iter2_reg = n9_reg_2243_pp3_iter1_reg.read();
        out_buf_9_64_reg_8021 = out_buf_9_64_fu_5571_p3.read();
        sel_tmp10_dup_reg_8075 = sel_tmp10_dup_fu_5609_p2.read();
        sel_tmp12_dup_reg_8086 = sel_tmp12_dup_fu_5615_p2.read();
        sel_tmp14_dup_reg_8098 = sel_tmp14_dup_fu_5621_p2.read();
        sel_tmp16_dup_reg_8111 = sel_tmp16_dup_fu_5627_p2.read();
        sel_tmp2_dup_reg_8041 = sel_tmp2_dup_fu_5585_p2.read();
        sel_tmp4_dup_reg_8048 = sel_tmp4_dup_fu_5591_p2.read();
        sel_tmp6_dup_reg_8056 = sel_tmp6_dup_fu_5597_p2.read();
        sel_tmp8_dup_reg_8065 = sel_tmp8_dup_fu_5603_p2.read();
        sel_tmp_dup_reg_8035 = sel_tmp_dup_fu_5579_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond5_reg_7408 = exitcond5_fu_3126_p2.read();
        exitcond5_reg_7408_pp2_iter1_reg = exitcond5_reg_7408.read();
    }
    if (esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0)) {
        exitcond5_reg_7408_pp2_iter2_reg = exitcond5_reg_7408_pp2_iter1_reg.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond8_reg_6980 = exitcond8_fu_2678_p2.read();
        exitcond8_reg_6980_pp1_iter1_reg = exitcond8_reg_6980.read();
    }
    if (esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0)) {
        exitcond8_reg_6980_pp1_iter2_reg = exitcond8_reg_6980_pp1_iter1_reg.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_6980.read()))) {
        input_buf_0_load_reg_7121 = input_buf_0_q0.read();
        input_buf_11_load_reg_7221 = input_buf_11_q0.read();
        input_buf_13_load_reg_7241 = input_buf_13_q0.read();
        input_buf_14_load_reg_7251 = input_buf_14_q0.read();
        input_buf_2_load_reg_7141 = input_buf_2_q0.read();
        input_buf_6_load_reg_7171 = input_buf_6_q0.read();
        input_buf_9_load_reg_7201 = input_buf_9_q0.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read())) {
        n_1_reg_6591 = n_1_fu_2672_p2.read();
        next_mul_reg_6582 = next_mul_fu_2660_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read())) {
        n_2_reg_7328 = n_2_fu_3108_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter4.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7747_pp3_iter3_reg.read()))) {
        out_buf_8_s_fu_736 = out_buf_8_mid2_fu_6119_p3.read();
        out_buf_9_1_fu_732 = out_buf_9_18_mid2_fu_6126_p3.read();
        out_buf_9_2_fu_728 = out_buf_9_27_mid2_fu_6133_p3.read();
        out_buf_9_3_fu_724 = out_buf_9_35_mid2_fu_6140_p3.read();
        out_buf_9_4_fu_720 = out_buf_9_42_mid2_fu_6147_p3.read();
        out_buf_9_5_fu_716 = out_buf_9_48_mid2_fu_6154_p3.read();
        out_buf_9_6_fu_712 = out_buf_9_53_mid2_fu_6161_p3.read();
        out_buf_9_7_fu_708 = out_buf_9_57_mid2_fu_6168_p3.read();
        out_buf_9_8_fu_704 = out_buf_9_60_mid2_fu_6175_p3.read();
        out_buf_9_s_fu_740 = out_buf_9_mid2_fu_6112_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter4.read()))) {
        out_buf_9_16_reg_8130 = out_buf_9_16_fu_5769_p3.read();
        out_buf_9_25_reg_8135 = out_buf_9_25_fu_5831_p3.read();
        out_buf_9_33_reg_8140 = out_buf_9_33_fu_5886_p3.read();
        out_buf_9_40_reg_8145 = out_buf_9_40_fu_5934_p3.read();
        out_buf_9_46_reg_8150 = out_buf_9_46_fu_5975_p3.read();
        out_buf_9_51_reg_8155 = out_buf_9_51_fu_6009_p3.read();
        out_buf_9_55_reg_8160 = out_buf_9_55_fu_6036_p3.read();
        out_buf_9_58_reg_8165 = out_buf_9_58_fu_6056_p3.read();
        out_buf_9_60_reg_8170 = out_buf_9_60_fu_6069_p3.read();
        out_buf_9_61_reg_8175 = out_buf_9_61_fu_6076_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7408.read()))) {
        ping_buf_0_load_reg_7549 = ping_buf_0_q0.read();
        ping_buf_10_load_reg_7639 = ping_buf_10_q0.read();
        ping_buf_14_load_reg_7669 = ping_buf_14_q0.read();
        ping_buf_2_load_reg_7569 = ping_buf_2_q0.read();
        ping_buf_5_load_reg_7599 = ping_buf_5_q0.read();
        ping_buf_8_load_reg_7619 = ping_buf_8_q0.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_8))) {
        pong_buf_15_3_106_fu_580 = pong_buf_15_3_289_fu_4137_p3.read();
        pong_buf_15_3_109_fu_576 = pong_buf_15_3_290_fu_4145_p3.read();
        pong_buf_15_3_192_fu_584 = pong_buf_15_3_287_fu_4121_p3.read();
        pong_buf_15_3_193_fu_588 = pong_buf_15_3_284_fu_4097_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_F))) {
        pong_buf_15_3_10_fu_688 = pong_buf_15_3_209_fu_4973_p3.read();
        pong_buf_15_3_206_fu_696 = pong_buf_15_3_6_fu_4949_p3.read();
        pong_buf_15_3_207_fu_700 = pong_buf_15_3_2_fu_4925_p3.read();
        pong_buf_15_3_7_fu_692 = pong_buf_15_3_9_fu_4965_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_9))) {
        pong_buf_15_3_117_fu_596 = pong_buf_15_3_298_fu_4045_p3.read();
        pong_buf_15_3_120_fu_592 = pong_buf_15_3_299_fu_4053_p3.read();
        pong_buf_15_3_194_fu_600 = pong_buf_15_3_296_fu_4029_p3.read();
        pong_buf_15_3_195_fu_604 = pong_buf_15_3_293_fu_4005_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_A))) {
        pong_buf_15_3_128_fu_612 = pong_buf_15_3_307_fu_3953_p3.read();
        pong_buf_15_3_131_fu_608 = pong_buf_15_3_308_fu_3961_p3.read();
        pong_buf_15_3_196_fu_616 = pong_buf_15_3_305_fu_3937_p3.read();
        pong_buf_15_3_197_fu_620 = pong_buf_15_3_302_fu_3913_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_B))) {
        pong_buf_15_3_139_fu_628 = pong_buf_15_3_316_fu_3861_p3.read();
        pong_buf_15_3_142_fu_624 = pong_buf_15_3_317_fu_3869_p3.read();
        pong_buf_15_3_198_fu_632 = pong_buf_15_3_314_fu_3845_p3.read();
        pong_buf_15_3_199_fu_636 = pong_buf_15_3_311_fu_3821_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_C))) {
        pong_buf_15_3_150_fu_644 = pong_buf_15_3_325_fu_3769_p3.read();
        pong_buf_15_3_153_fu_640 = pong_buf_15_3_326_fu_3777_p3.read();
        pong_buf_15_3_200_fu_648 = pong_buf_15_3_323_fu_3753_p3.read();
        pong_buf_15_3_201_fu_652 = pong_buf_15_3_320_fu_3729_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_D))) {
        pong_buf_15_3_161_fu_660 = pong_buf_15_3_334_fu_3677_p3.read();
        pong_buf_15_3_164_fu_656 = pong_buf_15_3_335_fu_3685_p3.read();
        pong_buf_15_3_202_fu_664 = pong_buf_15_3_332_fu_3661_p3.read();
        pong_buf_15_3_203_fu_668 = pong_buf_15_3_329_fu_3637_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_E))) {
        pong_buf_15_3_172_fu_676 = pong_buf_15_3_343_fu_3585_p3.read();
        pong_buf_15_3_175_fu_672 = pong_buf_15_3_344_fu_3593_p3.read();
        pong_buf_15_3_204_fu_680 = pong_buf_15_3_341_fu_3569_p3.read();
        pong_buf_15_3_205_fu_684 = pong_buf_15_3_338_fu_3545_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(ap_const_lv4_0, tmp_73_fu_3507_p1.read()))) {
        pong_buf_15_3_177_fu_460 = pong_buf_15_3_212_fu_4833_p3.read();
        pong_buf_15_3_18_fu_452 = pong_buf_15_3_217_fu_4873_p3.read();
        pong_buf_15_3_1_fu_448 = pong_buf_15_3_218_fu_4881_p3.read();
        pong_buf_15_3_21_fu_456 = pong_buf_15_3_215_fu_4857_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_1))) {
        pong_buf_15_3_178_fu_472 = pong_buf_15_3_224_fu_4765_p3.read();
        pong_buf_15_3_179_fu_476 = pong_buf_15_3_221_fu_4741_p3.read();
        pong_buf_15_3_29_fu_468 = pong_buf_15_3_226_fu_4781_p3.read();
        pong_buf_15_3_32_fu_464 = pong_buf_15_3_227_fu_4789_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_2))) {
        pong_buf_15_3_180_fu_488 = pong_buf_15_3_233_fu_4673_p3.read();
        pong_buf_15_3_181_fu_492 = pong_buf_15_3_230_fu_4649_p3.read();
        pong_buf_15_3_40_fu_484 = pong_buf_15_3_235_fu_4689_p3.read();
        pong_buf_15_3_43_fu_480 = pong_buf_15_3_236_fu_4697_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_3))) {
        pong_buf_15_3_182_fu_504 = pong_buf_15_3_242_fu_4581_p3.read();
        pong_buf_15_3_183_fu_508 = pong_buf_15_3_239_fu_4557_p3.read();
        pong_buf_15_3_51_fu_500 = pong_buf_15_3_244_fu_4597_p3.read();
        pong_buf_15_3_54_fu_496 = pong_buf_15_3_245_fu_4605_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_4))) {
        pong_buf_15_3_184_fu_520 = pong_buf_15_3_251_fu_4489_p3.read();
        pong_buf_15_3_185_fu_524 = pong_buf_15_3_248_fu_4465_p3.read();
        pong_buf_15_3_62_fu_516 = pong_buf_15_3_253_fu_4505_p3.read();
        pong_buf_15_3_65_fu_512 = pong_buf_15_3_254_fu_4513_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_5))) {
        pong_buf_15_3_186_fu_536 = pong_buf_15_3_260_fu_4397_p3.read();
        pong_buf_15_3_187_fu_540 = pong_buf_15_3_257_fu_4373_p3.read();
        pong_buf_15_3_73_fu_532 = pong_buf_15_3_262_fu_4413_p3.read();
        pong_buf_15_3_76_fu_528 = pong_buf_15_3_263_fu_4421_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_6))) {
        pong_buf_15_3_188_fu_552 = pong_buf_15_3_269_fu_4305_p3.read();
        pong_buf_15_3_189_fu_556 = pong_buf_15_3_266_fu_4281_p3.read();
        pong_buf_15_3_84_fu_548 = pong_buf_15_3_271_fu_4321_p3.read();
        pong_buf_15_3_87_fu_544 = pong_buf_15_3_272_fu_4329_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_73_fu_3507_p1.read(), ap_const_lv4_7))) {
        pong_buf_15_3_190_fu_568 = pong_buf_15_3_278_fu_4213_p3.read();
        pong_buf_15_3_191_fu_572 = pong_buf_15_3_275_fu_4189_p3.read();
        pong_buf_15_3_95_fu_564 = pong_buf_15_3_280_fu_4229_p3.read();
        pong_buf_15_3_98_fu_560 = pong_buf_15_3_281_fu_4237_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter2.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_6980_pp1_iter1_reg.read()))) {
        tmp19_reg_7276 = grp_fu_6282_p3.read();
        tmp20_reg_7281 = grp_fu_6289_p3.read();
        tmp22_reg_7286 = grp_fu_6274_p3.read();
        tmp23_reg_7291 = grp_fu_6266_p3.read();
        tmp26_reg_7296 = grp_fu_6305_p3.read();
        tmp27_reg_7301 = grp_fu_6297_p3.read();
        tmp29_reg_7306 = grp_fu_6321_p3.read();
        tmp30_reg_7311 = grp_fu_6313_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7747_pp3_iter1_reg.read()))) {
        tmp49_reg_8001 = tmp49_fu_5491_p2.read();
        tmp69_reg_8016 = tmp69_fu_5503_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7747_pp3_iter1_reg.read()) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter2.read()))) {
        tmp50_reg_8006 = grp_fu_6431_p3.read();
        tmp65_reg_8011 = grp_fu_6423_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter2.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7408_pp2_iter1_reg.read()))) {
        tmp51_reg_7699 = grp_fu_6345_p3.read();
        tmp52_reg_7704 = grp_fu_6353_p3.read();
        tmp54_reg_7709 = grp_fu_6337_p3.read();
        tmp55_reg_7714 = grp_fu_6329_p3.read();
        tmp58_reg_7719 = grp_fu_6368_p3.read();
        tmp59_reg_7724 = grp_fu_6360_p3.read();
        tmp61_reg_7729 = grp_fu_6383_p3.read();
        tmp62_reg_7734 = grp_fu_6376_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_5001_p2.read()))) {
        tmp_11_mid2_v_reg_7771 = tmp_11_mid2_v_fu_5033_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_fu_3126_p2.read()))) {
        tmp_14_reg_7417 = tmp_14_fu_3138_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3102_p2.read()))) {
        tmp_17_cast_reg_7333 = tmp_17_cast_fu_3122_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond1_reg_6455.read(), ap_const_lv1_0))) {
        tmp_1_reg_6488 = tmp_1_fu_2505_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7747.read()))) {
        tmp_29_reg_7881 = tmp_29_fu_5106_p6.read();
        tmp_35_reg_7891 = tmp_35_fu_5132_p6.read();
        tmp_37_reg_7971 = tmp_37_fu_5283_p2.read();
        tmp_38_reg_7901 = tmp_38_fu_5158_p6.read();
        tmp_40_reg_7911 = tmp_40_fu_5184_p6.read();
        tmp_43_reg_7921 = tmp_43_fu_5197_p6.read();
        tmp_45_reg_7936 = tmp_45_fu_5210_p6.read();
        tmp_53_reg_7951 = tmp_53_fu_5236_p6.read();
        tmp_54_11_reg_7991 = tmp_54_11_fu_5339_p2.read();
        tmp_54_13_reg_7996 = tmp_54_13_fu_5353_p2.read();
        tmp_54_2_reg_7976 = tmp_54_2_fu_5297_p2.read();
        tmp_54_4_reg_7981 = tmp_54_4_fu_5311_p2.read();
        tmp_54_6_reg_7986 = tmp_54_6_fu_5325_p2.read();
        tmp_55_reg_7961 = tmp_55_fu_5262_p6.read();
        weights_l3_8b_10_loa_reg_7941 = weights_l3_8b_10_q0.read();
        weights_l3_8b_11_loa_reg_7946 = weights_l3_8b_11_q0.read();
        weights_l3_8b_13_loa_reg_7956 = weights_l3_8b_13_q0.read();
        weights_l3_8b_15_loa_reg_7966 = weights_l3_8b_15_q0.read();
        weights_l3_8b_1_load_reg_7886 = weights_l3_8b_1_q0.read();
        weights_l3_8b_3_load_reg_7896 = weights_l3_8b_3_q0.read();
        weights_l3_8b_5_load_reg_7906 = weights_l3_8b_5_q0.read();
        weights_l3_8b_7_load_reg_7916 = weights_l3_8b_7_q0.read();
        weights_l3_8b_8_load_reg_7926 = weights_l3_8b_8_q0.read();
        weights_l3_8b_9_load_reg_7931 = weights_l3_8b_9_q0.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_6980.read()))) {
        tmp_36_5_reg_7271 = tmp_36_5_fu_2740_p2.read();
        weights_l1_8b_0_load_reg_7126 = weights_l1_8b_0_q0.read();
        weights_l1_8b_10_loa_reg_7216 = weights_l1_8b_10_q0.read();
        weights_l1_8b_11_loa_reg_7226 = weights_l1_8b_11_q0.read();
        weights_l1_8b_12_loa_reg_7236 = weights_l1_8b_12_q0.read();
        weights_l1_8b_13_loa_reg_7246 = weights_l1_8b_13_q0.read();
        weights_l1_8b_14_loa_reg_7256 = weights_l1_8b_14_q0.read();
        weights_l1_8b_15_loa_reg_7266 = weights_l1_8b_15_q0.read();
        weights_l1_8b_1_load_reg_7136 = weights_l1_8b_1_q0.read();
        weights_l1_8b_2_load_reg_7146 = weights_l1_8b_2_q0.read();
        weights_l1_8b_3_load_reg_7156 = weights_l1_8b_3_q0.read();
        weights_l1_8b_4_load_reg_7166 = weights_l1_8b_4_q0.read();
        weights_l1_8b_6_load_reg_7176 = weights_l1_8b_6_q0.read();
        weights_l1_8b_7_load_reg_7186 = weights_l1_8b_7_q0.read();
        weights_l1_8b_8_load_reg_7196 = weights_l1_8b_8_q0.read();
        weights_l1_8b_9_load_reg_7206 = weights_l1_8b_9_q0.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_fu_2678_p2.read()))) {
        tmp_3_reg_6989 = tmp_3_fu_2690_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7408.read()))) {
        tmp_44_11_reg_7694 = tmp_44_11_fu_3201_p2.read();
        tmp_44_6_reg_7689 = tmp_44_6_fu_3187_p2.read();
        weights_l2_8b_0_load_reg_7554 = weights_l2_8b_0_q0.read();
        weights_l2_8b_10_loa_reg_7644 = weights_l2_8b_10_q0.read();
        weights_l2_8b_11_loa_reg_7654 = weights_l2_8b_11_q0.read();
        weights_l2_8b_13_loa_reg_7664 = weights_l2_8b_13_q0.read();
        weights_l2_8b_14_loa_reg_7674 = weights_l2_8b_14_q0.read();
        weights_l2_8b_15_loa_reg_7684 = weights_l2_8b_15_q0.read();
        weights_l2_8b_1_load_reg_7564 = weights_l2_8b_1_q0.read();
        weights_l2_8b_2_load_reg_7574 = weights_l2_8b_2_q0.read();
        weights_l2_8b_3_load_reg_7584 = weights_l2_8b_3_q0.read();
        weights_l2_8b_4_load_reg_7594 = weights_l2_8b_4_q0.read();
        weights_l2_8b_5_load_reg_7604 = weights_l2_8b_5_q0.read();
        weights_l2_8b_7_load_reg_7614 = weights_l2_8b_7_q0.read();
        weights_l2_8b_8_load_reg_7624 = weights_l2_8b_8_q0.read();
        weights_l2_8b_9_load_reg_7634 = weights_l2_8b_9_q0.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond1_fu_2480_p2.read(), ap_const_lv1_0))) {
        tmp_reg_6464 = tmp_fu_2492_p3.read();
    }
}

void mlp_accel_8b::thread_ap_NS_fsm() {
    switch (ap_CS_fsm.read().to_uint64()) {
        case 1 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else {
                ap_NS_fsm = ap_ST_fsm_state1;
            }
            break;
        case 2 : 
            if ((esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond1_fu_2480_p2.read(), ap_const_lv1_1)))) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond1_fu_2480_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state19;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            }
            break;
        case 4 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage1_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage1;
            }
            break;
        case 8 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage2_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage3;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage2;
            }
            break;
        case 16 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage3_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage4;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage3;
            }
            break;
        case 32 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage4_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage5;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage4;
            }
            break;
        case 64 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage5_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage6;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage5;
            }
            break;
        case 128 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage6_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage7;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage6;
            }
            break;
        case 256 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage7_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage8;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage7;
            }
            break;
        case 512 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage8_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage9;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage8;
            }
            break;
        case 1024 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage9_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage10;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage9;
            }
            break;
        case 2048 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage10_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage11;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage10;
            }
            break;
        case 4096 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage11_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage12;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage11;
            }
            break;
        case 8192 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage12_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage13;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage12;
            }
            break;
        case 16384 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage13_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage14;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage13;
            }
            break;
        case 32768 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage14_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage15;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage14;
            }
            break;
        case 65536 : 
            if (esl_seteq<1,1,1>(ap_block_pp0_stage15_subdone.read(), ap_const_boolean_0)) {
                ap_NS_fsm = ap_ST_fsm_pp0_stage0;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp0_stage15;
            }
            break;
        case 131072 : 
            ap_NS_fsm = ap_ST_fsm_state20;
            break;
        case 262144 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read()) && esl_seteq<1,1,1>(exitcond9_fu_2666_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_state27;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp1_stage0;
            }
            break;
        case 524288 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter3.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_enable_reg_pp1_iter2.read(), ap_const_logic_0)) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond8_fu_2678_p2.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_enable_reg_pp1_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_pp1_stage0;
            } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter3.read()) && 
  esl_seteq<1,1,1>(ap_block_pp1_stage0_subdone.read(), ap_const_boolean_0) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp1_iter2.read(), ap_const_logic_0)) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter0.read()) && 
  esl_seteq<1,1,1>(ap_block_pp1_stage0_subdone.read(), ap_const_boolean_0) && 
  esl_seteq<1,1,1>(exitcond8_fu_2678_p2.read(), ap_const_lv1_1) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp1_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_state25;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp1_stage0;
            }
            break;
        case 1048576 : 
            ap_NS_fsm = ap_ST_fsm_state26;
            break;
        case 2097152 : 
            ap_NS_fsm = ap_ST_fsm_state20;
            break;
        case 4194304 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && esl_seteq<1,1,1>(exitcond6_fu_3102_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_pp3_stage0;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp2_stage0;
            }
            break;
        case 8388608 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter3.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_enable_reg_pp2_iter2.read(), ap_const_logic_0)) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond5_fu_3126_p2.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_enable_reg_pp2_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_pp2_stage0;
            } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter3.read()) && 
  esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp2_iter2.read(), ap_const_logic_0)) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && 
  esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && 
  esl_seteq<1,1,1>(exitcond5_fu_3126_p2.read(), ap_const_lv1_1) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp2_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_state32;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp2_stage0;
            }
            break;
        case 16777216 : 
            ap_NS_fsm = ap_ST_fsm_state33;
            break;
        case 33554432 : 
            ap_NS_fsm = ap_ST_fsm_state27;
            break;
        case 67108864 : 
            if (!(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter4.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_enable_reg_pp3_iter3.read(), ap_const_logic_0))) {
                ap_NS_fsm = ap_ST_fsm_pp3_stage0;
            } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter4.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_enable_reg_pp3_iter3.read(), ap_const_logic_0))) {
                ap_NS_fsm = ap_ST_fsm_state39;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp3_stage0;
            }
            break;
        case 134217728 : 
            ap_NS_fsm = ap_ST_fsm_state40;
            break;
        case 268435456 : 
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state40.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_fu_6232_p2.read()))) {
                ap_NS_fsm = ap_ST_fsm_state40;
            } else {
                ap_NS_fsm = ap_ST_fsm_state41;
            }
            break;
        case 536870912 : 
            ap_NS_fsm = ap_ST_fsm_state1;
            break;
        default : 
            ap_NS_fsm =  (sc_lv<30>) ("XXXXXXXXXXXXXXXXXXXXXXXXXXXXXX");
            break;
    }
}

}

