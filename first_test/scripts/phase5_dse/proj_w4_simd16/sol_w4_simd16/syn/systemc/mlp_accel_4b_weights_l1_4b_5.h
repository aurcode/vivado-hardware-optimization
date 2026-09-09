// ==============================================================
// File generated on Wed Sep 02 16:33:43 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_5_H__
#define __mlp_accel_4b_weights_l1_4b_5_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_5_ram : public sc_core::sc_module {

  static const unsigned DataWidth = 3;
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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_5_ram) {
        for (unsigned i = 0; i < 76 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[76] = "0b111";
        ram[77] = "0b000";
        ram[78] = "0b001";
        for (unsigned i = 79; i < 104 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[104] = "0b111";
        for (unsigned i = 105; i < 125 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[125] = "0b001";
        ram[126] = "0b000";
        ram[127] = "0b000";
        ram[128] = "0b001";
        for (unsigned i = 129; i < 134 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[134] = "0b001";
        ram[135] = "0b111";
        for (unsigned i = 136; i < 141 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[141] = "0b001";
        for (unsigned i = 142; i < 156 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[156] = "0b111";
        for (unsigned i = 157; i < 162 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[162] = "0b111";
        ram[163] = "0b111";
        ram[164] = "0b000";
        ram[165] = "0b001";
        for (unsigned i = 166; i < 175 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[175] = "0b001";
        ram[176] = "0b000";
        ram[177] = "0b000";
        ram[178] = "0b000";
        ram[179] = "0b001";
        ram[180] = "0b000";
        ram[181] = "0b111";
        for (unsigned i = 182; i < 305 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[305] = "0b111";
        ram[306] = "0b000";
        ram[307] = "0b000";
        ram[308] = "0b000";
        ram[309] = "0b000";
        ram[310] = "0b001";
        ram[311] = "0b000";
        ram[312] = "0b111";
        for (unsigned i = 313; i < 319 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[319] = "0b111";
        for (unsigned i = 320; i < 419 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[419] = "0b001";
        for (unsigned i = 420; i < 431 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[431] = "0b111";
        for (unsigned i = 432; i < 454 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[454] = "0b111";
        ram[455] = "0b000";
        ram[456] = "0b000";
        ram[457] = "0b000";
        ram[458] = "0b000";
        ram[459] = "0b111";
        for (unsigned i = 460; i < 498 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[498] = "0b111";
        for (unsigned i = 499; i < 508 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[508] = "0b111";
        ram[509] = "0b000";
        ram[510] = "0b000";
        ram[511] = "0b111";
        for (unsigned i = 512; i < 525 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[525] = "0b111";
        for (unsigned i = 526; i < 553 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[553] = "0b111";
        ram[554] = "0b111";
        ram[555] = "0b000";
        ram[556] = "0b000";
        ram[557] = "0b111";
        ram[558] = "0b000";
        ram[559] = "0b001";
        for (unsigned i = 560; i < 568 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[568] = "0b111";
        for (unsigned i = 569; i < 608 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[608] = "0b001";
        for (unsigned i = 609; i < 618 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[618] = "0b001";
        ram[619] = "0b000";
        ram[620] = "0b001";
        for (unsigned i = 621; i < 648 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[648] = "0b001";
        ram[649] = "0b000";
        ram[650] = "0b001";
        ram[651] = "0b000";
        ram[652] = "0b000";
        ram[653] = "0b000";
        ram[654] = "0b000";
        ram[655] = "0b111";
        for (unsigned i = 656; i < 697 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[697] = "0b111";
        ram[698] = "0b000";
        ram[699] = "0b001";
        ram[700] = "0b000";
        ram[701] = "0b000";
        ram[702] = "0b000";
        ram[703] = "0b000";
        ram[704] = "0b111";
        for (unsigned i = 705; i < 715 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[715] = "0b001";
        for (unsigned i = 716; i < 727 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[727] = "0b111";
        ram[728] = "0b000";
        ram[729] = "0b000";
        ram[730] = "0b111";
        for (unsigned i = 731; i < 804 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[804] = "0b001";
        ram[805] = "0b111";
        ram[806] = "0b111";
        ram[807] = "0b000";
        ram[808] = "0b000";
        ram[809] = "0b001";
        ram[810] = "0b000";
        ram[811] = "0b000";
        ram[812] = "0b111";
        for (unsigned i = 813; i < 827 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[827] = "0b111";
        for (unsigned i = 828; i < 842 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[842] = "0b001";
        ram[843] = "0b000";
        ram[844] = "0b000";
        ram[845] = "0b000";
        ram[846] = "0b111";
        for (unsigned i = 847; i < 853 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[853] = "0b001";
        for (unsigned i = 854; i < 869 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[869] = "0b111";
        ram[870] = "0b000";
        ram[871] = "0b000";
        ram[872] = "0b000";
        ram[873] = "0b000";
        ram[874] = "0b111";
        ram[875] = "0b000";
        ram[876] = "0b000";
        ram[877] = "0b000";
        ram[878] = "0b000";
        ram[879] = "0b001";
        for (unsigned i = 880; i < 907 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[907] = "0b001";
        for (unsigned i = 908; i < 942 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[942] = "0b001";
        ram[943] = "0b000";
        ram[944] = "0b000";
        ram[945] = "0b000";
        ram[946] = "0b000";
        ram[947] = "0b111";
        for (unsigned i = 948; i < 954 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[954] = "0b001";
        ram[955] = "0b000";
        ram[956] = "0b111";
        ram[957] = "0b000";
        ram[958] = "0b000";
        ram[959] = "0b000";
        ram[960] = "0b000";
        ram[961] = "0b111";
        for (unsigned i = 962; i < 1044 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1044] = "0b111";
        for (unsigned i = 1045; i < 1057 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1057] = "0b111";
        for (unsigned i = 1058; i < 1098 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1098] = "0b001";
        for (unsigned i = 1099; i < 1114 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1114] = "0b111";
        ram[1115] = "0b000";
        ram[1116] = "0b000";
        ram[1117] = "0b000";
        ram[1118] = "0b000";
        ram[1119] = "0b111";
        for (unsigned i = 1120; i < 1138 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1138] = "0b001";
        for (unsigned i = 1139; i < 1184 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1184] = "0b001";
        ram[1185] = "0b111";
        for (unsigned i = 1186; i < 1193 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1193] = "0b001";
        ram[1194] = "0b000";
        ram[1195] = "0b000";
        ram[1196] = "0b001";
        for (unsigned i = 1197; i < 1205 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1205] = "0b111";
        ram[1206] = "0b000";
        ram[1207] = "0b000";
        ram[1208] = "0b000";
        ram[1209] = "0b000";
        ram[1210] = "0b001";
        ram[1211] = "0b000";
        ram[1212] = "0b111";
        ram[1213] = "0b000";
        ram[1214] = "0b000";
        ram[1215] = "0b000";
        ram[1216] = "0b000";
        ram[1217] = "0b110";
        ram[1218] = "0b001";
        for (unsigned i = 1219; i < 1378 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1378] = "0b111";
        for (unsigned i = 1379; i < 1400 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1400] = "0b111";
        ram[1401] = "0b000";
        ram[1402] = "0b111";
        ram[1403] = "0b000";
        ram[1404] = "0b001";
        ram[1405] = "0b000";
        ram[1406] = "0b000";
        ram[1407] = "0b111";
        for (unsigned i = 1408; i < 1437 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1437] = "0b111";
        for (unsigned i = 1438; i < 1449 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1449] = "0b001";
        ram[1450] = "0b000";
        ram[1451] = "0b001";
        for (unsigned i = 1452; i < 1465 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1465] = "0b111";
        for (unsigned i = 1466; i < 1488 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1488] = "0b111";
        for (unsigned i = 1489; i < 1504 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1504] = "0b001";
        ram[1505] = "0b000";
        ram[1506] = "0b000";
        ram[1507] = "0b000";
        ram[1508] = "0b000";
        ram[1509] = "0b001";
        for (unsigned i = 1510; i < 1540 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1540] = "0b111";
        ram[1541] = "0b111";
        ram[1542] = "0b000";
        ram[1543] = "0b000";
        ram[1544] = "0b000";
        ram[1545] = "0b000";
        ram[1546] = "0b001";
        for (unsigned i = 1547; i < 1553 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1553] = "0b111";
        ram[1554] = "0b111";
        for (unsigned i = 1555; i < 1588 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1588] = "0b111";
        ram[1589] = "0b000";
        ram[1590] = "0b001";
        for (unsigned i = 1591; i < 1600 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1600] = "0b001";
        ram[1601] = "0b000";
        ram[1602] = "0b000";
        ram[1603] = "0b111";
        for (unsigned i = 1604; i < 1628 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1628] = "0b111";
        ram[1629] = "0b000";
        ram[1630] = "0b000";
        ram[1631] = "0b000";
        ram[1632] = "0b000";
        ram[1633] = "0b001";
        ram[1634] = "0b000";
        ram[1635] = "0b001";
        for (unsigned i = 1636; i < 1645 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1645] = "0b111";
        for (unsigned i = 1646; i < 1826 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1826] = "0b111";
        ram[1827] = "0b000";
        ram[1828] = "0b111";
        for (unsigned i = 1829; i < 1920 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1920] = "0b001";
        for (unsigned i = 1921; i < 1936 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1936] = "0b111";
        ram[1937] = "0b000";
        ram[1938] = "0b111";
        ram[1939] = "0b000";
        ram[1940] = "0b000";
        ram[1941] = "0b000";
        ram[1942] = "0b000";
        ram[1943] = "0b111";
        for (unsigned i = 1944; i < 1955 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1955] = "0b001";
        for (unsigned i = 1956; i < 1966 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1966] = "0b001";
        for (unsigned i = 1967; i < 1975 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1975] = "0b111";
        for (unsigned i = 1976; i < 1982 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[1982] = "0b111";
        for (unsigned i = 1983; i < 2006 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2006] = "0b111";
        for (unsigned i = 2007; i < 2030 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2030] = "0b111";
        ram[2031] = "0b000";
        ram[2032] = "0b111";
        ram[2033] = "0b000";
        ram[2034] = "0b001";
        for (unsigned i = 2035; i < 2078 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2078] = "0b111";
        for (unsigned i = 2079; i < 2085 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2085] = "0b111";
        ram[2086] = "0b000";
        ram[2087] = "0b000";
        ram[2088] = "0b111";
        ram[2089] = "0b000";
        ram[2090] = "0b111";
        for (unsigned i = 2091; i < 2099 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2099] = "0b001";
        for (unsigned i = 2100; i < 2125 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2125] = "0b111";
        for (unsigned i = 2126; i < 2132 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2132] = "0b111";
        for (unsigned i = 2133; i < 2139 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2139] = "0b111";
        for (unsigned i = 2140; i < 2153 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2153] = "0b001";
        for (unsigned i = 2154; i < 2213 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2213] = "0b001";
        ram[2214] = "0b000";
        ram[2215] = "0b000";
        ram[2216] = "0b000";
        ram[2217] = "0b000";
        ram[2218] = "0b001";
        ram[2219] = "0b001";
        for (unsigned i = 2220; i < 2326 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2326] = "0b001";
        ram[2327] = "0b000";
        ram[2328] = "0b001";
        ram[2329] = "0b000";
        ram[2330] = "0b000";
        ram[2331] = "0b000";
        ram[2332] = "0b000";
        ram[2333] = "0b111";
        ram[2334] = "0b000";
        ram[2335] = "0b000";
        ram[2336] = "0b000";
        ram[2337] = "0b111";
        for (unsigned i = 2338; i < 2344 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2344] = "0b111";
        ram[2345] = "0b001";
        for (unsigned i = 2346; i < 2356 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2356] = "0b001";
        ram[2357] = "0b000";
        ram[2358] = "0b001";
        ram[2359] = "0b000";
        ram[2360] = "0b000";
        ram[2361] = "0b000";
        ram[2362] = "0b000";
        ram[2363] = "0b001";
        ram[2364] = "0b000";
        ram[2365] = "0b000";
        ram[2366] = "0b000";
        ram[2367] = "0b000";
        ram[2368] = "0b111";
        ram[2369] = "0b000";
        ram[2370] = "0b111";
        ram[2371] = "0b000";
        ram[2372] = "0b000";
        ram[2373] = "0b111";
        for (unsigned i = 2374; i < 2380 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2380] = "0b001";
        for (unsigned i = 2381; i < 2396 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2396] = "0b001";
        for (unsigned i = 2397; i < 2426 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2426] = "0b001";
        for (unsigned i = 2427; i < 2438 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2438] = "0b111";
        for (unsigned i = 2439; i < 2466 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2466] = "0b001";
        ram[2467] = "0b000";
        ram[2468] = "0b111";
        ram[2469] = "0b000";
        ram[2470] = "0b001";
        ram[2471] = "0b000";
        ram[2472] = "0b000";
        ram[2473] = "0b000";
        ram[2474] = "0b000";
        ram[2475] = "0b111";
        ram[2476] = "0b000";
        ram[2477] = "0b001";
        ram[2478] = "0b000";
        ram[2479] = "0b000";
        ram[2480] = "0b000";
        ram[2481] = "0b000";
        ram[2482] = "0b111";
        ram[2483] = "0b000";
        ram[2484] = "0b000";
        ram[2485] = "0b000";
        ram[2486] = "0b111";
        for (unsigned i = 2487; i < 2516 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2516] = "0b001";
        ram[2517] = "0b001";
        ram[2518] = "0b000";
        ram[2519] = "0b111";
        ram[2520] = "0b000";
        ram[2521] = "0b111";
        for (unsigned i = 2522; i < 2533 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2533] = "0b111";
        ram[2534] = "0b000";
        ram[2535] = "0b111";
        ram[2536] = "0b000";
        ram[2537] = "0b000";
        ram[2538] = "0b000";
        ram[2539] = "0b000";
        ram[2540] = "0b111";
        for (unsigned i = 2541; i < 2569 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2569] = "0b111";
        for (unsigned i = 2570; i < 2608 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2608] = "0b001";
        ram[2609] = "0b000";
        ram[2610] = "0b000";
        ram[2611] = "0b000";
        ram[2612] = "0b111";
        for (unsigned i = 2613; i < 2638 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2638] = "0b111";
        for (unsigned i = 2639; i < 2671 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2671] = "0b001";
        ram[2672] = "0b000";
        ram[2673] = "0b000";
        ram[2674] = "0b000";
        ram[2675] = "0b000";
        ram[2676] = "0b111";
        for (unsigned i = 2677; i < 2720 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2720] = "0b111";
        for (unsigned i = 2721; i < 2727 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2727] = "0b111";
        for (unsigned i = 2728; i < 2762 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2762] = "0b111";
        ram[2763] = "0b000";
        ram[2764] = "0b000";
        ram[2765] = "0b000";
        ram[2766] = "0b000";
        ram[2767] = "0b001";
        ram[2768] = "0b000";
        ram[2769] = "0b000";
        ram[2770] = "0b000";
        ram[2771] = "0b000";
        ram[2772] = "0b111";
        for (unsigned i = 2773; i < 2811 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2811] = "0b001";
        ram[2812] = "0b000";
        ram[2813] = "0b000";
        ram[2814] = "0b001";
        ram[2815] = "0b000";
        ram[2816] = "0b000";
        ram[2817] = "0b000";
        ram[2818] = "0b111";
        ram[2819] = "0b000";
        ram[2820] = "0b000";
        ram[2821] = "0b000";
        ram[2822] = "0b000";
        ram[2823] = "0b111";
        ram[2824] = "0b000";
        ram[2825] = "0b001";
        ram[2826] = "0b000";
        ram[2827] = "0b000";
        ram[2828] = "0b111";
        for (unsigned i = 2829; i < 2853 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2853] = "0b111";
        for (unsigned i = 2854; i < 2860 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2860] = "0b111";
        for (unsigned i = 2861; i < 2867 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2867] = "0b001";
        for (unsigned i = 2868; i < 2883 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2883] = "0b111";
        ram[2884] = "0b000";
        ram[2885] = "0b000";
        ram[2886] = "0b111";
        for (unsigned i = 2887; i < 2902 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2902] = "0b001";
        for (unsigned i = 2903; i < 2911 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2911] = "0b001";
        for (unsigned i = 2912; i < 2968 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[2968] = "0b111";
        for (unsigned i = 2969; i < 3003 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3003] = "0b111";
        ram[3004] = "0b000";
        ram[3005] = "0b001";
        for (unsigned i = 3006; i < 3016 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3016] = "0b001";
        for (unsigned i = 3017; i < 3023 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3023] = "0b111";
        for (unsigned i = 3024; i < 3030 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3030] = "0b111";
        for (unsigned i = 3031; i < 3056 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3056] = "0b111";
        for (unsigned i = 3057; i < 3100 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3100] = "0b111";
        ram[3101] = "0b000";
        ram[3102] = "0b001";
        ram[3103] = "0b000";
        ram[3104] = "0b000";
        ram[3105] = "0b001";
        ram[3106] = "0b000";
        ram[3107] = "0b000";
        ram[3108] = "0b001";
        for (unsigned i = 3109; i < 3115 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3115] = "0b111";
        ram[3116] = "0b000";
        ram[3117] = "0b111";
        for (unsigned i = 3118; i < 3144 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3144] = "0b001";
        ram[3145] = "0b000";
        ram[3146] = "0b000";
        ram[3147] = "0b000";
        ram[3148] = "0b000";
        ram[3149] = "0b001";
        ram[3150] = "0b000";
        ram[3151] = "0b111";
        for (unsigned i = 3152; i < 3180 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3180] = "0b001";
        ram[3181] = "0b000";
        ram[3182] = "0b001";
        for (unsigned i = 3183; i < 3196 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3196] = "0b111";
        for (unsigned i = 3197; i < 3298 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3298] = "0b111";
        for (unsigned i = 3299; i < 3308 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3308] = "0b111";
        for (unsigned i = 3309; i < 3324 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3324] = "0b111";
        for (unsigned i = 3325; i < 3341 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3341] = "0b111";
        for (unsigned i = 3342; i < 3350 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3350] = "0b111";
        ram[3351] = "0b000";
        ram[3352] = "0b111";
        ram[3353] = "0b000";
        ram[3354] = "0b000";
        ram[3355] = "0b001";
        for (unsigned i = 3356; i < 3364 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3364] = "0b001";
        for (unsigned i = 3365; i < 3376 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3376] = "0b111";
        for (unsigned i = 3377; i < 3390 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3390] = "0b111";
        for (unsigned i = 3391; i < 3399 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3399] = "0b111";
        ram[3400] = "0b000";
        ram[3401] = "0b000";
        ram[3402] = "0b111";
        ram[3403] = "0b000";
        ram[3404] = "0b111";
        ram[3405] = "0b000";
        ram[3406] = "0b000";
        ram[3407] = "0b000";
        ram[3408] = "0b000";
        ram[3409] = "0b001";
        for (unsigned i = 3410; i < 3420 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3420] = "0b111";
        for (unsigned i = 3421; i < 3448 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3448] = "0b111";
        ram[3449] = "0b000";
        ram[3450] = "0b000";
        ram[3451] = "0b000";
        ram[3452] = "0b000";
        ram[3453] = "0b110";
        ram[3454] = "0b000";
        ram[3455] = "0b000";
        ram[3456] = "0b000";
        ram[3457] = "0b000";
        ram[3458] = "0b111";
        for (unsigned i = 3459; i < 3490 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3490] = "0b001";
        for (unsigned i = 3491; i < 3595 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3595] = "0b111";
        ram[3596] = "0b000";
        ram[3597] = "0b111";
        ram[3598] = "0b000";
        ram[3599] = "0b000";
        ram[3600] = "0b001";
        for (unsigned i = 3601; i < 3670 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3670] = "0b111";
        for (unsigned i = 3671; i < 3705 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3705] = "0b111";
        ram[3706] = "0b000";
        ram[3707] = "0b111";
        for (unsigned i = 3708; i < 3714 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3714] = "0b001";
        ram[3715] = "0b000";
        ram[3716] = "0b001";
        for (unsigned i = 3717; i < 3781 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3781] = "0b111";
        ram[3782] = "0b000";
        ram[3783] = "0b000";
        ram[3784] = "0b111";
        ram[3785] = "0b000";
        ram[3786] = "0b001";
        for (unsigned i = 3787; i < 3802 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3802] = "0b111";
        ram[3803] = "0b001";
        for (unsigned i = 3804; i < 3809 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3809] = "0b111";
        for (unsigned i = 3810; i < 3819 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3819] = "0b001";
        for (unsigned i = 3820; i < 3844 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3844] = "0b001";
        ram[3845] = "0b000";
        ram[3846] = "0b000";
        ram[3847] = "0b001";
        ram[3848] = "0b000";
        ram[3849] = "0b000";
        ram[3850] = "0b111";
        ram[3851] = "0b000";
        ram[3852] = "0b111";
        ram[3853] = "0b000";
        ram[3854] = "0b111";
        for (unsigned i = 3855; i < 3892 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3892] = "0b111";
        for (unsigned i = 3893; i < 3898 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3898] = "0b001";
        ram[3899] = "0b000";
        ram[3900] = "0b111";
        ram[3901] = "0b000";
        ram[3902] = "0b000";
        ram[3903] = "0b111";
        ram[3904] = "0b000";
        ram[3905] = "0b000";
        ram[3906] = "0b000";
        ram[3907] = "0b111";
        for (unsigned i = 3908; i < 3950 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3950] = "0b111";
        for (unsigned i = 3951; i < 3973 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[3973] = "0b111";
        for (unsigned i = 3974; i < 4004 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4004] = "0b111";
        for (unsigned i = 4005; i < 4015 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4015] = "0b001";
        for (unsigned i = 4016; i < 4050 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4050] = "0b111";
        for (unsigned i = 4051; i < 4080 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4080] = "0b001";
        ram[4081] = "0b000";
        ram[4082] = "0b111";
        ram[4083] = "0b111";
        ram[4084] = "0b000";
        ram[4085] = "0b111";
        for (unsigned i = 4086; i < 4096 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4096] = "0b001";
        for (unsigned i = 4097; i < 4136 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4136] = "0b001";
        for (unsigned i = 4137; i < 4194 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4194] = "0b001";
        ram[4195] = "0b111";
        for (unsigned i = 4196; i < 4232 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4232] = "0b001";
        for (unsigned i = 4233; i < 4246 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4246] = "0b111";
        ram[4247] = "0b000";
        ram[4248] = "0b001";
        ram[4249] = "0b000";
        ram[4250] = "0b000";
        ram[4251] = "0b000";
        ram[4252] = "0b000";
        ram[4253] = "0b001";
        for (unsigned i = 4254; i < 4321 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4321] = "0b111";
        for (unsigned i = 4322; i < 4342 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4342] = "0b111";
        ram[4343] = "0b000";
        ram[4344] = "0b111";
        for (unsigned i = 4345; i < 4468 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4468] = "0b111";
        ram[4469] = "0b000";
        ram[4470] = "0b000";
        ram[4471] = "0b000";
        ram[4472] = "0b000";
        ram[4473] = "0b111";
        for (unsigned i = 4474; i < 4490 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4490] = "0b001";
        for (unsigned i = 4491; i < 4535 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4535] = "0b111";
        for (unsigned i = 4536; i < 4547 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4547] = "0b001";
        for (unsigned i = 4548; i < 4584 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4584] = "0b001";
        for (unsigned i = 4585; i < 4598 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4598] = "0b111";
        for (unsigned i = 4599; i < 4619 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4619] = "0b001";
        ram[4620] = "0b000";
        ram[4621] = "0b001";
        ram[4622] = "0b000";
        ram[4623] = "0b000";
        ram[4624] = "0b000";
        ram[4625] = "0b000";
        ram[4626] = "0b110";
        ram[4627] = "0b000";
        ram[4628] = "0b111";
        for (unsigned i = 4629; i < 4676 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4676] = "0b111";
        for (unsigned i = 4677; i < 4682 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4682] = "0b111";
        for (unsigned i = 4683; i < 4731 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4731] = "0b111";
        for (unsigned i = 4732; i < 4745 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4745] = "0b001";
        for (unsigned i = 4746; i < 4774 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4774] = "0b001";
        ram[4775] = "0b001";
        for (unsigned i = 4776; i < 4827 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4827] = "0b001";
        for (unsigned i = 4828; i < 4872 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4872] = "0b111";
        for (unsigned i = 4873; i < 4881 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4881] = "0b001";
        ram[4882] = "0b000";
        ram[4883] = "0b111";
        ram[4884] = "0b000";
        ram[4885] = "0b000";
        ram[4886] = "0b000";
        ram[4887] = "0b000";
        ram[4888] = "0b001";
        ram[4889] = "0b000";
        ram[4890] = "0b000";
        ram[4891] = "0b000";
        ram[4892] = "0b111";
        ram[4893] = "0b000";
        ram[4894] = "0b111";
        for (unsigned i = 4895; i < 4906 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4906] = "0b111";
        ram[4907] = "0b000";
        ram[4908] = "0b000";
        ram[4909] = "0b000";
        ram[4910] = "0b000";
        ram[4911] = "0b111";
        ram[4912] = "0b000";
        ram[4913] = "0b000";
        ram[4914] = "0b001";
        ram[4915] = "0b000";
        ram[4916] = "0b001";
        ram[4917] = "0b000";
        ram[4918] = "0b111";
        for (unsigned i = 4919; i < 4932 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4932] = "0b001";
        for (unsigned i = 4933; i < 4946 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4946] = "0b111";
        for (unsigned i = 4947; i < 4971 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4971] = "0b001";
        ram[4972] = "0b000";
        ram[4973] = "0b000";
        ram[4974] = "0b001";
        ram[4975] = "0b000";
        ram[4976] = "0b000";
        ram[4977] = "0b000";
        ram[4978] = "0b111";
        for (unsigned i = 4979; i < 4985 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[4985] = "0b111";
        for (unsigned i = 4986; i < 5034 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5034] = "0b001";
        ram[5035] = "0b001";
        for (unsigned i = 5036; i < 5075 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5075] = "0b001";
        ram[5076] = "0b111";
        for (unsigned i = 5077; i < 5083 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5083] = "0b111";
        for (unsigned i = 5084; i < 5121 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5121] = "0b001";
        for (unsigned i = 5122; i < 5161 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5161] = "0b111";
        for (unsigned i = 5162; i < 5224 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5224] = "0b111";
        for (unsigned i = 5225; i < 5231 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5231] = "0b001";
        for (unsigned i = 5232; i < 5298 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5298] = "0b111";
        ram[5299] = "0b000";
        ram[5300] = "0b000";
        ram[5301] = "0b000";
        ram[5302] = "0b000";
        ram[5303] = "0b111";
        ram[5304] = "0b000";
        ram[5305] = "0b001";
        ram[5306] = "0b000";
        ram[5307] = "0b000";
        ram[5308] = "0b000";
        ram[5309] = "0b111";
        ram[5310] = "0b111";
        ram[5311] = "0b000";
        ram[5312] = "0b000";
        ram[5313] = "0b000";
        ram[5314] = "0b001";
        for (unsigned i = 5315; i < 5333 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5333] = "0b111";
        for (unsigned i = 5334; i < 5356 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5356] = "0b111";
        ram[5357] = "0b000";
        ram[5358] = "0b000";
        ram[5359] = "0b000";
        ram[5360] = "0b000";
        ram[5361] = "0b111";
        ram[5362] = "0b000";
        ram[5363] = "0b000";
        ram[5364] = "0b111";
        ram[5365] = "0b000";
        ram[5366] = "0b001";
        for (unsigned i = 5367; i < 5404 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5404] = "0b111";
        for (unsigned i = 5405; i < 5420 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5420] = "0b001";
        for (unsigned i = 5421; i < 5427 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5427] = "0b111";
        for (unsigned i = 5428; i < 5434 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5434] = "0b001";
        ram[5435] = "0b000";
        ram[5436] = "0b001";
        for (unsigned i = 5437; i < 5447 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5447] = "0b111";
        ram[5448] = "0b000";
        ram[5449] = "0b000";
        ram[5450] = "0b000";
        ram[5451] = "0b000";
        ram[5452] = "0b111";
        for (unsigned i = 5453; i < 5480 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5480] = "0b111";
        for (unsigned i = 5481; i < 5499 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5499] = "0b111";
        ram[5500] = "0b000";
        ram[5501] = "0b111";
        ram[5502] = "0b000";
        ram[5503] = "0b000";
        ram[5504] = "0b000";
        ram[5505] = "0b000";
        ram[5506] = "0b010";
        ram[5507] = "0b000";
        ram[5508] = "0b000";
        ram[5509] = "0b000";
        ram[5510] = "0b111";
        ram[5511] = "0b000";
        ram[5512] = "0b000";
        ram[5513] = "0b111";
        ram[5514] = "0b000";
        ram[5515] = "0b000";
        ram[5516] = "0b111";
        for (unsigned i = 5517; i < 5532 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5532] = "0b111";
        ram[5533] = "0b000";
        ram[5534] = "0b001";
        for (unsigned i = 5535; i < 5557 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5557] = "0b001";
        for (unsigned i = 5558; i < 5644 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5644] = "0b111";
        ram[5645] = "0b000";
        ram[5646] = "0b001";
        for (unsigned i = 5647; i < 5758 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5758] = "0b001";
        for (unsigned i = 5759; i < 5802 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5802] = "0b111";
        ram[5803] = "0b111";
        for (unsigned i = 5804; i < 5821 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5821] = "0b001";
        for (unsigned i = 5822; i < 5837 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5837] = "0b001";
        for (unsigned i = 5838; i < 5846 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5846] = "0b001";
        ram[5847] = "0b000";
        ram[5848] = "0b111";
        for (unsigned i = 5849; i < 5870 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5870] = "0b111";
        ram[5871] = "0b000";
        ram[5872] = "0b000";
        ram[5873] = "0b001";
        ram[5874] = "0b000";
        ram[5875] = "0b001";
        for (unsigned i = 5876; i < 5993 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[5993] = "0b111";
        ram[5994] = "0b000";
        ram[5995] = "0b000";
        ram[5996] = "0b001";
        ram[5997] = "0b000";
        ram[5998] = "0b111";
        for (unsigned i = 5999; i < 6021 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6021] = "0b111";
        for (unsigned i = 6022; i < 6036 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6036] = "0b001";
        for (unsigned i = 6037; i < 6045 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6045] = "0b111";
        ram[6046] = "0b000";
        ram[6047] = "0b000";
        ram[6048] = "0b111";
        ram[6049] = "0b111";
        ram[6050] = "0b111";
        for (unsigned i = 6051; i < 6057 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6057] = "0b001";
        for (unsigned i = 6058; i < 6068 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6068] = "0b111";
        for (unsigned i = 6069; i < 6094 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6094] = "0b111";
        ram[6095] = "0b000";
        ram[6096] = "0b000";
        ram[6097] = "0b111";
        ram[6098] = "0b000";
        ram[6099] = "0b000";
        ram[6100] = "0b000";
        ram[6101] = "0b001";
        ram[6102] = "0b000";
        ram[6103] = "0b001";
        ram[6104] = "0b000";
        ram[6105] = "0b001";
        ram[6106] = "0b000";
        ram[6107] = "0b001";
        for (unsigned i = 6108; i < 6115 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6115] = "0b111";
        ram[6116] = "0b000";
        ram[6117] = "0b111";
        ram[6118] = "0b000";
        ram[6119] = "0b000";
        ram[6120] = "0b111";
        for (unsigned i = 6121; i < 6131 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6131] = "0b001";
        for (unsigned i = 6132; i < 6141 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6141] = "0b111";
        ram[6142] = "0b000";
        ram[6143] = "0b000";
        ram[6144] = "0b000";
        ram[6145] = "0b111";
        for (unsigned i = 6146; i < 6157 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6157] = "0b001";
        ram[6158] = "0b000";
        ram[6159] = "0b000";
        ram[6160] = "0b000";
        ram[6161] = "0b001";
        for (unsigned i = 6162; i < 6192 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6192] = "0b111";
        ram[6193] = "0b000";
        ram[6194] = "0b001";
        ram[6195] = "0b000";
        ram[6196] = "0b000";
        ram[6197] = "0b000";
        ram[6198] = "0b000";
        ram[6199] = "0b001";
        for (unsigned i = 6200; i < 6243 ; i = i + 1) {
            ram[i] = "0b000";
        }
        ram[6243] = "0b001";
        ram[6244] = "0b000";
        ram[6245] = "0b001";
        ram[6246] = "0b001";
        ram[6247] = "0b000";
        ram[6248] = "0b111";
        for (unsigned i = 6249; i < 6272 ; i = i + 1) {
            ram[i] = "0b000";
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_5) {


static const unsigned DataWidth = 3;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_5_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_5) {
meminst = new mlp_accel_4b_weights_l1_4b_5_ram("mlp_accel_4b_weights_l1_4b_5_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_5() {
    delete meminst;
}


};//endmodule
#endif
