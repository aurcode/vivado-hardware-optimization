// ==============================================================
// File generated on Wed Sep 02 16:33:44 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_12_H__
#define __mlp_accel_4b_weights_l1_4b_12_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_12_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_12_ram) {
        for (unsigned i = 0; i < 21 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[21] = "0b11";
        for (unsigned i = 22; i < 72 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[72] = "0b11";
        ram[73] = "0b00";
        ram[74] = "0b00";
        ram[75] = "0b00";
        ram[76] = "0b01";
        for (unsigned i = 77; i < 109 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[109] = "0b01";
        for (unsigned i = 110; i < 125 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[125] = "0b11";
        ram[126] = "0b00";
        ram[127] = "0b00";
        ram[128] = "0b01";
        ram[129] = "0b00";
        ram[130] = "0b00";
        ram[131] = "0b00";
        ram[132] = "0b00";
        ram[133] = "0b11";
        ram[134] = "0b00";
        ram[135] = "0b00";
        ram[136] = "0b00";
        ram[137] = "0b01";
        for (unsigned i = 138; i < 154 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[154] = "0b11";
        ram[155] = "0b00";
        ram[156] = "0b00";
        ram[157] = "0b00";
        ram[158] = "0b00";
        ram[159] = "0b11";
        for (unsigned i = 160; i < 165 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[165] = "0b11";
        ram[166] = "0b00";
        ram[167] = "0b00";
        ram[168] = "0b01";
        for (unsigned i = 169; i < 178 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[178] = "0b01";
        for (unsigned i = 179; i < 189 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[189] = "0b11";
        for (unsigned i = 190; i < 306 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[306] = "0b01";
        ram[307] = "0b00";
        ram[308] = "0b11";
        ram[309] = "0b00";
        ram[310] = "0b00";
        ram[311] = "0b00";
        ram[312] = "0b00";
        ram[313] = "0b01";
        ram[314] = "0b00";
        ram[315] = "0b11";
        for (unsigned i = 316; i < 357 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[357] = "0b11";
        for (unsigned i = 358; i < 401 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[401] = "0b11";
        for (unsigned i = 402; i < 415 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[415] = "0b01";
        ram[416] = "0b00";
        ram[417] = "0b01";
        for (unsigned i = 418; i < 424 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[424] = "0b11";
        ram[425] = "0b00";
        ram[426] = "0b11";
        for (unsigned i = 427; i < 452 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[452] = "0b11";
        for (unsigned i = 453; i < 462 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[462] = "0b11";
        for (unsigned i = 463; i < 468 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[468] = "0b01";
        for (unsigned i = 469; i < 504 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[504] = "0b01";
        ram[505] = "0b00";
        ram[506] = "0b00";
        ram[507] = "0b00";
        ram[508] = "0b00";
        ram[509] = "0b10";
        ram[510] = "0b00";
        ram[511] = "0b00";
        ram[512] = "0b00";
        ram[513] = "0b00";
        ram[514] = "0b11";
        ram[515] = "0b00";
        ram[516] = "0b01";
        for (unsigned i = 517; i < 523 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[523] = "0b11";
        for (unsigned i = 524; i < 548 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[548] = "0b11";
        ram[549] = "0b00";
        ram[550] = "0b11";
        ram[551] = "0b00";
        ram[552] = "0b00";
        ram[553] = "0b00";
        ram[554] = "0b00";
        ram[555] = "0b01";
        for (unsigned i = 556; i < 646 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[646] = "0b01";
        ram[647] = "0b00";
        ram[648] = "0b00";
        ram[649] = "0b00";
        ram[650] = "0b00";
        ram[651] = "0b11";
        for (unsigned i = 652; i < 700 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[700] = "0b11";
        ram[701] = "0b00";
        ram[702] = "0b01";
        ram[703] = "0b00";
        ram[704] = "0b00";
        ram[705] = "0b00";
        ram[706] = "0b00";
        ram[707] = "0b11";
        for (unsigned i = 708; i < 727 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[727] = "0b11";
        ram[728] = "0b11";
        for (unsigned i = 729; i < 805 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[805] = "0b01";
        ram[806] = "0b00";
        ram[807] = "0b01";
        ram[808] = "0b00";
        ram[809] = "0b00";
        ram[810] = "0b11";
        ram[811] = "0b00";
        ram[812] = "0b11";
        for (unsigned i = 813; i < 842 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[842] = "0b11";
        ram[843] = "0b00";
        ram[844] = "0b11";
        for (unsigned i = 845; i < 851 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[851] = "0b01";
        ram[852] = "0b00";
        ram[853] = "0b01";
        for (unsigned i = 854; i < 872 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[872] = "0b11";
        ram[873] = "0b00";
        ram[874] = "0b00";
        ram[875] = "0b11";
        for (unsigned i = 876; i < 950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[950] = "0b11";
        ram[951] = "0b00";
        ram[952] = "0b01";
        for (unsigned i = 953; i < 966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[966] = "0b01";
        for (unsigned i = 967; i < 998 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[998] = "0b11";
        ram[999] = "0b00";
        ram[1000] = "0b11";
        for (unsigned i = 1001; i < 1022 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1022] = "0b11";
        for (unsigned i = 1023; i < 1045 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1045] = "0b01";
        for (unsigned i = 1046; i < 1052 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1052] = "0b01";
        ram[1053] = "0b00";
        ram[1054] = "0b11";
        for (unsigned i = 1055; i < 1090 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1090] = "0b11";
        for (unsigned i = 1091; i < 1188 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1188] = "0b11";
        for (unsigned i = 1189; i < 1194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1194] = "0b01";
        ram[1195] = "0b00";
        ram[1196] = "0b01";
        for (unsigned i = 1197; i < 1206 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1206] = "0b01";
        ram[1207] = "0b00";
        ram[1208] = "0b11";
        for (unsigned i = 1209; i < 1215 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1215] = "0b11";
        ram[1216] = "0b00";
        ram[1217] = "0b00";
        ram[1218] = "0b01";
        for (unsigned i = 1219; i < 1379 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1379] = "0b11";
        for (unsigned i = 1380; i < 1393 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1393] = "0b11";
        ram[1394] = "0b00";
        ram[1395] = "0b00";
        ram[1396] = "0b00";
        ram[1397] = "0b00";
        ram[1398] = "0b11";
        for (unsigned i = 1399; i < 1407 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1407] = "0b01";
        for (unsigned i = 1408; i < 1428 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1428] = "0b11";
        for (unsigned i = 1429; i < 1444 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1444] = "0b11";
        for (unsigned i = 1445; i < 1451 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1451] = "0b01";
        for (unsigned i = 1452; i < 1463 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1463] = "0b11";
        for (unsigned i = 1464; i < 1482 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1482] = "0b11";
        for (unsigned i = 1483; i < 1491 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1491] = "0b11";
        for (unsigned i = 1492; i < 1542 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1542] = "0b01";
        for (unsigned i = 1543; i < 1552 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1552] = "0b11";
        ram[1553] = "0b00";
        ram[1554] = "0b00";
        ram[1555] = "0b00";
        ram[1556] = "0b00";
        ram[1557] = "0b11";
        for (unsigned i = 1558; i < 1589 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1589] = "0b11";
        ram[1590] = "0b00";
        ram[1591] = "0b01";
        for (unsigned i = 1592; i < 1628 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1628] = "0b11";
        ram[1629] = "0b00";
        ram[1630] = "0b00";
        ram[1631] = "0b01";
        for (unsigned i = 1632; i < 1638 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1638] = "0b11";
        ram[1639] = "0b00";
        ram[1640] = "0b00";
        ram[1641] = "0b11";
        for (unsigned i = 1642; i < 1782 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1782] = "0b11";
        for (unsigned i = 1783; i < 1820 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1820] = "0b11";
        for (unsigned i = 1821; i < 1829 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1829] = "0b11";
        ram[1830] = "0b01";
        ram[1831] = "0b11";
        ram[1832] = "0b00";
        ram[1833] = "0b00";
        ram[1834] = "0b11";
        for (unsigned i = 1835; i < 1885 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1885] = "0b11";
        for (unsigned i = 1886; i < 1925 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1925] = "0b01";
        for (unsigned i = 1926; i < 1932 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1932] = "0b11";
        for (unsigned i = 1933; i < 1941 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1941] = "0b11";
        for (unsigned i = 1942; i < 1948 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1948] = "0b01";
        for (unsigned i = 1949; i < 1978 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1978] = "0b11";
        ram[1979] = "0b11";
        ram[1980] = "0b11";
        for (unsigned i = 1981; i < 1988 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1988] = "0b11";
        for (unsigned i = 1989; i < 2004 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2004] = "0b11";
        for (unsigned i = 2005; i < 2033 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2033] = "0b11";
        ram[2034] = "0b00";
        ram[2035] = "0b11";
        ram[2036] = "0b00";
        ram[2037] = "0b01";
        for (unsigned i = 2038; i < 2081 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2081] = "0b11";
        ram[2082] = "0b00";
        ram[2083] = "0b00";
        ram[2084] = "0b00";
        ram[2085] = "0b01";
        ram[2086] = "0b00";
        ram[2087] = "0b00";
        ram[2088] = "0b00";
        ram[2089] = "0b00";
        ram[2090] = "0b01";
        ram[2091] = "0b00";
        ram[2092] = "0b00";
        ram[2093] = "0b11";
        for (unsigned i = 2094; i < 2100 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2100] = "0b01";
        for (unsigned i = 2101; i < 2123 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2123] = "0b11";
        ram[2124] = "0b00";
        ram[2125] = "0b11";
        for (unsigned i = 2126; i < 2141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2141] = "0b01";
        for (unsigned i = 2142; i < 2233 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2233] = "0b11";
        for (unsigned i = 2234; i < 2321 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2321] = "0b01";
        ram[2322] = "0b01";
        ram[2323] = "0b01";
        for (unsigned i = 2324; i < 2342 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2342] = "0b11";
        ram[2343] = "0b01";
        for (unsigned i = 2344; i < 2359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2359] = "0b01";
        ram[2360] = "0b00";
        ram[2361] = "0b01";
        for (unsigned i = 2362; i < 2371 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2371] = "0b10";
        ram[2372] = "0b01";
        ram[2373] = "0b01";
        for (unsigned i = 2374; i < 2408 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2408] = "0b11";
        for (unsigned i = 2409; i < 2434 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2434] = "0b11";
        for (unsigned i = 2435; i < 2470 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2470] = "0b11";
        for (unsigned i = 2471; i < 2480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2480] = "0b01";
        ram[2481] = "0b00";
        ram[2482] = "0b00";
        ram[2483] = "0b11";
        for (unsigned i = 2484; i < 2506 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2506] = "0b11";
        ram[2507] = "0b00";
        ram[2508] = "0b11";
        for (unsigned i = 2509; i < 2530 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2530] = "0b11";
        for (unsigned i = 2531; i < 2564 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2564] = "0b11";
        ram[2565] = "0b00";
        ram[2566] = "0b00";
        ram[2567] = "0b00";
        ram[2568] = "0b00";
        ram[2569] = "0b01";
        for (unsigned i = 2570; i < 2613 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2613] = "0b01";
        for (unsigned i = 2614; i < 2672 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2672] = "0b11";
        for (unsigned i = 2673; i < 2681 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2681] = "0b11";
        for (unsigned i = 2682; i < 2723 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2723] = "0b11";
        for (unsigned i = 2724; i < 2732 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2732] = "0b01";
        ram[2733] = "0b00";
        ram[2734] = "0b00";
        ram[2735] = "0b11";
        for (unsigned i = 2736; i < 2756 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2756] = "0b01";
        for (unsigned i = 2757; i < 2763 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2763] = "0b01";
        ram[2764] = "0b01";
        ram[2765] = "0b00";
        ram[2766] = "0b00";
        ram[2767] = "0b00";
        ram[2768] = "0b11";
        for (unsigned i = 2769; i < 2800 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2800] = "0b11";
        for (unsigned i = 2801; i < 2810 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2810] = "0b01";
        for (unsigned i = 2811; i < 2821 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2821] = "0b11";
        ram[2822] = "0b00";
        ram[2823] = "0b00";
        ram[2824] = "0b00";
        ram[2825] = "0b00";
        ram[2826] = "0b11";
        ram[2827] = "0b00";
        ram[2828] = "0b01";
        for (unsigned i = 2829; i < 2882 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2882] = "0b11";
        for (unsigned i = 2883; i < 2966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2966] = "0b11";
        ram[2967] = "0b00";
        ram[2968] = "0b01";
        for (unsigned i = 2969; i < 2978 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2978] = "0b01";
        for (unsigned i = 2979; i < 3015 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3015] = "0b11";
        for (unsigned i = 3016; i < 3022 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3022] = "0b11";
        for (unsigned i = 3023; i < 3054 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3054] = "0b11";
        for (unsigned i = 3055; i < 3061 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3061] = "0b01";
        for (unsigned i = 3062; i < 3108 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3108] = "0b01";
        ram[3109] = "0b00";
        ram[3110] = "0b11";
        ram[3111] = "0b00";
        ram[3112] = "0b11";
        for (unsigned i = 3113; i < 3122 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3122] = "0b01";
        for (unsigned i = 3123; i < 3147 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3147] = "0b01";
        ram[3148] = "0b00";
        ram[3149] = "0b00";
        ram[3150] = "0b00";
        ram[3151] = "0b00";
        ram[3152] = "0b10";
        ram[3153] = "0b00";
        ram[3154] = "0b11";
        ram[3155] = "0b00";
        ram[3156] = "0b00";
        ram[3157] = "0b11";
        ram[3158] = "0b00";
        ram[3159] = "0b00";
        ram[3160] = "0b00";
        ram[3161] = "0b01";
        for (unsigned i = 3162; i < 3192 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3192] = "0b11";
        ram[3193] = "0b00";
        ram[3194] = "0b00";
        ram[3195] = "0b00";
        ram[3196] = "0b00";
        ram[3197] = "0b11";
        for (unsigned i = 3198; i < 3204 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3204] = "0b01";
        for (unsigned i = 3205; i < 3220 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3220] = "0b11";
        for (unsigned i = 3221; i < 3294 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3294] = "0b11";
        for (unsigned i = 3295; i < 3303 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3303] = "0b11";
        for (unsigned i = 3304; i < 3323 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3323] = "0b11";
        for (unsigned i = 3324; i < 3360 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3360] = "0b01";
        for (unsigned i = 3361; i < 3394 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3394] = "0b11";
        ram[3395] = "0b01";
        ram[3396] = "0b00";
        ram[3397] = "0b00";
        ram[3398] = "0b00";
        ram[3399] = "0b01";
        ram[3400] = "0b00";
        ram[3401] = "0b00";
        ram[3402] = "0b11";
        for (unsigned i = 3403; i < 3451 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3451] = "0b11";
        ram[3452] = "0b00";
        ram[3453] = "0b00";
        ram[3454] = "0b11";
        ram[3455] = "0b00";
        ram[3456] = "0b11";
        for (unsigned i = 3457; i < 3490 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3490] = "0b11";
        for (unsigned i = 3491; i < 3502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3502] = "0b11";
        for (unsigned i = 3503; i < 3540 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3540] = "0b01";
        for (unsigned i = 3541; i < 3570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3570] = "0b01";
        for (unsigned i = 3571; i < 3586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3586] = "0b11";
        for (unsigned i = 3587; i < 3649 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3649] = "0b11";
        for (unsigned i = 3650; i < 3706 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3706] = "0b11";
        for (unsigned i = 3707; i < 3715 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3715] = "0b01";
        ram[3716] = "0b00";
        ram[3717] = "0b00";
        ram[3718] = "0b00";
        ram[3719] = "0b11";
        for (unsigned i = 3720; i < 3752 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3752] = "0b01";
        for (unsigned i = 3753; i < 3785 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3785] = "0b11";
        ram[3786] = "0b11";
        for (unsigned i = 3787; i < 3793 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3793] = "0b01";
        ram[3794] = "0b11";
        for (unsigned i = 3795; i < 3812 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3812] = "0b11";
        for (unsigned i = 3813; i < 3850 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3850] = "0b01";
        ram[3851] = "0b00";
        ram[3852] = "0b00";
        ram[3853] = "0b11";
        ram[3854] = "0b00";
        ram[3855] = "0b11";
        ram[3856] = "0b00";
        ram[3857] = "0b00";
        ram[3858] = "0b00";
        ram[3859] = "0b00";
        ram[3860] = "0b01";
        ram[3861] = "0b00";
        ram[3862] = "0b01";
        for (unsigned i = 3863; i < 3892 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3892] = "0b01";
        ram[3893] = "0b00";
        ram[3894] = "0b00";
        ram[3895] = "0b11";
        ram[3896] = "0b00";
        ram[3897] = "0b00";
        ram[3898] = "0b11";
        ram[3899] = "0b00";
        ram[3900] = "0b00";
        ram[3901] = "0b01";
        for (unsigned i = 3902; i < 3915 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3915] = "0b01";
        for (unsigned i = 3916; i < 3934 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3934] = "0b01";
        for (unsigned i = 3935; i < 3950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3950] = "0b11";
        for (unsigned i = 3951; i < 3962 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3962] = "0b01";
        for (unsigned i = 3963; i < 3976 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3976] = "0b11";
        for (unsigned i = 3977; i < 3985 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3985] = "0b01";
        for (unsigned i = 3986; i < 3995 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3995] = "0b01";
        ram[3996] = "0b00";
        ram[3997] = "0b01";
        ram[3998] = "0b00";
        ram[3999] = "0b00";
        ram[4000] = "0b11";
        ram[4001] = "0b00";
        ram[4002] = "0b11";
        ram[4003] = "0b00";
        ram[4004] = "0b11";
        for (unsigned i = 4005; i < 4025 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4025] = "0b11";
        ram[4026] = "0b00";
        ram[4027] = "0b00";
        ram[4028] = "0b00";
        ram[4029] = "0b01";
        for (unsigned i = 4030; i < 4041 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4041] = "0b11";
        for (unsigned i = 4042; i < 4051 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4051] = "0b01";
        for (unsigned i = 4052; i < 4057 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4057] = "0b11";
        ram[4058] = "0b00";
        ram[4059] = "0b00";
        ram[4060] = "0b01";
        for (unsigned i = 4061; i < 4079 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4079] = "0b11";
        ram[4080] = "0b00";
        ram[4081] = "0b00";
        ram[4082] = "0b00";
        ram[4083] = "0b01";
        ram[4084] = "0b00";
        ram[4085] = "0b11";
        for (unsigned i = 4086; i < 4134 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4134] = "0b01";
        for (unsigned i = 4135; i < 4172 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4172] = "0b01";
        for (unsigned i = 4173; i < 4186 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4186] = "0b01";
        ram[4187] = "0b00";
        ram[4188] = "0b00";
        ram[4189] = "0b00";
        ram[4190] = "0b00";
        ram[4191] = "0b11";
        ram[4192] = "0b00";
        ram[4193] = "0b11";
        for (unsigned i = 4194; i < 4200 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4200] = "0b01";
        for (unsigned i = 4201; i < 4234 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4234] = "0b01";
        for (unsigned i = 4235; i < 4253 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4253] = "0b11";
        for (unsigned i = 4254; i < 4279 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4279] = "0b11";
        for (unsigned i = 4280; i < 4328 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4328] = "0b11";
        for (unsigned i = 4329; i < 4338 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4338] = "0b11";
        for (unsigned i = 4339; i < 4354 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4354] = "0b01";
        for (unsigned i = 4355; i < 4381 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4381] = "0b01";
        for (unsigned i = 4382; i < 4430 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4430] = "0b01";
        for (unsigned i = 4431; i < 4466 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4466] = "0b01";
        for (unsigned i = 4467; i < 4479 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4479] = "0b01";
        ram[4480] = "0b00";
        ram[4481] = "0b00";
        ram[4482] = "0b00";
        ram[4483] = "0b00";
        ram[4484] = "0b11";
        ram[4485] = "0b00";
        ram[4486] = "0b00";
        ram[4487] = "0b00";
        ram[4488] = "0b00";
        ram[4489] = "0b11";
        ram[4490] = "0b00";
        ram[4491] = "0b01";
        for (unsigned i = 4492; i < 4498 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4498] = "0b01";
        ram[4499] = "0b00";
        ram[4500] = "0b00";
        ram[4501] = "0b11";
        ram[4502] = "0b00";
        ram[4503] = "0b11";
        for (unsigned i = 4504; i < 4524 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4524] = "0b01";
        ram[4525] = "0b00";
        ram[4526] = "0b01";
        for (unsigned i = 4527; i < 4545 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4545] = "0b01";
        for (unsigned i = 4546; i < 4580 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4580] = "0b01";
        for (unsigned i = 4581; i < 4619 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4619] = "0b01";
        ram[4620] = "0b00";
        ram[4621] = "0b00";
        ram[4622] = "0b00";
        ram[4623] = "0b00";
        ram[4624] = "0b11";
        ram[4625] = "0b00";
        ram[4626] = "0b11";
        ram[4627] = "0b00";
        ram[4628] = "0b00";
        ram[4629] = "0b00";
        ram[4630] = "0b00";
        ram[4631] = "0b01";
        for (unsigned i = 4632; i < 4638 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4638] = "0b01";
        for (unsigned i = 4639; i < 4671 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4671] = "0b01";
        for (unsigned i = 4672; i < 4746 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4746] = "0b01";
        ram[4747] = "0b00";
        ram[4748] = "0b01";
        for (unsigned i = 4749; i < 4774 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4774] = "0b11";
        for (unsigned i = 4775; i < 4827 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4827] = "0b11";
        for (unsigned i = 4828; i < 4875 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4875] = "0b11";
        for (unsigned i = 4876; i < 4881 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4881] = "0b11";
        ram[4882] = "0b00";
        ram[4883] = "0b00";
        ram[4884] = "0b01";
        ram[4885] = "0b00";
        ram[4886] = "0b11";
        ram[4887] = "0b00";
        ram[4888] = "0b11";
        ram[4889] = "0b00";
        ram[4890] = "0b00";
        ram[4891] = "0b01";
        ram[4892] = "0b00";
        ram[4893] = "0b01";
        for (unsigned i = 4894; i < 4914 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4914] = "0b11";
        for (unsigned i = 4915; i < 4942 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4942] = "0b11";
        for (unsigned i = 4943; i < 4970 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4970] = "0b01";
        for (unsigned i = 4971; i < 4988 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4988] = "0b11";
        for (unsigned i = 4989; i < 5021 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5021] = "0b11";
        for (unsigned i = 5022; i < 5068 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5068] = "0b11";
        for (unsigned i = 5069; i < 5084 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5084] = "0b11";
        ram[5085] = "0b00";
        ram[5086] = "0b11";
        for (unsigned i = 5087; i < 5159 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5159] = "0b11";
        ram[5160] = "0b00";
        ram[5161] = "0b00";
        ram[5162] = "0b00";
        ram[5163] = "0b00";
        ram[5164] = "0b11";
        ram[5165] = "0b00";
        ram[5166] = "0b01";
        ram[5167] = "0b00";
        ram[5168] = "0b00";
        ram[5169] = "0b00";
        ram[5170] = "0b00";
        ram[5171] = "0b11";
        ram[5172] = "0b00";
        ram[5173] = "0b00";
        ram[5174] = "0b00";
        ram[5175] = "0b01";
        for (unsigned i = 5176; i < 5215 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5215] = "0b01";
        ram[5216] = "0b00";
        ram[5217] = "0b00";
        ram[5218] = "0b00";
        ram[5219] = "0b00";
        ram[5220] = "0b10";
        for (unsigned i = 5221; i < 5227 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5227] = "0b01";
        for (unsigned i = 5228; i < 5299 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5299] = "0b11";
        for (unsigned i = 5300; i < 5306 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5306] = "0b11";
        ram[5307] = "0b00";
        ram[5308] = "0b01";
        for (unsigned i = 5309; i < 5318 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5318] = "0b01";
        for (unsigned i = 5319; i < 5324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5324] = "0b11";
        ram[5325] = "0b00";
        ram[5326] = "0b00";
        ram[5327] = "0b00";
        ram[5328] = "0b00";
        ram[5329] = "0b11";
        for (unsigned i = 5330; i < 5352 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5352] = "0b11";
        for (unsigned i = 5353; i < 5358 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5358] = "0b11";
        ram[5359] = "0b11";
        ram[5360] = "0b00";
        ram[5361] = "0b11";
        for (unsigned i = 5362; i < 5378 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5378] = "0b11";
        for (unsigned i = 5379; i < 5399 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5399] = "0b11";
        for (unsigned i = 5400; i < 5406 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5406] = "0b01";
        ram[5407] = "0b00";
        ram[5408] = "0b00";
        ram[5409] = "0b00";
        ram[5410] = "0b00";
        ram[5411] = "0b11";
        for (unsigned i = 5412; i < 5425 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5425] = "0b11";
        ram[5426] = "0b00";
        ram[5427] = "0b00";
        ram[5428] = "0b00";
        ram[5429] = "0b00";
        ram[5430] = "0b11";
        for (unsigned i = 5431; i < 5436 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5436] = "0b01";
        for (unsigned i = 5437; i < 5450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5450] = "0b11";
        for (unsigned i = 5451; i < 5481 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5481] = "0b11";
        for (unsigned i = 5482; i < 5504 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5504] = "0b01";
        ram[5505] = "0b01";
        ram[5506] = "0b01";
        ram[5507] = "0b01";
        for (unsigned i = 5508; i < 5514 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5514] = "0b11";
        for (unsigned i = 5515; i < 5521 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5521] = "0b01";
        for (unsigned i = 5522; i < 5532 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5532] = "0b01";
        for (unsigned i = 5533; i < 5557 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5557] = "0b11";
        for (unsigned i = 5558; i < 5563 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5563] = "0b11";
        for (unsigned i = 5564; i < 5647 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5647] = "0b11";
        ram[5648] = "0b00";
        ram[5649] = "0b01";
        ram[5650] = "0b00";
        ram[5651] = "0b00";
        ram[5652] = "0b00";
        ram[5653] = "0b00";
        ram[5654] = "0b11";
        ram[5655] = "0b00";
        ram[5656] = "0b01";
        for (unsigned i = 5657; i < 5693 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5693] = "0b11";
        for (unsigned i = 5694; i < 5717 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5717] = "0b11";
        ram[5718] = "0b00";
        ram[5719] = "0b01";
        ram[5720] = "0b00";
        ram[5721] = "0b00";
        ram[5722] = "0b00";
        ram[5723] = "0b00";
        ram[5724] = "0b11";
        for (unsigned i = 5725; i < 5789 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5789] = "0b01";
        for (unsigned i = 5790; i < 5824 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5824] = "0b01";
        for (unsigned i = 5825; i < 5842 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5842] = "0b01";
        ram[5843] = "0b00";
        ram[5844] = "0b00";
        ram[5845] = "0b00";
        ram[5846] = "0b00";
        ram[5847] = "0b11";
        ram[5848] = "0b00";
        ram[5849] = "0b01";
        ram[5850] = "0b01";
        for (unsigned i = 5851; i < 5941 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5941] = "0b11";
        for (unsigned i = 5942; i < 5989 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5989] = "0b11";
        ram[5990] = "0b11";
        for (unsigned i = 5991; i < 6022 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6022] = "0b11";
        for (unsigned i = 6023; i < 6046 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6046] = "0b11";
        ram[6047] = "0b00";
        ram[6048] = "0b11";
        ram[6049] = "0b00";
        ram[6050] = "0b00";
        ram[6051] = "0b00";
        ram[6052] = "0b11";
        ram[6053] = "0b00";
        ram[6054] = "0b00";
        ram[6055] = "0b01";
        for (unsigned i = 6056; i < 6093 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6093] = "0b11";
        for (unsigned i = 6094; i < 6101 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6101] = "0b11";
        ram[6102] = "0b00";
        ram[6103] = "0b01";
        ram[6104] = "0b00";
        ram[6105] = "0b00";
        ram[6106] = "0b01";
        ram[6107] = "0b01";
        for (unsigned i = 6108; i < 6113 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6113] = "0b11";
        ram[6114] = "0b00";
        ram[6115] = "0b00";
        ram[6116] = "0b00";
        ram[6117] = "0b00";
        ram[6118] = "0b11";
        for (unsigned i = 6119; i < 6136 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6136] = "0b11";
        ram[6137] = "0b11";
        ram[6138] = "0b00";
        ram[6139] = "0b00";
        ram[6140] = "0b00";
        ram[6141] = "0b11";
        for (unsigned i = 6142; i < 6151 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6151] = "0b01";
        for (unsigned i = 6152; i < 6169 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6169] = "0b11";
        for (unsigned i = 6170; i < 6232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6232] = "0b11";
        for (unsigned i = 6233; i < 6240 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6240] = "0b01";
        for (unsigned i = 6241; i < 6249 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6249] = "0b01";
        ram[6250] = "0b00";
        ram[6251] = "0b11";
        for (unsigned i = 6252; i < 6258 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6258] = "0b01";
        for (unsigned i = 6259; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_12) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_12_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_12) {
meminst = new mlp_accel_4b_weights_l1_4b_12_ram("mlp_accel_4b_weights_l1_4b_12_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_12() {
    delete meminst;
}


};//endmodule
#endif
