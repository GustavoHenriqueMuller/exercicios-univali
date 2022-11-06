library IEEE;
use IEEE.std_logic_1164.all;

entity full_adder_1bit_tb is
end full_adder_1bit_tb;

architecture arch_full_adder_1bit_tb of full_adder_1bit_tb is

component full_adder_1bit is
	port
	(
		i_A: in std_logic;
		i_B: in std_logic;
		i_CARRY_IN: in std_logic;
		o_R: out std_logic;
		o_CARRY_OUT: out std_logic
	);
end component;

signal w_A: std_logic;
signal w_B: std_logic;
signal W_CARRY_IN: std_logic;
signal w_R: std_logic;
signal w_CARRY_OUT: std_logic;

begin
	u_FULL_ADDER: full_adder_1bit port map (w_A, w_B, W_CARRY_IN, w_R, w_CARRY_OUT);

	process
	begin
		-- Test 1
		w_A <= '0';
		w_B <= '0';
		w_CARRY_IN <= '0';
		
		wait for 1ns;
		assert (w_R = '0') report "Fail full_adder_1bit -> Test 1" severity error;
		assert (w_CARRY_OUT = '0') report "Fail full_adder_1bit -> Test 1" severity error;
		
		-- Test 2
		w_A <= '0';
		w_B <= '0';
		w_CARRY_IN <= '1';
		
		wait for 1ns;
		assert (w_R = '1') report "Fail full_adder_1bit -> Test 2" severity error;
		assert (w_CARRY_OUT = '0') report "Fail full_adder_1bit -> Test 2" severity error;
		
		-- Test 3
		w_A <= '0';
		w_B <= '1';
		w_CARRY_IN <= '0';
		
		wait for 1ns;
		assert (w_R = '1') report "Fail full_adder_1bit -> Test 3" severity error;
		assert (w_CARRY_OUT = '0') report "Fail full_adder_1bit -> Test 3" severity error;
		
		-- Test 4
		w_A <= '0';
		w_B <= '1';
		w_CARRY_IN <= '1';
		
		wait for 1ns;
		assert (w_R = '0') report "Fail full_adder_1bit -> Test 4" severity error;
		assert (w_CARRY_OUT = '1') report "Fail full_adder_1bit -> Test 4" severity error;
		
		-- Test 5
		w_A <= '1';
		w_B <= '0';
		w_CARRY_IN <= '0';
		
		wait for 1ns;
		assert (w_R = '1') report "Fail full_adder_1bit -> Test 5" severity error;
		assert (w_CARRY_OUT = '0') report "Fail full_adder_1bit -> Test 5" severity error;
		
		-- Test 6
		w_A <= '1';
		w_B <= '0';
		w_CARRY_IN <= '1';
		
		wait for 1ns;
		assert (w_R = '0') report "Fail full_adder_1bit -> Test 6" severity error;
		assert (w_CARRY_OUT = '1') report "Fail full_adder_1bit -> Test 6" severity error;
		
		-- Test 7
		w_A <= '1';
		w_B <= '1';
		w_CARRY_IN <= '0';
		
		wait for 1ns;
		assert (w_R = '0') report "Fail full_adder_1bit -> Test 7" severity error;
		assert (w_CARRY_OUT = '1') report "Fail full_adder_1bit -> Test 7" severity error;
		
		-- Test 8
		w_A <= '1';
		w_B <= '1';
		w_CARRY_IN <= '1';
		
		wait for 1ns;
		assert (w_R = '1') report "Fail full_adder_1bit -> Test 8" severity error;
		assert (w_CARRY_OUT = '1') report "Fail full_adder_1bit -> Test 8" severity error;
	
		wait;
	end process;
end arch_full_adder_1bit_tb;