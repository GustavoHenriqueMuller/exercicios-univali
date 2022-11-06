library IEEE;
use IEEE.std_logic_1164.all;

entity and_4bit_tb is
end and_4bit_tb;

architecture arch_and_4bit_tb of and_4bit_tb is

component and_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

signal w_A: std_logic_vector (3 downto 0);
signal w_B: std_logic_vector (3 downto 0);
signal w_R: std_logic_vector (3 downto 0);

begin
	u_OR: and_4bit port map (w_A, w_B, w_R);

	process
	begin
		-- Test 1
		w_A <= "1001";
		w_B <= "1001";
		
		wait for 1ns;
		assert (w_R = "1001") report "Fail and_4bit -> Test 1" severity error;
		
		-- Test 2
		w_A <= "0101";
		w_B <= "1110";
		
		wait for 1ns;
		assert (w_R = "0100") report "Fail and_4bit -> Test 2" severity error;
				
		-- Test 3
		w_A <= "1010";
		w_B <= "0101";
		
		wait for 1ns;
		assert (w_R = "0000") report "Fail and_4bit -> Test 3" severity error;
	
		wait;
	end process;
end arch_and_4bit_tb;