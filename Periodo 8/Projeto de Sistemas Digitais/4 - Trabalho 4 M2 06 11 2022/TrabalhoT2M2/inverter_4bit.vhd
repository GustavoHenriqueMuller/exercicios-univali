library IEEE;
use IEEE.std_logic_1164.all;

entity inverter_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end inverter_4bit;

architecture arch_inverter_4bit of inverter_4bit is
begin
	o_R(0) <= NOT i_A(0);
	o_R(1) <= NOT i_A(1);
	o_R(2) <= NOT i_A(2);
	o_R(3) <= NOT i_A(3);
end arch_inverter_4bit;