library IEEE;
use IEEE.std_logic_1164.all;

entity ula_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		i_SEL: in std_logic_vector (2 downto 0);
		i_LOAD: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (3 downto 0)
	);
end ula_4bit;

architecture arch_ula_4bit of ula_4bit is

component adder_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

component subtractor_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		
		o_R: out std_logic_vector (3 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

component incrementer_4bit
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

component and_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

component or_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

component xor_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

component inverter_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

component mux_8x4bit is
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
end component;

component register_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_LOAD: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

signal w_ADDER_RESULT: std_logic_vector (3 downto 0);
signal w_SUBTRACTOR_RESULT: std_logic_vector (3 downto 0);
signal w_INCREMENTER_RESULT: std_logic_vector (3 downto 0);
signal w_AND_RESULT: std_logic_vector (3 downto 0);
signal w_OR_RESULT: std_logic_vector (3 downto 0);
signal w_XOR_RESULT: std_logic_vector (3 downto 0);
signal w_INVERTER_RESULT: std_logic_vector (3 downto 0);
signal w_MUX_RESULT: std_logic_vector (3 downto 0);

begin
	u_ADDER: adder_4bit port map(i_A, i_B, w_ADDER_RESULT, open);
	u_SUBTRACTOR: subtractor_4bit port map(i_A, i_B, w_SUBTRACTOR_RESULT, open);
	u_INCREMENTER: incrementer_4bit port map(i_A, w_INCREMENTER_RESULT, open);
	u_AND: and_4bit port map(i_A, i_B, w_AND_RESULT);
	u_OR: or_4bit port map(i_A, i_B, w_OR_RESULT);
	u_XOR: xor_4bit port map(i_A, i_B, w_XOR_RESULT);
	u_INVERTER: inverter_4bit port map(i_A, w_INVERTER_RESULT);
	
	u_MUX: mux_8x4bit port map (
		w_ADDER_RESULT,
		w_SUBTRACTOR_RESULT,
		w_INCREMENTER_RESULT,
		i_A,
		w_AND_RESULT,
		w_OR_RESULT,
		w_XOR_RESULT,
		w_INVERTER_RESULT,
		i_SEL,
		w_MUX_RESULT
	);
	
	u_REGISTER: register_4bit port map (
		w_MUX_RESULT,
		i_LOAD,
		i_CLK,
		O_R
	);
end arch_ula_4bit;