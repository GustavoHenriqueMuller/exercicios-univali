library IEEE;
use IEEE.std_logic_1164.all;

entity incrementer_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0);
		o_CARRY_OUT: out std_logic
	);
end incrementer_4bit;

architecture arch_incrementer_4bit of incrementer_4bit is

component adder_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

begin
	u_ADDER: adder_4bit port map(i_A, "0001", o_R, o_CARRY_OUT);
end arch_incrementer_4bit;