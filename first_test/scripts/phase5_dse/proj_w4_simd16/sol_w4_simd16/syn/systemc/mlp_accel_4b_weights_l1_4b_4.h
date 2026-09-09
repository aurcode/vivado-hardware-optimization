// ==============================================================
// File generated on Wed Sep 02 16:33:43 +0000 2026
// Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
// SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
// IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
// Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
// ==============================================================
#ifndef __mlp_accel_4b_weights_l1_4b_4_H__
#define __mlp_accel_4b_weights_l1_4b_4_H__


#include <systemc>
using namespace sc_core;
using namespace sc_dt;




#include <iostream>
#include <fstream>

struct mlp_accel_4b_weights_l1_4b_4_ram : public sc_core::sc_module {

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


   SC_CTOR(mlp_accel_4b_weights_l1_4b_4_ram) {
        for (unsigned i = 0; i < 76 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[76] = "0b11";
        ram[77] = "0b00";
        ram[78] = "0b01";
        for (unsigned i = 79; i < 111 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[111] = "0b11";
        ram[112] = "0b00";
        ram[113] = "0b00";
        ram[114] = "0b11";
        ram[115] = "0b00";
        ram[116] = "0b00";
        ram[117] = "0b00";
        ram[118] = "0b11";
        for (unsigned i = 119; i < 125 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[125] = "0b01";
        for (unsigned i = 126; i < 132 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[132] = "0b01";
        for (unsigned i = 133; i < 156 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[156] = "0b11";
        for (unsigned i = 157; i < 162 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[162] = "0b11";
        ram[163] = "0b11";
        for (unsigned i = 164; i < 171 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[171] = "0b11";
        ram[172] = "0b00";
        ram[173] = "0b00";
        ram[174] = "0b00";
        ram[175] = "0b01";
        for (unsigned i = 176; i < 302 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[302] = "0b01";
        for (unsigned i = 303; i < 310 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[310] = "0b01";
        ram[311] = "0b00";
        ram[312] = "0b11";
        ram[313] = "0b00";
        ram[314] = "0b00";
        ram[315] = "0b00";
        ram[316] = "0b00";
        ram[317] = "0b01";
        for (unsigned i = 318; i < 375 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[375] = "0b11";
        for (unsigned i = 376; i < 407 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[407] = "0b11";
        for (unsigned i = 408; i < 424 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[424] = "0b01";
        ram[425] = "0b00";
        ram[426] = "0b00";
        ram[427] = "0b00";
        ram[428] = "0b11";
        ram[429] = "0b00";
        ram[430] = "0b00";
        ram[431] = "0b11";
        ram[432] = "0b00";
        ram[433] = "0b11";
        for (unsigned i = 434; i < 452 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[452] = "0b01";
        for (unsigned i = 453; i < 473 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[473] = "0b01";
        for (unsigned i = 474; i < 484 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[484] = "0b01";
        for (unsigned i = 485; i < 503 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[503] = "0b11";
        for (unsigned i = 504; i < 511 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[511] = "0b11";
        ram[512] = "0b00";
        ram[513] = "0b11";
        ram[514] = "0b00";
        ram[515] = "0b01";
        for (unsigned i = 516; i < 554 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[554] = "0b11";
        ram[555] = "0b00";
        ram[556] = "0b00";
        ram[557] = "0b11";
        ram[558] = "0b00";
        ram[559] = "0b01";
        for (unsigned i = 560; i < 576 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[576] = "0b11";
        for (unsigned i = 577; i < 608 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[608] = "0b01";
        for (unsigned i = 609; i < 618 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[618] = "0b01";
        ram[619] = "0b00";
        ram[620] = "0b01";
        for (unsigned i = 621; i < 650 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[650] = "0b01";
        ram[651] = "0b00";
        ram[652] = "0b00";
        ram[653] = "0b00";
        ram[654] = "0b11";
        ram[655] = "0b11";
        for (unsigned i = 656; i < 678 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[678] = "0b11";
        for (unsigned i = 679; i < 729 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[729] = "0b11";
        for (unsigned i = 730; i < 804 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[804] = "0b01";
        ram[805] = "0b11";
        for (unsigned i = 806; i < 816 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[816] = "0b11";
        ram[817] = "0b00";
        ram[818] = "0b00";
        ram[819] = "0b01";
        for (unsigned i = 820; i < 827 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[827] = "0b11";
        for (unsigned i = 828; i < 842 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[842] = "0b01";
        ram[843] = "0b00";
        ram[844] = "0b00";
        ram[845] = "0b00";
        ram[846] = "0b11";
        for (unsigned i = 847; i < 853 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[853] = "0b01";
        ram[854] = "0b00";
        ram[855] = "0b00";
        ram[856] = "0b00";
        ram[857] = "0b01";
        for (unsigned i = 858; i < 863 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[863] = "0b11";
        for (unsigned i = 864; i < 869 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[869] = "0b11";
        ram[870] = "0b11";
        for (unsigned i = 871; i < 940 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[940] = "0b01";
        for (unsigned i = 941; i < 947 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[947] = "0b11";
        ram[948] = "0b00";
        ram[949] = "0b00";
        ram[950] = "0b00";
        ram[951] = "0b11";
        ram[952] = "0b00";
        ram[953] = "0b00";
        ram[954] = "0b01";
        for (unsigned i = 955; i < 963 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[963] = "0b11";
        for (unsigned i = 964; i < 1043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1043] = "0b01";
        ram[1044] = "0b11";
        for (unsigned i = 1045; i < 1056 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1056] = "0b01";
        for (unsigned i = 1057; i < 1114 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1114] = "0b11";
        for (unsigned i = 1115; i < 1193 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1193] = "0b01";
        for (unsigned i = 1194; i < 1212 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1212] = "0b11";
        ram[1213] = "0b00";
        ram[1214] = "0b00";
        ram[1215] = "0b00";
        ram[1216] = "0b00";
        ram[1217] = "0b11";
        for (unsigned i = 1218; i < 1292 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1292] = "0b01";
        for (unsigned i = 1293; i < 1397 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1397] = "0b11";
        ram[1398] = "0b00";
        ram[1399] = "0b00";
        ram[1400] = "0b00";
        ram[1401] = "0b00";
        ram[1402] = "0b10";
        ram[1403] = "0b00";
        ram[1404] = "0b01";
        for (unsigned i = 1405; i < 1418 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1418] = "0b11";
        for (unsigned i = 1419; i < 1437 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1437] = "0b11";
        ram[1438] = "0b00";
        ram[1439] = "0b00";
        ram[1440] = "0b00";
        ram[1441] = "0b11";
        for (unsigned i = 1442; i < 1456 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1456] = "0b01";
        for (unsigned i = 1457; i < 1462 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1462] = "0b11";
        for (unsigned i = 1463; i < 1504 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1504] = "0b01";
        for (unsigned i = 1505; i < 1511 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1511] = "0b11";
        for (unsigned i = 1512; i < 1525 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1525] = "0b11";
        for (unsigned i = 1526; i < 1539 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1539] = "0b01";
        ram[1540] = "0b00";
        ram[1541] = "0b11";
        ram[1542] = "0b00";
        ram[1543] = "0b00";
        ram[1544] = "0b00";
        ram[1545] = "0b00";
        ram[1546] = "0b01";
        for (unsigned i = 1547; i < 1588 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1588] = "0b11";
        ram[1589] = "0b00";
        ram[1590] = "0b00";
        ram[1591] = "0b00";
        ram[1592] = "0b00";
        ram[1593] = "0b11";
        ram[1594] = "0b00";
        ram[1595] = "0b00";
        ram[1596] = "0b00";
        ram[1597] = "0b00";
        ram[1598] = "0b11";
        ram[1599] = "0b00";
        ram[1600] = "0b00";
        ram[1601] = "0b00";
        ram[1602] = "0b00";
        ram[1603] = "0b11";
        for (unsigned i = 1604; i < 1625 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1625] = "0b11";
        ram[1626] = "0b00";
        ram[1627] = "0b00";
        ram[1628] = "0b11";
        for (unsigned i = 1629; i < 1635 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1635] = "0b01";
        for (unsigned i = 1636; i < 1698 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1698] = "0b01";
        for (unsigned i = 1699; i < 1705 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1705] = "0b01";
        for (unsigned i = 1706; i < 1796 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1796] = "0b01";
        for (unsigned i = 1797; i < 1828 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1828] = "0b11";
        for (unsigned i = 1829; i < 1834 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1834] = "0b01";
        ram[1835] = "0b00";
        ram[1836] = "0b00";
        ram[1837] = "0b00";
        ram[1838] = "0b11";
        for (unsigned i = 1839; i < 1856 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1856] = "0b01";
        for (unsigned i = 1857; i < 1924 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1924] = "0b01";
        for (unsigned i = 1925; i < 1936 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1936] = "0b11";
        ram[1937] = "0b00";
        ram[1938] = "0b00";
        ram[1939] = "0b00";
        ram[1940] = "0b11";
        ram[1941] = "0b00";
        ram[1942] = "0b00";
        ram[1943] = "0b11";
        for (unsigned i = 1944; i < 1955 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1955] = "0b01";
        for (unsigned i = 1956; i < 1966 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1966] = "0b01";
        for (unsigned i = 1967; i < 1982 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1982] = "0b11";
        for (unsigned i = 1983; i < 1990 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[1990] = "0b01";
        for (unsigned i = 1991; i < 2032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2032] = "0b11";
        for (unsigned i = 2033; i < 2075 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2075] = "0b01";
        ram[2076] = "0b01";
        ram[2077] = "0b00";
        ram[2078] = "0b11";
        ram[2079] = "0b00";
        ram[2080] = "0b00";
        ram[2081] = "0b00";
        ram[2082] = "0b01";
        ram[2083] = "0b00";
        ram[2084] = "0b00";
        ram[2085] = "0b11";
        ram[2086] = "0b00";
        ram[2087] = "0b00";
        ram[2088] = "0b00";
        ram[2089] = "0b00";
        ram[2090] = "0b11";
        for (unsigned i = 2091; i < 2099 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2099] = "0b01";
        for (unsigned i = 2100; i < 2121 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2121] = "0b11";
        for (unsigned i = 2122; i < 2139 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2139] = "0b11";
        for (unsigned i = 2140; i < 2216 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2216] = "0b11";
        ram[2217] = "0b00";
        ram[2218] = "0b01";
        ram[2219] = "0b00";
        ram[2220] = "0b00";
        ram[2221] = "0b01";
        for (unsigned i = 2222; i < 2230 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2230] = "0b11";
        for (unsigned i = 2231; i < 2320 ; i = i + 1) {
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
        ram[2332] = "0b00";
        ram[2333] = "0b10";
        ram[2334] = "0b00";
        ram[2335] = "0b00";
        ram[2336] = "0b00";
        ram[2337] = "0b11";
        for (unsigned i = 2338; i < 2356 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2356] = "0b01";
        ram[2357] = "0b00";
        ram[2358] = "0b01";
        ram[2359] = "0b00";
        ram[2360] = "0b00";
        ram[2361] = "0b00";
        ram[2362] = "0b11";
        ram[2363] = "0b01";
        for (unsigned i = 2364; i < 2370 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2370] = "0b10";
        ram[2371] = "0b00";
        ram[2372] = "0b00";
        ram[2373] = "0b11";
        for (unsigned i = 2374; i < 2380 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2380] = "0b01";
        for (unsigned i = 2381; i < 2396 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2396] = "0b01";
        for (unsigned i = 2397; i < 2426 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2426] = "0b01";
        for (unsigned i = 2427; i < 2438 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2438] = "0b11";
        ram[2439] = "0b00";
        ram[2440] = "0b00";
        ram[2441] = "0b00";
        ram[2442] = "0b11";
        for (unsigned i = 2443; i < 2482 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2482] = "0b11";
        ram[2483] = "0b00";
        ram[2484] = "0b00";
        ram[2485] = "0b00";
        ram[2486] = "0b11";
        ram[2487] = "0b11";
        for (unsigned i = 2488; i < 2516 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2516] = "0b01";
        ram[2517] = "0b00";
        ram[2518] = "0b00";
        ram[2519] = "0b00";
        ram[2520] = "0b00";
        ram[2521] = "0b11";
        for (unsigned i = 2522; i < 2534 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2534] = "0b11";
        ram[2535] = "0b11";
        for (unsigned i = 2536; i < 2615 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2615] = "0b11";
        for (unsigned i = 2616; i < 2678 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2678] = "0b11";
        for (unsigned i = 2679; i < 2720 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2720] = "0b11";
        for (unsigned i = 2721; i < 2727 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2727] = "0b11";
        ram[2728] = "0b00";
        ram[2729] = "0b01";
        for (unsigned i = 2730; i < 2761 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2761] = "0b01";
        for (unsigned i = 2762; i < 2773 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2773] = "0b11";
        for (unsigned i = 2774; i < 2811 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2811] = "0b01";
        for (unsigned i = 2812; i < 2818 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2818] = "0b11";
        ram[2819] = "0b00";
        ram[2820] = "0b00";
        ram[2821] = "0b00";
        ram[2822] = "0b00";
        ram[2823] = "0b11";
        for (unsigned i = 2824; i < 2830 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2830] = "0b11";
        for (unsigned i = 2831; i < 2855 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2855] = "0b11";
        for (unsigned i = 2856; i < 2874 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2874] = "0b01";
        for (unsigned i = 2875; i < 2886 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2886] = "0b11";
        for (unsigned i = 2887; i < 2902 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2902] = "0b01";
        for (unsigned i = 2903; i < 2911 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2911] = "0b01";
        for (unsigned i = 2912; i < 2963 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[2963] = "0b11";
        ram[2964] = "0b00";
        ram[2965] = "0b00";
        ram[2966] = "0b00";
        ram[2967] = "0b00";
        ram[2968] = "0b11";
        ram[2969] = "0b00";
        ram[2970] = "0b00";
        ram[2971] = "0b00";
        ram[2972] = "0b01";
        for (unsigned i = 2973; i < 3019 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3019] = "0b11";
        for (unsigned i = 3020; i < 3096 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3096] = "0b11";
        ram[3097] = "0b00";
        ram[3098] = "0b00";
        ram[3099] = "0b00";
        ram[3100] = "0b11";
        ram[3101] = "0b00";
        ram[3102] = "0b00";
        ram[3103] = "0b00";
        ram[3104] = "0b00";
        ram[3105] = "0b01";
        for (unsigned i = 3106; i < 3117 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3117] = "0b11";
        for (unsigned i = 3118; i < 3146 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3146] = "0b01";
        ram[3147] = "0b00";
        ram[3148] = "0b00";
        ram[3149] = "0b01";
        ram[3150] = "0b00";
        ram[3151] = "0b11";
        for (unsigned i = 3152; i < 3180 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3180] = "0b01";
        for (unsigned i = 3181; i < 3193 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3193] = "0b11";
        ram[3194] = "0b00";
        ram[3195] = "0b00";
        ram[3196] = "0b11";
        for (unsigned i = 3197; i < 3292 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3292] = "0b01";
        for (unsigned i = 3293; i < 3298 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3298] = "0b11";
        for (unsigned i = 3299; i < 3315 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3315] = "0b11";
        for (unsigned i = 3316; i < 3324 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3324] = "0b11";
        for (unsigned i = 3325; i < 3352 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3352] = "0b11";
        for (unsigned i = 3353; i < 3359 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3359] = "0b01";
        for (unsigned i = 3360; i < 3394 ; i = i + 1) {
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
        for (unsigned i = 3405; i < 3420 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3420] = "0b11";
        for (unsigned i = 3421; i < 3448 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3448] = "0b11";
        ram[3449] = "0b00";
        ram[3450] = "0b00";
        ram[3451] = "0b00";
        ram[3452] = "0b00";
        ram[3453] = "0b10";
        ram[3454] = "0b00";
        ram[3455] = "0b00";
        ram[3456] = "0b00";
        ram[3457] = "0b00";
        ram[3458] = "0b11";
        for (unsigned i = 3459; i < 3520 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3520] = "0b01";
        for (unsigned i = 3521; i < 3586 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3586] = "0b11";
        for (unsigned i = 3587; i < 3594 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3594] = "0b01";
        ram[3595] = "0b00";
        ram[3596] = "0b00";
        ram[3597] = "0b11";
        for (unsigned i = 3598; i < 3606 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3606] = "0b11";
        for (unsigned i = 3607; i < 3670 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3670] = "0b11";
        for (unsigned i = 3671; i < 3707 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3707] = "0b11";
        ram[3708] = "0b00";
        ram[3709] = "0b01";
        ram[3710] = "0b00";
        ram[3711] = "0b00";
        ram[3712] = "0b00";
        ram[3713] = "0b00";
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
        for (unsigned i = 3787; i < 3802 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3802] = "0b11";
        ram[3803] = "0b00";
        ram[3804] = "0b00";
        ram[3805] = "0b11";
        ram[3806] = "0b00";
        ram[3807] = "0b00";
        ram[3808] = "0b00";
        ram[3809] = "0b11";
        for (unsigned i = 3810; i < 3844 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3844] = "0b01";
        ram[3845] = "0b00";
        ram[3846] = "0b00";
        ram[3847] = "0b01";
        ram[3848] = "0b00";
        ram[3849] = "0b00";
        ram[3850] = "0b11";
        ram[3851] = "0b00";
        ram[3852] = "0b10";
        ram[3853] = "0b00";
        ram[3854] = "0b10";
        ram[3855] = "0b00";
        ram[3856] = "0b00";
        ram[3857] = "0b00";
        ram[3858] = "0b00";
        ram[3859] = "0b01";
        for (unsigned i = 3860; i < 3880 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3880] = "0b11";
        for (unsigned i = 3881; i < 3903 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3903] = "0b11";
        for (unsigned i = 3904; i < 3986 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[3986] = "0b01";
        for (unsigned i = 3987; i < 4004 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4004] = "0b11";
        ram[4005] = "0b00";
        ram[4006] = "0b00";
        ram[4007] = "0b01";
        for (unsigned i = 4008; i < 4033 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4033] = "0b01";
        ram[4034] = "0b11";
        for (unsigned i = 4035; i < 4045 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4045] = "0b11";
        ram[4046] = "0b00";
        ram[4047] = "0b00";
        ram[4048] = "0b00";
        ram[4049] = "0b00";
        ram[4050] = "0b11";
        ram[4051] = "0b00";
        ram[4052] = "0b01";
        ram[4053] = "0b00";
        ram[4054] = "0b11";
        for (unsigned i = 4055; i < 4091 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4091] = "0b01";
        for (unsigned i = 4092; i < 4101 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4101] = "0b01";
        for (unsigned i = 4102; i < 4134 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4134] = "0b11";
        for (unsigned i = 4135; i < 4195 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4195] = "0b11";
        ram[4196] = "0b00";
        ram[4197] = "0b11";
        for (unsigned i = 4198; i < 4321 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4321] = "0b11";
        for (unsigned i = 4322; i < 4332 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4332] = "0b11";
        for (unsigned i = 4333; i < 4342 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4342] = "0b11";
        ram[4343] = "0b00";
        ram[4344] = "0b11";
        ram[4345] = "0b00";
        ram[4346] = "0b01";
        ram[4347] = "0b01";
        ram[4348] = "0b00";
        ram[4349] = "0b01";
        for (unsigned i = 4350; i < 4355 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4355] = "0b11";
        for (unsigned i = 4356; i < 4402 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4402] = "0b01";
        for (unsigned i = 4403; i < 4468 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4468] = "0b11";
        for (unsigned i = 4469; i < 4481 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4481] = "0b11";
        for (unsigned i = 4482; i < 4488 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4488] = "0b11";
        ram[4489] = "0b00";
        ram[4490] = "0b00";
        ram[4491] = "0b01";
        for (unsigned i = 4492; i < 4497 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4497] = "0b01";
        ram[4498] = "0b00";
        ram[4499] = "0b00";
        ram[4500] = "0b00";
        ram[4501] = "0b00";
        ram[4502] = "0b11";
        for (unsigned i = 4503; i < 4519 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4519] = "0b11";
        for (unsigned i = 4520; i < 4525 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4525] = "0b01";
        for (unsigned i = 4526; i < 4542 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4542] = "0b01";
        ram[4543] = "0b00";
        ram[4544] = "0b11";
        ram[4545] = "0b00";
        ram[4546] = "0b00";
        ram[4547] = "0b01";
        for (unsigned i = 4548; i < 4572 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4572] = "0b01";
        for (unsigned i = 4573; i < 4584 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4584] = "0b01";
        ram[4585] = "0b00";
        ram[4586] = "0b01";
        for (unsigned i = 4587; i < 4598 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4598] = "0b11";
        for (unsigned i = 4599; i < 4621 ; i = i + 1) {
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
        for (unsigned i = 4631; i < 4638 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4638] = "0b01";
        for (unsigned i = 4639; i < 4644 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4644] = "0b01";
        for (unsigned i = 4645; i < 4684 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4684] = "0b11";
        for (unsigned i = 4685; i < 4733 ; i = i + 1) {
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
        ram[4774] = "0b00";
        ram[4775] = "0b01";
        for (unsigned i = 4776; i < 4838 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4838] = "0b01";
        for (unsigned i = 4839; i < 4860 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4860] = "0b11";
        for (unsigned i = 4861; i < 4872 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4872] = "0b11";
        ram[4873] = "0b00";
        ram[4874] = "0b00";
        ram[4875] = "0b01";
        for (unsigned i = 4876; i < 4883 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4883] = "0b11";
        for (unsigned i = 4884; i < 4911 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4911] = "0b11";
        ram[4912] = "0b00";
        ram[4913] = "0b00";
        ram[4914] = "0b00";
        ram[4915] = "0b00";
        ram[4916] = "0b01";
        for (unsigned i = 4917; i < 4962 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[4962] = "0b11";
        for (unsigned i = 4963; i < 5032 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5032] = "0b01";
        ram[5033] = "0b00";
        ram[5034] = "0b00";
        ram[5035] = "0b01";
        for (unsigned i = 5036; i < 5058 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5058] = "0b11";
        for (unsigned i = 5059; i < 5079 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5079] = "0b11";
        ram[5080] = "0b00";
        ram[5081] = "0b00";
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
        ram[5164] = "0b00";
        ram[5165] = "0b11";
        for (unsigned i = 5166; i < 5211 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5211] = "0b01";
        for (unsigned i = 5212; i < 5224 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5224] = "0b11";
        ram[5225] = "0b00";
        ram[5226] = "0b11";
        ram[5227] = "0b00";
        ram[5228] = "0b00";
        ram[5229] = "0b00";
        ram[5230] = "0b00";
        ram[5231] = "0b01";
        for (unsigned i = 5232; i < 5298 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5298] = "0b11";
        ram[5299] = "0b00";
        ram[5300] = "0b00";
        ram[5301] = "0b00";
        ram[5302] = "0b00";
        ram[5303] = "0b11";
        ram[5304] = "0b00";
        ram[5305] = "0b01";
        ram[5306] = "0b00";
        ram[5307] = "0b00";
        ram[5308] = "0b00";
        ram[5309] = "0b11";
        ram[5310] = "0b11";
        ram[5311] = "0b00";
        ram[5312] = "0b01";
        for (unsigned i = 5313; i < 5336 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5336] = "0b01";
        for (unsigned i = 5337; i < 5355 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5355] = "0b11";
        ram[5356] = "0b00";
        ram[5357] = "0b00";
        ram[5358] = "0b00";
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
        for (unsigned i = 5378; i < 5384 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5384] = "0b11";
        for (unsigned i = 5385; i < 5399 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5399] = "0b11";
        for (unsigned i = 5400; i < 5420 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5420] = "0b01";
        for (unsigned i = 5421; i < 5427 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5427] = "0b11";
        for (unsigned i = 5428; i < 5434 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5434] = "0b01";
        ram[5435] = "0b00";
        ram[5436] = "0b01";
        for (unsigned i = 5437; i < 5445 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5445] = "0b01";
        ram[5446] = "0b00";
        ram[5447] = "0b11";
        ram[5448] = "0b00";
        ram[5449] = "0b00";
        ram[5450] = "0b00";
        ram[5451] = "0b00";
        ram[5452] = "0b11";
        for (unsigned i = 5453; i < 5480 ; i = i + 1) {
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
        ram[5508] = "0b00";
        ram[5509] = "0b01";
        for (unsigned i = 5510; i < 5515 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5515] = "0b11";
        for (unsigned i = 5516; i < 5524 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5524] = "0b11";
        for (unsigned i = 5525; i < 5550 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5550] = "0b11";
        for (unsigned i = 5551; i < 5644 ; i = i + 1) {
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
        ram[5652] = "0b01";
        ram[5653] = "0b01";
        for (unsigned i = 5654; i < 5659 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5659] = "0b01";
        for (unsigned i = 5660; i < 5679 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5679] = "0b11";
        for (unsigned i = 5680; i < 5721 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5721] = "0b11";
        for (unsigned i = 5722; i < 5802 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5802] = "0b11";
        for (unsigned i = 5803; i < 5818 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5818] = "0b01";
        ram[5819] = "0b00";
        ram[5820] = "0b00";
        ram[5821] = "0b01";
        ram[5822] = "0b00";
        ram[5823] = "0b01";
        for (unsigned i = 5824; i < 5837 ; i = i + 1) {
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
        ram[5848] = "0b00";
        ram[5849] = "0b00";
        ram[5850] = "0b00";
        ram[5851] = "0b11";
        for (unsigned i = 5852; i < 5877 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5877] = "0b11";
        for (unsigned i = 5878; i < 5891 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5891] = "0b11";
        for (unsigned i = 5892; i < 5956 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5956] = "0b01";
        for (unsigned i = 5957; i < 5992 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[5992] = "0b01";
        ram[5993] = "0b11";
        for (unsigned i = 5994; i < 6043 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6043] = "0b11";
        ram[6044] = "0b00";
        ram[6045] = "0b00";
        ram[6046] = "0b00";
        ram[6047] = "0b00";
        ram[6048] = "0b11";
        ram[6049] = "0b11";
        ram[6050] = "0b11";
        for (unsigned i = 6051; i < 6057 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6057] = "0b01";
        for (unsigned i = 6058; i < 6065 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6065] = "0b01";
        for (unsigned i = 6066; i < 6087 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6087] = "0b11";
        for (unsigned i = 6088; i < 6097 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6097] = "0b11";
        ram[6098] = "0b00";
        ram[6099] = "0b00";
        ram[6100] = "0b00";
        ram[6101] = "0b01";
        for (unsigned i = 6102; i < 6110 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6110] = "0b01";
        ram[6111] = "0b00";
        ram[6112] = "0b00";
        ram[6113] = "0b00";
        ram[6114] = "0b00";
        ram[6115] = "0b11";
        ram[6116] = "0b00";
        ram[6117] = "0b11";
        ram[6118] = "0b00";
        ram[6119] = "0b11";
        for (unsigned i = 6120; i < 6131 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6131] = "0b01";
        for (unsigned i = 6132; i < 6141 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6141] = "0b11";
        for (unsigned i = 6142; i < 6155 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6155] = "0b01";
        ram[6156] = "0b00";
        ram[6157] = "0b00";
        ram[6158] = "0b00";
        ram[6159] = "0b01";
        ram[6160] = "0b00";
        ram[6161] = "0b01";
        for (unsigned i = 6162; i < 6246 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6246] = "0b01";
        ram[6247] = "0b00";
        ram[6248] = "0b11";
        for (unsigned i = 6249; i < 6260 ; i = i + 1) {
            ram[i] = "0b00";
        }
        ram[6260] = "0b11";
        ram[6261] = "0b00";
        ram[6262] = "0b00";
        ram[6263] = "0b00";
        ram[6264] = "0b11";
        for (unsigned i = 6265; i < 6272 ; i = i + 1) {
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


SC_MODULE(mlp_accel_4b_weights_l1_4b_4) {


static const unsigned DataWidth = 2;
static const unsigned AddressRange = 6272;
static const unsigned AddressWidth = 13;

sc_core::sc_in <sc_lv<AddressWidth> > address0;
sc_core::sc_in<sc_logic> ce0;
sc_core::sc_out <sc_lv<DataWidth> > q0;
sc_core::sc_in<sc_logic> reset;
sc_core::sc_in<bool> clk;


mlp_accel_4b_weights_l1_4b_4_ram* meminst;


SC_CTOR(mlp_accel_4b_weights_l1_4b_4) {
meminst = new mlp_accel_4b_weights_l1_4b_4_ram("mlp_accel_4b_weights_l1_4b_4_ram");
meminst->address0(address0);
meminst->ce0(ce0);
meminst->q0(q0);

meminst->reset(reset);
meminst->clk(clk);
}
~mlp_accel_4b_weights_l1_4b_4() {
    delete meminst;
}


};//endmodule
#endif
