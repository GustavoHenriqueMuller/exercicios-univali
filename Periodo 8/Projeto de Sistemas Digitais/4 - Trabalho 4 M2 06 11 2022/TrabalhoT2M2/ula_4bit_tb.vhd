library IEEE;
use IEEE.std_logic_1164.all;

entity ula_4bit_tb is
end ula_4bit_tb;

architecture arch_ula_4bit_tb of ula_4bit_tb is

component ula_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_B: in std_logic_vector (3 downto 0);
		i_SEL: in std_logic_vector (2 downto 0);
		i_LOAD: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

signal w_A: std_logic_vector (3 downto 0);
signal w_B: std_logic_vector (3 downto 0);
signal w_SEL: std_logic_vector (2 downto 0);
signal w_LOAD: std_logic;
signal w_CLK: std_logic;
signal w_R: std_logic_vector (3 downto 0);

begin
	ula_instance: ula_4bit port map (w_A, w_B, w_SEL, w_LOAD, w_CLK, W_R);
	
	process
	begin
		w_LOAD <= '1';
	
		-----------------------------------------------------------------------------
		-- "AND" BLOCK TEST
		w_SEL <= "100";
		
			-- Test 1
			w_A <= "1111";
			w_B <= "0000";
			
			wait for 1ns;
			assert (w_R = "0000") report "Fail AND_4bit -> Test 1" severity error;
			
			-- Test 2
			w_A <= "0101";
			w_B <= "1100";
			
			wait for 1ns;
			assert (w_R = "0100") report "Fail AND_4bit -> Test 2" severity error;
					
			-- Test 3
			w_A <= "1111";
			w_B <= "1111";
			
			wait for 1ns;
			assert (w_R = "1111") report "Fail AND_4bit -> Test 3" severity error;	
		
		-----------------------------------------------------------------------------
		-- "OR" BLOCK TEST
		w_SEL <= "101";
		
			-- Test 1
			w_A <= "1001";
			w_B <= "1001";
			
			wait for 1ns;
			assert (w_R = "1001") report "Fail OR_4bit -> Test 1" severity error;
			
			-- Test 2
			w_A <= "0101";
			w_B <= "1100";
			
			wait for 1ns;
			assert (w_R = "1101") report "Fail OR_4bit -> Test 2" severity error;
					
			-- Test 3
			w_A <= "1010";
			w_B <= "0101";
			
			wait for 1ns;
			assert (w_R = "1111") report "Fail OR_4bit -> Test 3" severity error;
		
		-----------------------------------------------------------------------------
		-- "XOR" BLOCK TEST
		w_SEL <= "110";
		
			-- Test 1
			w_A <= "1111";
			w_B <= "0000";
			
			wait for 1ns;
			assert (w_R = "1111") report "Fail XOR_4bit -> Test 1" severity error;
			
			-- Test 2
			w_A <= "0101";
			w_B <= "1100";
			
			wait for 1ns;
			assert (w_R = "1001") report "Fail XOR_4bit -> Test 2" severity error;
					
			-- Test 3
			w_A <= "1100";
			w_B <= "1111";
			
			wait for 1ns;
			assert (w_R = "0011") report "Fail XOR_4bit -> Test 3" severity error;
		
		-----------------------------------------------------------------------------
		-- INVERTER BLOCK TEST
		w_SEL <= "111";
		
			-- Test 1
			w_A <= "1111";
			
			wait for 1ns;
			assert (w_R = "0000") report "Fail INVERTER_4bit -> Test 1" severity error;
			
			-- Test 2
			w_A <= "0101";
			
			wait for 1ns;
			assert (w_R = "1010") report "Fail INVERTER_4bit -> Test 2" severity error;
					
			-- Test 3
			w_A <= "1100";
			
			wait for 1ns;
			assert (w_R = "0011") report "Fail INVERTER_4bit -> Test 3" severity error;
		wait;
	end process;
end architecture arch_ula_4bit_tb;