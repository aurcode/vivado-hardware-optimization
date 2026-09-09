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

entity mlp_accel_4b_weights_l2_4b_10_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_10_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "110", 1 => "000", 2 to 3=> "111", 4 to 6=> "000", 7 => "111", 8 to 9=> "001", 
    10 => "111", 11 to 17=> "000", 18 => "001", 19 to 29=> "000", 30 to 31=> "111", 32 to 37=> "000", 
    38 => "001", 39 to 40=> "111", 41 => "000", 42 to 43=> "001", 44 to 45=> "000", 46 => "001", 
    47 => "111", 48 to 49=> "000", 50 => "111", 51 to 53=> "000", 54 => "111", 55 to 57=> "000", 
    58 => "111", 59 to 61=> "000", 62 => "111", 63 to 65=> "000", 66 to 67=> "111", 68 to 71=> "000", 
    72 => "010", 73 => "000", 74 to 75=> "001", 76 to 77=> "000", 78 => "001", 79 => "010", 
    80 to 81=> "000", 82 => "001", 83 => "111", 84 => "000", 85 => "001", 86 => "111", 
    87 to 89=> "000", 90 => "111", 91 to 94=> "000", 95 => "111", 96 => "010", 97 => "000", 
    98 => "111", 99 => "001", 100 to 101=> "000", 102 => "111", 103 to 110=> "000", 111 => "001", 
    112 to 119=> "000", 120 => "111", 121 to 126=> "000", 127 => "111", 128 to 139=> "000", 140 => "001", 
    141 => "000", 142 => "001", 143 to 146=> "000", 147 => "001", 148 to 151=> "000", 152 => "111", 
    153 to 159=> "000", 160 => "111", 161 => "000", 162 => "001", 163 => "111", 164 to 165=> "000", 
    166 => "001", 167 => "000", 168 => "001", 169 => "000", 170 => "111", 171 to 177=> "000", 
    178 => "001", 179 => "111", 180 to 181=> "000", 182 => "001", 183 to 191=> "000", 192 to 194=> "001", 
    195 to 198=> "000", 199 => "001", 200 to 201=> "000", 202 => "001", 203 to 205=> "000", 206 => "001", 
    207 => "000", 208 => "001", 209 to 210=> "000", 211 => "001", 212 to 214=> "000", 215 => "001", 
    216 => "111", 217 => "000", 218 => "111", 219 => "001", 220 to 221=> "000", 222 => "111", 
    223 => "001", 224 to 231=> "000", 232 => "111", 233 => "000", 234 => "111", 235 to 239=> "000", 
    240 => "111", 241 => "000", 242 => "111", 243 to 246=> "000", 247 => "111", 248 => "001", 
    249 => "000", 250 => "001", 251 to 253=> "000", 254 => "010", 255 to 261=> "000", 262 => "001", 
    263 to 270=> "000", 271 => "001", 272 => "111", 273 to 278=> "000", 279 => "111", 280 => "001", 
    281 to 282=> "000", 283 => "001", 284 to 285=> "111", 286 => "000", 287 to 288=> "001", 289 to 290=> "000", 
    291 => "001", 292 to 294=> "000", 295 => "001", 296 to 298=> "000", 299 => "001", 300 to 302=> "000", 
    303 to 304=> "001", 305 to 314=> "000", 315 => "111", 316 to 328=> "000", 329 => "111", 330 => "001", 
    331 to 351=> "000", 352 => "111", 353 => "000", 354 => "001", 355 to 358=> "000", 359 => "111", 
    360 to 366=> "000", 367 => "111", 368 => "001", 369 to 370=> "000", 371 to 372=> "111", 373 to 375=> "000", 
    376 => "111", 377 to 378=> "000", 379 => "111", 380 to 383=> "000", 384 => "001", 385 to 386=> "000", 
    387 to 388=> "001", 389 to 399=> "000", 400 => "111", 401 to 402=> "000", 403 => "111", 404 to 405=> "000", 
    406 to 407=> "001", 408 to 415=> "000", 416 => "111", 417 to 418=> "000", 419 => "001", 420 => "000", 
    421 => "001", 422 => "111", 423 to 424=> "001", 425 => "000", 426 => "001", 427 => "000", 
    428 => "111", 429 => "000", 430 => "111", 431 => "000", 432 => "001", 433 => "000", 
    434 => "001", 435 to 437=> "000", 438 => "001", 439 to 441=> "000", 442 => "111", 443 => "001", 
    444 to 445=> "000", 446 => "111", 447 => "001", 448 => "111", 449 to 454=> "000", 455 => "111", 
    456 to 457=> "000", 458 => "001", 459 to 462=> "000", 463 => "111", 464 => "001", 465 => "000", 
    466 => "001", 467 to 469=> "000", 470 => "001", 471 => "000", 472 => "001", 473 to 474=> "000", 
    475 => "111", 476 to 478=> "000", 479 => "001", 480 to 481=> "000", 482 => "001", 483 to 485=> "000", 
    486 => "001", 487 to 496=> "000", 497 to 498=> "001", 499 to 501=> "000", 502 => "001", 503 => "000", 
    504 => "111", 505 to 510=> "000", 511 => "001" );


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

entity mlp_accel_4b_weights_l2_4b_10 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_10 is
    component mlp_accel_4b_weights_l2_4b_10_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_10_rom_U :  component mlp_accel_4b_weights_l2_4b_10_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


