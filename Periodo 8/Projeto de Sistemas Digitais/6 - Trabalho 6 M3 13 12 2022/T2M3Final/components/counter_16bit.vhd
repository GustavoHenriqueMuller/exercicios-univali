library IEEE;
use IEEE.std_logic_1164.all;

entity counter_16bit is
	port
	(
		i_UP: in std_logic;
		i_CLR_N: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (15 downto 0)
	);
end counter_16bit;

architecture arch_counter_16bit of counter_16bit is

component register_16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_LOAD: in std_logic;
		i_CLR_N: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (15 downto 0)
	);
end component;

component incrementer_16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		o_R: out std_logic_vector (15 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

signal w_IN_COUNT: std_logic_vector (15 downto 0);
signal w_OUT_COUNT: std_logic_vector (15 downto 0);

begin
	u_COUNT_REGISTER: register_16bit port map (w_IN_COUNT, i_UP, i_CLR_N, i_CLK, w_OUT_COUNT);
	u_INCREMENTER: incrementer_16bit port map (w_OUT_COUNT, w_IN_COUNT, open);
	
	o_R <= w_OUT_COUNT;
end arch_counter_16bit;