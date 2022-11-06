library IEEE;
use IEEE.std_logic_1164.all;

entity subtractor_4bit_tb is
end subtractor_4bit_tb;

architecture arch_subtractor_4bit_tb of subtractor_4bit_tb is

component subtractor_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

signal w_A: std_logic_vector (3 downto 0);
signal w_B: std_logic_vector (3 downto 0);
signal w_R: std_logic_vector (3 downto 0);
signal w_CARRY_OUT: std_logic;

begin
	u_SUBTRACTOR: subtractor_4bit port map (w_A, w_B, w_R, w_CARRY_OUT);

	process
	begin
		-- Test 1
		w_A <= "1001";
		w_B <= "0011";
		
		wait for 1ns;
		assert (w_R = "0101") report "Fail subtractor_4bit -> Test 1" severity error;
		assert (w_CARRY_OUT = '0') report "Fail subtractor_4bit -> Test 1" severity error;
		
		-- Test 2
		w_A <= "1111";
		w_B <= "0001";
		
		wait for 1ns;
		assert (w_R = "1110") report "Fail subtractor_4bit -> Test 2" severity error;
		assert (w_CARRY_OUT = '1') report "Fail subtractor_4bit -> Test 2" severity error;
		
		-- Test 3
		w_A <= "0000";
		w_B <= "0001";
		
		wait for 1ns;
		assert (w_R = "1111") report "Fail subtractor_4bit -> Test 3" severity error;
		assert (w_CARRY_OUT = '0') report "Fail subtractor_4bit -> Test 3" severity error;
	
		wait;
	end process;
end arch_subtractor_4bit_tb;