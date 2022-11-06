library IEEE;
use IEEE.std_logic_1164.all;

entity incrementer_4bit_tb is
end incrementer_4bit_tb;

architecture arch_incrementer_4bit_tb of incrementer_4bit_tb is

component incrementer_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0);
		o_CARRY_OUT: out std_logic
	);
end component;

signal w_A: std_logic_vector (3 downto 0);
signal w_R: std_logic_vector (3 downto 0);
signal w_CARRY_OUT: std_logic;

begin
	u_INCREMENTER: incrementer_4bit port map (w_A, w_R, w_CARRY_OUT);

	process
	begin
		-- Test 1
		w_A <= "1110";
		
		wait for 1ns;
		assert (w_R = "1111") report "Fail incrementer_4bit -> Test 1" severity error;
		assert (w_CARRY_OUT = '0') report "Fail incrementer_4bit -> Test 1" severity error;
		
		-- Test 2
		w_A <= "1111";
		
		wait for 1ns;
		assert (w_R = "0000") report "Fail incrementer_4bit -> Test 2" severity error;
		assert (w_CARRY_OUT = '1') report "Fail incrementer_4bit -> Test 2" severity error;
		
		-- Test 3
		w_A <= "0101";
		
		wait for 1ns;
		assert (w_R = "0110") report "Fail incrementer_4bit -> Test 3" severity error;
		assert (w_CARRY_OUT = '0') report "Fail incrementer_4bit -> Test 3" severity error;
	
		wait;
	end process;
end arch_incrementer_4bit_tb;