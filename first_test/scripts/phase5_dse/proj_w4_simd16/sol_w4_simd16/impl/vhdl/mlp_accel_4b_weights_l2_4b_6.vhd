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

entity mlp_accel_4b_weights_l2_4b_6_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_6_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 3=> "000", 4 => "110", 5 => "000", 6 => "001", 7 to 10=> "000", 11 => "001", 
    12 to 15=> "000", 16 => "001", 17 to 25=> "000", 26 => "111", 27 => "000", 28 => "001", 
    29 to 53=> "000", 54 to 55=> "001", 56 to 59=> "000", 60 => "111", 61 to 63=> "000", 64 => "111", 
    65 to 75=> "000", 76 => "001", 77 to 93=> "000", 94 to 95=> "001", 96 to 98=> "000", 99 to 100=> "001", 
    101 to 107=> "000", 108 => "001", 109 to 111=> "000", 112 => "001", 113 to 114=> "000", 115 => "001", 
    116 to 122=> "000", 123 => "001", 124 to 138=> "000", 139 => "001", 140 to 151=> "000", 152 to 153=> "001", 
    154 to 155=> "000", 156 => "111", 157 to 158=> "000", 159 => "111", 160 => "000", 161 => "001", 
    162 to 163=> "000", 164 => "111", 165 to 168=> "000", 169 => "001", 170 to 176=> "000", 177 => "111", 
    178 => "001", 179 => "000", 180 => "001", 181 to 191=> "000", 192 to 193=> "001", 194 to 195=> "000", 
    196 => "001", 197 => "000", 198 to 199=> "111", 200 to 202=> "000", 203 to 204=> "001", 205 to 207=> "000", 
    208 to 209=> "001", 210 to 211=> "000", 212 => "001", 213 to 216=> "000", 217 => "001", 218 to 219=> "000", 
    220 => "111", 221 to 231=> "000", 232 => "001", 233 to 234=> "000", 235 => "001", 236 => "111", 
    237 => "001", 238 to 243=> "000", 244 => "110", 245 to 247=> "000", 248 => "111", 249 => "001", 
    250 => "000", 251 to 252=> "001", 253 to 257=> "000", 258 => "001", 259 to 260=> "000", 261 => "001", 
    262 to 268=> "000", 269 => "001", 270 => "000", 271 to 272=> "001", 273 to 275=> "000", 276 => "110", 
    277 to 278=> "000", 279 => "111", 280 to 283=> "000", 284 => "010", 285 => "111", 286 => "001", 
    287 => "000", 288 => "111", 289 => "001", 290 => "000", 291 to 292=> "001", 293 to 296=> "000", 
    297 => "001", 298 to 300=> "000", 301 => "001", 302 to 307=> "000", 308 => "001", 309 to 310=> "000", 
    311 => "001", 312 to 315=> "000", 316 to 317=> "111", 318 => "000", 319 => "111", 320 to 324=> "000", 
    325 => "111", 326 to 327=> "000", 328 => "001", 329 to 330=> "000", 331 to 332=> "111", 333 => "000", 
    334 => "111", 335 to 348=> "000", 349 to 350=> "001", 351 => "000", 352 => "001", 353 to 358=> "000", 
    359 to 360=> "001", 361 to 363=> "000", 364 => "111", 365 to 367=> "000", 368 => "111", 369 to 371=> "000", 
    372 => "001", 373 to 380=> "000", 381 => "111", 382 to 387=> "000", 388 => "001", 389 to 390=> "000", 
    391 => "001", 392 to 398=> "000", 399 => "001", 400 to 403=> "000", 404 => "111", 405 to 406=> "000", 
    407 => "111", 408 to 420=> "000", 421 => "001", 422 => "000", 423 => "001", 424 to 427=> "000", 
    428 => "001", 429 to 430=> "000", 431 => "001", 432 => "111", 433 to 435=> "000", 436 => "001", 
    437 to 443=> "000", 444 to 448=> "001", 449 to 451=> "000", 452 => "110", 453 to 456=> "000", 457 => "111", 
    458 to 463=> "000", 464 => "111", 465 to 467=> "000", 468 => "001", 469 to 470=> "000", 471 => "001", 
    472 => "111", 473 to 485=> "000", 486 to 487=> "001", 488 to 497=> "000", 498 to 499=> "001", 500 to 502=> "000", 
    503 => "111", 504 to 507=> "000", 508 => "111", 509 => "001", 510 to 511=> "000" );


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

entity mlp_accel_4b_weights_l2_4b_6 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_6 is
    component mlp_accel_4b_weights_l2_4b_6_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_6_rom_U :  component mlp_accel_4b_weights_l2_4b_6_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


