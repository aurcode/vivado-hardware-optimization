// ==============================================================
// File generated on Wed Sep 02 16:33:43 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_6_H__
#define __mlp_accel_4b_weights_l1_4b_6_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_6_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_6_ram) {
        for (unsigned i = 0; i < 70 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[70] = "0b01";
        for (unsigned i = 71; i < 90 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[90] = "0b11";
        for (unsigned i = 91; i < 107 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[107] = "0b01";
        for (unsigned i = 108; i < 116 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[116] = "0b11";
        for (unsigned i = 117; i < 126 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[126] = "0b01";
        for (unsigned i = 127; i < 132 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[132] = "0b01";
        ram[133] = "0b00";
        ram[134] = "0b01";
        ram[135] = "0b11";
        for (unsigned i = 136; i < 141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[141] = "0b01";
        for (unsigned i = 142; i < 153 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[153] = "0b01";
        ram[154] = "0b00";
        ram[155] = "0b00";
        ram[156] = "0b11";
        for (unsigned i = 157; i < 165 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[165] = "0b01";
        ram[166] = "0b00";
        ram[167] = "0b00";
        ram[168] = "0b00";
        ram[169] = "0b00";
        ram[170] = "0b01";
        for (unsigned i = 171; i < 179 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[179] = "0b01";
        for (unsigned i = 180; i < 189 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[189] = "0b11";
        for (unsigned i = 190; i < 242 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[242] = "0b01";
        for (unsigned i = 243; i < 305 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[305] = "0b11";
        ram[306] = "0b00";
        ram[307] = "0b00";
        ram[308] = "0b00";
        ram[309] = "0b00";
        ram[310] = "0b01";
        for (unsigned i = 311; i < 319 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[319] = "0b11";
        for (unsigned i = 320; i < 349 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[349] = "0b01";
        for (unsigned i = 350; i < 361 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[361] = "0b11";
        for (unsigned i = 362; i < 373 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[373] = "0b11";
        for (unsigned i = 374; i < 419 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[419] = "0b01";
        for (unsigned i = 420; i < 429 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[429] = "0b11";
        for (unsigned i = 430; i < 454 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[454] = "0b11";
        ram[455] = "0b00";
        ram[456] = "0b00";
        ram[457] = "0b00";
        ram[458] = "0b00";
        ram[459] = "0b11";
        for (unsigned i = 460; i < 498 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[498] = "0b11";
        for (unsigned i = 499; i < 511 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[511] = "0b10";
        for (unsigned i = 512; i < 518 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[518] = "0b01";
        for (unsigned i = 519; i < 554 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[554] = "0b11";
        ram[555] = "0b01";
        for (unsigned i = 556; i < 581 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[581] = "0b11";
        for (unsigned i = 582; i < 599 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[599] = "0b11";
        for (unsigned i = 600; i < 623 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[623] = "0b11";
        for (unsigned i = 624; i < 648 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[648] = "0b01";
        ram[649] = "0b00";
        ram[650] = "0b01";
        ram[651] = "0b00";
        ram[652] = "0b00";
        ram[653] = "0b00";
        ram[654] = "0b00";
        ram[655] = "0b11";
        for (unsigned i = 656; i < 674 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[674] = "0b01";
        for (unsigned i = 675; i < 697 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[697] = "0b11";
        for (unsigned i = 698; i < 704 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[704] = "0b11";
        for (unsigned i = 705; i < 718 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[718] = "0b01";
        for (unsigned i = 719; i < 725 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[725] = "0b11";
        for (unsigned i = 726; i < 804 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[804] = "0b01";
        ram[805] = "0b11";
        for (unsigned i = 806; i < 816 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[816] = "0b11";
        for (unsigned i = 817; i < 825 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[825] = "0b01";
        ram[826] = "0b00";
        ram[827] = "0b00";
        ram[828] = "0b01";
        for (unsigned i = 829; i < 841 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[841] = "0b11";
        ram[842] = "0b00";
        ram[843] = "0b00";
        ram[844] = "0b00";
        ram[845] = "0b00";
        ram[846] = "0b11";
        ram[847] = "0b01";
        for (unsigned i = 848; i < 853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[853] = "0b01";
        ram[854] = "0b11";
        for (unsigned i = 855; i < 865 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[865] = "0b01";
        ram[866] = "0b00";
        ram[867] = "0b00";
        ram[868] = "0b00";
        ram[869] = "0b11";
        ram[870] = "0b00";
        ram[871] = "0b00";
        ram[872] = "0b00";
        ram[873] = "0b00";
        ram[874] = "0b11";
        for (unsigned i = 875; i < 900 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[900] = "0b01";
        for (unsigned i = 901; i < 940 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[940] = "0b01";
        for (unsigned i = 941; i < 947 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[947] = "0b11";
        ram[948] = "0b00";
        ram[949] = "0b00";
        ram[950] = "0b00";
        ram[951] = "0b00";
        ram[952] = "0b11";
        ram[953] = "0b00";
        ram[954] = "0b01";
        for (unsigned i = 955; i < 961 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[961] = "0b11";
        for (unsigned i = 962; i < 967 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[967] = "0b01";
        ram[968] = "0b00";
        ram[969] = "0b00";
        ram[970] = "0b00";
        ram[971] = "0b00";
        ram[972] = "0b11";
        for (unsigned i = 973; i < 1021 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1021] = "0b01";
        for (unsigned i = 1022; i < 1047 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1047] = "0b01";
        for (unsigned i = 1048; i < 1056 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1056] = "0b11";
        for (unsigned i = 1057; i < 1098 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1098] = "0b01";
        for (unsigned i = 1099; i < 1119 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1119] = "0b11";
        for (unsigned i = 1120; i < 1138 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1138] = "0b01";
        for (unsigned i = 1139; i < 1196 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1196] = "0b01";
        for (unsigned i = 1197; i < 1205 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1205] = "0b11";
        ram[1206] = "0b11";
        for (unsigned i = 1207; i < 1217 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1217] = "0b11";
        ram[1218] = "0b00";
        ram[1219] = "0b00";
        ram[1220] = "0b01";
        ram[1221] = "0b00";
        ram[1222] = "0b01";
        for (unsigned i = 1223; i < 1385 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1385] = "0b01";
        for (unsigned i = 1386; i < 1400 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1400] = "0b11";
        ram[1401] = "0b00";
        ram[1402] = "0b11";
        ram[1403] = "0b00";
        ram[1404] = "0b00";
        ram[1405] = "0b00";
        ram[1406] = "0b00";
        ram[1407] = "0b11";
        for (unsigned i = 1408; i < 1416 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1416] = "0b11";
        for (unsigned i = 1417; i < 1437 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1437] = "0b11";
        for (unsigned i = 1438; i < 1446 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1446] = "0b11";
        ram[1447] = "0b00";
        ram[1448] = "0b00";
        ram[1449] = "0b00";
        ram[1450] = "0b00";
        ram[1451] = "0b01";
        for (unsigned i = 1452; i < 1491 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1491] = "0b01";
        for (unsigned i = 1492; i < 1532 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1532] = "0b11";
        for (unsigned i = 1533; i < 1542 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1542] = "0b01";
        for (unsigned i = 1543; i < 1549 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1549] = "0b01";
        ram[1550] = "0b00";
        ram[1551] = "0b00";
        ram[1552] = "0b00";
        ram[1553] = "0b11";
        ram[1554] = "0b11";
        for (unsigned i = 1555; i < 1623 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1623] = "0b11";
        for (unsigned i = 1624; i < 1633 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1633] = "0b01";
        for (unsigned i = 1634; i < 1639 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1639] = "0b11";
        ram[1640] = "0b11";
        for (unsigned i = 1641; i < 1828 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1828] = "0b11";
        ram[1829] = "0b00";
        ram[1830] = "0b00";
        ram[1831] = "0b11";
        for (unsigned i = 1832; i < 1845 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1845] = "0b01";
        for (unsigned i = 1846; i < 1903 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1903] = "0b01";
        for (unsigned i = 1904; i < 1938 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1938] = "0b11";
        ram[1939] = "0b00";
        ram[1940] = "0b11";
        ram[1941] = "0b00";
        ram[1942] = "0b00";
        ram[1943] = "0b11";
        for (unsigned i = 1944; i < 1966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1966] = "0b01";
        for (unsigned i = 1967; i < 1975 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1975] = "0b11";
        ram[1976] = "0b11";
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
        for (unsigned i = 2002; i < 2018 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2018] = "0b11";
        for (unsigned i = 2019; i < 2030 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2030] = "0b11";
        ram[2031] = "0b00";
        ram[2032] = "0b11";
        ram[2033] = "0b00";
        ram[2034] = "0b00";
        ram[2035] = "0b00";
        ram[2036] = "0b01";
        for (unsigned i = 2037; i < 2043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2043] = "0b11";
        for (unsigned i = 2044; i < 2090 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2090] = "0b11";
        for (unsigned i = 2091; i < 2123 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2123] = "0b01";
        ram[2124] = "0b00";
        ram[2125] = "0b11";
        for (unsigned i = 2126; i < 2153 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2153] = "0b01";
        for (unsigned i = 2154; i < 2223 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2223] = "0b01";
        for (unsigned i = 2224; i < 2246 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2246] = "0b01";
        for (unsigned i = 2247; i < 2326 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2326] = "0b01";
        ram[2327] = "0b00";
        ram[2328] = "0b00";
        ram[2329] = "0b00";
        ram[2330] = "0b00";
        ram[2331] = "0b11";
        ram[2332] = "0b00";
        ram[2333] = "0b11";
        for (unsigned i = 2334; i < 2344 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2344] = "0b11";
        for (unsigned i = 2345; i < 2366 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2366] = "0b11";
        ram[2367] = "0b00";
        ram[2368] = "0b11";
        ram[2369] = "0b00";
        ram[2370] = "0b11";
        ram[2371] = "0b00";
        ram[2372] = "0b00";
        ram[2373] = "0b10";
        ram[2374] = "0b00";
        ram[2375] = "0b01";
        ram[2376] = "0b00";
        ram[2377] = "0b00";
        ram[2378] = "0b00";
        ram[2379] = "0b00";
        ram[2380] = "0b01";
        for (unsigned i = 2381; i < 2396 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2396] = "0b01";
        for (unsigned i = 2397; i < 2417 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2417] = "0b01";
        for (unsigned i = 2418; i < 2430 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2430] = "0b01";
        for (unsigned i = 2431; i < 2468 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2468] = "0b11";
        ram[2469] = "0b00";
        ram[2470] = "0b00";
        ram[2471] = "0b00";
        ram[2472] = "0b00";
        ram[2473] = "0b01";
        ram[2474] = "0b00";
        ram[2475] = "0b00";
        ram[2476] = "0b00";
        ram[2477] = "0b01";
        for (unsigned i = 2478; i < 2486 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2486] = "0b11";
        for (unsigned i = 2487; i < 2492 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2492] = "0b11";
        for (unsigned i = 2493; i < 2508 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2508] = "0b11";
        for (unsigned i = 2509; i < 2517 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2517] = "0b01";
        ram[2518] = "0b00";
        ram[2519] = "0b11";
        ram[2520] = "0b00";
        ram[2521] = "0b11";
        ram[2522] = "0b00";
        ram[2523] = "0b00";
        ram[2524] = "0b01";
        for (unsigned i = 2525; i < 2531 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2531] = "0b01";
        ram[2532] = "0b00";
        ram[2533] = "0b00";
        ram[2534] = "0b00";
        ram[2535] = "0b11";
        ram[2536] = "0b00";
        ram[2537] = "0b00";
        ram[2538] = "0b00";
        ram[2539] = "0b00";
        ram[2540] = "0b11";
        ram[2541] = "0b11";
        for (unsigned i = 2542; i < 2613 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2613] = "0b11";
        for (unsigned i = 2614; i < 2639 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2639] = "0b01";
        ram[2640] = "0b00";
        ram[2641] = "0b01";
        for (unsigned i = 2642; i < 2674 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2674] = "0b11";
        ram[2675] = "0b00";
        ram[2676] = "0b11";
        ram[2677] = "0b00";
        ram[2678] = "0b11";
        for (unsigned i = 2679; i < 2690 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2690] = "0b01";
        for (unsigned i = 2691; i < 2767 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2767] = "0b01";
        for (unsigned i = 2768; i < 2823 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2823] = "0b10";
        ram[2824] = "0b00";
        ram[2825] = "0b01";
        for (unsigned i = 2826; i < 2853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2853] = "0b11";
        for (unsigned i = 2854; i < 2860 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2860] = "0b11";
        for (unsigned i = 2861; i < 2878 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2878] = "0b11";
        ram[2879] = "0b00";
        ram[2880] = "0b00";
        ram[2881] = "0b00";
        ram[2882] = "0b00";
        ram[2883] = "0b11";
        ram[2884] = "0b00";
        ram[2885] = "0b00";
        ram[2886] = "0b00";
        ram[2887] = "0b00";
        ram[2888] = "0b11";
        for (unsigned i = 2889; i < 2902 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2902] = "0b01";
        for (unsigned i = 2903; i < 2937 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2937] = "0b01";
        for (unsigned i = 2938; i < 2968 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2968] = "0b11";
        ram[2969] = "0b00";
        ram[2970] = "0b01";
        for (unsigned i = 2971; i < 3014 ; i = i + 1) {
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
        for (unsigned i = 3064; i < 3114 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3114] = "0b11";
        ram[3115] = "0b11";
        ram[3116] = "0b00";
        ram[3117] = "0b11";
        for (unsigned i = 3118; i < 3133 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3133] = "0b11";
        for (unsigned i = 3134; i < 3142 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3142] = "0b01";
        ram[3143] = "0b00";
        ram[3144] = "0b00";
        ram[3145] = "0b01";
        ram[3146] = "0b00";
        ram[3147] = "0b01";
        ram[3148] = "0b00";
        ram[3149] = "0b01";
        ram[3150] = "0b00";
        ram[3151] = "0b11";
        ram[3152] = "0b00";
        ram[3153] = "0b00";
        ram[3154] = "0b11";
        for (unsigned i = 3155; i < 3182 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3182] = "0b01";
        for (unsigned i = 3183; i < 3201 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3201] = "0b01";
        for (unsigned i = 3202; i < 3298 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3298] = "0b11";
        for (unsigned i = 3299; i < 3324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3324] = "0b11";
        for (unsigned i = 3325; i < 3355 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3355] = "0b01";
        for (unsigned i = 3356; i < 3392 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3392] = "0b01";
        ram[3393] = "0b00";
        ram[3394] = "0b00";
        ram[3395] = "0b00";
        ram[3396] = "0b01";
        ram[3397] = "0b00";
        ram[3398] = "0b00";
        ram[3399] = "0b11";
        ram[3400] = "0b00";
        ram[3401] = "0b00";
        ram[3402] = "0b11";
        ram[3403] = "0b00";
        ram[3404] = "0b11";
        ram[3405] = "0b00";
        ram[3406] = "0b00";
        ram[3407] = "0b00";
        ram[3408] = "0b00";
        ram[3409] = "0b01";
        for (unsigned i = 3410; i < 3448 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3448] = "0b11";
        ram[3449] = "0b00";
        ram[3450] = "0b00";
        ram[3451] = "0b00";
        ram[3452] = "0b00";
        ram[3453] = "0b10";
        ram[3454] = "0b00";
        ram[3455] = "0b00";
        ram[3456] = "0b00";
        ram[3457] = "0b00";
        ram[3458] = "0b11";
        for (unsigned i = 3459; i < 3464 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3464] = "0b11";
        for (unsigned i = 3465; i < 3490 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3490] = "0b01";
        ram[3491] = "0b00";
        ram[3492] = "0b00";
        ram[3493] = "0b00";
        ram[3494] = "0b00";
        ram[3495] = "0b01";
        for (unsigned i = 3496; i < 3560 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3560] = "0b11";
        ram[3561] = "0b00";
        ram[3562] = "0b00";
        ram[3563] = "0b00";
        ram[3564] = "0b00";
        ram[3565] = "0b11";
        for (unsigned i = 3566; i < 3595 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3595] = "0b11";
        ram[3596] = "0b00";
        ram[3597] = "0b11";
        ram[3598] = "0b00";
        ram[3599] = "0b00";
        ram[3600] = "0b01";
        for (unsigned i = 3601; i < 3670 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3670] = "0b11";
        for (unsigned i = 3671; i < 3700 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3700] = "0b01";
        ram[3701] = "0b00";
        ram[3702] = "0b00";
        ram[3703] = "0b00";
        ram[3704] = "0b00";
        ram[3705] = "0b11";
        ram[3706] = "0b00";
        ram[3707] = "0b11";
        for (unsigned i = 3708; i < 3714 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3714] = "0b01";
        ram[3715] = "0b00";
        ram[3716] = "0b01";
        for (unsigned i = 3717; i < 3786 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3786] = "0b01";
        for (unsigned i = 3787; i < 3819 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3819] = "0b01";
        for (unsigned i = 3820; i < 3840 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3840] = "0b11";
        ram[3841] = "0b00";
        ram[3842] = "0b00";
        ram[3843] = "0b01";
        for (unsigned i = 3844; i < 3850 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3850] = "0b11";
        ram[3851] = "0b00";
        ram[3852] = "0b11";
        for (unsigned i = 3853; i < 3859 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3859] = "0b01";
        for (unsigned i = 3860; i < 3891 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3891] = "0b01";
        ram[3892] = "0b00";
        ram[3893] = "0b00";
        ram[3894] = "0b01";
        ram[3895] = "0b00";
        ram[3896] = "0b11";
        ram[3897] = "0b00";
        ram[3898] = "0b01";
        ram[3899] = "0b00";
        ram[3900] = "0b11";
        for (unsigned i = 3901; i < 3952 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3952] = "0b11";
        for (unsigned i = 3953; i < 3975 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3975] = "0b01";
        ram[3976] = "0b00";
        ram[3977] = "0b01";
        for (unsigned i = 3978; i < 3990 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3990] = "0b01";
        for (unsigned i = 3991; i < 4004 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4004] = "0b11";
        for (unsigned i = 4005; i < 4011 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4011] = "0b01";
        ram[4012] = "0b00";
        ram[4013] = "0b00";
        ram[4014] = "0b00";
        ram[4015] = "0b01";
        for (unsigned i = 4016; i < 4059 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4059] = "0b11";
        for (unsigned i = 4060; i < 4080 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4080] = "0b01";
        ram[4081] = "0b00";
        ram[4082] = "0b00";
        ram[4083] = "0b11";
        for (unsigned i = 4084; i < 4097 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4097] = "0b11";
        for (unsigned i = 4098; i < 4174 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4174] = "0b01";
        for (unsigned i = 4175; i < 4193 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4193] = "0b11";
        ram[4194] = "0b01";
        ram[4195] = "0b11";
        for (unsigned i = 4196; i < 4232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4232] = "0b01";
        for (unsigned i = 4233; i < 4244 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4244] = "0b01";
        ram[4245] = "0b00";
        ram[4246] = "0b11";
        for (unsigned i = 4247; i < 4281 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4281] = "0b11";
        for (unsigned i = 4282; i < 4334 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4334] = "0b11";
        for (unsigned i = 4335; i < 4340 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4340] = "0b11";
        ram[4341] = "0b11";
        ram[4342] = "0b11";
        ram[4343] = "0b00";
        ram[4344] = "0b00";
        ram[4345] = "0b00";
        ram[4346] = "0b01";
        for (unsigned i = 4347; i < 4375 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4375] = "0b01";
        for (unsigned i = 4376; i < 4405 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4405] = "0b01";
        for (unsigned i = 4406; i < 4428 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4428] = "0b01";
        for (unsigned i = 4429; i < 4480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4480] = "0b11";
        for (unsigned i = 4481; i < 4486 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4486] = "0b11";
        for (unsigned i = 4487; i < 4535 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4535] = "0b11";
        for (unsigned i = 4536; i < 4570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4570] = "0b11";
        for (unsigned i = 4571; i < 4619 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4619] = "0b01";
        ram[4620] = "0b00";
        ram[4621] = "0b00";
        ram[4622] = "0b00";
        ram[4623] = "0b00";
        ram[4624] = "0b11";
        ram[4625] = "0b00";
        ram[4626] = "0b10";
        ram[4627] = "0b00";
        ram[4628] = "0b11";
        for (unsigned i = 4629; i < 4827 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4827] = "0b01";
        for (unsigned i = 4828; i < 4843 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4843] = "0b01";
        for (unsigned i = 4844; i < 4869 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4869] = "0b01";
        ram[4870] = "0b00";
        ram[4871] = "0b00";
        ram[4872] = "0b00";
        ram[4873] = "0b01";
        for (unsigned i = 4874; i < 4881 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4881] = "0b01";
        ram[4882] = "0b00";
        ram[4883] = "0b00";
        ram[4884] = "0b00";
        ram[4885] = "0b11";
        ram[4886] = "0b00";
        ram[4887] = "0b00";
        ram[4888] = "0b01";
        ram[4889] = "0b00";
        ram[4890] = "0b00";
        ram[4891] = "0b00";
        ram[4892] = "0b11";
        ram[4893] = "0b00";
        ram[4894] = "0b00";
        ram[4895] = "0b01";
        for (unsigned i = 4896; i < 4906 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4906] = "0b11";
        ram[4907] = "0b00";
        ram[4908] = "0b00";
        ram[4909] = "0b00";
        ram[4910] = "0b00";
        ram[4911] = "0b11";
        for (unsigned i = 4912; i < 4918 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4918] = "0b11";
        for (unsigned i = 4919; i < 4932 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4932] = "0b01";
        for (unsigned i = 4933; i < 4946 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4946] = "0b11";
        for (unsigned i = 4947; i < 5034 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5034] = "0b01";
        for (unsigned i = 5035; i < 5056 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5056] = "0b11";
        ram[5057] = "0b00";
        ram[5058] = "0b00";
        ram[5059] = "0b00";
        ram[5060] = "0b01";
        ram[5061] = "0b00";
        ram[5062] = "0b00";
        ram[5063] = "0b00";
        ram[5064] = "0b00";
        ram[5065] = "0b01";
        for (unsigned i = 5066; i < 5161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5161] = "0b11";
        for (unsigned i = 5162; i < 5168 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5168] = "0b01";
        for (unsigned i = 5169; i < 5186 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5186] = "0b11";
        for (unsigned i = 5187; i < 5216 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5216] = "0b11";
        for (unsigned i = 5217; i < 5222 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5222] = "0b11";
        ram[5223] = "0b00";
        ram[5224] = "0b10";
        for (unsigned i = 5225; i < 5231 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5231] = "0b01";
        for (unsigned i = 5232; i < 5280 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5280] = "0b11";
        for (unsigned i = 5281; i < 5312 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5312] = "0b01";
        for (unsigned i = 5313; i < 5324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5324] = "0b11";
        ram[5325] = "0b00";
        ram[5326] = "0b11";
        for (unsigned i = 5327; i < 5336 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5336] = "0b11";
        for (unsigned i = 5337; i < 5361 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5361] = "0b11";
        ram[5362] = "0b11";
        for (unsigned i = 5363; i < 5399 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5399] = "0b11";
        for (unsigned i = 5400; i < 5418 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5418] = "0b01";
        ram[5419] = "0b00";
        ram[5420] = "0b01";
        ram[5421] = "0b00";
        ram[5422] = "0b00";
        ram[5423] = "0b00";
        ram[5424] = "0b00";
        ram[5425] = "0b11";
        ram[5426] = "0b00";
        ram[5427] = "0b11";
        for (unsigned i = 5428; i < 5436 ; i = i + 1) {
            ram[i] = "0b00";
        }
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
        for (unsigned i = 5481; i < 5497 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5497] = "0b11";
        ram[5498] = "0b00";
        ram[5499] = "0b00";
        ram[5500] = "0b00";
        ram[5501] = "0b11";
        ram[5502] = "0b00";
        ram[5503] = "0b00";
        ram[5504] = "0b00";
        ram[5505] = "0b00";
        ram[5506] = "0b01";
        ram[5507] = "0b01";
        ram[5508] = "0b00";
        ram[5509] = "0b00";
        ram[5510] = "0b00";
        ram[5511] = "0b11";
        ram[5512] = "0b00";
        ram[5513] = "0b11";
        for (unsigned i = 5514; i < 5555 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5555] = "0b11";
        ram[5556] = "0b00";
        ram[5557] = "0b01";
        for (unsigned i = 5558; i < 5565 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5565] = "0b11";
        for (unsigned i = 5566; i < 5644 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5644] = "0b11";
        ram[5645] = "0b00";
        ram[5646] = "0b00";
        ram[5647] = "0b00";
        ram[5648] = "0b00";
        ram[5649] = "0b11";
        ram[5650] = "0b00";
        ram[5651] = "0b00";
        ram[5652] = "0b00";
        ram[5653] = "0b11";
        for (unsigned i = 5654; i < 5674 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5674] = "0b11";
        ram[5675] = "0b00";
        ram[5676] = "0b11";
        ram[5677] = "0b00";
        ram[5678] = "0b00";
        ram[5679] = "0b00";
        ram[5680] = "0b00";
        ram[5681] = "0b11";
        for (unsigned i = 5682; i < 5758 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5758] = "0b01";
        for (unsigned i = 5759; i < 5814 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5814] = "0b11";
        ram[5815] = "0b00";
        ram[5816] = "0b00";
        ram[5817] = "0b00";
        ram[5818] = "0b01";
        ram[5819] = "0b00";
        ram[5820] = "0b00";
        ram[5821] = "0b01";
        ram[5822] = "0b00";
        ram[5823] = "0b01";
        for (unsigned i = 5824; i < 5844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5844] = "0b01";
        ram[5845] = "0b00";
        ram[5846] = "0b01";
        ram[5847] = "0b00";
        ram[5848] = "0b00";
        ram[5849] = "0b11";
        ram[5850] = "0b00";
        ram[5851] = "0b01";
        for (unsigned i = 5852; i < 5873 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5873] = "0b01";
        ram[5874] = "0b00";
        ram[5875] = "0b01";
        for (unsigned i = 5876; i < 5938 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5938] = "0b11";
        ram[5939] = "0b00";
        ram[5940] = "0b00";
        ram[5941] = "0b00";
        ram[5942] = "0b00";
        ram[5943] = "0b11";
        for (unsigned i = 5944; i < 5954 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5954] = "0b01";
        for (unsigned i = 5955; i < 5986 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5986] = "0b11";
        for (unsigned i = 5987; i < 5993 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5993] = "0b11";
        ram[5994] = "0b00";
        ram[5995] = "0b00";
        ram[5996] = "0b01";
        ram[5997] = "0b00";
        ram[5998] = "0b11";
        ram[5999] = "0b11";
        for (unsigned i = 6000; i < 6024 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6024] = "0b11";
        for (unsigned i = 6025; i < 6036 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6036] = "0b01";
        for (unsigned i = 6037; i < 6045 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6045] = "0b11";
        ram[6046] = "0b00";
        ram[6047] = "0b11";
        ram[6048] = "0b11";
        ram[6049] = "0b11";
        for (unsigned i = 6050; i < 6055 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6055] = "0b01";
        ram[6056] = "0b00";
        ram[6057] = "0b01";
        for (unsigned i = 6058; i < 6068 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6068] = "0b11";
        for (unsigned i = 6069; i < 6094 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6094] = "0b11";
        for (unsigned i = 6095; i < 6104 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6104] = "0b01";
        for (unsigned i = 6105; i < 6115 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6115] = "0b11";
        ram[6116] = "0b00";
        ram[6117] = "0b11";
        for (unsigned i = 6118; i < 6138 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6138] = "0b11";
        ram[6139] = "0b00";
        ram[6140] = "0b00";
        ram[6141] = "0b11";
        for (unsigned i = 6142; i < 6154 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6154] = "0b11";
        ram[6155] = "0b00";
        ram[6156] = "0b00";
        ram[6157] = "0b01";
        for (unsigned i = 6158; i < 6189 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6189] = "0b11";
        for (unsigned i = 6190; i < 6215 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6215] = "0b01";
        for (unsigned i = 6216; i < 6234 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6234] = "0b11";
        for (unsigned i = 6235; i < 6243 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6243] = "0b01";
        ram[6244] = "0b00";
        ram[6245] = "0b00";
        ram[6246] = "0b00";
        ram[6247] = "0b00";
        ram[6248] = "0b11";
        for (unsigned i = 6249; i < 6259 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_6) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_6_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_6) {
meminst = new mlp_accel_4b_weights_l1_4b_6_ram("mlp_accel_4b_weights_l1_4b_6_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_6() {
    delete meminst;
}


};//endmodule
#endif
