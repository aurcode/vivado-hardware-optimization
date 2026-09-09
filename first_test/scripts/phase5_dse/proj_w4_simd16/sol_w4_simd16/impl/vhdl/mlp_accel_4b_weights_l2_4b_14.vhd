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

entity mlp_accel_4b_weights_l2_4b_14_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_14_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 11=> "000", 12 => "001", 13 => "111", 14 to 15=> "001", 16 to 20=> "000", 21 => "001", 
    22 to 23=> "000", 24 => "110", 25 to 26=> "000", 27 to 28=> "001", 29 => "000", 30 => "001", 
    31 to 32=> "000", 33 => "001", 34 to 35=> "000", 36 => "001", 37 => "000", 38 to 41=> "001", 
    42 to 44=> "000", 45 to 46=> "001", 47 to 48=> "000", 49 => "001", 50 to 51=> "000", 52 => "111", 
    53 => "001", 54 => "111", 55 to 56=> "001", 57 to 62=> "000", 63 => "001", 64 => "000", 
    65 => "001", 66 to 67=> "000", 68 => "001", 69 => "111", 70 to 71=> "000", 72 => "001", 
    73 to 76=> "000", 77 to 78=> "111", 79 => "000", 80 => "111", 81 to 82=> "000", 83 to 84=> "111", 
    85 to 88=> "000", 89 => "001", 90 to 92=> "000", 93 => "001", 94 => "000", 95 => "001", 
    96 to 98=> "000", 99 => "001", 100 => "000", 101 to 102=> "111", 103 to 107=> "000", 108 => "111", 
    109 => "000", 110 => "111", 111 => "000", 112 => "111", 113 to 115=> "000", 116 => "010", 
    117 => "000", 118 => "001", 119 => "000", 120 => "111", 121 to 124=> "000", 125 to 126=> "001", 
    127 to 135=> "000", 136 => "001", 137 to 139=> "000", 140 => "001", 141 => "110", 142 to 143=> "000", 
    144 => "001", 145 to 146=> "000", 147 => "001", 148 => "000", 149 => "001", 150 => "111", 
    151 to 155=> "000", 156 => "001", 157 to 163=> "000", 164 => "010", 165 to 166=> "001", 167 to 171=> "000", 
    172 => "001", 173 => "111", 174 to 175=> "000", 176 => "001", 177 to 179=> "000", 180 => "110", 
    181 => "111", 182 => "000", 183 => "001", 184 to 191=> "000", 192 => "111", 193 to 195=> "000", 
    196 => "001", 197 => "111", 198 to 199=> "000", 200 => "111", 201 to 204=> "000", 205 to 206=> "001", 
    207 => "000", 208 => "001", 209 to 211=> "000", 212 => "001", 213 to 214=> "000", 215 => "111", 
    216 to 219=> "000", 220 => "111", 221 => "001", 222 => "111", 223 to 235=> "000", 236 => "111", 
    237 => "001", 238 => "111", 239 to 243=> "000", 244 => "001", 245 => "010", 246 => "001", 
    247 to 251=> "000", 252 => "010", 253 => "000", 254 => "001", 255 to 259=> "000", 260 => "001", 
    261 => "010", 262 => "001", 263 to 268=> "000", 269 => "111", 270 => "000", 271 => "001", 
    272 to 280=> "000", 281 => "111", 282 => "000", 283 => "001", 284 => "111", 285 => "000", 
    286 => "111", 287 to 290=> "000", 291 => "001", 292 => "111", 293 to 296=> "000", 297 => "001", 
    298 to 300=> "000", 301 => "001", 302 to 307=> "000", 308 => "111", 309 => "110", 310 to 311=> "000", 
    312 => "001", 313 to 315=> "000", 316 => "001", 317 => "111", 318 => "000", 319 => "001", 
    320 to 323=> "000", 324 => "111", 325 to 331=> "000", 332 => "111", 333 to 334=> "000", 335 => "111", 
    336 to 343=> "000", 344 to 345=> "001", 346 to 347=> "000", 348 => "110", 349 => "001", 350 to 356=> "000", 
    357 to 358=> "001", 359 => "000", 360 => "111", 361 to 365=> "000", 366 => "001", 367 to 372=> "000", 
    373 => "111", 374 to 375=> "000", 376 => "111", 377 to 381=> "000", 382 => "001", 383 to 386=> "000", 
    387 => "001", 388 => "000", 389 => "001", 390 to 391=> "000", 392 => "111", 393 to 399=> "000", 
    400 => "001", 401 to 405=> "000", 406 => "001", 407 to 416=> "000", 417 => "001", 418 to 419=> "000", 
    420 => "110", 421 => "000", 422 => "111", 423 => "000", 424 => "111", 425 to 427=> "000", 
    428 to 429=> "111", 430 => "001", 431 => "000", 432 => "111", 433 to 435=> "000", 436 => "001", 
    437 => "000", 438 => "001", 439 => "000", 440 to 441=> "001", 442 to 443=> "000", 444 => "111", 
    445 => "000", 446 => "111", 447 to 451=> "000", 452 to 453=> "001", 454 to 458=> "000", 459 to 460=> "111", 
    461 => "000", 462 => "001", 463 to 467=> "000", 468 => "001", 469 to 471=> "000", 472 => "111", 
    473 to 475=> "000", 476 => "001", 477 => "111", 478 to 480=> "001", 481 to 499=> "000", 500 => "010", 
    501 => "000", 502 => "001", 503 to 507=> "000", 508 => "111", 509 to 511=> "000" );


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

entity mlp_accel_4b_weights_l2_4b_14 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_14 is
    component mlp_accel_4b_weights_l2_4b_14_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_14_rom_U :  component mlp_accel_4b_weights_l2_4b_14_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


