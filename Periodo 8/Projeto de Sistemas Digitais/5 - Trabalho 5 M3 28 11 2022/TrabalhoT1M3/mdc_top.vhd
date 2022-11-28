library IEEE;
use IEEE.std_logic_1164.all;

entity mdc_top is
	port
	(
		i_X: in std_logic_vector (7 downto 0);
		i_Y: in std_logic_vector (7 downto 0);
		i_GO: in std_logic;
		i_CLK: in std_logic;
				
		o_D: out std_logic_vector (7 downto 0);
		o_RDY: out std_logic
	);
end mdc_top;

architecture arch_mdc_top of mdc_top is

component mdc_control is
	port
	(
		-- Inputs
		i_CLK: in std_logic;
		i_GO: in std_logic;
		i_X_EQ_Y: in std_logic;
		i_X_LT_Y: in std_logic;
		
		-- Outputs
		o_RDY: out std_logic;
		
		o_X_CLRn: out std_logic;
		o_X_LOAD: out std_logic;
		o_X_LOAD_MODE: out std_logic;
		
		o_Y_CLRn: out std_logic;
		o_Y_LOAD: out std_logic;
		o_Y_LOAD_MODE: out std_logic;
		
		o_D_CLRn: out std_logic;
		o_D_LOAD: out std_logic
	);
end component;

component mdc_datapath is
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
end component;

-- Clock signal
signal w_CLK: std_logic;

-- Controller outputs to Datapath
signal w_X_CLRn: std_logic;
signal w_X_LOAD: std_logic;
signal w_X_LOAD_MODE: std_logic;
		
signal w_Y_CLRn: std_logic;
signal w_Y_LOAD: std_logic;
signal w_Y_LOAD_MODE: std_logic;
		
signal w_D_CLRn: std_logic;
signal w_D_LOAD: std_logic;

-- Datapath outputs to Controller
signal w_X_EQ_Y: std_logic;
signal w_X_LT_Y: std_logic;

begin
	u_MDC_CONTROL: mdc_control port map (
		i_CLK,
		i_GO,
		w_X_EQ_Y,
		w_X_LT_Y,
		
		o_RDY,
		
		w_X_CLRn,
		w_X_LOAD,
		w_X_LOAD_MODE,
		
		w_Y_CLRn,
		w_Y_LOAD,
		w_Y_LOAD_MODE,
		
		w_D_CLRn,
		w_D_LOAD
	);
	
	u_MDC_DATAPATH: mdc_datapath port map (
		i_CLK,
		
		i_X,
		w_X_LOAD,
		w_X_CLRn,
		w_X_LOAD_MODE,
		
		i_Y,
		w_Y_LOAD,
		w_Y_CLRn,
		w_Y_LOAD_MODE,
		
		w_D_LOAD,
		w_D_CLRn,
		
		w_X_EQ_Y,
		w_X_LT_Y,
		o_D
	);
end arch_mdc_top;