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

entity mlp_accel_4b_weights_l2_4b_2_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_2_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "001", 1 to 7=> "000", 8 to 10=> "001", 11 => "111", 12 to 18=> "000", 19 => "001", 
    20 to 36=> "000", 37 => "001", 38 to 48=> "000", 49 => "001", 50 to 53=> "000", 54 => "001", 
    55 => "000", 56 to 57=> "001", 58 to 61=> "000", 62 => "001", 63 => "000", 64 => "001", 
    65 => "000", 66 => "111", 67 to 71=> "000", 72 => "001", 73 => "000", 74 => "001", 
    75 to 76=> "000", 77 => "111", 78 to 82=> "000", 83 => "001", 84 to 87=> "000", 88 => "001", 
    89 to 90=> "000", 91 => "111", 92 to 93=> "000", 94 => "001", 95 to 106=> "000", 107 => "001", 
    108 to 138=> "000", 139 => "111", 140 to 143=> "000", 144 => "001", 145 to 154=> "000", 155 => "001", 
    156 to 162=> "000", 163 => "111", 164 => "000", 165 => "111", 166 to 168=> "000", 169 => "001", 
    170 to 172=> "000", 173 => "111", 174 => "001", 175 to 180=> "000", 181 => "001", 182 to 191=> "000", 
    192 => "001", 193 to 194=> "000", 195 => "001", 196 => "000", 197 => "111", 198 to 199=> "000", 
    200 => "111", 201 to 202=> "000", 203 => "111", 204 => "000", 205 => "001", 206 to 210=> "000", 
    211 => "001", 212 to 233=> "000", 234 => "001", 235 to 236=> "000", 237 => "001", 238 to 239=> "000", 
    240 => "001", 241 to 255=> "000", 256 => "111", 257 to 258=> "000", 259 => "111", 260 to 263=> "000", 
    264 => "111", 265 to 266=> "000", 267 => "111", 268 to 274=> "000", 275 => "001", 276 to 279=> "000", 
    280 => "001", 281 to 282=> "000", 283 => "001", 284 => "000", 285 => "111", 286 to 289=> "000", 
    290 => "001", 291 => "111", 292 to 295=> "000", 296 => "111", 297 => "000", 298 => "001", 
    299 => "111", 300 to 304=> "000", 305 => "001", 306 => "000", 307 => "001", 308 to 311=> "000", 
    312 => "001", 313 to 314=> "000", 315 => "001", 316 => "000", 317 => "111", 318 to 319=> "000", 
    320 => "001", 321 to 322=> "000", 323 => "001", 324 to 328=> "000", 329 => "111", 330 => "000", 
    331 => "001", 332 to 333=> "000", 334 => "111", 335 to 345=> "000", 346 => "001", 347 to 351=> "000", 
    352 => "111", 353 to 356=> "000", 357 => "001", 358 to 359=> "000", 360 => "111", 361 to 367=> "000", 
    368 => "001", 369 => "000", 370 => "111", 371 => "001", 372 => "000", 373 => "111", 
    374 to 378=> "000", 379 => "001", 380 to 381=> "000", 382 => "111", 383 to 386=> "000", 387 => "111", 
    388 to 394=> "000", 395 => "111", 396 to 399=> "000", 400 => "001", 401 to 415=> "000", 416 => "111", 
    417 => "000", 418 => "001", 419 to 420=> "000", 421 => "001", 422 to 423=> "000", 424 => "111", 
    425 to 428=> "000", 429 => "001", 430 to 438=> "000", 439 => "001", 440 to 442=> "000", 443 => "111", 
    444 to 450=> "000", 451 => "001", 452 to 458=> "000", 459 => "001", 460 => "000", 461 => "001", 
    462 to 466=> "000", 467 => "001", 468 => "000", 469 => "111", 470 to 471=> "000", 472 => "001", 
    473 => "000", 474 => "111", 475 => "001", 476 => "000", 477 => "111", 478 => "000", 
    479 => "001", 480 to 482=> "000", 483 => "111", 484 => "000", 485 => "001", 486 to 495=> "000", 
    496 => "010", 497 to 503=> "000", 504 => "111", 505 to 511=> "000" );


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

entity mlp_accel_4b_weights_l2_4b_2 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_2 is
    component mlp_accel_4b_weights_l2_4b_2_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_2_rom_U :  component mlp_accel_4b_weights_l2_4b_2_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


