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

entity mlp_accel_weights_l3_4_rom is 
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


architecture rtl of mlp_accel_weights_l3_4_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "000000111110010", 1 => "111001100101100", 2 => "111011111001010", 
    3 => "001001000100010", 4 => "111001000010001", 5 => "000100010110011", 
    6 => "111010011011110", 7 => "111100011101101", 8 => "000101001101100", 
    9 => "110010111010011", 10 => "001000001100100", 11 => "111100110101111", 
    12 => "000011011101101", 13 => "000110101001111", 14 => "000010110100011", 
    15 => "111100000100011", 16 => "110011110010100", 17 => "111101000111111", 
    18 => "111000110100100", 19 => "110111001010000", 20 => "000001011101110", 
    21 => "000110111011101", 22 => "111011000101000", 23 => "111001111110001", 
    24 => "111000110100100", 25 => "111110010000010", 26 => "000100110111110", 
    27 => "001010010101110", 28 => "110100110111100", 29 => "101111111000010", 
    30 => "000100010011000", 31 => "110101001100100", 32 => "111011000001111", 
    33 => "111111100101010", 34 => "111110111111010", 35 => "000101110100000", 
    36 => "000010011011011", 37 => "000111110111001", 38 => "101101010110100", 
    39 => "110111110001111" );

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

entity mlp_accel_weights_l3_4 is
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

architecture arch of mlp_accel_weights_l3_4 is
    component mlp_accel_weights_l3_4_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_weights_l3_4_rom_U :  component mlp_accel_weights_l3_4_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


