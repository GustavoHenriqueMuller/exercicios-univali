library ieee;
use ieee.std_logic_1164.all;

entity fsm_2 is
	port
	(
		i_CLK: in std_logic;
		i_GCNT: in std_logic;
		o_X: out std_logic;
		o_Y: out std_logic;
		o_Z: out std_logic
	);
end fsm_2;

architecture arch_fsm_2 of fsm_2 is
	type t_STATE is (s0, s1, s2, s3, s4, s5, s6, s7);
	signal r_STATE: t_STATE;
	signal w_NEXT_STATE: t_STATE;
	
	begin
		-- State register
		p_CHANGE_STATE: process(i_CLK) begin
			if (rising_edge(i_CLK) and i_GCNT = '1') then
				r_STATE <= w_NEXT_STATE;
			end if;
		end process;
	
		-- Combinational logic
		p_NEXT_STATE: process(r_STATE) begin
			case (r_STATE) is
				when s0 => w_NEXT_STATE <= s1;
				when s1 => w_NEXT_STATE <= s2;
				when s2 => w_NEXT_STATE <= s3;
				when s3 => w_NEXT_STATE <= s4;
				when s4 => w_NEXT_STATE <= s5;
				when s5 => w_NEXT_STATE <= s6;
				when s6 => w_NEXT_STATE <= s7;
				when s7 => w_NEXT_STATE <= s0;
				when others => w_NEXT_STATE <= s0;
			end case;
		end process;
		
		p_OUTPUT: process(r_STATE) begin
			case (r_STATE) is
				when s0 => o_X <= '0'; o_Y <= '0'; o_Z <= '0';
				when s1 => o_X <= '0'; o_Y <= '1'; o_Z <= '0';
				when s2 => o_X <= '0'; o_Y <= '1'; o_Z <= '1';
				when s3 => o_X <= '0'; o_Y <= '0'; o_Z <= '1';
				when s4 => o_X <= '1'; o_Y <= '0'; o_Z <= '1';
				when s5 => o_X <= '1'; o_Y <= '1'; o_Z <= '1';
				when s6 => o_X <= '1'; o_Y <= '1'; o_Z <= '0';
				when s7 => o_X <= '1'; o_Y <= '0'; o_Z <= '0';
				when others => o_X <= '0'; o_Y <= '0'; o_Z <= '0';
			end case;
		end process;
end arch_fsm_2;