library IEEE;
use IEEE.std_logic_1164.all;

entity gp_processor_controller is
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
end gp_processor_controller;

architecture arch_gp_processor_controller of gp_processor_controller is

type t_STATE is (s0, s1, s2, s3, s4, s5, s6);
signal r_STATE: t_STATE;
signal w_NEXT_STATE: t_STATE;

signal w_IR_OPCODE: std_logic_vector (3 downto 0);
signal w_IR_R1: std_logic_vector (3 downto 0);
signal w_IR_R2: std_logic_vector (3 downto 0);
signal w_IR_R3: std_logic_vector (3 downto 0);
signal w_IR_DATA_ADDRESS: std_logic_vector (7 downto 0);

begin
	-- Auxiliary signals
	p_CHANGE_AUX_IR_STATES: process(i_IR) begin
		w_IR_OPCODE <= i_IR (15 downto 12);
		w_IR_R1 <= i_IR (11 downto 8);
		w_IR_R2 <= i_IR (7 downto 4);
		w_IR_R3 <= i_IR (3 downto 0);
		w_IR_DATA_ADDRESS <= i_IR (7 downto 0);
	end process;

	-- State register
	p_CHANGE_STATE: process(i_CLK) begin
		if (rising_edge(i_CLK)) then
			r_STATE <= w_NEXT_STATE;
		end if;
	end process;
	
	-- Combinational logic
	p_NEXT_STATE: process(r_STATE, w_IR_OPCODE) begin
		case (r_STATE) is
			when s0 => w_NEXT_STATE <= s1;
			when s1 => w_NEXT_STATE <= s2;
			
			when s2 => 
				if (w_IR_OPCODE = "0001") then -- load
					w_NEXT_STATE <= s3;
				elsif (w_IR_OPCODE = "0010") then -- store
					w_NEXT_STATE <= s4;
				elsif (w_IR_OPCODE = "0011") then -- add
					w_NEXT_STATE <= s5;
				elsif (w_IR_OPCODE = "1111") then -- load immediate
					w_NEXT_STATE <= s6;
				else
					w_NEXT_STATE <= s2;
				end if;
			
			when s3 => w_NEXT_STATE <= s1;
			when s4 => w_NEXT_STATE <= s1;
			when s5 => w_NEXT_STATE <= s1;
			when s6 => w_NEXT_STATE <= s1;
			when others => w_NEXT_STATE <= s0;
		end case;
	end process;
	
	p_OUTPUT: process(r_STATE) begin
		-- Outputs
		o_PC_CLR_N <= '1';
		o_PC_UP <= '0';
				
		o_IM_READ <= '0';
		o_IR_LOAD <= '0';

		-- Outputs to datapath
		o_DM_ADDRESS <= "00000000";
		o_DM_READ <= '0';
		o_DM_WRITE <= '0';
				
		o_RF_SEL <= "00";
		o_RF_W <= '0';
		o_RF_W_ADDRESS <= "0000";
				
		o_RF_RP_ADDRESS <= "0000";
		o_RF_RP_READ <= '0';
				
		o_RF_RQ_ADDRESS <= "0000";
		o_RF_RQ_READ <= '0';
				
		o_ALU_SEL <= '0';
	
		case (r_STATE) is
			when s0 => o_PC_CLR_N <= '0';
			when s1 => o_IM_READ <= '1'; o_PC_UP <= '1'; o_IR_LOAD <= '1';
			when s2 => NULL;
			when s3 => o_DM_ADDRESS <= w_IR_DATA_ADDRESS; o_DM_READ <= '1'; o_RF_SEL <= "01"; o_RF_W_ADDRESS <= w_IR_R1; o_RF_W <= '1';
			when s4 => o_DM_ADDRESS <= w_IR_DATA_ADDRESS; o_DM_WRITE <= '1'; o_RF_RP_ADDRESS <= w_IR_R1; o_RF_RP_READ <= '1';
			when s5 => o_RF_RP_ADDRESS <= w_IR_R2; o_RF_RP_READ <= '1'; o_RF_RQ_ADDRESS <= w_IR_R3; o_RF_RQ_READ <= '1'; o_RF_W_ADDRESS <= w_IR_R1; o_RF_W <= '1'; o_ALU_SEL <= '1';
			when s6 => o_RF_W_ADDRESS <= w_IR_R1; o_RF_W <= '1'; o_RF_SEL <= "10"; o_DM_ADDRESS <= w_IR_DATA_ADDRESS;
			when others => NULL;
		end case;
	end process;

end arch_gp_processor_controller;