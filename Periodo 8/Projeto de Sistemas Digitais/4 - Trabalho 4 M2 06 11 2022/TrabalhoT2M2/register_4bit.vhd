library IEEE;
use IEEE.std_logic_1164.all;

entity register_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_LOAD: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (3 downto 0)
	);
end register_4bit;

architecture arch_register_4bit of register_4bit is
begin
	process (i_A, i_LOAD, i_CLK)
	begin
		if (rising_edge(i_CLK)) then
			if (i_LOAD = '1') then
				o_R <= i_A;
			end if;
		end if;
	end process;
end arch_register_4bit;