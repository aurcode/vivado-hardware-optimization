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

entity mlp_accel_4b_weights_l2_4b_5_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_5_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 3=> "000", 4 to 5=> "111", 6 to 8=> "000", 9 => "001", 10 => "000", 11 to 13=> "001", 
    14 to 16=> "000", 17 => "111", 18 to 19=> "000", 20 => "111", 21 => "000", 22 => "001", 
    23 to 25=> "000", 26 => "001", 27 => "000", 28 => "010", 29 to 30=> "000", 31 => "001", 
    32 to 35=> "000", 36 to 37=> "001", 38 to 40=> "000", 41 to 43=> "111", 44 => "000", 45 => "001", 
    46 to 49=> "000", 50 => "001", 51 to 56=> "000", 57 => "001", 58 to 60=> "000", 61 => "111", 
    62 to 64=> "000", 65 => "001", 66 => "000", 67 => "001", 68 to 73=> "000", 74 => "111", 
    75 => "000", 76 => "111", 77 to 82=> "000", 83 => "001", 84 => "000", 85 => "111", 
    86 to 89=> "000", 90 => "001", 91 => "111", 92 to 93=> "001", 94 to 110=> "000", 111 => "001", 
    112 to 115=> "000", 116 to 117=> "001", 118 to 121=> "000", 122 => "001", 123 to 124=> "000", 125 => "001", 
    126 to 136=> "000", 137 => "001", 138 => "111", 139 to 144=> "000", 145 => "111", 146 => "000", 
    147 to 148=> "111", 149 to 150=> "000", 151 => "001", 152 to 155=> "000", 156 => "111", 157 => "000", 
    158 to 159=> "001", 160 to 163=> "000", 164 to 165=> "001", 166 to 168=> "000", 169 => "001", 170 to 173=> "000", 
    174 => "001", 175 => "000", 176 => "001", 177 to 181=> "000", 182 to 183=> "111", 184 to 193=> "000", 
    194 => "111", 195 => "001", 196 => "000", 197 => "111", 198 to 199=> "001", 200 to 203=> "000", 
    204 to 205=> "001", 206 to 211=> "000", 212 => "111", 213 => "000", 214 => "001", 215 to 217=> "000", 
    218 => "001", 219 to 220=> "000", 221 => "111", 222 to 223=> "001", 224 to 235=> "000", 236 to 237=> "111", 
    238 to 241=> "000", 242 => "001", 243 to 244=> "000", 245 => "001", 246 => "000", 247 => "001", 
    248 to 250=> "000", 251 => "001", 252 => "000", 253 => "001", 254 to 256=> "000", 257 => "111", 
    258 to 267=> "000", 268 => "001", 269 => "000", 270 => "001", 271 to 273=> "000", 274 => "111", 
    275 => "000", 276 => "111", 277 to 281=> "000", 282 => "001", 283 to 298=> "000", 299 => "001", 
    300 to 301=> "000", 302 => "001", 303 to 304=> "000", 305 => "001", 306 => "111", 307 => "000", 
    308 => "111", 309 to 312=> "000", 313 => "001", 314 => "111", 315 => "001", 316 to 317=> "111", 
    318 to 320=> "000", 321 => "001", 322 to 328=> "000", 329 => "111", 330 to 331=> "000", 332 to 333=> "111", 
    334 => "000", 335 => "111", 336 to 345=> "000", 346 => "001", 347 to 348=> "000", 349 => "111", 
    350 to 365=> "000", 366 => "001", 367 to 369=> "000", 370 to 372=> "001", 373 to 378=> "000", 379 => "001", 
    380 => "000", 381 => "001", 382 to 385=> "000", 386 => "001", 387 => "000", 388 to 389=> "001", 
    390 to 395=> "000", 396 => "001", 397 to 401=> "000", 402 => "111", 403 => "000", 404 to 405=> "111", 
    406 to 420=> "000", 421 => "111", 422 to 425=> "000", 426 => "001", 427 => "000", 428 => "001", 
    429 to 433=> "000", 434 => "001", 435 => "000", 436 => "001", 437 => "010", 438 to 442=> "000", 
    443 => "111", 444 to 446=> "000", 447 => "001", 448 to 451=> "000", 452 => "111", 453 to 462=> "000", 
    463 => "111", 464 to 468=> "000", 469 => "001", 470 => "111", 471 to 472=> "000", 473 to 476=> "001", 
    477 to 482=> "000", 483 => "111", 484 to 500=> "000", 501 => "001", 502 to 505=> "000", 506 => "111", 
    507 to 508=> "000", 509 => "111", 510 => "001", 511 => "000" );


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

entity mlp_accel_4b_weights_l2_4b_5 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_5 is
    component mlp_accel_4b_weights_l2_4b_5_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_5_rom_U :  component mlp_accel_4b_weights_l2_4b_5_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


