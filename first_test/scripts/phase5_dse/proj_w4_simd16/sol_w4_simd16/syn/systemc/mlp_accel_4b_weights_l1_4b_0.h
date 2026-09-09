// ==============================================================
// File generated on Wed Sep 02 16:33:43 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_0_H__
#define __mlp_accel_4b_weights_l1_4b_0_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_0_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_0_ram) {
        for (unsigned i = 0; i < 24 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[24] = "0b01";
        ram[25] = "0b00";
        ram[26] = "0b00";
        ram[27] = "0b00";
        ram[28] = "0b00";
        ram[29] = "0b01";
        ram[30] = "0b00";
        ram[31] = "0b11";
        for (unsigned i = 32; i < 66 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[66] = "0b01";
        ram[67] = "0b00";
        ram[68] = "0b00";
        ram[69] = "0b11";
        ram[70] = "0b00";
        ram[71] = "0b11";
        ram[72] = "0b00";
        ram[73] = "0b00";
        ram[74] = "0b00";
        ram[75] = "0b01";
        for (unsigned i = 76; i < 106 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[106] = "0b11";
        for (unsigned i = 107; i < 113 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[113] = "0b11";
        for (unsigned i = 114; i < 127 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[127] = "0b01";
        ram[128] = "0b00";
        ram[129] = "0b00";
        ram[130] = "0b00";
        ram[131] = "0b00";
        ram[132] = "0b11";
        ram[133] = "0b00";
        ram[134] = "0b01";
        for (unsigned i = 135; i < 153 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[153] = "0b11";
        ram[154] = "0b00";
        ram[155] = "0b00";
        ram[156] = "0b00";
        ram[157] = "0b00";
        ram[158] = "0b11";
        for (unsigned i = 159; i < 164 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[164] = "0b11";
        ram[165] = "0b11";
        ram[166] = "0b00";
        ram[167] = "0b01";
        for (unsigned i = 168; i < 177 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[177] = "0b01";
        for (unsigned i = 178; i < 305 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[305] = "0b01";
        ram[306] = "0b00";
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
        for (unsigned i = 320; i < 325 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[325] = "0b01";
        for (unsigned i = 326; i < 375 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[375] = "0b11";
        ram[376] = "0b00";
        ram[377] = "0b11";
        ram[378] = "0b00";
        ram[379] = "0b01";
        for (unsigned i = 380; i < 414 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[414] = "0b01";
        for (unsigned i = 415; i < 456 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[456] = "0b11";
        ram[457] = "0b00";
        ram[458] = "0b00";
        ram[459] = "0b00";
        ram[460] = "0b00";
        ram[461] = "0b11";
        for (unsigned i = 462; i < 475 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[475] = "0b01";
        for (unsigned i = 476; i < 486 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[486] = "0b01";
        for (unsigned i = 487; i < 502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[502] = "0b11";
        ram[503] = "0b01";
        for (unsigned i = 504; i < 510 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[510] = "0b11";
        ram[511] = "0b00";
        ram[512] = "0b00";
        ram[513] = "0b11";
        for (unsigned i = 514; i < 524 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[524] = "0b11";
        for (unsigned i = 525; i < 555 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[555] = "0b11";
        for (unsigned i = 556; i < 562 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[562] = "0b01";
        for (unsigned i = 563; i < 622 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[622] = "0b01";
        for (unsigned i = 623; i < 645 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[645] = "0b01";
        for (unsigned i = 646; i < 652 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[652] = "0b01";
        for (unsigned i = 653; i < 667 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[667] = "0b11";
        ram[668] = "0b11";
        for (unsigned i = 669; i < 701 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[701] = "0b01";
        ram[702] = "0b00";
        ram[703] = "0b00";
        ram[704] = "0b00";
        ram[705] = "0b00";
        ram[706] = "0b11";
        for (unsigned i = 707; i < 731 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[731] = "0b11";
        for (unsigned i = 732; i < 808 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[808] = "0b11";
        ram[809] = "0b11";
        for (unsigned i = 810; i < 845 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[845] = "0b11";
        ram[846] = "0b00";
        ram[847] = "0b00";
        ram[848] = "0b11";
        ram[849] = "0b00";
        ram[850] = "0b00";
        ram[851] = "0b00";
        ram[852] = "0b01";
        ram[853] = "0b00";
        ram[854] = "0b00";
        ram[855] = "0b01";
        for (unsigned i = 856; i < 866 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[866] = "0b01";
        ram[867] = "0b00";
        ram[868] = "0b00";
        ram[869] = "0b11";
        ram[870] = "0b00";
        ram[871] = "0b11";
        ram[872] = "0b00";
        ram[873] = "0b00";
        ram[874] = "0b00";
        ram[875] = "0b00";
        ram[876] = "0b11";
        for (unsigned i = 877; i < 897 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[897] = "0b01";
        for (unsigned i = 898; i < 949 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[949] = "0b11";
        ram[950] = "0b00";
        ram[951] = "0b01";
        ram[952] = "0b00";
        ram[953] = "0b11";
        ram[954] = "0b00";
        ram[955] = "0b00";
        ram[956] = "0b01";
        for (unsigned i = 957; i < 1051 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1051] = "0b01";
        for (unsigned i = 1052; i < 1142 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1142] = "0b01";
        ram[1143] = "0b00";
        ram[1144] = "0b00";
        ram[1145] = "0b00";
        ram[1146] = "0b00";
        ram[1147] = "0b11";
        for (unsigned i = 1148; i < 1195 ; i = i + 1) {
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
        for (unsigned i = 1215; i < 1404 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1404] = "0b11";
        ram[1405] = "0b00";
        ram[1406] = "0b01";
        for (unsigned i = 1407; i < 1443 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1443] = "0b11";
        for (unsigned i = 1444; i < 1450 ; i = i + 1) {
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
        for (unsigned i = 1507; i < 1513 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1513] = "0b11";
        for (unsigned i = 1514; i < 1538 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1538] = "0b01";
        ram[1539] = "0b01";
        for (unsigned i = 1540; i < 1548 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1548] = "0b01";
        ram[1549] = "0b00";
        ram[1550] = "0b00";
        ram[1551] = "0b00";
        ram[1552] = "0b00";
        ram[1553] = "0b11";
        ram[1554] = "0b00";
        ram[1555] = "0b00";
        ram[1556] = "0b00";
        ram[1557] = "0b11";
        ram[1558] = "0b00";
        ram[1559] = "0b00";
        ram[1560] = "0b00";
        ram[1561] = "0b00";
        ram[1562] = "0b11";
        for (unsigned i = 1563; i < 1629 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1629] = "0b01";
        ram[1630] = "0b00";
        ram[1631] = "0b00";
        ram[1632] = "0b01";
        for (unsigned i = 1633; i < 1640 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1640] = "0b11";
        for (unsigned i = 1641; i < 1660 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1660] = "0b11";
        for (unsigned i = 1661; i < 1683 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1683] = "0b01";
        for (unsigned i = 1684; i < 1828 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1828] = "0b11";
        ram[1829] = "0b00";
        ram[1830] = "0b11";
        for (unsigned i = 1831; i < 1905 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1905] = "0b01";
        for (unsigned i = 1906; i < 1922 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1922] = "0b01";
        ram[1923] = "0b00";
        ram[1924] = "0b00";
        ram[1925] = "0b00";
        ram[1926] = "0b01";
        for (unsigned i = 1927; i < 1938 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1938] = "0b11";
        for (unsigned i = 1939; i < 1950 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1950] = "0b01";
        for (unsigned i = 1951; i < 1968 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1968] = "0b01";
        ram[1969] = "0b00";
        ram[1970] = "0b01";
        for (unsigned i = 1971; i < 1977 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1977] = "0b11";
        for (unsigned i = 1978; i < 2027 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2027] = "0b01";
        ram[2028] = "0b00";
        ram[2029] = "0b00";
        ram[2030] = "0b00";
        ram[2031] = "0b00";
        ram[2032] = "0b11";
        ram[2033] = "0b00";
        ram[2034] = "0b11";
        ram[2035] = "0b00";
        ram[2036] = "0b01";
        for (unsigned i = 2037; i < 2078 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2078] = "0b01";
        ram[2079] = "0b00";
        ram[2080] = "0b11";
        ram[2081] = "0b00";
        ram[2082] = "0b00";
        ram[2083] = "0b00";
        ram[2084] = "0b01";
        ram[2085] = "0b00";
        ram[2086] = "0b00";
        ram[2087] = "0b11";
        ram[2088] = "0b00";
        ram[2089] = "0b00";
        ram[2090] = "0b00";
        ram[2091] = "0b00";
        ram[2092] = "0b11";
        for (unsigned i = 2093; i < 2099 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2099] = "0b01";
        ram[2100] = "0b00";
        ram[2101] = "0b01";
        for (unsigned i = 2102; i < 2115 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2115] = "0b01";
        for (unsigned i = 2116; i < 2124 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2124] = "0b11";
        for (unsigned i = 2125; i < 2134 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2134] = "0b11";
        for (unsigned i = 2135; i < 2152 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2152] = "0b01";
        for (unsigned i = 2153; i < 2218 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2218] = "0b11";
        ram[2219] = "0b00";
        ram[2220] = "0b01";
        for (unsigned i = 2221; i < 2232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2232] = "0b11";
        for (unsigned i = 2233; i < 2322 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2322] = "0b01";
        for (unsigned i = 2323; i < 2330 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2330] = "0b01";
        ram[2331] = "0b00";
        ram[2332] = "0b00";
        ram[2333] = "0b00";
        ram[2334] = "0b00";
        ram[2335] = "0b11";
        for (unsigned i = 2336; i < 2341 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2341] = "0b11";
        ram[2342] = "0b00";
        ram[2343] = "0b00";
        ram[2344] = "0b00";
        ram[2345] = "0b00";
        ram[2346] = "0b11";
        for (unsigned i = 2347; i < 2358 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2358] = "0b01";
        ram[2359] = "0b00";
        ram[2360] = "0b01";
        for (unsigned i = 2361; i < 2370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2370] = "0b11";
        ram[2371] = "0b00";
        ram[2372] = "0b11";
        ram[2373] = "0b00";
        ram[2374] = "0b00";
        ram[2375] = "0b11";
        ram[2376] = "0b00";
        ram[2377] = "0b01";
        ram[2378] = "0b00";
        ram[2379] = "0b11";
        for (unsigned i = 2380; i < 2428 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2428] = "0b01";
        for (unsigned i = 2429; i < 2466 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2466] = "0b01";
        for (unsigned i = 2467; i < 2484 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2484] = "0b11";
        for (unsigned i = 2485; i < 2523 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2523] = "0b11";
        for (unsigned i = 2524; i < 2536 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2536] = "0b11";
        for (unsigned i = 2537; i < 2542 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2542] = "0b11";
        for (unsigned i = 2543; i < 2640 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2640] = "0b11";
        for (unsigned i = 2641; i < 2722 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2722] = "0b11";
        for (unsigned i = 2723; i < 2729 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2729] = "0b11";
        ram[2730] = "0b00";
        ram[2731] = "0b01";
        for (unsigned i = 2732; i < 2762 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2762] = "0b01";
        ram[2763] = "0b01";
        ram[2764] = "0b00";
        ram[2765] = "0b00";
        ram[2766] = "0b00";
        ram[2767] = "0b11";
        for (unsigned i = 2768; i < 2799 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2799] = "0b11";
        for (unsigned i = 2800; i < 2813 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2813] = "0b01";
        for (unsigned i = 2814; i < 2820 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2820] = "0b11";
        ram[2821] = "0b00";
        ram[2822] = "0b00";
        ram[2823] = "0b00";
        ram[2824] = "0b01";
        ram[2825] = "0b11";
        for (unsigned i = 2826; i < 2855 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2855] = "0b11";
        ram[2856] = "0b00";
        ram[2857] = "0b11";
        for (unsigned i = 2858; i < 2865 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2865] = "0b11";
        ram[2866] = "0b01";
        for (unsigned i = 2867; i < 2904 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2904] = "0b01";
        for (unsigned i = 2905; i < 2965 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2965] = "0b11";
        ram[2966] = "0b00";
        ram[2967] = "0b01";
        ram[2968] = "0b00";
        ram[2969] = "0b00";
        ram[2970] = "0b11";
        for (unsigned i = 2971; i < 2977 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2977] = "0b01";
        ram[2978] = "0b00";
        ram[2979] = "0b00";
        ram[2980] = "0b00";
        ram[2981] = "0b01";
        for (unsigned i = 2982; i < 2999 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2999] = "0b11";
        for (unsigned i = 3000; i < 3011 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3011] = "0b01";
        for (unsigned i = 3012; i < 3060 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3060] = "0b01";
        for (unsigned i = 3061; i < 3097 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3097] = "0b01";
        for (unsigned i = 3098; i < 3107 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3107] = "0b01";
        ram[3108] = "0b00";
        ram[3109] = "0b11";
        ram[3110] = "0b00";
        ram[3111] = "0b00";
        ram[3112] = "0b00";
        ram[3113] = "0b11";
        ram[3114] = "0b00";
        ram[3115] = "0b00";
        ram[3116] = "0b00";
        ram[3117] = "0b11";
        ram[3118] = "0b00";
        ram[3119] = "0b11";
        for (unsigned i = 3120; i < 3146 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3146] = "0b01";
        ram[3147] = "0b00";
        ram[3148] = "0b01";
        ram[3149] = "0b00";
        ram[3150] = "0b00";
        ram[3151] = "0b00";
        ram[3152] = "0b00";
        ram[3153] = "0b11";
        ram[3154] = "0b00";
        ram[3155] = "0b00";
        ram[3156] = "0b00";
        ram[3157] = "0b00";
        ram[3158] = "0b01";
        ram[3159] = "0b00";
        ram[3160] = "0b01";
        for (unsigned i = 3161; i < 3181 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3181] = "0b01";
        for (unsigned i = 3182; i < 3223 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3223] = "0b11";
        for (unsigned i = 3224; i < 3291 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3291] = "0b11";
        ram[3292] = "0b00";
        ram[3293] = "0b11";
        for (unsigned i = 3294; i < 3302 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3302] = "0b11";
        for (unsigned i = 3303; i < 3321 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3321] = "0b11";
        ram[3322] = "0b11";
        ram[3323] = "0b00";
        ram[3324] = "0b00";
        ram[3325] = "0b00";
        ram[3326] = "0b11";
        for (unsigned i = 3327; i < 3342 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3342] = "0b01";
        ram[3343] = "0b11";
        for (unsigned i = 3344; i < 3354 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3354] = "0b11";
        for (unsigned i = 3355; i < 3361 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3361] = "0b01";
        for (unsigned i = 3362; i < 3391 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3391] = "0b01";
        ram[3392] = "0b00";
        ram[3393] = "0b00";
        ram[3394] = "0b01";
        for (unsigned i = 3395; i < 3401 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3401] = "0b10";
        ram[3402] = "0b00";
        ram[3403] = "0b00";
        ram[3404] = "0b11";
        for (unsigned i = 3405; i < 3415 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3415] = "0b11";
        for (unsigned i = 3416; i < 3422 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3422] = "0b11";
        for (unsigned i = 3423; i < 3442 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3442] = "0b11";
        for (unsigned i = 3443; i < 3448 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3448] = "0b01";
        ram[3449] = "0b00";
        ram[3450] = "0b10";
        ram[3451] = "0b00";
        ram[3452] = "0b00";
        ram[3453] = "0b11";
        ram[3454] = "0b00";
        ram[3455] = "0b10";
        for (unsigned i = 3456; i < 3501 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3501] = "0b11";
        for (unsigned i = 3502; i < 3571 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3571] = "0b01";
        for (unsigned i = 3572; i < 3697 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3697] = "0b11";
        for (unsigned i = 3698; i < 3704 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3704] = "0b11";
        for (unsigned i = 3705; i < 3711 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3711] = "0b01";
        ram[3712] = "0b00";
        ram[3713] = "0b00";
        ram[3714] = "0b01";
        ram[3715] = "0b00";
        ram[3716] = "0b01";
        for (unsigned i = 3717; i < 3751 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3751] = "0b01";
        for (unsigned i = 3752; i < 3758 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3758] = "0b01";
        for (unsigned i = 3759; i < 3785 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3785] = "0b11";
        ram[3786] = "0b00";
        ram[3787] = "0b00";
        ram[3788] = "0b01";
        for (unsigned i = 3789; i < 3795 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3795] = "0b11";
        for (unsigned i = 3796; i < 3804 ; i = i + 1) {
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
        ram[3852] = "0b11";
        ram[3853] = "0b00";
        ram[3854] = "0b10";
        ram[3855] = "0b00";
        ram[3856] = "0b10";
        ram[3857] = "0b00";
        ram[3858] = "0b00";
        ram[3859] = "0b01";
        ram[3860] = "0b00";
        ram[3861] = "0b01";
        for (unsigned i = 3862; i < 3891 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3891] = "0b01";
        for (unsigned i = 3892; i < 3975 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3975] = "0b11";
        for (unsigned i = 3976; i < 3992 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3992] = "0b01";
        ram[3993] = "0b00";
        ram[3994] = "0b01";
        ram[3995] = "0b00";
        ram[3996] = "0b00";
        ram[3997] = "0b00";
        ram[3998] = "0b00";
        ram[3999] = "0b11";
        ram[4000] = "0b00";
        ram[4001] = "0b11";
        ram[4002] = "0b11";
        ram[4003] = "0b11";
        for (unsigned i = 4004; i < 4040 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4040] = "0b11";
        for (unsigned i = 4041; i < 4084 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4084] = "0b11";
        ram[4085] = "0b11";
        for (unsigned i = 4086; i < 4101 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4101] = "0b11";
        for (unsigned i = 4102; i < 4199 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4199] = "0b01";
        for (unsigned i = 4200; i < 4323 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4323] = "0b11";
        for (unsigned i = 4324; i < 4337 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4337] = "0b11";
        for (unsigned i = 4338; i < 4346 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4346] = "0b11";
        for (unsigned i = 4347; i < 4376 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4376] = "0b01";
        for (unsigned i = 4377; i < 4404 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4404] = "0b01";
        for (unsigned i = 4405; i < 4469 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4469] = "0b11";
        ram[4470] = "0b11";
        ram[4471] = "0b00";
        ram[4472] = "0b00";
        ram[4473] = "0b00";
        ram[4474] = "0b00";
        ram[4475] = "0b11";
        ram[4476] = "0b11";
        ram[4477] = "0b00";
        ram[4478] = "0b01";
        ram[4479] = "0b00";
        ram[4480] = "0b00";
        ram[4481] = "0b00";
        ram[4482] = "0b00";
        ram[4483] = "0b11";
        for (unsigned i = 4484; i < 4491 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4491] = "0b01";
        ram[4492] = "0b00";
        ram[4493] = "0b01";
        for (unsigned i = 4494; i < 4502 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4502] = "0b11";
        for (unsigned i = 4503; i < 4527 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4527] = "0b01";
        ram[4528] = "0b11";
        for (unsigned i = 4529; i < 4544 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4544] = "0b01";
        for (unsigned i = 4545; i < 4572 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4572] = "0b11";
        for (unsigned i = 4573; i < 4596 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4596] = "0b11";
        for (unsigned i = 4597; i < 4618 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4618] = "0b01";
        ram[4619] = "0b00";
        ram[4620] = "0b00";
        ram[4621] = "0b01";
        for (unsigned i = 4622; i < 4670 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4670] = "0b01";
        for (unsigned i = 4671; i < 4677 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4677] = "0b11";
        for (unsigned i = 4678; i < 4686 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4686] = "0b11";
        ram[4687] = "0b11";
        for (unsigned i = 4688; i < 4735 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4735] = "0b11";
        for (unsigned i = 4736; i < 4747 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4747] = "0b01";
        for (unsigned i = 4748; i < 4777 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4777] = "0b01";
        ram[4778] = "0b00";
        ram[4779] = "0b00";
        ram[4780] = "0b00";
        ram[4781] = "0b00";
        ram[4782] = "0b01";
        for (unsigned i = 4783; i < 4812 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4812] = "0b01";
        for (unsigned i = 4813; i < 4836 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4836] = "0b11";
        for (unsigned i = 4837; i < 4874 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4874] = "0b11";
        ram[4875] = "0b00";
        ram[4876] = "0b00";
        ram[4877] = "0b00";
        ram[4878] = "0b01";
        ram[4879] = "0b00";
        ram[4880] = "0b00";
        ram[4881] = "0b00";
        ram[4882] = "0b00";
        ram[4883] = "0b01";
        ram[4884] = "0b00";
        ram[4885] = "0b11";
        ram[4886] = "0b00";
        ram[4887] = "0b00";
        ram[4888] = "0b00";
        ram[4889] = "0b00";
        ram[4890] = "0b01";
        for (unsigned i = 4891; i < 4913 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4913] = "0b11";
        ram[4914] = "0b00";
        ram[4915] = "0b00";
        ram[4916] = "0b00";
        ram[4917] = "0b00";
        ram[4918] = "0b01";
        for (unsigned i = 4919; i < 4929 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4929] = "0b01";
        for (unsigned i = 4930; i < 4964 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4964] = "0b11";
        for (unsigned i = 4965; i < 4973 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4973] = "0b01";
        for (unsigned i = 4974; i < 4986 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4986] = "0b11";
        for (unsigned i = 4987; i < 5034 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5034] = "0b01";
        for (unsigned i = 5035; i < 5055 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5055] = "0b01";
        ram[5056] = "0b00";
        ram[5057] = "0b00";
        ram[5058] = "0b00";
        ram[5059] = "0b00";
        ram[5060] = "0b11";
        ram[5061] = "0b00";
        ram[5062] = "0b00";
        ram[5063] = "0b00";
        ram[5064] = "0b01";
        for (unsigned i = 5065; i < 5085 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5085] = "0b11";
        for (unsigned i = 5086; i < 5163 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5163] = "0b11";
        ram[5164] = "0b00";
        ram[5165] = "0b00";
        ram[5166] = "0b00";
        ram[5167] = "0b11";
        for (unsigned i = 5168; i < 5307 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5307] = "0b01";
        ram[5308] = "0b00";
        ram[5309] = "0b11";
        ram[5310] = "0b00";
        ram[5311] = "0b00";
        ram[5312] = "0b11";
        ram[5313] = "0b00";
        ram[5314] = "0b01";
        for (unsigned i = 5315; i < 5321 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5321] = "0b01";
        for (unsigned i = 5322; i < 5333 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5333] = "0b01";
        ram[5334] = "0b00";
        ram[5335] = "0b11";
        for (unsigned i = 5336; i < 5351 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5351] = "0b11";
        for (unsigned i = 5352; i < 5357 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5357] = "0b11";
        ram[5358] = "0b00";
        ram[5359] = "0b00";
        ram[5360] = "0b00";
        ram[5361] = "0b11";
        for (unsigned i = 5362; i < 5368 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5368] = "0b01";
        for (unsigned i = 5369; i < 5379 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5379] = "0b11";
        for (unsigned i = 5380; i < 5403 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5403] = "0b01";
        ram[5404] = "0b00";
        ram[5405] = "0b01";
        for (unsigned i = 5406; i < 5419 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5419] = "0b11";
        ram[5420] = "0b00";
        ram[5421] = "0b00";
        ram[5422] = "0b01";
        ram[5423] = "0b11";
        for (unsigned i = 5424; i < 5429 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5429] = "0b11";
        for (unsigned i = 5430; i < 5435 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5435] = "0b01";
        for (unsigned i = 5436; i < 5449 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5449] = "0b11";
        ram[5450] = "0b00";
        ram[5451] = "0b00";
        ram[5452] = "0b00";
        ram[5453] = "0b00";
        ram[5454] = "0b11";
        for (unsigned i = 5455; i < 5461 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5461] = "0b01";
        for (unsigned i = 5462; i < 5480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5480] = "0b11";
        for (unsigned i = 5481; i < 5501 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5501] = "0b11";
        ram[5502] = "0b00";
        ram[5503] = "0b11";
        ram[5504] = "0b01";
        ram[5505] = "0b00";
        ram[5506] = "0b00";
        ram[5507] = "0b00";
        ram[5508] = "0b01";
        ram[5509] = "0b00";
        ram[5510] = "0b00";
        ram[5511] = "0b00";
        ram[5512] = "0b00";
        ram[5513] = "0b11";
        ram[5514] = "0b00";
        ram[5515] = "0b00";
        ram[5516] = "0b00";
        ram[5517] = "0b11";
        for (unsigned i = 5518; i < 5552 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5552] = "0b11";
        ram[5553] = "0b00";
        ram[5554] = "0b01";
        ram[5555] = "0b00";
        ram[5556] = "0b11";
        ram[5557] = "0b11";
        ram[5558] = "0b00";
        ram[5559] = "0b01";
        for (unsigned i = 5560; i < 5582 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5582] = "0b11";
        for (unsigned i = 5583; i < 5646 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5646] = "0b11";
        ram[5647] = "0b00";
        ram[5648] = "0b01";
        ram[5649] = "0b00";
        ram[5650] = "0b00";
        ram[5651] = "0b00";
        ram[5652] = "0b00";
        ram[5653] = "0b11";
        ram[5654] = "0b01";
        ram[5655] = "0b01";
        for (unsigned i = 5656; i < 5661 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5661] = "0b01";
        for (unsigned i = 5662; i < 5692 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5692] = "0b11";
        for (unsigned i = 5693; i < 5716 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5716] = "0b11";
        for (unsigned i = 5717; i < 5723 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5723] = "0b11";
        for (unsigned i = 5724; i < 5804 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5804] = "0b11";
        for (unsigned i = 5805; i < 5818 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5818] = "0b01";
        ram[5819] = "0b00";
        ram[5820] = "0b01";
        ram[5821] = "0b01";
        ram[5822] = "0b00";
        ram[5823] = "0b01";
        for (unsigned i = 5824; i < 5839 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5839] = "0b01";
        for (unsigned i = 5840; i < 5846 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5846] = "0b11";
        ram[5847] = "0b00";
        ram[5848] = "0b01";
        ram[5849] = "0b00";
        ram[5850] = "0b11";
        ram[5851] = "0b00";
        ram[5852] = "0b00";
        ram[5853] = "0b00";
        ram[5854] = "0b01";
        for (unsigned i = 5855; i < 5988 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5988] = "0b11";
        for (unsigned i = 5989; i < 5994 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5994] = "0b01";
        ram[5995] = "0b11";
        for (unsigned i = 5996; i < 6045 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6045] = "0b11";
        ram[6046] = "0b00";
        ram[6047] = "0b11";
        ram[6048] = "0b00";
        ram[6049] = "0b00";
        ram[6050] = "0b11";
        ram[6051] = "0b11";
        ram[6052] = "0b00";
        ram[6053] = "0b00";
        ram[6054] = "0b00";
        ram[6055] = "0b00";
        ram[6056] = "0b01";
        ram[6057] = "0b00";
        ram[6058] = "0b00";
        ram[6059] = "0b01";
        for (unsigned i = 6060; i < 6066 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6066] = "0b11";
        for (unsigned i = 6067; i < 6099 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6099] = "0b11";
        ram[6100] = "0b00";
        ram[6101] = "0b00";
        ram[6102] = "0b01";
        ram[6103] = "0b01";
        ram[6104] = "0b00";
        ram[6105] = "0b01";
        for (unsigned i = 6106; i < 6117 ; i = i + 1) {
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
        for (unsigned i = 6141; i < 6161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6161] = "0b01";
        ram[6162] = "0b00";
        ram[6163] = "0b01";
        ram[6164] = "0b00";
        ram[6165] = "0b00";
        ram[6166] = "0b00";
        ram[6167] = "0b00";
        ram[6168] = "0b11";
        for (unsigned i = 6169; i < 6239 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6239] = "0b01";
        for (unsigned i = 6240; i < 6248 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6248] = "0b01";
        ram[6249] = "0b00";
        ram[6250] = "0b11";
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_0) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_0_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_0) {
meminst = new mlp_accel_4b_weights_l1_4b_0_ram("mlp_accel_4b_weights_l1_4b_0_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_0() {
    delete meminst;
}


};//endmodule
#endif
