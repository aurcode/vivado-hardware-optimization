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

entity mlp_accel_4b_weights_l2_4b_11_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_11_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "001", 1 => "000", 2 => "111", 3 to 5=> "000", 6 => "001", 7 => "111", 
    8 => "001", 9 => "000", 10 => "110", 11 => "001", 12 to 13=> "000", 14 => "001", 
    15 to 17=> "000", 18 => "001", 19 to 20=> "000", 21 => "001", 22 => "000", 23 => "001", 
    24 to 27=> "000", 28 => "001", 29 => "111", 30 to 31=> "000", 32 => "001", 33 to 35=> "000", 
    36 to 38=> "001", 39 to 41=> "000", 42 => "001", 43 => "000", 44 => "001", 45 to 46=> "000", 
    47 => "001", 48 to 52=> "000", 53 => "001", 54 => "000", 55 => "111", 56 to 57=> "000", 
    58 => "111", 59 => "000", 60 => "111", 61 to 62=> "000", 63 => "111", 64 => "001", 
    65 => "000", 66 => "111", 67 to 70=> "000", 71 => "111", 72 to 73=> "000", 74 to 75=> "111", 
    76 to 78=> "000", 79 to 81=> "001", 82 => "000", 83 => "001", 84 => "000", 85 => "001", 
    86 to 92=> "000", 93 => "001", 94 => "000", 95 => "111", 96 to 97=> "000", 98 => "110", 
    99 => "000", 100 => "111", 101 to 115=> "000", 116 to 117=> "111", 118 => "001", 119 to 122=> "000", 
    123 => "001", 124 to 137=> "000", 138 => "111", 139 to 140=> "000", 141 => "111", 142 => "000", 
    143 => "111", 144 to 145=> "000", 146 => "001", 147 => "111", 148 => "000", 149 => "001", 
    150 => "000", 151 => "001", 152 to 156=> "000", 157 => "001", 158 to 163=> "000", 164 => "001", 
    165 to 166=> "111", 167 to 169=> "000", 170 => "111", 171 => "000", 172 => "111", 173 to 174=> "000", 
    175 => "111", 176 to 177=> "001", 178 to 179=> "000", 180 => "010", 181 => "001", 182 to 195=> "000", 
    196 => "111", 197 to 201=> "000", 202 => "001", 203 to 204=> "000", 205 => "111", 206 => "000", 
    207 => "001", 208 => "111", 209 => "000", 210 => "010", 211 => "111", 212 => "000", 
    213 => "001", 214 => "000", 215 => "001", 216 => "000", 217 => "001", 218 to 219=> "000", 
    220 => "111", 221 to 222=> "000", 223 => "111", 224 to 236=> "000", 237 => "111", 238 to 241=> "000", 
    242 => "111", 243 to 249=> "000", 250 => "001", 251 => "000", 252 => "001", 253 to 254=> "000", 
    255 => "001", 256 => "111", 257 => "000", 258 => "001", 259 to 260=> "000", 261 to 262=> "111", 
    263 => "001", 264 to 268=> "000", 269 => "111", 270 => "000", 271 => "111", 272 to 275=> "000", 
    276 => "001", 277 to 281=> "000", 282 => "001", 283 to 284=> "000", 285 => "001", 286 => "000", 
    287 => "001", 288 to 294=> "000", 295 => "001", 296 to 300=> "000", 301 => "110", 302 => "000", 
    303 => "111", 304 to 308=> "000", 309 => "001", 310 to 311=> "000", 312 => "001", 313 => "000", 
    314 => "111", 315 to 316=> "000", 317 => "001", 318 to 319=> "000", 320 => "001", 321 => "000", 
    322 => "111", 323 => "001", 324 to 325=> "000", 326 => "001", 327 to 329=> "000", 330 => "001", 
    331 to 334=> "000", 335 => "111", 336 to 345=> "000", 346 => "001", 347 => "111", 348 => "000", 
    349 => "001", 350 to 353=> "000", 354 => "001", 355 => "000", 356 to 357=> "001", 358 => "000", 
    359 => "001", 360 to 367=> "000", 368 => "001", 369 to 372=> "000", 373 => "001", 374 to 377=> "000", 
    378 => "111", 379 to 380=> "001", 381 => "000", 382 to 383=> "001", 384 to 390=> "000", 391 => "001", 
    392 to 395=> "000", 396 => "001", 397 => "111", 398 => "000", 399 => "111", 400 to 403=> "000", 
    404 => "001", 405 to 415=> "000", 416 => "001", 417 to 420=> "000", 421 => "111", 422 => "000", 
    423 => "110", 424 to 425=> "000", 426 to 427=> "001", 428 to 438=> "000", 439 => "001", 440 to 443=> "000", 
    444 => "111", 445 => "001", 446 to 447=> "000", 448 => "001", 449 => "000", 450 => "001", 
    451 => "000", 452 => "001", 453 to 458=> "000", 459 => "001", 460 to 465=> "000", 466 => "001", 
    467 to 468=> "000", 469 => "001", 470 => "000", 471 to 472=> "001", 473 to 481=> "000", 482 => "001", 
    483 => "000", 484 to 485=> "001", 486 to 499=> "000", 500 => "001", 501 to 502=> "000", 503 => "010", 
    504 to 508=> "000", 509 => "110", 510 => "000", 511 => "111" );


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

entity mlp_accel_4b_weights_l2_4b_11 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_11 is
    component mlp_accel_4b_weights_l2_4b_11_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_11_rom_U :  component mlp_accel_4b_weights_l2_4b_11_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


