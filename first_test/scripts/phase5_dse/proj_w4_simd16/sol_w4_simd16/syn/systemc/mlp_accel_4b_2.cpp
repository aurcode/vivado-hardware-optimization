#include "mlp_accel_4b.h"
#include "AESL_pkg.h"

using namespace std;

namespace ap_rtl {

void mlp_accel_4b::thread_ap_clk_no_reset_() {
    if ((esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter3.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7486_pp2_iter2_reg.read()))) {
        acc_assign_1_reg_2220 = acc_1_fu_3454_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3136_p2.read()))) {
        acc_assign_1_reg_2220 = ap_const_lv16_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
         esl_seteq<1,1,1>(exitcond6_fu_3136_p2.read(), ap_const_lv1_1))) {
        acc_assign_2_reg_2266 = ap_const_lv16_0;
    } else if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter3.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7818_pp3_iter2_reg.read()))) {
        acc_assign_2_reg_2266 = acc_2_fu_5743_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter3.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_7053_pp1_iter2_reg.read()))) {
        acc_assign_reg_2185 = acc_fu_3006_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond9_fu_2666_p2.read()))) {
        acc_assign_reg_2185 = ap_const_lv16_0;
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
                    esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3136_p2.read()))) {
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
                    esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3136_p2.read()))) {
            ap_enable_reg_pp2_iter3 = ap_const_logic_0;
        }
    }
    if ( ap_rst_n_inv.read() == ap_const_logic_1) {
        ap_enable_reg_pp3_iter0 = ap_const_logic_0;
    } else {
        if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
             esl_seteq<1,1,1>(ap_block_pp3_stage0_subdone.read(), ap_const_boolean_0) && 
             esl_seteq<1,1,1>(exitcond_flatten_fu_5038_p2.read(), ap_const_lv1_1))) {
            ap_enable_reg_pp3_iter0 = ap_const_logic_0;
        } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                    esl_seteq<1,1,1>(exitcond6_fu_3136_p2.read(), ap_const_lv1_1))) {
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
                    esl_seteq<1,1,1>(exitcond6_fu_3136_p2.read(), ap_const_lv1_1))) {
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
         esl_seteq<1,1,1>(exitcond6_fu_3136_p2.read(), ap_const_lv1_1))) {
        b2_reg_2255 = ap_const_lv3_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
                esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_5038_p2.read()))) {
        b2_reg_2255 = b_4_fu_5124_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && 
         esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_fu_3160_p2.read()))) {
        b5_reg_2209 = b_3_fu_3166_p2.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3136_p2.read()))) {
        b5_reg_2209 = ap_const_lv4_0;
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && 
         esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && 
         esl_seteq<1,1,1>(exitcond1_reg_6528.read(), ap_const_lv1_0) && 
         esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter1.read()))) {
        b_reg_2138 = b_1_reg_6532.read();
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state1.read()) && 
                esl_seteq<1,1,1>(ap_start.read(), ap_const_logic_1))) {
        b_reg_2138 = ap_const_lv6_0;
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state39.read())) {
        i_reg_2277 = ap_const_lv4_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state40.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_fu_6297_p2.read()))) {
        i_reg_2277 = i_1_fu_6303_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
         esl_seteq<1,1,1>(exitcond6_fu_3136_p2.read(), ap_const_lv1_1))) {
        indvar_flatten_reg_2232 = ap_const_lv6_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
                esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_5038_p2.read()))) {
        indvar_flatten_reg_2232 = indvar_flatten_next_fu_5044_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read()) && 
         esl_seteq<1,1,1>(exitcond9_fu_2666_p2.read(), ap_const_lv1_1))) {
        n3_reg_2197 = ap_const_lv7_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state33.read())) {
        n3_reg_2197 = n_2_reg_7406.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && 
         esl_seteq<1,1,1>(exitcond6_fu_3136_p2.read(), ap_const_lv1_1))) {
        n9_reg_2243 = ap_const_lv4_0;
    } else if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && 
                esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && 
                esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7818.read()) && 
                esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter1.read()))) {
        n9_reg_2243 = tmp_13_mid2_v_reg_7842.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state19.read())) {
        n_reg_2150 = ap_const_lv8_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state26.read())) {
        n_reg_2150 = n_1_reg_6664.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state19.read())) {
        phi_mul_reg_2162 = ap_const_lv13_0;
    } else if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state26.read())) {
        phi_mul_reg_2162 = next_mul_reg_6655.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp0_iter0.read()))) {
        b_1_reg_6532 = b_1_fu_2486_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond1_reg_6528 = exitcond1_fu_2480_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_5038_p2.read()))) {
        exitcond2_reg_7827 = exitcond2_fu_5056_p2.read();
        tmp_33_reg_7927 = tmp_33_fu_5120_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond2_reg_7827_pp3_iter1_reg = exitcond2_reg_7827.read();
        exitcond_flatten_reg_7818 = exitcond_flatten_fu_5038_p2.read();
        exitcond_flatten_reg_7818_pp3_iter1_reg = exitcond_flatten_reg_7818.read();
        n9_reg_2243_pp3_iter1_reg = n9_reg_2243.read();
    }
    if (esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0)) {
        exitcond2_reg_7827_pp3_iter2_reg = exitcond2_reg_7827_pp3_iter1_reg.read();
        exitcond2_reg_7827_pp3_iter3_reg = exitcond2_reg_7827_pp3_iter2_reg.read();
        exitcond_flatten_reg_7818_pp3_iter2_reg = exitcond_flatten_reg_7818_pp3_iter1_reg.read();
        exitcond_flatten_reg_7818_pp3_iter3_reg = exitcond_flatten_reg_7818_pp3_iter2_reg.read();
        n9_reg_2243_pp3_iter2_reg = n9_reg_2243_pp3_iter1_reg.read();
        out_buf_9_64_reg_8077 = out_buf_9_64_fu_5671_p3.read();
        sel_tmp10_dup_reg_8131 = sel_tmp10_dup_fu_5709_p2.read();
        sel_tmp12_dup_reg_8142 = sel_tmp12_dup_fu_5715_p2.read();
        sel_tmp14_dup_reg_8154 = sel_tmp14_dup_fu_5721_p2.read();
        sel_tmp16_dup_reg_8167 = sel_tmp16_dup_fu_5727_p2.read();
        sel_tmp2_dup_reg_8097 = sel_tmp2_dup_fu_5685_p2.read();
        sel_tmp4_dup_reg_8104 = sel_tmp4_dup_fu_5691_p2.read();
        sel_tmp6_dup_reg_8112 = sel_tmp6_dup_fu_5697_p2.read();
        sel_tmp8_dup_reg_8121 = sel_tmp8_dup_fu_5703_p2.read();
        sel_tmp_dup_reg_8091 = sel_tmp_dup_fu_5679_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond5_reg_7486 = exitcond5_fu_3160_p2.read();
        exitcond5_reg_7486_pp2_iter1_reg = exitcond5_reg_7486.read();
    }
    if (esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0)) {
        exitcond5_reg_7486_pp2_iter2_reg = exitcond5_reg_7486_pp2_iter1_reg.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0))) {
        exitcond8_reg_7053 = exitcond8_fu_2678_p2.read();
        exitcond8_reg_7053_pp1_iter1_reg = exitcond8_reg_7053.read();
    }
    if (esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0)) {
        exitcond8_reg_7053_pp1_iter2_reg = exitcond8_reg_7053_pp1_iter1_reg.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_7053.read()))) {
        input_buf_0_load_reg_7194 = input_buf_0_q0.read();
        input_buf_10_load_reg_7294 = input_buf_10_q0.read();
        input_buf_12_load_reg_7314 = input_buf_12_q0.read();
        input_buf_14_load_reg_7334 = input_buf_14_q0.read();
        input_buf_2_load_reg_7214 = input_buf_2_q0.read();
        input_buf_5_load_reg_7244 = input_buf_5_q0.read();
        input_buf_6_load_reg_7254 = input_buf_6_q0.read();
        input_buf_8_load_reg_7274 = input_buf_8_q0.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state20.read())) {
        n_1_reg_6664 = n_1_fu_2672_p2.read();
        next_mul_reg_6655 = next_mul_fu_2660_p2.read();
    }
    if (esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read())) {
        n_2_reg_7406 = n_2_fu_3142_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter4.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7818_pp3_iter3_reg.read()))) {
        out_buf_8_s_fu_736 = out_buf_8_mid2_fu_6184_p3.read();
        out_buf_9_1_fu_732 = out_buf_9_18_mid2_fu_6191_p3.read();
        out_buf_9_2_fu_728 = out_buf_9_27_mid2_fu_6198_p3.read();
        out_buf_9_3_fu_724 = out_buf_9_35_mid2_fu_6205_p3.read();
        out_buf_9_4_fu_720 = out_buf_9_42_mid2_fu_6212_p3.read();
        out_buf_9_5_fu_716 = out_buf_9_48_mid2_fu_6219_p3.read();
        out_buf_9_6_fu_712 = out_buf_9_53_mid2_fu_6226_p3.read();
        out_buf_9_7_fu_708 = out_buf_9_57_mid2_fu_6233_p3.read();
        out_buf_9_8_fu_704 = out_buf_9_60_mid2_fu_6240_p3.read();
        out_buf_9_s_fu_740 = out_buf_9_mid2_fu_6177_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter4.read()))) {
        out_buf_9_16_reg_8186 = out_buf_9_16_fu_5834_p3.read();
        out_buf_9_25_reg_8191 = out_buf_9_25_fu_5896_p3.read();
        out_buf_9_33_reg_8196 = out_buf_9_33_fu_5951_p3.read();
        out_buf_9_40_reg_8201 = out_buf_9_40_fu_5999_p3.read();
        out_buf_9_46_reg_8206 = out_buf_9_46_fu_6040_p3.read();
        out_buf_9_51_reg_8211 = out_buf_9_51_fu_6074_p3.read();
        out_buf_9_55_reg_8216 = out_buf_9_55_fu_6101_p3.read();
        out_buf_9_58_reg_8221 = out_buf_9_58_fu_6121_p3.read();
        out_buf_9_60_reg_8226 = out_buf_9_60_fu_6134_p3.read();
        out_buf_9_61_reg_8231 = out_buf_9_61_fu_6141_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter1.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7486.read()))) {
        ping_buf_0_load_reg_7635 = ping_buf_0_q0.read();
        ping_buf_11_load_reg_7705 = ping_buf_11_q0.read();
        ping_buf_12_load_reg_7715 = ping_buf_12_q0.read();
        ping_buf_14_load_reg_7735 = ping_buf_14_q0.read();
        ping_buf_6_load_reg_7675 = ping_buf_6_q0.read();
        ping_buf_9_load_reg_7695 = ping_buf_9_q0.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_8))) {
        pong_buf_15_3_106_fu_580 = pong_buf_15_3_289_fu_4174_p3.read();
        pong_buf_15_3_109_fu_576 = pong_buf_15_3_290_fu_4182_p3.read();
        pong_buf_15_3_192_fu_584 = pong_buf_15_3_287_fu_4158_p3.read();
        pong_buf_15_3_193_fu_588 = pong_buf_15_3_284_fu_4134_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_F))) {
        pong_buf_15_3_10_fu_688 = pong_buf_15_3_209_fu_5010_p3.read();
        pong_buf_15_3_206_fu_696 = pong_buf_15_3_6_fu_4986_p3.read();
        pong_buf_15_3_207_fu_700 = pong_buf_15_3_2_fu_4962_p3.read();
        pong_buf_15_3_7_fu_692 = pong_buf_15_3_9_fu_5002_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_9))) {
        pong_buf_15_3_117_fu_596 = pong_buf_15_3_298_fu_4082_p3.read();
        pong_buf_15_3_120_fu_592 = pong_buf_15_3_299_fu_4090_p3.read();
        pong_buf_15_3_194_fu_600 = pong_buf_15_3_296_fu_4066_p3.read();
        pong_buf_15_3_195_fu_604 = pong_buf_15_3_293_fu_4042_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_A))) {
        pong_buf_15_3_128_fu_612 = pong_buf_15_3_307_fu_3990_p3.read();
        pong_buf_15_3_131_fu_608 = pong_buf_15_3_308_fu_3998_p3.read();
        pong_buf_15_3_196_fu_616 = pong_buf_15_3_305_fu_3974_p3.read();
        pong_buf_15_3_197_fu_620 = pong_buf_15_3_302_fu_3950_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_B))) {
        pong_buf_15_3_139_fu_628 = pong_buf_15_3_316_fu_3898_p3.read();
        pong_buf_15_3_142_fu_624 = pong_buf_15_3_317_fu_3906_p3.read();
        pong_buf_15_3_198_fu_632 = pong_buf_15_3_314_fu_3882_p3.read();
        pong_buf_15_3_199_fu_636 = pong_buf_15_3_311_fu_3858_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_C))) {
        pong_buf_15_3_150_fu_644 = pong_buf_15_3_325_fu_3806_p3.read();
        pong_buf_15_3_153_fu_640 = pong_buf_15_3_326_fu_3814_p3.read();
        pong_buf_15_3_200_fu_648 = pong_buf_15_3_323_fu_3790_p3.read();
        pong_buf_15_3_201_fu_652 = pong_buf_15_3_320_fu_3766_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_D))) {
        pong_buf_15_3_161_fu_660 = pong_buf_15_3_334_fu_3714_p3.read();
        pong_buf_15_3_164_fu_656 = pong_buf_15_3_335_fu_3722_p3.read();
        pong_buf_15_3_202_fu_664 = pong_buf_15_3_332_fu_3698_p3.read();
        pong_buf_15_3_203_fu_668 = pong_buf_15_3_329_fu_3674_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_E))) {
        pong_buf_15_3_172_fu_676 = pong_buf_15_3_343_fu_3622_p3.read();
        pong_buf_15_3_175_fu_672 = pong_buf_15_3_344_fu_3630_p3.read();
        pong_buf_15_3_204_fu_680 = pong_buf_15_3_341_fu_3606_p3.read();
        pong_buf_15_3_205_fu_684 = pong_buf_15_3_338_fu_3582_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(ap_const_lv4_0, tmp_63_fu_3544_p1.read()))) {
        pong_buf_15_3_177_fu_460 = pong_buf_15_3_212_fu_4870_p3.read();
        pong_buf_15_3_18_fu_452 = pong_buf_15_3_217_fu_4910_p3.read();
        pong_buf_15_3_1_fu_448 = pong_buf_15_3_218_fu_4918_p3.read();
        pong_buf_15_3_21_fu_456 = pong_buf_15_3_215_fu_4894_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_1))) {
        pong_buf_15_3_178_fu_472 = pong_buf_15_3_224_fu_4802_p3.read();
        pong_buf_15_3_179_fu_476 = pong_buf_15_3_221_fu_4778_p3.read();
        pong_buf_15_3_29_fu_468 = pong_buf_15_3_226_fu_4818_p3.read();
        pong_buf_15_3_32_fu_464 = pong_buf_15_3_227_fu_4826_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_2))) {
        pong_buf_15_3_180_fu_488 = pong_buf_15_3_233_fu_4710_p3.read();
        pong_buf_15_3_181_fu_492 = pong_buf_15_3_230_fu_4686_p3.read();
        pong_buf_15_3_40_fu_484 = pong_buf_15_3_235_fu_4726_p3.read();
        pong_buf_15_3_43_fu_480 = pong_buf_15_3_236_fu_4734_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_3))) {
        pong_buf_15_3_182_fu_504 = pong_buf_15_3_242_fu_4618_p3.read();
        pong_buf_15_3_183_fu_508 = pong_buf_15_3_239_fu_4594_p3.read();
        pong_buf_15_3_51_fu_500 = pong_buf_15_3_244_fu_4634_p3.read();
        pong_buf_15_3_54_fu_496 = pong_buf_15_3_245_fu_4642_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_4))) {
        pong_buf_15_3_184_fu_520 = pong_buf_15_3_251_fu_4526_p3.read();
        pong_buf_15_3_185_fu_524 = pong_buf_15_3_248_fu_4502_p3.read();
        pong_buf_15_3_62_fu_516 = pong_buf_15_3_253_fu_4542_p3.read();
        pong_buf_15_3_65_fu_512 = pong_buf_15_3_254_fu_4550_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_5))) {
        pong_buf_15_3_186_fu_536 = pong_buf_15_3_260_fu_4434_p3.read();
        pong_buf_15_3_187_fu_540 = pong_buf_15_3_257_fu_4410_p3.read();
        pong_buf_15_3_73_fu_532 = pong_buf_15_3_262_fu_4450_p3.read();
        pong_buf_15_3_76_fu_528 = pong_buf_15_3_263_fu_4458_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_6))) {
        pong_buf_15_3_188_fu_552 = pong_buf_15_3_269_fu_4342_p3.read();
        pong_buf_15_3_189_fu_556 = pong_buf_15_3_266_fu_4318_p3.read();
        pong_buf_15_3_84_fu_548 = pong_buf_15_3_271_fu_4358_p3.read();
        pong_buf_15_3_87_fu_544 = pong_buf_15_3_272_fu_4366_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state32.read()) && esl_seteq<1,4,4>(tmp_63_fu_3544_p1.read(), ap_const_lv4_7))) {
        pong_buf_15_3_190_fu_568 = pong_buf_15_3_278_fu_4250_p3.read();
        pong_buf_15_3_191_fu_572 = pong_buf_15_3_275_fu_4226_p3.read();
        pong_buf_15_3_95_fu_564 = pong_buf_15_3_280_fu_4266_p3.read();
        pong_buf_15_3_98_fu_560 = pong_buf_15_3_281_fu_4274_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp1_iter2.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_7053_pp1_iter1_reg.read()))) {
        tmp17_reg_7354 = grp_fu_6347_p3.read();
        tmp18_reg_7359 = grp_fu_6355_p3.read();
        tmp20_reg_7364 = grp_fu_6339_p3.read();
        tmp21_reg_7369 = grp_fu_6331_p3.read();
        tmp24_reg_7374 = grp_fu_6371_p3.read();
        tmp25_reg_7379 = grp_fu_6363_p3.read();
        tmp27_reg_7384 = grp_fu_6387_p3.read();
        tmp28_reg_7389 = grp_fu_6379_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter2.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7486_pp2_iter1_reg.read()))) {
        tmp42_reg_7775 = grp_fu_6410_p3.read();
        tmp43_reg_7780 = grp_fu_6417_p3.read();
        tmp45_reg_7785 = grp_fu_6403_p3.read();
        tmp46_reg_7790 = grp_fu_6395_p3.read();
        tmp52_reg_7800 = grp_fu_6449_p3.read();
        tmp53_reg_7805 = grp_fu_6441_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7486_pp2_iter1_reg.read()))) {
        tmp51_reg_7795 = tmp51_fu_3376_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_fu_2678_p2.read()))) {
        tmp_10_reg_7062 = tmp_10_fu_2690_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond6_fu_3136_p2.read()))) {
        tmp_13_cast_reg_7411 = tmp_13_cast_fu_3156_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp3_iter0.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_fu_5038_p2.read()))) {
        tmp_13_mid2_v_reg_7842 = tmp_13_mid2_v_fu_5070_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_fu_3160_p2.read()))) {
        tmp_18_reg_7495 = tmp_18_fu_3172_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage1.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage1_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond1_reg_6528.read(), ap_const_lv1_0))) {
        tmp_1_reg_6561 = tmp_1_fu_2505_p1.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp3_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7818.read()))) {
        tmp_29_reg_7952 = tmp_29_fu_5143_p6.read();
        tmp_34_reg_7962 = tmp_34_fu_5169_p6.read();
        tmp_43_reg_7972 = tmp_43_fu_5182_p6.read();
        tmp_48_reg_7982 = tmp_48_fu_5221_p6.read();
        tmp_49_reg_7992 = tmp_49_fu_5234_p6.read();
        tmp_50_reg_8032 = tmp_50_fu_5346_p2.read();
        tmp_53_reg_8002 = tmp_53_fu_5273_p6.read();
        tmp_55_reg_8012 = tmp_55_fu_5299_p6.read();
        tmp_59_reg_8022 = tmp_59_fu_5325_p6.read();
        tmp_60_11_reg_8062 = tmp_60_11_fu_5430_p2.read();
        tmp_60_13_reg_8067 = tmp_60_13_fu_5444_p2.read();
        tmp_60_2_reg_8037 = tmp_60_2_fu_5360_p2.read();
        tmp_60_5_reg_8042 = tmp_60_5_fu_5374_p2.read();
        tmp_60_6_reg_8047 = tmp_60_6_fu_5388_p2.read();
        tmp_60_9_reg_8052 = tmp_60_9_fu_5402_p2.read();
        tmp_60_s_reg_8057 = tmp_60_s_fu_5416_p2.read();
        weights_l3_4b_11_loa_reg_8007 = weights_l3_4b_11_q0.read();
        weights_l3_4b_13_loa_reg_8017 = weights_l3_4b_13_q0.read();
        weights_l3_4b_15_loa_reg_8027 = weights_l3_4b_15_q0.read();
        weights_l3_4b_1_load_reg_7957 = weights_l3_4b_1_q0.read();
        weights_l3_4b_3_load_reg_7967 = weights_l3_4b_3_q0.read();
        weights_l3_4b_4_load_reg_7977 = weights_l3_4b_4_q0.read();
        weights_l3_4b_7_load_reg_7987 = weights_l3_4b_7_q0.read();
        weights_l3_4b_8_load_reg_7997 = weights_l3_4b_8_q0.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp2_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond5_reg_7486.read()))) {
        tmp_50_2_reg_7755 = tmp_50_2_fu_3223_p2.read();
        tmp_50_5_reg_7760 = tmp_50_5_fu_3237_p2.read();
        tmp_50_8_reg_7765 = tmp_50_8_fu_3251_p2.read();
        tmp_50_s_reg_7770 = tmp_50_s_fu_3265_p2.read();
        weights_l2_4b_0_load_reg_7640 = weights_l2_4b_0_q0.read();
        weights_l2_4b_11_loa_reg_7710 = weights_l2_4b_11_q0.read();
        weights_l2_4b_12_loa_reg_7720 = weights_l2_4b_12_q0.read();
        weights_l2_4b_13_loa_reg_7730 = weights_l2_4b_13_q0.read();
        weights_l2_4b_14_loa_reg_7740 = weights_l2_4b_14_q0.read();
        weights_l2_4b_15_loa_reg_7750 = weights_l2_4b_15_q0.read();
        weights_l2_4b_1_load_reg_7650 = weights_l2_4b_1_q0.read();
        weights_l2_4b_3_load_reg_7660 = weights_l2_4b_3_q0.read();
        weights_l2_4b_4_load_reg_7670 = weights_l2_4b_4_q0.read();
        weights_l2_4b_6_load_reg_7680 = weights_l2_4b_6_q0.read();
        weights_l2_4b_7_load_reg_7690 = weights_l2_4b_7_q0.read();
        weights_l2_4b_9_load_reg_7700 = weights_l2_4b_9_q0.read();
    }
    if ((esl_seteq<1,1,1>(ap_block_pp3_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_flatten_reg_7818_pp3_iter1_reg.read()))) {
        tmp_60_reg_8072 = tmp_60_fu_5603_p2.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp0_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp0_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond1_fu_2480_p2.read(), ap_const_lv1_0))) {
        tmp_reg_6537 = tmp_fu_2492_p3.read();
    }
    if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_pp1_stage0.read()) && esl_seteq<1,1,1>(ap_block_pp1_stage0_11001.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond8_reg_7053.read()))) {
        weights_l1_4b_0_load_reg_7199 = weights_l1_4b_0_q0.read();
        weights_l1_4b_10_loa_reg_7299 = weights_l1_4b_10_q0.read();
        weights_l1_4b_11_loa_reg_7309 = weights_l1_4b_11_q0.read();
        weights_l1_4b_12_loa_reg_7319 = weights_l1_4b_12_q0.read();
        weights_l1_4b_13_loa_reg_7329 = weights_l1_4b_13_q0.read();
        weights_l1_4b_14_loa_reg_7339 = weights_l1_4b_14_q0.read();
        weights_l1_4b_15_loa_reg_7349 = weights_l1_4b_15_q0.read();
        weights_l1_4b_1_load_reg_7209 = weights_l1_4b_1_q0.read();
        weights_l1_4b_2_load_reg_7219 = weights_l1_4b_2_q0.read();
        weights_l1_4b_3_load_reg_7229 = weights_l1_4b_3_q0.read();
        weights_l1_4b_4_load_reg_7239 = weights_l1_4b_4_q0.read();
        weights_l1_4b_5_load_reg_7249 = weights_l1_4b_5_q0.read();
        weights_l1_4b_6_load_reg_7259 = weights_l1_4b_6_q0.read();
        weights_l1_4b_7_load_reg_7269 = weights_l1_4b_7_q0.read();
        weights_l1_4b_8_load_reg_7279 = weights_l1_4b_8_q0.read();
        weights_l1_4b_9_load_reg_7289 = weights_l1_4b_9_q0.read();
    }
}

