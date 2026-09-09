// ==============================================================
// File generated on Wed Sep 02 16:33:43 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_2_H__
#define __mlp_accel_4b_weights_l1_4b_2_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_2_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_2_ram) {
        for (unsigned i = 0; i < 71 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[71] = "0b11";
        for (unsigned i = 72; i < 80 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[80] = "0b01";
        for (unsigned i = 81; i < 118 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[118] = "0b11";
        ram[119] = "0b00";
        ram[120] = "0b00";
        ram[121] = "0b00";
        ram[122] = "0b11";
        for (unsigned i = 123; i < 128 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[128] = "0b01";
        for (unsigned i = 129; i < 134 ; i = i + 1) {
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
        for (unsigned i = 161; i < 170 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[170] = "0b11";
        ram[171] = "0b11";
        for (unsigned i = 172; i < 179 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[179] = "0b11";
        ram[180] = "0b00";
        ram[181] = "0b01";
        for (unsigned i = 182; i < 190 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[190] = "0b01";
        ram[191] = "0b11";
        for (unsigned i = 192; i < 307 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[307] = "0b11";
        ram[308] = "0b00";
        ram[309] = "0b00";
        ram[310] = "0b00";
        ram[311] = "0b00";
        ram[312] = "0b01";
        for (unsigned i = 313; i < 321 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[321] = "0b11";
        for (unsigned i = 322; i < 333 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[333] = "0b11";
        for (unsigned i = 334; i < 370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[370] = "0b01";
        for (unsigned i = 371; i < 398 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[398] = "0b01";
        for (unsigned i = 399; i < 456 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[456] = "0b11";
        for (unsigned i = 457; i < 482 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[482] = "0b01";
        for (unsigned i = 483; i < 496 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[496] = "0b11";
        ram[497] = "0b00";
        ram[498] = "0b01";
        for (unsigned i = 499; i < 508 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[508] = "0b11";
        ram[509] = "0b00";
        ram[510] = "0b00";
        ram[511] = "0b00";
        ram[512] = "0b00";
        ram[513] = "0b10";
        ram[514] = "0b00";
        ram[515] = "0b01";
        for (unsigned i = 516; i < 556 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[556] = "0b11";
        for (unsigned i = 557; i < 601 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[601] = "0b11";
        ram[602] = "0b00";
        ram[603] = "0b00";
        ram[604] = "0b00";
        ram[605] = "0b11";
        for (unsigned i = 606; i < 622 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[622] = "0b01";
        ram[623] = "0b00";
        ram[624] = "0b00";
        ram[625] = "0b11";
        for (unsigned i = 626; i < 643 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[643] = "0b01";
        for (unsigned i = 644; i < 655 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[655] = "0b11";
        ram[656] = "0b00";
        ram[657] = "0b11";
        for (unsigned i = 658; i < 683 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[683] = "0b01";
        for (unsigned i = 684; i < 699 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[699] = "0b11";
        ram[700] = "0b00";
        ram[701] = "0b00";
        ram[702] = "0b00";
        ram[703] = "0b11";
        for (unsigned i = 704; i < 727 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[727] = "0b11";
        for (unsigned i = 728; i < 748 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[748] = "0b11";
        for (unsigned i = 749; i < 804 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[804] = "0b01";
        ram[805] = "0b00";
        ram[806] = "0b00";
        ram[807] = "0b11";
        ram[808] = "0b00";
        ram[809] = "0b11";
        for (unsigned i = 810; i < 843 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[843] = "0b11";
        for (unsigned i = 844; i < 853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[853] = "0b01";
        for (unsigned i = 854; i < 869 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[869] = "0b11";
        ram[870] = "0b00";
        ram[871] = "0b11";
        for (unsigned i = 872; i < 909 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[909] = "0b01";
        for (unsigned i = 910; i < 947 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[947] = "0b11";
        ram[948] = "0b00";
        ram[949] = "0b11";
        for (unsigned i = 950; i < 956 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[956] = "0b01";
        for (unsigned i = 957; i < 965 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[965] = "0b01";
        ram[966] = "0b00";
        ram[967] = "0b00";
        ram[968] = "0b00";
        ram[969] = "0b01";
        for (unsigned i = 970; i < 991 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[991] = "0b11";
        ram[992] = "0b00";
        ram[993] = "0b00";
        ram[994] = "0b00";
        ram[995] = "0b11";
        for (unsigned i = 996; i < 1010 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1010] = "0b11";
        for (unsigned i = 1011; i < 1049 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1049] = "0b01";
        for (unsigned i = 1050; i < 1056 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1056] = "0b01";
        ram[1057] = "0b00";
        ram[1058] = "0b11";
        ram[1059] = "0b11";
        for (unsigned i = 1060; i < 1098 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1098] = "0b01";
        for (unsigned i = 1099; i < 1142 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1142] = "0b01";
        ram[1143] = "0b00";
        ram[1144] = "0b00";
        ram[1145] = "0b00";
        ram[1146] = "0b00";
        ram[1147] = "0b11";
        for (unsigned i = 1148; i < 1196 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1196] = "0b01";
        ram[1197] = "0b00";
        ram[1198] = "0b00";
        ram[1199] = "0b11";
        ram[1200] = "0b11";
        for (unsigned i = 1201; i < 1207 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1207] = "0b11";
        for (unsigned i = 1208; i < 1219 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1219] = "0b11";
        for (unsigned i = 1220; i < 1301 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1301] = "0b01";
        for (unsigned i = 1302; i < 1378 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1378] = "0b11";
        for (unsigned i = 1379; i < 1392 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1392] = "0b11";
        ram[1393] = "0b00";
        ram[1394] = "0b00";
        ram[1395] = "0b00";
        ram[1396] = "0b00";
        ram[1397] = "0b11";
        ram[1398] = "0b00";
        ram[1399] = "0b00";
        ram[1400] = "0b00";
        ram[1401] = "0b00";
        ram[1402] = "0b11";
        for (unsigned i = 1403; i < 1432 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1432] = "0b11";
        for (unsigned i = 1433; i < 1438 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1438] = "0b11";
        for (unsigned i = 1439; i < 1448 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1448] = "0b11";
        for (unsigned i = 1449; i < 1459 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1459] = "0b01";
        ram[1460] = "0b00";
        ram[1461] = "0b00";
        ram[1462] = "0b11";
        for (unsigned i = 1463; i < 1481 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1481] = "0b11";
        for (unsigned i = 1482; i < 1556 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1556] = "0b11";
        for (unsigned i = 1557; i < 1590 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1590] = "0b01";
        ram[1591] = "0b00";
        ram[1592] = "0b00";
        ram[1593] = "0b00";
        ram[1594] = "0b00";
        ram[1595] = "0b01";
        for (unsigned i = 1596; i < 1626 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1626] = "0b01";
        for (unsigned i = 1627; i < 1635 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1635] = "0b01";
        for (unsigned i = 1636; i < 1775 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1775] = "0b11";
        for (unsigned i = 1776; i < 1781 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1781] = "0b11";
        for (unsigned i = 1782; i < 1824 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1824] = "0b01";
        ram[1825] = "0b00";
        ram[1826] = "0b01";
        ram[1827] = "0b00";
        ram[1828] = "0b11";
        ram[1829] = "0b00";
        ram[1830] = "0b11";
        ram[1831] = "0b00";
        ram[1832] = "0b00";
        ram[1833] = "0b11";
        for (unsigned i = 1834; i < 1856 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1856] = "0b01";
        for (unsigned i = 1857; i < 1905 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1905] = "0b01";
        for (unsigned i = 1906; i < 1919 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1919] = "0b01";
        for (unsigned i = 1920; i < 1931 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1931] = "0b11";
        for (unsigned i = 1932; i < 1938 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1938] = "0b11";
        ram[1939] = "0b00";
        ram[1940] = "0b11";
        ram[1941] = "0b11";
        for (unsigned i = 1942; i < 1950 ; i = i + 1) {
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
        ram[1978] = "0b00";
        ram[1979] = "0b00";
        ram[1980] = "0b01";
        for (unsigned i = 1981; i < 1987 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1987] = "0b01";
        for (unsigned i = 1988; i < 2025 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2025] = "0b01";
        ram[2026] = "0b00";
        ram[2027] = "0b00";
        ram[2028] = "0b00";
        ram[2029] = "0b01";
        ram[2030] = "0b00";
        ram[2031] = "0b00";
        ram[2032] = "0b11";
        ram[2033] = "0b00";
        ram[2034] = "0b11";
        ram[2035] = "0b00";
        ram[2036] = "0b00";
        ram[2037] = "0b00";
        ram[2038] = "0b01";
        ram[2039] = "0b01";
        for (unsigned i = 2040; i < 2075 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2075] = "0b01";
        for (unsigned i = 2076; i < 2090 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2090] = "0b11";
        ram[2091] = "0b00";
        ram[2092] = "0b11";
        for (unsigned i = 2093; i < 2113 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2113] = "0b01";
        ram[2114] = "0b00";
        ram[2115] = "0b01";
        ram[2116] = "0b00";
        ram[2117] = "0b01";
        for (unsigned i = 2118; i < 2124 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2124] = "0b11";
        ram[2125] = "0b01";
        for (unsigned i = 2126; i < 2148 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2148] = "0b01";
        for (unsigned i = 2149; i < 2216 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2216] = "0b11";
        ram[2217] = "0b00";
        ram[2218] = "0b00";
        ram[2219] = "0b00";
        ram[2220] = "0b00";
        ram[2221] = "0b01";
        for (unsigned i = 2222; i < 2230 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2230] = "0b11";
        for (unsigned i = 2231; i < 2236 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2236] = "0b01";
        for (unsigned i = 2237; i < 2314 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2314] = "0b01";
        for (unsigned i = 2315; i < 2320 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2320] = "0b01";
        for (unsigned i = 2321; i < 2328 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2328] = "0b01";
        ram[2329] = "0b00";
        ram[2330] = "0b00";
        ram[2331] = "0b00";
        ram[2332] = "0b11";
        ram[2333] = "0b11";
        ram[2334] = "0b00";
        ram[2335] = "0b11";
        for (unsigned i = 2336; i < 2358 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2358] = "0b01";
        ram[2359] = "0b00";
        ram[2360] = "0b01";
        ram[2361] = "0b00";
        ram[2362] = "0b00";
        ram[2363] = "0b01";
        ram[2364] = "0b00";
        ram[2365] = "0b01";
        ram[2366] = "0b00";
        ram[2367] = "0b00";
        ram[2368] = "0b00";
        ram[2369] = "0b00";
        ram[2370] = "0b10";
        ram[2371] = "0b00";
        ram[2372] = "0b00";
        ram[2373] = "0b00";
        ram[2374] = "0b00";
        ram[2375] = "0b11";
        for (unsigned i = 2376; i < 2424 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2424] = "0b11";
        ram[2425] = "0b00";
        ram[2426] = "0b01";
        for (unsigned i = 2427; i < 2435 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2435] = "0b11";
        ram[2436] = "0b00";
        ram[2437] = "0b00";
        ram[2438] = "0b00";
        ram[2439] = "0b11";
        for (unsigned i = 2440; i < 2475 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2475] = "0b01";
        for (unsigned i = 2476; i < 2482 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2482] = "0b11";
        ram[2483] = "0b00";
        ram[2484] = "0b00";
        ram[2485] = "0b00";
        ram[2486] = "0b00";
        ram[2487] = "0b11";
        ram[2488] = "0b11";
        for (unsigned i = 2489; i < 2505 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2505] = "0b11";
        ram[2506] = "0b00";
        ram[2507] = "0b00";
        ram[2508] = "0b00";
        ram[2509] = "0b00";
        ram[2510] = "0b11";
        ram[2511] = "0b00";
        ram[2512] = "0b00";
        ram[2513] = "0b00";
        ram[2514] = "0b01";
        for (unsigned i = 2515; i < 2521 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2521] = "0b11";
        ram[2522] = "0b00";
        ram[2523] = "0b11";
        ram[2524] = "0b00";
        ram[2525] = "0b00";
        ram[2526] = "0b01";
        ram[2527] = "0b00";
        ram[2528] = "0b00";
        ram[2529] = "0b01";
        for (unsigned i = 2530; i < 2535 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2535] = "0b11";
        for (unsigned i = 2536; i < 2542 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2542] = "0b11";
        ram[2543] = "0b11";
        for (unsigned i = 2544; i < 2572 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2572] = "0b11";
        for (unsigned i = 2573; i < 2612 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2612] = "0b01";
        ram[2613] = "0b00";
        ram[2614] = "0b00";
        ram[2615] = "0b11";
        ram[2616] = "0b00";
        ram[2617] = "0b01";
        for (unsigned i = 2618; i < 2769 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2769] = "0b01";
        ram[2770] = "0b00";
        ram[2771] = "0b00";
        ram[2772] = "0b00";
        ram[2773] = "0b11";
        for (unsigned i = 2774; i < 2799 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2799] = "0b11";
        for (unsigned i = 2800; i < 2823 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2823] = "0b11";
        ram[2824] = "0b00";
        ram[2825] = "0b11";
        for (unsigned i = 2826; i < 2855 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2855] = "0b11";
        ram[2856] = "0b00";
        ram[2857] = "0b11";
        for (unsigned i = 2858; i < 2866 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2866] = "0b01";
        ram[2867] = "0b00";
        ram[2868] = "0b00";
        ram[2869] = "0b01";
        for (unsigned i = 2870; i < 2885 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2885] = "0b11";
        for (unsigned i = 2886; i < 2904 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2904] = "0b01";
        for (unsigned i = 2905; i < 2946 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2946] = "0b11";
        for (unsigned i = 2947; i < 2965 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2965] = "0b11";
        ram[2966] = "0b00";
        ram[2967] = "0b00";
        ram[2968] = "0b00";
        ram[2969] = "0b00";
        ram[2970] = "0b11";
        ram[2971] = "0b00";
        ram[2972] = "0b01";
        for (unsigned i = 2973; i < 3009 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3009] = "0b11";
        for (unsigned i = 3010; i < 3016 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3016] = "0b01";
        ram[3017] = "0b00";
        ram[3018] = "0b00";
        ram[3019] = "0b00";
        ram[3020] = "0b11";
        ram[3021] = "0b00";
        ram[3022] = "0b00";
        ram[3023] = "0b00";
        ram[3024] = "0b00";
        ram[3025] = "0b11";
        for (unsigned i = 3026; i < 3032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3032] = "0b11";
        for (unsigned i = 3033; i < 3093 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3093] = "0b11";
        ram[3094] = "0b00";
        ram[3095] = "0b01";
        ram[3096] = "0b00";
        ram[3097] = "0b01";
        ram[3098] = "0b00";
        ram[3099] = "0b00";
        ram[3100] = "0b11";
        ram[3101] = "0b00";
        ram[3102] = "0b00";
        ram[3103] = "0b00";
        ram[3104] = "0b00";
        ram[3105] = "0b01";
        ram[3106] = "0b00";
        ram[3107] = "0b11";
        ram[3108] = "0b00";
        ram[3109] = "0b00";
        ram[3110] = "0b00";
        ram[3111] = "0b11";
        for (unsigned i = 3112; i < 3117 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3117] = "0b11";
        for (unsigned i = 3118; i < 3133 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3133] = "0b11";
        for (unsigned i = 3134; i < 3144 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3144] = "0b01";
        ram[3145] = "0b00";
        ram[3146] = "0b01";
        ram[3147] = "0b00";
        ram[3148] = "0b00";
        ram[3149] = "0b01";
        ram[3150] = "0b00";
        ram[3151] = "0b11";
        ram[3152] = "0b00";
        ram[3153] = "0b11";
        ram[3154] = "0b00";
        ram[3155] = "0b00";
        ram[3156] = "0b00";
        ram[3157] = "0b00";
        ram[3158] = "0b01";
        ram[3159] = "0b00";
        ram[3160] = "0b11";
        for (unsigned i = 3161; i < 3181 ; i = i + 1) {
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
        for (unsigned i = 3294; i < 3305 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3305] = "0b01";
        for (unsigned i = 3306; i < 3314 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3314] = "0b01";
        ram[3315] = "0b00";
        ram[3316] = "0b00";
        ram[3317] = "0b01";
        ram[3318] = "0b00";
        ram[3319] = "0b00";
        ram[3320] = "0b11";
        for (unsigned i = 3321; i < 3352 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3352] = "0b11";
        ram[3353] = "0b00";
        ram[3354] = "0b00";
        ram[3355] = "0b00";
        ram[3356] = "0b00";
        ram[3357] = "0b01";
        ram[3358] = "0b00";
        ram[3359] = "0b01";
        for (unsigned i = 3360; i < 3370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3370] = "0b01";
        for (unsigned i = 3371; i < 3392 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3392] = "0b01";
        ram[3393] = "0b00";
        ram[3394] = "0b01";
        ram[3395] = "0b00";
        ram[3396] = "0b00";
        ram[3397] = "0b00";
        ram[3398] = "0b01";
        ram[3399] = "0b00";
        ram[3400] = "0b00";
        ram[3401] = "0b11";
        ram[3402] = "0b00";
        ram[3403] = "0b00";
        ram[3404] = "0b11";
        for (unsigned i = 3405; i < 3412 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3412] = "0b11";
        for (unsigned i = 3413; i < 3441 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3441] = "0b01";
        for (unsigned i = 3442; i < 3450 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3450] = "0b11";
        ram[3451] = "0b00";
        ram[3452] = "0b00";
        ram[3453] = "0b11";
        ram[3454] = "0b00";
        ram[3455] = "0b11";
        ram[3456] = "0b00";
        ram[3457] = "0b00";
        ram[3458] = "0b00";
        ram[3459] = "0b00";
        ram[3460] = "0b11";
        for (unsigned i = 3461; i < 3595 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3595] = "0b01";
        for (unsigned i = 3596; i < 3602 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3602] = "0b01";
        for (unsigned i = 3603; i < 3695 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3695] = "0b11";
        for (unsigned i = 3696; i < 3707 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3707] = "0b11";
        for (unsigned i = 3708; i < 3716 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3716] = "0b01";
        for (unsigned i = 3717; i < 3788 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3788] = "0b01";
        for (unsigned i = 3789; i < 3802 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3802] = "0b11";
        for (unsigned i = 3803; i < 3847 ; i = i + 1) {
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
        ram[3858] = "0b00";
        ram[3859] = "0b00";
        ram[3860] = "0b00";
        ram[3861] = "0b01";
        for (unsigned i = 3862; i < 3891 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3891] = "0b11";
        ram[3892] = "0b00";
        ram[3893] = "0b01";
        ram[3894] = "0b11";
        ram[3895] = "0b00";
        ram[3896] = "0b01";
        ram[3897] = "0b00";
        ram[3898] = "0b11";
        ram[3899] = "0b00";
        ram[3900] = "0b01";
        for (unsigned i = 3901; i < 3933 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3933] = "0b01";
        for (unsigned i = 3934; i < 3994 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3994] = "0b01";
        for (unsigned i = 3995; i < 4006 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4006] = "0b11";
        for (unsigned i = 4007; i < 4029 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4029] = "0b11";
        for (unsigned i = 4030; i < 4054 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4054] = "0b11";
        for (unsigned i = 4055; i < 4085 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4085] = "0b11";
        ram[4086] = "0b00";
        ram[4087] = "0b00";
        ram[4088] = "0b00";
        ram[4089] = "0b11";
        for (unsigned i = 4090; i < 4099 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4099] = "0b11";
        for (unsigned i = 4100; i < 4150 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4150] = "0b11";
        for (unsigned i = 4151; i < 4183 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4183] = "0b11";
        for (unsigned i = 4184; i < 4234 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4234] = "0b01";
        for (unsigned i = 4235; i < 4250 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4250] = "0b01";
        for (unsigned i = 4251; i < 4329 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4329] = "0b01";
        for (unsigned i = 4330; i < 4335 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4335] = "0b11";
        ram[4336] = "0b00";
        ram[4337] = "0b11";
        for (unsigned i = 4338; i < 4344 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4344] = "0b11";
        ram[4345] = "0b00";
        ram[4346] = "0b00";
        ram[4347] = "0b00";
        ram[4348] = "0b01";
        ram[4349] = "0b00";
        ram[4350] = "0b11";
        ram[4351] = "0b00";
        ram[4352] = "0b00";
        ram[4353] = "0b00";
        ram[4354] = "0b00";
        ram[4355] = "0b11";
        for (unsigned i = 4356; i < 4430 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4430] = "0b01";
        for (unsigned i = 4431; i < 4453 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4453] = "0b11";
        for (unsigned i = 4454; i < 4470 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4470] = "0b11";
        for (unsigned i = 4471; i < 4482 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4482] = "0b11";
        for (unsigned i = 4483; i < 4488 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4488] = "0b11";
        ram[4489] = "0b00";
        ram[4490] = "0b00";
        ram[4491] = "0b01";
        ram[4492] = "0b00";
        ram[4493] = "0b00";
        ram[4494] = "0b00";
        ram[4495] = "0b01";
        for (unsigned i = 4496; i < 4519 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4519] = "0b11";
        for (unsigned i = 4520; i < 4525 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4525] = "0b01";
        for (unsigned i = 4526; i < 4563 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4563] = "0b01";
        ram[4564] = "0b00";
        ram[4565] = "0b00";
        ram[4566] = "0b00";
        ram[4567] = "0b00";
        ram[4568] = "0b11";
        for (unsigned i = 4569; i < 4586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4586] = "0b01";
        for (unsigned i = 4587; i < 4615 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4615] = "0b11";
        for (unsigned i = 4616; i < 4621 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4621] = "0b01";
        for (unsigned i = 4622; i < 4628 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4628] = "0b11";
        ram[4629] = "0b00";
        ram[4630] = "0b11";
        for (unsigned i = 4631; i < 4684 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4684] = "0b11";
        ram[4685] = "0b00";
        ram[4686] = "0b00";
        ram[4687] = "0b11";
        for (unsigned i = 4688; i < 4733 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4733] = "0b11";
        ram[4734] = "0b00";
        ram[4735] = "0b00";
        ram[4736] = "0b01";
        for (unsigned i = 4737; i < 4745 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4745] = "0b01";
        for (unsigned i = 4746; i < 4829 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4829] = "0b01";
        for (unsigned i = 4830; i < 4838 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4838] = "0b01";
        for (unsigned i = 4839; i < 4857 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4857] = "0b01";
        ram[4858] = "0b00";
        ram[4859] = "0b00";
        ram[4860] = "0b11";
        for (unsigned i = 4861; i < 4873 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4873] = "0b11";
        for (unsigned i = 4874; i < 4883 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4883] = "0b01";
        ram[4884] = "0b00";
        ram[4885] = "0b00";
        ram[4886] = "0b00";
        ram[4887] = "0b00";
        ram[4888] = "0b01";
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
        for (unsigned i = 4919; i < 4934 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4934] = "0b01";
        for (unsigned i = 4935; i < 4972 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4972] = "0b11";
        for (unsigned i = 4973; i < 5058 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5058] = "0b11";
        ram[5059] = "0b00";
        ram[5060] = "0b11";
        ram[5061] = "0b00";
        ram[5062] = "0b00";
        ram[5063] = "0b00";
        ram[5064] = "0b01";
        ram[5065] = "0b00";
        ram[5066] = "0b00";
        ram[5067] = "0b01";
        for (unsigned i = 5068; i < 5083 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5083] = "0b11";
        for (unsigned i = 5084; i < 5123 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5123] = "0b01";
        for (unsigned i = 5124; i < 5151 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5151] = "0b01";
        for (unsigned i = 5152; i < 5161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5161] = "0b11";
        ram[5162] = "0b00";
        ram[5163] = "0b11";
        ram[5164] = "0b00";
        ram[5165] = "0b01";
        for (unsigned i = 5166; i < 5172 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5172] = "0b11";
        for (unsigned i = 5173; i < 5211 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5211] = "0b01";
        ram[5212] = "0b11";
        ram[5213] = "0b00";
        ram[5214] = "0b01";
        for (unsigned i = 5215; i < 5226 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5226] = "0b11";
        ram[5227] = "0b00";
        ram[5228] = "0b01";
        for (unsigned i = 5229; i < 5298 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5298] = "0b11";
        ram[5299] = "0b00";
        ram[5300] = "0b11";
        ram[5301] = "0b00";
        ram[5302] = "0b01";
        for (unsigned i = 5303; i < 5310 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5310] = "0b01";
        for (unsigned i = 5311; i < 5326 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5326] = "0b11";
        ram[5327] = "0b00";
        ram[5328] = "0b11";
        for (unsigned i = 5329; i < 5361 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5361] = "0b01";
        ram[5362] = "0b00";
        ram[5363] = "0b00";
        ram[5364] = "0b11";
        for (unsigned i = 5365; i < 5403 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5403] = "0b01";
        for (unsigned i = 5404; i < 5412 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5412] = "0b01";
        ram[5413] = "0b00";
        ram[5414] = "0b11";
        for (unsigned i = 5415; i < 5420 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5420] = "0b01";
        ram[5421] = "0b00";
        ram[5422] = "0b01";
        for (unsigned i = 5423; i < 5429 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5429] = "0b11";
        for (unsigned i = 5430; i < 5436 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5436] = "0b01";
        for (unsigned i = 5437; i < 5445 ; i = i + 1) {
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
        for (unsigned i = 5455; i < 5480 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5480] = "0b11";
        for (unsigned i = 5481; i < 5499 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5499] = "0b11";
        ram[5500] = "0b00";
        ram[5501] = "0b11";
        ram[5502] = "0b00";
        ram[5503] = "0b00";
        ram[5504] = "0b00";
        ram[5505] = "0b00";
        ram[5506] = "0b01";
        ram[5507] = "0b00";
        ram[5508] = "0b01";
        ram[5509] = "0b00";
        ram[5510] = "0b00";
        ram[5511] = "0b00";
        ram[5512] = "0b00";
        ram[5513] = "0b11";
        for (unsigned i = 5514; i < 5557 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5557] = "0b11";
        ram[5558] = "0b00";
        ram[5559] = "0b01";
        ram[5560] = "0b00";
        ram[5561] = "0b00";
        ram[5562] = "0b00";
        ram[5563] = "0b00";
        ram[5564] = "0b01";
        ram[5565] = "0b00";
        ram[5566] = "0b00";
        ram[5567] = "0b11";
        for (unsigned i = 5568; i < 5651 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5651] = "0b11";
        ram[5652] = "0b00";
        ram[5653] = "0b00";
        ram[5654] = "0b00";
        ram[5655] = "0b11";
        for (unsigned i = 5656; i < 5678 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5678] = "0b11";
        for (unsigned i = 5679; i < 5692 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5692] = "0b11";
        for (unsigned i = 5693; i < 5708 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5708] = "0b01";
        for (unsigned i = 5709; i < 5716 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5716] = "0b11";
        ram[5717] = "0b00";
        ram[5718] = "0b00";
        ram[5719] = "0b00";
        ram[5720] = "0b11";
        for (unsigned i = 5721; i < 5760 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5760] = "0b01";
        for (unsigned i = 5761; i < 5793 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5793] = "0b01";
        for (unsigned i = 5794; i < 5818 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5818] = "0b01";
        ram[5819] = "0b00";
        ram[5820] = "0b01";
        ram[5821] = "0b00";
        ram[5822] = "0b00";
        ram[5823] = "0b00";
        ram[5824] = "0b00";
        ram[5825] = "0b01";
        for (unsigned i = 5826; i < 5837 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5837] = "0b01";
        ram[5838] = "0b00";
        ram[5839] = "0b01";
        ram[5840] = "0b00";
        ram[5841] = "0b00";
        ram[5842] = "0b00";
        ram[5843] = "0b00";
        ram[5844] = "0b11";
        ram[5845] = "0b00";
        ram[5846] = "0b01";
        ram[5847] = "0b00";
        ram[5848] = "0b01";
        ram[5849] = "0b00";
        ram[5850] = "0b00";
        ram[5851] = "0b11";
        for (unsigned i = 5852; i < 5860 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5860] = "0b01";
        for (unsigned i = 5861; i < 5874 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5874] = "0b11";
        for (unsigned i = 5875; i < 5940 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5940] = "0b11";
        ram[5941] = "0b00";
        ram[5942] = "0b00";
        ram[5943] = "0b00";
        ram[5944] = "0b00";
        ram[5945] = "0b11";
        ram[5946] = "0b11";
        for (unsigned i = 5947; i < 5956 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5956] = "0b01";
        for (unsigned i = 5957; i < 5993 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5993] = "0b11";
        ram[5994] = "0b00";
        ram[5995] = "0b00";
        ram[5996] = "0b00";
        ram[5997] = "0b00";
        ram[5998] = "0b01";
        ram[5999] = "0b00";
        ram[6000] = "0b11";
        ram[6001] = "0b11";
        ram[6002] = "0b01";
        for (unsigned i = 6003; i < 6009 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6009] = "0b01";
        ram[6010] = "0b00";
        ram[6011] = "0b00";
        ram[6012] = "0b00";
        ram[6013] = "0b00";
        ram[6014] = "0b01";
        for (unsigned i = 6015; i < 6047 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6047] = "0b11";
        ram[6048] = "0b00";
        ram[6049] = "0b11";
        ram[6050] = "0b00";
        ram[6051] = "0b11";
        for (unsigned i = 6052; i < 6057 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6057] = "0b01";
        ram[6058] = "0b00";
        ram[6059] = "0b01";
        for (unsigned i = 6060; i < 6085 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6085] = "0b01";
        ram[6086] = "0b00";
        ram[6087] = "0b11";
        ram[6088] = "0b00";
        ram[6089] = "0b00";
        ram[6090] = "0b00";
        ram[6091] = "0b00";
        ram[6092] = "0b11";
        for (unsigned i = 6093; i < 6110 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6110] = "0b01";
        for (unsigned i = 6111; i < 6117 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6117] = "0b11";
        for (unsigned i = 6118; i < 6138 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6138] = "0b01";
        ram[6139] = "0b00";
        ram[6140] = "0b11";
        ram[6141] = "0b00";
        ram[6142] = "0b00";
        ram[6143] = "0b11";
        ram[6144] = "0b00";
        ram[6145] = "0b00";
        ram[6146] = "0b00";
        ram[6147] = "0b00";
        ram[6148] = "0b01";
        ram[6149] = "0b00";
        ram[6150] = "0b00";
        ram[6151] = "0b00";
        ram[6152] = "0b01";
        ram[6153] = "0b00";
        ram[6154] = "0b00";
        ram[6155] = "0b00";
        ram[6156] = "0b00";
        ram[6157] = "0b11";
        ram[6158] = "0b00";
        ram[6159] = "0b01";
        ram[6160] = "0b00";
        ram[6161] = "0b01";
        for (unsigned i = 6162; i < 6191 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6191] = "0b11";
        for (unsigned i = 6192; i < 6203 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6203] = "0b11";
        for (unsigned i = 6204; i < 6232 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6232] = "0b01";
        for (unsigned i = 6233; i < 6266 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_2) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_2_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_2) {
meminst = new mlp_accel_4b_weights_l1_4b_2_ram("mlp_accel_4b_weights_l1_4b_2_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_2() {
    delete meminst;
}


};//endmodule
#endif
