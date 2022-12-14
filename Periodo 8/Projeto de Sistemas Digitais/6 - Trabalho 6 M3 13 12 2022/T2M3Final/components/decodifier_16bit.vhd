library IEEE;
use IEEE.std_logic_1164.all;

entity decodifier_16bit is
	port
	(
		i_NUMBER: in std_logic_vector (3 downto 0);
		
		o_0: out std_logic;
		o_1: out std_logic;
		o_2: out std_logic;
		o_3: out std_logic;
		o_4: out std_logic;
		o_5: out std_logic;
		o_6: out std_logic;
		o_7: out std_logic;
		o_8: out std_logic;
		o_9: out std_logic;
		o_10: out std_logic;
		o_11: out std_logic;
		o_12: out std_logic;
		o_13: out std_logic;
		o_14: out std_logic;
		o_15: out std_logic
	);
end decodifier_16bit;

architecture arch_decodifier_16bit of decodifier_16bit is

begin
	process (i_NUMBER) begin
		o_0 <= '0';
		o_1 <= '0';
		o_2 <= '0';
		o_3 <= '0';
		o_4 <= '0';
		o_5 <= '0';
		o_6 <= '0';
		o_7 <= '0';
		o_8 <= '0';
		o_9 <= '0';
		o_10 <= '0';
		o_11 <= '0';
		o_12 <= '0';
		o_13 <= '0';
		o_14 <= '0';
		o_15 <= '0';
	
		case (i_NUMBER) is
			when "0000" => o_0 <= '1';
			when "0001" => o_1 <= '1';
			when "0010" => o_2 <= '1';
			when "0011" => o_3 <= '1';
			when "0100" => o_4 <= '1';
			when "0101" => o_5 <= '1';
			when "0110" => o_6 <= '1';
			when "0111" => o_7 <= '1';
			when "1000" => o_8 <= '1';
			when "1001" => o_9 <= '1';
			when "1010" => o_10 <= '1';
			when "1011" => o_11 <= '1';
			when "1100" => o_12 <= '1';
			when "1101" => o_13 <= '1';
			when "1110" => o_14 <= '1';
			when "1111" => o_15 <= '1';
			when others => NULL;
		end case;
	end process;
end arch_decodifier_16bit;