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

entity mlp_accel_4b_weights_l2_4b_4_rom is 
    generic(
             DWIDTH     : integer := 2; 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_4_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 2=> "00", 3 to 4=> "01", 5 to 11=> "00", 12 => "01", 13 to 14=> "00", 15 => "01", 
    16 to 21=> "00", 22 => "01", 23 to 29=> "00", 30 => "11", 31 to 37=> "00", 38 => "11", 
    39 => "00", 40 => "11", 41 to 51=> "00", 52 => "01", 53 to 54=> "00", 55 => "01", 
    56 => "00", 57 => "01", 58 to 59=> "00", 60 => "01", 61 to 64=> "00", 65 => "01", 
    66 to 69=> "00", 70 => "11", 71 => "01", 72 to 77=> "00", 78 => "01", 79 to 83=> "00", 
    84 => "11", 85 => "00", 86 => "11", 87 => "01", 88 to 90=> "00", 91 to 92=> "01", 
    93 to 101=> "00", 102 => "01", 103 to 104=> "00", 105 => "01", 106 to 110=> "00", 111 to 112=> "01", 
    113 to 114=> "00", 115 to 117=> "01", 118 to 124=> "00", 125 => "01", 126 to 140=> "00", 141 => "01", 
    142 to 146=> "00", 147 => "01", 148 => "00", 149 => "11", 150 => "01", 151 => "00", 
    152 => "01", 153 to 157=> "00", 158 => "01", 159 to 164=> "00", 165 => "01", 166 => "10", 
    167 to 172=> "00", 173 => "01", 174 to 181=> "00", 182 => "11", 183 to 191=> "00", 192 => "01", 
    193 to 197=> "00", 198 => "01", 199 to 200=> "00", 201 to 202=> "11", 203 to 213=> "00", 214 => "01", 
    215 => "00", 216 to 218=> "01", 219 => "00", 220 => "01", 221 to 234=> "00", 235 to 236=> "01", 
    237 => "00", 238 => "01", 239 to 241=> "00", 242 to 244=> "01", 245 => "11", 246 to 248=> "00", 
    249 => "11", 250 => "00", 251 => "01", 252 => "11", 253 => "00", 254 => "11", 
    255 to 261=> "00", 262 => "11", 263 to 286=> "00", 287 => "01", 288 to 294=> "00", 295 => "01", 
    296 to 298=> "00", 299 => "01", 300 to 310=> "00", 311 => "01", 312 => "00", 313 => "01", 
    314 to 318=> "00", 319 => "01", 320 to 326=> "00", 327 => "01", 328 to 333=> "00", 334 => "01", 
    335 to 343=> "00", 344 => "11", 345 => "01", 346 to 359=> "00", 360 => "01", 361 => "11", 
    362 to 364=> "00", 365 to 366=> "01", 367 to 373=> "00", 374 => "11", 375 to 387=> "00", 388 => "01", 
    389 to 400=> "00", 401 => "01", 402 to 417=> "00", 418 to 419=> "01", 420 => "00", 421 to 423=> "01", 
    424 => "00", 425 => "01", 426 to 427=> "00", 428 => "11", 429 to 433=> "00", 434 => "11", 
    435 to 437=> "00", 438 => "11", 439 to 445=> "00", 446 => "01", 447 to 457=> "00", 458 => "11", 
    459 => "00", 460 => "11", 461 to 467=> "00", 468 => "11", 469 => "00", 470 => "11", 
    471 to 472=> "00", 473 => "01", 474 to 477=> "00", 478 => "11", 479 => "00", 480 => "11", 
    481 to 501=> "00", 502 => "11", 503 to 508=> "00", 509 => "01", 510 to 511=> "00" );


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

entity mlp_accel_4b_weights_l2_4b_4 is
    generic (
        DataWidth : INTEGER := 2;
        AddressRange : INTEGER := 512;
        AddressWidth : INTEGER := 9);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of mlp_accel_4b_weights_l2_4b_4 is
    component mlp_accel_4b_weights_l2_4b_4_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_4_rom_U :  component mlp_accel_4b_weights_l2_4b_4_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


