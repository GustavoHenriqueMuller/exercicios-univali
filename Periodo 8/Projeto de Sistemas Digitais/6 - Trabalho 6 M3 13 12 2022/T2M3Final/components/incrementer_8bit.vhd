library IEEE;
use IEEE.std_logic_1164.all;

entity incrementer_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		o_R: out std_logic_vector (7 downto 0);
		o_CARRY_OUT: out std_logic
	);
end incrementer_8bit;

architecture arch_incrementer_8bit of incrementer_8bit is

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

begin
	u_ADDER: adder_8bit port map(i_A, "00000001", '0', o_R, o_CARRY_OUT);
end arch_incrementer_8bit;