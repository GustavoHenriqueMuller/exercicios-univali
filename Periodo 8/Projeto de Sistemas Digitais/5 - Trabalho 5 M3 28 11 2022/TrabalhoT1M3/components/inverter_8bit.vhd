library IEEE;
use IEEE.std_logic_1164.all;

entity inverter_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		o_R: out std_logic_vector (7 downto 0)
	);
end inverter_8bit;

architecture arch_inverter_8bit of inverter_8bit is
begin
	o_R(0) <= not i_A(0);
	o_R(1) <= not i_A(1);
	o_R(2) <= not i_A(2);
	o_R(3) <= not i_A(3);
	o_R(4) <= not i_A(4);
	o_R(5) <= not i_A(5);
	o_R(6) <= not i_A(6);
	o_R(7) <= not i_A(7);
end arch_inverter_8bit;