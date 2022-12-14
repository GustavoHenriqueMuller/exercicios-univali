library IEEE;
use IEEE.std_logic_1164.all;

entity gp_processor_datapath is
	port
	(
		-- Inputs
		i_CLK: in std_logic;
		i_ALU_SEL: in std_logic;
		i_DM_DATA: in std_logic_vector (15 downto 0);
		i_CONSTANT_DATA: in std_logic_vector (7 downto 0);
		
		-- Inputs for register file
		i_RF_SEL: in std_logic_vector (1 downto 0);
		i_RF_W: in std_logic;
		i_RF_W_ADDRESS: in std_logic_vector (3 downto 0);
		
		i_RF_RP_ADDRESS: in std_logic_vector (3 downto 0);
		i_RF_RP_READ: in std_logic;
		
		i_RF_RQ_ADDRESS: in std_logic_vector (3 downto 0);
		i_RF_RQ_READ: in std_logic;
		
		-- Outputs
		o_DM_W_DATA: out std_logic_vector (15 downto 0)
	);
end gp_processor_datapath;

architecture arch_gp_processor_datapath of gp_processor_datapath is

component alu_16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_B: in std_logic_vector (15 downto 0);
		i_SEL: in std_logic;
		
		o_R: out std_logic_vector (15 downto 0)
	);
end component;

component mux_3x16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_B: in std_logic_vector (15 downto 0);
		i_C: in std_logic_vector (15 downto 0);
		i_SEL: in std_logic_vector (1 downto 0);
		
		o_R: out std_logic_vector (15 downto 0)
	);
end component;

component register_file_16x16 is
	port
	(
		-- Inputs
		i_CLK: in std_logic;
		
		i_RF_W_DATA: in std_logic_vector (15 downto 0);
		i_RF_W: in std_logic;
		i_RF_W_ADDRESS: in std_logic_vector (3 downto 0);
		
		i_RF_RP_ADDRESS: in std_logic_vector (3 downto 0);
		i_RF_RP_READ: in std_logic;
		
		i_RF_RQ_ADDRESS: in std_logic_vector (3 downto 0);
		i_RF_RQ_READ: in std_logic;
		
		-- Outputs
		o_RP_DATA: out std_logic_vector (15 downto 0);
		o_RQ_DATA: out std_logic_vector (15 downto 0)
	);
end component;

signal w_MUX_OUT: std_logic_vector (15 downto 0);
signal w_RP_DATA: std_logic_vector (15 downto 0);
signal w_RQ_DATA: std_logic_vector (15 downto 0);

signal w_ALU_OUT: std_logic_vector (15 downto 0);

signal w_CONSTANT_16BIT: std_logic_vector (15 downto 0);

begin
	w_CONSTANT_16BIT <= "00000000" & i_CONSTANT_DATA;
	o_DM_W_DATA <= w_RP_DATA;
	
	u_MUX: mux_3x16bit port map (
		w_ALU_OUT,
		i_DM_DATA,
		w_CONSTANT_16BIT,
		i_RF_SEL,
		
		w_MUX_OUT
	);

	u_REGISTER_FILE: register_file_16x16 port map (
		i_CLK,
		
		w_MUX_OUT,
		i_RF_W,
		i_RF_W_ADDRESS,
		
		i_RF_RP_ADDRESS,
		i_RF_RP_READ,
		
		i_RF_RQ_ADDRESS,
		i_RF_RQ_READ,
		
		w_RP_DATA,
		w_RQ_DATA
	);

	u_ALU: alu_16bit port map (
		w_RP_DATA,
		w_RQ_DATA,
		i_ALU_SEL,
		
		w_ALU_OUT
	);
	
end arch_gp_processor_datapath;