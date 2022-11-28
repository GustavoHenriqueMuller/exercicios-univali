library IEEE;
use IEEE.std_logic_1164.all;

entity adder_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0);
		o_CARRY_OUT: out std_logic
	);
end adder_4bit;

architecture arch_adder_4bit of adder_4bit is

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

begin
	u_FULL_ADDER_0: full_adder_1bit port map(i_A(0), i_B(0), '0', o_R(0), w_CARRY_OUT_0);
	u_FULL_ADDER_1: full_adder_1bit port map(i_A(1), i_B(1), w_CARRY_OUT_0, o_R(1), w_CARRY_OUT_1);
	u_FULL_ADDER_2: full_adder_1bit port map(i_A(2), i_B(2), w_CARRY_OUT_1, o_R(2), w_CARRY_OUT_2);
	u_FULL_ADDER_3: full_adder_1bit port map(i_A(3), i_B(3), w_CARRY_OUT_2, o_R(3), o_CARRY_OUT);
end arch_adder_4bit;