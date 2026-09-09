// ==============================================================
// File generated on Wed Sep 02 16:33:44 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_8_H__
#define __mlp_accel_4b_weights_l1_4b_8_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_8_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_8_ram) {
        for (unsigned i = 0; i < 30 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[30] = "0b01";
        for (unsigned i = 31; i < 74 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[74] = "0b11";
        ram[75] = "0b00";
        ram[76] = "0b01";
        for (unsigned i = 77; i < 112 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[112] = "0b11";
        ram[113] = "0b00";
        ram[114] = "0b00";
        ram[115] = "0b00";
        ram[116] = "0b11";
        for (unsigned i = 117; i < 123 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[123] = "0b01";
        for (unsigned i = 124; i < 130 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[130] = "0b01";
        for (unsigned i = 131; i < 139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[139] = "0b01";
        for (unsigned i = 140; i < 156 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[156] = "0b11";
        ram[157] = "0b00";
        ram[158] = "0b00";
        ram[159] = "0b00";
        ram[160] = "0b00";
        ram[161] = "0b11";
        for (unsigned i = 162; i < 167 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[167] = "0b11";
        ram[168] = "0b00";
        ram[169] = "0b11";
        ram[170] = "0b01";
        for (unsigned i = 171; i < 308 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[308] = "0b01";
        ram[309] = "0b00";
        ram[310] = "0b11";
        ram[311] = "0b00";
        ram[312] = "0b00";
        ram[313] = "0b00";
        ram[314] = "0b00";
        ram[315] = "0b01";
        ram[316] = "0b00";
        ram[317] = "0b11";
        for (unsigned i = 318; i < 426 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[426] = "0b11";
        for (unsigned i = 427; i < 464 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[464] = "0b11";
        for (unsigned i = 465; i < 480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[480] = "0b01";
        ram[481] = "0b00";
        ram[482] = "0b01";
        ram[483] = "0b11";
        for (unsigned i = 484; i < 511 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[511] = "0b10";
        ram[512] = "0b00";
        ram[513] = "0b01";
        ram[514] = "0b00";
        ram[515] = "0b00";
        ram[516] = "0b00";
        ram[517] = "0b00";
        ram[518] = "0b01";
        for (unsigned i = 519; i < 552 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[552] = "0b11";
        ram[553] = "0b00";
        ram[554] = "0b00";
        ram[555] = "0b00";
        ram[556] = "0b00";
        ram[557] = "0b01";
        for (unsigned i = 558; i < 569 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[569] = "0b01";
        for (unsigned i = 570; i < 608 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[608] = "0b11";
        for (unsigned i = 609; i < 616 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[616] = "0b01";
        for (unsigned i = 617; i < 627 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[627] = "0b01";
        for (unsigned i = 628; i < 648 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[648] = "0b01";
        ram[649] = "0b00";
        ram[650] = "0b00";
        ram[651] = "0b00";
        ram[652] = "0b00";
        ram[653] = "0b11";
        ram[654] = "0b00";
        ram[655] = "0b00";
        ram[656] = "0b00";
        ram[657] = "0b01";
        for (unsigned i = 658; i < 677 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[677] = "0b11";
        for (unsigned i = 678; i < 704 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[704] = "0b01";
        for (unsigned i = 705; i < 727 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[727] = "0b11";
        for (unsigned i = 728; i < 803 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[803] = "0b11";
        ram[804] = "0b00";
        ram[805] = "0b00";
        ram[806] = "0b11";
        ram[807] = "0b01";
        for (unsigned i = 808; i < 814 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[814] = "0b11";
        for (unsigned i = 815; i < 846 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[846] = "0b11";
        for (unsigned i = 847; i < 853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[853] = "0b01";
        for (unsigned i = 854; i < 868 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[868] = "0b11";
        for (unsigned i = 869; i < 944 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[944] = "0b11";
        ram[945] = "0b00";
        ram[946] = "0b00";
        ram[947] = "0b11";
        for (unsigned i = 948; i < 1015 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1015] = "0b11";
        for (unsigned i = 1016; i < 1024 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1024] = "0b11";
        for (unsigned i = 1025; i < 1047 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1047] = "0b01";
        for (unsigned i = 1048; i < 1112 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1112] = "0b11";
        for (unsigned i = 1113; i < 1182 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1182] = "0b01";
        ram[1183] = "0b11";
        for (unsigned i = 1184; i < 1190 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1190] = "0b11";
        ram[1191] = "0b01";
        for (unsigned i = 1192; i < 1208 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1208] = "0b01";
        ram[1209] = "0b00";
        ram[1210] = "0b11";
        for (unsigned i = 1211; i < 1393 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1393] = "0b01";
        ram[1394] = "0b00";
        ram[1395] = "0b10";
        ram[1396] = "0b00";
        ram[1397] = "0b00";
        ram[1398] = "0b00";
        ram[1399] = "0b00";
        ram[1400] = "0b11";
        ram[1401] = "0b00";
        ram[1402] = "0b01";
        for (unsigned i = 1403; i < 1414 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1414] = "0b11";
        for (unsigned i = 1415; i < 1430 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1430] = "0b11";
        ram[1431] = "0b00";
        ram[1432] = "0b00";
        ram[1433] = "0b00";
        ram[1434] = "0b00";
        ram[1435] = "0b11";
        ram[1436] = "0b00";
        ram[1437] = "0b00";
        ram[1438] = "0b00";
        ram[1439] = "0b11";
        for (unsigned i = 1440; i < 1453 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1453] = "0b01";
        for (unsigned i = 1454; i < 1465 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1465] = "0b11";
        for (unsigned i = 1466; i < 1534 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1534] = "0b01";
        ram[1535] = "0b00";
        ram[1536] = "0b00";
        ram[1537] = "0b01";
        ram[1538] = "0b00";
        ram[1539] = "0b00";
        ram[1540] = "0b01";
        ram[1541] = "0b11";
        ram[1542] = "0b00";
        ram[1543] = "0b00";
        ram[1544] = "0b01";
        for (unsigned i = 1545; i < 1553 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1553] = "0b11";
        ram[1554] = "0b11";
        for (unsigned i = 1555; i < 1563 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1563] = "0b11";
        for (unsigned i = 1564; i < 1586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1586] = "0b11";
        ram[1587] = "0b00";
        ram[1588] = "0b00";
        ram[1589] = "0b00";
        ram[1590] = "0b00";
        ram[1591] = "0b11";
        for (unsigned i = 1592; i < 1626 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1626] = "0b11";
        for (unsigned i = 1627; i < 1633 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1633] = "0b01";
        for (unsigned i = 1634; i < 1640 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1640] = "0b11";
        for (unsigned i = 1641; i < 1659 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1659] = "0b11";
        ram[1660] = "0b00";
        ram[1661] = "0b01";
        for (unsigned i = 1662; i < 1696 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1696] = "0b01";
        for (unsigned i = 1697; i < 1710 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1710] = "0b11";
        for (unsigned i = 1711; i < 1782 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1782] = "0b11";
        for (unsigned i = 1783; i < 1824 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1824] = "0b01";
        ram[1825] = "0b00";
        ram[1826] = "0b11";
        ram[1827] = "0b01";
        ram[1828] = "0b11";
        ram[1829] = "0b00";
        ram[1830] = "0b00";
        ram[1831] = "0b11";
        ram[1832] = "0b01";
        ram[1833] = "0b00";
        ram[1834] = "0b00";
        ram[1835] = "0b00";
        ram[1836] = "0b11";
        for (unsigned i = 1837; i < 1854 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1854] = "0b01";
        for (unsigned i = 1855; i < 1934 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1934] = "0b11";
        ram[1935] = "0b00";
        ram[1936] = "0b00";
        ram[1937] = "0b00";
        ram[1938] = "0b11";
        ram[1939] = "0b00";
        ram[1940] = "0b00";
        ram[1941] = "0b11";
        ram[1942] = "0b00";
        ram[1943] = "0b11";
        ram[1944] = "0b00";
        ram[1945] = "0b00";
        ram[1946] = "0b00";
        ram[1947] = "0b00";
        ram[1948] = "0b01";
        for (unsigned i = 1949; i < 1980 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1980] = "0b11";
        ram[1981] = "0b11";
        for (unsigned i = 1982; i < 1989 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1989] = "0b01";
        ram[1990] = "0b11";
        for (unsigned i = 1991; i < 2035 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2035] = "0b11";
        for (unsigned i = 2036; i < 2043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2043] = "0b11";
        for (unsigned i = 2044; i < 2051 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2051] = "0b11";
        for (unsigned i = 2052; i < 2076 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2076] = "0b11";
        for (unsigned i = 2077; i < 2083 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2083] = "0b11";
        for (unsigned i = 2084; i < 2092 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2092] = "0b01";
        for (unsigned i = 2093; i < 2119 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2119] = "0b11";
        ram[2120] = "0b00";
        ram[2121] = "0b00";
        ram[2122] = "0b00";
        ram[2123] = "0b01";
        ram[2124] = "0b00";
        ram[2125] = "0b00";
        ram[2126] = "0b00";
        ram[2127] = "0b11";
        for (unsigned i = 2128; i < 2151 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2151] = "0b01";
        for (unsigned i = 2152; i < 2211 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2211] = "0b01";
        ram[2212] = "0b00";
        ram[2213] = "0b00";
        ram[2214] = "0b00";
        ram[2215] = "0b00";
        ram[2216] = "0b01";
        for (unsigned i = 2217; i < 2225 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2225] = "0b11";
        ram[2226] = "0b00";
        ram[2227] = "0b00";
        ram[2228] = "0b11";
        for (unsigned i = 2229; i < 2235 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2235] = "0b11";
        for (unsigned i = 2236; i < 2318 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2318] = "0b01";
        for (unsigned i = 2319; i < 2326 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2326] = "0b01";
        ram[2327] = "0b00";
        ram[2328] = "0b00";
        ram[2329] = "0b00";
        ram[2330] = "0b00";
        ram[2331] = "0b11";
        ram[2332] = "0b11";
        for (unsigned i = 2333; i < 2368 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2368] = "0b11";
        ram[2369] = "0b00";
        ram[2370] = "0b00";
        ram[2371] = "0b11";
        ram[2372] = "0b00";
        ram[2373] = "0b10";
        for (unsigned i = 2374; i < 2394 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2394] = "0b01";
        for (unsigned i = 2395; i < 2410 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2410] = "0b11";
        ram[2411] = "0b00";
        ram[2412] = "0b00";
        ram[2413] = "0b00";
        ram[2414] = "0b00";
        ram[2415] = "0b01";
        for (unsigned i = 2416; i < 2436 ; i = i + 1) {
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
        ram[2478] = "0b00";
        ram[2479] = "0b00";
        ram[2480] = "0b11";
        ram[2481] = "0b00";
        ram[2482] = "0b00";
        ram[2483] = "0b00";
        ram[2484] = "0b11";
        ram[2485] = "0b11";
        for (unsigned i = 2486; i < 2508 ; i = i + 1) {
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
        ram[2519] = "0b10";
        ram[2520] = "0b00";
        ram[2521] = "0b11";
        for (unsigned i = 2522; i < 2531 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2531] = "0b11";
        ram[2532] = "0b11";
        ram[2533] = "0b11";
        for (unsigned i = 2534; i < 2566 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2566] = "0b11";
        ram[2567] = "0b00";
        ram[2568] = "0b00";
        ram[2569] = "0b00";
        ram[2570] = "0b00";
        ram[2571] = "0b01";
        for (unsigned i = 2572; i < 2615 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2615] = "0b01";
        for (unsigned i = 2616; i < 2655 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2655] = "0b01";
        for (unsigned i = 2656; i < 2669 ; i = i + 1) {
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
        for (unsigned i = 2677; i < 2718 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2718] = "0b11";
        for (unsigned i = 2719; i < 2725 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2725] = "0b11";
        ram[2726] = "0b00";
        ram[2727] = "0b01";
        for (unsigned i = 2728; i < 2737 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2737] = "0b11";
        for (unsigned i = 2738; i < 2759 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2759] = "0b01";
        for (unsigned i = 2760; i < 2767 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2767] = "0b01";
        ram[2768] = "0b00";
        ram[2769] = "0b00";
        ram[2770] = "0b00";
        ram[2771] = "0b11";
        for (unsigned i = 2772; i < 2778 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2778] = "0b11";
        for (unsigned i = 2779; i < 2812 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2812] = "0b01";
        ram[2813] = "0b00";
        ram[2814] = "0b00";
        ram[2815] = "0b00";
        ram[2816] = "0b11";
        for (unsigned i = 2817; i < 2823 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2823] = "0b11";
        ram[2824] = "0b00";
        ram[2825] = "0b00";
        ram[2826] = "0b00";
        ram[2827] = "0b00";
        ram[2828] = "0b11";
        for (unsigned i = 2829; i < 2853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2853] = "0b11";
        for (unsigned i = 2854; i < 2864 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2864] = "0b01";
        for (unsigned i = 2865; i < 2884 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2884] = "0b11";
        for (unsigned i = 2885; i < 2900 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2900] = "0b01";
        for (unsigned i = 2901; i < 2951 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2951] = "0b11";
        for (unsigned i = 2952; i < 2966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2966] = "0b11";
        ram[2967] = "0b00";
        ram[2968] = "0b11";
        ram[2969] = "0b00";
        ram[2970] = "0b01";
        ram[2971] = "0b00";
        ram[2972] = "0b00";
        ram[2973] = "0b00";
        ram[2974] = "0b00";
        ram[2975] = "0b01";
        for (unsigned i = 2976; i < 3017 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3017] = "0b11";
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
        for (unsigned i = 3099; i < 3106 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3106] = "0b01";
        for (unsigned i = 3107; i < 3114 ; i = i + 1) {
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
        for (unsigned i = 3155; i < 3163 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3163] = "0b01";
        for (unsigned i = 3164; i < 3180 ; i = i + 1) {
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
        for (unsigned i = 3202; i < 3290 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3290] = "0b01";
        for (unsigned i = 3291; i < 3296 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3296] = "0b11";
        ram[3297] = "0b00";
        ram[3298] = "0b11";
        for (unsigned i = 3299; i < 3310 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3310] = "0b01";
        for (unsigned i = 3311; i < 3322 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3322] = "0b11";
        for (unsigned i = 3323; i < 3374 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3374] = "0b11";
        for (unsigned i = 3375; i < 3392 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3392] = "0b01";
        ram[3393] = "0b00";
        ram[3394] = "0b00";
        ram[3395] = "0b00";
        ram[3396] = "0b11";
        for (unsigned i = 3397; i < 3402 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3402] = "0b11";
        for (unsigned i = 3403; i < 3446 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3446] = "0b01";
        for (unsigned i = 3447; i < 3453 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3453] = "0b11";
        ram[3454] = "0b00";
        ram[3455] = "0b00";
        ram[3456] = "0b11";
        for (unsigned i = 3457; i < 3463 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3463] = "0b01";
        for (unsigned i = 3464; i < 3548 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3548] = "0b11";
        ram[3549] = "0b11";
        for (unsigned i = 3550; i < 3570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3570] = "0b01";
        for (unsigned i = 3571; i < 3592 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3592] = "0b01";
        ram[3593] = "0b11";
        ram[3594] = "0b00";
        ram[3595] = "0b11";
        ram[3596] = "0b00";
        ram[3597] = "0b00";
        ram[3598] = "0b00";
        ram[3599] = "0b00";
        ram[3600] = "0b01";
        for (unsigned i = 3601; i < 3646 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3646] = "0b11";
        for (unsigned i = 3647; i < 3667 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3667] = "0b11";
        ram[3668] = "0b00";
        ram[3669] = "0b00";
        ram[3670] = "0b11";
        for (unsigned i = 3671; i < 3700 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3700] = "0b11";
        ram[3701] = "0b00";
        ram[3702] = "0b00";
        ram[3703] = "0b11";
        ram[3704] = "0b00";
        ram[3705] = "0b11";
        ram[3706] = "0b00";
        ram[3707] = "0b00";
        ram[3708] = "0b11";
        ram[3709] = "0b00";
        ram[3710] = "0b00";
        ram[3711] = "0b00";
        ram[3712] = "0b01";
        for (unsigned i = 3713; i < 3754 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3754] = "0b01";
        for (unsigned i = 3755; i < 3782 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3782] = "0b11";
        for (unsigned i = 3783; i < 3793 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3793] = "0b01";
        for (unsigned i = 3794; i < 3808 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3808] = "0b01";
        for (unsigned i = 3809; i < 3814 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3814] = "0b11";
        for (unsigned i = 3815; i < 3840 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3840] = "0b11";
        for (unsigned i = 3841; i < 3848 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3848] = "0b11";
        ram[3849] = "0b00";
        ram[3850] = "0b11";
        for (unsigned i = 3851; i < 3862 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3862] = "0b01";
        for (unsigned i = 3863; i < 3894 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3894] = "0b01";
        for (unsigned i = 3895; i < 3903 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3903] = "0b01";
        for (unsigned i = 3904; i < 3976 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3976] = "0b11";
        for (unsigned i = 3977; i < 3997 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3997] = "0b01";
        ram[3998] = "0b00";
        ram[3999] = "0b01";
        ram[4000] = "0b00";
        ram[4001] = "0b00";
        ram[4002] = "0b11";
        ram[4003] = "0b00";
        ram[4004] = "0b11";
        for (unsigned i = 4005; i < 4027 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4027] = "0b11";
        for (unsigned i = 4028; i < 4043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4043] = "0b11";
        ram[4044] = "0b00";
        ram[4045] = "0b00";
        ram[4046] = "0b00";
        ram[4047] = "0b00";
        ram[4048] = "0b11";
        ram[4049] = "0b00";
        ram[4050] = "0b01";
        ram[4051] = "0b00";
        ram[4052] = "0b00";
        ram[4053] = "0b01";
        for (unsigned i = 4054; i < 4059 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4059] = "0b11";
        for (unsigned i = 4060; i < 4076 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4076] = "0b01";
        ram[4077] = "0b00";
        ram[4078] = "0b00";
        ram[4079] = "0b00";
        ram[4080] = "0b00";
        ram[4081] = "0b11";
        ram[4082] = "0b00";
        ram[4083] = "0b11";
        ram[4084] = "0b00";
        ram[4085] = "0b00";
        ram[4086] = "0b00";
        ram[4087] = "0b11";
        ram[4088] = "0b00";
        ram[4089] = "0b01";
        ram[4090] = "0b00";
        ram[4091] = "0b00";
        ram[4092] = "0b00";
        ram[4093] = "0b00";
        ram[4094] = "0b01";
        for (unsigned i = 4095; i < 4174 ; i = i + 1) {
            ram[i] = "0b00";
        }
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
        ram[4194] = "0b00";
        ram[4195] = "0b10";
        for (unsigned i = 4196; i < 4202 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4202] = "0b01";
        for (unsigned i = 4203; i < 4255 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4255] = "0b11";
        for (unsigned i = 4256; i < 4281 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4281] = "0b11";
        for (unsigned i = 4282; i < 4324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4324] = "0b11";
        for (unsigned i = 4325; i < 4330 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4330] = "0b11";
        for (unsigned i = 4331; i < 4340 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4340] = "0b11";
        ram[4341] = "0b00";
        ram[4342] = "0b11";
        ram[4343] = "0b00";
        ram[4344] = "0b00";
        ram[4345] = "0b01";
        for (unsigned i = 4346; i < 4353 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4353] = "0b11";
        ram[4354] = "0b00";
        ram[4355] = "0b00";
        ram[4356] = "0b01";
        for (unsigned i = 4357; i < 4386 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4386] = "0b11";
        for (unsigned i = 4387; i < 4486 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4486] = "0b11";
        ram[4487] = "0b00";
        ram[4488] = "0b00";
        ram[4489] = "0b00";
        ram[4490] = "0b00";
        ram[4491] = "0b11";
        ram[4492] = "0b00";
        ram[4493] = "0b01";
        for (unsigned i = 4494; i < 4522 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4522] = "0b11";
        ram[4523] = "0b00";
        ram[4524] = "0b00";
        ram[4525] = "0b00";
        ram[4526] = "0b01";
        for (unsigned i = 4527; i < 4547 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4547] = "0b01";
        for (unsigned i = 4548; i < 4577 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4577] = "0b11";
        ram[4578] = "0b00";
        ram[4579] = "0b00";
        ram[4580] = "0b00";
        ram[4581] = "0b00";
        ram[4582] = "0b01";
        for (unsigned i = 4583; i < 4594 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4594] = "0b01";
        for (unsigned i = 4595; i < 4619 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4619] = "0b01";
        ram[4620] = "0b00";
        ram[4621] = "0b01";
        ram[4622] = "0b00";
        ram[4623] = "0b00";
        ram[4624] = "0b10";
        ram[4625] = "0b00";
        ram[4626] = "0b10";
        ram[4627] = "0b00";
        ram[4628] = "0b11";
        ram[4629] = "0b00";
        ram[4630] = "0b00";
        ram[4631] = "0b01";
        for (unsigned i = 4632; i < 4642 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4642] = "0b01";
        for (unsigned i = 4643; i < 4650 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4650] = "0b01";
        for (unsigned i = 4651; i < 4680 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4680] = "0b11";
        for (unsigned i = 4681; i < 4731 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4731] = "0b11";
        for (unsigned i = 4732; i < 4792 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4792] = "0b11";
        for (unsigned i = 4793; i < 4823 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4823] = "0b11";
        for (unsigned i = 4824; i < 4873 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4873] = "0b01";
        for (unsigned i = 4874; i < 4883 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4883] = "0b11";
        ram[4884] = "0b00";
        ram[4885] = "0b00";
        ram[4886] = "0b01";
        ram[4887] = "0b11";
        for (unsigned i = 4888; i < 4895 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4895] = "0b01";
        for (unsigned i = 4896; i < 4914 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4914] = "0b01";
        for (unsigned i = 4915; i < 4944 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4944] = "0b11";
        ram[4945] = "0b00";
        ram[4946] = "0b11";
        for (unsigned i = 4947; i < 4960 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4960] = "0b11";
        for (unsigned i = 4961; i < 4972 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4972] = "0b01";
        for (unsigned i = 4973; i < 5058 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5058] = "0b11";
        for (unsigned i = 5059; i < 5081 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5081] = "0b11";
        ram[5082] = "0b00";
        ram[5083] = "0b00";
        ram[5084] = "0b00";
        ram[5085] = "0b00";
        ram[5086] = "0b11";
        for (unsigned i = 5087; i < 5111 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5111] = "0b11";
        for (unsigned i = 5112; i < 5161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5161] = "0b11";
        for (unsigned i = 5162; i < 5168 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5168] = "0b01";
        ram[5169] = "0b00";
        ram[5170] = "0b00";
        ram[5171] = "0b00";
        ram[5172] = "0b00";
        ram[5173] = "0b11";
        for (unsigned i = 5174; i < 5209 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5209] = "0b01";
        for (unsigned i = 5210; i < 5217 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5217] = "0b01";
        ram[5218] = "0b00";
        ram[5219] = "0b00";
        ram[5220] = "0b00";
        ram[5221] = "0b00";
        ram[5222] = "0b10";
        ram[5223] = "0b00";
        ram[5224] = "0b11";
        ram[5225] = "0b00";
        ram[5226] = "0b00";
        ram[5227] = "0b00";
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
        ram[5323] = "0b00";
        ram[5324] = "0b00";
        ram[5325] = "0b00";
        ram[5326] = "0b11";
        for (unsigned i = 5327; i < 5362 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5362] = "0b11";
        for (unsigned i = 5363; i < 5370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5370] = "0b01";
        for (unsigned i = 5371; i < 5399 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5399] = "0b11";
        for (unsigned i = 5400; i < 5406 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5406] = "0b01";
        ram[5407] = "0b00";
        ram[5408] = "0b01";
        ram[5409] = "0b00";
        ram[5410] = "0b00";
        ram[5411] = "0b00";
        ram[5412] = "0b11";
        for (unsigned i = 5413; i < 5418 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5418] = "0b01";
        ram[5419] = "0b00";
        ram[5420] = "0b01";
        ram[5421] = "0b00";
        ram[5422] = "0b00";
        ram[5423] = "0b11";
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
        for (unsigned i = 5444; i < 5452 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5452] = "0b11";
        for (unsigned i = 5453; i < 5461 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5461] = "0b01";
        for (unsigned i = 5462; i < 5499 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5499] = "0b11";
        ram[5500] = "0b00";
        ram[5501] = "0b00";
        ram[5502] = "0b00";
        ram[5503] = "0b00";
        ram[5504] = "0b01";
        ram[5505] = "0b00";
        ram[5506] = "0b01";
        ram[5507] = "0b01";
        ram[5508] = "0b00";
        ram[5509] = "0b01";
        ram[5510] = "0b11";
        ram[5511] = "0b11";
        for (unsigned i = 5512; i < 5522 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5522] = "0b11";
        ram[5523] = "0b01";
        for (unsigned i = 5524; i < 5530 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5530] = "0b11";
        for (unsigned i = 5531; i < 5642 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5642] = "0b11";
        ram[5643] = "0b00";
        ram[5644] = "0b00";
        ram[5645] = "0b00";
        ram[5646] = "0b11";
        ram[5647] = "0b00";
        ram[5648] = "0b00";
        ram[5649] = "0b11";
        ram[5650] = "0b01";
        ram[5651] = "0b01";
        for (unsigned i = 5652; i < 5657 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5657] = "0b01";
        ram[5658] = "0b00";
        ram[5659] = "0b00";
        ram[5660] = "0b00";
        ram[5661] = "0b00";
        ram[5662] = "0b11";
        for (unsigned i = 5663; i < 5702 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5702] = "0b01";
        for (unsigned i = 5703; i < 5711 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5711] = "0b01";
        for (unsigned i = 5712; i < 5719 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5719] = "0b11";
        for (unsigned i = 5720; i < 5726 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5726] = "0b11";
        for (unsigned i = 5727; i < 5760 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5760] = "0b11";
        for (unsigned i = 5761; i < 5791 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5791] = "0b01";
        for (unsigned i = 5792; i < 5807 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5807] = "0b11";
        for (unsigned i = 5808; i < 5816 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5816] = "0b01";
        for (unsigned i = 5817; i < 5844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5844] = "0b01";
        ram[5845] = "0b00";
        ram[5846] = "0b00";
        ram[5847] = "0b00";
        ram[5848] = "0b00";
        ram[5849] = "0b11";
        ram[5850] = "0b00";
        ram[5851] = "0b01";
        for (unsigned i = 5852; i < 5947 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5947] = "0b11";
        for (unsigned i = 5948; i < 5954 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5954] = "0b01";
        for (unsigned i = 5955; i < 5985 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5985] = "0b01";
        ram[5986] = "0b00";
        ram[5987] = "0b00";
        ram[5988] = "0b00";
        ram[5989] = "0b01";
        ram[5990] = "0b00";
        ram[5991] = "0b11";
        for (unsigned i = 5992; i < 5997 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5997] = "0b01";
        for (unsigned i = 5998; i < 6046 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6046] = "0b11";
        ram[6047] = "0b11";
        ram[6048] = "0b11";
        for (unsigned i = 6049; i < 6054 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6054] = "0b11";
        for (unsigned i = 6055; i < 6085 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6085] = "0b11";
        for (unsigned i = 6086; i < 6095 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6095] = "0b11";
        ram[6096] = "0b00";
        ram[6097] = "0b00";
        ram[6098] = "0b00";
        ram[6099] = "0b01";
        ram[6100] = "0b00";
        ram[6101] = "0b00";
        ram[6102] = "0b00";
        ram[6103] = "0b11";
        ram[6104] = "0b00";
        ram[6105] = "0b01";
        ram[6106] = "0b00";
        ram[6107] = "0b00";
        ram[6108] = "0b01";
        ram[6109] = "0b01";
        ram[6110] = "0b00";
        ram[6111] = "0b00";
        ram[6112] = "0b00";
        ram[6113] = "0b11";
        ram[6114] = "0b00";
        ram[6115] = "0b11";
        ram[6116] = "0b00";
        ram[6117] = "0b11";
        ram[6118] = "0b11";
        for (unsigned i = 6119; i < 6138 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6138] = "0b11";
        ram[6139] = "0b11";
        ram[6140] = "0b00";
        ram[6141] = "0b00";
        ram[6142] = "0b00";
        ram[6143] = "0b11";
        for (unsigned i = 6144; i < 6153 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6153] = "0b01";
        ram[6154] = "0b00";
        ram[6155] = "0b00";
        ram[6156] = "0b00";
        ram[6157] = "0b01";
        for (unsigned i = 6158; i < 6192 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6192] = "0b01";
        for (unsigned i = 6193; i < 6201 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6201] = "0b11";
        for (unsigned i = 6202; i < 6246 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6246] = "0b11";
        ram[6247] = "0b00";
        ram[6248] = "0b00";
        ram[6249] = "0b00";
        ram[6250] = "0b00";
        ram[6251] = "0b01";
        ram[6252] = "0b00";
        ram[6253] = "0b11";
        for (unsigned i = 6254; i < 6260 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6260] = "0b01";
        for (unsigned i = 6261; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_8) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_8_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_8) {
meminst = new mlp_accel_4b_weights_l1_4b_8_ram("mlp_accel_4b_weights_l1_4b_8_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_8() {
    delete meminst;
}


};//endmodule
#endif
