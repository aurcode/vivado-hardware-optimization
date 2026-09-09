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

entity mlp_accel_4b_weights_l2_4b_8_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_8_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 1=> "000", 2 => "001", 3 to 5=> "000", 6 => "001", 7 to 13=> "000", 14 => "001", 
    15 to 17=> "000", 18 => "111", 19 to 23=> "000", 24 => "001", 25 => "000", 26 => "111", 
    27 to 33=> "000", 34 => "111", 35 to 41=> "000", 42 => "111", 43 => "000", 44 => "001", 
    45 to 47=> "000", 48 to 49=> "111", 50 to 53=> "000", 54 => "001", 55 to 57=> "000", 58 => "001", 
    59 to 65=> "000", 66 => "001", 67 to 71=> "000", 72 => "001", 73 => "000", 74 => "001", 
    75 to 84=> "000", 85 => "111", 86 to 87=> "000", 88 => "111", 89 => "000", 90 to 91=> "001", 
    92 => "000", 93 => "001", 94 to 97=> "000", 98 => "001", 99 to 100=> "000", 101 => "111", 
    102 to 103=> "000", 104 => "001", 105 to 108=> "000", 109 => "111", 110 to 112=> "000", 113 => "010", 
    114 to 115=> "001", 116 => "000", 117 => "001", 118 to 120=> "000", 121 => "001", 122 => "000", 
    123 => "001", 124 to 145=> "000", 146 to 147=> "001", 148 => "000", 149 => "001", 150 to 152=> "000", 
    153 => "001", 154 => "000", 155 => "001", 156 => "000", 157 => "001", 158 to 160=> "000", 
    161 to 162=> "001", 163 to 164=> "000", 165 => "010", 166 to 168=> "000", 169 to 170=> "001", 171 to 176=> "000", 
    177 to 179=> "111", 180 to 191=> "000", 192 to 193=> "001", 194 to 200=> "000", 201 => "001", 202 to 212=> "000", 
    213 => "001", 214 to 215=> "000", 216 => "111", 217 => "000", 218 => "001", 219 to 220=> "000", 
    221 => "001", 222 => "000", 223 => "001", 224 to 232=> "000", 233 => "001", 234 to 235=> "000", 
    236 => "001", 237 => "000", 238 to 239=> "001", 240 to 242=> "000", 243 => "001", 244 => "000", 
    245 => "001", 246 to 249=> "000", 250 => "001", 251 to 252=> "000", 253 => "001", 254 to 256=> "000", 
    257 to 258=> "001", 259 to 260=> "000", 261 => "001", 262 to 264=> "000", 265 => "001", 266 => "000", 
    267 => "111", 268 => "000", 269 => "001", 270 to 271=> "000", 272 => "001", 273 to 280=> "000", 
    281 => "111", 282 to 287=> "000", 288 => "001", 289 => "111", 290 to 292=> "000", 293 => "111", 
    294 => "001", 295 => "000", 296 to 298=> "001", 299 to 304=> "000", 305 to 306=> "111", 307 to 308=> "000", 
    309 => "111", 310 to 313=> "000", 314 to 315=> "001", 316 to 320=> "000", 321 => "111", 322 to 323=> "000", 
    324 to 325=> "111", 326 => "001", 327 to 329=> "000", 330 => "111", 331 to 332=> "000", 333 to 334=> "111", 
    335 to 344=> "000", 345 => "111", 346 => "000", 347 => "111", 348 => "001", 349 => "111", 
    350 => "001", 351 to 353=> "000", 354 => "111", 355 to 360=> "000", 361 => "001", 362 => "000", 
    363 => "001", 364 to 370=> "000", 371 => "111", 372 to 379=> "000", 380 to 381=> "111", 382 to 386=> "000", 
    387 to 388=> "001", 389 to 395=> "000", 396 to 397=> "001", 398 to 399=> "000", 400 => "001", 401 to 404=> "000", 
    405 => "111", 406 => "001", 407 to 415=> "000", 416 => "001", 417 to 419=> "000", 420 => "001", 
    421 to 422=> "000", 423 to 424=> "001", 425 to 426=> "111", 427 to 428=> "000", 429 => "111", 430 to 432=> "000", 
    433 to 434=> "001", 435 => "111", 436 => "000", 437 => "001", 438 to 444=> "000", 445 => "001", 
    446 to 447=> "000", 448 to 449=> "001", 450 to 457=> "000", 458 => "111", 459 to 460=> "000", 461 => "111", 
    462 to 468=> "000", 469 => "001", 470 to 473=> "000", 474 => "001", 475 => "000", 476 => "111", 
    477 to 480=> "000", 481 => "111", 482 to 483=> "000", 484 => "001", 485 to 497=> "000", 498 => "001", 
    499 to 503=> "000", 504 to 505=> "001", 506 to 510=> "000", 511 => "001" );


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

entity mlp_accel_4b_weights_l2_4b_8 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_8 is
    component mlp_accel_4b_weights_l2_4b_8_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_8_rom_U :  component mlp_accel_4b_weights_l2_4b_8_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