void mlp_accel_4b::thread_ap_NS_fsm() {
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
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state27.read()) && esl_seteq<1,1,1>(exitcond6_fu_3136_p2.read(), ap_const_lv1_1))) {
                ap_NS_fsm = ap_ST_fsm_pp3_stage0;
            } else {
                ap_NS_fsm = ap_ST_fsm_pp2_stage0;
            }
            break;
        case 8388608 : 
            if ((!(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter3.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(ap_enable_reg_pp2_iter2.read(), ap_const_logic_0)) && !(esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && esl_seteq<1,1,1>(exitcond5_fu_3160_p2.read(), ap_const_lv1_1) && esl_seteq<1,1,1>(ap_enable_reg_pp2_iter1.read(), ap_const_logic_0)))) {
                ap_NS_fsm = ap_ST_fsm_pp2_stage0;
            } else if (((esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter3.read()) && 
  esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && 
  esl_seteq<1,1,1>(ap_enable_reg_pp2_iter2.read(), ap_const_logic_0)) || (esl_seteq<1,1,1>(ap_const_logic_1, ap_enable_reg_pp2_iter0.read()) && 
  esl_seteq<1,1,1>(ap_block_pp2_stage0_subdone.read(), ap_const_boolean_0) && 
  esl_seteq<1,1,1>(exitcond5_fu_3160_p2.read(), ap_const_lv1_1) && 
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
            if ((esl_seteq<1,1,1>(ap_const_logic_1, ap_CS_fsm_state40.read()) && esl_seteq<1,1,1>(ap_const_lv1_0, exitcond_fu_6297_p2.read()))) {
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

