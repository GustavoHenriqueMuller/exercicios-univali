library IEEE;
use IEEE.std_logic_1164.all;

entity mux_2x16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_B: in std_logic_vector (15 downto 0);
		i_SEL: in std_logic;
		
		o_R: out std_logic_vector (15 downto 0)
	);
end mux_2x16bit;

architecture arch_mux_2x16bit of mux_2x16bit is
begin
	process(i_A, i_B, i_SEL) begin
		case (i_SEL) is
			when '0' => o_R <= i_A;
			when '1' => o_R <= i_B;
			when others => o_R <= i_A; -- TODO: Tomar cuidado
		end case;
	end process;
end arch_mux_2x16bit;