library IEEE;
use IEEE.std_logic_1164.all;

entity xor_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end xor_4bit;

architecture arch_xor_4bit of xor_4bit is
begin
	o_R(0) <= i_A(0) XOR i_B(0);
	o_R(1) <= i_A(1) XOR i_B(1);
	o_R(2) <= i_A(2) XOR i_B(2);
	o_R(3) <= i_A(3) XOR i_B(3);
end arch_xor_4bit;