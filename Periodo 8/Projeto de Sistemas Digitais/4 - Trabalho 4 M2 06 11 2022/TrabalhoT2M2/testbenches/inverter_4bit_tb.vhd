library IEEE;
use IEEE.std_logic_1164.all;

entity inverter_4bit_tb is
end inverter_4bit_tb;

architecture arch_inverter_4bit_tb of inverter_4bit_tb is

component inverter_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

signal w_A: std_logic_vector (3 downto 0);
signal w_R: std_logic_vector (3 downto 0);

begin
	u_AND: inverter_4bit port map (w_A, w_R);

	process
	begin
		-- Test 1
		w_A <= "1111";
			
		wait for 1ns;
		assert (w_R = "0000") report "Fail inverter_4bit -> Test 1" severity error;
			
		-- Test 2
		w_A <= "0101";
			
		wait for 1ns;
		assert (w_R = "1010") report "Fail inverter_4bit -> Test 2" severity error;
					
		-- Test 3
		w_A <= "1100";
			
		wait for 1ns;
		assert (w_R = "0011") report "Fail inverter_4bit -> Test 3" severity error;
	
		wait;
	end process;
end arch_inverter_4bit_tb;