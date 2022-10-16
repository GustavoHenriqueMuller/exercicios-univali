library ieee;
use ieee.std_logic_1164.all;

entity fsm_2_tb is
end fsm_2_tb;

architecture arch_fsm_2_tb of fsm_2_tb is
	component fsm_2 is
		port
		(
			i_CLK: in std_logic;
			i_GCNT: in std_logic;
			o_X: out std_logic;
			o_Y: out std_logic;
			o_Z: out std_logic
		);
	end component;

	signal w_CLK: std_logic;
	signal w_GCNT: std_logic;
	signal w_X: std_logic;
	signal w_Y: std_logic;
	signal w_Z: std_logic;
	
	begin
		fsm_instance: fsm_2 port map (w_CLK, w_GCNT, w_X, w_Y, w_Z);
		
		process begin		
			w_GCNT <= '1';
			
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
			assert (w_Y = '1') report "Fail y @ 1" severity error;
			assert (w_Z = '0') report "Fail z @ 1" severity error;
			
			-- s2
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '0') report "Fail x @ 2" severity error;
			assert (w_Y = '1') report "Fail y @ 2" severity error;
			assert (w_Z = '1') report "Fail z @ 2" severity error;
			
			-- s3
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '0') report "Fail x @ 3" severity error;
			assert (w_Y = '0') report "Fail y @ 3" severity error;
			assert (w_Z = '1') report "Fail z @ 3" severity error;

			-- s4
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '1') report "Fail x @ 4" severity error;
			assert (w_Y = '0') report "Fail y @ 4" severity error;
			assert (w_Z = '1') report "Fail z @ 4" severity error;

			-- s5
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '1') report "Fail x @ 5" severity error;
			assert (w_Y = '1') report "Fail y @ 5" severity error;
			assert (w_Z = '1') report "Fail z @ 5" severity error;

			-- s6
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '1') report "Fail x @ 6" severity error;
			assert (w_Y = '1') report "Fail y @ 6" severity error;
			assert (w_Z = '0') report "Fail z @ 6" severity error;

			-- s7
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '1') report "Fail x @ 7" severity error;
			assert (w_Y = '0') report "Fail y @ 7" severity error;
			assert (w_Z = '0') report "Fail z @ 7" severity error;
			
			
			-- back to s0
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '0') report "Fail x @ 8" severity error;
			assert (w_Y = '0') report "Fail y @ 8" severity error;
			assert (w_Z = '0') report "Fail z @ 8" severity error;
			
			-- gcnt equals '0': should not change state even on clock rise
			w_GCNT <= '0';
			w_CLK <= '1';
			wait for 1 ns;
			w_CLK <= '0';
			wait for 1 ns;
			
			assert (w_X = '0') report "Fail x @ 9" severity error;
			assert (w_Y = '0') report "Fail y @ 9" severity error;
			assert (w_Z = '0') report "Fail z @ 9" severity error;
			
			wait;
		end process;
	
end arch_fsm_2_tb;