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

entity mlp_accel_4b_weights_l2_4b_7_rom is 
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


architecture rtl of mlp_accel_4b_weights_l2_4b_7_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 to 1=> "000", 2 => "111", 3 to 9=> "000", 10 to 11=> "111", 12 to 14=> "000", 15 => "001", 
    16 to 17=> "000", 18 to 19=> "001", 20 to 21=> "000", 22 => "111", 23 to 25=> "000", 26 => "111", 
    27 to 30=> "000", 31 => "001", 32 to 34=> "000", 35 => "111", 36 to 39=> "000", 40 => "111", 
    41 to 42=> "000", 43 => "111", 44 to 46=> "000", 47 => "111", 48 to 51=> "000", 52 => "001", 
    53 => "000", 54 => "001", 55 to 56=> "000", 57 to 58=> "111", 59 to 69=> "000", 70 to 71=> "001", 
    72 to 73=> "000", 74 => "001", 75 => "000", 76 => "111", 77 => "000", 78 => "111", 
    79 to 80=> "000", 81 => "001", 82 => "111", 83 => "001", 84 to 86=> "000", 87 to 88=> "001", 
    89 to 91=> "000", 92 => "001", 93 => "000", 94 => "001", 95 => "111", 96 => "001", 
    97 to 102=> "000", 103 => "001", 104 => "111", 105 to 110=> "000", 111 => "001", 112 => "000", 
    113 to 115=> "111", 116 to 118=> "000", 119 => "111", 120 => "000", 121 => "001", 122 => "111", 
    123 to 126=> "000", 127 => "111", 128 to 137=> "000", 138 to 139=> "111", 140 to 144=> "000", 145 => "111", 
    146 to 149=> "000", 150 to 151=> "111", 152 => "000", 153 to 154=> "111", 155 to 158=> "000", 159 => "111", 
    160 to 166=> "000", 167 => "111", 168 => "000", 169 to 170=> "111", 171 to 177=> "000", 178 => "001", 
    179 to 182=> "000", 183 => "010", 184 to 191=> "000", 192 => "001", 193 to 195=> "000", 196 => "111", 
    197 to 198=> "000", 199 => "001", 200 to 205=> "000", 206 => "001", 207 => "111", 208 to 209=> "000", 
    210 to 211=> "001", 212 to 217=> "000", 218 => "111", 219 to 222=> "001", 223 => "111", 224 to 233=> "000", 
    234 => "111", 235 to 236=> "000", 237 => "001", 238 => "000", 239 => "111", 240 => "000", 
    241 to 242=> "111", 243 to 244=> "000", 245 => "001", 246 to 247=> "111", 248 to 249=> "000", 250 => "001", 
    251 to 257=> "000", 258 => "001", 259 => "000", 260 => "001", 261 to 262=> "000", 263 => "110", 
    264 to 265=> "000", 266 => "001", 267 to 269=> "000", 270 => "001", 271 to 274=> "000", 275 => "001", 
    276 to 281=> "000", 282 to 283=> "001", 284 => "111", 285 => "000", 286 => "111", 287 => "001", 
    288 to 290=> "000", 291 => "111", 292 to 301=> "000", 302 => "001", 303 to 305=> "000", 306 => "001", 
    307 to 310=> "000", 311 => "001", 312 => "000", 313 to 314=> "111", 315 => "000", 316 => "111", 
    317 => "000", 318 => "111", 319 to 321=> "000", 322 => "111", 323 to 324=> "000", 325 => "001", 
    326 => "111", 327 => "001", 328 to 329=> "000", 330 to 331=> "001", 332 => "000", 333 => "001", 
    334 => "000", 335 => "001", 336 to 343=> "000", 344 => "110", 345 => "000", 346 => "001", 
    347 to 352=> "000", 353 => "001", 354 to 357=> "000", 358 => "001", 359 => "111", 360 => "001", 
    361 to 364=> "000", 365 => "001", 366 => "000", 367 => "111", 368 to 369=> "000", 370 to 371=> "001", 
    372 to 374=> "000", 375 => "001", 376 => "000", 377 => "001", 378 => "111", 379 => "001", 
    380 => "000", 381 => "001", 382 => "111", 383 => "001", 384 to 386=> "000", 387 => "111", 
    388 to 390=> "000", 391 => "111", 392 => "001", 393 to 395=> "000", 396 => "001", 397 to 399=> "000", 
    400 => "111", 401 to 403=> "000", 404 => "111", 405 to 406=> "000", 407 => "001", 408 to 418=> "000", 
    419 => "111", 420 to 421=> "000", 422 => "001", 423 to 424=> "000", 425 to 426=> "001", 427 to 434=> "000", 
    435 => "001", 436 to 438=> "000", 439 => "111", 440 to 445=> "000", 446 => "001", 447 to 454=> "000", 
    455 => "111", 456 to 461=> "000", 462 => "001", 463 to 465=> "000", 466 => "001", 467 to 470=> "000", 
    471 to 472=> "001", 473 to 474=> "000", 475 => "001", 476 to 478=> "000", 479 => "001", 480 to 481=> "000", 
    482 => "001", 483 to 485=> "000", 486 => "001", 487 to 497=> "000", 498 => "111", 499 => "000", 
    500 => "111", 501 => "000", 502 => "111", 503 to 509=> "000", 510 to 511=> "001" );


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

entity mlp_accel_4b_weights_l2_4b_7 is
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

architecture arch of mlp_accel_4b_weights_l2_4b_7 is
    component mlp_accel_4b_weights_l2_4b_7_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_4b_weights_l2_4b_7_rom_U :  component mlp_accel_4b_weights_l2_4b_7_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


