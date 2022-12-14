library IEEE;
use IEEE.std_logic_1164.all;

entity alu_16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_B: in std_logic_vector (15 downto 0);
		i_SEL: in std_logic;
		
		o_R: out std_logic_vector (15 downto 0)
	);
end alu_16bit;

architecture arch_alu_16bit of alu_16bit is

component adder_16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_B: in std_logic_vector (15 downto 0);
		i_CARRY_IN: in std_logic;
		o_R: out std_logic_vector (15 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

component mux_2x16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_B: in std_logic_vector (15 downto 0);
		i_SEL: in std_logic;
		o_R: out std_logic_vector (15 downto 0)
	);
end component;

signal w_ADDER_OUT: std_logic_vector (15 downto 0);

begin
	u_ADDER: adder_16bit port map (i_A, i_B, '0', w_ADDER_OUT, open);
	u_MUX: mux_2x16bit port map (i_A, w_ADDER_OUT, i_SEL, o_R);
	
end arch_alu_16bit;