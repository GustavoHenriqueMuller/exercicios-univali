library IEEE;
use IEEE.std_logic_1164.all;

entity mux_3x16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_B: in std_logic_vector (15 downto 0);
		i_C: in std_logic_vector (15 downto 0);
		i_SEL: in std_logic_vector (1 downto 0);
		
		o_R: out std_logic_vector (15 downto 0)
	);
end mux_3x16bit;

architecture arch_mux_3x16bit of mux_3x16bit is
begin
	process(i_A, i_B, i_C, i_SEL) begin
		case (i_SEL) is
			when "00" => o_R <= i_A;
			when "01" => o_R <= i_B;
			when "10" => o_R <= i_C;
			when others => o_R <= i_A; -- TODO: Tomar cuidado
		end case;
	end process;
end arch_mux_3x16bit;