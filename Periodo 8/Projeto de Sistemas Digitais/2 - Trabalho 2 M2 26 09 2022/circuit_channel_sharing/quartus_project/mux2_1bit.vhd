library IEEE;
use IEEE.std_logic_1164.all;

entity mux2_1bit is
	port
	(
		i_SEL : in std_logic;
		i_A : in std_logic;
		i_B : in std_logic;
		o_S : out std_logic
	); 
end mux2_1bit;

architecture arch_1 of mux2_1bit is
begin
	process(i_SEL, i_A, i_B) begin
		if (i_SEL='0') then
			o_S <= i_A;
		else
			o_S <= i_B;
		end if;
	end process;
end arch_1;