// ==============================================================
// File generated on Wed Sep 02 16:33:44 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_13_H__
#define __mlp_accel_4b_weights_l1_4b_13_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_13_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_13_ram) {
        for (unsigned i = 0; i < 21 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[21] = "0b11";
        ram[22] = "0b00";
        ram[23] = "0b00";
        ram[24] = "0b00";
        ram[25] = "0b01";
        for (unsigned i = 26; i < 72 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[72] = "0b11";
        ram[73] = "0b00";
        ram[74] = "0b01";
        for (unsigned i = 75; i < 103 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[103] = "0b11";
        for (unsigned i = 104; i < 128 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[128] = "0b01";
        for (unsigned i = 129; i < 137 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[137] = "0b01";
        ram[138] = "0b11";
        for (unsigned i = 139; i < 159 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[159] = "0b11";
        ram[160] = "0b00";
        ram[161] = "0b01";
        ram[162] = "0b00";
        ram[163] = "0b11";
        ram[164] = "0b00";
        ram[165] = "0b11";
        ram[166] = "0b00";
        ram[167] = "0b00";
        ram[168] = "0b01";
        ram[169] = "0b00";
        ram[170] = "0b00";
        ram[171] = "0b11";
        for (unsigned i = 172; i < 178 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[178] = "0b01";
        for (unsigned i = 179; i < 191 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[191] = "0b01";
        for (unsigned i = 192; i < 308 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[308] = "0b11";
        ram[309] = "0b00";
        ram[310] = "0b00";
        ram[311] = "0b00";
        ram[312] = "0b00";
        ram[313] = "0b01";
        ram[314] = "0b00";
        ram[315] = "0b11";
        ram[316] = "0b00";
        ram[317] = "0b00";
        ram[318] = "0b00";
        ram[319] = "0b00";
        ram[320] = "0b01";
        for (unsigned i = 321; i < 401 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[401] = "0b11";
        for (unsigned i = 402; i < 415 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[415] = "0b01";
        for (unsigned i = 416; i < 452 ; i = i + 1) {
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
        for (unsigned i = 469; i < 478 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[478] = "0b01";
        ram[479] = "0b00";
        ram[480] = "0b00";
        ram[481] = "0b11";
        for (unsigned i = 482; i < 504 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[504] = "0b01";
        ram[505] = "0b00";
        ram[506] = "0b00";
        ram[507] = "0b00";
        ram[508] = "0b00";
        ram[509] = "0b10";
        ram[510] = "0b00";
        ram[511] = "0b01";
        ram[512] = "0b00";
        ram[513] = "0b00";
        ram[514] = "0b11";
        ram[515] = "0b00";
        ram[516] = "0b01";
        for (unsigned i = 517; i < 548 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[548] = "0b11";
        ram[549] = "0b11";
        for (unsigned i = 550; i < 555 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[555] = "0b01";
        for (unsigned i = 556; i < 572 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[572] = "0b11";
        for (unsigned i = 573; i < 606 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[606] = "0b11";
        ram[607] = "0b00";
        ram[608] = "0b00";
        ram[609] = "0b11";
        for (unsigned i = 610; i < 644 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[644] = "0b01";
        for (unsigned i = 645; i < 651 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[651] = "0b11";
        ram[652] = "0b00";
        ram[653] = "0b01";
        for (unsigned i = 654; i < 695 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[695] = "0b01";
        ram[696] = "0b00";
        ram[697] = "0b00";
        ram[698] = "0b00";
        ram[699] = "0b00";
        ram[700] = "0b11";
        ram[701] = "0b00";
        ram[702] = "0b01";
        for (unsigned i = 703; i < 713 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[713] = "0b01";
        for (unsigned i = 714; i < 728 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[728] = "0b11";
        for (unsigned i = 729; i < 793 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[793] = "0b01";
        for (unsigned i = 794; i < 805 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[805] = "0b01";
        ram[806] = "0b00";
        ram[807] = "0b00";
        ram[808] = "0b11";
        ram[809] = "0b00";
        ram[810] = "0b11";
        ram[811] = "0b00";
        ram[812] = "0b11";
        for (unsigned i = 813; i < 838 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[838] = "0b01";
        ram[839] = "0b00";
        ram[840] = "0b00";
        ram[841] = "0b00";
        ram[842] = "0b11";
        ram[843] = "0b00";
        ram[844] = "0b11";
        for (unsigned i = 845; i < 872 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[872] = "0b11";
        for (unsigned i = 873; i < 948 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[948] = "0b11";
        for (unsigned i = 949; i < 971 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[971] = "0b01";
        for (unsigned i = 972; i < 992 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[992] = "0b11";
        ram[993] = "0b00";
        ram[994] = "0b00";
        ram[995] = "0b00";
        ram[996] = "0b11";
        for (unsigned i = 997; i < 1045 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1045] = "0b01";
        for (unsigned i = 1046; i < 1052 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1052] = "0b01";
        for (unsigned i = 1053; i < 1059 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1059] = "0b11";
        for (unsigned i = 1060; i < 1110 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1110] = "0b11";
        for (unsigned i = 1111; i < 1118 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1118] = "0b11";
        for (unsigned i = 1119; i < 1143 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1143] = "0b01";
        ram[1144] = "0b00";
        ram[1145] = "0b00";
        ram[1146] = "0b00";
        ram[1147] = "0b00";
        ram[1148] = "0b11";
        for (unsigned i = 1149; i < 1188 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1188] = "0b11";
        for (unsigned i = 1189; i < 1196 ; i = i + 1) {
            ram[i] = "0b00";
        }
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
        for (unsigned i = 1219; i < 1302 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1302] = "0b01";
        for (unsigned i = 1303; i < 1379 ; i = i + 1) {
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
        ram[1399] = "0b00";
        ram[1400] = "0b01";
        for (unsigned i = 1401; i < 1428 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1428] = "0b11";
        ram[1429] = "0b00";
        ram[1430] = "0b00";
        ram[1431] = "0b00";
        ram[1432] = "0b00";
        ram[1433] = "0b11";
        ram[1434] = "0b00";
        ram[1435] = "0b00";
        ram[1436] = "0b00";
        ram[1437] = "0b11";
        for (unsigned i = 1438; i < 1451 ; i = i + 1) {
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
        for (unsigned i = 1483; i < 1528 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1528] = "0b11";
        for (unsigned i = 1529; i < 1542 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1542] = "0b01";
        for (unsigned i = 1543; i < 1556 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1556] = "0b11";
        for (unsigned i = 1557; i < 1580 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1580] = "0b11";
        for (unsigned i = 1581; i < 1589 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1589] = "0b11";
        ram[1590] = "0b00";
        ram[1591] = "0b01";
        for (unsigned i = 1592; i < 1631 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1631] = "0b01";
        for (unsigned i = 1632; i < 1638 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1638] = "0b11";
        ram[1639] = "0b00";
        ram[1640] = "0b00";
        ram[1641] = "0b11";
        for (unsigned i = 1642; i < 1780 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1780] = "0b11";
        for (unsigned i = 1781; i < 1820 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1820] = "0b11";
        ram[1821] = "0b00";
        ram[1822] = "0b01";
        for (unsigned i = 1823; i < 1829 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1829] = "0b11";
        ram[1830] = "0b01";
        ram[1831] = "0b11";
        ram[1832] = "0b00";
        ram[1833] = "0b00";
        ram[1834] = "0b11";
        for (unsigned i = 1835; i < 1932 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1932] = "0b11";
        for (unsigned i = 1933; i < 1939 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1939] = "0b11";
        ram[1940] = "0b00";
        ram[1941] = "0b11";
        for (unsigned i = 1942; i < 1949 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1949] = "0b01";
        ram[1950] = "0b00";
        ram[1951] = "0b01";
        for (unsigned i = 1952; i < 1978 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1978] = "0b11";
        ram[1979] = "0b11";
        for (unsigned i = 1980; i < 2004 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2004] = "0b11";
        for (unsigned i = 2005; i < 2033 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2033] = "0b11";
        ram[2034] = "0b00";
        ram[2035] = "0b11";
        for (unsigned i = 2036; i < 2081 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2081] = "0b11";
        for (unsigned i = 2082; i < 2123 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2123] = "0b11";
        ram[2124] = "0b00";
        ram[2125] = "0b11";
        ram[2126] = "0b00";
        ram[2127] = "0b00";
        ram[2128] = "0b11";
        for (unsigned i = 2129; i < 2139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2139] = "0b01";
        for (unsigned i = 2140; i < 2215 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2215] = "0b01";
        for (unsigned i = 2216; i < 2223 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2223] = "0b11";
        for (unsigned i = 2224; i < 2233 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2233] = "0b11";
        ram[2234] = "0b00";
        ram[2235] = "0b00";
        ram[2236] = "0b00";
        ram[2237] = "0b01";
        ram[2238] = "0b01";
        for (unsigned i = 2239; i < 2329 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2329] = "0b01";
        ram[2330] = "0b00";
        ram[2331] = "0b00";
        ram[2332] = "0b00";
        ram[2333] = "0b11";
        for (unsigned i = 2334; i < 2340 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2340] = "0b11";
        for (unsigned i = 2341; i < 2357 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2357] = "0b01";
        for (unsigned i = 2358; i < 2369 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2369] = "0b11";
        ram[2370] = "0b00";
        ram[2371] = "0b10";
        for (unsigned i = 2372; i < 2408 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2408] = "0b11";
        ram[2409] = "0b00";
        ram[2410] = "0b11";
        ram[2411] = "0b00";
        ram[2412] = "0b00";
        ram[2413] = "0b01";
        for (unsigned i = 2414; i < 2419 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2419] = "0b11";
        for (unsigned i = 2420; i < 2425 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2425] = "0b11";
        for (unsigned i = 2426; i < 2467 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2467] = "0b01";
        ram[2468] = "0b00";
        ram[2469] = "0b00";
        ram[2470] = "0b00";
        ram[2471] = "0b11";
        for (unsigned i = 2472; i < 2478 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2478] = "0b11";
        for (unsigned i = 2479; i < 2489 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2489] = "0b11";
        for (unsigned i = 2490; i < 2506 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2506] = "0b11";
        ram[2507] = "0b00";
        ram[2508] = "0b11";
        ram[2509] = "0b00";
        ram[2510] = "0b00";
        ram[2511] = "0b00";
        ram[2512] = "0b00";
        ram[2513] = "0b01";
        ram[2514] = "0b00";
        ram[2515] = "0b00";
        ram[2516] = "0b00";
        ram[2517] = "0b00";
        ram[2518] = "0b11";
        for (unsigned i = 2519; i < 2529 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2529] = "0b11";
        ram[2530] = "0b11";
        ram[2531] = "0b11";
        for (unsigned i = 2532; i < 2543 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2543] = "0b11";
        for (unsigned i = 2544; i < 2564 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2564] = "0b11";
        ram[2565] = "0b00";
        ram[2566] = "0b00";
        ram[2567] = "0b00";
        ram[2568] = "0b00";
        ram[2569] = "0b01";
        for (unsigned i = 2570; i < 2611 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2611] = "0b11";
        ram[2612] = "0b00";
        ram[2613] = "0b01";
        for (unsigned i = 2614; i < 2623 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2623] = "0b11";
        for (unsigned i = 2624; i < 2635 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2635] = "0b01";
        for (unsigned i = 2636; i < 2641 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2641] = "0b11";
        for (unsigned i = 2642; i < 2672 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2672] = "0b11";
        for (unsigned i = 2673; i < 2678 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2678] = "0b01";
        for (unsigned i = 2679; i < 2716 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2716] = "0b11";
        for (unsigned i = 2717; i < 2723 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2723] = "0b11";
        for (unsigned i = 2724; i < 2735 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2735] = "0b11";
        for (unsigned i = 2736; i < 2755 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2755] = "0b11";
        ram[2756] = "0b00";
        ram[2757] = "0b00";
        ram[2758] = "0b00";
        ram[2759] = "0b00";
        ram[2760] = "0b11";
        ram[2761] = "0b00";
        ram[2762] = "0b00";
        ram[2763] = "0b01";
        ram[2764] = "0b01";
        for (unsigned i = 2765; i < 2788 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2788] = "0b01";
        for (unsigned i = 2789; i < 2817 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2817] = "0b01";
        for (unsigned i = 2818; i < 2824 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2824] = "0b11";
        ram[2825] = "0b00";
        ram[2826] = "0b11";
        for (unsigned i = 2827; i < 2853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2853] = "0b11";
        ram[2854] = "0b00";
        ram[2855] = "0b00";
        ram[2856] = "0b11";
        ram[2857] = "0b00";
        ram[2858] = "0b00";
        ram[2859] = "0b00";
        ram[2860] = "0b00";
        ram[2861] = "0b01";
        for (unsigned i = 2862; i < 2907 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2907] = "0b01";
        for (unsigned i = 2908; i < 2950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2950] = "0b11";
        for (unsigned i = 2951; i < 2964 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2964] = "0b11";
        ram[2965] = "0b00";
        ram[2966] = "0b11";
        ram[2967] = "0b00";
        ram[2968] = "0b01";
        ram[2969] = "0b00";
        ram[2970] = "0b00";
        ram[2971] = "0b00";
        ram[2972] = "0b00";
        ram[2973] = "0b01";
        for (unsigned i = 2974; i < 2996 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2996] = "0b11";
        ram[2997] = "0b00";
        ram[2998] = "0b00";
        ram[2999] = "0b01";
        for (unsigned i = 3000; i < 3010 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3010] = "0b11";
        for (unsigned i = 3011; i < 3021 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3021] = "0b11";
        ram[3022] = "0b00";
        ram[3023] = "0b00";
        ram[3024] = "0b00";
        ram[3025] = "0b00";
        ram[3026] = "0b11";
        for (unsigned i = 3027; i < 3054 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3054] = "0b11";
        for (unsigned i = 3055; i < 3105 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3105] = "0b01";
        for (unsigned i = 3106; i < 3111 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3111] = "0b01";
        ram[3112] = "0b11";
        ram[3113] = "0b00";
        ram[3114] = "0b00";
        ram[3115] = "0b01";
        ram[3116] = "0b00";
        ram[3117] = "0b00";
        ram[3118] = "0b11";
        for (unsigned i = 3119; i < 3145 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3145] = "0b01";
        ram[3146] = "0b00";
        ram[3147] = "0b01";
        ram[3148] = "0b00";
        ram[3149] = "0b00";
        ram[3150] = "0b00";
        ram[3151] = "0b00";
        ram[3152] = "0b10";
        ram[3153] = "0b00";
        ram[3154] = "0b11";
        for (unsigned i = 3155; i < 3192 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3192] = "0b11";
        ram[3193] = "0b00";
        ram[3194] = "0b00";
        ram[3195] = "0b00";
        ram[3196] = "0b00";
        ram[3197] = "0b11";
        for (unsigned i = 3198; i < 3292 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3292] = "0b11";
        for (unsigned i = 3293; i < 3303 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3303] = "0b11";
        for (unsigned i = 3304; i < 3313 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3313] = "0b01";
        ram[3314] = "0b00";
        ram[3315] = "0b00";
        ram[3316] = "0b11";
        ram[3317] = "0b00";
        ram[3318] = "0b01";
        ram[3319] = "0b00";
        ram[3320] = "0b11";
        ram[3321] = "0b00";
        ram[3322] = "0b11";
        for (unsigned i = 3323; i < 3353 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3353] = "0b11";
        for (unsigned i = 3354; i < 3360 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3360] = "0b01";
        for (unsigned i = 3361; i < 3371 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3371] = "0b01";
        for (unsigned i = 3372; i < 3388 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3388] = "0b11";
        for (unsigned i = 3389; i < 3395 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3395] = "0b01";
        ram[3396] = "0b00";
        ram[3397] = "0b00";
        ram[3398] = "0b00";
        ram[3399] = "0b00";
        ram[3400] = "0b11";
        ram[3401] = "0b00";
        ram[3402] = "0b00";
        ram[3403] = "0b00";
        ram[3404] = "0b00";
        ram[3405] = "0b11";
        ram[3406] = "0b11";
        for (unsigned i = 3407; i < 3412 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3412] = "0b01";
        for (unsigned i = 3413; i < 3447 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3447] = "0b01";
        ram[3448] = "0b00";
        ram[3449] = "0b00";
        ram[3450] = "0b00";
        ram[3451] = "0b10";
        ram[3452] = "0b00";
        ram[3453] = "0b00";
        ram[3454] = "0b11";
        ram[3455] = "0b00";
        ram[3456] = "0b11";
        for (unsigned i = 3457; i < 3462 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3462] = "0b11";
        for (unsigned i = 3463; i < 3475 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3475] = "0b11";
        for (unsigned i = 3476; i < 3553 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3553] = "0b11";
        for (unsigned i = 3554; i < 3570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3570] = "0b01";
        for (unsigned i = 3571; i < 3596 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3596] = "0b01";
        for (unsigned i = 3597; i < 3609 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3609] = "0b11";
        for (unsigned i = 3610; i < 3706 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3706] = "0b11";
        ram[3707] = "0b00";
        ram[3708] = "0b00";
        ram[3709] = "0b00";
        ram[3710] = "0b01";
        ram[3711] = "0b00";
        ram[3712] = "0b00";
        ram[3713] = "0b00";
        ram[3714] = "0b00";
        ram[3715] = "0b01";
        for (unsigned i = 3716; i < 3785 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3785] = "0b11";
        for (unsigned i = 3786; i < 3794 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3794] = "0b11";
        ram[3795] = "0b00";
        ram[3796] = "0b00";
        ram[3797] = "0b00";
        ram[3798] = "0b01";
        for (unsigned i = 3799; i < 3812 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3812] = "0b11";
        for (unsigned i = 3813; i < 3832 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3832] = "0b01";
        for (unsigned i = 3833; i < 3848 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3848] = "0b01";
        ram[3849] = "0b00";
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
        for (unsigned i = 3861; i < 3894 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3894] = "0b01";
        ram[3895] = "0b00";
        ram[3896] = "0b00";
        ram[3897] = "0b01";
        ram[3898] = "0b00";
        ram[3899] = "0b11";
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
        for (unsigned i = 3935; i < 3962 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3962] = "0b01";
        for (unsigned i = 3963; i < 3974 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3974] = "0b11";
        ram[3975] = "0b00";
        ram[3976] = "0b11";
        for (unsigned i = 3977; i < 3985 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3985] = "0b01";
        for (unsigned i = 3986; i < 3995 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3995] = "0b01";
        ram[3996] = "0b11";
        ram[3997] = "0b01";
        ram[3998] = "0b00";
        ram[3999] = "0b00";
        ram[4000] = "0b11";
        ram[4001] = "0b00";
        ram[4002] = "0b11";
        for (unsigned i = 4003; i < 4025 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4025] = "0b11";
        ram[4026] = "0b00";
        ram[4027] = "0b00";
        ram[4028] = "0b00";
        ram[4029] = "0b01";
        for (unsigned i = 4030; i < 4057 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4057] = "0b11";
        for (unsigned i = 4058; i < 4078 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4078] = "0b11";
        for (unsigned i = 4079; i < 4085 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4085] = "0b11";
        for (unsigned i = 4086; i < 4099 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4099] = "0b01";
        ram[4100] = "0b11";
        for (unsigned i = 4101; i < 4186 ; i = i + 1) {
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
        ram[4194] = "0b00";
        ram[4195] = "0b00";
        ram[4196] = "0b00";
        ram[4197] = "0b00";
        ram[4198] = "0b01";
        ram[4199] = "0b00";
        ram[4200] = "0b01";
        for (unsigned i = 4201; i < 4253 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4253] = "0b11";
        for (unsigned i = 4254; i < 4288 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4288] = "0b01";
        for (unsigned i = 4289; i < 4330 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4330] = "0b11";
        ram[4331] = "0b00";
        ram[4332] = "0b00";
        ram[4333] = "0b01";
        ram[4334] = "0b00";
        ram[4335] = "0b00";
        ram[4336] = "0b11";
        ram[4337] = "0b00";
        ram[4338] = "0b11";
        for (unsigned i = 4339; i < 4349 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4349] = "0b01";
        ram[4350] = "0b00";
        ram[4351] = "0b11";
        ram[4352] = "0b00";
        ram[4353] = "0b00";
        ram[4354] = "0b00";
        ram[4355] = "0b00";
        ram[4356] = "0b11";
        for (unsigned i = 4357; i < 4466 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4466] = "0b01";
        ram[4467] = "0b00";
        ram[4468] = "0b11";
        ram[4469] = "0b11";
        ram[4470] = "0b00";
        ram[4471] = "0b11";
        ram[4472] = "0b11";
        for (unsigned i = 4473; i < 4484 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4484] = "0b11";
        ram[4485] = "0b00";
        ram[4486] = "0b00";
        ram[4487] = "0b00";
        ram[4488] = "0b00";
        ram[4489] = "0b11";
        ram[4490] = "0b00";
        ram[4491] = "0b01";
        ram[4492] = "0b01";
        ram[4493] = "0b00";
        ram[4494] = "0b00";
        ram[4495] = "0b00";
        ram[4496] = "0b00";
        ram[4497] = "0b01";
        ram[4498] = "0b01";
        ram[4499] = "0b00";
        ram[4500] = "0b00";
        ram[4501] = "0b11";
        ram[4502] = "0b00";
        ram[4503] = "0b11";
        for (unsigned i = 4504; i < 4520 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4520] = "0b11";
        for (unsigned i = 4521; i < 4588 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4588] = "0b01";
        ram[4589] = "0b00";
        ram[4590] = "0b00";
        ram[4591] = "0b00";
        ram[4592] = "0b01";
        for (unsigned i = 4593; i < 4599 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4599] = "0b11";
        for (unsigned i = 4600; i < 4624 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4624] = "0b11";
        for (unsigned i = 4625; i < 4671 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4671] = "0b01";
        ram[4672] = "0b00";
        ram[4673] = "0b00";
        ram[4674] = "0b00";
        ram[4675] = "0b00";
        ram[4676] = "0b11";
        for (unsigned i = 4677; i < 4688 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4688] = "0b11";
        for (unsigned i = 4689; i < 4741 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4741] = "0b01";
        for (unsigned i = 4742; i < 4748 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4748] = "0b01";
        for (unsigned i = 4749; i < 4827 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4827] = "0b11";
        for (unsigned i = 4828; i < 4861 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4861] = "0b11";
        for (unsigned i = 4862; i < 4879 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4879] = "0b11";
        ram[4880] = "0b00";
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
        ram[4915] = "0b00";
        ram[4916] = "0b00";
        ram[4917] = "0b00";
        ram[4918] = "0b00";
        ram[4919] = "0b01";
        ram[4920] = "0b00";
        ram[4921] = "0b00";
        ram[4922] = "0b00";
        ram[4923] = "0b00";
        ram[4924] = "0b01";
        for (unsigned i = 4925; i < 4935 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4935] = "0b01";
        ram[4936] = "0b00";
        ram[4937] = "0b00";
        ram[4938] = "0b00";
        ram[4939] = "0b00";
        ram[4940] = "0b11";
        for (unsigned i = 4941; i < 4970 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4970] = "0b01";
        for (unsigned i = 4971; i < 4981 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4981] = "0b11";
        for (unsigned i = 4982; i < 4988 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4988] = "0b11";
        for (unsigned i = 4989; i < 5021 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5021] = "0b11";
        for (unsigned i = 5022; i < 5059 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5059] = "0b11";
        for (unsigned i = 5060; i < 5084 ; i = i + 1) {
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
        ram[5162] = "0b11";
        ram[5163] = "0b00";
        ram[5164] = "0b11";
        ram[5165] = "0b00";
        ram[5166] = "0b01";
        for (unsigned i = 5167; i < 5173 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5173] = "0b11";
        ram[5174] = "0b00";
        ram[5175] = "0b01";
        for (unsigned i = 5176; i < 5220 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5220] = "0b11";
        for (unsigned i = 5221; i < 5282 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5282] = "0b01";
        for (unsigned i = 5283; i < 5299 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5299] = "0b11";
        for (unsigned i = 5300; i < 5305 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5305] = "0b11";
        ram[5306] = "0b11";
        ram[5307] = "0b00";
        ram[5308] = "0b01";
        for (unsigned i = 5309; i < 5320 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5320] = "0b01";
        for (unsigned i = 5321; i < 5327 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5327] = "0b11";
        ram[5328] = "0b00";
        ram[5329] = "0b11";
        ram[5330] = "0b01";
        for (unsigned i = 5331; i < 5352 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5352] = "0b11";
        for (unsigned i = 5353; i < 5359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5359] = "0b11";
        for (unsigned i = 5360; i < 5378 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5378] = "0b11";
        for (unsigned i = 5379; i < 5400 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5400] = "0b11";
        for (unsigned i = 5401; i < 5406 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5406] = "0b01";
        ram[5407] = "0b00";
        ram[5408] = "0b11";
        for (unsigned i = 5409; i < 5430 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5430] = "0b11";
        for (unsigned i = 5431; i < 5450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5450] = "0b11";
        for (unsigned i = 5451; i < 5460 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5460] = "0b11";
        for (unsigned i = 5461; i < 5466 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5466] = "0b01";
        for (unsigned i = 5467; i < 5474 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5474] = "0b01";
        for (unsigned i = 5475; i < 5481 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5481] = "0b11";
        for (unsigned i = 5482; i < 5505 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5505] = "0b01";
        ram[5506] = "0b00";
        ram[5507] = "0b01";
        ram[5508] = "0b00";
        ram[5509] = "0b00";
        ram[5510] = "0b00";
        ram[5511] = "0b00";
        ram[5512] = "0b11";
        for (unsigned i = 5513; i < 5527 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5527] = "0b11";
        ram[5528] = "0b00";
        ram[5529] = "0b00";
        ram[5530] = "0b00";
        ram[5531] = "0b00";
        ram[5532] = "0b01";
        for (unsigned i = 5533; i < 5560 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5560] = "0b01";
        ram[5561] = "0b00";
        ram[5562] = "0b11";
        for (unsigned i = 5563; i < 5642 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5642] = "0b01";
        for (unsigned i = 5643; i < 5661 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5661] = "0b01";
        for (unsigned i = 5662; i < 5677 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5677] = "0b01";
        ram[5678] = "0b00";
        ram[5679] = "0b11";
        for (unsigned i = 5680; i < 5693 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5693] = "0b11";
        for (unsigned i = 5694; i < 5717 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5717] = "0b11";
        for (unsigned i = 5718; i < 5761 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5761] = "0b01";
        for (unsigned i = 5762; i < 5806 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5806] = "0b11";
        for (unsigned i = 5807; i < 5819 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5819] = "0b01";
        ram[5820] = "0b00";
        ram[5821] = "0b00";
        ram[5822] = "0b01";
        for (unsigned i = 5823; i < 5842 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5842] = "0b01";
        for (unsigned i = 5843; i < 5849 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5849] = "0b01";
        for (unsigned i = 5850; i < 5873 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5873] = "0b11";
        for (unsigned i = 5874; i < 5941 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5941] = "0b11";
        ram[5942] = "0b00";
        ram[5943] = "0b00";
        ram[5944] = "0b00";
        ram[5945] = "0b11";
        for (unsigned i = 5946; i < 5989 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5989] = "0b11";
        for (unsigned i = 5990; i < 6003 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6003] = "0b01";
        for (unsigned i = 6004; i < 6046 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6046] = "0b11";
        ram[6047] = "0b00";
        ram[6048] = "0b11";
        ram[6049] = "0b00";
        ram[6050] = "0b00";
        ram[6051] = "0b11";
        ram[6052] = "0b11";
        ram[6053] = "0b00";
        ram[6054] = "0b00";
        ram[6055] = "0b01";
        for (unsigned i = 6056; i < 6067 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6067] = "0b11";
        for (unsigned i = 6068; i < 6090 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6090] = "0b11";
        for (unsigned i = 6091; i < 6103 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6103] = "0b01";
        ram[6104] = "0b00";
        ram[6105] = "0b00";
        ram[6106] = "0b01";
        ram[6107] = "0b01";
        ram[6108] = "0b00";
        ram[6109] = "0b00";
        ram[6110] = "0b00";
        ram[6111] = "0b11";
        for (unsigned i = 6112; i < 6118 ; i = i + 1) {
            ram[i] = "0b00";
        }
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
        for (unsigned i = 6142; i < 6152 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6152] = "0b01";
        for (unsigned i = 6153; i < 6167 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6167] = "0b11";
        ram[6168] = "0b00";
        ram[6169] = "0b11";
        for (unsigned i = 6170; i < 6232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6232] = "0b11";
        ram[6233] = "0b01";
        for (unsigned i = 6234; i < 6248 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6248] = "0b01";
        for (unsigned i = 6249; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_13) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_13_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_13) {
meminst = new mlp_accel_4b_weights_l1_4b_13_ram("mlp_accel_4b_weights_l1_4b_13_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_13() {
    delete meminst;
}


};//endmodule
#endif
