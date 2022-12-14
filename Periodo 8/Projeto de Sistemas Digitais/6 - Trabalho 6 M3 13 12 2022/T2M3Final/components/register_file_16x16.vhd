library IEEE;
use IEEE.std_logic_1164.all;

entity register_file_16x16 is
	port
	(
		-- Inputs
		i_CLK: in std_logic;
		
		i_RF_W_DATA: in std_logic_vector (15 downto 0);
		i_RF_W: in std_logic;
		i_RF_W_ADDRESS: in std_logic_vector (3 downto 0);
		
		i_RF_RP_ADDRESS: in std_logic_vector (3 downto 0);
		i_RF_RP_READ: in std_logic;
		
		i_RF_RQ_ADDRESS: in std_logic_vector (3 downto 0);
		i_RF_RQ_READ: in std_logic;
		
		-- Outputs
		o_RP_DATA: out std_logic_vector (15 downto 0);
		o_RQ_DATA: out std_logic_vector (15 downto 0)
	);
end register_file_16x16;

architecture arch_register_file_16x16 of register_file_16x16 is

component register_16bit is
	port
	(
		i_A: in std_logic_vector (15 downto 0);
		i_LOAD: in std_logic;
		i_CLR_N: in std_logic;
		i_CLK: in std_logic;
		o_R: out std_logic_vector (15 downto 0)
	);
end component;

component decodifier_16bit is
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
end component;

component mux_16x16bit is
	port
	(
		i_0: in std_logic_vector (15 downto 0);
		i_1: in std_logic_vector (15 downto 0);
		i_2: in std_logic_vector (15 downto 0);
		i_3: in std_logic_vector (15 downto 0);
		i_4: in std_logic_vector (15 downto 0);
		i_5: in std_logic_vector (15 downto 0);
		i_6: in std_logic_vector (15 downto 0);
		i_7: in std_logic_vector (15 downto 0);
		i_8: in std_logic_vector (15 downto 0);
		i_9: in std_logic_vector (15 downto 0);
		i_10: in std_logic_vector (15 downto 0);
		i_11: in std_logic_vector (15 downto 0);
		i_12: in std_logic_vector (15 downto 0);
		i_13: in std_logic_vector (15 downto 0);
		i_14: in std_logic_vector (15 downto 0);
		i_15: in std_logic_vector (15 downto 0);
		
		i_SEL: in std_logic_vector (3 downto 0);
		o_R: out std_logic_vector (15 downto 0)
	);
end component;

signal w_OUT_DECODIFIER_0: std_logic;
signal w_OUT_DECODIFIER_1: std_logic;
signal w_OUT_DECODIFIER_2: std_logic;
signal w_OUT_DECODIFIER_3: std_logic;
signal w_OUT_DECODIFIER_4: std_logic;
signal w_OUT_DECODIFIER_5: std_logic;
signal w_OUT_DECODIFIER_6: std_logic;
signal w_OUT_DECODIFIER_7: std_logic;
signal w_OUT_DECODIFIER_8: std_logic;
signal w_OUT_DECODIFIER_9: std_logic;
signal w_OUT_DECODIFIER_10: std_logic;
signal w_OUT_DECODIFIER_11: std_logic;
signal w_OUT_DECODIFIER_12: std_logic;
signal w_OUT_DECODIFIER_13: std_logic;
signal w_OUT_DECODIFIER_14: std_logic;
signal w_OUT_DECODIFIER_15: std_logic;

signal w_LOAD_REGISTER_0: std_logic;
signal w_LOAD_REGISTER_1: std_logic;
signal w_LOAD_REGISTER_2: std_logic;
signal w_LOAD_REGISTER_3: std_logic;
signal w_LOAD_REGISTER_4: std_logic;
signal w_LOAD_REGISTER_5: std_logic;
signal w_LOAD_REGISTER_6: std_logic;
signal w_LOAD_REGISTER_7: std_logic;
signal w_LOAD_REGISTER_8: std_logic;
signal w_LOAD_REGISTER_9: std_logic;
signal w_LOAD_REGISTER_10: std_logic;
signal w_LOAD_REGISTER_11: std_logic;
signal w_LOAD_REGISTER_12: std_logic;
signal w_LOAD_REGISTER_13: std_logic;
signal w_LOAD_REGISTER_14: std_logic;
signal w_LOAD_REGISTER_15: std_logic;

signal w_OUT_REGISTER_0: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_1: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_2: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_3: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_4: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_5: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_6: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_7: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_8: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_9: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_10: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_11: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_12: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_13: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_14: std_logic_vector (15 downto 0);
signal w_OUT_REGISTER_15: std_logic_vector (15 downto 0);
	
