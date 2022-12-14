library IEEE;
use IEEE.std_logic_1164.all;

entity adder_16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_B: in std_logic_vector (15 downto 0);
		i_CARRY_IN: in std_logic;
		o_R: out std_logic_vector (15 downto 0);
		o_CARRY_OUT: out std_logic
	);
end adder_16bit;

architecture arch_adder_16bit of adder_16bit is

component full_adder_1bit is
	port
	(
		i_A: in std_logic;
		i_B: in std_logic;
		i_CARRY_IN: in std_logic;
		o_R: out std_logic;
		o_CARRY_OUT: out std_logic
	);
end component;

signal w_CARRY_OUT_0: std_logic;
signal w_CARRY_OUT_1: std_logic;
signal w_CARRY_OUT_2: std_logic;
signal w_CARRY_OUT_3: std_logic;
signal w_CARRY_OUT_4: std_logic;
signal w_CARRY_OUT_5: std_logic;
signal w_CARRY_OUT_6: std_logic;
signal w_CARRY_OUT_7: std_logic;
signal w_CARRY_OUT_8: std_logic;
signal w_CARRY_OUT_9: std_logic;
signal w_CARRY_OUT_10: std_logic;
signal w_CARRY_OUT_11: std_logic;
signal w_CARRY_OUT_12: std_logic;
signal w_CARRY_OUT_13: std_logic;
signal w_CARRY_OUT_14: std_logic;	

begin
	u_FULL_ADDER_0: full_adder_1bit port map(i_A(0), i_B(0), i_CARRY_IN, o_R(0), w_CARRY_OUT_0);
	u_FULL_ADDER_1: full_adder_1bit port map(i_A(1), i_B(1), w_CARRY_OUT_0, o_R(1), w_CARRY_OUT_1);
	u_FULL_ADDER_2: full_adder_1bit port map(i_A(2), i_B(2), w_CARRY_OUT_1, o_R(2), w_CARRY_OUT_2);
	u_FULL_ADDER_3: full_adder_1bit port map(i_A(3), i_B(3), w_CARRY_OUT_2, o_R(3), w_CARRY_OUT_3);
	u_FULL_ADDER_4: full_adder_1bit port map(i_A(4), i_B(4), w_CARRY_OUT_3, o_R(4), w_CARRY_OUT_4);
	u_FULL_ADDER_5: full_adder_1bit port map(i_A(5), i_B(5), w_CARRY_OUT_4, o_R(5), w_CARRY_OUT_5);
	u_FULL_ADDER_6: full_adder_1bit port map(i_A(6), i_B(6), w_CARRY_OUT_5, o_R(6), w_CARRY_OUT_6);
	u_FULL_ADDER_7: full_adder_1bit port map(i_A(7), i_B(7), w_CARRY_OUT_6, o_R(7), w_CARRY_OUT_7);
	u_FULL_ADDER_8: full_adder_1bit port map(i_A(8), i_B(8), w_CARRY_OUT_7, o_R(8), w_CARRY_OUT_8);
	u_FULL_ADDER_9: full_adder_1bit port map(i_A(9), i_B(9), w_CARRY_OUT_8, o_R(9), w_CARRY_OUT_9);
	u_FULL_ADDER_10: full_adder_1bit port map(i_A(10), i_B(10), w_CARRY_OUT_9, o_R(10), w_CARRY_OUT_10);
	u_FULL_ADDER_11: full_adder_1bit port map(i_A(11), i_B(11), w_CARRY_OUT_10, o_R(11), w_CARRY_OUT_11);
	u_FULL_ADDER_12: full_adder_1bit port map(i_A(12), i_B(12), w_CARRY_OUT_11, o_R(12), w_CARRY_OUT_12);
	u_FULL_ADDER_13: full_adder_1bit port map(i_A(13), i_B(13), w_CARRY_OUT_12, o_R(13), w_CARRY_OUT_13);
	u_FULL_ADDER_14: full_adder_1bit port map(i_A(14), i_B(14), w_CARRY_OUT_13, o_R(14), w_CARRY_OUT_14);
	u_FULL_ADDER_15: full_adder_1bit port map(i_A(15), i_B(15), w_CARRY_OUT_14, o_R(15), o_CARRY_OUT);
	
end arch_adder_16bit;