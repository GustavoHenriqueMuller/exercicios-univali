library IEEE;
use IEEE.std_logic_1164.all;

entity mdc_control is
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
end mdc_control;

architecture arch_mdc_control of mdc_control is

type t_STATE is (s0, s1, s2, s3, s4, s5, s6, s7, s8, s9, s10);
signal r_STATE: t_STATE;
signal w_NEXT_STATE: t_STATE;

begin
	-- State register
	p_CHANGE_STATE: process(i_CLK) begin
		if (rising_edge(i_CLK)) then
			r_STATE <= w_NEXT_STATE;
		end if;
	end process;
	
	-- Combinational logic
	p_NEXT_STATE: process(r_STATE, i_GO, i_X_EQ_Y, i_X_LT_Y) begin
		case (r_STATE) is
			when s0 => w_NEXT_STATE <= s1;
			when s1 => w_NEXT_STATE <= s2;
			when s2 => if (i_GO = '1') then w_NEXT_STATE <= s3; else w_NEXT_STATE <= s2; end if;
			when s3 => w_NEXT_STATE <= s4;
			when s4 => w_NEXT_STATE <= s5;
			when s5 => if (i_X_EQ_Y = '0') then w_NEXT_STATE <= s6; else w_NEXT_STATE <= s10; end if;
			when s6 => if (i_X_LT_Y = '1') then w_NEXT_STATE <= s7; else w_NEXT_STATE <= s8; end if;
			when s7 => w_NEXT_STATE <= s9;
			when s8 => w_NEXT_STATE <= s9;
			when s9 => w_NEXT_STATE <= s5;
			when s10 => w_NEXT_STATE <= s1;
			when others => w_NEXT_STATE <= s0;
		end case;
	end process;
	
	p_OUTPUT: process(r_STATE) begin
		o_RDY <= '0';
		
		o_X_CLRn <= '1';
		o_X_LOAD <= '0';
		o_X_LOAD_MODE <= '0';
		
		o_Y_CLRn <= '1';
		o_Y_LOAD <= '0';
		o_Y_LOAD_MODE <= '0';
		
		o_D_CLRn <= '1';
		o_D_LOAD <= '0';
	
		case (r_STATE) is
			when s0 => o_X_CLRn <= '0'; o_Y_CLRn <= '0'; o_D_CLRn <= '0'; o_RDY <= '1';
			when s1 => O_RDY <= '1';
			when s2 => NULL;
			when s3 => o_X_LOAD <= '1'; o_Y_LOAD <= '1';
			when s4 => NULL;
			when s5 => NULL;
			when s6 => NULL;
			when s7 => o_Y_LOAD <= '1'; o_Y_LOAD_MODE <= '1';
			when s8 => o_X_LOAD <= '1'; o_X_LOAD_MODE <= '1';
			when s9 => NULL;
			when s10 => o_D_LOAD <= '1';
			when others => NULL;
		end case;
	end process;
end arch_mdc_control;