begin
	u_DECODIFIER: decodifier_16bit port map (
		i_RF_W_ADDRESS,
    	w_OUT_DECODIFIER_0,
		w_OUT_DECODIFIER_1,
		w_OUT_DECODIFIER_2,
		w_OUT_DECODIFIER_3,
		w_OUT_DECODIFIER_4,
		w_OUT_DECODIFIER_5,
		w_OUT_DECODIFIER_6,
		w_OUT_DECODIFIER_7,
		w_OUT_DECODIFIER_8,
		w_OUT_DECODIFIER_9,
		w_OUT_DECODIFIER_10,
		w_OUT_DECODIFIER_11,
		w_OUT_DECODIFIER_12,
		w_OUT_DECODIFIER_13,
		w_OUT_DECODIFIER_14,
		w_OUT_DECODIFIER_15
	);
	
	w_LOAD_REGISTER_0 <= w_OUT_DECODIFIER_0 and i_RF_W;
	w_LOAD_REGISTER_1 <= w_OUT_DECODIFIER_1 and i_RF_W;
	w_LOAD_REGISTER_2 <= w_OUT_DECODIFIER_2 and i_RF_W;
	w_LOAD_REGISTER_3 <= w_OUT_DECODIFIER_3 and i_RF_W;
	w_LOAD_REGISTER_4 <= w_OUT_DECODIFIER_4 and i_RF_W;
	w_LOAD_REGISTER_5 <= w_OUT_DECODIFIER_5 and i_RF_W;
	w_LOAD_REGISTER_6 <= w_OUT_DECODIFIER_6 and i_RF_W;
	w_LOAD_REGISTER_7 <= w_OUT_DECODIFIER_7 and i_RF_W;
	w_LOAD_REGISTER_8 <= w_OUT_DECODIFIER_8 and i_RF_W;
	w_LOAD_REGISTER_9 <= w_OUT_DECODIFIER_9 and i_RF_W;
	w_LOAD_REGISTER_10 <= w_OUT_DECODIFIER_10 and i_RF_W;
	w_LOAD_REGISTER_11 <= w_OUT_DECODIFIER_11 and i_RF_W;
	w_LOAD_REGISTER_12 <= w_OUT_DECODIFIER_12 and i_RF_W;
	w_LOAD_REGISTER_13 <= w_OUT_DECODIFIER_13 and i_RF_W;
	w_LOAD_REGISTER_14 <= w_OUT_DECODIFIER_14 and i_RF_W;
	w_LOAD_REGISTER_15 <= w_OUT_DECODIFIER_15 and i_RF_W;
														  
	u_REGISTER_0: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_0, '1', i_CLK, w_OUT_REGISTER_0);
	u_REGISTER_1: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_1, '1', i_CLK, w_OUT_REGISTER_1);
	u_REGISTER_2: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_2, '1', i_CLK, w_OUT_REGISTER_2);
	u_REGISTER_3: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_3, '1', i_CLK, w_OUT_REGISTER_3);
	u_REGISTER_4: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_4, '1', i_CLK, w_OUT_REGISTER_4);
	u_REGISTER_5: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_5, '1', i_CLK, w_OUT_REGISTER_5);
	u_REGISTER_6: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_6, '1', i_CLK, w_OUT_REGISTER_6);
	u_REGISTER_7: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_7, '1', i_CLK, w_OUT_REGISTER_7);
	u_REGISTER_8: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_8, '1', i_CLK, w_OUT_REGISTER_8);
	u_REGISTER_9: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_9, '1', i_CLK, w_OUT_REGISTER_9);
	u_REGISTER_10: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_10, '1', i_CLK, w_OUT_REGISTER_10);
	u_REGISTER_11: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_11, '1', i_CLK, w_OUT_REGISTER_11);
	u_REGISTER_12: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_12, '1', i_CLK, w_OUT_REGISTER_12);
	u_REGISTER_13: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_13, '1', i_CLK, w_OUT_REGISTER_13);
	u_REGISTER_14: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_14, '1', i_CLK, w_OUT_REGISTER_14);
	u_REGISTER_15: register_16bit port map (i_RF_W_DATA, w_LOAD_REGISTER_15, '1', i_CLK, w_OUT_REGISTER_15);
	
	u_MUX_0: mux_16x16bit port map (
		w_OUT_REGISTER_0,
	   w_OUT_REGISTER_1,
		w_OUT_REGISTER_2,
		w_OUT_REGISTER_3,
		w_OUT_REGISTER_4,
		w_OUT_REGISTER_5,
		w_OUT_REGISTER_6,
		w_OUT_REGISTER_7,
		w_OUT_REGISTER_8,
		w_OUT_REGISTER_9,
		w_OUT_REGISTER_10,
		w_OUT_REGISTER_11,
		w_OUT_REGISTER_12,
		w_OUT_REGISTER_13,
		w_OUT_REGISTER_14,
		w_OUT_REGISTER_15,
		i_RF_RP_ADDRESS,
		o_RP_DATA
	);
	
	u_MUX_1: mux_16x16bit port map (
		w_OUT_REGISTER_0,
	   w_OUT_REGISTER_1,
		w_OUT_REGISTER_2,
		w_OUT_REGISTER_3,
		w_OUT_REGISTER_4,
		w_OUT_REGISTER_5,
		w_OUT_REGISTER_6,
		w_OUT_REGISTER_7,
		w_OUT_REGISTER_8,
		w_OUT_REGISTER_9,
		w_OUT_REGISTER_10,
		w_OUT_REGISTER_11,
		w_OUT_REGISTER_12,
		w_OUT_REGISTER_13,
		w_OUT_REGISTER_14,
		w_OUT_REGISTER_15,
		i_RF_RQ_ADDRESS,
		o_RQ_DATA
	);
	
end arch_register_file_16x16;