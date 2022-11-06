library IEEE;
use IEEE.std_logic_1164.all;

entity register_4bit_tb is
end register_4bit_tb;

architecture arch_register_4bit_tb of register_4bit_tb is

component register_4bit is
	port
	(
		i_A: in std_logic_vector (3 downto 0);
		i_LOAD: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (3 downto 0)
	);
end component;

signal w_A: std_logic_vector (3 downto 0);
signal w_LOAD: std_logic;
signal w_CLK: std_logic;
signal w_R: std_logic_vector (3 downto 0);

begin
	u_REGISTER: register_4bit port map (w_A, w_LOAD, w_CLK, w_R);

	process
	begin
		-- Test 1
		w_A <= "1001";
		w_LOAD <= '1';
		
		-- Clock pulse
		w_CLK <= '0';
		wait for 1ns;
		w_CLK <= '1';
		wait for 1ns;
		w_CLK <= '0';
		
		wait for 1ns;
		assert (w_R = "1001") report "Fail register_4bit -> Test 1" severity error;
		
		-- Test 2
		w_A <= "1101";
		w_LOAD <= '0';
		
		-- Clock pulse
		w_CLK <= '0';
		wait for 1ns;
		w_CLK <= '1';
		wait for 1ns;
		w_CLK <= '0';
		
		wait for 1ns;
		assert (w_R = "1001") report "Fail register_4bit -> Test 2" severity error;
		
		-- Test 3
		w_LOAD <= '1';
		
		-- Clock pulse
		w_CLK <= '0';
		wait for 1ns;
		w_CLK <= '1';
		wait for 1ns;
		w_CLK <= '0';
		
		wait for 1ns;
		assert (w_R = "1101") report "Fail register_4bit -> Test 3" severity error;
	
		wait;
	end process;
end arch_register_4bit_tb;