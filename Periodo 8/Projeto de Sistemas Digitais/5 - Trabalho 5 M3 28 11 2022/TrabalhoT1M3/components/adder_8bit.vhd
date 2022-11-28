library IEEE;
use IEEE.std_logic_1164.all;

entity adder_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_B: in std_logic_vector (7 downto 0);
		i_CARRY_IN: in std_logic;
		o_R: out std_logic_vector (7 downto 0);
		o_CARRY_OUT: out std_logic
	);
end adder_8bit;

architecture arch_adder_8bit of adder_8bit is

component full_adder_1bit is
	port
	(
		i_A: in std_logic;
		i_B: in std_logic;
		i_CARRY_IN: in std_logic;
		o_R: out std_logic;
		o_CARRY_OUT: out std_logic
	);
end component;

signal w_CARRY_OUT_0: std_logic;
signal w_CARRY_OUT_1: std_logic;
signal w_CARRY_OUT_2: std_logic;
signal w_CARRY_OUT_3: std_logic;
signal w_CARRY_OUT_4: std_logic;
signal w_CARRY_OUT_5: std_logic;
signal w_CARRY_OUT_6: std_logic;

begin
	u_FULL_ADDER_0: full_adder_1bit port map(i_A(0), i_B(0), i_CARRY_IN, o_R(0), w_CARRY_OUT_0);
	u_FULL_ADDER_1: full_adder_1bit port map(i_A(1), i_B(1), w_CARRY_OUT_0, o_R(1), w_CARRY_OUT_1);
	u_FULL_ADDER_2: full_adder_1bit port map(i_A(2), i_B(2), w_CARRY_OUT_1, o_R(2), w_CARRY_OUT_2);
	u_FULL_ADDER_3: full_adder_1bit port map(i_A(3), i_B(3), w_CARRY_OUT_2, o_R(3), w_CARRY_OUT_3);
	u_FULL_ADDER_4: full_adder_1bit port map(i_A(4), i_B(4), w_CARRY_OUT_3, o_R(4), w_CARRY_OUT_4);
	u_FULL_ADDER_5: full_adder_1bit port map(i_A(5), i_B(5), w_CARRY_OUT_4, o_R(5), w_CARRY_OUT_5);
	u_FULL_ADDER_6: full_adder_1bit port map(i_A(6), i_B(6), w_CARRY_OUT_5, o_R(6), w_CARRY_OUT_6);
	u_FULL_ADDER_7: full_adder_1bit port map(i_A(7), i_B(7), w_CARRY_OUT_6, o_R(7), o_CARRY_OUT);
end arch_adder_8bit;