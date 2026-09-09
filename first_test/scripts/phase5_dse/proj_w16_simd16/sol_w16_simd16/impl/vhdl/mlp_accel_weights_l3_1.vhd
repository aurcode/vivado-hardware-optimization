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

entity mlp_accel_weights_l3_1_rom is 
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


architecture rtl of mlp_accel_weights_l3_1_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "111100000110001", 1 => "000001011000000", 2 => "000101011001101", 
    3 => "000101010110101", 4 => "110101111011000", 5 => "111001110011011", 
    6 => "000100000001111", 7 => "111110111011011", 8 => "000011000101100", 
    9 => "000000001011100", 10 => "111100001101101", 11 => "111111110110011", 
    12 => "000111110110010", 13 => "000111010000101", 14 => "000101101101000", 
    15 => "000101101010110", 16 => "000100110111101", 17 => "000100110111001", 
    18 => "110110100010101", 19 => "110101011010000", 20 => "111000111111011", 
    21 => "111110000100110", 22 => "000000010110100", 23 => "000000011101001", 
    24 => "101111101101111", 25 => "110111001010101", 26 => "111011011011110", 
    27 => "111100110000011", 28 => "000000000110111", 29 => "110100000111111", 
    30 => "111111000001011", 31 => "110001100000111", 32 => "000011001110111", 
    33 => "000100000011100", 34 => "000011111011101", 35 => "000100010010001", 
    36 => "000100110101001", 37 => "111101001000010", 38 => "111011101010010", 
    39 => "111011101110001" );

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

entity mlp_accel_weights_l3_1 is
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

architecture arch of mlp_accel_weights_l3_1 is
    component mlp_accel_weights_l3_1_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_weights_l3_1_rom_U :  component mlp_accel_weights_l3_1_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


