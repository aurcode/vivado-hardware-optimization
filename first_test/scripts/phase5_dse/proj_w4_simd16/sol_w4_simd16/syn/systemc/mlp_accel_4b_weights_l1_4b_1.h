// ==============================================================
// File generated on Wed Sep 02 16:33:43 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_1_H__
#define __mlp_accel_4b_weights_l1_4b_1_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_1_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_1_ram) {
        for (unsigned i = 0; i < 20 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[20] = "0b11";
        for (unsigned i = 21; i < 29 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[29] = "0b01";
        for (unsigned i = 30; i < 71 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[71] = "0b11";
        for (unsigned i = 72; i < 104 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[104] = "0b11";
        ram[105] = "0b00";
        ram[106] = "0b11";
        for (unsigned i = 107; i < 115 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[115] = "0b01";
        for (unsigned i = 116; i < 134 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[134] = "0b01";
        ram[135] = "0b00";
        ram[136] = "0b01";
        ram[137] = "0b11";
        for (unsigned i = 138; i < 158 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[158] = "0b11";
        ram[159] = "0b00";
        ram[160] = "0b01";
        ram[161] = "0b00";
        ram[162] = "0b00";
        ram[163] = "0b00";
        ram[164] = "0b11";
        ram[165] = "0b00";
        ram[166] = "0b00";
        ram[167] = "0b01";
        ram[168] = "0b00";
        ram[169] = "0b00";
        ram[170] = "0b11";
        for (unsigned i = 171; i < 177 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[177] = "0b01";
        ram[178] = "0b11";
        for (unsigned i = 179; i < 190 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[190] = "0b01";
        for (unsigned i = 191; i < 307 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[307] = "0b11";
        ram[308] = "0b00";
        ram[309] = "0b00";
        ram[310] = "0b00";
        ram[311] = "0b00";
        ram[312] = "0b01";
        for (unsigned i = 313; i < 319 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[319] = "0b01";
        for (unsigned i = 320; i < 402 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[402] = "0b11";
        for (unsigned i = 403; i < 447 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[447] = "0b01";
        for (unsigned i = 448; i < 456 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[456] = "0b11";
        ram[457] = "0b00";
        ram[458] = "0b00";
        ram[459] = "0b00";
        ram[460] = "0b00";
        ram[461] = "0b11";
        for (unsigned i = 462; i < 496 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[496] = "0b11";
        for (unsigned i = 497; i < 503 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[503] = "0b01";
        ram[504] = "0b00";
        ram[505] = "0b00";
        ram[506] = "0b00";
        ram[507] = "0b00";
        ram[508] = "0b11";
        ram[509] = "0b00";
        ram[510] = "0b00";
        ram[511] = "0b00";
        ram[512] = "0b00";
        ram[513] = "0b11";
        ram[514] = "0b00";
        ram[515] = "0b01";
        for (unsigned i = 516; i < 526 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[526] = "0b11";
        for (unsigned i = 527; i < 535 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[535] = "0b11";
        for (unsigned i = 536; i < 570 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[570] = "0b11";
        for (unsigned i = 571; i < 608 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[608] = "0b11";
        for (unsigned i = 609; i < 625 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[625] = "0b11";
        for (unsigned i = 626; i < 643 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[643] = "0b01";
        for (unsigned i = 644; i < 652 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[652] = "0b01";
        ram[653] = "0b00";
        ram[654] = "0b00";
        ram[655] = "0b11";
        for (unsigned i = 656; i < 668 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[668] = "0b11";
        for (unsigned i = 669; i < 676 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[676] = "0b01";
        for (unsigned i = 677; i < 699 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[699] = "0b11";
        ram[700] = "0b00";
        ram[701] = "0b01";
        ram[702] = "0b00";
        ram[703] = "0b00";
        ram[704] = "0b00";
        ram[705] = "0b00";
        ram[706] = "0b11";
        for (unsigned i = 707; i < 717 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[717] = "0b01";
        for (unsigned i = 718; i < 727 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[727] = "0b11";
        for (unsigned i = 728; i < 755 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[755] = "0b11";
        ram[756] = "0b00";
        ram[757] = "0b00";
        ram[758] = "0b00";
        ram[759] = "0b00";
        ram[760] = "0b01";
        for (unsigned i = 761; i < 799 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[799] = "0b11";
        ram[800] = "0b00";
        ram[801] = "0b00";
        ram[802] = "0b00";
        ram[803] = "0b00";
        ram[804] = "0b01";
        ram[805] = "0b00";
        ram[806] = "0b00";
        ram[807] = "0b11";
        ram[808] = "0b11";
        ram[809] = "0b11";
        for (unsigned i = 810; i < 821 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[821] = "0b01";
        for (unsigned i = 822; i < 843 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[843] = "0b11";
        for (unsigned i = 844; i < 849 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[849] = "0b01";
        ram[850] = "0b00";
        ram[851] = "0b00";
        ram[852] = "0b01";
        for (unsigned i = 853; i < 871 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[871] = "0b11";
        for (unsigned i = 872; i < 909 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[909] = "0b01";
        for (unsigned i = 910; i < 949 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[949] = "0b11";
        ram[950] = "0b00";
        ram[951] = "0b01";
        ram[952] = "0b00";
        ram[953] = "0b00";
        ram[954] = "0b00";
        ram[955] = "0b00";
        ram[956] = "0b01";
        ram[957] = "0b00";
        ram[958] = "0b11";
        ram[959] = "0b00";
        ram[960] = "0b00";
        ram[961] = "0b00";
        ram[962] = "0b01";
        ram[963] = "0b00";
        ram[964] = "0b00";
        ram[965] = "0b01";
        for (unsigned i = 966; i < 991 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[991] = "0b11";
        ram[992] = "0b00";
        ram[993] = "0b00";
        ram[994] = "0b00";
        ram[995] = "0b11";
        for (unsigned i = 996; i < 1002 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1002] = "0b01";
        for (unsigned i = 1003; i < 1051 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1051] = "0b01";
        ram[1052] = "0b00";
        ram[1053] = "0b00";
        ram[1054] = "0b00";
        ram[1055] = "0b00";
        ram[1056] = "0b01";
        ram[1057] = "0b00";
        ram[1058] = "0b00";
        ram[1059] = "0b11";
        for (unsigned i = 1060; i < 1098 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1098] = "0b01";
        ram[1099] = "0b00";
        ram[1100] = "0b01";
        for (unsigned i = 1101; i < 1195 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1195] = "0b01";
        for (unsigned i = 1196; i < 1207 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1207] = "0b11";
        for (unsigned i = 1208; i < 1214 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1214] = "0b11";
        ram[1215] = "0b00";
        ram[1216] = "0b00";
        ram[1217] = "0b00";
        ram[1218] = "0b00";
        ram[1219] = "0b11";
        for (unsigned i = 1220; i < 1378 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1378] = "0b11";
        for (unsigned i = 1379; i < 1392 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1392] = "0b11";
        for (unsigned i = 1393; i < 1402 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1402] = "0b11";
        ram[1403] = "0b00";
        ram[1404] = "0b11";
        ram[1405] = "0b00";
        ram[1406] = "0b01";
        for (unsigned i = 1407; i < 1413 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1413] = "0b01";
        for (unsigned i = 1414; i < 1432 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1432] = "0b11";
        for (unsigned i = 1433; i < 1439 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1439] = "0b11";
        for (unsigned i = 1440; i < 1450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1450] = "0b01";
        ram[1451] = "0b00";
        ram[1452] = "0b00";
        ram[1453] = "0b01";
        ram[1454] = "0b00";
        ram[1455] = "0b00";
        ram[1456] = "0b00";
        ram[1457] = "0b00";
        ram[1458] = "0b01";
        for (unsigned i = 1459; i < 1481 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1481] = "0b11";
        for (unsigned i = 1482; i < 1490 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1490] = "0b11";
        for (unsigned i = 1491; i < 1506 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1506] = "0b01";
        for (unsigned i = 1507; i < 1525 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1525] = "0b11";
        for (unsigned i = 1526; i < 1538 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1538] = "0b01";
        for (unsigned i = 1539; i < 1548 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1548] = "0b01";
        ram[1549] = "0b00";
        ram[1550] = "0b00";
        ram[1551] = "0b00";
        ram[1552] = "0b00";
        ram[1553] = "0b11";
        for (unsigned i = 1554; i < 1592 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1592] = "0b01";
        for (unsigned i = 1593; i < 1600 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1600] = "0b11";
        for (unsigned i = 1601; i < 1635 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1635] = "0b01";
        for (unsigned i = 1636; i < 1691 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1691] = "0b01";
        for (unsigned i = 1692; i < 1787 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1787] = "0b11";
        for (unsigned i = 1788; i < 1828 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1828] = "0b11";
        ram[1829] = "0b00";
        ram[1830] = "0b11";
        for (unsigned i = 1831; i < 1926 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1926] = "0b01";
        ram[1927] = "0b00";
        ram[1928] = "0b00";
        ram[1929] = "0b00";
        ram[1930] = "0b00";
        ram[1931] = "0b11";
        for (unsigned i = 1932; i < 1938 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1938] = "0b11";
        for (unsigned i = 1939; i < 1950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1950] = "0b01";
        ram[1951] = "0b00";
        ram[1952] = "0b00";
        ram[1953] = "0b00";
        ram[1954] = "0b01";
        for (unsigned i = 1955; i < 1977 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1977] = "0b11";
        ram[1978] = "0b11";
        ram[1979] = "0b00";
        ram[1980] = "0b01";
        ram[1981] = "0b00";
        ram[1982] = "0b00";
        ram[1983] = "0b11";
        for (unsigned i = 1984; i < 1991 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1991] = "0b01";
        for (unsigned i = 1992; i < 2032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2032] = "0b11";
        ram[2033] = "0b00";
        ram[2034] = "0b11";
        ram[2035] = "0b00";
        ram[2036] = "0b01";
        for (unsigned i = 2037; i < 2080 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2080] = "0b11";
        for (unsigned i = 2081; i < 2090 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2090] = "0b11";
        ram[2091] = "0b00";
        ram[2092] = "0b11";
        for (unsigned i = 2093; i < 2101 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2101] = "0b01";
        for (unsigned i = 2102; i < 2113 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2113] = "0b01";
        for (unsigned i = 2114; i < 2124 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2124] = "0b11";
        ram[2125] = "0b01";
        ram[2126] = "0b00";
        ram[2127] = "0b11";
        for (unsigned i = 2128; i < 2134 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2134] = "0b11";
        for (unsigned i = 2135; i < 2141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2141] = "0b11";
        for (unsigned i = 2142; i < 2148 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2148] = "0b01";
        ram[2149] = "0b00";
        ram[2150] = "0b00";
        ram[2151] = "0b00";
        ram[2152] = "0b01";
        for (unsigned i = 2153; i < 2218 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2218] = "0b11";
        ram[2219] = "0b00";
        ram[2220] = "0b00";
        ram[2221] = "0b00";
        ram[2222] = "0b11";
        for (unsigned i = 2223; i < 2232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2232] = "0b11";
        for (unsigned i = 2233; i < 2311 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2311] = "0b11";
        ram[2312] = "0b00";
        ram[2313] = "0b11";
        for (unsigned i = 2314; i < 2322 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2322] = "0b01";
        for (unsigned i = 2323; i < 2328 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2328] = "0b01";
        for (unsigned i = 2329; i < 2335 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2335] = "0b10";
        for (unsigned i = 2336; i < 2346 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2346] = "0b11";
        for (unsigned i = 2347; i < 2358 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2358] = "0b01";
        for (unsigned i = 2359; i < 2370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2370] = "0b10";
        ram[2371] = "0b00";
        ram[2372] = "0b00";
        ram[2373] = "0b00";
        ram[2374] = "0b00";
        ram[2375] = "0b11";
        ram[2376] = "0b00";
        ram[2377] = "0b01";
        for (unsigned i = 2378; i < 2428 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2428] = "0b01";
        for (unsigned i = 2429; i < 2470 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2470] = "0b11";
        for (unsigned i = 2471; i < 2479 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2479] = "0b01";
        for (unsigned i = 2480; i < 2505 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2505] = "0b11";
        ram[2506] = "0b00";
        ram[2507] = "0b00";
        ram[2508] = "0b00";
        ram[2509] = "0b00";
        ram[2510] = "0b11";
        for (unsigned i = 2511; i < 2517 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2517] = "0b11";
        ram[2518] = "0b01";
        ram[2519] = "0b00";
        ram[2520] = "0b00";
        ram[2521] = "0b11";
        ram[2522] = "0b00";
        ram[2523] = "0b11";
        ram[2524] = "0b00";
        ram[2525] = "0b00";
        ram[2526] = "0b00";
        ram[2527] = "0b00";
        ram[2528] = "0b11";
        for (unsigned i = 2529; i < 2542 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2542] = "0b11";
        ram[2543] = "0b00";
        ram[2544] = "0b00";
        ram[2545] = "0b01";
        for (unsigned i = 2546; i < 2615 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2615] = "0b11";
        for (unsigned i = 2616; i < 2677 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2677] = "0b01";
        for (unsigned i = 2678; i < 2715 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2715] = "0b11";
        ram[2716] = "0b00";
        ram[2717] = "0b00";
        ram[2718] = "0b01";
        for (unsigned i = 2719; i < 2729 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2729] = "0b11";
        ram[2730] = "0b00";
        ram[2731] = "0b01";
        for (unsigned i = 2732; i < 2762 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2762] = "0b01";
        ram[2763] = "0b00";
        ram[2764] = "0b11";
        for (unsigned i = 2765; i < 2774 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2774] = "0b11";
        for (unsigned i = 2775; i < 2799 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2799] = "0b11";
        for (unsigned i = 2800; i < 2816 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2816] = "0b01";
        for (unsigned i = 2817; i < 2825 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2825] = "0b11";
        ram[2826] = "0b00";
        ram[2827] = "0b01";
        for (unsigned i = 2828; i < 2855 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2855] = "0b11";
        for (unsigned i = 2856; i < 2866 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2866] = "0b01";
        ram[2867] = "0b00";
        ram[2868] = "0b00";
        ram[2869] = "0b01";
        for (unsigned i = 2870; i < 2879 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2879] = "0b11";
        for (unsigned i = 2880; i < 2885 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2885] = "0b11";
        for (unsigned i = 2886; i < 2904 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2904] = "0b01";
        for (unsigned i = 2905; i < 2922 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2922] = "0b11";
        for (unsigned i = 2923; i < 2950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2950] = "0b01";
        for (unsigned i = 2951; i < 2965 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2965] = "0b11";
        ram[2966] = "0b00";
        ram[2967] = "0b01";
        ram[2968] = "0b00";
        ram[2969] = "0b00";
        ram[2970] = "0b11";
        for (unsigned i = 2971; i < 2981 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2981] = "0b01";
        for (unsigned i = 2982; i < 2998 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2998] = "0b01";
        ram[2999] = "0b11";
        for (unsigned i = 3000; i < 3005 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3005] = "0b11";
        ram[3006] = "0b00";
        ram[3007] = "0b00";
        ram[3008] = "0b00";
        ram[3009] = "0b11";
        for (unsigned i = 3010; i < 3021 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3021] = "0b11";
        ram[3022] = "0b00";
        ram[3023] = "0b00";
        ram[3024] = "0b00";
        ram[3025] = "0b11";
        for (unsigned i = 3026; i < 3032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3032] = "0b11";
        ram[3033] = "0b01";
        for (unsigned i = 3034; i < 3093 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3093] = "0b11";
        ram[3094] = "0b00";
        ram[3095] = "0b00";
        ram[3096] = "0b00";
        ram[3097] = "0b01";
        for (unsigned i = 3098; i < 3104 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3104] = "0b01";
        for (unsigned i = 3105; i < 3110 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3110] = "0b01";
        ram[3111] = "0b11";
        for (unsigned i = 3112; i < 3117 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3117] = "0b11";
        ram[3118] = "0b00";
        ram[3119] = "0b00";
        ram[3120] = "0b00";
        ram[3121] = "0b01";
        for (unsigned i = 3122; i < 3133 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3133] = "0b11";
        for (unsigned i = 3134; i < 3151 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3151] = "0b11";
        ram[3152] = "0b00";
        ram[3153] = "0b11";
        for (unsigned i = 3154; i < 3159 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3159] = "0b11";
        for (unsigned i = 3160; i < 3181 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3181] = "0b01";
        for (unsigned i = 3182; i < 3196 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3196] = "0b11";
        for (unsigned i = 3197; i < 3291 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3291] = "0b11";
        ram[3292] = "0b01";
        ram[3293] = "0b11";
        for (unsigned i = 3294; i < 3300 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3300] = "0b11";
        ram[3301] = "0b00";
        ram[3302] = "0b11";
        for (unsigned i = 3303; i < 3314 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3314] = "0b01";
        for (unsigned i = 3315; i < 3328 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3328] = "0b11";
        for (unsigned i = 3329; i < 3340 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3340] = "0b01";
        ram[3341] = "0b00";
        ram[3342] = "0b01";
        ram[3343] = "0b11";
        for (unsigned i = 3344; i < 3352 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3352] = "0b11";
        for (unsigned i = 3353; i < 3359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3359] = "0b01";
        for (unsigned i = 3360; i < 3370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3370] = "0b01";
        for (unsigned i = 3371; i < 3394 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3394] = "0b01";
        for (unsigned i = 3395; i < 3401 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3401] = "0b11";
        ram[3402] = "0b00";
        ram[3403] = "0b00";
        ram[3404] = "0b11";
        for (unsigned i = 3405; i < 3441 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3441] = "0b01";
        for (unsigned i = 3442; i < 3450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3450] = "0b10";
        ram[3451] = "0b00";
        ram[3452] = "0b00";
        ram[3453] = "0b11";
        ram[3454] = "0b00";
        ram[3455] = "0b11";
        for (unsigned i = 3456; i < 3475 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3475] = "0b11";
        for (unsigned i = 3476; i < 3492 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3492] = "0b01";
        for (unsigned i = 3493; i < 3595 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3595] = "0b01";
        ram[3596] = "0b00";
        ram[3597] = "0b11";
        ram[3598] = "0b00";
        ram[3599] = "0b00";
        ram[3600] = "0b00";
        ram[3601] = "0b00";
        ram[3602] = "0b01";
        for (unsigned i = 3603; i < 3697 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3697] = "0b11";
        for (unsigned i = 3698; i < 3705 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3705] = "0b11";
        ram[3706] = "0b00";
        ram[3707] = "0b11";
        for (unsigned i = 3708; i < 3718 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3718] = "0b01";
        for (unsigned i = 3719; i < 3788 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3788] = "0b01";
        for (unsigned i = 3789; i < 3804 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3804] = "0b11";
        for (unsigned i = 3805; i < 3811 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3811] = "0b11";
        for (unsigned i = 3812; i < 3847 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3847] = "0b01";
        ram[3848] = "0b00";
        ram[3849] = "0b01";
        ram[3850] = "0b00";
        ram[3851] = "0b00";
        ram[3852] = "0b10";
        ram[3853] = "0b00";
        ram[3854] = "0b10";
        ram[3855] = "0b00";
        ram[3856] = "0b11";
        ram[3857] = "0b00";
        ram[3858] = "0b01";
        ram[3859] = "0b01";
        for (unsigned i = 3860; i < 3896 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3896] = "0b01";
        ram[3897] = "0b00";
        ram[3898] = "0b11";
        ram[3899] = "0b00";
        ram[3900] = "0b01";
        ram[3901] = "0b00";
        ram[3902] = "0b11";
        ram[3903] = "0b00";
        ram[3904] = "0b00";
        ram[3905] = "0b11";
        for (unsigned i = 3906; i < 3933 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3933] = "0b01";
        for (unsigned i = 3934; i < 3949 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3949] = "0b11";
        for (unsigned i = 3950; i < 3959 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3959] = "0b11";
        for (unsigned i = 3960; i < 3975 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3975] = "0b11";
        for (unsigned i = 3976; i < 3988 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3988] = "0b01";
        ram[3989] = "0b00";
        ram[3990] = "0b00";
        ram[3991] = "0b00";
        ram[3992] = "0b01";
        ram[3993] = "0b00";
        ram[3994] = "0b01";
        for (unsigned i = 3995; i < 4001 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4001] = "0b11";
        ram[4002] = "0b00";
        ram[4003] = "0b00";
        ram[4004] = "0b00";
        ram[4005] = "0b00";
        ram[4006] = "0b11";
        for (unsigned i = 4007; i < 4082 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4082] = "0b01";
        ram[4083] = "0b00";
        ram[4084] = "0b00";
        ram[4085] = "0b11";
        for (unsigned i = 4086; i < 4098 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4098] = "0b01";
        for (unsigned i = 4099; i < 4194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4194] = "0b01";
        ram[4195] = "0b00";
        ram[4196] = "0b01";
        ram[4197] = "0b00";
        ram[4198] = "0b00";
        ram[4199] = "0b01";
        for (unsigned i = 4200; i < 4220 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4220] = "0b01";
        for (unsigned i = 4221; i < 4250 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4250] = "0b01";
        for (unsigned i = 4251; i < 4306 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4306] = "0b11";
        for (unsigned i = 4307; i < 4337 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4337] = "0b11";
        for (unsigned i = 4338; i < 4344 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4344] = "0b11";
        ram[4345] = "0b00";
        ram[4346] = "0b00";
        ram[4347] = "0b00";
        ram[4348] = "0b01";
        ram[4349] = "0b01";
        for (unsigned i = 4350; i < 4379 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4379] = "0b01";
        for (unsigned i = 4380; i < 4470 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4470] = "0b11";
        for (unsigned i = 4471; i < 4488 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4488] = "0b11";
        ram[4489] = "0b00";
        ram[4490] = "0b00";
        ram[4491] = "0b01";
        ram[4492] = "0b01";
        ram[4493] = "0b00";
        ram[4494] = "0b00";
        ram[4495] = "0b00";
        ram[4496] = "0b01";
        for (unsigned i = 4497; i < 4502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4502] = "0b11";
        for (unsigned i = 4503; i < 4544 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4544] = "0b01";
        for (unsigned i = 4545; i < 4586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4586] = "0b01";
        for (unsigned i = 4587; i < 4600 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4600] = "0b11";
        for (unsigned i = 4601; i < 4621 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4621] = "0b01";
        for (unsigned i = 4622; i < 4670 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4670] = "0b01";
        for (unsigned i = 4671; i < 4687 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4687] = "0b11";
        for (unsigned i = 4688; i < 4714 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4714] = "0b01";
        for (unsigned i = 4715; i < 4745 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4745] = "0b01";
        for (unsigned i = 4746; i < 4777 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4777] = "0b01";
        ram[4778] = "0b00";
        ram[4779] = "0b00";
        ram[4780] = "0b00";
        ram[4781] = "0b00";
        ram[4782] = "0b01";
        ram[4783] = "0b00";
        ram[4784] = "0b11";
        for (unsigned i = 4785; i < 4812 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4812] = "0b01";
        for (unsigned i = 4813; i < 4826 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4826] = "0b11";
        ram[4827] = "0b00";
        ram[4828] = "0b00";
        ram[4829] = "0b01";
        for (unsigned i = 4830; i < 4857 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4857] = "0b01";
        for (unsigned i = 4858; i < 4870 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4870] = "0b11";
        ram[4871] = "0b00";
        ram[4872] = "0b00";
        ram[4873] = "0b00";
        ram[4874] = "0b11";
        for (unsigned i = 4875; i < 4883 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4883] = "0b01";
        ram[4884] = "0b00";
        ram[4885] = "0b11";
        ram[4886] = "0b00";
        ram[4887] = "0b11";
        ram[4888] = "0b00";
        ram[4889] = "0b00";
        ram[4890] = "0b01";
        ram[4891] = "0b00";
        ram[4892] = "0b00";
        ram[4893] = "0b00";
        ram[4894] = "0b11";
        ram[4895] = "0b11";
        for (unsigned i = 4896; i < 4913 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4913] = "0b11";
        ram[4914] = "0b00";
        ram[4915] = "0b00";
        ram[4916] = "0b00";
        ram[4917] = "0b00";
        ram[4918] = "0b01";
        for (unsigned i = 4919; i < 4934 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4934] = "0b01";
        for (unsigned i = 4935; i < 4969 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4969] = "0b01";
        ram[4970] = "0b00";
        ram[4971] = "0b00";
        ram[4972] = "0b11";
        for (unsigned i = 4973; i < 4980 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4980] = "0b11";
        for (unsigned i = 4981; i < 4986 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4986] = "0b11";
        ram[4987] = "0b11";
        for (unsigned i = 4988; i < 5058 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5058] = "0b11";
        ram[5059] = "0b00";
        ram[5060] = "0b11";
        ram[5061] = "0b00";
        ram[5062] = "0b01";
        for (unsigned i = 5063; i < 5078 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5078] = "0b11";
        for (unsigned i = 5079; i < 5085 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5085] = "0b11";
        ram[5086] = "0b01";
        for (unsigned i = 5087; i < 5123 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5123] = "0b01";
        for (unsigned i = 5124; i < 5163 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5163] = "0b11";
        ram[5164] = "0b00";
        ram[5165] = "0b01";
        for (unsigned i = 5166; i < 5172 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5172] = "0b11";
        for (unsigned i = 5173; i < 5204 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5204] = "0b11";
        for (unsigned i = 5205; i < 5214 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5214] = "0b01";
        for (unsigned i = 5215; i < 5249 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5249] = "0b11";
        ram[5250] = "0b00";
        ram[5251] = "0b00";
        ram[5252] = "0b00";
        ram[5253] = "0b00";
        ram[5254] = "0b01";
        for (unsigned i = 5255; i < 5298 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5298] = "0b11";
        for (unsigned i = 5299; i < 5307 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5307] = "0b01";
        for (unsigned i = 5308; i < 5316 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5316] = "0b01";
        for (unsigned i = 5317; i < 5328 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5328] = "0b11";
        for (unsigned i = 5329; i < 5335 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5335] = "0b11";
        for (unsigned i = 5336; i < 5351 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5351] = "0b11";
        for (unsigned i = 5352; i < 5358 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5358] = "0b11";
        for (unsigned i = 5359; i < 5368 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5368] = "0b01";
        for (unsigned i = 5369; i < 5403 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5403] = "0b01";
        ram[5404] = "0b00";
        ram[5405] = "0b01";
        for (unsigned i = 5406; i < 5422 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5422] = "0b01";
        for (unsigned i = 5423; i < 5429 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5429] = "0b11";
        for (unsigned i = 5430; i < 5435 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5435] = "0b01";
        for (unsigned i = 5436; i < 5445 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5445] = "0b01";
        ram[5446] = "0b00";
        ram[5447] = "0b00";
        ram[5448] = "0b00";
        ram[5449] = "0b11";
        ram[5450] = "0b00";
        ram[5451] = "0b00";
        ram[5452] = "0b00";
        ram[5453] = "0b00";
        ram[5454] = "0b11";
        ram[5455] = "0b00";
        ram[5456] = "0b00";
        ram[5457] = "0b00";
        ram[5458] = "0b00";
        ram[5459] = "0b11";
        for (unsigned i = 5460; i < 5480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5480] = "0b11";
        ram[5481] = "0b00";
        ram[5482] = "0b11";
        for (unsigned i = 5483; i < 5499 ; i = i + 1) {
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
        ram[5507] = "0b00";
        ram[5508] = "0b01";
        ram[5509] = "0b00";
        ram[5510] = "0b00";
        ram[5511] = "0b00";
        ram[5512] = "0b00";
        ram[5513] = "0b11";
        for (unsigned i = 5514; i < 5527 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5527] = "0b01";
        ram[5528] = "0b00";
        ram[5529] = "0b00";
        ram[5530] = "0b00";
        ram[5531] = "0b01";
        for (unsigned i = 5532; i < 5543 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5543] = "0b11";
        for (unsigned i = 5544; i < 5557 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5557] = "0b11";
        ram[5558] = "0b00";
        ram[5559] = "0b01";
        ram[5560] = "0b00";
        ram[5561] = "0b00";
        ram[5562] = "0b11";
        for (unsigned i = 5563; i < 5646 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5646] = "0b11";
        ram[5647] = "0b00";
        ram[5648] = "0b01";
        for (unsigned i = 5649; i < 5662 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5662] = "0b11";
        for (unsigned i = 5663; i < 5678 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5678] = "0b11";
        for (unsigned i = 5679; i < 5692 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5692] = "0b11";
        for (unsigned i = 5693; i < 5711 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5711] = "0b01";
        ram[5712] = "0b00";
        ram[5713] = "0b00";
        ram[5714] = "0b00";
        ram[5715] = "0b00";
        ram[5716] = "0b11";
        for (unsigned i = 5717; i < 5760 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5760] = "0b01";
        for (unsigned i = 5761; i < 5776 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5776] = "0b11";
        for (unsigned i = 5777; i < 5818 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5818] = "0b01";
        ram[5819] = "0b00";
        ram[5820] = "0b00";
        ram[5821] = "0b01";
        ram[5822] = "0b00";
        ram[5823] = "0b01";
        for (unsigned i = 5824; i < 5839 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5839] = "0b01";
        ram[5840] = "0b00";
        ram[5841] = "0b00";
        ram[5842] = "0b00";
        ram[5843] = "0b11";
        ram[5844] = "0b00";
        ram[5845] = "0b00";
        ram[5846] = "0b00";
        ram[5847] = "0b00";
        ram[5848] = "0b01";
        ram[5849] = "0b00";
        ram[5850] = "0b11";
        for (unsigned i = 5851; i < 5872 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5872] = "0b11";
        ram[5873] = "0b00";
        ram[5874] = "0b11";
        ram[5875] = "0b01";
        for (unsigned i = 5876; i < 5940 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5940] = "0b11";
        ram[5941] = "0b00";
        ram[5942] = "0b00";
        ram[5943] = "0b00";
        ram[5944] = "0b11";
        ram[5945] = "0b11";
        for (unsigned i = 5946; i < 5952 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5952] = "0b11";
        for (unsigned i = 5953; i < 5988 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5988] = "0b11";
        for (unsigned i = 5989; i < 5995 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5995] = "0b11";
        ram[5996] = "0b00";
        ram[5997] = "0b00";
        ram[5998] = "0b01";
        ram[5999] = "0b00";
        ram[6000] = "0b11";
        for (unsigned i = 6001; i < 6009 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6009] = "0b01";
        for (unsigned i = 6010; i < 6047 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6047] = "0b11";
        ram[6048] = "0b00";
        ram[6049] = "0b11";
        ram[6050] = "0b11";
        ram[6051] = "0b11";
        for (unsigned i = 6052; i < 6057 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6057] = "0b01";
        ram[6058] = "0b00";
        ram[6059] = "0b01";
        for (unsigned i = 6060; i < 6089 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6089] = "0b11";
        for (unsigned i = 6090; i < 6100 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6100] = "0b11";
        ram[6101] = "0b00";
        ram[6102] = "0b01";
        ram[6103] = "0b01";
        ram[6104] = "0b00";
        ram[6105] = "0b01";
        ram[6106] = "0b01";
        for (unsigned i = 6107; i < 6117 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6117] = "0b11";
        for (unsigned i = 6118; i < 6135 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6135] = "0b11";
        ram[6136] = "0b11";
        ram[6137] = "0b00";
        ram[6138] = "0b00";
        ram[6139] = "0b00";
        ram[6140] = "0b11";
        ram[6141] = "0b00";
        ram[6142] = "0b00";
        ram[6143] = "0b11";
        for (unsigned i = 6144; i < 6161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6161] = "0b01";
        ram[6162] = "0b00";
        ram[6163] = "0b00";
        ram[6164] = "0b00";
        ram[6165] = "0b00";
        ram[6166] = "0b11";
        for (unsigned i = 6167; i < 6247 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6247] = "0b01";
        ram[6248] = "0b01";
        ram[6249] = "0b00";
        ram[6250] = "0b11";
        for (unsigned i = 6251; i < 6266 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6266] = "0b11";
        for (unsigned i = 6267; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_1) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_1_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_1) {
meminst = new mlp_accel_4b_weights_l1_4b_1_ram("mlp_accel_4b_weights_l1_4b_1_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_1() {
    delete meminst;
}


};//endmodule
#endif
