library ieee;
use ieee.std_logic_1164.all;

entity fsm_3 is
	port
	(
		i_CLK: in std_logic;
		o_X: out std_logic;
		o_Y: out std_logic;
		o_Z: out std_logic
	);
end fsm_3;

architecture arch_fsm_3 of fsm_3 is
	signal r_STATE: std_logic_vector (1 downto 0) := "00";
	signal w_NEXT_STATE: std_logic_vector (1 downto 0);
	
	begin
		-- State register
		p_CHANGE_STATE: process(i_CLK) begin
			if (rising_edge(i_CLK)) then
				r_STATE <= w_NEXT_STATE;
			end if;	
		end process;
		
		-- Combinational logic
		
		-- Next state
		p_NEXT_STATE: process(r_STATE) begin
			w_NEXT_STATE(1) <= (not r_STATE(1) and r_STATE(0)) or (r_STATE(1) and not r_STATE(0));
			w_NEXT_STATE(0) <= (not r_STATE(1) and not r_STATE(0)) or (r_STATE(1) and not r_STATE(0));
		end process;
		
		-- Output
		o_X <= r_STATE(1) and r_STATE(0);
		o_Y <= r_STATE(1) and not r_STATE(0);
		o_Z <= not r_STATE(1) and r_STATE(0);
end arch_fsm_3;