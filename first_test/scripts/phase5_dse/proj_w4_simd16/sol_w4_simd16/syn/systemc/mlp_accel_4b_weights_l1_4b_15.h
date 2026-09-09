// ==============================================================
// File generated on Wed Sep 02 16:33:45 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_15_H__
#define __mlp_accel_4b_weights_l1_4b_15_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_15_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_15_ram) {
        for (unsigned i = 0; i < 23 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[23] = "0b01";
        for (unsigned i = 24; i < 68 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[68] = "0b11";
        ram[69] = "0b00";
        ram[70] = "0b11";
        ram[71] = "0b00";
        ram[72] = "0b00";
        ram[73] = "0b01";
        for (unsigned i = 74; i < 109 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[109] = "0b01";
        ram[110] = "0b00";
        ram[111] = "0b00";
        ram[112] = "0b11";
        ram[113] = "0b00";
        ram[114] = "0b00";
        ram[115] = "0b00";
        ram[116] = "0b11";
        ram[117] = "0b00";
        ram[118] = "0b00";
        ram[119] = "0b11";
        ram[120] = "0b00";
        ram[121] = "0b00";
        ram[122] = "0b00";
        ram[123] = "0b11";
        for (unsigned i = 124; i < 137 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[137] = "0b01";
        for (unsigned i = 138; i < 152 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[152] = "0b11";
        ram[153] = "0b00";
        ram[154] = "0b00";
        ram[155] = "0b00";
        ram[156] = "0b00";
        ram[157] = "0b11";
        for (unsigned i = 158; i < 164 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[164] = "0b11";
        for (unsigned i = 165; i < 185 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[185] = "0b11";
        for (unsigned i = 186; i < 318 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[318] = "0b01";
        for (unsigned i = 319; i < 376 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[376] = "0b11";
        for (unsigned i = 377; i < 401 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[401] = "0b11";
        for (unsigned i = 402; i < 424 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[424] = "0b11";
        for (unsigned i = 425; i < 452 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[452] = "0b11";
        ram[453] = "0b01";
        for (unsigned i = 454; i < 460 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[460] = "0b11";
        ram[461] = "0b00";
        ram[462] = "0b00";
        ram[463] = "0b00";
        ram[464] = "0b01";
        for (unsigned i = 465; i < 474 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[474] = "0b01";
        for (unsigned i = 475; i < 481 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[481] = "0b11";
        for (unsigned i = 482; i < 497 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[497] = "0b11";
        ram[498] = "0b00";
        ram[499] = "0b00";
        ram[500] = "0b00";
        ram[501] = "0b11";
        ram[502] = "0b01";
        for (unsigned i = 503; i < 509 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[509] = "0b11";
        for (unsigned i = 510; i < 534 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[534] = "0b11";
        for (unsigned i = 535; i < 556 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[556] = "0b01";
        for (unsigned i = 557; i < 599 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[599] = "0b01";
        ram[600] = "0b00";
        ram[601] = "0b00";
        ram[602] = "0b11";
        for (unsigned i = 603; i < 621 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[621] = "0b01";
        ram[622] = "0b00";
        ram[623] = "0b00";
        ram[624] = "0b00";
        ram[625] = "0b00";
        ram[626] = "0b11";
        ram[627] = "0b00";
        ram[628] = "0b00";
        ram[629] = "0b00";
        ram[630] = "0b01";
        for (unsigned i = 631; i < 644 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[644] = "0b01";
        ram[645] = "0b00";
        ram[646] = "0b00";
        ram[647] = "0b00";
        ram[648] = "0b11";
        ram[649] = "0b00";
        ram[650] = "0b00";
        ram[651] = "0b00";
        ram[652] = "0b00";
        ram[653] = "0b01";
        for (unsigned i = 654; i < 667 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[667] = "0b11";
        for (unsigned i = 668; i < 693 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[693] = "0b11";
        for (unsigned i = 694; i < 704 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[704] = "0b11";
        ram[705] = "0b00";
        ram[706] = "0b00";
        ram[707] = "0b11";
        for (unsigned i = 708; i < 714 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[714] = "0b01";
        for (unsigned i = 715; i < 730 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[730] = "0b11";
        for (unsigned i = 731; i < 805 ; i = i + 1) {
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
        for (unsigned i = 816; i < 842 ; i = i + 1) {
            ram[i] = "0b00";
        }
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
        ram[855] = "0b00";
        ram[856] = "0b00";
        ram[857] = "0b00";
        ram[858] = "0b01";
        for (unsigned i = 859; i < 872 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[872] = "0b11";
        for (unsigned i = 873; i < 948 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[948] = "0b10";
        ram[949] = "0b00";
        ram[950] = "0b00";
        ram[951] = "0b00";
        ram[952] = "0b11";
        for (unsigned i = 953; i < 1050 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1050] = "0b01";
        ram[1051] = "0b00";
        ram[1052] = "0b00";
        ram[1053] = "0b11";
        for (unsigned i = 1054; i < 1113 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1113] = "0b01";
        ram[1114] = "0b00";
        ram[1115] = "0b11";
        for (unsigned i = 1116; i < 1141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1141] = "0b01";
        ram[1142] = "0b00";
        ram[1143] = "0b01";
        ram[1144] = "0b00";
        ram[1145] = "0b00";
        ram[1146] = "0b00";
        ram[1147] = "0b00";
        ram[1148] = "0b11";
        for (unsigned i = 1149; i < 1194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1194] = "0b01";
        for (unsigned i = 1195; i < 1200 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1200] = "0b11";
        ram[1201] = "0b11";
        for (unsigned i = 1202; i < 1213 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1213] = "0b10";
        for (unsigned i = 1214; i < 1302 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1302] = "0b01";
        for (unsigned i = 1303; i < 1379 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1379] = "0b11";
        for (unsigned i = 1380; i < 1398 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1398] = "0b11";
        ram[1399] = "0b00";
        ram[1400] = "0b00";
        ram[1401] = "0b00";
        ram[1402] = "0b00";
        ram[1403] = "0b11";
        ram[1404] = "0b00";
        ram[1405] = "0b01";
        for (unsigned i = 1406; i < 1442 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1442] = "0b11";
        for (unsigned i = 1443; i < 1449 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1449] = "0b01";
        for (unsigned i = 1450; i < 1505 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1505] = "0b01";
        for (unsigned i = 1506; i < 1512 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1512] = "0b11";
        for (unsigned i = 1513; i < 1528 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1528] = "0b11";
        for (unsigned i = 1529; i < 1538 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1538] = "0b01";
        ram[1539] = "0b00";
        ram[1540] = "0b01";
        ram[1541] = "0b00";
        ram[1542] = "0b11";
        ram[1543] = "0b00";
        ram[1544] = "0b00";
        ram[1545] = "0b00";
        ram[1546] = "0b00";
        ram[1547] = "0b01";
        for (unsigned i = 1548; i < 1556 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1556] = "0b11";
        ram[1557] = "0b00";
        ram[1558] = "0b00";
        ram[1559] = "0b00";
        ram[1560] = "0b00";
        ram[1561] = "0b11";
        for (unsigned i = 1562; i < 1577 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1577] = "0b11";
        for (unsigned i = 1578; i < 1591 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1591] = "0b01";
        for (unsigned i = 1592; i < 1600 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1600] = "0b11";
        for (unsigned i = 1601; i < 1631 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1631] = "0b01";
        for (unsigned i = 1632; i < 1641 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1641] = "0b11";
        for (unsigned i = 1642; i < 1822 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1822] = "0b01";
        for (unsigned i = 1823; i < 1857 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1857] = "0b01";
        for (unsigned i = 1858; i < 1925 ; i = i + 1) {
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
        ram[1933] = "0b00";
        ram[1934] = "0b11";
        ram[1935] = "0b00";
        ram[1936] = "0b00";
        ram[1937] = "0b11";
        ram[1938] = "0b00";
        ram[1939] = "0b00";
        ram[1940] = "0b00";
        ram[1941] = "0b11";
        for (unsigned i = 1942; i < 1948 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1948] = "0b01";
        for (unsigned i = 1949; i < 1967 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1967] = "0b01";
        ram[1968] = "0b00";
        ram[1969] = "0b01";
        for (unsigned i = 1970; i < 1978 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1978] = "0b11";
        ram[1979] = "0b00";
        ram[1980] = "0b00";
        ram[1981] = "0b01";
        ram[1982] = "0b00";
        ram[1983] = "0b11";
        for (unsigned i = 1984; i < 2026 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2026] = "0b01";
        for (unsigned i = 2027; i < 2033 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2033] = "0b11";
        ram[2034] = "0b00";
        ram[2035] = "0b01";
        ram[2036] = "0b00";
        ram[2037] = "0b00";
        ram[2038] = "0b00";
        ram[2039] = "0b00";
        ram[2040] = "0b01";
        for (unsigned i = 2041; i < 2076 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2076] = "0b01";
        ram[2077] = "0b01";
        ram[2078] = "0b00";
        ram[2079] = "0b11";
        ram[2080] = "0b00";
        ram[2081] = "0b00";
        ram[2082] = "0b00";
        ram[2083] = "0b01";
        for (unsigned i = 2084; i < 2091 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2091] = "0b11";
        for (unsigned i = 2092; i < 2100 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2100] = "0b01";
        for (unsigned i = 2101; i < 2114 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2114] = "0b01";
        ram[2115] = "0b00";
        ram[2116] = "0b00";
        ram[2117] = "0b00";
        ram[2118] = "0b00";
        ram[2119] = "0b01";
        ram[2120] = "0b00";
        ram[2121] = "0b00";
        ram[2122] = "0b00";
        ram[2123] = "0b11";
        ram[2124] = "0b00";
        ram[2125] = "0b11";
        for (unsigned i = 2126; i < 2133 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2133] = "0b11";
        ram[2134] = "0b00";
        ram[2135] = "0b00";
        ram[2136] = "0b00";
        ram[2137] = "0b00";
        ram[2138] = "0b11";
        for (unsigned i = 2139; i < 2151 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2151] = "0b01";
        for (unsigned i = 2152; i < 2214 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2214] = "0b01";
        ram[2215] = "0b00";
        ram[2216] = "0b00";
        ram[2217] = "0b11";
        for (unsigned i = 2218; i < 2243 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2243] = "0b11";
        for (unsigned i = 2244; i < 2321 ; i = i + 1) {
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
        ram[2333] = "0b11";
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
        ram[2358] = "0b00";
        ram[2359] = "0b01";
        ram[2360] = "0b00";
        ram[2361] = "0b00";
        ram[2362] = "0b00";
        ram[2363] = "0b00";
        ram[2364] = "0b01";
        ram[2365] = "0b00";
        ram[2366] = "0b00";
        ram[2367] = "0b00";
        ram[2368] = "0b00";
        ram[2369] = "0b11";
        ram[2370] = "0b00";
        ram[2371] = "0b11";
        ram[2372] = "0b00";
        ram[2373] = "0b00";
        ram[2374] = "0b00";
        ram[2375] = "0b00";
        ram[2376] = "0b01";
        for (unsigned i = 2377; i < 2427 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2427] = "0b01";
        ram[2428] = "0b00";
        ram[2429] = "0b00";
        ram[2430] = "0b00";
        ram[2431] = "0b00";
        ram[2432] = "0b11";
        for (unsigned i = 2433; i < 2457 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2457] = "0b11";
        for (unsigned i = 2458; i < 2482 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2482] = "0b11";
        ram[2483] = "0b11";
        for (unsigned i = 2484; i < 2515 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2515] = "0b01";
        for (unsigned i = 2516; i < 2522 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2522] = "0b11";
        ram[2523] = "0b00";
        ram[2524] = "0b11";
        for (unsigned i = 2525; i < 2630 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2630] = "0b11";
        for (unsigned i = 2631; i < 2670 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2670] = "0b11";
        for (unsigned i = 2671; i < 2718 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2718] = "0b11";
        ram[2719] = "0b00";
        ram[2720] = "0b01";
        for (unsigned i = 2721; i < 2730 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2730] = "0b01";
        for (unsigned i = 2731; i < 2762 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2762] = "0b01";
        for (unsigned i = 2763; i < 2774 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2774] = "0b11";
        for (unsigned i = 2775; i < 2812 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2812] = "0b01";
        for (unsigned i = 2813; i < 2819 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2819] = "0b11";
        ram[2820] = "0b00";
        ram[2821] = "0b00";
        ram[2822] = "0b00";
        ram[2823] = "0b00";
        ram[2824] = "0b11";
        for (unsigned i = 2825; i < 2856 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2856] = "0b11";
        for (unsigned i = 2857; i < 2875 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2875] = "0b01";
        for (unsigned i = 2876; i < 2964 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2964] = "0b11";
        for (unsigned i = 2965; i < 2996 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2996] = "0b11";
        ram[2997] = "0b00";
        ram[2998] = "0b00";
        ram[2999] = "0b01";
        for (unsigned i = 3000; i < 3010 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3010] = "0b01";
        for (unsigned i = 3011; i < 3019 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3019] = "0b11";
        ram[3020] = "0b00";
        ram[3021] = "0b00";
        ram[3022] = "0b11";
        for (unsigned i = 3023; i < 3033 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3033] = "0b11";
        for (unsigned i = 3034; i < 3096 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3096] = "0b01";
        ram[3097] = "0b11";
        for (unsigned i = 3098; i < 3106 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3106] = "0b01";
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
        ram[3146] = "0b00";
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
        ram[3157] = "0b01";
        for (unsigned i = 3158; i < 3180 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3180] = "0b01";
        for (unsigned i = 3181; i < 3222 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3222] = "0b11";
        for (unsigned i = 3223; i < 3292 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3292] = "0b11";
        ram[3293] = "0b00";
        ram[3294] = "0b00";
        ram[3295] = "0b00";
        ram[3296] = "0b00";
        ram[3297] = "0b01";
        for (unsigned i = 3298; i < 3308 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3308] = "0b01";
        for (unsigned i = 3309; i < 3316 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3316] = "0b11";
        ram[3317] = "0b00";
        ram[3318] = "0b00";
        ram[3319] = "0b00";
        ram[3320] = "0b00";
        ram[3321] = "0b11";
        for (unsigned i = 3322; i < 3341 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3341] = "0b01";
        for (unsigned i = 3342; i < 3353 ; i = i + 1) {
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
        ram[3389] = "0b00";
        ram[3390] = "0b01";
        ram[3391] = "0b11";
        ram[3392] = "0b00";
        ram[3393] = "0b00";
        ram[3394] = "0b00";
        ram[3395] = "0b01";
        ram[3396] = "0b00";
        ram[3397] = "0b00";
        ram[3398] = "0b00";
        ram[3399] = "0b00";
        ram[3400] = "0b11";
        ram[3401] = "0b00";
        ram[3402] = "0b01";
        for (unsigned i = 3403; i < 3418 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3418] = "0b01";
        for (unsigned i = 3419; i < 3449 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3449] = "0b11";
        ram[3450] = "0b00";
        ram[3451] = "0b00";
        ram[3452] = "0b00";
        ram[3453] = "0b00";
        ram[3454] = "0b10";
        ram[3455] = "0b00";
        ram[3456] = "0b01";
        for (unsigned i = 3457; i < 3466 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3466] = "0b01";
        for (unsigned i = 3467; i < 3474 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3474] = "0b11";
        for (unsigned i = 3475; i < 3523 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3523] = "0b01";
        for (unsigned i = 3524; i < 3568 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3568] = "0b01";
        for (unsigned i = 3569; i < 3587 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3587] = "0b11";
        for (unsigned i = 3588; i < 3696 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3696] = "0b11";
        for (unsigned i = 3697; i < 3703 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3703] = "0b11";
        for (unsigned i = 3704; i < 3710 ; i = i + 1) {
            ram[i] = "0b00";
        }
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
        for (unsigned i = 3786; i < 3791 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3791] = "0b01";
        for (unsigned i = 3792; i < 3844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3844] = "0b11";
        ram[3845] = "0b00";
        ram[3846] = "0b01";
        ram[3847] = "0b00";
        ram[3848] = "0b01";
        ram[3849] = "0b00";
        ram[3850] = "0b00";
        ram[3851] = "0b00";
        ram[3852] = "0b00";
        ram[3853] = "0b11";
        ram[3854] = "0b00";
        ram[3855] = "0b10";
        ram[3856] = "0b00";
        ram[3857] = "0b00";
        ram[3858] = "0b00";
        ram[3859] = "0b00";
        ram[3860] = "0b01";
        for (unsigned i = 3861; i < 3881 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3881] = "0b11";
        for (unsigned i = 3882; i < 3895 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3895] = "0b11";
        for (unsigned i = 3896; i < 3962 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3962] = "0b01";
        for (unsigned i = 3963; i < 3974 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3974] = "0b11";
        ram[3975] = "0b00";
        ram[3976] = "0b00";
        ram[3977] = "0b00";
        ram[3978] = "0b11";
        for (unsigned i = 3979; i < 3993 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3993] = "0b01";
        ram[3994] = "0b00";
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
        for (unsigned i = 4101; i < 4111 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4111] = "0b11";
        for (unsigned i = 4112; i < 4183 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4183] = "0b11";
        for (unsigned i = 4184; i < 4191 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4191] = "0b11";
        ram[4192] = "0b00";
        ram[4193] = "0b00";
        ram[4194] = "0b00";
        ram[4195] = "0b01";
        ram[4196] = "0b00";
        ram[4197] = "0b00";
        ram[4198] = "0b01";
        for (unsigned i = 4199; i < 4284 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4284] = "0b11";
        for (unsigned i = 4285; i < 4322 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4322] = "0b11";
        for (unsigned i = 4323; i < 4337 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4337] = "0b11";
        for (unsigned i = 4338; i < 4344 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4344] = "0b11";
        ram[4345] = "0b11";
        for (unsigned i = 4346; i < 4482 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4482] = "0b11";
        for (unsigned i = 4483; i < 4489 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4489] = "0b11";
        ram[4490] = "0b00";
        ram[4491] = "0b00";
        ram[4492] = "0b01";
        for (unsigned i = 4493; i < 4501 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4501] = "0b11";
        ram[4502] = "0b00";
        ram[4503] = "0b11";
        for (unsigned i = 4504; i < 4526 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4526] = "0b01";
        ram[4527] = "0b11";
        for (unsigned i = 4528; i < 4583 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4583] = "0b11";
        ram[4584] = "0b00";
        ram[4585] = "0b00";
        ram[4586] = "0b00";
        ram[4587] = "0b01";
        ram[4588] = "0b01";
        ram[4589] = "0b00";
        ram[4590] = "0b01";
        ram[4591] = "0b00";
        ram[4592] = "0b01";
        for (unsigned i = 4593; i < 4624 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4624] = "0b11";
        for (unsigned i = 4625; i < 4631 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4631] = "0b11";
        for (unsigned i = 4632; i < 4639 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4639] = "0b01";
        for (unsigned i = 4640; i < 4685 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4685] = "0b11";
        ram[4686] = "0b11";
        for (unsigned i = 4687; i < 4741 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4741] = "0b01";
        ram[4742] = "0b00";
        ram[4743] = "0b00";
        ram[4744] = "0b00";
        ram[4745] = "0b00";
        ram[4746] = "0b01";
        ram[4747] = "0b00";
        ram[4748] = "0b01";
        for (unsigned i = 4749; i < 4776 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4776] = "0b01";
        for (unsigned i = 4777; i < 4811 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4811] = "0b01";
        for (unsigned i = 4812; i < 4835 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4835] = "0b11";
        ram[4836] = "0b00";
        ram[4837] = "0b00";
        ram[4838] = "0b00";
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
        for (unsigned i = 4878; i < 4883 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4883] = "0b01";
        for (unsigned i = 4884; i < 4889 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4889] = "0b01";
        ram[4890] = "0b11";
        for (unsigned i = 4891; i < 4905 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4905] = "0b01";
        for (unsigned i = 4906; i < 4914 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4914] = "0b11";
        for (unsigned i = 4915; i < 4940 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4940] = "0b11";
        for (unsigned i = 4941; i < 5033 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5033] = "0b01";
        for (unsigned i = 5034; i < 5054 ; i = i + 1) {
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
        for (unsigned i = 5066; i < 5080 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5080] = "0b11";
        ram[5081] = "0b00";
        ram[5082] = "0b00";
        ram[5083] = "0b00";
        ram[5084] = "0b11";
        for (unsigned i = 5085; i < 5162 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5162] = "0b11";
        for (unsigned i = 5163; i < 5218 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5218] = "0b11";
        ram[5219] = "0b00";
        ram[5220] = "0b00";
        ram[5221] = "0b00";
        ram[5222] = "0b11";
        ram[5223] = "0b00";
        ram[5224] = "0b00";
        ram[5225] = "0b00";
        ram[5226] = "0b11";
        for (unsigned i = 5227; i < 5234 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5234] = "0b01";
        for (unsigned i = 5235; i < 5262 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5262] = "0b11";
        for (unsigned i = 5263; i < 5310 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5310] = "0b11";
        ram[5311] = "0b11";
        ram[5312] = "0b00";
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
        for (unsigned i = 5330; i < 5357 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5357] = "0b11";
        ram[5358] = "0b00";
        ram[5359] = "0b00";
        ram[5360] = "0b11";
        for (unsigned i = 5361; i < 5367 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5367] = "0b01";
        for (unsigned i = 5368; i < 5385 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5385] = "0b11";
        for (unsigned i = 5386; i < 5428 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5428] = "0b11";
        for (unsigned i = 5429; i < 5434 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5434] = "0b01";
        for (unsigned i = 5435; i < 5450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5450] = "0b11";
        ram[5451] = "0b01";
        ram[5452] = "0b00";
        ram[5453] = "0b11";
        for (unsigned i = 5454; i < 5474 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5474] = "0b01";
        ram[5475] = "0b00";
        ram[5476] = "0b00";
        ram[5477] = "0b00";
        ram[5478] = "0b00";
        ram[5479] = "0b11";
        ram[5480] = "0b00";
        ram[5481] = "0b11";
        for (unsigned i = 5482; i < 5507 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5507] = "0b01";
        ram[5508] = "0b00";
        ram[5509] = "0b00";
        ram[5510] = "0b00";
        ram[5511] = "0b00";
        ram[5512] = "0b11";
        for (unsigned i = 5513; i < 5519 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5519] = "0b01";
        for (unsigned i = 5520; i < 5532 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5532] = "0b01";
        for (unsigned i = 5533; i < 5551 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5551] = "0b11";
        ram[5552] = "0b00";
        ram[5553] = "0b01";
        for (unsigned i = 5554; i < 5570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5570] = "0b11";
        for (unsigned i = 5571; i < 5581 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5581] = "0b11";
        for (unsigned i = 5582; i < 5644 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5644] = "0b11";
        ram[5645] = "0b11";
        ram[5646] = "0b00";
        ram[5647] = "0b01";
        ram[5648] = "0b00";
        ram[5649] = "0b11";
        ram[5650] = "0b00";
        ram[5651] = "0b01";
        ram[5652] = "0b00";
        ram[5653] = "0b00";
        ram[5654] = "0b01";
        ram[5655] = "0b00";
        ram[5656] = "0b11";
        ram[5657] = "0b00";
        ram[5658] = "0b00";
        ram[5659] = "0b00";
        ram[5660] = "0b01";
        for (unsigned i = 5661; i < 5666 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5666] = "0b01";
        for (unsigned i = 5667; i < 5691 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5691] = "0b11";
        ram[5692] = "0b00";
        ram[5693] = "0b11";
        for (unsigned i = 5694; i < 5700 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5700] = "0b11";
        for (unsigned i = 5701; i < 5800 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5800] = "0b01";
        for (unsigned i = 5801; i < 5815 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5815] = "0b11";
        ram[5816] = "0b00";
        ram[5817] = "0b00";
        ram[5818] = "0b00";
        ram[5819] = "0b01";
        ram[5820] = "0b01";
        ram[5821] = "0b01";
        ram[5822] = "0b01";
        for (unsigned i = 5823; i < 5838 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5838] = "0b01";
        ram[5839] = "0b00";
        ram[5840] = "0b01";
        ram[5841] = "0b00";
        ram[5842] = "0b00";
        ram[5843] = "0b00";
        ram[5844] = "0b00";
        ram[5845] = "0b11";
        ram[5846] = "0b00";
        ram[5847] = "0b01";
        ram[5848] = "0b00";
        ram[5849] = "0b00";
        ram[5850] = "0b00";
        ram[5851] = "0b00";
        ram[5852] = "0b11";
        for (unsigned i = 5853; i < 5994 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5994] = "0b11";
        for (unsigned i = 5995; i < 6002 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6002] = "0b11";
        for (unsigned i = 6003; i < 6010 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6010] = "0b01";
        for (unsigned i = 6011; i < 6044 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6044] = "0b11";
        ram[6045] = "0b00";
        ram[6046] = "0b11";
        ram[6047] = "0b00";
        ram[6048] = "0b11";
        ram[6049] = "0b00";
        ram[6050] = "0b11";
        ram[6051] = "0b00";
        ram[6052] = "0b00";
        ram[6053] = "0b00";
        ram[6054] = "0b00";
        ram[6055] = "0b01";
        ram[6056] = "0b00";
        ram[6057] = "0b00";
        ram[6058] = "0b01";
        for (unsigned i = 6059; i < 6071 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6071] = "0b11";
        for (unsigned i = 6072; i < 6083 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6083] = "0b11";
        for (unsigned i = 6084; i < 6094 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6094] = "0b11";
        for (unsigned i = 6095; i < 6104 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6104] = "0b01";
        for (unsigned i = 6105; i < 6120 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6120] = "0b11";
        for (unsigned i = 6121; i < 6139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6139] = "0b01";
        for (unsigned i = 6140; i < 6169 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6169] = "0b11";
        for (unsigned i = 6170; i < 6204 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6204] = "0b11";
        for (unsigned i = 6205; i < 6239 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6239] = "0b01";
        for (unsigned i = 6240; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_15) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_15_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_15) {
meminst = new mlp_accel_4b_weights_l1_4b_15_ram("mlp_accel_4b_weights_l1_4b_15_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_15() {
    delete meminst;
}


};//endmodule
#endif
