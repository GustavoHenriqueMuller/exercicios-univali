library ieee;
use ieee.std_logic_1164.all;

entity fsm_3_tb is
end fsm_3_tb;

architecture arch_fsm_3_tb of fsm_3_tb is
	component fsm_3 is
		port
		(
			i_CLK: in std_logic;
			o_X: out std_logic;
			o_Y: out std_logic;
			o_Z: out std_logic
		);
	end component;

	signal w_CLK: std_logic;
	signal w_X: std_logic;
	signal w_Y: std_logic;
	signal w_Z: std_logic;
	
	begin
		fsm_instance: fsm_3 port map (w_CLK, w_X, w_Y, w_Z);
		
		process begin
			-- s0
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '0') report "Fail x @ 0" severity error;
			assert (w_Y = '0') report "Fail y @ 0" severity error;
			assert (w_Z = '0') report "Fail z @ 0" severity error;
			
			-- s1
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '0') report "Fail x @ 1" severity error;
			assert (w_Y = '0') report "Fail y @ 1" severity error;
			assert (w_Z = '1') report "Fail z @ 1" severity error;
			
			-- s2
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '0') report "Fail x @ 2" severity error;
			assert (w_Y = '1') report "Fail y @ 2" severity error;
			assert (w_Z = '0') report "Fail z @ 2" severity error;
			
			-- s3
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '1') report "Fail x @ 3" severity error;
			assert (w_Y = '0') report "Fail y @ 3" severity error;
			assert (w_Z = '0') report "Fail z @ 3" severity error;
			
			-- back to s0
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '0') report "Fail x @ 4" severity error;
			assert (w_Y = '0') report "Fail y @ 4" severity error;
			assert (w_Z = '0') report "Fail z @ 4" severity error;
			
			wait;
		end process;
end arch_fsm_3_tb;