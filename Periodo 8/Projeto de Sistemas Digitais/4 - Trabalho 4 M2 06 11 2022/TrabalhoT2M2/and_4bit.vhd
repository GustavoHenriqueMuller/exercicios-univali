library IEEE;
use IEEE.std_logic_1164.all;

entity and_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end and_4bit;

architecture arch_and_4bit of and_4bit is
begin
	o_R(0) <= i_A(0) AND i_B(0);
	o_R(1) <= i_A(1) AND i_B(1);
	o_R(2) <= i_A(2) AND i_B(2);
	o_R(3) <= i_A(3) AND i_B(3);
end arch_and_4bit;