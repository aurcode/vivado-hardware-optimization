// ==============================================================
// File generated on Wed Sep 02 16:33:44 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_11_H__
#define __mlp_accel_4b_weights_l1_4b_11_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_11_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_11_ram) {
        for (unsigned i = 0; i < 72 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[72] = "0b11";
        ram[73] = "0b00";
        ram[74] = "0b00";
        ram[75] = "0b01";
        for (unsigned i = 76; i < 114 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[114] = "0b11";
        for (unsigned i = 115; i < 125 ; i = i + 1) {
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
        for (unsigned i = 134; i < 140 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[140] = "0b01";
        for (unsigned i = 141; i < 154 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[154] = "0b11";
        ram[155] = "0b00";
        ram[156] = "0b00";
        ram[157] = "0b00";
        ram[158] = "0b00";
        ram[159] = "0b11";
        ram[160] = "0b00";
        ram[161] = "0b11";
        for (unsigned i = 162; i < 168 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[168] = "0b01";
        for (unsigned i = 169; i < 187 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[187] = "0b11";
        for (unsigned i = 188; i < 230 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[230] = "0b11";
        for (unsigned i = 231; i < 320 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[320] = "0b01";
        ram[321] = "0b00";
        ram[322] = "0b00";
        ram[323] = "0b00";
        ram[324] = "0b11";
        for (unsigned i = 325; i < 331 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[331] = "0b01";
        ram[332] = "0b00";
        ram[333] = "0b00";
        ram[334] = "0b11";
        for (unsigned i = 335; i < 380 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[380] = "0b01";
        for (unsigned i = 381; i < 403 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[403] = "0b11";
        for (unsigned i = 404; i < 417 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[417] = "0b01";
        for (unsigned i = 418; i < 426 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[426] = "0b11";
        for (unsigned i = 427; i < 454 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[454] = "0b11";
        for (unsigned i = 455; i < 475 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[475] = "0b01";
        ram[476] = "0b01";
        ram[477] = "0b00";
        ram[478] = "0b00";
        ram[479] = "0b00";
        ram[480] = "0b00";
        ram[481] = "0b11";
        ram[482] = "0b00";
        ram[483] = "0b11";
        for (unsigned i = 484; i < 499 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[499] = "0b11";
        ram[500] = "0b00";
        ram[501] = "0b00";
        ram[502] = "0b01";
        ram[503] = "0b00";
        ram[504] = "0b01";
        ram[505] = "0b00";
        ram[506] = "0b00";
        ram[507] = "0b00";
        ram[508] = "0b00";
        ram[509] = "0b11";
        for (unsigned i = 510; i < 516 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[516] = "0b01";
        ram[517] = "0b00";
        ram[518] = "0b00";
        ram[519] = "0b00";
        ram[520] = "0b00";
        ram[521] = "0b01";
        for (unsigned i = 522; i < 530 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[530] = "0b01";
        for (unsigned i = 531; i < 550 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[550] = "0b11";
        ram[551] = "0b11";
        for (unsigned i = 552; i < 579 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[579] = "0b11";
        for (unsigned i = 580; i < 601 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[601] = "0b01";
        ram[602] = "0b00";
        ram[603] = "0b00";
        ram[604] = "0b11";
        for (unsigned i = 605; i < 646 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[646] = "0b01";
        ram[647] = "0b00";
        ram[648] = "0b00";
        ram[649] = "0b00";
        ram[650] = "0b11";
        for (unsigned i = 651; i < 672 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[672] = "0b01";
        for (unsigned i = 673; i < 695 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[695] = "0b11";
        ram[696] = "0b00";
        ram[697] = "0b00";
        ram[698] = "0b00";
        ram[699] = "0b11";
        for (unsigned i = 700; i < 727 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[727] = "0b11";
        for (unsigned i = 728; i < 804 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[804] = "0b11";
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
        for (unsigned i = 815; i < 842 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[842] = "0b11";
        ram[843] = "0b00";
        ram[844] = "0b11";
        ram[845] = "0b01";
        ram[846] = "0b11";
        for (unsigned i = 847; i < 853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[853] = "0b01";
        for (unsigned i = 854; i < 863 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[863] = "0b01";
        ram[864] = "0b11";
        for (unsigned i = 865; i < 870 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[870] = "0b11";
        ram[871] = "0b00";
        ram[872] = "0b11";
        ram[873] = "0b00";
        ram[874] = "0b00";
        ram[875] = "0b11";
        for (unsigned i = 876; i < 944 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[944] = "0b11";
        for (unsigned i = 945; i < 950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[950] = "0b11";
        ram[951] = "0b00";
        ram[952] = "0b01";
        ram[953] = "0b00";
        ram[954] = "0b11";
        for (unsigned i = 955; i < 966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[966] = "0b01";
        for (unsigned i = 967; i < 992 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[992] = "0b11";
        for (unsigned i = 993; i < 1045 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1045] = "0b01";
        ram[1046] = "0b00";
        ram[1047] = "0b11";
        ram[1048] = "0b00";
        ram[1049] = "0b00";
        ram[1050] = "0b00";
        ram[1051] = "0b00";
        ram[1052] = "0b01";
        ram[1053] = "0b00";
        ram[1054] = "0b00";
        ram[1055] = "0b11";
        for (unsigned i = 1056; i < 1101 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1101] = "0b01";
        for (unsigned i = 1102; i < 1115 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1115] = "0b01";
        for (unsigned i = 1116; i < 1143 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1143] = "0b01";
        for (unsigned i = 1144; i < 1189 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1189] = "0b01";
        for (unsigned i = 1190; i < 1196 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1196] = "0b01";
        ram[1197] = "0b00";
        ram[1198] = "0b00";
        ram[1199] = "0b00";
        ram[1200] = "0b00";
        ram[1201] = "0b11";
        for (unsigned i = 1202; i < 1208 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1208] = "0b11";
        for (unsigned i = 1209; i < 1215 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1215] = "0b11";
        for (unsigned i = 1216; i < 1379 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1379] = "0b11";
        for (unsigned i = 1380; i < 1393 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1393] = "0b11";
        for (unsigned i = 1394; i < 1400 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1400] = "0b11";
        ram[1401] = "0b00";
        ram[1402] = "0b00";
        ram[1403] = "0b00";
        ram[1404] = "0b00";
        ram[1405] = "0b11";
        ram[1406] = "0b00";
        ram[1407] = "0b01";
        for (unsigned i = 1408; i < 1435 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1435] = "0b11";
        for (unsigned i = 1436; i < 1444 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1444] = "0b11";
        for (unsigned i = 1445; i < 1451 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1451] = "0b01";
        for (unsigned i = 1452; i < 1507 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1507] = "0b01";
        for (unsigned i = 1508; i < 1514 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1514] = "0b11";
        for (unsigned i = 1515; i < 1540 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1540] = "0b01";
        for (unsigned i = 1541; i < 1549 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1549] = "0b01";
        ram[1550] = "0b00";
        ram[1551] = "0b11";
        for (unsigned i = 1552; i < 1588 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1588] = "0b01";
        for (unsigned i = 1589; i < 1594 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1594] = "0b11";
        for (unsigned i = 1595; i < 1626 ; i = i + 1) {
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
        ram[1634] = "0b00";
        ram[1635] = "0b00";
        ram[1636] = "0b00";
        ram[1637] = "0b00";
        ram[1638] = "0b11";
        for (unsigned i = 1639; i < 1776 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1776] = "0b11";
        for (unsigned i = 1777; i < 1826 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1826] = "0b11";
        ram[1827] = "0b00";
        ram[1828] = "0b00";
        ram[1829] = "0b11";
        for (unsigned i = 1830; i < 1841 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1841] = "0b11";
        ram[1842] = "0b00";
        ram[1843] = "0b01";
        for (unsigned i = 1844; i < 1853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1853] = "0b11";
        for (unsigned i = 1854; i < 1859 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1859] = "0b01";
        for (unsigned i = 1860; i < 1927 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1927] = "0b01";
        for (unsigned i = 1928; i < 1936 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1936] = "0b11";
        ram[1937] = "0b00";
        ram[1938] = "0b00";
        ram[1939] = "0b11";
        for (unsigned i = 1940; i < 1948 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1948] = "0b01";
        for (unsigned i = 1949; i < 1979 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1979] = "0b11";
        ram[1980] = "0b11";
        for (unsigned i = 1981; i < 1988 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1988] = "0b11";
        for (unsigned i = 1989; i < 2028 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2028] = "0b01";
        ram[2029] = "0b00";
        ram[2030] = "0b11";
        ram[2031] = "0b00";
        ram[2032] = "0b00";
        ram[2033] = "0b00";
        ram[2034] = "0b00";
        ram[2035] = "0b11";
        ram[2036] = "0b00";
        ram[2037] = "0b01";
        for (unsigned i = 2038; i < 2078 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2078] = "0b01";
        ram[2079] = "0b01";
        ram[2080] = "0b00";
        ram[2081] = "0b11";
        ram[2082] = "0b00";
        ram[2083] = "0b00";
        ram[2084] = "0b00";
        ram[2085] = "0b01";
        ram[2086] = "0b00";
        ram[2087] = "0b00";
        ram[2088] = "0b11";
        ram[2089] = "0b00";
        ram[2090] = "0b00";
        ram[2091] = "0b00";
        ram[2092] = "0b00";
        ram[2093] = "0b11";
        for (unsigned i = 2094; i < 2100 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2100] = "0b01";
        for (unsigned i = 2101; i < 2121 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2121] = "0b01";
        ram[2122] = "0b00";
        ram[2123] = "0b11";
        ram[2124] = "0b00";
        ram[2125] = "0b11";
        ram[2126] = "0b00";
        ram[2127] = "0b11";
        for (unsigned i = 2128; i < 2135 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2135] = "0b11";
        ram[2136] = "0b00";
        ram[2137] = "0b00";
        ram[2138] = "0b00";
        ram[2139] = "0b00";
        ram[2140] = "0b11";
        ram[2141] = "0b00";
        ram[2142] = "0b00";
        ram[2143] = "0b00";
        ram[2144] = "0b01";
        for (unsigned i = 2145; i < 2219 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2219] = "0b11";
        for (unsigned i = 2220; i < 2232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2232] = "0b01";
        ram[2233] = "0b11";
        for (unsigned i = 2234; i < 2323 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2323] = "0b01";
        for (unsigned i = 2324; i < 2335 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2335] = "0b11";
        for (unsigned i = 2336; i < 2342 ; i = i + 1) {
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
        ram[2371] = "0b10";
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
        ram[2412] = "0b11";
        ram[2413] = "0b00";
        ram[2414] = "0b00";
        ram[2415] = "0b01";
        for (unsigned i = 2416; i < 2422 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2422] = "0b11";
        for (unsigned i = 2423; i < 2434 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2434] = "0b11";
        ram[2435] = "0b00";
        ram[2436] = "0b11";
        ram[2437] = "0b00";
        ram[2438] = "0b00";
        ram[2439] = "0b00";
        ram[2440] = "0b11";
        for (unsigned i = 2441; i < 2475 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2475] = "0b01";
        for (unsigned i = 2476; i < 2484 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2484] = "0b11";
        ram[2485] = "0b11";
        for (unsigned i = 2486; i < 2506 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2506] = "0b11";
        for (unsigned i = 2507; i < 2512 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2512] = "0b01";
        for (unsigned i = 2513; i < 2522 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2522] = "0b01";
        for (unsigned i = 2523; i < 2529 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2529] = "0b01";
        for (unsigned i = 2530; i < 2538 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2538] = "0b11";
        for (unsigned i = 2539; i < 2564 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2564] = "0b11";
        ram[2565] = "0b00";
        ram[2566] = "0b00";
        ram[2567] = "0b00";
        ram[2568] = "0b00";
        ram[2569] = "0b01";
        for (unsigned i = 2570; i < 2632 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2632] = "0b11";
        for (unsigned i = 2633; i < 2672 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2672] = "0b11";
        ram[2673] = "0b00";
        ram[2674] = "0b11";
        ram[2675] = "0b00";
        ram[2676] = "0b11";
        for (unsigned i = 2677; i < 2723 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2723] = "0b11";
        ram[2724] = "0b00";
        ram[2725] = "0b01";
        for (unsigned i = 2726; i < 2800 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2800] = "0b11";
        for (unsigned i = 2801; i < 2821 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2821] = "0b10";
        ram[2822] = "0b00";
        ram[2823] = "0b00";
        ram[2824] = "0b00";
        ram[2825] = "0b00";
        ram[2826] = "0b11";
        for (unsigned i = 2827; i < 2855 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2855] = "0b11";
        ram[2856] = "0b00";
        ram[2857] = "0b00";
        ram[2858] = "0b11";
        ram[2859] = "0b00";
        ram[2860] = "0b00";
        ram[2861] = "0b00";
        ram[2862] = "0b00";
        ram[2863] = "0b01";
        for (unsigned i = 2864; i < 2882 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2882] = "0b11";
        for (unsigned i = 2883; i < 2959 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2959] = "0b01";
        for (unsigned i = 2960; i < 2966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2966] = "0b11";
        ram[2967] = "0b00";
        ram[2968] = "0b01";
        for (unsigned i = 2969; i < 2975 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2975] = "0b01";
        for (unsigned i = 2976; i < 2982 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2982] = "0b01";
        for (unsigned i = 2983; i < 3002 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3002] = "0b01";
        for (unsigned i = 3003; i < 3012 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3012] = "0b01";
        ram[3013] = "0b00";
        ram[3014] = "0b01";
        for (unsigned i = 3015; i < 3021 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3021] = "0b11";
        for (unsigned i = 3022; i < 3029 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3029] = "0b01";
        for (unsigned i = 3030; i < 3051 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3051] = "0b11";
        for (unsigned i = 3052; i < 3061 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3061] = "0b01";
        for (unsigned i = 3062; i < 3096 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3096] = "0b11";
        for (unsigned i = 3097; i < 3110 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3110] = "0b11";
        ram[3111] = "0b00";
        ram[3112] = "0b00";
        ram[3113] = "0b00";
        ram[3114] = "0b00";
        ram[3115] = "0b11";
        ram[3116] = "0b00";
        ram[3117] = "0b00";
        ram[3118] = "0b00";
        ram[3119] = "0b00";
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
        for (unsigned i = 3155; i < 3180 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3180] = "0b01";
        for (unsigned i = 3181; i < 3199 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3199] = "0b01";
        for (unsigned i = 3200; i < 3206 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3206] = "0b11";
        for (unsigned i = 3207; i < 3212 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3212] = "0b11";
        for (unsigned i = 3213; i < 3294 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3294] = "0b11";
        ram[3295] = "0b00";
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
        for (unsigned i = 3317; i < 3323 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3323] = "0b11";
        for (unsigned i = 3324; i < 3345 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3345] = "0b11";
        for (unsigned i = 3346; i < 3353 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3353] = "0b01";
        for (unsigned i = 3354; i < 3366 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3366] = "0b01";
        for (unsigned i = 3367; i < 3372 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3372] = "0b11";
        for (unsigned i = 3373; i < 3402 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3402] = "0b11";
        ram[3403] = "0b00";
        ram[3404] = "0b00";
        ram[3405] = "0b00";
        ram[3406] = "0b11";
        ram[3407] = "0b00";
        ram[3408] = "0b00";
        ram[3409] = "0b00";
        ram[3410] = "0b00";
        ram[3411] = "0b01";
        for (unsigned i = 3412; i < 3449 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3449] = "0b01";
        ram[3450] = "0b00";
        ram[3451] = "0b10";
        ram[3452] = "0b00";
        ram[3453] = "0b00";
        ram[3454] = "0b00";
        ram[3455] = "0b00";
        ram[3456] = "0b11";
        for (unsigned i = 3457; i < 3488 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3488] = "0b01";
        for (unsigned i = 3489; i < 3502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3502] = "0b11";
        ram[3503] = "0b00";
        ram[3504] = "0b11";
        for (unsigned i = 3505; i < 3544 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3544] = "0b11";
        for (unsigned i = 3545; i < 3568 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3568] = "0b01";
        ram[3569] = "0b00";
        ram[3570] = "0b01";
        for (unsigned i = 3571; i < 3586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3586] = "0b11";
        ram[3587] = "0b00";
        ram[3588] = "0b00";
        ram[3589] = "0b11";
        for (unsigned i = 3590; i < 3598 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3598] = "0b01";
        for (unsigned i = 3599; i < 3649 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3649] = "0b11";
        for (unsigned i = 3650; i < 3705 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3705] = "0b11";
        for (unsigned i = 3706; i < 3712 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3712] = "0b01";
        for (unsigned i = 3713; i < 3752 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3752] = "0b01";
        for (unsigned i = 3753; i < 3793 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3793] = "0b01";
        for (unsigned i = 3794; i < 3839 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3839] = "0b01";
        for (unsigned i = 3840; i < 3850 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3850] = "0b01";
        ram[3851] = "0b00";
        ram[3852] = "0b00";
        ram[3853] = "0b00";
        ram[3854] = "0b00";
        ram[3855] = "0b11";
        for (unsigned i = 3856; i < 3862 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3862] = "0b01";
        for (unsigned i = 3863; i < 3883 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3883] = "0b11";
        for (unsigned i = 3884; i < 3892 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3892] = "0b01";
        ram[3893] = "0b00";
        ram[3894] = "0b11";
        ram[3895] = "0b00";
        ram[3896] = "0b00";
        ram[3897] = "0b00";
        ram[3898] = "0b11";
        for (unsigned i = 3899; i < 3995 ; i = i + 1) {
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
        ram[4005] = "0b00";
        ram[4006] = "0b00";
        ram[4007] = "0b00";
        ram[4008] = "0b00";
        ram[4009] = "0b01";
        for (unsigned i = 4010; i < 4025 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4025] = "0b11";
        for (unsigned i = 4026; i < 4036 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4036] = "0b11";
        for (unsigned i = 4037; i < 4043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4043] = "0b11";
        for (unsigned i = 4044; i < 4080 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4080] = "0b11";
        for (unsigned i = 4081; i < 4086 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4086] = "0b11";
        for (unsigned i = 4087; i < 4141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4141] = "0b11";
        for (unsigned i = 4142; i < 4172 ; i = i + 1) {
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
        ram[4192] = "0b01";
        ram[4193] = "0b10";
        for (unsigned i = 4194; i < 4200 ; i = i + 1) {
            ram[i] = "0b00";
        }
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
        for (unsigned i = 4252; i < 4288 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4288] = "0b01";
        for (unsigned i = 4289; i < 4324 ; i = i + 1) {
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
        ram[4339] = "0b11";
        ram[4340] = "0b00";
        ram[4341] = "0b00";
        ram[4342] = "0b00";
        ram[4343] = "0b00";
        ram[4344] = "0b01";
        for (unsigned i = 4345; i < 4374 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4374] = "0b01";
        for (unsigned i = 4375; i < 4387 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4387] = "0b01";
        for (unsigned i = 4388; i < 4471 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4471] = "0b11";
        for (unsigned i = 4472; i < 4479 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4479] = "0b01";
        ram[4480] = "0b00";
        ram[4481] = "0b00";
        ram[4482] = "0b00";
        ram[4483] = "0b00";
        ram[4484] = "0b11";
        for (unsigned i = 4485; i < 4494 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4494] = "0b01";
        for (unsigned i = 4495; i < 4501 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4501] = "0b11";
        ram[4502] = "0b00";
        ram[4503] = "0b11";
        for (unsigned i = 4504; i < 4522 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4522] = "0b11";
        ram[4523] = "0b00";
        ram[4524] = "0b00";
        ram[4525] = "0b00";
        ram[4526] = "0b01";
        ram[4527] = "0b00";
        ram[4528] = "0b00";
        ram[4529] = "0b11";
        ram[4530] = "0b00";
        ram[4531] = "0b00";
        ram[4532] = "0b00";
        ram[4533] = "0b11";
        for (unsigned i = 4534; i < 4570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4570] = "0b11";
        for (unsigned i = 4571; i < 4580 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4580] = "0b01";
        ram[4581] = "0b00";
        ram[4582] = "0b00";
        ram[4583] = "0b00";
        ram[4584] = "0b00";
        ram[4585] = "0b11";
        for (unsigned i = 4586; i < 4592 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4592] = "0b01";
        ram[4593] = "0b00";
        ram[4594] = "0b00";
        ram[4595] = "0b00";
        ram[4596] = "0b00";
        ram[4597] = "0b11";
        for (unsigned i = 4598; i < 4619 ; i = i + 1) {
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
        for (unsigned i = 4627; i < 4671 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4671] = "0b01";
        for (unsigned i = 4672; i < 4699 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4699] = "0b11";
        for (unsigned i = 4700; i < 4827 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4827] = "0b11";
        ram[4828] = "0b00";
        ram[4829] = "0b11";
        for (unsigned i = 4830; i < 4870 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4870] = "0b01";
        for (unsigned i = 4871; i < 4879 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4879] = "0b01";
        for (unsigned i = 4880; i < 4893 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4893] = "0b01";
        for (unsigned i = 4894; i < 4909 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4909] = "0b11";
        for (unsigned i = 4910; i < 4942 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4942] = "0b11";
        for (unsigned i = 4943; i < 4961 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4961] = "0b11";
        ram[4962] = "0b01";
        for (unsigned i = 4963; i < 4970 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4970] = "0b01";
        for (unsigned i = 4971; i < 5010 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5010] = "0b11";
        for (unsigned i = 5011; i < 5032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5032] = "0b01";
        for (unsigned i = 5033; i < 5061 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5061] = "0b11";
        for (unsigned i = 5062; i < 5067 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5067] = "0b01";
        for (unsigned i = 5068; i < 5079 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5079] = "0b11";
        for (unsigned i = 5080; i < 5086 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5086] = "0b11";
        for (unsigned i = 5087; i < 5124 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5124] = "0b01";
        for (unsigned i = 5125; i < 5159 ; i = i + 1) {
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
        for (unsigned i = 5167; i < 5214 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5214] = "0b11";
        for (unsigned i = 5215; i < 5220 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5220] = "0b10";
        ram[5221] = "0b00";
        ram[5222] = "0b11";
        ram[5223] = "0b00";
        ram[5224] = "0b00";
        ram[5225] = "0b01";
        for (unsigned i = 5226; i < 5305 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5305] = "0b01";
        ram[5306] = "0b00";
        ram[5307] = "0b00";
        ram[5308] = "0b01";
        ram[5309] = "0b00";
        ram[5310] = "0b00";
        ram[5311] = "0b11";
        ram[5312] = "0b00";
        ram[5313] = "0b11";
        for (unsigned i = 5314; i < 5324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5324] = "0b11";
        ram[5325] = "0b00";
        ram[5326] = "0b00";
        ram[5327] = "0b00";
        ram[5328] = "0b00";
        ram[5329] = "0b11";
        for (unsigned i = 5330; i < 5362 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5362] = "0b11";
        for (unsigned i = 5363; i < 5369 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5369] = "0b01";
        for (unsigned i = 5370; i < 5399 ; i = i + 1) {
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
        for (unsigned i = 5426; i < 5436 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5436] = "0b01";
        for (unsigned i = 5437; i < 5450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5450] = "0b11";
        ram[5451] = "0b00";
        ram[5452] = "0b11";
        for (unsigned i = 5453; i < 5473 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5473] = "0b01";
        ram[5474] = "0b00";
        ram[5475] = "0b00";
        ram[5476] = "0b00";
        ram[5477] = "0b00";
        ram[5478] = "0b11";
        ram[5479] = "0b11";
        ram[5480] = "0b00";
        ram[5481] = "0b11";
        ram[5482] = "0b00";
        ram[5483] = "0b11";
        for (unsigned i = 5484; i < 5506 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5506] = "0b01";
        for (unsigned i = 5507; i < 5514 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5514] = "0b11";
        for (unsigned i = 5515; i < 5534 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5534] = "0b01";
        for (unsigned i = 5535; i < 5553 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5553] = "0b11";
        ram[5554] = "0b00";
        ram[5555] = "0b01";
        ram[5556] = "0b00";
        ram[5557] = "0b11";
        ram[5558] = "0b00";
        ram[5559] = "0b00";
        ram[5560] = "0b01";
        ram[5561] = "0b00";
        ram[5562] = "0b00";
        ram[5563] = "0b11";
        for (unsigned i = 5564; i < 5598 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5598] = "0b11";
        for (unsigned i = 5599; i < 5642 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5642] = "0b11";
        ram[5643] = "0b00";
        ram[5644] = "0b00";
        ram[5645] = "0b00";
        ram[5646] = "0b11";
        ram[5647] = "0b11";
        ram[5648] = "0b01";
        ram[5649] = "0b01";
        ram[5650] = "0b00";
        ram[5651] = "0b11";
        ram[5652] = "0b00";
        ram[5653] = "0b00";
        ram[5654] = "0b00";
        ram[5655] = "0b00";
        ram[5656] = "0b01";
        for (unsigned i = 5657; i < 5702 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5702] = "0b11";
        for (unsigned i = 5703; i < 5709 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5709] = "0b01";
        for (unsigned i = 5710; i < 5719 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5719] = "0b01";
        for (unsigned i = 5720; i < 5756 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5756] = "0b01";
        for (unsigned i = 5757; i < 5789 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5789] = "0b01";
        for (unsigned i = 5790; i < 5819 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5819] = "0b01";
        ram[5820] = "0b00";
        ram[5821] = "0b00";
        ram[5822] = "0b01";
        ram[5823] = "0b01";
        for (unsigned i = 5824; i < 5842 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5842] = "0b01";
        ram[5843] = "0b00";
        ram[5844] = "0b00";
        ram[5845] = "0b00";
        ram[5846] = "0b00";
        ram[5847] = "0b10";
        ram[5848] = "0b00";
        ram[5849] = "0b01";
        for (unsigned i = 5850; i < 5859 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5859] = "0b11";
        for (unsigned i = 5860; i < 5941 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5941] = "0b11";
        for (unsigned i = 5942; i < 5994 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5994] = "0b01";
        for (unsigned i = 5995; i < 6046 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6046] = "0b11";
        ram[6047] = "0b11";
        ram[6048] = "0b11";
        for (unsigned i = 6049; i < 6057 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6057] = "0b01";
        ram[6058] = "0b00";
        ram[6059] = "0b01";
        for (unsigned i = 6060; i < 6089 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6089] = "0b11";
        for (unsigned i = 6090; i < 6106 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6106] = "0b01";
        ram[6107] = "0b00";
        ram[6108] = "0b00";
        ram[6109] = "0b00";
        ram[6110] = "0b01";
        ram[6111] = "0b00";
        ram[6112] = "0b00";
        ram[6113] = "0b11";
        ram[6114] = "0b00";
        ram[6115] = "0b00";
        ram[6116] = "0b00";
        ram[6117] = "0b00";
        ram[6118] = "0b11";
        for (unsigned i = 6119; i < 6134 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6134] = "0b01";
        ram[6135] = "0b00";
        ram[6136] = "0b11";
        for (unsigned i = 6137; i < 6151 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6151] = "0b01";
        ram[6152] = "0b00";
        ram[6153] = "0b00";
        ram[6154] = "0b00";
        ram[6155] = "0b01";
        for (unsigned i = 6156; i < 6164 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6164] = "0b01";
        for (unsigned i = 6165; i < 6232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6232] = "0b11";
        for (unsigned i = 6233; i < 6246 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6246] = "0b11";
        ram[6247] = "0b00";
        ram[6248] = "0b00";
        ram[6249] = "0b01";
        ram[6250] = "0b00";
        ram[6251] = "0b11";
        for (unsigned i = 6252; i < 6257 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6257] = "0b11";
        for (unsigned i = 6258; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_11) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_11_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_11) {
meminst = new mlp_accel_4b_weights_l1_4b_11_ram("mlp_accel_4b_weights_l1_4b_11_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_11() {
    delete meminst;
}


};//endmodule
#endif
