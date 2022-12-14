library IEEE;
use IEEE.std_logic_1164.all;

entity gp_processor is
	port
	(
		i_CLK: in std_logic
	);
end gp_processor;

architecture arch_gp_processor of gp_processor is

component gp_processor_control is
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
end component;

component gp_processor_datapath is
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
end component;

component rom_256x16_im is
	generic 
	(
		DATA_WIDTH : natural := 16;
		ADDRESS_WIDTH : natural := 8
	);

	port 
	(
		addr	: in std_logic_vector (ADDRESS_WIDTH - 1 downto 0);
		q		: out std_logic_vector((DATA_WIDTH -1) downto 0)
	);
end component;

component ram_256x16_dm is
	generic 
	(
		WORD_WIDTH : natural := 16;
		ADDRESS_WIDTH : natural := 8
	);

	port 
	(
		i_CLK: in std_logic;
		i_ADDRESS: in std_logic_vector (ADDRESS_WIDTH - 1 downto 0);
		i_W_DATA: in std_logic_vector ((WORD_WIDTH - 1) downto 0);
		i_W: in std_logic := '1';
		i_READ: in std_logic;
		
		o_R: out std_logic_vector ((WORD_WIDTH - 1) downto 0)
	);
end component;

-- Instruction memory
signal w_IM_DATA: std_logic_vector (15 downto 0);
signal w_IM_READ: std_logic;
signal w_IM_ADDRESS: std_logic_vector (7 downto 0);

-- Data memory
signal w_DM_ADDRESS: std_logic_vector (7 downto 0);
signal w_DM_W_DATA: std_logic_vector (15 downto 0);
signal w_DM_READ: std_logic;
signal w_DM_WRITE: std_logic;
signal w_DM_R: std_logic_vector (15 downto 0);

-- Controller to datapath
signal w_RF_SEL: std_logic_vector (1 downto 0);
signal w_RF_W: std_logic;
signal w_RF_W_ADDRESS: std_logic_vector (3 downto 0);

signal w_RF_RP_ADDRESS: std_logic_vector (3 downto 0);
signal w_RF_RP_READ: std_logic;
		
signal w_RF_RQ_ADDRESS: std_logic_vector (3 downto 0);
signal w_RF_RQ_READ: std_logic;
		
signal w_ALU_SEL: std_logic;

begin
	u_CONTROL: gp_processor_control port map (
		i_CLK,
		w_IM_DATA,
		
		w_IM_READ, -- open?
		w_IM_ADDRESS,
		
		w_DM_ADDRESS,
		w_DM_READ,
		w_DM_WRITE,
		
		w_RF_SEL,
		w_RF_W,
		w_RF_W_ADDRESS,
		
		w_RF_RP_ADDRESS,
		w_RF_RP_READ,
		
		w_RF_RQ_ADDRESS,
		w_RF_RQ_READ,
		
		W_ALU_SEL
	);
	
	
	u_DATAPATH: gp_processor_datapath port map (
		i_CLK,
		w_ALU_SEL,
		w_DM_R,
		w_DM_ADDRESS,
		
		w_RF_SEL,
		w_RF_W,
		w_RF_W_ADDRESS,
		
		w_RF_RP_ADDRESS,
		w_RF_RP_READ,
		
		w_RF_RQ_ADDRESS,
		w_RF_RQ_READ,
		
		w_DM_W_DATA
	);
	
	u_DATA_MEMORY: ram_256x16_dm port map (
		i_CLK,
		w_DM_ADDRESS,
		w_DM_W_DATA,
		w_DM_WRITE,
		w_DM_READ,
		
		w_DM_R
	);
	
	u_INSTRUCTION_MEMORY: rom_256x16_im port map (
		w_IM_ADDRESS,
		w_IM_DATA
	);

end arch_gp_processor;