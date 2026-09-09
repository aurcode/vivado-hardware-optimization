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

entity mlp_accel_weights_l3_3_rom is 
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


architecture rtl of mlp_accel_weights_l3_3_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "11000001001001", 1 => "00000001101000", 2 => "10011111011010", 
    3 => "11111111110111", 4 => "10010100001011", 5 => "00011111001111", 
    6 => "01000001011010", 7 => "00000000000000", 8 => "11001101000110", 
    9 => "10000001100111", 10 => "01001100100110", 11 => "11111111111111", 
    12 => "01001100100010", 13 => "10100101110101", 14 => "11011011110110", 
    15 => "11111111111010", 16 => "11001110011110", 17 => "00111100010011", 
    18 => "00100101000100", 19 => "11111111111010", 20 => "10101010101100", 
    21 => "00100000100010", 22 => "10000101110010", 23 => "11111111111000", 
    24 => "00101100000101", 25 => "00000111100100", 26 => "00110001110101", 
    27 => "00000000000000", 28 => "00100101100100", 29 => "11101010100100", 
    30 => "01000101101011", 31 => "11111111111111", 32 => "11100111101010", 
    33 => "11110011000111", 34 => "11011110000100", 35 => "11111111111010", 
    36 => "01001111001010", 37 => "00010011011010", 38 => "10111011011001", 
    39 => "00000000101011" );

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

entity mlp_accel_weights_l3_3 is
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

architecture arch of mlp_accel_weights_l3_3 is
    component mlp_accel_weights_l3_3_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_weights_l3_3_rom_U :  component mlp_accel_weights_l3_3_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


