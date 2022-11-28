library IEEE;
use IEEE.std_logic_1164.all;

entity mdc_top_tb is
end mdc_top_tb;

architecture arch_mdc_top_tb of mdc_top_tb is

component mdc_top is
	port
	(
		i_X: in std_logic_vector (7 downto 0);
		i_Y: in std_logic_vector (7 downto 0);
		i_GO: in std_logic;
		i_CLK: in std_logic;
		
		o_D: out std_logic_vector (7 downto 0);
		o_RDY: out std_logic
	);
end component;

signal w_X: std_logic_vector (7 downto 0);
signal w_Y: std_logic_vector (7 downto 0);
signal w_GO: std_logic;
signal w_CLK: std_logic;
signal w_D: std_logic_vector (7 downto 0);
signal w_RDY: std_logic;

begin
	u_MDC_TOP: mdc_top port map (w_X, w_Y, w_GO, w_CLK, w_D, w_RDY);

	process
	begin
		-- Test 1 (12 and 4)
		w_X <= "00001100";
		w_Y <= "00000100";
		
		w_GO <= '1';
		wait for 8 ns;
		w_GO <= '0';
		
		wait for 80 ns;
		assert (w_D = "00000100") report "Fail mdc_top_tb -> Test 1" severity error;
		
		-- Test 2 (16 and 40)
		w_X <= "00010000";
		w_Y <= "00101000";
		
		w_GO <= '1';
		wait for 8 ns;
		w_GO <= '0';
		
		wait for 80 ns;
		assert (w_D = "00001000") report "Fail mdc_top_tb -> Test 2" severity error;
		
		-- Test 3 (5 and 5)
		w_X <= "00000101";
		w_Y <= "00000101";
		
		w_GO <= '1';
		wait for 8 ns;
		w_GO <= '0';
		
		wait for 80 ns;
		assert (w_D = "00000101") report "Fail mdc_top_tb -> Test 3" severity error;
	
		wait;
	end process;
end arch_mdc_top_tb;