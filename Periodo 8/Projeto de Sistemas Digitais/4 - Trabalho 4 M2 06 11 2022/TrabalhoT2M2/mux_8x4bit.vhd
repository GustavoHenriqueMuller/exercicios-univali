library IEEE;
use IEEE.std_logic_1164.all;

entity mux_8x4bit is
	port
	(
		i_A_0: in std_logic_vector (3 downto 0);
		i_A_1: in std_logic_vector (3 downto 0);
		i_A_2: in std_logic_vector (3 downto 0);
		i_A_3: in std_logic_vector (3 downto 0);
		i_A_4: in std_logic_vector (3 downto 0);
		i_A_5: in std_logic_vector (3 downto 0);
		i_A_6: in std_logic_vector (3 downto 0);
		i_A_7: in std_logic_vector (3 downto 0);
		i_SEL: in std_logic_vector (2 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end mux_8x4bit;

architecture arch_mux_8x4bit of mux_8x4bit is
begin
	process (i_A_0, i_A_1, i_A_2, i_A_3, i_A_4, i_A_5, i_A_6, i_A_7, i_SEL)
	begin
		case i_SEL is
			when "000" => o_R <= i_A_0;
			when "001" => o_R <= i_A_1;
			when "010" => o_R <= i_A_2;
			when "011" => o_R <= i_A_3;
			when "100" => o_R <= i_A_4;
			when "101" => o_R <= i_A_5;
			when "110" => o_R <= i_A_6;
			when "111" => o_R <= i_A_7;
			when others => o_R <= i_A_0;
		end case;
	end process;
end arch_mux_8x4bit;