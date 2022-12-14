library IEEE;
use IEEE.std_logic_1164.all;

entity mux_16x16bit is
	port
	(
		i_0: in std_logic_vector (15 downto 0);
		i_1: in std_logic_vector (15 downto 0);
		i_2: in std_logic_vector (15 downto 0);
		i_3: in std_logic_vector (15 downto 0);
		i_4: in std_logic_vector (15 downto 0);
		i_5: in std_logic_vector (15 downto 0);
		i_6: in std_logic_vector (15 downto 0);
		i_7: in std_logic_vector (15 downto 0);
		i_8: in std_logic_vector (15 downto 0);
		i_9: in std_logic_vector (15 downto 0);
		i_10: in std_logic_vector (15 downto 0);
		i_11: in std_logic_vector (15 downto 0);
		i_12: in std_logic_vector (15 downto 0);
		i_13: in std_logic_vector (15 downto 0);
		i_14: in std_logic_vector (15 downto 0);
		i_15: in std_logic_vector (15 downto 0);
		
		i_SEL: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (15 downto 0)
	);
end mux_16x16bit;

architecture arch_mux_16x16bit of mux_16x16bit is
begin
	process (i_0, i_1, i_2, i_3, i_4, i_5, i_6, i_7, i_8, i_9, i_10, i_11, i_12, i_13, i_14, i_15, i_SEL) begin
		case (i_SEL) is
			when "0000" => o_R <= i_0;
			when "0001" => o_R <= i_1;
			when "0010" => o_R <= i_2;
			when "0011" => o_R <= i_3;
			when "0100" => o_R <= i_4;
			when "0101" => o_R <= i_5;
			when "0110" => o_R <= i_6;
			when "0111" => o_R <= i_7;
			when "1000" => o_R <= i_8;
			when "1001" => o_R <= i_9;
			when "1010" => o_R <= i_10;
			when "1011" => o_R <= i_11;
			when "1100" => o_R <= i_12;
			when "1101" => o_R <= i_13;
			when "1110" => o_R <= i_14;
			when "1111" => o_R <= i_15;
			when others => o_R <= i_0;
		end case;
	end process;
end arch_mux_16x16bit;