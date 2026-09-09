// ==============================================================
// File generated on Wed Sep 02 16:33:44 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_14_H__
#define __mlp_accel_4b_weights_l1_4b_14_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_14_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_14_ram) {
        for (unsigned i = 0; i < 66 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[66] = "0b01";
        for (unsigned i = 67; i < 72 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[72] = "0b11";
        ram[73] = "0b00";
        ram[74] = "0b01";
        for (unsigned i = 75; i < 119 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[119] = "0b11";
        ram[120] = "0b00";
        ram[121] = "0b00";
        ram[122] = "0b00";
        ram[123] = "0b11";
        ram[124] = "0b00";
        ram[125] = "0b00";
        ram[126] = "0b00";
        ram[127] = "0b00";
        ram[128] = "0b01";
        ram[129] = "0b01";
        for (unsigned i = 130; i < 137 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[137] = "0b01";
        for (unsigned i = 138; i < 159 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[159] = "0b11";
        ram[160] = "0b00";
        ram[161] = "0b01";
        ram[162] = "0b00";
        ram[163] = "0b11";
        ram[164] = "0b11";
        ram[165] = "0b11";
        ram[166] = "0b00";
        ram[167] = "0b00";
        ram[168] = "0b01";
        ram[169] = "0b00";
        ram[170] = "0b00";
        ram[171] = "0b11";
        for (unsigned i = 172; i < 179 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[179] = "0b11";
        ram[180] = "0b11";
        ram[181] = "0b00";
        ram[182] = "0b00";
        ram[183] = "0b00";
        ram[184] = "0b00";
        ram[185] = "0b11";
        for (unsigned i = 186; i < 313 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[313] = "0b01";
        for (unsigned i = 314; i < 320 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[320] = "0b01";
        ram[321] = "0b00";
        ram[322] = "0b11";
        for (unsigned i = 323; i < 415 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[415] = "0b01";
        for (unsigned i = 416; i < 423 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[423] = "0b11";
        for (unsigned i = 424; i < 452 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[452] = "0b11";
        ram[453] = "0b01";
        ram[454] = "0b00";
        ram[455] = "0b00";
        ram[456] = "0b00";
        ram[457] = "0b00";
        ram[458] = "0b01";
        ram[459] = "0b11";
        for (unsigned i = 460; i < 474 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[474] = "0b01";
        for (unsigned i = 475; i < 497 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[497] = "0b11";
        ram[498] = "0b00";
        ram[499] = "0b00";
        ram[500] = "0b01";
        ram[501] = "0b00";
        ram[502] = "0b00";
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
        for (unsigned i = 517; i < 523 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[523] = "0b11";
        for (unsigned i = 524; i < 548 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[548] = "0b11";
        for (unsigned i = 549; i < 555 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[555] = "0b01";
        for (unsigned i = 556; i < 599 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[599] = "0b01";
        for (unsigned i = 600; i < 626 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[626] = "0b11";
        for (unsigned i = 627; i < 644 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[644] = "0b01";
        for (unsigned i = 645; i < 653 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[653] = "0b01";
        ram[654] = "0b00";
        ram[655] = "0b00";
        ram[656] = "0b00";
        ram[657] = "0b00";
        ram[658] = "0b11";
        for (unsigned i = 659; i < 695 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[695] = "0b01";
        ram[696] = "0b00";
        ram[697] = "0b00";
        ram[698] = "0b00";
        ram[699] = "0b00";
        ram[700] = "0b11";
        ram[701] = "0b00";
        ram[702] = "0b00";
        ram[703] = "0b00";
        ram[704] = "0b11";
        for (unsigned i = 705; i < 728 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[728] = "0b11";
        for (unsigned i = 729; i < 805 ; i = i + 1) {
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
        ram[813] = "0b00";
        ram[814] = "0b00";
        ram[815] = "0b01";
        for (unsigned i = 816; i < 838 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[838] = "0b01";
        ram[839] = "0b00";
        ram[840] = "0b00";
        ram[841] = "0b00";
        ram[842] = "0b11";
        ram[843] = "0b00";
        ram[844] = "0b11";
        ram[845] = "0b00";
        ram[846] = "0b00";
        ram[847] = "0b11";
        for (unsigned i = 848; i < 854 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[854] = "0b01";
        for (unsigned i = 855; i < 872 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[872] = "0b11";
        for (unsigned i = 873; i < 912 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[912] = "0b11";
        for (unsigned i = 913; i < 945 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[945] = "0b01";
        ram[946] = "0b00";
        ram[947] = "0b00";
        ram[948] = "0b11";
        for (unsigned i = 949; i < 955 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[955] = "0b01";
        for (unsigned i = 956; i < 992 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[992] = "0b11";
        ram[993] = "0b00";
        ram[994] = "0b01";
        for (unsigned i = 995; i < 1040 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1040] = "0b11";
        for (unsigned i = 1041; i < 1053 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1053] = "0b11";
        for (unsigned i = 1054; i < 1059 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1059] = "0b11";
        for (unsigned i = 1060; i < 1099 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1099] = "0b01";
        for (unsigned i = 1100; i < 1110 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1110] = "0b11";
        for (unsigned i = 1111; i < 1141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1141] = "0b01";
        for (unsigned i = 1142; i < 1148 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1148] = "0b11";
        for (unsigned i = 1149; i < 1194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1194] = "0b01";
        ram[1195] = "0b00";
        ram[1196] = "0b00";
        ram[1197] = "0b01";
        ram[1198] = "0b00";
        ram[1199] = "0b00";
        ram[1200] = "0b11";
        ram[1201] = "0b11";
        for (unsigned i = 1202; i < 1208 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1208] = "0b11";
        ram[1209] = "0b00";
        ram[1210] = "0b00";
        ram[1211] = "0b00";
        ram[1212] = "0b00";
        ram[1213] = "0b11";
        for (unsigned i = 1214; i < 1220 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1220] = "0b11";
        for (unsigned i = 1221; i < 1302 ; i = i + 1) {
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
        ram[1398] = "0b10";
        ram[1399] = "0b00";
        ram[1400] = "0b00";
        ram[1401] = "0b00";
        ram[1402] = "0b01";
        ram[1403] = "0b11";
        for (unsigned i = 1404; i < 1414 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1414] = "0b01";
        for (unsigned i = 1415; i < 1430 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1430] = "0b01";
        ram[1431] = "0b00";
        ram[1432] = "0b00";
        ram[1433] = "0b11";
        for (unsigned i = 1434; i < 1451 ; i = i + 1) {
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
        for (unsigned i = 1529; i < 1589 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1589] = "0b11";
        ram[1590] = "0b00";
        ram[1591] = "0b01";
        for (unsigned i = 1592; i < 1631 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1631] = "0b01";
        for (unsigned i = 1632; i < 1641 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1641] = "0b11";
        ram[1642] = "0b11";
        for (unsigned i = 1643; i < 1774 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1774] = "0b11";
        for (unsigned i = 1775; i < 1782 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1782] = "0b11";
        for (unsigned i = 1783; i < 1822 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1822] = "0b01";
        for (unsigned i = 1823; i < 1831 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1831] = "0b11";
        for (unsigned i = 1832; i < 1841 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1841] = "0b01";
        ram[1842] = "0b00";
        ram[1843] = "0b00";
        ram[1844] = "0b00";
        ram[1845] = "0b00";
        ram[1846] = "0b01";
        for (unsigned i = 1847; i < 1893 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1893] = "0b01";
        for (unsigned i = 1894; i < 1925 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1925] = "0b01";
        ram[1926] = "0b00";
        ram[1927] = "0b01";
        ram[1928] = "0b00";
        ram[1929] = "0b00";
        ram[1930] = "0b00";
        ram[1931] = "0b00";
        ram[1932] = "0b11";
        for (unsigned i = 1933; i < 1941 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1941] = "0b11";
        for (unsigned i = 1942; i < 1967 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1967] = "0b01";
        for (unsigned i = 1968; i < 1978 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1978] = "0b10";
        ram[1979] = "0b00";
        ram[1980] = "0b00";
        ram[1981] = "0b01";
        ram[1982] = "0b00";
        ram[1983] = "0b11";
        for (unsigned i = 1984; i < 2030 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2030] = "0b01";
        ram[2031] = "0b00";
        ram[2032] = "0b00";
        ram[2033] = "0b11";
        for (unsigned i = 2034; i < 2076 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2076] = "0b01";
        ram[2077] = "0b00";
        ram[2078] = "0b00";
        ram[2079] = "0b00";
        ram[2080] = "0b00";
        ram[2081] = "0b11";
        ram[2082] = "0b01";
        for (unsigned i = 2083; i < 2091 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2091] = "0b11";
        for (unsigned i = 2092; i < 2100 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2100] = "0b01";
        for (unsigned i = 2101; i < 2116 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2116] = "0b01";
        ram[2117] = "0b00";
        ram[2118] = "0b01";
        ram[2119] = "0b00";
        ram[2120] = "0b00";
        ram[2121] = "0b00";
        ram[2122] = "0b00";
        ram[2123] = "0b11";
        ram[2124] = "0b00";
        ram[2125] = "0b11";
        ram[2126] = "0b00";
        ram[2127] = "0b00";
        ram[2128] = "0b11";
        for (unsigned i = 2129; i < 2135 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2135] = "0b11";
        ram[2136] = "0b00";
        ram[2137] = "0b00";
        ram[2138] = "0b00";
        ram[2139] = "0b00";
        ram[2140] = "0b11";
        for (unsigned i = 2141; i < 2151 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2151] = "0b01";
        for (unsigned i = 2152; i < 2321 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2321] = "0b01";
        for (unsigned i = 2322; i < 2329 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2329] = "0b01";
        ram[2330] = "0b00";
        ram[2331] = "0b00";
        ram[2332] = "0b00";
        ram[2333] = "0b00";
        ram[2334] = "0b11";
        ram[2335] = "0b00";
        ram[2336] = "0b11";
        ram[2337] = "0b00";
        ram[2338] = "0b00";
        ram[2339] = "0b00";
        ram[2340] = "0b11";
        for (unsigned i = 2341; i < 2357 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2357] = "0b01";
        for (unsigned i = 2358; i < 2364 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2364] = "0b01";
        ram[2365] = "0b00";
        ram[2366] = "0b00";
        ram[2367] = "0b00";
        ram[2368] = "0b00";
        ram[2369] = "0b11";
        ram[2370] = "0b00";
        ram[2371] = "0b10";
        ram[2372] = "0b00";
        ram[2373] = "0b00";
        ram[2374] = "0b00";
        ram[2375] = "0b00";
        ram[2376] = "0b01";
        for (unsigned i = 2377; i < 2408 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2408] = "0b11";
        for (unsigned i = 2409; i < 2419 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2419] = "0b11";
        for (unsigned i = 2420; i < 2425 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2425] = "0b11";
        ram[2426] = "0b00";
        ram[2427] = "0b01";
        for (unsigned i = 2428; i < 2457 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2457] = "0b11";
        for (unsigned i = 2458; i < 2471 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2471] = "0b11";
        ram[2472] = "0b00";
        ram[2473] = "0b00";
        ram[2474] = "0b00";
        ram[2475] = "0b00";
        ram[2476] = "0b01";
        ram[2477] = "0b00";
        ram[2478] = "0b00";
        ram[2479] = "0b00";
        ram[2480] = "0b01";
        ram[2481] = "0b00";
        ram[2482] = "0b00";
        ram[2483] = "0b11";
        for (unsigned i = 2484; i < 2489 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2489] = "0b11";
        for (unsigned i = 2490; i < 2508 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2508] = "0b11";
        for (unsigned i = 2509; i < 2515 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2515] = "0b01";
        ram[2516] = "0b00";
        ram[2517] = "0b00";
        ram[2518] = "0b11";
        ram[2519] = "0b00";
        ram[2520] = "0b00";
        ram[2521] = "0b00";
        ram[2522] = "0b11";
        ram[2523] = "0b00";
        ram[2524] = "0b11";
        ram[2525] = "0b11";
        ram[2526] = "0b00";
        ram[2527] = "0b01";
        for (unsigned i = 2528; i < 2564 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2564] = "0b11";
        for (unsigned i = 2565; i < 2609 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2609] = "0b01";
        for (unsigned i = 2610; i < 2686 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2686] = "0b01";
        for (unsigned i = 2687; i < 2718 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2718] = "0b11";
        for (unsigned i = 2719; i < 2730 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2730] = "0b01";
        ram[2731] = "0b00";
        ram[2732] = "0b00";
        ram[2733] = "0b00";
        ram[2734] = "0b11";
        for (unsigned i = 2735; i < 2760 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2760] = "0b11";
        for (unsigned i = 2761; i < 2774 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2774] = "0b11";
        for (unsigned i = 2775; i < 2788 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2788] = "0b01";
        for (unsigned i = 2789; i < 2812 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2812] = "0b01";
        for (unsigned i = 2813; i < 2821 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2821] = "0b01";
        ram[2822] = "0b00";
        ram[2823] = "0b00";
        ram[2824] = "0b11";
        ram[2825] = "0b00";
        ram[2826] = "0b11";
        for (unsigned i = 2827; i < 2856 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2856] = "0b11";
        for (unsigned i = 2857; i < 2867 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2867] = "0b01";
        for (unsigned i = 2868; i < 2880 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2880] = "0b11";
        for (unsigned i = 2881; i < 2917 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2917] = "0b11";
        for (unsigned i = 2918; i < 2950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2950] = "0b11";
        for (unsigned i = 2951; i < 2966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2966] = "0b11";
        for (unsigned i = 2967; i < 2973 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2973] = "0b01";
        for (unsigned i = 2974; i < 2996 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2996] = "0b11";
        ram[2997] = "0b00";
        ram[2998] = "0b00";
        ram[2999] = "0b01";
        for (unsigned i = 3000; i < 3021 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3021] = "0b11";
        ram[3022] = "0b11";
        ram[3023] = "0b00";
        ram[3024] = "0b00";
        ram[3025] = "0b00";
        ram[3026] = "0b11";
        ram[3027] = "0b01";
        for (unsigned i = 3028; i < 3033 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3033] = "0b11";
        for (unsigned i = 3034; i < 3068 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3068] = "0b01";
        for (unsigned i = 3069; i < 3103 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3103] = "0b01";
        ram[3104] = "0b00";
        ram[3105] = "0b00";
        ram[3106] = "0b00";
        ram[3107] = "0b00";
        ram[3108] = "0b11";
        for (unsigned i = 3109; i < 3118 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3118] = "0b11";
        for (unsigned i = 3119; i < 3145 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3145] = "0b01";
        for (unsigned i = 3146; i < 3152 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3152] = "0b10";
        ram[3153] = "0b00";
        ram[3154] = "0b11";
        for (unsigned i = 3155; i < 3197 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3197] = "0b11";
        for (unsigned i = 3198; i < 3213 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3213] = "0b01";
        for (unsigned i = 3214; i < 3292 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3292] = "0b11";
        ram[3293] = "0b00";
        ram[3294] = "0b11";
        ram[3295] = "0b00";
        ram[3296] = "0b00";
        ram[3297] = "0b01";
        for (unsigned i = 3298; i < 3318 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3318] = "0b01";
        ram[3319] = "0b00";
        ram[3320] = "0b11";
        for (unsigned i = 3321; i < 3353 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3353] = "0b11";
        for (unsigned i = 3354; i < 3360 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3360] = "0b01";
        for (unsigned i = 3361; i < 3388 ; i = i + 1) {
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
        ram[3399] = "0b01";
        ram[3400] = "0b11";
        ram[3401] = "0b00";
        ram[3402] = "0b01";
        for (unsigned i = 3403; i < 3421 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3421] = "0b11";
        for (unsigned i = 3422; i < 3444 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3444] = "0b01";
        ram[3445] = "0b00";
        ram[3446] = "0b00";
        ram[3447] = "0b00";
        ram[3448] = "0b00";
        ram[3449] = "0b11";
        ram[3450] = "0b00";
        ram[3451] = "0b00";
        ram[3452] = "0b00";
        ram[3453] = "0b00";
        ram[3454] = "0b10";
        for (unsigned i = 3455; i < 3469 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3469] = "0b01";
        ram[3470] = "0b00";
        ram[3471] = "0b00";
        ram[3472] = "0b00";
        ram[3473] = "0b00";
        ram[3474] = "0b11";
        ram[3475] = "0b11";
        for (unsigned i = 3476; i < 3502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3502] = "0b11";
        for (unsigned i = 3503; i < 3570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3570] = "0b01";
        for (unsigned i = 3571; i < 3587 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3587] = "0b11";
        for (unsigned i = 3588; i < 3596 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3596] = "0b01";
        ram[3597] = "0b00";
        ram[3598] = "0b11";
        ram[3599] = "0b00";
        ram[3600] = "0b00";
        ram[3601] = "0b00";
        ram[3602] = "0b00";
        ram[3603] = "0b01";
        ram[3604] = "0b00";
        ram[3605] = "0b11";
        for (unsigned i = 3606; i < 3710 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3710] = "0b01";
        ram[3711] = "0b00";
        ram[3712] = "0b00";
        ram[3713] = "0b00";
        ram[3714] = "0b00";
        ram[3715] = "0b01";
        ram[3716] = "0b00";
        ram[3717] = "0b01";
        for (unsigned i = 3718; i < 3785 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3785] = "0b11";
        for (unsigned i = 3786; i < 3848 ; i = i + 1) {
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
        for (unsigned i = 3856; i < 3862 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3862] = "0b01";
        ram[3863] = "0b00";
        ram[3864] = "0b00";
        ram[3865] = "0b00";
        ram[3866] = "0b11";
        for (unsigned i = 3867; i < 3895 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3895] = "0b11";
        ram[3896] = "0b00";
        ram[3897] = "0b01";
        ram[3898] = "0b00";
        ram[3899] = "0b11";
        ram[3900] = "0b00";
        ram[3901] = "0b01";
        for (unsigned i = 3902; i < 3943 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3943] = "0b11";
        for (unsigned i = 3944; i < 3995 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3995] = "0b01";
        ram[3996] = "0b00";
        ram[3997] = "0b00";
        ram[3998] = "0b00";
        ram[3999] = "0b00";
        ram[4000] = "0b11";
        ram[4001] = "0b00";
        ram[4002] = "0b11";
        for (unsigned i = 4003; i < 4049 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4049] = "0b01";
        for (unsigned i = 4050; i < 4078 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4078] = "0b11";
        for (unsigned i = 4079; i < 4100 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4100] = "0b11";
        for (unsigned i = 4101; i < 4107 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4107] = "0b11";
        for (unsigned i = 4108; i < 4154 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4154] = "0b01";
        for (unsigned i = 4155; i < 4191 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4191] = "0b11";
        for (unsigned i = 4192; i < 4198 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4198] = "0b01";
        for (unsigned i = 4199; i < 4235 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4235] = "0b01";
        for (unsigned i = 4236; i < 4322 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4322] = "0b11";
        ram[4323] = "0b00";
        ram[4324] = "0b01";
        for (unsigned i = 4325; i < 4336 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4336] = "0b11";
        ram[4337] = "0b00";
        ram[4338] = "0b00";
        ram[4339] = "0b00";
        ram[4340] = "0b01";
        ram[4341] = "0b00";
        ram[4342] = "0b00";
        ram[4343] = "0b00";
        ram[4344] = "0b11";
        for (unsigned i = 4345; i < 4351 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4351] = "0b11";
        ram[4352] = "0b00";
        ram[4353] = "0b00";
        ram[4354] = "0b00";
        ram[4355] = "0b00";
        ram[4356] = "0b11";
        for (unsigned i = 4357; i < 4389 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4389] = "0b11";
        for (unsigned i = 4390; i < 4469 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4469] = "0b11";
        ram[4470] = "0b00";
        ram[4471] = "0b00";
        ram[4472] = "0b00";
        ram[4473] = "0b01";
        for (unsigned i = 4474; i < 4483 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4483] = "0b11";
        ram[4484] = "0b11";
        ram[4485] = "0b00";
        ram[4486] = "0b00";
        ram[4487] = "0b00";
        ram[4488] = "0b00";
        ram[4489] = "0b11";
        ram[4490] = "0b00";
        ram[4491] = "0b01";
        ram[4492] = "0b01";
        for (unsigned i = 4493; i < 4501 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4501] = "0b11";
        ram[4502] = "0b00";
        ram[4503] = "0b11";
        for (unsigned i = 4504; i < 4575 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4575] = "0b11";
        for (unsigned i = 4576; i < 4583 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4583] = "0b11";
        for (unsigned i = 4584; i < 4590 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4590] = "0b01";
        ram[4591] = "0b00";
        ram[4592] = "0b01";
        ram[4593] = "0b00";
        ram[4594] = "0b00";
        ram[4595] = "0b11";
        ram[4596] = "0b00";
        ram[4597] = "0b00";
        ram[4598] = "0b00";
        ram[4599] = "0b11";
        for (unsigned i = 4600; i < 4613 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4613] = "0b11";
        ram[4614] = "0b00";
        ram[4615] = "0b11";
        ram[4616] = "0b11";
        for (unsigned i = 4617; i < 4624 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4624] = "0b11";
        for (unsigned i = 4625; i < 4671 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4671] = "0b01";
        for (unsigned i = 4672; i < 4685 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4685] = "0b11";
        ram[4686] = "0b00";
        ram[4687] = "0b00";
        ram[4688] = "0b11";
        for (unsigned i = 4689; i < 4774 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4774] = "0b11";
        for (unsigned i = 4775; i < 4827 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4827] = "0b11";
        for (unsigned i = 4828; i < 4839 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4839] = "0b01";
        for (unsigned i = 4840; i < 4861 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4861] = "0b11";
        for (unsigned i = 4862; i < 4869 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4869] = "0b01";
        for (unsigned i = 4870; i < 4877 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4877] = "0b01";
        for (unsigned i = 4878; i < 4884 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4884] = "0b01";
        ram[4885] = "0b00";
        ram[4886] = "0b00";
        ram[4887] = "0b00";
        ram[4888] = "0b00";
        ram[4889] = "0b01";
        ram[4890] = "0b00";
        ram[4891] = "0b01";
        for (unsigned i = 4892; i < 4914 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4914] = "0b11";
        ram[4915] = "0b00";
        ram[4916] = "0b00";
        ram[4917] = "0b00";
        ram[4918] = "0b00";
        ram[4919] = "0b01";
        for (unsigned i = 4920; i < 4931 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4931] = "0b11";
        ram[4932] = "0b00";
        ram[4933] = "0b00";
        ram[4934] = "0b00";
        ram[4935] = "0b01";
        ram[4936] = "0b00";
        ram[4937] = "0b00";
        ram[4938] = "0b00";
        ram[4939] = "0b00";
        ram[4940] = "0b11";
        for (unsigned i = 4941; i < 4973 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4973] = "0b11";
        for (unsigned i = 4974; i < 4981 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4981] = "0b11";
        for (unsigned i = 4982; i < 5054 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5054] = "0b01";
        ram[5055] = "0b00";
        ram[5056] = "0b00";
        ram[5057] = "0b00";
        ram[5058] = "0b00";
        ram[5059] = "0b11";
        for (unsigned i = 5060; i < 5065 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5065] = "0b01";
        for (unsigned i = 5066; i < 5082 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5082] = "0b01";
        ram[5083] = "0b00";
        ram[5084] = "0b11";
        ram[5085] = "0b00";
        ram[5086] = "0b00";
        ram[5087] = "0b00";
        ram[5088] = "0b00";
        ram[5089] = "0b11";
        for (unsigned i = 5090; i < 5117 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5117] = "0b01";
        for (unsigned i = 5118; i < 5131 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5131] = "0b01";
        for (unsigned i = 5132; i < 5156 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5156] = "0b01";
        for (unsigned i = 5157; i < 5162 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5162] = "0b11";
        ram[5163] = "0b00";
        ram[5164] = "0b11";
        ram[5165] = "0b00";
        ram[5166] = "0b01";
        ram[5167] = "0b00";
        ram[5168] = "0b00";
        ram[5169] = "0b01";
        for (unsigned i = 5170; i < 5187 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5187] = "0b01";
        for (unsigned i = 5188; i < 5220 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5220] = "0b11";
        ram[5221] = "0b00";
        ram[5222] = "0b11";
        for (unsigned i = 5223; i < 5299 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5299] = "0b11";
        for (unsigned i = 5300; i < 5306 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5306] = "0b11";
        for (unsigned i = 5307; i < 5313 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5313] = "0b01";
        for (unsigned i = 5314; i < 5323 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5323] = "0b11";
        ram[5324] = "0b00";
        ram[5325] = "0b00";
        ram[5326] = "0b00";
        ram[5327] = "0b11";
        ram[5328] = "0b00";
        ram[5329] = "0b11";
        for (unsigned i = 5330; i < 5362 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5362] = "0b01";
        ram[5363] = "0b00";
        ram[5364] = "0b00";
        ram[5365] = "0b00";
        ram[5366] = "0b00";
        ram[5367] = "0b01";
        for (unsigned i = 5368; i < 5397 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5397] = "0b11";
        ram[5398] = "0b00";
        ram[5399] = "0b00";
        ram[5400] = "0b11";
        ram[5401] = "0b00";
        ram[5402] = "0b00";
        ram[5403] = "0b00";
        ram[5404] = "0b01";
        ram[5405] = "0b00";
        ram[5406] = "0b01";
        for (unsigned i = 5407; i < 5418 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5418] = "0b11";
        for (unsigned i = 5419; i < 5450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5450] = "0b11";
        for (unsigned i = 5451; i < 5457 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5457] = "0b11";
        for (unsigned i = 5458; i < 5464 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5464] = "0b01";
        for (unsigned i = 5465; i < 5474 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5474] = "0b01";
        for (unsigned i = 5475; i < 5481 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5481] = "0b11";
        for (unsigned i = 5482; i < 5502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5502] = "0b11";
        ram[5503] = "0b00";
        ram[5504] = "0b00";
        ram[5505] = "0b00";
        ram[5506] = "0b00";
        ram[5507] = "0b01";
        ram[5508] = "0b00";
        ram[5509] = "0b00";
        ram[5510] = "0b00";
        ram[5511] = "0b00";
        ram[5512] = "0b11";
        for (unsigned i = 5513; i < 5560 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5560] = "0b01";
        for (unsigned i = 5561; i < 5568 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5568] = "0b11";
        for (unsigned i = 5569; i < 5642 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5642] = "0b01";
        ram[5643] = "0b00";
        ram[5644] = "0b11";
        ram[5645] = "0b11";
        ram[5646] = "0b00";
        ram[5647] = "0b01";
        ram[5648] = "0b00";
        ram[5649] = "0b00";
        ram[5650] = "0b00";
        ram[5651] = "0b01";
        ram[5652] = "0b00";
        ram[5653] = "0b00";
        ram[5654] = "0b00";
        ram[5655] = "0b00";
        ram[5656] = "0b11";
        ram[5657] = "0b00";
        ram[5658] = "0b00";
        ram[5659] = "0b00";
        ram[5660] = "0b00";
        ram[5661] = "0b01";
        ram[5662] = "0b00";
        ram[5663] = "0b00";
        ram[5664] = "0b00";
        ram[5665] = "0b00";
        ram[5666] = "0b01";
        for (unsigned i = 5667; i < 5679 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5679] = "0b11";
        for (unsigned i = 5680; i < 5721 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5721] = "0b11";
        for (unsigned i = 5722; i < 5807 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5807] = "0b11";
        for (unsigned i = 5808; i < 5815 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5815] = "0b11";
        ram[5816] = "0b00";
        ram[5817] = "0b00";
        ram[5818] = "0b00";
        ram[5819] = "0b01";
        ram[5820] = "0b00";
        ram[5821] = "0b01";
        ram[5822] = "0b01";
        for (unsigned i = 5823; i < 5847 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5847] = "0b01";
        ram[5848] = "0b00";
        ram[5849] = "0b01";
        ram[5850] = "0b00";
        ram[5851] = "0b00";
        ram[5852] = "0b11";
        for (unsigned i = 5853; i < 5873 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5873] = "0b11";
        for (unsigned i = 5874; i < 5915 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5915] = "0b01";
        for (unsigned i = 5916; i < 5994 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5994] = "0b11";
        ram[5995] = "0b00";
        ram[5996] = "0b00";
        ram[5997] = "0b00";
        ram[5998] = "0b00";
        ram[5999] = "0b01";
        for (unsigned i = 6000; i < 6046 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6046] = "0b11";
        ram[6047] = "0b00";
        ram[6048] = "0b11";
        ram[6049] = "0b00";
        ram[6050] = "0b00";
        ram[6051] = "0b00";
        ram[6052] = "0b11";
        for (unsigned i = 6053; i < 6058 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6058] = "0b01";
        for (unsigned i = 6059; i < 6071 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6071] = "0b11";
        for (unsigned i = 6072; i < 6090 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6090] = "0b11";
        for (unsigned i = 6091; i < 6118 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6118] = "0b11";
        for (unsigned i = 6119; i < 6139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6139] = "0b01";
        ram[6140] = "0b00";
        ram[6141] = "0b11";
        for (unsigned i = 6142; i < 6149 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6149] = "0b01";
        ram[6150] = "0b00";
        ram[6151] = "0b00";
        ram[6152] = "0b00";
        ram[6153] = "0b01";
        for (unsigned i = 6154; i < 6160 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6160] = "0b01";
        ram[6161] = "0b00";
        ram[6162] = "0b00";
        ram[6163] = "0b00";
        ram[6164] = "0b00";
        ram[6165] = "0b11";
        for (unsigned i = 6166; i < 6197 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6197] = "0b01";
        for (unsigned i = 6198; i < 6204 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6204] = "0b11";
        for (unsigned i = 6205; i < 6232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6232] = "0b11";
        for (unsigned i = 6233; i < 6244 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6244] = "0b11";
        for (unsigned i = 6245; i < 6265 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6265] = "0b11";
        for (unsigned i = 6266; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_14) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_14_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_14) {
meminst = new mlp_accel_4b_weights_l1_4b_14_ram("mlp_accel_4b_weights_l1_4b_14_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_14() {
    delete meminst;
}


};//endmodule
#endif
