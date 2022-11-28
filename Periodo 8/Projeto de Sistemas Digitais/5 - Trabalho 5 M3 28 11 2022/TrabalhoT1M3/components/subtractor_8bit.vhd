library IEEE;
use IEEE.std_logic_1164.all;

entity subtractor_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_B: in std_logic_vector (7 downto 0);
		o_R: out std_logic_vector (7 downto 0);
		o_CARRY_OUT: out std_logic
	);
end subtractor_8bit;

architecture arch_subtractor_8bit of subtractor_8bit is

component inverter_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		o_R: out std_logic_vector (7 downto 0)
	);
end component;

component adder_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_B: in std_logic_vector (7 downto 0);
		i_CARRY_IN: in std_logic;
		o_R: out std_logic_vector (7 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

signal w_INVERTED_B: std_logic_vector (7 downto 0);

begin
	u_INVERTER: inverter_8bit port map(i_B, w_INVERTED_B);
	u_ADDER: adder_8bit port map(i_A, w_INVERTED_B, '1', o_R, o_CARRY_OUT);
end arch_subtractor_8bit;