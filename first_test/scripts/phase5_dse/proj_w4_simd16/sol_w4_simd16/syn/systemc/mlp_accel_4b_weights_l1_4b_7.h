// ==============================================================
// File generated on Wed Sep 02 16:33:44 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_7_H__
#define __mlp_accel_4b_weights_l1_4b_7_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_7_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 2;
  static const unsigned AddressRange = 6272;
  static const unsigned AddressWidth = 13;

//latency = 1
//input_reg = 1
//output_reg = 0
sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in <sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


sc_lv<DataWidth> ram[AddressRange];


   SC_CTOR(mlp_accel_4b_weights_l1_4b_7_ram) {
        for (unsigned i = 0; i < 74 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[74] = "0b11";
        for (unsigned i = 75; i < 116 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[116] = "0b11";
        for (unsigned i = 117; i < 127 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[127] = "0b11";
        ram[128] = "0b00";
        ram[129] = "0b00";
        ram[130] = "0b01";
        ram[131] = "0b00";
        ram[132] = "0b00";
        ram[133] = "0b00";
        ram[134] = "0b01";
        ram[135] = "0b11";
        for (unsigned i = 136; i < 155 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[155] = "0b01";
        ram[156] = "0b11";
        for (unsigned i = 157; i < 165 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[165] = "0b01";
        for (unsigned i = 166; i < 319 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[319] = "0b11";
        for (unsigned i = 320; i < 333 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[333] = "0b01";
        ram[334] = "0b00";
        ram[335] = "0b00";
        ram[336] = "0b11";
        for (unsigned i = 337; i < 366 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[366] = "0b01";
        for (unsigned i = 367; i < 405 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[405] = "0b11";
        for (unsigned i = 406; i < 419 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[419] = "0b01";
        for (unsigned i = 420; i < 429 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[429] = "0b11";
        for (unsigned i = 430; i < 456 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[456] = "0b11";
        for (unsigned i = 457; i < 498 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[498] = "0b11";
        for (unsigned i = 499; i < 504 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[504] = "0b01";
        for (unsigned i = 505; i < 511 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[511] = "0b10";
        for (unsigned i = 512; i < 518 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[518] = "0b01";
        for (unsigned i = 519; i < 552 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[552] = "0b11";
        ram[553] = "0b00";
        ram[554] = "0b11";
        for (unsigned i = 555; i < 581 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[581] = "0b11";
        for (unsigned i = 582; i < 627 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[627] = "0b01";
        for (unsigned i = 628; i < 648 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[648] = "0b01";
        ram[649] = "0b00";
        ram[650] = "0b01";
        ram[651] = "0b00";
        ram[652] = "0b00";
        ram[653] = "0b11";
        ram[654] = "0b00";
        ram[655] = "0b11";
        for (unsigned i = 656; i < 666 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[666] = "0b11";
        for (unsigned i = 667; i < 674 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[674] = "0b01";
        for (unsigned i = 675; i < 697 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[697] = "0b11";
        ram[698] = "0b00";
        ram[699] = "0b00";
        ram[700] = "0b00";
        ram[701] = "0b11";
        for (unsigned i = 702; i < 721 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[721] = "0b01";
        for (unsigned i = 722; i < 727 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[727] = "0b11";
        for (unsigned i = 728; i < 805 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[805] = "0b11";
        ram[806] = "0b11";
        for (unsigned i = 807; i < 813 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[813] = "0b01";
        ram[814] = "0b11";
        for (unsigned i = 815; i < 844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[844] = "0b11";
        ram[845] = "0b00";
        ram[846] = "0b11";
        ram[847] = "0b01";
        for (unsigned i = 848; i < 865 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[865] = "0b01";
        for (unsigned i = 866; i < 874 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[874] = "0b11";
        for (unsigned i = 875; i < 947 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[947] = "0b11";
        for (unsigned i = 948; i < 954 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[954] = "0b01";
        for (unsigned i = 955; i < 994 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[994] = "0b11";
        for (unsigned i = 995; i < 1024 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1024] = "0b11";
        for (unsigned i = 1025; i < 1098 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1098] = "0b01";
        for (unsigned i = 1099; i < 1197 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1197] = "0b11";
        for (unsigned i = 1198; i < 1205 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1205] = "0b11";
        ram[1206] = "0b00";
        ram[1207] = "0b00";
        ram[1208] = "0b00";
        ram[1209] = "0b00";
        ram[1210] = "0b11";
        for (unsigned i = 1211; i < 1217 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1217] = "0b11";
        for (unsigned i = 1218; i < 1386 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1386] = "0b01";
        for (unsigned i = 1387; i < 1395 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1395] = "0b11";
        ram[1396] = "0b00";
        ram[1397] = "0b00";
        ram[1398] = "0b00";
        ram[1399] = "0b00";
        ram[1400] = "0b11";
        ram[1401] = "0b00";
        ram[1402] = "0b00";
        ram[1403] = "0b00";
        ram[1404] = "0b01";
        for (unsigned i = 1405; i < 1414 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1414] = "0b11";
        ram[1415] = "0b00";
        ram[1416] = "0b00";
        ram[1417] = "0b00";
        ram[1418] = "0b11";
        for (unsigned i = 1419; i < 1430 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1430] = "0b11";
        ram[1431] = "0b00";
        ram[1432] = "0b00";
        ram[1433] = "0b00";
        ram[1434] = "0b00";
        ram[1435] = "0b11";
        for (unsigned i = 1436; i < 1446 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1446] = "0b11";
        for (unsigned i = 1447; i < 1453 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1453] = "0b01";
        for (unsigned i = 1454; i < 1537 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1537] = "0b01";
        ram[1538] = "0b00";
        ram[1539] = "0b00";
        ram[1540] = "0b00";
        ram[1541] = "0b11";
        for (unsigned i = 1542; i < 1553 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1553] = "0b11";
        ram[1554] = "0b11";
        for (unsigned i = 1555; i < 1590 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1590] = "0b01";
        ram[1591] = "0b00";
        ram[1592] = "0b00";
        ram[1593] = "0b01";
        for (unsigned i = 1594; i < 1633 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1633] = "0b01";
        for (unsigned i = 1634; i < 1640 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1640] = "0b11";
        for (unsigned i = 1641; i < 1824 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1824] = "0b01";
        ram[1825] = "0b00";
        ram[1826] = "0b00";
        ram[1827] = "0b00";
        ram[1828] = "0b11";
        ram[1829] = "0b00";
        ram[1830] = "0b00";
        ram[1831] = "0b11";
        for (unsigned i = 1832; i < 1841 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1841] = "0b11";
        ram[1842] = "0b00";
        ram[1843] = "0b11";
        for (unsigned i = 1844; i < 1929 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1929] = "0b11";
        for (unsigned i = 1930; i < 1938 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1938] = "0b11";
        for (unsigned i = 1939; i < 1948 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1948] = "0b01";
        ram[1949] = "0b00";
        ram[1950] = "0b00";
        ram[1951] = "0b00";
        ram[1952] = "0b00";
        ram[1953] = "0b01";
        for (unsigned i = 1954; i < 1975 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1975] = "0b11";
        ram[1976] = "0b00";
        ram[1977] = "0b00";
        ram[1978] = "0b01";
        ram[1979] = "0b00";
        ram[1980] = "0b00";
        ram[1981] = "0b11";
        ram[1982] = "0b11";
        for (unsigned i = 1983; i < 1989 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1989] = "0b01";
        for (unsigned i = 1990; i < 2001 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2001] = "0b01";
        ram[2002] = "0b00";
        ram[2003] = "0b00";
        ram[2004] = "0b11";
        for (unsigned i = 2005; i < 2018 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2018] = "0b11";
        ram[2019] = "0b00";
        ram[2020] = "0b00";
        ram[2021] = "0b00";
        ram[2022] = "0b00";
        ram[2023] = "0b01";
        for (unsigned i = 2024; i < 2032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2032] = "0b11";
        for (unsigned i = 2033; i < 2044 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2044] = "0b01";
        for (unsigned i = 2045; i < 2051 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2051] = "0b11";
        for (unsigned i = 2052; i < 2074 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2074] = "0b01";
        ram[2075] = "0b00";
        ram[2076] = "0b11";
        ram[2077] = "0b00";
        ram[2078] = "0b00";
        ram[2079] = "0b00";
        ram[2080] = "0b01";
        for (unsigned i = 2081; i < 2095 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2095] = "0b11";
        for (unsigned i = 2096; i < 2120 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2120] = "0b01";
        ram[2121] = "0b00";
        ram[2122] = "0b00";
        ram[2123] = "0b01";
        ram[2124] = "0b00";
        ram[2125] = "0b11";
        ram[2126] = "0b00";
        ram[2127] = "0b11";
        for (unsigned i = 2128; i < 2135 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2135] = "0b11";
        for (unsigned i = 2136; i < 2214 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2214] = "0b11";
        for (unsigned i = 2215; i < 2223 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2223] = "0b01";
        ram[2224] = "0b00";
        ram[2225] = "0b11";
        for (unsigned i = 2226; i < 2325 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2325] = "0b01";
        ram[2326] = "0b00";
        ram[2327] = "0b00";
        ram[2328] = "0b01";
        ram[2329] = "0b00";
        ram[2330] = "0b00";
        ram[2331] = "0b11";
        ram[2332] = "0b11";
        ram[2333] = "0b11";
        for (unsigned i = 2334; i < 2360 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2360] = "0b11";
        for (unsigned i = 2361; i < 2368 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2368] = "0b11";
        ram[2369] = "0b00";
        ram[2370] = "0b11";
        ram[2371] = "0b00";
        ram[2372] = "0b00";
        ram[2373] = "0b10";
        ram[2374] = "0b00";
        ram[2375] = "0b01";
        for (unsigned i = 2376; i < 2394 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2394] = "0b01";
        for (unsigned i = 2395; i < 2417 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2417] = "0b01";
        for (unsigned i = 2418; i < 2436 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2436] = "0b11";
        for (unsigned i = 2437; i < 2442 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2442] = "0b11";
        for (unsigned i = 2443; i < 2477 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2477] = "0b01";
        for (unsigned i = 2478; i < 2484 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2484] = "0b11";
        ram[2485] = "0b11";
        ram[2486] = "0b11";
        for (unsigned i = 2487; i < 2492 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2492] = "0b11";
        for (unsigned i = 2493; i < 2508 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2508] = "0b11";
        for (unsigned i = 2509; i < 2514 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2514] = "0b01";
        ram[2515] = "0b00";
        ram[2516] = "0b00";
        ram[2517] = "0b00";
        ram[2518] = "0b00";
        ram[2519] = "0b11";
        ram[2520] = "0b00";
        ram[2521] = "0b11";
        ram[2522] = "0b00";
        ram[2523] = "0b00";
        ram[2524] = "0b01";
        for (unsigned i = 2525; i < 2540 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2540] = "0b11";
        for (unsigned i = 2541; i < 2566 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2566] = "0b11";
        for (unsigned i = 2567; i < 2613 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2613] = "0b11";
        ram[2614] = "0b00";
        ram[2615] = "0b01";
        for (unsigned i = 2616; i < 2639 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2639] = "0b01";
        ram[2640] = "0b00";
        ram[2641] = "0b01";
        for (unsigned i = 2642; i < 2669 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2669] = "0b01";
        ram[2670] = "0b00";
        ram[2671] = "0b00";
        ram[2672] = "0b00";
        ram[2673] = "0b00";
        ram[2674] = "0b11";
        ram[2675] = "0b00";
        ram[2676] = "0b11";
        ram[2677] = "0b00";
        ram[2678] = "0b11";
        for (unsigned i = 2679; i < 2711 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2711] = "0b01";
        ram[2712] = "0b00";
        ram[2713] = "0b00";
        ram[2714] = "0b00";
        ram[2715] = "0b11";
        ram[2716] = "0b00";
        ram[2717] = "0b00";
        ram[2718] = "0b11";
        for (unsigned i = 2719; i < 2727 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2727] = "0b01";
        for (unsigned i = 2728; i < 2734 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2734] = "0b01";
        for (unsigned i = 2735; i < 2759 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2759] = "0b01";
        for (unsigned i = 2760; i < 2765 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2765] = "0b01";
        ram[2766] = "0b00";
        ram[2767] = "0b01";
        ram[2768] = "0b00";
        ram[2769] = "0b00";
        ram[2770] = "0b00";
        ram[2771] = "0b11";
        for (unsigned i = 2772; i < 2823 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2823] = "0b10";
        ram[2824] = "0b00";
        ram[2825] = "0b00";
        ram[2826] = "0b00";
        ram[2827] = "0b00";
        ram[2828] = "0b11";
        ram[2829] = "0b00";
        ram[2830] = "0b00";
        ram[2831] = "0b00";
        ram[2832] = "0b01";
        for (unsigned i = 2833; i < 2853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2853] = "0b11";
        ram[2854] = "0b00";
        ram[2855] = "0b11";
        for (unsigned i = 2856; i < 2878 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2878] = "0b11";
        ram[2879] = "0b00";
        ram[2880] = "0b00";
        ram[2881] = "0b00";
        ram[2882] = "0b00";
        ram[2883] = "0b11";
        ram[2884] = "0b11";
        ram[2885] = "0b00";
        ram[2886] = "0b00";
        ram[2887] = "0b00";
        ram[2888] = "0b11";
        for (unsigned i = 2889; i < 2904 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2904] = "0b11";
        for (unsigned i = 2905; i < 2961 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2961] = "0b01";
        ram[2962] = "0b00";
        ram[2963] = "0b11";
        ram[2964] = "0b00";
        ram[2965] = "0b00";
        ram[2966] = "0b00";
        ram[2967] = "0b00";
        ram[2968] = "0b11";
        ram[2969] = "0b00";
        ram[2970] = "0b01";
        ram[2971] = "0b00";
        ram[2972] = "0b00";
        ram[2973] = "0b00";
        ram[2974] = "0b00";
        ram[2975] = "0b01";
        for (unsigned i = 2976; i < 3002 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3002] = "0b01";
        for (unsigned i = 3003; i < 3014 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3014] = "0b01";
        ram[3015] = "0b00";
        ram[3016] = "0b00";
        ram[3017] = "0b00";
        ram[3018] = "0b11";
        ram[3019] = "0b00";
        ram[3020] = "0b00";
        ram[3021] = "0b00";
        ram[3022] = "0b00";
        ram[3023] = "0b11";
        for (unsigned i = 3024; i < 3030 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3030] = "0b11";
        for (unsigned i = 3031; i < 3056 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3056] = "0b11";
        for (unsigned i = 3057; i < 3063 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3063] = "0b01";
        for (unsigned i = 3064; i < 3098 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3098] = "0b11";
        ram[3099] = "0b00";
        ram[3100] = "0b00";
        ram[3101] = "0b00";
        ram[3102] = "0b01";
        for (unsigned i = 3103; i < 3108 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3108] = "0b01";
        for (unsigned i = 3109; i < 3114 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3114] = "0b11";
        ram[3115] = "0b11";
        for (unsigned i = 3116; i < 3142 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3142] = "0b01";
        ram[3143] = "0b00";
        ram[3144] = "0b01";
        ram[3145] = "0b00";
        ram[3146] = "0b00";
        ram[3147] = "0b01";
        ram[3148] = "0b00";
        ram[3149] = "0b00";
        ram[3150] = "0b00";
        ram[3151] = "0b11";
        ram[3152] = "0b00";
        ram[3153] = "0b00";
        ram[3154] = "0b11";
        for (unsigned i = 3155; i < 3182 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3182] = "0b01";
        for (unsigned i = 3183; i < 3194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3194] = "0b11";
        for (unsigned i = 3195; i < 3296 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3296] = "0b11";
        ram[3297] = "0b00";
        ram[3298] = "0b11";
        for (unsigned i = 3299; i < 3310 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3310] = "0b01";
        for (unsigned i = 3311; i < 3355 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3355] = "0b01";
        for (unsigned i = 3356; i < 3374 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3374] = "0b11";
        for (unsigned i = 3375; i < 3390 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3390] = "0b11";
        ram[3391] = "0b00";
        ram[3392] = "0b01";
        for (unsigned i = 3393; i < 3399 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3399] = "0b11";
        ram[3400] = "0b00";
        ram[3401] = "0b00";
        ram[3402] = "0b11";
        for (unsigned i = 3403; i < 3408 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3408] = "0b11";
        ram[3409] = "0b00";
        ram[3410] = "0b11";
        for (unsigned i = 3411; i < 3416 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3416] = "0b01";
        for (unsigned i = 3417; i < 3453 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3453] = "0b11";
        ram[3454] = "0b00";
        ram[3455] = "0b00";
        ram[3456] = "0b11";
        ram[3457] = "0b00";
        ram[3458] = "0b11";
        for (unsigned i = 3459; i < 3490 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3490] = "0b01";
        for (unsigned i = 3491; i < 3504 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3504] = "0b11";
        for (unsigned i = 3505; i < 3570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3570] = "0b01";
        for (unsigned i = 3571; i < 3586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3586] = "0b01";
        ram[3587] = "0b00";
        ram[3588] = "0b11";
        ram[3589] = "0b00";
        ram[3590] = "0b00";
        ram[3591] = "0b00";
        ram[3592] = "0b01";
        for (unsigned i = 3593; i < 3600 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3600] = "0b01";
        for (unsigned i = 3601; i < 3651 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3651] = "0b11";
        for (unsigned i = 3652; i < 3705 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3705] = "0b11";
        for (unsigned i = 3706; i < 3717 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3717] = "0b01";
        for (unsigned i = 3718; i < 3754 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3754] = "0b01";
        for (unsigned i = 3755; i < 3806 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3806] = "0b11";
        for (unsigned i = 3807; i < 3840 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3840] = "0b11";
        for (unsigned i = 3841; i < 3847 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3847] = "0b01";
        ram[3848] = "0b00";
        ram[3849] = "0b00";
        ram[3850] = "0b11";
        ram[3851] = "0b00";
        ram[3852] = "0b11";
        for (unsigned i = 3853; i < 3864 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3864] = "0b01";
        for (unsigned i = 3865; i < 3885 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3885] = "0b11";
        for (unsigned i = 3886; i < 3891 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3891] = "0b01";
        ram[3892] = "0b00";
        ram[3893] = "0b00";
        ram[3894] = "0b01";
        ram[3895] = "0b00";
        ram[3896] = "0b11";
        for (unsigned i = 3897; i < 3961 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3961] = "0b11";
        for (unsigned i = 3962; i < 3990 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3990] = "0b01";
        ram[3991] = "0b01";
        for (unsigned i = 3992; i < 3999 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3999] = "0b01";
        ram[4000] = "0b00";
        ram[4001] = "0b00";
        ram[4002] = "0b00";
        ram[4003] = "0b00";
        ram[4004] = "0b11";
        for (unsigned i = 4005; i < 4011 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4011] = "0b01";
        for (unsigned i = 4012; i < 4027 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4027] = "0b11";
        for (unsigned i = 4028; i < 4033 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4033] = "0b01";
        for (unsigned i = 4034; i < 4045 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4045] = "0b11";
        for (unsigned i = 4046; i < 4059 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4059] = "0b11";
        for (unsigned i = 4060; i < 4080 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4080] = "0b01";
        ram[4081] = "0b00";
        ram[4082] = "0b11";
        for (unsigned i = 4083; i < 4089 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4089] = "0b01";
        for (unsigned i = 4090; i < 4095 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4095] = "0b01";
        for (unsigned i = 4096; i < 4171 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4171] = "0b11";
        ram[4172] = "0b00";
        ram[4173] = "0b00";
        ram[4174] = "0b01";
        for (unsigned i = 4175; i < 4188 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4188] = "0b01";
        ram[4189] = "0b00";
        ram[4190] = "0b00";
        ram[4191] = "0b00";
        ram[4192] = "0b00";
        ram[4193] = "0b11";
        ram[4194] = "0b01";
        ram[4195] = "0b10";
        for (unsigned i = 4196; i < 4207 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4207] = "0b01";
        for (unsigned i = 4208; i < 4243 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4243] = "0b01";
        ram[4244] = "0b01";
        for (unsigned i = 4245; i < 4281 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4281] = "0b11";
        for (unsigned i = 4282; i < 4332 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4332] = "0b11";
        ram[4333] = "0b00";
        ram[4334] = "0b11";
        for (unsigned i = 4335; i < 4340 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4340] = "0b11";
        ram[4341] = "0b11";
        ram[4342] = "0b11";
        for (unsigned i = 4343; i < 4353 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4353] = "0b11";
        for (unsigned i = 4354; i < 4477 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4477] = "0b01";
        ram[4478] = "0b00";
        ram[4479] = "0b00";
        ram[4480] = "0b11";
        for (unsigned i = 4481; i < 4486 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4486] = "0b10";
        ram[4487] = "0b00";
        ram[4488] = "0b00";
        ram[4489] = "0b00";
        ram[4490] = "0b00";
        ram[4491] = "0b11";
        ram[4492] = "0b01";
        for (unsigned i = 4493; i < 4535 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4535] = "0b11";
        for (unsigned i = 4536; i < 4547 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4547] = "0b01";
        for (unsigned i = 4548; i < 4566 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4566] = "0b11";
        for (unsigned i = 4567; i < 4590 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4590] = "0b01";
        ram[4591] = "0b00";
        ram[4592] = "0b00";
        ram[4593] = "0b00";
        ram[4594] = "0b01";
        for (unsigned i = 4595; i < 4619 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4619] = "0b01";
        ram[4620] = "0b00";
        ram[4621] = "0b01";
        ram[4622] = "0b00";
        ram[4623] = "0b00";
        ram[4624] = "0b11";
        ram[4625] = "0b00";
        ram[4626] = "0b10";
        ram[4627] = "0b00";
        ram[4628] = "0b11";
        for (unsigned i = 4629; i < 4731 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4731] = "0b11";
        for (unsigned i = 4732; i < 4792 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4792] = "0b11";
        for (unsigned i = 4793; i < 4866 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4866] = "0b01";
        for (unsigned i = 4867; i < 4873 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4873] = "0b01";
        for (unsigned i = 4874; i < 4881 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4881] = "0b01";
        ram[4882] = "0b00";
        ram[4883] = "0b00";
        ram[4884] = "0b00";
        ram[4885] = "0b00";
        ram[4886] = "0b01";
        for (unsigned i = 4887; i < 4895 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4895] = "0b01";
        for (unsigned i = 4896; i < 4911 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4911] = "0b11";
        ram[4912] = "0b00";
        ram[4913] = "0b00";
        ram[4914] = "0b01";
        for (unsigned i = 4915; i < 4944 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4944] = "0b11";
        ram[4945] = "0b00";
        ram[4946] = "0b11";
        for (unsigned i = 4947; i < 4970 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4970] = "0b11";
        ram[4971] = "0b00";
        ram[4972] = "0b01";
        for (unsigned i = 4973; i < 5034 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5034] = "0b01";
        for (unsigned i = 5035; i < 5056 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5056] = "0b11";
        ram[5057] = "0b00";
        ram[5058] = "0b11";
        for (unsigned i = 5059; i < 5069 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5069] = "0b01";
        for (unsigned i = 5070; i < 5081 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5081] = "0b11";
        for (unsigned i = 5082; i < 5089 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5089] = "0b11";
        for (unsigned i = 5090; i < 5161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5161] = "0b11";
        for (unsigned i = 5162; i < 5168 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5168] = "0b01";
        for (unsigned i = 5169; i < 5178 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5178] = "0b01";
        for (unsigned i = 5179; i < 5216 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5216] = "0b11";
        for (unsigned i = 5217; i < 5222 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5222] = "0b10";
        ram[5223] = "0b00";
        ram[5224] = "0b11";
        ram[5225] = "0b00";
        ram[5226] = "0b00";
        ram[5227] = "0b01";
        ram[5228] = "0b00";
        ram[5229] = "0b01";
        for (unsigned i = 5230; i < 5252 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5252] = "0b01";
        for (unsigned i = 5253; i < 5301 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5301] = "0b11";
        for (unsigned i = 5302; i < 5310 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5310] = "0b01";
        for (unsigned i = 5311; i < 5324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5324] = "0b11";
        ram[5325] = "0b00";
        ram[5326] = "0b11";
        ram[5327] = "0b00";
        ram[5328] = "0b00";
        ram[5329] = "0b00";
        ram[5330] = "0b00";
        ram[5331] = "0b11";
        for (unsigned i = 5332; i < 5359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5359] = "0b01";
        ram[5360] = "0b00";
        ram[5361] = "0b00";
        ram[5362] = "0b11";
        for (unsigned i = 5363; i < 5370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5370] = "0b01";
        for (unsigned i = 5371; i < 5399 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5399] = "0b11";
        for (unsigned i = 5400; i < 5405 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5405] = "0b11";
        ram[5406] = "0b01";
        for (unsigned i = 5407; i < 5413 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5413] = "0b11";
        ram[5414] = "0b00";
        ram[5415] = "0b00";
        ram[5416] = "0b00";
        ram[5417] = "0b00";
        ram[5418] = "0b01";
        ram[5419] = "0b00";
        ram[5420] = "0b01";
        ram[5421] = "0b00";
        ram[5422] = "0b00";
        ram[5423] = "0b00";
        ram[5424] = "0b01";
        ram[5425] = "0b11";
        ram[5426] = "0b00";
        ram[5427] = "0b11";
        for (unsigned i = 5428; i < 5433 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5433] = "0b01";
        ram[5434] = "0b00";
        ram[5435] = "0b00";
        ram[5436] = "0b01";
        for (unsigned i = 5437; i < 5443 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5443] = "0b01";
        ram[5444] = "0b00";
        ram[5445] = "0b00";
        ram[5446] = "0b00";
        ram[5447] = "0b11";
        ram[5448] = "0b00";
        ram[5449] = "0b00";
        ram[5450] = "0b00";
        ram[5451] = "0b00";
        ram[5452] = "0b11";
        for (unsigned i = 5453; i < 5480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5480] = "0b11";
        for (unsigned i = 5481; i < 5499 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5499] = "0b11";
        for (unsigned i = 5500; i < 5506 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5506] = "0b01";
        ram[5507] = "0b01";
        for (unsigned i = 5508; i < 5534 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5534] = "0b01";
        for (unsigned i = 5535; i < 5555 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5555] = "0b11";
        ram[5556] = "0b00";
        ram[5557] = "0b01";
        for (unsigned i = 5558; i < 5646 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5646] = "0b11";
        ram[5647] = "0b00";
        ram[5648] = "0b00";
        ram[5649] = "0b11";
        ram[5650] = "0b00";
        ram[5651] = "0b01";
        for (unsigned i = 5652; i < 5657 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5657] = "0b01";
        ram[5658] = "0b01";
        ram[5659] = "0b00";
        ram[5660] = "0b00";
        ram[5661] = "0b00";
        ram[5662] = "0b11";
        for (unsigned i = 5663; i < 5671 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5671] = "0b11";
        for (unsigned i = 5672; i < 5791 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5791] = "0b01";
        for (unsigned i = 5792; i < 5809 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5809] = "0b11";
        for (unsigned i = 5810; i < 5818 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5818] = "0b01";
        for (unsigned i = 5819; i < 5840 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5840] = "0b11";
        ram[5841] = "0b00";
        ram[5842] = "0b00";
        ram[5843] = "0b00";
        ram[5844] = "0b01";
        ram[5845] = "0b00";
        ram[5846] = "0b00";
        ram[5847] = "0b00";
        ram[5848] = "0b00";
        ram[5849] = "0b10";
        ram[5850] = "0b00";
        ram[5851] = "0b01";
        for (unsigned i = 5852; i < 5858 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5858] = "0b01";
        for (unsigned i = 5859; i < 5877 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5877] = "0b01";
        for (unsigned i = 5878; i < 5889 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5889] = "0b11";
        for (unsigned i = 5890; i < 5938 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5938] = "0b11";
        ram[5939] = "0b00";
        ram[5940] = "0b00";
        ram[5941] = "0b00";
        ram[5942] = "0b00";
        ram[5943] = "0b11";
        ram[5944] = "0b00";
        ram[5945] = "0b00";
        ram[5946] = "0b00";
        ram[5947] = "0b11";
        for (unsigned i = 5948; i < 5954 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5954] = "0b01";
        for (unsigned i = 5955; i < 5991 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5991] = "0b11";
        ram[5992] = "0b00";
        ram[5993] = "0b00";
        ram[5994] = "0b11";
        ram[5995] = "0b00";
        ram[5996] = "0b00";
        ram[5997] = "0b00";
        ram[5998] = "0b00";
        ram[5999] = "0b11";
        for (unsigned i = 6000; i < 6048 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6048] = "0b11";
        ram[6049] = "0b11";
        for (unsigned i = 6050; i < 6055 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6055] = "0b01";
        ram[6056] = "0b00";
        ram[6057] = "0b01";
        for (unsigned i = 6058; i < 6066 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6066] = "0b11";
        for (unsigned i = 6067; i < 6104 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6104] = "0b01";
        ram[6105] = "0b00";
        ram[6106] = "0b01";
        ram[6107] = "0b00";
        ram[6108] = "0b01";
        ram[6109] = "0b00";
        ram[6110] = "0b00";
        ram[6111] = "0b00";
        ram[6112] = "0b00";
        ram[6113] = "0b11";
        ram[6114] = "0b00";
        ram[6115] = "0b11";
        for (unsigned i = 6116; i < 6136 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6136] = "0b01";
        ram[6137] = "0b00";
        ram[6138] = "0b11";
        for (unsigned i = 6139; i < 6147 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6147] = "0b11";
        for (unsigned i = 6148; i < 6153 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6153] = "0b01";
        ram[6154] = "0b00";
        ram[6155] = "0b11";
        ram[6156] = "0b00";
        ram[6157] = "0b01";
        for (unsigned i = 6158; i < 6194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6194] = "0b01";
        for (unsigned i = 6195; i < 6201 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6201] = "0b11";
        for (unsigned i = 6202; i < 6251 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6251] = "0b01";
        ram[6252] = "0b00";
        ram[6253] = "0b11";
        for (unsigned i = 6254; i < 6259 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6259] = "0b11";
        ram[6260] = "0b00";
        ram[6261] = "0b00";
        ram[6262] = "0b00";
        ram[6263] = "0b00";
        ram[6264] = "0b11";
        for (unsigned i = 6265; i < 6272 ; i = i + 1) {
            ram[i] = "0b00";
        }


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


SC_MODULE(mlp_accel_4b_weights_l1_4b_7) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_7_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_7) {
meminst = new mlp_accel_4b_weights_l1_4b_7_ram("mlp_accel_4b_weights_l1_4b_7_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_7() {
    delete meminst;
}


};//endmodule
#endif
