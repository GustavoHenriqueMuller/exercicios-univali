library IEEE;
use IEEE.std_logic_1164.all;

entity mdc_datapath is
	port
	(
		i_CLK: in std_logic;
		
		-- Data inputs
		i_X: in std_logic_vector (7 downto 0);
		i_X_LOAD: in std_logic;
		i_X_CLRn: in std_logic;
		i_X_LOAD_MODE: in std_logic;
		
		i_Y: in std_logic_vector (7 downto 0);
		i_Y_LOAD: in std_logic;
		i_Y_CLRn: in std_logic;
		i_Y_LOAD_MODE: in std_logic;
		
		i_D_LOAD: in std_logic;
		i_D_CLRn: in std_logic;
		
		-- Data outputs
		o_X_EQ_Y: out std_logic;
		o_X_LT_Y: out std_logic;
		o_D: out std_logic_vector (7 downto 0)
	);
end mdc_datapath;

architecture arch_mdc_datapath of mdc_datapath is

component register_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_LOAD: in std_logic;
		i_CLRn: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (7 downto 0)
	);
end component;

component mux_2x8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_B: in std_logic_vector (7 downto 0);
		i_SEL: in std_logic;
		o_R: out std_logic_vector (7 downto 0)
	);
end component;

component subtractor_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_B: in std_logic_vector (7 downto 0);
		o_R: out std_logic_vector (7 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

component comparator_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_B: in std_logic_vector (7 downto 0);
		o_GT: out std_logic;
		o_EQ: out std_logic;
		o_LT: out std_logic
	);
end component;

signal w_MUX_X_OUT: std_logic_vector (7 downto 0);
signal w_X_MINUS_Y: std_logic_vector (7 downto 0);

signal w_MUX_Y_OUT: std_logic_vector (7 downto 0);
signal w_Y_MINUS_X: std_logic_vector (7 downto 0);

signal w_X: std_logic_vector (7 downto 0);
signal w_Y: std_logic_vector (7 downto 0);

begin
	u_SUBTRACTOR_0: subtractor_8bit port map (w_X, w_Y, w_X_MINUS_Y, open);
	u_SUBTRACTOR_1: subtractor_8bit port map (w_Y, w_X, w_Y_MINUS_X, open);
	u_COMPARATOR: comparator_8bit port map (w_X, w_Y, open, o_X_EQ_Y, o_X_LT_Y);
	
	u_MUX_X: mux_2x8bit port map (i_X, w_X_MINUS_Y, i_X_LOAD_MODE, w_MUX_X_OUT);
	u_MUX_Y: mux_2x8bit port map (i_Y, w_Y_MINUS_X, i_Y_LOAD_MODE, w_MUX_Y_OUT);
		
	u_REGISTER_X: register_8bit port map (w_MUX_X_OUT, i_X_LOAD, i_X_CLRn, i_CLK, w_X);
	u_REGISTER_Y: register_8bit port map (w_MUX_Y_OUT, i_Y_LOAD, i_Y_CLRn, i_CLK, w_Y);
	u_REGSITER_D: register_8bit port map (w_X, i_D_LOAD, i_D_CLRn, i_CLK, o_D);
end arch_mdc_datapath;