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
	u_ULA: ula_4bit port map (w_A, w_B, w_SEL, w_LOAD, w_CLK, w_R);

	process
	begin
		w_LOAD <= '1';
		
		-- Test 1 - ADD
		w_A <= "1001";
		w_B <= "0011";
		w_SEL <= "000";
		
			-- Clock pulse
			w_CLK <= '0';
			wait for 1ns;
			w_CLK <= '1';
			wait for 1ns;
			w_CLK <= '0';
			
			wait for 1ns;
			assert (w_R = "1100") report "Fail ula_4bit -> Test 1" severity error;
			
		-- Test 2 - SUBTRACT
		w_A <= "1001";
		w_B <= "0011";
		w_SEL <= "001";
		
			-- Clock pulse
			w_CLK <= '0';
			wait for 1ns;
			w_CLK <= '1';
			wait for 1ns;
			w_CLK <= '0';
			
			wait for 1ns;
			assert (w_R = "0110") report "Fail ula_4bit -> Test 2" severity error;
			
		-- Test 3 - INCREMENT
		w_A <= "1101";
		w_SEL <= "010";
		
			-- Clock pulse
			w_CLK <= '0';
			wait for 1ns;
			w_CLK <= '1';
			wait for 1ns;
			w_CLK <= '0';
			
			wait for 1ns;
			assert (w_R = "1110") report "Fail ula_4bit -> Test 3" severity error;
			
		-- Test 4 - A
		w_A <= "0011";
		w_SEL <= "011";
		
			-- Clock pulse
			w_CLK <= '0';
			wait for 1ns;
			w_CLK <= '1';
			wait for 1ns;
			w_CLK <= '0';
			
			wait for 1ns;
			assert (w_R = "0011") report "Fail ula_4bit -> Test 4" severity error;
			
		-- Test 5 - AND
		w_A <= "1101";
		w_B <= "1110";
		w_SEL <= "100";
		
			-- Clock pulse
			w_CLK <= '0';
			wait for 1ns;
			w_CLK <= '1';
			wait for 1ns;
			w_CLK <= '0';
			
			wait for 1ns;
			assert (w_R = "1100") report "Fail ula_4bit -> Test 5" severity error;
			
		-- Test 6 - OR
		w_A <= "1001";
		w_B <= "0011";
		w_SEL <= "101";
		
			-- Clock pulse
			w_CLK <= '0';
			wait for 1ns;
			w_CLK <= '1';
			wait for 1ns;
			w_CLK <= '0';
			
			wait for 1ns;
			assert (w_R = "1011") report "Fail ula_4bit -> Test 6" severity error;
			
		-- Test 7 - XOR
		w_A <= "1001";
		w_B <= "1011";
		w_SEL <= "110";
		
			-- Clock pulse
			w_CLK <= '0';
			wait for 1ns;
			w_CLK <= '1';
			wait for 1ns;
			w_CLK <= '0';
			
			wait for 1ns;
			assert (w_R = "0010") report "Fail ula_4bit -> Test 7" severity error;
			
		-- Test 8 - INVERTER
		w_A <= "1000";
		w_SEL <= "111";
		
			-- Clock pulse
			w_CLK <= '0';
			wait for 1ns;
			w_CLK <= '1';
			wait for 1ns;
			w_CLK <= '0';
			
			wait for 1ns;
			assert (w_R = "0111") report "Fail ula_4bit -> Test 8" severity error;
		wait;
	end process;
end arch_ula_4bit_tb;