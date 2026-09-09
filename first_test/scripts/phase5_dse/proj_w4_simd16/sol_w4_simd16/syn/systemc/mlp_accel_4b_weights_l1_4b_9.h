// ==============================================================
// File generated on Wed Sep 02 16:33:44 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_9_H__
#define __mlp_accel_4b_weights_l1_4b_9_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_9_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_9_ram) {
        for (unsigned i = 0; i < 74 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[74] = "0b11";
        ram[75] = "0b00";
        ram[76] = "0b01";
        for (unsigned i = 77; i < 123 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[123] = "0b01";
        ram[124] = "0b00";
        ram[125] = "0b11";
        ram[126] = "0b00";
        ram[127] = "0b00";
        ram[128] = "0b00";
        ram[129] = "0b00";
        ram[130] = "0b01";
        ram[131] = "0b00";
        ram[132] = "0b01";
        for (unsigned i = 133; i < 139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[139] = "0b01";
        for (unsigned i = 140; i < 161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[161] = "0b11";
        ram[162] = "0b00";
        ram[163] = "0b01";
        for (unsigned i = 164; i < 170 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[170] = "0b01";
        ram[171] = "0b00";
        ram[172] = "0b00";
        ram[173] = "0b00";
        ram[174] = "0b01";
        ram[175] = "0b11";
        for (unsigned i = 176; i < 193 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[193] = "0b01";
        for (unsigned i = 194; i < 228 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[228] = "0b01";
        for (unsigned i = 229; i < 308 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[308] = "0b01";
        ram[309] = "0b00";
        ram[310] = "0b11";
        for (unsigned i = 311; i < 317 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[317] = "0b11";
        for (unsigned i = 318; i < 324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[324] = "0b11";
        for (unsigned i = 325; i < 417 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[417] = "0b01";
        for (unsigned i = 418; i < 429 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[429] = "0b11";
        for (unsigned i = 430; i < 450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[450] = "0b01";
        for (unsigned i = 451; i < 461 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[461] = "0b01";
        ram[462] = "0b00";
        ram[463] = "0b00";
        ram[464] = "0b11";
        for (unsigned i = 465; i < 485 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[485] = "0b11";
        for (unsigned i = 486; i < 509 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[509] = "0b11";
        ram[510] = "0b11";
        ram[511] = "0b10";
        ram[512] = "0b01";
        ram[513] = "0b01";
        ram[514] = "0b00";
        ram[515] = "0b00";
        ram[516] = "0b00";
        ram[517] = "0b00";
        ram[518] = "0b01";
        for (unsigned i = 519; i < 525 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[525] = "0b11";
        for (unsigned i = 526; i < 552 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[552] = "0b11";
        ram[553] = "0b00";
        ram[554] = "0b00";
        ram[555] = "0b00";
        ram[556] = "0b00";
        ram[557] = "0b01";
        for (unsigned i = 558; i < 574 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[574] = "0b11";
        for (unsigned i = 575; i < 581 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[581] = "0b11";
        for (unsigned i = 582; i < 600 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[600] = "0b01";
        for (unsigned i = 601; i < 608 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[608] = "0b11";
        ram[609] = "0b00";
        ram[610] = "0b00";
        ram[611] = "0b11";
        for (unsigned i = 612; i < 646 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[646] = "0b01";
        for (unsigned i = 647; i < 653 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[653] = "0b11";
        ram[654] = "0b00";
        ram[655] = "0b01";
        for (unsigned i = 656; i < 695 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[695] = "0b11";
        ram[696] = "0b00";
        ram[697] = "0b01";
        ram[698] = "0b00";
        ram[699] = "0b00";
        ram[700] = "0b00";
        ram[701] = "0b00";
        ram[702] = "0b11";
        for (unsigned i = 703; i < 715 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[715] = "0b01";
        for (unsigned i = 716; i < 803 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[803] = "0b11";
        ram[804] = "0b00";
        ram[805] = "0b00";
        ram[806] = "0b00";
        ram[807] = "0b01";
        ram[808] = "0b00";
        ram[809] = "0b00";
        ram[810] = "0b11";
        ram[811] = "0b00";
        ram[812] = "0b00";
        ram[813] = "0b00";
        ram[814] = "0b11";
        ram[815] = "0b00";
        ram[816] = "0b00";
        ram[817] = "0b01";
        for (unsigned i = 818; i < 825 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[825] = "0b11";
        for (unsigned i = 826; i < 844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[844] = "0b11";
        for (unsigned i = 845; i < 853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[853] = "0b01";
        ram[854] = "0b00";
        ram[855] = "0b01";
        for (unsigned i = 856; i < 867 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[867] = "0b11";
        for (unsigned i = 868; i < 950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[950] = "0b11";
        ram[951] = "0b11";
        ram[952] = "0b01";
        for (unsigned i = 953; i < 1042 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1042] = "0b11";
        for (unsigned i = 1043; i < 1062 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1062] = "0b11";
        for (unsigned i = 1063; i < 1112 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1112] = "0b11";
        for (unsigned i = 1113; i < 1183 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1183] = "0b11";
        for (unsigned i = 1184; i < 1203 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1203] = "0b11";
        ram[1204] = "0b11";
        ram[1205] = "0b00";
        ram[1206] = "0b00";
        ram[1207] = "0b00";
        ram[1208] = "0b01";
        ram[1209] = "0b00";
        ram[1210] = "0b11";
        ram[1211] = "0b00";
        ram[1212] = "0b00";
        ram[1213] = "0b00";
        ram[1214] = "0b00";
        ram[1215] = "0b11";
        for (unsigned i = 1216; i < 1304 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1304] = "0b01";
        for (unsigned i = 1305; i < 1395 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1395] = "0b11";
        ram[1396] = "0b00";
        ram[1397] = "0b00";
        ram[1398] = "0b00";
        ram[1399] = "0b11";
        ram[1400] = "0b11";
        ram[1401] = "0b00";
        ram[1402] = "0b01";
        ram[1403] = "0b00";
        ram[1404] = "0b00";
        ram[1405] = "0b11";
        for (unsigned i = 1406; i < 1465 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1465] = "0b11";
        for (unsigned i = 1466; i < 1528 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1528] = "0b11";
        for (unsigned i = 1529; i < 1540 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1540] = "0b01";
        ram[1541] = "0b00";
        ram[1542] = "0b00";
        ram[1543] = "0b00";
        ram[1544] = "0b01";
        for (unsigned i = 1545; i < 1556 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1556] = "0b11";
        for (unsigned i = 1557; i < 1586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1586] = "0b11";
        ram[1587] = "0b00";
        ram[1588] = "0b01";
        ram[1589] = "0b00";
        ram[1590] = "0b00";
        ram[1591] = "0b11";
        for (unsigned i = 1592; i < 1601 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1601] = "0b11";
        for (unsigned i = 1602; i < 1626 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1626] = "0b11";
        for (unsigned i = 1627; i < 1633 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1633] = "0b01";
        ram[1634] = "0b00";
        ram[1635] = "0b11";
        ram[1636] = "0b00";
        ram[1637] = "0b11";
        for (unsigned i = 1638; i < 1643 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1643] = "0b11";
        for (unsigned i = 1644; i < 1710 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1710] = "0b11";
        for (unsigned i = 1711; i < 1831 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1831] = "0b11";
        for (unsigned i = 1832; i < 1839 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1839] = "0b11";
        for (unsigned i = 1840; i < 1895 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1895] = "0b01";
        for (unsigned i = 1896; i < 1934 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1934] = "0b11";
        for (unsigned i = 1935; i < 1943 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1943] = "0b11";
        for (unsigned i = 1944; i < 1978 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1978] = "0b01";
        ram[1979] = "0b00";
        ram[1980] = "0b11";
        for (unsigned i = 1981; i < 2035 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2035] = "0b11";
        for (unsigned i = 2036; i < 2043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2043] = "0b11";
        for (unsigned i = 2044; i < 2076 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2076] = "0b11";
        ram[2077] = "0b00";
        ram[2078] = "0b00";
        ram[2079] = "0b01";
        ram[2080] = "0b00";
        ram[2081] = "0b00";
        ram[2082] = "0b00";
        ram[2083] = "0b11";
        ram[2084] = "0b01";
        ram[2085] = "0b00";
        ram[2086] = "0b00";
        ram[2087] = "0b00";
        ram[2088] = "0b11";
        for (unsigned i = 2089; i < 2123 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2123] = "0b11";
        ram[2124] = "0b00";
        ram[2125] = "0b11";
        ram[2126] = "0b00";
        ram[2127] = "0b11";
        for (unsigned i = 2128; i < 2137 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2137] = "0b11";
        ram[2138] = "0b00";
        ram[2139] = "0b00";
        ram[2140] = "0b00";
        ram[2141] = "0b01";
        for (unsigned i = 2142; i < 2151 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2151] = "0b01";
        for (unsigned i = 2152; i < 2216 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2216] = "0b01";
        ram[2217] = "0b01";
        for (unsigned i = 2218; i < 2225 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2225] = "0b11";
        for (unsigned i = 2226; i < 2232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2232] = "0b01";
        for (unsigned i = 2233; i < 2318 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2318] = "0b01";
        for (unsigned i = 2319; i < 2326 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2326] = "0b01";
        for (unsigned i = 2327; i < 2335 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2335] = "0b11";
        for (unsigned i = 2336; i < 2342 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2342] = "0b11";
        for (unsigned i = 2343; i < 2359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2359] = "0b01";
        for (unsigned i = 2360; i < 2368 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2368] = "0b10";
        ram[2369] = "0b00";
        ram[2370] = "0b00";
        ram[2371] = "0b11";
        ram[2372] = "0b00";
        ram[2373] = "0b11";
        ram[2374] = "0b00";
        ram[2375] = "0b00";
        ram[2376] = "0b00";
        ram[2377] = "0b00";
        ram[2378] = "0b01";
        for (unsigned i = 2379; i < 2408 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2408] = "0b11";
        ram[2409] = "0b00";
        ram[2410] = "0b11";
        ram[2411] = "0b00";
        ram[2412] = "0b00";
        ram[2413] = "0b00";
        ram[2414] = "0b00";
        ram[2415] = "0b01";
        for (unsigned i = 2416; i < 2429 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2429] = "0b01";
        for (unsigned i = 2430; i < 2442 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2442] = "0b11";
        for (unsigned i = 2443; i < 2464 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2464] = "0b01";
        ram[2465] = "0b00";
        ram[2466] = "0b00";
        ram[2467] = "0b00";
        ram[2468] = "0b01";
        ram[2469] = "0b00";
        ram[2470] = "0b00";
        ram[2471] = "0b00";
        ram[2472] = "0b00";
        ram[2473] = "0b11";
        for (unsigned i = 2474; i < 2480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2480] = "0b11";
        ram[2481] = "0b00";
        ram[2482] = "0b00";
        ram[2483] = "0b00";
        ram[2484] = "0b11";
        ram[2485] = "0b11";
        for (unsigned i = 2486; i < 2514 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2514] = "0b01";
        ram[2515] = "0b01";
        ram[2516] = "0b00";
        ram[2517] = "0b00";
        ram[2518] = "0b00";
        ram[2519] = "0b11";
        for (unsigned i = 2520; i < 2531 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2531] = "0b11";
        ram[2532] = "0b11";
        ram[2533] = "0b11";
        for (unsigned i = 2534; i < 2567 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2567] = "0b11";
        for (unsigned i = 2568; i < 2613 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2613] = "0b11";
        ram[2614] = "0b00";
        ram[2615] = "0b01";
        for (unsigned i = 2616; i < 2669 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2669] = "0b01";
        ram[2670] = "0b00";
        ram[2671] = "0b00";
        ram[2672] = "0b00";
        ram[2673] = "0b00";
        ram[2674] = "0b11";
        for (unsigned i = 2675; i < 2680 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2680] = "0b01";
        for (unsigned i = 2681; i < 2718 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2718] = "0b11";
        for (unsigned i = 2719; i < 2725 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2725] = "0b11";
        ram[2726] = "0b00";
        ram[2727] = "0b01";
        for (unsigned i = 2728; i < 2762 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2762] = "0b11";
        for (unsigned i = 2763; i < 2812 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2812] = "0b01";
        ram[2813] = "0b00";
        ram[2814] = "0b00";
        ram[2815] = "0b00";
        ram[2816] = "0b11";
        ram[2817] = "0b00";
        ram[2818] = "0b00";
        ram[2819] = "0b00";
        ram[2820] = "0b00";
        ram[2821] = "0b11";
        ram[2822] = "0b00";
        ram[2823] = "0b01";
        ram[2824] = "0b00";
        ram[2825] = "0b00";
        ram[2826] = "0b00";
        ram[2827] = "0b00";
        ram[2828] = "0b11";
        for (unsigned i = 2829; i < 2853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2853] = "0b11";
        ram[2854] = "0b00";
        ram[2855] = "0b11";
        ram[2856] = "0b00";
        ram[2857] = "0b00";
        ram[2858] = "0b11";
        for (unsigned i = 2859; i < 2876 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2876] = "0b11";
        for (unsigned i = 2877; i < 2886 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2886] = "0b11";
        for (unsigned i = 2887; i < 2900 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2900] = "0b01";
        for (unsigned i = 2901; i < 2909 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2909] = "0b01";
        for (unsigned i = 2910; i < 2953 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2953] = "0b01";
        for (unsigned i = 2954; i < 2966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2966] = "0b11";
        ram[2967] = "0b11";
        for (unsigned i = 2968; i < 2975 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2975] = "0b01";
        for (unsigned i = 2976; i < 2984 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2984] = "0b01";
        for (unsigned i = 2985; i < 3003 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3003] = "0b01";
        for (unsigned i = 3004; i < 3012 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3012] = "0b11";
        ram[3013] = "0b00";
        ram[3014] = "0b00";
        ram[3015] = "0b00";
        ram[3016] = "0b00";
        ram[3017] = "0b11";
        ram[3018] = "0b00";
        ram[3019] = "0b00";
        ram[3020] = "0b00";
        ram[3021] = "0b11";
        ram[3022] = "0b11";
        for (unsigned i = 3023; i < 3028 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3028] = "0b11";
        for (unsigned i = 3029; i < 3056 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3056] = "0b11";
        for (unsigned i = 3057; i < 3098 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3098] = "0b11";
        for (unsigned i = 3099; i < 3114 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3114] = "0b11";
        ram[3115] = "0b11";
        ram[3116] = "0b00";
        ram[3117] = "0b00";
        ram[3118] = "0b00";
        ram[3119] = "0b00";
        ram[3120] = "0b11";
        for (unsigned i = 3121; i < 3131 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3131] = "0b01";
        for (unsigned i = 3132; i < 3142 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3142] = "0b01";
        ram[3143] = "0b00";
        ram[3144] = "0b00";
        ram[3145] = "0b00";
        ram[3146] = "0b00";
        ram[3147] = "0b01";
        for (unsigned i = 3148; i < 3154 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3154] = "0b11";
        ram[3155] = "0b00";
        ram[3156] = "0b11";
        for (unsigned i = 3157; i < 3180 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3180] = "0b01";
        for (unsigned i = 3181; i < 3194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3194] = "0b11";
        for (unsigned i = 3195; i < 3201 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3201] = "0b01";
        ram[3202] = "0b00";
        ram[3203] = "0b11";
        for (unsigned i = 3204; i < 3215 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3215] = "0b01";
        for (unsigned i = 3216; i < 3296 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3296] = "0b11";
        ram[3297] = "0b00";
        ram[3298] = "0b00";
        ram[3299] = "0b01";
        for (unsigned i = 3300; i < 3306 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3306] = "0b11";
        for (unsigned i = 3307; i < 3315 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3315] = "0b01";
        ram[3316] = "0b11";
        for (unsigned i = 3317; i < 3322 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3322] = "0b11";
        for (unsigned i = 3323; i < 3341 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3341] = "0b11";
        for (unsigned i = 3342; i < 3374 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3374] = "0b11";
        for (unsigned i = 3375; i < 3392 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3392] = "0b01";
        for (unsigned i = 3393; i < 3400 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3400] = "0b11";
        ram[3401] = "0b00";
        ram[3402] = "0b11";
        for (unsigned i = 3403; i < 3411 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3411] = "0b01";
        for (unsigned i = 3412; i < 3451 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3451] = "0b11";
        ram[3452] = "0b00";
        ram[3453] = "0b00";
        ram[3454] = "0b00";
        ram[3455] = "0b00";
        ram[3456] = "0b11";
        for (unsigned i = 3457; i < 3474 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3474] = "0b11";
        for (unsigned i = 3475; i < 3511 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3511] = "0b11";
        for (unsigned i = 3512; i < 3590 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3590] = "0b01";
        ram[3591] = "0b00";
        ram[3592] = "0b00";
        ram[3593] = "0b00";
        ram[3594] = "0b00";
        ram[3595] = "0b11";
        for (unsigned i = 3596; i < 3670 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3670] = "0b11";
        for (unsigned i = 3671; i < 3700 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3700] = "0b11";
        ram[3701] = "0b00";
        ram[3702] = "0b01";
        for (unsigned i = 3703; i < 3708 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3708] = "0b11";
        ram[3709] = "0b00";
        ram[3710] = "0b00";
        ram[3711] = "0b00";
        ram[3712] = "0b01";
        for (unsigned i = 3713; i < 3782 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3782] = "0b11";
        ram[3783] = "0b00";
        ram[3784] = "0b01";
        ram[3785] = "0b00";
        ram[3786] = "0b00";
        ram[3787] = "0b11";
        for (unsigned i = 3788; i < 3793 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3793] = "0b01";
        for (unsigned i = 3794; i < 3855 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3855] = "0b11";
        for (unsigned i = 3856; i < 3862 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3862] = "0b01";
        ram[3863] = "0b00";
        ram[3864] = "0b00";
        ram[3865] = "0b00";
        ram[3866] = "0b01";
        for (unsigned i = 3867; i < 3896 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3896] = "0b01";
        ram[3897] = "0b00";
        ram[3898] = "0b00";
        ram[3899] = "0b00";
        ram[3900] = "0b00";
        ram[3901] = "0b11";
        ram[3902] = "0b00";
        ram[3903] = "0b01";
        for (unsigned i = 3904; i < 3976 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3976] = "0b11";
        for (unsigned i = 3977; i < 3995 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3995] = "0b01";
        ram[3996] = "0b00";
        ram[3997] = "0b01";
        ram[3998] = "0b11";
        ram[3999] = "0b01";
        ram[4000] = "0b00";
        ram[4001] = "0b00";
        ram[4002] = "0b11";
        ram[4003] = "0b00";
        ram[4004] = "0b11";
        ram[4005] = "0b00";
        ram[4006] = "0b11";
        for (unsigned i = 4007; i < 4032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4032] = "0b11";
        for (unsigned i = 4033; i < 4080 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4080] = "0b11";
        ram[4081] = "0b00";
        ram[4082] = "0b00";
        ram[4083] = "0b11";
        for (unsigned i = 4084; i < 4094 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4094] = "0b01";
        for (unsigned i = 4095; i < 4188 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4188] = "0b01";
        ram[4189] = "0b00";
        ram[4190] = "0b00";
        ram[4191] = "0b00";
        ram[4192] = "0b00";
        ram[4193] = "0b11";
        ram[4194] = "0b00";
        ram[4195] = "0b11";
        ram[4196] = "0b00";
        ram[4197] = "0b00";
        ram[4198] = "0b00";
        ram[4199] = "0b00";
        ram[4200] = "0b01";
        for (unsigned i = 4201; i < 4255 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4255] = "0b11";
        for (unsigned i = 4256; i < 4286 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4286] = "0b11";
        for (unsigned i = 4287; i < 4324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4324] = "0b11";
        for (unsigned i = 4325; i < 4332 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4332] = "0b11";
        for (unsigned i = 4333; i < 4338 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4338] = "0b11";
        ram[4339] = "0b00";
        ram[4340] = "0b11";
        ram[4341] = "0b00";
        ram[4342] = "0b00";
        ram[4343] = "0b00";
        ram[4344] = "0b01";
        for (unsigned i = 4345; i < 4354 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4354] = "0b01";
        for (unsigned i = 4355; i < 4471 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4471] = "0b11";
        for (unsigned i = 4472; i < 4486 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4486] = "0b11";
        ram[4487] = "0b00";
        ram[4488] = "0b01";
        ram[4489] = "0b00";
        ram[4490] = "0b00";
        ram[4491] = "0b11";
        ram[4492] = "0b00";
        ram[4493] = "0b00";
        ram[4494] = "0b01";
        for (unsigned i = 4495; i < 4501 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4501] = "0b11";
        for (unsigned i = 4502; i < 4522 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4522] = "0b11";
        ram[4523] = "0b00";
        ram[4524] = "0b00";
        ram[4525] = "0b00";
        ram[4526] = "0b01";
        for (unsigned i = 4527; i < 4545 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4545] = "0b01";
        for (unsigned i = 4546; i < 4568 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4568] = "0b11";
        for (unsigned i = 4569; i < 4590 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4590] = "0b01";
        ram[4591] = "0b00";
        ram[4592] = "0b00";
        ram[4593] = "0b00";
        ram[4594] = "0b01";
        for (unsigned i = 4595; i < 4610 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4610] = "0b01";
        for (unsigned i = 4611; i < 4619 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4619] = "0b01";
        ram[4620] = "0b00";
        ram[4621] = "0b00";
        ram[4622] = "0b00";
        ram[4623] = "0b00";
        ram[4624] = "0b10";
        ram[4625] = "0b00";
        ram[4626] = "0b11";
        for (unsigned i = 4627; i < 4718 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4718] = "0b11";
        for (unsigned i = 4719; i < 4736 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4736] = "0b11";
        for (unsigned i = 4737; i < 4743 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4743] = "0b01";
        for (unsigned i = 4744; i < 4825 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4825] = "0b01";
        ram[4826] = "0b00";
        ram[4827] = "0b00";
        ram[4828] = "0b00";
        ram[4829] = "0b11";
        for (unsigned i = 4830; i < 4846 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4846] = "0b01";
        for (unsigned i = 4847; i < 4863 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4863] = "0b11";
        ram[4864] = "0b00";
        ram[4865] = "0b00";
        ram[4866] = "0b00";
        ram[4867] = "0b01";
        for (unsigned i = 4868; i < 4879 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4879] = "0b01";
        ram[4880] = "0b00";
        ram[4881] = "0b11";
        ram[4882] = "0b00";
        ram[4883] = "0b11";
        ram[4884] = "0b00";
        ram[4885] = "0b00";
        ram[4886] = "0b01";
        for (unsigned i = 4887; i < 4892 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4892] = "0b11";
        for (unsigned i = 4893; i < 4912 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4912] = "0b01";
        ram[4913] = "0b00";
        ram[4914] = "0b01";
        ram[4915] = "0b00";
        ram[4916] = "0b11";
        for (unsigned i = 4917; i < 4937 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4937] = "0b01";
        ram[4938] = "0b00";
        ram[4939] = "0b00";
        ram[4940] = "0b00";
        ram[4941] = "0b00";
        ram[4942] = "0b11";
        ram[4943] = "0b00";
        ram[4944] = "0b00";
        ram[4945] = "0b00";
        ram[4946] = "0b11";
        for (unsigned i = 4947; i < 4983 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4983] = "0b11";
        for (unsigned i = 4984; i < 5010 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5010] = "0b11";
        for (unsigned i = 5011; i < 5035 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5035] = "0b01";
        for (unsigned i = 5036; i < 5061 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5061] = "0b11";
        for (unsigned i = 5062; i < 5073 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5073] = "0b01";
        for (unsigned i = 5074; i < 5081 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5081] = "0b11";
        ram[5082] = "0b00";
        ram[5083] = "0b00";
        ram[5084] = "0b00";
        ram[5085] = "0b00";
        ram[5086] = "0b11";
        for (unsigned i = 5087; i < 5161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5161] = "0b11";
        ram[5162] = "0b00";
        ram[5163] = "0b00";
        ram[5164] = "0b11";
        for (unsigned i = 5165; i < 5222 ; i = i + 1) {
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
        for (unsigned i = 5230; i < 5301 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5301] = "0b11";
        for (unsigned i = 5302; i < 5307 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5307] = "0b11";
        ram[5308] = "0b11";
        ram[5309] = "0b00";
        ram[5310] = "0b01";
        for (unsigned i = 5311; i < 5322 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5322] = "0b01";
        for (unsigned i = 5323; i < 5331 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5331] = "0b11";
        ram[5332] = "0b01";
        for (unsigned i = 5333; i < 5362 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5362] = "0b11";
        ram[5363] = "0b00";
        ram[5364] = "0b01";
        ram[5365] = "0b00";
        ram[5366] = "0b00";
        ram[5367] = "0b00";
        ram[5368] = "0b00";
        ram[5369] = "0b01";
        ram[5370] = "0b01";
        for (unsigned i = 5371; i < 5380 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5380] = "0b11";
        for (unsigned i = 5381; i < 5399 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5399] = "0b11";
        ram[5400] = "0b00";
        ram[5401] = "0b00";
        ram[5402] = "0b11";
        for (unsigned i = 5403; i < 5418 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5418] = "0b01";
        for (unsigned i = 5419; i < 5436 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5436] = "0b01";
        for (unsigned i = 5437; i < 5443 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5443] = "0b01";
        for (unsigned i = 5444; i < 5450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5450] = "0b11";
        ram[5451] = "0b00";
        ram[5452] = "0b11";
        for (unsigned i = 5453; i < 5468 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5468] = "0b01";
        for (unsigned i = 5469; i < 5476 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5476] = "0b01";
        for (unsigned i = 5477; i < 5504 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5504] = "0b01";
        ram[5505] = "0b00";
        ram[5506] = "0b00";
        ram[5507] = "0b01";
        ram[5508] = "0b00";
        ram[5509] = "0b01";
        ram[5510] = "0b00";
        ram[5511] = "0b11";
        for (unsigned i = 5512; i < 5530 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5530] = "0b11";
        for (unsigned i = 5531; i < 5544 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5544] = "0b11";
        for (unsigned i = 5545; i < 5567 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5567] = "0b01";
        for (unsigned i = 5568; i < 5642 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5642] = "0b11";
        ram[5643] = "0b00";
        ram[5644] = "0b01";
        ram[5645] = "0b00";
        ram[5646] = "0b11";
        ram[5647] = "0b00";
        ram[5648] = "0b00";
        ram[5649] = "0b00";
        ram[5650] = "0b01";
        ram[5651] = "0b00";
        ram[5652] = "0b00";
        ram[5653] = "0b01";
        for (unsigned i = 5654; i < 5719 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5719] = "0b11";
        for (unsigned i = 5720; i < 5726 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5726] = "0b11";
        for (unsigned i = 5727; i < 5789 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5789] = "0b01";
        for (unsigned i = 5790; i < 5819 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5819] = "0b01";
        for (unsigned i = 5820; i < 5844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5844] = "0b01";
        ram[5845] = "0b00";
        ram[5846] = "0b11";
        ram[5847] = "0b00";
        ram[5848] = "0b00";
        ram[5849] = "0b00";
        ram[5850] = "0b00";
        ram[5851] = "0b01";
        ram[5852] = "0b00";
        ram[5853] = "0b11";
        for (unsigned i = 5854; i < 5863 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5863] = "0b01";
        for (unsigned i = 5864; i < 5875 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5875] = "0b11";
        for (unsigned i = 5876; i < 5950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5950] = "0b01";
        for (unsigned i = 5951; i < 5991 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5991] = "0b11";
        for (unsigned i = 5992; i < 6006 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6006] = "0b01";
        for (unsigned i = 6007; i < 6019 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6019] = "0b11";
        for (unsigned i = 6020; i < 6043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6043] = "0b11";
        ram[6044] = "0b00";
        ram[6045] = "0b00";
        ram[6046] = "0b11";
        ram[6047] = "0b00";
        ram[6048] = "0b11";
        for (unsigned i = 6049; i < 6092 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6092] = "0b11";
        for (unsigned i = 6093; i < 6099 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6099] = "0b01";
        ram[6100] = "0b00";
        ram[6101] = "0b00";
        ram[6102] = "0b00";
        ram[6103] = "0b11";
        ram[6104] = "0b00";
        ram[6105] = "0b01";
        for (unsigned i = 6106; i < 6113 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6113] = "0b11";
        ram[6114] = "0b00";
        ram[6115] = "0b11";
        ram[6116] = "0b00";
        ram[6117] = "0b00";
        ram[6118] = "0b11";
        ram[6119] = "0b00";
        ram[6120] = "0b11";
        for (unsigned i = 6121; i < 6139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6139] = "0b11";
        for (unsigned i = 6140; i < 6155 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6155] = "0b01";
        for (unsigned i = 6156; i < 6192 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6192] = "0b01";
        ram[6193] = "0b11";
        for (unsigned i = 6194; i < 6206 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6206] = "0b11";
        for (unsigned i = 6207; i < 6241 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6241] = "0b01";
        ram[6242] = "0b00";
        ram[6243] = "0b00";
        ram[6244] = "0b00";
        ram[6245] = "0b00";
        ram[6246] = "0b11";
        ram[6247] = "0b00";
        ram[6248] = "0b00";
        ram[6249] = "0b00";
        ram[6250] = "0b01";
        for (unsigned i = 6251; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_9) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_9_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_9) {
meminst = new mlp_accel_4b_weights_l1_4b_9_ram("mlp_accel_4b_weights_l1_4b_9_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_9() {
    delete meminst;
}


};//endmodule
#endif
