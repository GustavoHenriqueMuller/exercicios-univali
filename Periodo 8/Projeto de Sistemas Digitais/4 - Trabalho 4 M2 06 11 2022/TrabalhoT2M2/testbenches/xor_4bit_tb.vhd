library IEEE;
use IEEE.std_logic_1164.all;

entity xor_4bit_tb is
end xor_4bit_tb;

architecture arch_xor_4bit_tb of xor_4bit_tb is

component xor_4bit is
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
	u_XOR: xor_4bit port map (w_A, w_B, w_R);

	process
	begin
		-- Test 1
		w_A <= "1111";
		w_B <= "0000";
			
		wait for 1ns;
		assert (w_R = "1111") report "Fail xor_4bit -> Test 1" severity error;
			
		-- Test 2
		w_A <= "0101";
		w_B <= "1100";
			
		wait for 1ns;
		assert (w_R = "1001") report "Fail xor_4bit -> Test 2" severity error;
					
		-- Test 3
		w_A <= "1100";
		w_B <= "1111";
			
		wait for 1ns;
		assert (w_R = "0011") report "Fail xor_4bit -> Test 3" severity error;
	
		wait;
	end process;
end arch_xor_4bit_tb;