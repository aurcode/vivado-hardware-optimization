-- ==============================================================
-- File generated on Wed Sep 02 16:31:16 +0000 2026
-- Vivado(TM) HLS - High-Level Synthesis from C, C++ and SystemC v2018.3 (64-bit)
-- SW Build 2405991 on Thu Dec  6 23:36:41 MST 2018
-- IP Build 2404404 on Fri Dec  7 01:43:56 MST 2018
-- Copyright 1986-2018 Xilinx, Inc. All Rights Reserved.
-- ==============================================================
library ieee; 
use ieee.std_logic_1164.all; 
use ieee.std_logic_unsigned.all;

entity mlp_accel_8b_weights_l3_8b_9_rom is 
    generic(
             DWIDTH     : integer := 7; 
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


architecture rtl of mlp_accel_8b_weights_l3_8b_9_rom is 

signal addr0_tmp : std_logic_vector(AWIDTH-1 downto 0); 
type mem_array is array (0 to MEM_SIZE-1) of std_logic_vector (DWIDTH-1 downto 0); 
signal mem : mem_array := (
    0 => "1111000", 1 => "0000011", 2 => "0001110", 3 => "0001100", 
    4 => "0001001", 5 => "1101001", 6 => "1110010", 7 => "1110000", 
    8 => "0001110", 9 => "1111110", 10 => "1100110", 11 => "0001000", 
    12 => "0000011", 13 => "0001100", 14 => "1101111", 15 => "1110010", 
    16 => "0001100", 17 => "1100111", 18 => "0000111", 19 => "1100001", 
    20 => "1110110", 21 => "0010001", 22 => "1101000", 23 => "0001100", 
    24 => "0000111", 25 => "1111101", 26 => "1111100", 27 => "1110101", 
    28 => "0000101", 29 => "0000011", 30 => "0010101", 31 => "0001100", 
    32 => "1110101", 33 => "0000011", 34 => "1110011", 35 => "1111011", 
    36 => "1010011", 37 => "1111100", 38 => "1111010", 39 => "1111110" );

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

entity mlp_accel_8b_weights_l3_8b_9 is
    generic (
        DataWidth : INTEGER := 7;
        AddressRange : INTEGER := 40;
        AddressWidth : INTEGER := 6);
    port (
        reset : IN STD_LOGIC;
        clk : IN STD_LOGIC;
        address0 : IN STD_LOGIC_VECTOR(AddressWidth - 1 DOWNTO 0);
        ce0 : IN STD_LOGIC;
        q0 : OUT STD_LOGIC_VECTOR(DataWidth - 1 DOWNTO 0));
end entity;

architecture arch of mlp_accel_8b_weights_l3_8b_9 is
    component mlp_accel_8b_weights_l3_8b_9_rom is
        port (
            clk : IN STD_LOGIC;
            addr0 : IN STD_LOGIC_VECTOR;
            ce0 : IN STD_LOGIC;
            q0 : OUT STD_LOGIC_VECTOR);
    end component;



begin
    mlp_accel_8b_weights_l3_8b_9_rom_U :  component mlp_accel_8b_weights_l3_8b_9_rom
    port map (
        clk => clk,
        addr0 => address0,
        ce0 => ce0,
        q0 => q0);

end architecture;


