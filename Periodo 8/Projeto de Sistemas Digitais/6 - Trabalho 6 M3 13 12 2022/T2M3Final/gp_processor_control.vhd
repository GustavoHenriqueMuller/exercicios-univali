library IEEE;
use IEEE.std_logic_1164.all;

entity gp_processor_control is
	port
	(
		-- Inputs
		i_CLK: in std_logic;
		i_IM_DATA: in std_logic_vector (15 downto 0);
		
		-- Outputs
		o_IM_READ: out std_logic;
		o_IM_ADDRESS: out std_logic_vector (7 downto 0);
		
		-- Outputs to datapath
		o_DM_ADDRESS: out std_logic_vector (7 downto 0);
		o_DM_READ: out std_logic;
		o_DM_WRITE: out std_logic;
		
		o_RF_SEL: out std_logic_vector (1 downto 0);
		o_RF_W: out std_logic;
		o_RF_W_ADDRESS: out std_logic_vector (3 downto 0);
		
		o_RF_RP_ADDRESS: out std_logic_vector (3 downto 0);
		o_RF_RP_READ: out std_logic;
		
		o_RF_RQ_ADDRESS: out std_logic_vector (3 downto 0);
		o_RF_RQ_READ: out std_logic;
		
		o_ALU_SEL: out std_logic
	);
end gp_processor_control;

architecture arch_gp_processor_control of gp_processor_control is

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

component counter_8bit is
	port
	(
		i_UP: in std_logic;
		i_CLR_N: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (7 downto 0)
	);
end component;

component gp_processor_controller is
	port
	(
		-- Inputs
		i_IR: in std_logic_vector (15 downto 0);
		i_CLK: in std_logic;
		
		-- Outputs
		o_PC_CLR_N: out std_logic;
		o_PC_UP: out std_logic;
		
		o_IM_READ: out std_logic;
		o_IR_LOAD: out std_logic;
		
		-- Outputs to datamemory
		o_DM_ADDRESS: out std_logic_vector (7 downto 0);
		o_DM_READ: out std_logic;
		o_DM_WRITE: out std_logic;
		
		-- Outputs to datapath
		o_RF_SEL: out std_logic_vector (1 downto 0);
		o_RF_W: out std_logic;
		o_RF_W_ADDRESS: out std_logic_vector (3 downto 0);
		
		o_RF_RP_ADDRESS: out std_logic_vector (3 downto 0);
		o_RF_RP_READ: out std_logic;
		
		o_RF_RQ_ADDRESS: out std_logic_vector (3 downto 0);
		o_RF_RQ_READ: out std_logic;
		
		o_ALU_SEL: out std_logic
	);
end component;

-- IR signals
signal w_IR_LOAD: std_logic;
signal w_IR: std_logic_vector (15 downto 0);

-- PC signals
signal w_PC_UP: std_logic;
signal w_PC_CLR_N: std_logic;

begin
	u_IR_REGISTER: register_16bit port map (i_IM_DATA, w_IR_LOAD, '1', i_CLK, w_IR);
	u_PC_COUNTER: counter_8bit port map (w_PC_UP, w_PC_CLR_N, i_CLK, o_IM_ADDRESS);

	u_CONTROLLER: gp_processor_controller port map (
		w_IR,
		i_CLK,
		
		w_PC_CLR_N,
		w_PC_UP,
		
		o_IM_READ,
		w_IR_LOAD,
		
		o_DM_ADDRESS,
		o_DM_READ,
		o_DM_WRITE,
		
		o_RF_SEL,
		o_RF_W,
		o_RF_W_ADDRESS,
		
		o_RF_RP_ADDRESS,
		o_RF_RP_READ,
		
		o_RF_RQ_ADDRESS,
		o_RF_RQ_READ,
		
		o_ALU_SEL
	);
end arch_gp_processor_control;