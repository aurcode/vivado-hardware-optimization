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

entity mlp_accel_weights_l3_13_rom is 
    generic(
             DWIDTH     : integer := 14; 
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


architecture rtl of mlp_accel_weights_l3_13_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "11111010101011", 1 => "00001100101001", 2 => "00010110100100", 
    3 => "00001001101000", 4 => "11101011010101", 5 => "11000011011110", 
    6 => "10110011101101", 7 => "11110011001110", 8 => "00010100010101", 
    9 => "10111011110111", 10 => "11000000010100", 11 => "00000000111001", 
    12 => "11101000011111", 13 => "11010100110010", 14 => "11011100101011", 
    15 => "00000101110100", 16 => "00001100001010", 17 => "00001100010011", 
    18 => "00001101111011", 19 => "11111010110100", 20 => "10011111010001", 
    21 => "11111100001111", 22 => "00110010011110", 23 => "11111101110101", 
    24 => "00110110001100", 25 => "00111111000000", 26 => "10110100101100", 
    27 => "00000110110001", 28 => "00010110101111", 29 => "10111000100010", 
    30 => "00010111110101", 31 => "11111000111000", 32 => "00001000001010", 
    33 => "00100110110001", 34 => "00101001010010", 35 => "00000000110101", 
    36 => "11110010000110", 37 => "11111011100011", 38 => "00010001000100", 
    39 => "11111100101110" );

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

entity mlp_accel_weights_l3_13 is
    generic (
        DataWidth : INTEGER := 14;
        AddressRange : INTEGER := 40;
        AddressWidth : INTEGER := 6);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of mlp_accel_weights_l3_13 is
    component mlp_accel_weights_l3_13_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_weights_l3_13_rom_U :  component mlp_accel_weights_l3_13_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


