// ==============================================================
// File generated on Wed Sep 02 16:33:44 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_10_H__
#define __mlp_accel_4b_weights_l1_4b_10_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_10_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_10_ram) {
        for (unsigned i = 0; i < 68 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[68] = "0b01";
        for (unsigned i = 69; i < 121 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[121] = "0b11";
        for (unsigned i = 122; i < 130 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[130] = "0b01";
        ram[131] = "0b00";
        ram[132] = "0b00";
        ram[133] = "0b11";
        for (unsigned i = 134; i < 139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[139] = "0b01";
        for (unsigned i = 140; i < 154 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[154] = "0b11";
        for (unsigned i = 155; i < 161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[161] = "0b11";
        ram[162] = "0b00";
        ram[163] = "0b01";
        for (unsigned i = 164; i < 177 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[177] = "0b01";
        ram[178] = "0b00";
        ram[179] = "0b00";
        ram[180] = "0b00";
        ram[181] = "0b11";
        for (unsigned i = 182; i < 240 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[240] = "0b01";
        for (unsigned i = 241; i < 317 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[317] = "0b11";
        for (unsigned i = 318; i < 359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[359] = "0b11";
        for (unsigned i = 360; i < 417 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[417] = "0b01";
        for (unsigned i = 418; i < 425 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[425] = "0b11";
        for (unsigned i = 426; i < 454 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[454] = "0b11";
        for (unsigned i = 455; i < 475 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[475] = "0b01";
        ram[476] = "0b01";
        for (unsigned i = 477; i < 482 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[482] = "0b01";
        ram[483] = "0b11";
        for (unsigned i = 484; i < 502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[502] = "0b01";
        ram[503] = "0b00";
        ram[504] = "0b01";
        ram[505] = "0b00";
        ram[506] = "0b00";
        ram[507] = "0b00";
        ram[508] = "0b00";
        ram[509] = "0b11";
        ram[510] = "0b00";
        ram[511] = "0b11";
        ram[512] = "0b00";
        ram[513] = "0b00";
        ram[514] = "0b00";
        ram[515] = "0b00";
        ram[516] = "0b01";
        ram[517] = "0b01";
        for (unsigned i = 518; i < 525 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[525] = "0b11";
        for (unsigned i = 526; i < 550 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[550] = "0b11";
        ram[551] = "0b00";
        ram[552] = "0b11";
        for (unsigned i = 553; i < 579 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[579] = "0b11";
        for (unsigned i = 580; i < 608 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[608] = "0b11";
        for (unsigned i = 609; i < 630 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[630] = "0b11";
        for (unsigned i = 631; i < 646 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[646] = "0b01";
        ram[647] = "0b00";
        ram[648] = "0b01";
        ram[649] = "0b00";
        ram[650] = "0b00";
        ram[651] = "0b00";
        ram[652] = "0b00";
        ram[653] = "0b11";
        for (unsigned i = 654; i < 672 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[672] = "0b01";
        for (unsigned i = 673; i < 693 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[693] = "0b01";
        ram[694] = "0b00";
        ram[695] = "0b11";
        ram[696] = "0b00";
        ram[697] = "0b01";
        ram[698] = "0b00";
        ram[699] = "0b00";
        ram[700] = "0b00";
        ram[701] = "0b00";
        ram[702] = "0b11";
        for (unsigned i = 703; i < 728 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[728] = "0b11";
        for (unsigned i = 729; i < 803 ; i = i + 1) {
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
        ram[812] = "0b11";
        ram[813] = "0b00";
        ram[814] = "0b11";
        for (unsigned i = 815; i < 844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[844] = "0b11";
        ram[845] = "0b01";
        ram[846] = "0b11";
        ram[847] = "0b00";
        ram[848] = "0b00";
        ram[849] = "0b00";
        ram[850] = "0b00";
        ram[851] = "0b01";
        ram[852] = "0b00";
        ram[853] = "0b00";
        ram[854] = "0b11";
        ram[855] = "0b00";
        ram[856] = "0b01";
        for (unsigned i = 857; i < 872 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[872] = "0b11";
        for (unsigned i = 873; i < 943 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[943] = "0b01";
        for (unsigned i = 944; i < 950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[950] = "0b11";
        ram[951] = "0b00";
        ram[952] = "0b01";
        for (unsigned i = 953; i < 958 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[958] = "0b11";
        for (unsigned i = 959; i < 992 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[992] = "0b11";
        for (unsigned i = 993; i < 1042 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1042] = "0b11";
        ram[1043] = "0b00";
        ram[1044] = "0b00";
        ram[1045] = "0b01";
        for (unsigned i = 1046; i < 1052 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1052] = "0b01";
        ram[1053] = "0b00";
        ram[1054] = "0b00";
        ram[1055] = "0b11";
        for (unsigned i = 1056; i < 1101 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1101] = "0b01";
        for (unsigned i = 1102; i < 1112 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1112] = "0b11";
        for (unsigned i = 1113; i < 1143 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1143] = "0b01";
        for (unsigned i = 1144; i < 1150 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1150] = "0b11";
        for (unsigned i = 1151; i < 1157 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1157] = "0b11";
        for (unsigned i = 1158; i < 1183 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1183] = "0b11";
        for (unsigned i = 1184; i < 1196 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1196] = "0b01";
        for (unsigned i = 1197; i < 1203 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1203] = "0b11";
        for (unsigned i = 1204; i < 1210 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1210] = "0b11";
        ram[1211] = "0b00";
        ram[1212] = "0b00";
        ram[1213] = "0b00";
        ram[1214] = "0b00";
        ram[1215] = "0b10";
        for (unsigned i = 1216; i < 1388 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1388] = "0b01";
        for (unsigned i = 1389; i < 1400 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1400] = "0b10";
        ram[1401] = "0b00";
        ram[1402] = "0b01";
        ram[1403] = "0b00";
        ram[1404] = "0b00";
        ram[1405] = "0b11";
        ram[1406] = "0b00";
        ram[1407] = "0b01";
        for (unsigned i = 1408; i < 1435 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1435] = "0b11";
        for (unsigned i = 1436; i < 1465 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1465] = "0b11";
        for (unsigned i = 1466; i < 1514 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1514] = "0b11";
        for (unsigned i = 1515; i < 1540 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1540] = "0b01";
        for (unsigned i = 1541; i < 1551 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1551] = "0b11";
        ram[1552] = "0b11";
        ram[1553] = "0b11";
        ram[1554] = "0b00";
        ram[1555] = "0b00";
        ram[1556] = "0b00";
        ram[1557] = "0b00";
        ram[1558] = "0b11";
        for (unsigned i = 1559; i < 1588 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1588] = "0b01";
        for (unsigned i = 1589; i < 1626 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1626] = "0b11";
        ram[1627] = "0b00";
        ram[1628] = "0b00";
        ram[1629] = "0b00";
        ram[1630] = "0b00";
        ram[1631] = "0b01";
        ram[1632] = "0b00";
        ram[1633] = "0b01";
        for (unsigned i = 1634; i < 1657 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1657] = "0b01";
        for (unsigned i = 1658; i < 1710 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1710] = "0b11";
        for (unsigned i = 1711; i < 1776 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1776] = "0b11";
        ram[1777] = "0b00";
        ram[1778] = "0b00";
        ram[1779] = "0b00";
        ram[1780] = "0b11";
        for (unsigned i = 1781; i < 1826 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1826] = "0b11";
        for (unsigned i = 1827; i < 1834 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1834] = "0b11";
        for (unsigned i = 1835; i < 1843 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1843] = "0b01";
        ram[1844] = "0b00";
        ram[1845] = "0b00";
        ram[1846] = "0b00";
        ram[1847] = "0b00";
        ram[1848] = "0b01";
        for (unsigned i = 1849; i < 1855 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1855] = "0b11";
        for (unsigned i = 1856; i < 1927 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1927] = "0b01";
        for (unsigned i = 1928; i < 1950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1950] = "0b01";
        ram[1951] = "0b01";
        for (unsigned i = 1952; i < 1973 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1973] = "0b11";
        for (unsigned i = 1974; i < 1979 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1979] = "0b11";
        ram[1980] = "0b11";
        ram[1981] = "0b00";
        ram[1982] = "0b00";
        ram[1983] = "0b01";
        ram[1984] = "0b00";
        ram[1985] = "0b11";
        ram[1986] = "0b00";
        ram[1987] = "0b00";
        ram[1988] = "0b00";
        ram[1989] = "0b00";
        ram[1990] = "0b01";
        for (unsigned i = 1991; i < 2043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2043] = "0b11";
        for (unsigned i = 2044; i < 2079 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2079] = "0b01";
        ram[2080] = "0b00";
        ram[2081] = "0b00";
        ram[2082] = "0b00";
        ram[2083] = "0b11";
        ram[2084] = "0b01";
        for (unsigned i = 2085; i < 2093 ; i = i + 1) {
            ram[i] = "0b00";
        }
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
        ram[2126] = "0b00";
        ram[2127] = "0b11";
        ram[2128] = "0b00";
        ram[2129] = "0b00";
        ram[2130] = "0b11";
        for (unsigned i = 2131; i < 2216 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2216] = "0b01";
        for (unsigned i = 2217; i < 2232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2232] = "0b01";
        for (unsigned i = 2233; i < 2323 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2323] = "0b01";
        for (unsigned i = 2324; i < 2342 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2342] = "0b11";
        ram[2343] = "0b00";
        ram[2344] = "0b00";
        ram[2345] = "0b00";
        ram[2346] = "0b00";
        ram[2347] = "0b11";
        for (unsigned i = 2348; i < 2359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2359] = "0b01";
        for (unsigned i = 2360; i < 2368 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2368] = "0b11";
        ram[2369] = "0b00";
        ram[2370] = "0b00";
        ram[2371] = "0b11";
        for (unsigned i = 2372; i < 2378 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2378] = "0b01";
        for (unsigned i = 2379; i < 2408 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2408] = "0b11";
        ram[2409] = "0b00";
        ram[2410] = "0b00";
        ram[2411] = "0b00";
        ram[2412] = "0b00";
        ram[2413] = "0b01";
        ram[2414] = "0b00";
        ram[2415] = "0b01";
        for (unsigned i = 2416; i < 2424 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2424] = "0b01";
        ram[2425] = "0b00";
        ram[2426] = "0b00";
        ram[2427] = "0b11";
        ram[2428] = "0b01";
        ram[2429] = "0b00";
        ram[2430] = "0b01";
        ram[2431] = "0b00";
        ram[2432] = "0b00";
        ram[2433] = "0b00";
        ram[2434] = "0b11";
        ram[2435] = "0b00";
        ram[2436] = "0b11";
        for (unsigned i = 2437; i < 2464 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2464] = "0b01";
        for (unsigned i = 2465; i < 2473 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2473] = "0b11";
        ram[2474] = "0b00";
        ram[2475] = "0b00";
        ram[2476] = "0b00";
        ram[2477] = "0b01";
        for (unsigned i = 2478; i < 2484 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2484] = "0b11";
        ram[2485] = "0b11";
        for (unsigned i = 2486; i < 2515 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2515] = "0b01";
        for (unsigned i = 2516; i < 2529 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2529] = "0b01";
        ram[2530] = "0b00";
        ram[2531] = "0b00";
        ram[2532] = "0b00";
        ram[2533] = "0b11";
        ram[2534] = "0b00";
        ram[2535] = "0b00";
        ram[2536] = "0b00";
        ram[2537] = "0b00";
        ram[2538] = "0b11";
        for (unsigned i = 2539; i < 2564 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2564] = "0b11";
        for (unsigned i = 2565; i < 2610 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2610] = "0b11";
        for (unsigned i = 2611; i < 2672 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2672] = "0b11";
        ram[2673] = "0b00";
        ram[2674] = "0b11";
        ram[2675] = "0b00";
        ram[2676] = "0b11";
        for (unsigned i = 2677; i < 2739 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2739] = "0b01";
        for (unsigned i = 2740; i < 2765 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2765] = "0b01";
        for (unsigned i = 2766; i < 2776 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2776] = "0b11";
        for (unsigned i = 2777; i < 2786 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2786] = "0b01";
        for (unsigned i = 2787; i < 2821 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2821] = "0b11";
        ram[2822] = "0b00";
        ram[2823] = "0b01";
        ram[2824] = "0b00";
        ram[2825] = "0b00";
        ram[2826] = "0b11";
        for (unsigned i = 2827; i < 2832 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2832] = "0b01";
        for (unsigned i = 2833; i < 2853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2853] = "0b11";
        ram[2854] = "0b00";
        ram[2855] = "0b00";
        ram[2856] = "0b00";
        ram[2857] = "0b00";
        ram[2858] = "0b11";
        ram[2859] = "0b00";
        ram[2860] = "0b00";
        ram[2861] = "0b00";
        ram[2862] = "0b00";
        ram[2863] = "0b01";
        for (unsigned i = 2864; i < 2869 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2869] = "0b01";
        for (unsigned i = 2870; i < 2882 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2882] = "0b11";
        ram[2883] = "0b00";
        ram[2884] = "0b00";
        ram[2885] = "0b00";
        ram[2886] = "0b11";
        for (unsigned i = 2887; i < 2904 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2904] = "0b11";
        for (unsigned i = 2905; i < 2953 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2953] = "0b01";
        for (unsigned i = 2954; i < 2959 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2959] = "0b01";
        for (unsigned i = 2960; i < 2966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2966] = "0b11";
        for (unsigned i = 2967; i < 2975 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2975] = "0b01";
        for (unsigned i = 2976; i < 3028 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3028] = "0b11";
        for (unsigned i = 3029; i < 3105 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3105] = "0b01";
        for (unsigned i = 3106; i < 3112 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3112] = "0b11";
        ram[3113] = "0b11";
        for (unsigned i = 3114; i < 3120 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3120] = "0b11";
        for (unsigned i = 3121; i < 3147 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3147] = "0b01";
        ram[3148] = "0b00";
        ram[3149] = "0b00";
        ram[3150] = "0b00";
        ram[3151] = "0b00";
        ram[3152] = "0b11";
        ram[3153] = "0b00";
        ram[3154] = "0b11";
        ram[3155] = "0b00";
        ram[3156] = "0b11";
        ram[3157] = "0b11";
        for (unsigned i = 3158; i < 3194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3194] = "0b11";
        for (unsigned i = 3195; i < 3203 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3203] = "0b11";
        for (unsigned i = 3204; i < 3220 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3220] = "0b11";
        for (unsigned i = 3221; i < 3296 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3296] = "0b11";
        ram[3297] = "0b00";
        ram[3298] = "0b00";
        ram[3299] = "0b01";
        for (unsigned i = 3300; i < 3313 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3313] = "0b01";
        ram[3314] = "0b00";
        ram[3315] = "0b00";
        ram[3316] = "0b11";
        for (unsigned i = 3317; i < 3355 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3355] = "0b11";
        ram[3356] = "0b00";
        ram[3357] = "0b00";
        ram[3358] = "0b01";
        for (unsigned i = 3359; i < 3374 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3374] = "0b11";
        for (unsigned i = 3375; i < 3392 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3392] = "0b01";
        ram[3393] = "0b00";
        ram[3394] = "0b00";
        ram[3395] = "0b01";
        for (unsigned i = 3396; i < 3402 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3402] = "0b11";
        ram[3403] = "0b00";
        ram[3404] = "0b01";
        for (unsigned i = 3405; i < 3425 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3425] = "0b11";
        for (unsigned i = 3426; i < 3451 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3451] = "0b10";
        ram[3452] = "0b00";
        ram[3453] = "0b00";
        ram[3454] = "0b00";
        ram[3455] = "0b00";
        ram[3456] = "0b10";
        for (unsigned i = 3457; i < 3467 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3467] = "0b01";
        for (unsigned i = 3468; i < 3506 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3506] = "0b11";
        ram[3507] = "0b00";
        ram[3508] = "0b00";
        ram[3509] = "0b00";
        ram[3510] = "0b00";
        ram[3511] = "0b11";
        for (unsigned i = 3512; i < 3563 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3563] = "0b11";
        for (unsigned i = 3564; i < 3670 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3670] = "0b11";
        for (unsigned i = 3671; i < 3705 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3705] = "0b11";
        ram[3706] = "0b00";
        ram[3707] = "0b01";
        ram[3708] = "0b00";
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
        ram[3863] = "0b11";
        for (unsigned i = 3864; i < 3894 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3894] = "0b11";
        for (unsigned i = 3895; i < 3945 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3945] = "0b11";
        ram[3946] = "0b00";
        ram[3947] = "0b00";
        ram[3948] = "0b00";
        ram[3949] = "0b00";
        ram[3950] = "0b11";
        for (unsigned i = 3951; i < 3976 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3976] = "0b11";
        for (unsigned i = 3977; i < 3995 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3995] = "0b01";
        ram[3996] = "0b00";
        ram[3997] = "0b01";
        ram[3998] = "0b00";
        ram[3999] = "0b00";
        ram[4000] = "0b00";
        ram[4001] = "0b00";
        ram[4002] = "0b11";
        ram[4003] = "0b00";
        ram[4004] = "0b11";
        for (unsigned i = 4005; i < 4011 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4011] = "0b01";
        for (unsigned i = 4012; i < 4031 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4031] = "0b01";
        for (unsigned i = 4032; i < 4080 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4080] = "0b11";
        for (unsigned i = 4081; i < 4102 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4102] = "0b11";
        for (unsigned i = 4103; i < 4171 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4171] = "0b11";
        ram[4172] = "0b01";
        for (unsigned i = 4173; i < 4192 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4192] = "0b01";
        ram[4193] = "0b11";
        ram[4194] = "0b00";
        ram[4195] = "0b11";
        ram[4196] = "0b00";
        ram[4197] = "0b00";
        ram[4198] = "0b00";
        ram[4199] = "0b00";
        ram[4200] = "0b01";
        for (unsigned i = 4201; i < 4242 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4242] = "0b01";
        ram[4243] = "0b00";
        ram[4244] = "0b11";
        for (unsigned i = 4245; i < 4251 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4251] = "0b01";
        for (unsigned i = 4252; i < 4286 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4286] = "0b11";
        for (unsigned i = 4287; i < 4324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4324] = "0b11";
        for (unsigned i = 4325; i < 4331 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4331] = "0b11";
        ram[4332] = "0b11";
        ram[4333] = "0b00";
        ram[4334] = "0b00";
        ram[4335] = "0b01";
        ram[4336] = "0b00";
        ram[4337] = "0b00";
        ram[4338] = "0b11";
        for (unsigned i = 4339; i < 4344 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4344] = "0b01";
        for (unsigned i = 4345; i < 4398 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4398] = "0b11";
        for (unsigned i = 4399; i < 4442 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4442] = "0b11";
        for (unsigned i = 4443; i < 4471 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4471] = "0b11";
        for (unsigned i = 4472; i < 4485 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4485] = "0b11";
        ram[4486] = "0b11";
        for (unsigned i = 4487; i < 4501 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4501] = "0b11";
        for (unsigned i = 4502; i < 4526 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4526] = "0b01";
        for (unsigned i = 4527; i < 4533 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4533] = "0b11";
        for (unsigned i = 4534; i < 4545 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4545] = "0b01";
        for (unsigned i = 4546; i < 4568 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4568] = "0b11";
        for (unsigned i = 4569; i < 4577 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4577] = "0b11";
        ram[4578] = "0b00";
        ram[4579] = "0b00";
        ram[4580] = "0b01";
        for (unsigned i = 4581; i < 4592 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4592] = "0b01";
        ram[4593] = "0b00";
        ram[4594] = "0b01";
        for (unsigned i = 4595; i < 4619 ; i = i + 1) {
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
        for (unsigned i = 4627; i < 4633 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4633] = "0b11";
        for (unsigned i = 4634; i < 4671 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4671] = "0b01";
        for (unsigned i = 4672; i < 4697 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4697] = "0b01";
        for (unsigned i = 4698; i < 4772 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4772] = "0b01";
        for (unsigned i = 4773; i < 4825 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4825] = "0b01";
        for (unsigned i = 4826; i < 4879 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4879] = "0b01";
        for (unsigned i = 4880; i < 4885 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4885] = "0b01";
        ram[4886] = "0b01";
        for (unsigned i = 4887; i < 4916 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4916] = "0b11";
        for (unsigned i = 4917; i < 4930 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4930] = "0b01";
        for (unsigned i = 4931; i < 4937 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4937] = "0b01";
        ram[4938] = "0b00";
        ram[4939] = "0b00";
        ram[4940] = "0b00";
        ram[4941] = "0b00";
        ram[4942] = "0b11";
        for (unsigned i = 4943; i < 4983 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4983] = "0b11";
        for (unsigned i = 4984; i < 5010 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5010] = "0b11";
        for (unsigned i = 5011; i < 5025 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5025] = "0b11";
        for (unsigned i = 5026; i < 5035 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5035] = "0b01";
        for (unsigned i = 5036; i < 5054 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5054] = "0b11";
        for (unsigned i = 5055; i < 5061 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5061] = "0b11";
        for (unsigned i = 5062; i < 5067 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5067] = "0b01";
        for (unsigned i = 5068; i < 5086 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5086] = "0b11";
        for (unsigned i = 5087; i < 5164 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5164] = "0b11";
        for (unsigned i = 5165; i < 5220 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5220] = "0b11";
        ram[5221] = "0b00";
        ram[5222] = "0b11";
        ram[5223] = "0b00";
        ram[5224] = "0b00";
        ram[5225] = "0b00";
        ram[5226] = "0b00";
        ram[5227] = "0b01";
        ram[5228] = "0b00";
        ram[5229] = "0b01";
        for (unsigned i = 5230; i < 5308 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5308] = "0b11";
        ram[5309] = "0b00";
        ram[5310] = "0b00";
        ram[5311] = "0b00";
        ram[5312] = "0b00";
        ram[5313] = "0b11";
        ram[5314] = "0b00";
        ram[5315] = "0b01";
        for (unsigned i = 5316; i < 5331 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5331] = "0b11";
        for (unsigned i = 5332; i < 5355 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5355] = "0b01";
        ram[5356] = "0b00";
        ram[5357] = "0b00";
        ram[5358] = "0b00";
        ram[5359] = "0b11";
        ram[5360] = "0b11";
        ram[5361] = "0b00";
        ram[5362] = "0b11";
        for (unsigned i = 5363; i < 5369 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5369] = "0b01";
        for (unsigned i = 5370; i < 5397 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5397] = "0b11";
        ram[5398] = "0b00";
        ram[5399] = "0b11";
        for (unsigned i = 5400; i < 5406 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5406] = "0b01";
        for (unsigned i = 5407; i < 5425 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5425] = "0b11";
        for (unsigned i = 5426; i < 5436 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5436] = "0b01";
        for (unsigned i = 5437; i < 5450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5450] = "0b11";
        ram[5451] = "0b11";
        ram[5452] = "0b11";
        for (unsigned i = 5453; i < 5476 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5476] = "0b01";
        ram[5477] = "0b00";
        ram[5478] = "0b11";
        ram[5479] = "0b00";
        ram[5480] = "0b00";
        ram[5481] = "0b00";
        ram[5482] = "0b00";
        ram[5483] = "0b11";
        for (unsigned i = 5484; i < 5504 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5504] = "0b01";
        for (unsigned i = 5505; i < 5510 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5510] = "0b01";
        ram[5511] = "0b00";
        ram[5512] = "0b00";
        ram[5513] = "0b00";
        ram[5514] = "0b00";
        ram[5515] = "0b01";
        for (unsigned i = 5516; i < 5555 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5555] = "0b01";
        ram[5556] = "0b00";
        ram[5557] = "0b11";
        for (unsigned i = 5558; i < 5563 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5563] = "0b11";
        for (unsigned i = 5564; i < 5642 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5642] = "0b11";
        ram[5643] = "0b00";
        ram[5644] = "0b01";
        ram[5645] = "0b00";
        ram[5646] = "0b00";
        ram[5647] = "0b11";
        ram[5648] = "0b00";
        ram[5649] = "0b00";
        ram[5650] = "0b00";
        ram[5651] = "0b11";
        ram[5652] = "0b00";
        ram[5653] = "0b01";
        ram[5654] = "0b00";
        ram[5655] = "0b00";
        ram[5656] = "0b00";
        ram[5657] = "0b00";
        ram[5658] = "0b11";
        for (unsigned i = 5659; i < 5672 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5672] = "0b11";
        for (unsigned i = 5673; i < 5809 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5809] = "0b11";
        for (unsigned i = 5810; i < 5819 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5819] = "0b01";
        ram[5820] = "0b00";
        ram[5821] = "0b01";
        for (unsigned i = 5822; i < 5842 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5842] = "0b01";
        ram[5843] = "0b00";
        ram[5844] = "0b01";
        ram[5845] = "0b00";
        ram[5846] = "0b00";
        ram[5847] = "0b11";
        ram[5848] = "0b00";
        ram[5849] = "0b01";
        for (unsigned i = 5850; i < 5859 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5859] = "0b11";
        ram[5860] = "0b00";
        ram[5861] = "0b00";
        ram[5862] = "0b00";
        ram[5863] = "0b01";
        for (unsigned i = 5864; i < 5996 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5996] = "0b11";
        for (unsigned i = 5997; i < 6005 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6005] = "0b01";
        for (unsigned i = 6006; i < 6048 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6048] = "0b11";
        for (unsigned i = 6049; i < 6057 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6057] = "0b01";
        for (unsigned i = 6058; i < 6083 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6083] = "0b01";
        for (unsigned i = 6084; i < 6092 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6092] = "0b11";
        for (unsigned i = 6093; i < 6105 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6105] = "0b01";
        for (unsigned i = 6106; i < 6113 ; i = i + 1) {
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
        for (unsigned i = 6137; i < 6143 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6143] = "0b11";
        for (unsigned i = 6144; i < 6155 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6155] = "0b01";
        for (unsigned i = 6156; i < 6192 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6192] = "0b01";
        for (unsigned i = 6193; i < 6241 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_10) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_10_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_10) {
meminst = new mlp_accel_4b_weights_l1_4b_10_ram("mlp_accel_4b_weights_l1_4b_10_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_10() {
    delete meminst;
}


};//endmodule
#endif
