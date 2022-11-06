-- Copyright (C) 2022  Intel Corporation. All rights reserved.
-- Your use of Intel Corporation's design tools, logic functions 
-- and other software and tools, and any partner logic 
-- functions, and any output files from any of the foregoing 
-- (including device programming or simulation files), and any 
-- associated documentation or information are expressly subject 
-- to the terms and conditions of the Intel Program License 
-- Subscription Agreement, the Intel Quartus Prime License Agreement,
-- the Intel FPGA IP License Agreement, or other applicable license
-- agreement, including, without limitation, that your use is for
-- the sole purpose of programming logic devices manufactured by
-- Intel and sold by Intel or its authorized distributors.  Please
-- refer to the applicable agreement for further details, at
-- https://fpgasoftware.intel.com/eula.

-- *****************************************************************************
-- This file contains a Vhdl test bench with test vectors .The test vectors     
-- are exported from a vector file in the Quartus Waveform Editor and apply to  
-- the top level entity of the current Quartus project .The user can use this   
-- testbench to simulate his design using a third-party simulation tool .       
-- *****************************************************************************
-- Generated on "11/06/2022 10:40:46"
                                                             
-- Vhdl Test Bench(with test vectors) for design  :          ula_4bit
-- 
-- Simulation tool : 3rd Party
-- 

LIBRARY ieee;                                               
USE ieee.std_logic_1164.all;                                

ENTITY ula_4bit_vhd_vec_tst IS
END ula_4bit_vhd_vec_tst;
ARCHITECTURE ula_4bit_arch OF ula_4bit_vhd_vec_tst IS
-- constants                                                 
-- signals                                                   
SIGNAL i_A : STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL i_B : STD_LOGIC_VECTOR(3 DOWNTO 0);
SIGNAL i_CLK : STD_LOGIC;
SIGNAL i_LOAD : STD_LOGIC;
SIGNAL i_SEL : STD_LOGIC_VECTOR(2 DOWNTO 0);
SIGNAL o_R : STD_LOGIC_VECTOR(3 DOWNTO 0);
COMPONENT ula_4bit
	PORT (
	i_A : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
	i_B : IN STD_LOGIC_VECTOR(3 DOWNTO 0);
	i_CLK : IN STD_LOGIC;
	i_LOAD : IN STD_LOGIC;
	i_SEL : IN STD_LOGIC_VECTOR(2 DOWNTO 0);
	o_R : BUFFER STD_LOGIC_VECTOR(3 DOWNTO 0)
	);
END COMPONENT;
BEGIN
	i1 : ula_4bit
	PORT MAP (
-- list connections between master ports and signals
	i_A => i_A,
	i_B => i_B,
	i_CLK => i_CLK,
	i_LOAD => i_LOAD,
	i_SEL => i_SEL,
	o_R => o_R
	);
-- i_A[3]
t_prcs_i_A_3: PROCESS
BEGIN
	i_A(3) <= '0';
WAIT;
END PROCESS t_prcs_i_A_3;
-- i_A[2]
t_prcs_i_A_2: PROCESS
BEGIN
	i_A(2) <= '0';
WAIT;
END PROCESS t_prcs_i_A_2;
-- i_A[1]
t_prcs_i_A_1: PROCESS
BEGIN
	i_A(1) <= '0';
WAIT;
END PROCESS t_prcs_i_A_1;
-- i_A[0]
t_prcs_i_A_0: PROCESS
BEGIN
	i_A(0) <= '0';
WAIT;
END PROCESS t_prcs_i_A_0;
-- i_B[3]
t_prcs_i_B_3: PROCESS
BEGIN
	i_B(3) <= '0';
WAIT;
END PROCESS t_prcs_i_B_3;
-- i_B[2]
t_prcs_i_B_2: PROCESS
BEGIN
	i_B(2) <= '0';
WAIT;
END PROCESS t_prcs_i_B_2;
-- i_B[1]
t_prcs_i_B_1: PROCESS
BEGIN
	i_B(1) <= '0';
WAIT;
END PROCESS t_prcs_i_B_1;
-- i_B[0]
t_prcs_i_B_0: PROCESS
BEGIN
	i_B(0) <= '0';
WAIT;
END PROCESS t_prcs_i_B_0;
-- i_SEL[2]
t_prcs_i_SEL_2: PROCESS
BEGIN
	i_SEL(2) <= '0';
WAIT;
END PROCESS t_prcs_i_SEL_2;
-- i_SEL[1]
t_prcs_i_SEL_1: PROCESS
BEGIN
	i_SEL(1) <= '0';
WAIT;
END PROCESS t_prcs_i_SEL_1;
-- i_SEL[0]
t_prcs_i_SEL_0: PROCESS
BEGIN
	i_SEL(0) <= '0';
WAIT;
END PROCESS t_prcs_i_SEL_0;

-- i_CLK
t_prcs_i_CLK: PROCESS
BEGIN
	i_CLK <= '0';
WAIT;
END PROCESS t_prcs_i_CLK;

-- i_LOAD
t_prcs_i_LOAD: PROCESS
BEGIN
	i_LOAD <= '0';
WAIT;
END PROCESS t_prcs_i_LOAD;
END ula_4bit_arch;
