-- ==============================================================
-- File generated on Wed Sep 02 16:35:40 +0000 2026
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity mlp_accel_weights_l3_7_rom is 
    generic(
             DWIDTH     : integer := 15; 
             AWIDTH     : integer := 6; 
             MEM_SIZE    : integer := 40
    ); 
    port (
          addr0      : in std_logic_vector(AWIDTH-1 downto 0); 
          ce0       : in std_logic; 
          q0         : out std_logic_vector(DWIDTH-1 downto 0);
          clk       : in std_logic
    ); 
end entity; 


architecture rtl of mlp_accel_weights_l3_7_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "111010101001000", 1 => "111111111111000", 2 => "000101101110111", 
    3 => "111011011111110", 4 => "000010100011111", 5 => "000000000000000", 
    6 => "000110010011100", 7 => "000100011111011", 8 => "111111100011111", 
    9 => "000000001100111", 10 => "000011011100001", 11 => "000110111000101", 
    12 => "111101001001001", 13 => "000000000000101", 14 => "110101101010111", 
    15 => "111010010010010", 16 => "000110001010101", 17 => "000000000100101", 
    18 => "000111011111101", 19 => "111010111100111", 20 => "110101011101011", 
    21 => "111111111111111", 22 => "111001100010000", 23 => "000000101100010", 
    24 => "000000011111101", 25 => "000000000000000", 26 => "111101001010110", 
    27 => "000010011100000", 28 => "110111100000111", 29 => "000000000000101", 
    30 => "111011000011011", 31 => "000000111001000", 32 => "001000101100111", 
    33 => "111111111111001", 34 => "110001000011000", 35 => "001000000000111", 
    36 => "111110100000101", 37 => "111111101001111", 38 => "000100101010000", 
    39 => "101110101110101" );

attribute syn_rom_style : string;
attribute syn_rom_style of mem : signal is "select_rom";
attribute ROM_STYLE : string;
attribute ROM_STYLE of mem : signal is "distributed";

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

entity mlp_accel_weights_l3_7 is
    generic (
        DataWidth : INTEGER := 15;
        AddressRange : INTEGER := 40;
        AddressWidth : INTEGER := 6);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of mlp_accel_weights_l3_7 is
    component mlp_accel_weights_l3_7_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_weights_l3_7_rom_U :  component mlp_accel_weights_l3_7_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


