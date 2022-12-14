library IEEE;
use IEEE.std_logic_1164.all;

entity full_adder_1bit is
	port
	(
		i_A: in std_logic;
		i_B: in std_logic;
		i_CARRY_IN: in std_logic;
		o_R: out std_logic;
		o_CARRY_OUT: out std_logic
	);
end full_adder_1bit;

architecture arch_full_adder_1bit of full_adder_1bit is
begin
	o_R <= i_A XOR i_B XOR i_CARRY_IN;
	o_CARRY_OUT <= (i_A AND i_B) OR (i_A AND i_CARRY_IN) OR (i_B AND i_CARRY_IN);
	
end arch_full_adder_1bit;