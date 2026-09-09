-- ==============================================================
-- File generated on Wed Sep 02 16:33:45 +0000 2026
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity mlp_accel_4b_weights_l2_4b_1_rom is 
    generic(
             DWIDTH     : integer := 3; 
             AWIDTH     : integer := 9; 
             MEM_SIZE    : integer := 512
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of mlp_accel_4b_weights_l2_4b_1_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "001", 1 => "000", 2 => "111", 3 to 5=> "000", 6 => "001", 7 to 8=> "000", 
    9 => "111", 10 to 15=> "001", 16 => "000", 17 => "001", 18 to 19=> "000", 20 => "111", 
    21 => "001", 22 to 26=> "000", 27 to 28=> "001", 29 to 30=> "000", 31 => "001", 32 to 34=> "000", 
    35 to 36=> "001", 37 to 40=> "000", 41 => "001", 42 to 46=> "000", 47 => "111", 48 to 52=> "000", 
    53 => "111", 54 => "001", 55 to 56=> "000", 57 => "111", 58 => "000", 59 => "111", 
    60 to 62=> "000", 63 => "001", 64 => "000", 65 => "111", 66 to 70=> "000", 71 => "001", 
    72 to 73=> "000", 74 => "111", 75 to 79=> "000", 80 => "001", 81 to 89=> "000", 90 => "001", 
    91 => "111", 92 to 95=> "000", 96 to 97=> "111", 98 to 100=> "000", 101 => "001", 102 => "000", 
    103 => "001", 104 to 105=> "000", 106 => "111", 107 to 112=> "000", 113 => "111", 114 to 116=> "000", 
    117 => "010", 118 to 119=> "000", 120 => "111", 121 to 124=> "000", 125 => "001", 126 to 136=> "000", 
    137 => "110", 138 to 140=> "000", 141 => "001", 142 => "000", 143 => "001", 144 => "000", 
    145 => "001", 146 => "111", 147 to 153=> "000", 154 to 155=> "111", 156 to 160=> "000", 161 => "111", 
    162 => "001", 163 to 164=> "000", 165 => "001", 166 to 168=> "000", 169 => "111", 170 => "000", 
    171 => "111", 172 to 174=> "000", 175 to 176=> "001", 177 => "111", 178 to 180=> "000", 181 => "111", 
    182 to 194=> "000", 195 => "111", 196 to 198=> "000", 199 => "001", 200 => "000", 201 to 203=> "001", 
    204 => "000", 205 => "001", 206 to 207=> "000", 208 => "111", 209 to 210=> "000", 211 => "111", 
    212 to 213=> "000", 214 => "111", 215 to 218=> "000", 219 to 221=> "111", 222 to 233=> "000", 234 to 235=> "111", 
    236 => "000", 237 => "111", 238 to 244=> "000", 245 => "001", 246 to 247=> "000", 248 => "111", 
    249 to 250=> "000", 251 => "001", 252 to 255=> "000", 256 => "111", 257 to 259=> "000", 260 => "111", 
    261 => "001", 262 to 263=> "111", 264 to 268=> "000", 269 => "001", 270 to 271=> "000", 272 => "001", 
    273 => "000", 274 => "111", 275 to 288=> "000", 289 => "001", 290 => "000", 291 => "001", 
    292 to 306=> "000", 307 => "001", 308 to 309=> "000", 310 to 311=> "001", 312 to 314=> "000", 315 => "001", 
    316 to 323=> "000", 324 => "001", 325 => "000", 326 => "001", 327 to 343=> "000", 344 to 345=> "001", 
    346 => "111", 347 to 348=> "000", 349 => "110", 350 => "000", 351 => "111", 352 => "001", 
    353 => "010", 354 => "000", 355 => "001", 356 to 358=> "000", 359 => "111", 360 to 361=> "000", 
    362 => "001", 363 to 364=> "000", 365 => "001", 366 to 370=> "000", 371 => "001", 372 to 374=> "000", 
    375 to 376=> "001", 377 to 378=> "000", 379 to 380=> "001", 381 => "000", 382 => "001", 383 to 384=> "000", 
    385 to 386=> "001", 387 to 392=> "000", 393 => "110", 394 to 396=> "000", 397 => "001", 398 => "000", 
    399 => "001", 400 to 404=> "000", 405 => "111", 406 to 418=> "000", 419 => "111", 420 => "000", 
    421 => "111", 422 => "001", 423 to 424=> "000", 425 to 428=> "001", 429 to 431=> "000", 432 => "111", 
    433 => "000", 434 to 435=> "001", 436 => "000", 437 => "001", 438 => "000", 439 => "001", 
    440 => "000", 441 => "001", 442 => "000", 443 => "111", 444 => "000", 445 => "111", 
    446 to 448=> "000", 449 => "001", 450 => "111", 451 to 456=> "000", 457 to 459=> "001", 460 to 463=> "000", 
    464 => "111", 465 to 467=> "001", 468 to 473=> "000", 474 to 477=> "001", 478 => "000", 479 => "001", 
    480 => "000", 481 => "001", 482 => "000", 483 => "001", 484 => "000", 485 => "111", 
    486 => "000", 487 => "111", 488 to 496=> "000", 497 => "111", 498 => "000", 499 to 501=> "001", 
    502 to 504=> "000", 505 => "001", 506 to 511=> "000" );


begin 


memory_access_guard_0: process (addr0) 
begin
      addr0_tmp <= addr0;
--synthesis translate_off
      if (CONV_INTEGER(addr0) > mem_size-1) then
           addr0_tmp <= (others => '0');
      else 
           addr0_tmp <= addr0;
      end if;
--synthesis translate_on
end process;

p_rom_access: process (clk)  
begin 
    if (clk'event and clk = '1') then
        if (ce0 = '1') then 
            q0 <= mem(CONV_INTEGER(addr0_tmp)); 
        end if;
    end if;
end process;

end rtl;

Library IEEE;
use IEEE.std_logic_1164.all;

entity mlp_accel_4b_weights_l2_4b_1 is
    generic (
        DataWidth : INTEGER := 3;
        AddressRange : INTEGER := 512;
        AddressWidth : INTEGER := 9);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of mlp_accel_4b_weights_l2_4b_1 is
    component mlp_accel_4b_weights_l2_4b_1_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_1_rom_U :  component mlp_accel_4b_weights_l2_4b_1_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


