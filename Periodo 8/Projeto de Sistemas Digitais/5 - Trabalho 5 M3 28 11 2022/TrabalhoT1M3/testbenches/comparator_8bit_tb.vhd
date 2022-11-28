library IEEE;
use IEEE.std_logic_1164.all;

entity comparator_8bit_tb is
end comparator_8bit_tb;

architecture arch_comparator_8bit_tb of comparator_8bit_tb is

component comparator_8bit is
	port
	(
		i_A: in std_logic_vector (7 downto 0);
		i_B: in std_logic_vector (7 downto 0);
		o_GT: out std_logic;
		o_EQ: out std_logic;
		o_LT: out std_logic
	);
end component;

signal w_A: std_logic_vector(7 downto 0);
signal w_B: std_logic_vector(7 downto 0);
signal w_GT: std_logic;
signal w_EQ: std_logic;
signal w_LT: std_logic;

begin
	u_COMPARATOR: comparator_8bit port map(w_A, w_B, w_GT, w_EQ, w_LT);

	process
	begin
		-- Test 1 - A = B
		w_A <= "00001000";
		w_B <= "00001000";
		
		wait for 1 ns;
		assert (w_GT = '0') report "Fail comparator_8bit -> Test 1" severity error;
		assert (w_EQ = '1') report "Fail comparator_8bit -> Test 1" severity error;
		assert (w_LT = '0') report "Fail comparator_8bit -> Test 1" severity error;
		
		-- Test 2 - A > B
		w_A <= "01011000";
		w_B <= "00101000";
		
		wait for 1 ns;
		assert (w_GT = '1') report "Fail comparator_8bit -> Test 2" severity error;
		assert (w_EQ = '0') report "Fail comparator_8bit -> Test 2" severity error;
		assert (w_LT = '0') report "Fail comparator_8bit -> Test 2" severity error;
		
		-- Test 3 - A < B
		w_A <= "00000111";
		w_B <= "00001000";
		
		wait for 1 ns;
		assert (w_GT = '0') report "Fail comparator_8bit -> Test 3" severity error;
		assert (w_EQ = '0') report "Fail comparator_8bit -> Test 3" severity error;
		assert (w_LT = '1') report "Fail comparator_8bit -> Test 3" severity error;
	
		wait;
	end process;
end arch_comparator_8bit_tb;