library IEEE;
use IEEE.std_logic_1164.all;

entity register_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_LOAD: in std_logic;
		i_CLR_N: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (7 downto 0)
	);
end register_8bit;

architecture arch_register_8bit of register_8bit is
begin
	process (i_A, i_LOAD, i_CLR_N, i_CLK)
	begin
		if (i_CLR_N = '0') then
			o_R <= (others => '0');
		elsif (rising_edge(i_CLK)) then
			if (i_LOAD = '1') then
				o_R <= i_A;
			end if;
		end if;
	end process;
end arch_register_8bit;