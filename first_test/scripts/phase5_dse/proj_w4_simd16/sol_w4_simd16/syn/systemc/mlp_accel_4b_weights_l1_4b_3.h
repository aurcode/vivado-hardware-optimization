// ==============================================================
// File generated on Wed Sep 02 16:33:43 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_3_H__
#define __mlp_accel_4b_weights_l1_4b_3_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_3_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_3_ram) {
        for (unsigned i = 0; i < 73 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[73] = "0b01";
        for (unsigned i = 74; i < 114 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[114] = "0b11";
        ram[115] = "0b00";
        ram[116] = "0b00";
        ram[117] = "0b00";
        ram[118] = "0b11";
        for (unsigned i = 119; i < 132 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[132] = "0b01";
        ram[133] = "0b00";
        ram[134] = "0b00";
        ram[135] = "0b00";
        ram[136] = "0b01";
        for (unsigned i = 137; i < 156 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[156] = "0b11";
        ram[157] = "0b00";
        ram[158] = "0b11";
        ram[159] = "0b00";
        ram[160] = "0b00";
        ram[161] = "0b00";
        ram[162] = "0b11";
        ram[163] = "0b11";
        for (unsigned i = 164; i < 171 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[171] = "0b11";
        for (unsigned i = 172; i < 179 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[179] = "0b11";
        for (unsigned i = 180; i < 317 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[317] = "0b01";
        ram[318] = "0b00";
        ram[319] = "0b00";
        ram[320] = "0b00";
        ram[321] = "0b11";
        for (unsigned i = 322; i < 424 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[424] = "0b01";
        for (unsigned i = 425; i < 431 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[431] = "0b11";
        for (unsigned i = 432; i < 452 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[452] = "0b01";
        for (unsigned i = 453; i < 458 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[458] = "0b11";
        for (unsigned i = 459; i < 473 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[473] = "0b01";
        ram[474] = "0b00";
        ram[475] = "0b11";
        for (unsigned i = 476; i < 498 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[498] = "0b01";
        ram[499] = "0b00";
        ram[500] = "0b11";
        for (unsigned i = 501; i < 513 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[513] = "0b10";
        ram[514] = "0b00";
        ram[515] = "0b01";
        for (unsigned i = 516; i < 552 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[552] = "0b01";
        ram[553] = "0b00";
        ram[554] = "0b00";
        ram[555] = "0b00";
        ram[556] = "0b11";
        for (unsigned i = 557; i < 601 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[601] = "0b11";
        for (unsigned i = 602; i < 617 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[617] = "0b01";
        ram[618] = "0b01";
        for (unsigned i = 619; i < 625 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[625] = "0b11";
        for (unsigned i = 626; i < 631 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[631] = "0b11";
        for (unsigned i = 632; i < 648 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[648] = "0b01";
        ram[649] = "0b00";
        ram[650] = "0b01";
        for (unsigned i = 651; i < 659 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[659] = "0b01";
        for (unsigned i = 660; i < 668 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[668] = "0b11";
        for (unsigned i = 669; i < 703 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[703] = "0b11";
        for (unsigned i = 704; i < 729 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[729] = "0b11";
        for (unsigned i = 730; i < 793 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[793] = "0b01";
        for (unsigned i = 794; i < 804 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[804] = "0b01";
        for (unsigned i = 805; i < 843 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[843] = "0b11";
        ram[844] = "0b00";
        ram[845] = "0b00";
        ram[846] = "0b11";
        ram[847] = "0b00";
        ram[848] = "0b00";
        ram[849] = "0b00";
        ram[850] = "0b00";
        ram[851] = "0b11";
        ram[852] = "0b00";
        ram[853] = "0b01";
        ram[854] = "0b00";
        ram[855] = "0b00";
        ram[856] = "0b00";
        ram[857] = "0b01";
        for (unsigned i = 858; i < 863 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[863] = "0b11";
        for (unsigned i = 864; i < 871 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[871] = "0b11";
        for (unsigned i = 872; i < 947 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[947] = "0b11";
        for (unsigned i = 948; i < 954 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[954] = "0b01";
        for (unsigned i = 955; i < 965 ; i = i + 1) {
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
        ram[993] = "0b01";
        for (unsigned i = 994; i < 1017 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1017] = "0b11";
        for (unsigned i = 1018; i < 1056 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1056] = "0b01";
        for (unsigned i = 1057; i < 1114 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1114] = "0b11";
        for (unsigned i = 1115; i < 1199 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1199] = "0b11";
        ram[1200] = "0b11";
        for (unsigned i = 1201; i < 1211 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1211] = "0b11";
        ram[1212] = "0b11";
        for (unsigned i = 1213; i < 1219 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1219] = "0b11";
        for (unsigned i = 1220; i < 1301 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1301] = "0b01";
        for (unsigned i = 1302; i < 1397 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1397] = "0b11";
        ram[1398] = "0b00";
        ram[1399] = "0b00";
        ram[1400] = "0b00";
        ram[1401] = "0b00";
        ram[1402] = "0b11";
        ram[1403] = "0b00";
        ram[1404] = "0b01";
        ram[1405] = "0b00";
        ram[1406] = "0b00";
        ram[1407] = "0b00";
        ram[1408] = "0b00";
        ram[1409] = "0b11";
        for (unsigned i = 1410; i < 1432 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1432] = "0b11";
        for (unsigned i = 1433; i < 1441 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1441] = "0b11";
        for (unsigned i = 1442; i < 1455 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1455] = "0b01";
        for (unsigned i = 1456; i < 1481 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1481] = "0b11";
        for (unsigned i = 1482; i < 1490 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1490] = "0b01";
        for (unsigned i = 1491; i < 1497 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1497] = "0b11";
        for (unsigned i = 1498; i < 1525 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1525] = "0b11";
        for (unsigned i = 1526; i < 1539 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1539] = "0b01";
        ram[1540] = "0b00";
        ram[1541] = "0b00";
        ram[1542] = "0b00";
        ram[1543] = "0b11";
        ram[1544] = "0b00";
        ram[1545] = "0b00";
        ram[1546] = "0b01";
        for (unsigned i = 1547; i < 1555 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1555] = "0b11";
        ram[1556] = "0b11";
        for (unsigned i = 1557; i < 1588 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1588] = "0b11";
        for (unsigned i = 1589; i < 1599 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1599] = "0b11";
        for (unsigned i = 1600; i < 1626 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1626] = "0b01";
        for (unsigned i = 1627; i < 1635 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1635] = "0b01";
        for (unsigned i = 1636; i < 1641 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1641] = "0b11";
        for (unsigned i = 1642; i < 1695 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1695] = "0b01";
        for (unsigned i = 1696; i < 1709 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1709] = "0b11";
        for (unsigned i = 1710; i < 1830 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1830] = "0b11";
        ram[1831] = "0b00";
        ram[1832] = "0b00";
        ram[1833] = "0b11";
        for (unsigned i = 1834; i < 1856 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1856] = "0b01";
        for (unsigned i = 1857; i < 1919 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1919] = "0b01";
        for (unsigned i = 1920; i < 1931 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1931] = "0b11";
        ram[1932] = "0b00";
        ram[1933] = "0b11";
        ram[1934] = "0b00";
        ram[1935] = "0b00";
        ram[1936] = "0b11";
        ram[1937] = "0b00";
        ram[1938] = "0b00";
        ram[1939] = "0b00";
        ram[1940] = "0b11";
        for (unsigned i = 1941; i < 1947 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1947] = "0b01";
        for (unsigned i = 1948; i < 1966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1966] = "0b01";
        ram[1967] = "0b00";
        ram[1968] = "0b01";
        for (unsigned i = 1969; i < 1977 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1977] = "0b11";
        ram[1978] = "0b00";
        ram[1979] = "0b00";
        ram[1980] = "0b00";
        ram[1981] = "0b00";
        ram[1982] = "0b11";
        for (unsigned i = 1983; i < 2025 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2025] = "0b01";
        ram[2026] = "0b00";
        ram[2027] = "0b01";
        ram[2028] = "0b00";
        ram[2029] = "0b00";
        ram[2030] = "0b00";
        ram[2031] = "0b00";
        ram[2032] = "0b11";
        for (unsigned i = 2033; i < 2076 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2076] = "0b01";
        ram[2077] = "0b00";
        ram[2078] = "0b11";
        for (unsigned i = 2079; i < 2090 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2090] = "0b11";
        for (unsigned i = 2091; i < 2113 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2113] = "0b01";
        for (unsigned i = 2114; i < 2124 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2124] = "0b11";
        for (unsigned i = 2125; i < 2132 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2132] = "0b11";
        for (unsigned i = 2133; i < 2139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2139] = "0b11";
        for (unsigned i = 2140; i < 2216 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2216] = "0b11";
        ram[2217] = "0b00";
        ram[2218] = "0b00";
        ram[2219] = "0b00";
        ram[2220] = "0b00";
        ram[2221] = "0b01";
        for (unsigned i = 2222; i < 2227 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2227] = "0b11";
        ram[2228] = "0b00";
        ram[2229] = "0b00";
        ram[2230] = "0b11";
        for (unsigned i = 2231; i < 2236 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2236] = "0b01";
        for (unsigned i = 2237; i < 2243 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2243] = "0b11";
        for (unsigned i = 2244; i < 2314 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2314] = "0b01";
        for (unsigned i = 2315; i < 2328 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2328] = "0b01";
        ram[2329] = "0b00";
        ram[2330] = "0b00";
        ram[2331] = "0b00";
        ram[2332] = "0b00";
        ram[2333] = "0b10";
        ram[2334] = "0b00";
        ram[2335] = "0b11";
        for (unsigned i = 2336; i < 2363 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2363] = "0b01";
        for (unsigned i = 2364; i < 2370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2370] = "0b10";
        for (unsigned i = 2371; i < 2424 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2424] = "0b11";
        for (unsigned i = 2425; i < 2438 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2438] = "0b11";
        for (unsigned i = 2439; i < 2479 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2479] = "0b01";
        ram[2480] = "0b00";
        ram[2481] = "0b00";
        ram[2482] = "0b11";
        ram[2483] = "0b00";
        ram[2484] = "0b00";
        ram[2485] = "0b00";
        ram[2486] = "0b00";
        ram[2487] = "0b11";
        for (unsigned i = 2488; i < 2494 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2494] = "0b11";
        for (unsigned i = 2495; i < 2510 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2510] = "0b11";
        for (unsigned i = 2511; i < 2521 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2521] = "0b10";
        ram[2522] = "0b00";
        ram[2523] = "0b11";
        ram[2524] = "0b00";
        ram[2525] = "0b00";
        ram[2526] = "0b01";
        for (unsigned i = 2527; i < 2542 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2542] = "0b11";
        for (unsigned i = 2543; i < 2615 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2615] = "0b11";
        ram[2616] = "0b00";
        ram[2617] = "0b01";
        for (unsigned i = 2618; i < 2673 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2673] = "0b01";
        for (unsigned i = 2674; i < 2680 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2680] = "0b11";
        for (unsigned i = 2681; i < 2717 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2717] = "0b11";
        ram[2718] = "0b00";
        ram[2719] = "0b00";
        ram[2720] = "0b11";
        for (unsigned i = 2721; i < 2729 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2729] = "0b01";
        ram[2730] = "0b00";
        ram[2731] = "0b00";
        ram[2732] = "0b00";
        ram[2733] = "0b00";
        ram[2734] = "0b11";
        for (unsigned i = 2735; i < 2761 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2761] = "0b01";
        for (unsigned i = 2762; i < 2767 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2767] = "0b01";
        ram[2768] = "0b00";
        ram[2769] = "0b01";
        ram[2770] = "0b00";
        ram[2771] = "0b00";
        ram[2772] = "0b00";
        ram[2773] = "0b11";
        for (unsigned i = 2774; i < 2818 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2818] = "0b11";
        ram[2819] = "0b00";
        ram[2820] = "0b00";
        ram[2821] = "0b00";
        ram[2822] = "0b00";
        ram[2823] = "0b11";
        ram[2824] = "0b00";
        ram[2825] = "0b11";
        ram[2826] = "0b00";
        ram[2827] = "0b00";
        ram[2828] = "0b00";
        ram[2829] = "0b00";
        ram[2830] = "0b11";
        for (unsigned i = 2831; i < 2855 ; i = i + 1) {
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
        for (unsigned i = 2870; i < 2886 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2886] = "0b11";
        for (unsigned i = 2887; i < 2902 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2902] = "0b01";
        for (unsigned i = 2903; i < 2946 ; i = i + 1) {
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
        for (unsigned i = 2973; i < 3016 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3016] = "0b01";
        ram[3017] = "0b00";
        ram[3018] = "0b00";
        ram[3019] = "0b00";
        ram[3020] = "0b00";
        ram[3021] = "0b11";
        for (unsigned i = 3022; i < 3032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3032] = "0b11";
        for (unsigned i = 3033; i < 3065 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3065] = "0b01";
        for (unsigned i = 3066; i < 3095 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3095] = "0b01";
        ram[3096] = "0b00";
        ram[3097] = "0b00";
        ram[3098] = "0b00";
        ram[3099] = "0b00";
        ram[3100] = "0b11";
        ram[3101] = "0b00";
        ram[3102] = "0b00";
        ram[3103] = "0b00";
        ram[3104] = "0b01";
        ram[3105] = "0b01";
        ram[3106] = "0b00";
        ram[3107] = "0b11";
        ram[3108] = "0b00";
        ram[3109] = "0b00";
        ram[3110] = "0b00";
        ram[3111] = "0b11";
        ram[3112] = "0b11";
        ram[3113] = "0b00";
        ram[3114] = "0b00";
        ram[3115] = "0b00";
        ram[3116] = "0b00";
        ram[3117] = "0b10";
        for (unsigned i = 3118; i < 3144 ; i = i + 1) {
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
        for (unsigned i = 3161; i < 3196 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3196] = "0b11";
        for (unsigned i = 3197; i < 3203 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3203] = "0b01";
        for (unsigned i = 3204; i < 3289 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3289] = "0b11";
        for (unsigned i = 3290; i < 3298 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3298] = "0b11";
        ram[3299] = "0b00";
        ram[3300] = "0b11";
        for (unsigned i = 3301; i < 3320 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3320] = "0b11";
        for (unsigned i = 3321; i < 3359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3359] = "0b01";
        for (unsigned i = 3360; i < 3387 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3387] = "0b11";
        for (unsigned i = 3388; i < 3394 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3394] = "0b01";
        ram[3395] = "0b00";
        ram[3396] = "0b00";
        ram[3397] = "0b00";
        ram[3398] = "0b00";
        ram[3399] = "0b11";
        ram[3400] = "0b00";
        ram[3401] = "0b00";
        ram[3402] = "0b00";
        ram[3403] = "0b00";
        ram[3404] = "0b11";
        ram[3405] = "0b11";
        for (unsigned i = 3406; i < 3412 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3412] = "0b11";
        for (unsigned i = 3413; i < 3418 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3418] = "0b01";
        for (unsigned i = 3419; i < 3453 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3453] = "0b11";
        for (unsigned i = 3454; i < 3465 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3465] = "0b01";
        ram[3466] = "0b00";
        ram[3467] = "0b00";
        ram[3468] = "0b01";
        for (unsigned i = 3469; i < 3586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3586] = "0b11";
        for (unsigned i = 3587; i < 3607 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3607] = "0b11";
        for (unsigned i = 3608; i < 3669 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3669] = "0b11";
        for (unsigned i = 3670; i < 3707 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3707] = "0b11";
        for (unsigned i = 3708; i < 3714 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3714] = "0b01";
        for (unsigned i = 3715; i < 3756 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3756] = "0b01";
        for (unsigned i = 3757; i < 3781 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3781] = "0b11";
        ram[3782] = "0b00";
        ram[3783] = "0b11";
        ram[3784] = "0b11";
        ram[3785] = "0b00";
        ram[3786] = "0b01";
        ram[3787] = "0b00";
        ram[3788] = "0b01";
        for (unsigned i = 3789; i < 3802 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3802] = "0b11";
        for (unsigned i = 3803; i < 3843 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3843] = "0b11";
        ram[3844] = "0b00";
        ram[3845] = "0b01";
        ram[3846] = "0b00";
        ram[3847] = "0b01";
        ram[3848] = "0b00";
        ram[3849] = "0b00";
        ram[3850] = "0b00";
        ram[3851] = "0b00";
        ram[3852] = "0b11";
        ram[3853] = "0b00";
        ram[3854] = "0b10";
        ram[3855] = "0b00";
        ram[3856] = "0b00";
        ram[3857] = "0b00";
        ram[3858] = "0b00";
        ram[3859] = "0b01";
        ram[3860] = "0b00";
        ram[3861] = "0b01";
        for (unsigned i = 3862; i < 3880 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3880] = "0b11";
        for (unsigned i = 3881; i < 3886 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3886] = "0b11";
        ram[3887] = "0b00";
        ram[3888] = "0b00";
        ram[3889] = "0b00";
        ram[3890] = "0b00";
        ram[3891] = "0b11";
        ram[3892] = "0b00";
        ram[3893] = "0b01";
        ram[3894] = "0b00";
        ram[3895] = "0b00";
        ram[3896] = "0b00";
        ram[3897] = "0b00";
        ram[3898] = "0b11";
        ram[3899] = "0b00";
        ram[3900] = "0b01";
        for (unsigned i = 3901; i < 3933 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3933] = "0b01";
        for (unsigned i = 3934; i < 3961 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3961] = "0b01";
        ram[3962] = "0b00";
        ram[3963] = "0b11";
        for (unsigned i = 3964; i < 3992 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3992] = "0b01";
        for (unsigned i = 3993; i < 4029 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4029] = "0b11";
        for (unsigned i = 4030; i < 4050 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4050] = "0b11";
        for (unsigned i = 4051; i < 4061 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4061] = "0b11";
        for (unsigned i = 4062; i < 4091 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4091] = "0b01";
        for (unsigned i = 4092; i < 4194 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4194] = "0b01";
        ram[4195] = "0b11";
        for (unsigned i = 4196; i < 4283 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4283] = "0b11";
        for (unsigned i = 4284; i < 4336 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4336] = "0b11";
        for (unsigned i = 4337; i < 4342 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4342] = "0b11";
        ram[4343] = "0b11";
        ram[4344] = "0b11";
        ram[4345] = "0b00";
        ram[4346] = "0b00";
        ram[4347] = "0b00";
        ram[4348] = "0b00";
        ram[4349] = "0b01";
        ram[4350] = "0b00";
        ram[4351] = "0b00";
        ram[4352] = "0b00";
        ram[4353] = "0b01";
        ram[4354] = "0b00";
        ram[4355] = "0b11";
        for (unsigned i = 4356; i < 4479 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4479] = "0b01";
        ram[4480] = "0b00";
        ram[4481] = "0b11";
        ram[4482] = "0b11";
        for (unsigned i = 4483; i < 4488 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4488] = "0b11";
        for (unsigned i = 4489; i < 4494 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4494] = "0b01";
        ram[4495] = "0b00";
        ram[4496] = "0b00";
        ram[4497] = "0b01";
        for (unsigned i = 4498; i < 4519 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4519] = "0b11";
        for (unsigned i = 4520; i < 4547 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4547] = "0b01";
        for (unsigned i = 4548; i < 4563 ; i = i + 1) {
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
        ram[4587] = "0b01";
        ram[4588] = "0b00";
        ram[4589] = "0b00";
        ram[4590] = "0b00";
        ram[4591] = "0b01";
        for (unsigned i = 4592; i < 4615 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4615] = "0b11";
        for (unsigned i = 4616; i < 4621 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4621] = "0b01";
        ram[4622] = "0b00";
        ram[4623] = "0b00";
        ram[4624] = "0b00";
        ram[4625] = "0b00";
        ram[4626] = "0b11";
        ram[4627] = "0b00";
        ram[4628] = "0b11";
        ram[4629] = "0b00";
        ram[4630] = "0b11";
        for (unsigned i = 4631; i < 4733 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4733] = "0b11";
        for (unsigned i = 4734; i < 4745 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4745] = "0b01";
        for (unsigned i = 4746; i < 4773 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4773] = "0b11";
        for (unsigned i = 4774; i < 4860 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4860] = "0b11";
        for (unsigned i = 4861; i < 4868 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4868] = "0b01";
        for (unsigned i = 4869; i < 4876 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4876] = "0b01";
        for (unsigned i = 4877; i < 4888 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4888] = "0b01";
        for (unsigned i = 4889; i < 4916 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4916] = "0b01";
        for (unsigned i = 4917; i < 4972 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4972] = "0b11";
        for (unsigned i = 4973; i < 5058 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5058] = "0b11";
        for (unsigned i = 5059; i < 5064 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5064] = "0b01";
        ram[5065] = "0b00";
        ram[5066] = "0b00";
        ram[5067] = "0b01";
        for (unsigned i = 5068; i < 5081 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5081] = "0b01";
        ram[5082] = "0b00";
        ram[5083] = "0b11";
        ram[5084] = "0b00";
        ram[5085] = "0b00";
        ram[5086] = "0b00";
        ram[5087] = "0b00";
        ram[5088] = "0b11";
        for (unsigned i = 5089; i < 5161 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5161] = "0b11";
        ram[5162] = "0b00";
        ram[5163] = "0b11";
        for (unsigned i = 5164; i < 5180 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5180] = "0b01";
        for (unsigned i = 5181; i < 5221 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5221] = "0b11";
        ram[5222] = "0b00";
        ram[5223] = "0b00";
        ram[5224] = "0b00";
        ram[5225] = "0b00";
        ram[5226] = "0b11";
        ram[5227] = "0b00";
        ram[5228] = "0b00";
        ram[5229] = "0b00";
        ram[5230] = "0b00";
        ram[5231] = "0b01";
        for (unsigned i = 5232; i < 5261 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5261] = "0b11";
        for (unsigned i = 5262; i < 5268 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5268] = "0b01";
        for (unsigned i = 5269; i < 5298 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5298] = "0b11";
        ram[5299] = "0b00";
        ram[5300] = "0b00";
        ram[5301] = "0b00";
        ram[5302] = "0b01";
        for (unsigned i = 5303; i < 5309 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5309] = "0b11";
        ram[5310] = "0b00";
        ram[5311] = "0b00";
        ram[5312] = "0b01";
        for (unsigned i = 5313; i < 5326 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5326] = "0b11";
        ram[5327] = "0b00";
        ram[5328] = "0b11";
        ram[5329] = "0b00";
        ram[5330] = "0b01";
        ram[5331] = "0b00";
        ram[5332] = "0b00";
        ram[5333] = "0b00";
        ram[5334] = "0b00";
        ram[5335] = "0b11";
        for (unsigned i = 5336; i < 5359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5359] = "0b11";
        ram[5360] = "0b00";
        ram[5361] = "0b00";
        ram[5362] = "0b00";
        ram[5363] = "0b00";
        ram[5364] = "0b11";
        ram[5365] = "0b00";
        ram[5366] = "0b01";
        for (unsigned i = 5367; i < 5377 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5377] = "0b11";
        for (unsigned i = 5378; i < 5414 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5414] = "0b11";
        ram[5415] = "0b11";
        ram[5416] = "0b00";
        ram[5417] = "0b00";
        ram[5418] = "0b00";
        ram[5419] = "0b00";
        ram[5420] = "0b01";
        ram[5421] = "0b11";
        ram[5422] = "0b01";
        ram[5423] = "0b00";
        ram[5424] = "0b00";
        ram[5425] = "0b00";
        ram[5426] = "0b00";
        ram[5427] = "0b11";
        ram[5428] = "0b00";
        ram[5429] = "0b11";
        for (unsigned i = 5430; i < 5449 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5449] = "0b11";
        ram[5450] = "0b00";
        ram[5451] = "0b00";
        ram[5452] = "0b11";
        for (unsigned i = 5453; i < 5463 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5463] = "0b01";
        for (unsigned i = 5464; i < 5478 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5478] = "0b11";
        ram[5479] = "0b00";
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
        for (unsigned i = 5509; i < 5532 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5532] = "0b01";
        for (unsigned i = 5533; i < 5550 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5550] = "0b11";
        for (unsigned i = 5551; i < 5559 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5559] = "0b01";
        for (unsigned i = 5560; i < 5599 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5599] = "0b01";
        for (unsigned i = 5600; i < 5644 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5644] = "0b11";
        ram[5645] = "0b00";
        ram[5646] = "0b01";
        ram[5647] = "0b00";
        ram[5648] = "0b11";
        ram[5649] = "0b00";
        ram[5650] = "0b00";
        ram[5651] = "0b11";
        ram[5652] = "0b00";
        ram[5653] = "0b01";
        ram[5654] = "0b00";
        ram[5655] = "0b11";
        ram[5656] = "0b00";
        ram[5657] = "0b00";
        ram[5658] = "0b00";
        ram[5659] = "0b01";
        ram[5660] = "0b01";
        for (unsigned i = 5661; i < 5678 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5678] = "0b11";
        for (unsigned i = 5679; i < 5720 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5720] = "0b11";
        ram[5721] = "0b11";
        for (unsigned i = 5722; i < 5799 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5799] = "0b01";
        ram[5800] = "0b00";
        ram[5801] = "0b00";
        ram[5802] = "0b11";
        for (unsigned i = 5803; i < 5820 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5820] = "0b01";
        ram[5821] = "0b01";
        ram[5822] = "0b00";
        ram[5823] = "0b00";
        ram[5824] = "0b00";
        ram[5825] = "0b00";
        ram[5826] = "0b01";
        for (unsigned i = 5827; i < 5837 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5837] = "0b01";
        for (unsigned i = 5838; i < 5844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5844] = "0b11";
        ram[5845] = "0b00";
        ram[5846] = "0b01";
        ram[5847] = "0b00";
        ram[5848] = "0b00";
        ram[5849] = "0b00";
        ram[5850] = "0b00";
        ram[5851] = "0b11";
        for (unsigned i = 5852; i < 5874 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5874] = "0b11";
        for (unsigned i = 5875; i < 5945 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5945] = "0b11";
        ram[5946] = "0b00";
        ram[5947] = "0b00";
        ram[5948] = "0b00";
        ram[5949] = "0b11";
        for (unsigned i = 5950; i < 5956 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5956] = "0b01";
        for (unsigned i = 5957; i < 5993 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5993] = "0b11";
        for (unsigned i = 5994; i < 6001 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6001] = "0b11";
        for (unsigned i = 6002; i < 6043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6043] = "0b11";
        for (unsigned i = 6044; i < 6049 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6049] = "0b11";
        ram[6050] = "0b11";
        ram[6051] = "0b11";
        ram[6052] = "0b00";
        ram[6053] = "0b00";
        ram[6054] = "0b01";
        ram[6055] = "0b00";
        ram[6056] = "0b00";
        ram[6057] = "0b01";
        for (unsigned i = 6058; i < 6093 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6093] = "0b11";
        for (unsigned i = 6094; i < 6101 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6101] = "0b01";
        ram[6102] = "0b00";
        ram[6103] = "0b01";
        for (unsigned i = 6104; i < 6110 ; i = i + 1) {
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
        for (unsigned i = 6141; i < 6157 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6157] = "0b11";
        ram[6158] = "0b00";
        ram[6159] = "0b01";
        for (unsigned i = 6160; i < 6196 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6196] = "0b01";
        for (unsigned i = 6197; i < 6246 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6246] = "0b01";
        for (unsigned i = 6247; i < 6266 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_3) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_3_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_3) {
meminst = new mlp_accel_4b_weights_l1_4b_3_ram("mlp_accel_4b_weights_l1_4b_3_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_3() {
    delete meminst;
}


};//endmodule
#endif
