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

entity mlp_accel_4b_weights_l2_4b_9_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_9_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "01", 1 => "00", 2 => "11", 3 to 5=> "00", 6 => "11", 7 => "01", 
    8 to 17=> "00", 18 => "01", 19 to 23=> "00", 24 => "01", 25 to 26=> "00", 27 => "11", 
    28 to 29=> "00", 30 => "11", 31 => "00", 32 => "01", 33 to 40=> "00", 41 => "01", 
    42 to 47=> "00", 48 => "01", 49 to 50=> "00", 51 => "01", 52 to 58=> "00", 59 to 60=> "01", 
    61 to 69=> "00", 70 => "11", 71 => "00", 72 => "11", 73 => "00", 74 => "01", 
    75 to 77=> "00", 78 => "01", 79 to 85=> "00", 86 => "11", 87 => "00", 88 => "01", 
    89 to 91=> "00", 92 => "01", 93 => "00", 94 => "11", 95 => "00", 96 => "11", 
    97 => "00", 98 to 99=> "01", 100 to 109=> "00", 110 => "01", 111 to 115=> "00", 116 => "01", 
    117 to 123=> "00", 124 => "01", 125 to 140=> "00", 141 => "01", 142 to 146=> "00", 147 => "01", 
    148 => "00", 149 => "11", 150 to 154=> "00", 155 => "11", 156 to 162=> "00", 163 => "11", 
    164 to 167=> "00", 168 => "11", 169 => "00", 170 => "01", 171 to 173=> "00", 174 => "11", 
    175 => "00", 176 => "01", 177 to 179=> "00", 180 => "11", 181 => "00", 182 => "01", 
    183 to 191=> "00", 192 => "10", 193 => "00", 194 => "01", 195 to 201=> "00", 202 => "01", 
    203 to 204=> "00", 205 to 206=> "01", 207 => "00", 208 => "11", 209 => "00", 210 to 211=> "01", 
    212 to 215=> "00", 216 => "01", 217 to 221=> "00", 222 => "11", 223 to 231=> "00", 232 => "01", 
    233 to 236=> "00", 237 => "01", 238 to 239=> "00", 240 => "01", 241 to 243=> "00", 244 => "01", 
    245 => "00", 246 => "11", 247 to 249=> "00", 250 => "01", 251 => "00", 252 => "11", 
    253 to 254=> "00", 255 => "11", 256 => "00", 257 => "01", 258 => "00", 259 => "11", 
    260 to 271=> "00", 272 => "01", 273 => "00", 274 to 275=> "11", 276 to 278=> "00", 279 => "01", 
    280 => "11", 281 => "00", 282 to 283=> "01", 284 to 289=> "00", 290 => "01", 291 => "00", 
    292 => "11", 293 => "00", 294 to 295=> "01", 296 to 298=> "00", 299 => "11", 300 to 301=> "00", 
    302 => "01", 303 to 306=> "00", 307 => "01", 308 to 309=> "00", 310 => "01", 311 => "00", 
    312 => "11", 313 to 318=> "00", 319 => "01", 320 to 322=> "00", 323 => "01", 324 to 326=> "00", 
    327 to 328=> "01", 329 => "00", 330 => "11", 331 => "00", 332 => "01", 333 => "00", 
    334 => "01", 335 to 343=> "00", 344 => "01", 345 to 347=> "00", 348 => "11", 349 => "00", 
    350 => "01", 351 => "00", 352 => "01", 353 to 363=> "00", 364 to 365=> "01", 366 to 369=> "00", 
    370 => "01", 371 => "00", 372 to 373=> "11", 374 to 377=> "00", 378 => "11", 379 to 381=> "00", 
    382 => "11", 383 => "00", 384 => "01", 385 to 386=> "00", 387 to 388=> "01", 389 to 391=> "00", 
    392 => "01", 393 to 402=> "00", 403 => "11", 404 to 405=> "00", 406 to 407=> "01", 408 to 415=> "00", 
    416 => "01", 417 to 420=> "00", 421 => "01", 422 => "00", 423 => "01", 424 to 425=> "00", 
    426 to 427=> "01", 428 to 429=> "00", 430 => "01", 431 to 441=> "00", 442 to 443=> "01", 444 to 445=> "00", 
    446 => "11", 447 => "00", 448 => "01", 449 => "00", 450 to 451=> "11", 452 to 454=> "00", 
    455 => "01", 456 to 460=> "00", 461 => "01", 462 => "00", 463 => "11", 464 to 465=> "00", 
    466 => "01", 467 => "00", 468 => "11", 469 to 479=> "00", 480 to 481=> "01", 482 to 485=> "00", 
    486 => "01", 487 to 506=> "00", 507 => "11", 508 to 511=> "00" );


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

entity mlp_accel_4b_weights_l2_4b_9 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_9 is
    component mlp_accel_4b_weights_l2_4b_9_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_9_rom_U :  component mlp_accel_4b_weights_l2_4b_9_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


