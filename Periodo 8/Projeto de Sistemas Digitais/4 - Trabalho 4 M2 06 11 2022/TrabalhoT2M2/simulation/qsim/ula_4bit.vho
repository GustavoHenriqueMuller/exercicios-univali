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

-- VENDOR "Altera"
-- PROGRAM "Quartus Prime"
-- VERSION "Version 21.1.1 Build 850 06/23/2022 SJ Lite Edition"

-- DATE "11/06/2022 10:40:47"

-- 
-- Device: Altera 5CGXFC7C7F23C8 Package FBGA484
-- 

-- 
-- This VHDL file should be used for Questa Intel FPGA (VHDL) only
-- 

LIBRARY ALTERA;
LIBRARY ALTERA_LNSIM;
LIBRARY CYCLONEV;
LIBRARY IEEE;
USE ALTERA.ALTERA_PRIMITIVES_COMPONENTS.ALL;
USE ALTERA_LNSIM.ALTERA_LNSIM_COMPONENTS.ALL;
USE CYCLONEV.CYCLONEV_COMPONENTS.ALL;
USE IEEE.STD_LOGIC_1164.ALL;

ENTITY 	ula_4bit IS
    PORT (
	i_A : IN std_logic_vector(3 DOWNTO 0);
	i_B : IN std_logic_vector(3 DOWNTO 0);
	i_SEL : IN std_logic_vector(2 DOWNTO 0);
	i_LOAD : IN std_logic;
	i_CLK : IN std_logic;
	o_R : BUFFER std_logic_vector(3 DOWNTO 0)
	);
END ula_4bit;

-- Design Ports Information
-- o_R[0]	=>  Location: PIN_M21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- o_R[1]	=>  Location: PIN_L17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- o_R[2]	=>  Location: PIN_N20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- o_R[3]	=>  Location: PIN_P18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_A[0]	=>  Location: PIN_N21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_B[0]	=>  Location: PIN_K17,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_SEL[1]	=>  Location: PIN_K21,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_SEL[2]	=>  Location: PIN_N16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_SEL[0]	=>  Location: PIN_L19,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_CLK	=>  Location: PIN_M16,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_LOAD	=>  Location: PIN_L18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_A[1]	=>  Location: PIN_M20,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_B[1]	=>  Location: PIN_K22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_B[2]	=>  Location: PIN_M22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_A[2]	=>  Location: PIN_M18,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_B[3]	=>  Location: PIN_L22,	 I/O Standard: 2.5 V,	 Current Strength: Default
-- i_A[3]	=>  Location: PIN_N19,	 I/O Standard: 2.5 V,	 Current Strength: Default


ARCHITECTURE structure OF ula_4bit IS
SIGNAL gnd : std_logic := '0';
SIGNAL vcc : std_logic := '1';
SIGNAL unknown : std_logic := 'X';
SIGNAL devoe : std_logic := '1';
SIGNAL devclrn : std_logic := '1';
SIGNAL devpor : std_logic := '1';
SIGNAL ww_devoe : std_logic;
SIGNAL ww_devclrn : std_logic;
SIGNAL ww_devpor : std_logic;
SIGNAL ww_i_A : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_i_B : std_logic_vector(3 DOWNTO 0);
SIGNAL ww_i_SEL : std_logic_vector(2 DOWNTO 0);
SIGNAL ww_i_LOAD : std_logic;
SIGNAL ww_i_CLK : std_logic;
SIGNAL ww_o_R : std_logic_vector(3 DOWNTO 0);
SIGNAL \~QUARTUS_CREATED_GND~I_combout\ : std_logic;
SIGNAL \i_CLK~input_o\ : std_logic;
SIGNAL \i_CLK~inputCLKENA0_outclk\ : std_logic;
SIGNAL \i_B[0]~input_o\ : std_logic;
SIGNAL \i_SEL[1]~input_o\ : std_logic;
SIGNAL \i_A[0]~input_o\ : std_logic;
SIGNAL \i_SEL[0]~input_o\ : std_logic;
SIGNAL \i_SEL[2]~input_o\ : std_logic;
SIGNAL \mux_instance|Mux3~0_combout\ : std_logic;
SIGNAL \i_LOAD~input_o\ : std_logic;
SIGNAL \i_A[1]~input_o\ : std_logic;
SIGNAL \i_B[1]~input_o\ : std_logic;
SIGNAL \mux_instance|Mux2~1_combout\ : std_logic;
SIGNAL \mux_instance|Mux2~0_combout\ : std_logic;
SIGNAL \mux_instance|Mux2~2_combout\ : std_logic;
SIGNAL \adder_instance|full_adder_instance_1|o_CARRY_OUT~0_combout\ : std_logic;
SIGNAL \i_B[2]~input_o\ : std_logic;
SIGNAL \mux_instance|Mux3~1_combout\ : std_logic;
SIGNAL \i_A[2]~input_o\ : std_logic;
SIGNAL \mux_instance|Mux1~1_combout\ : std_logic;
SIGNAL \mux_instance|Mux1~0_combout\ : std_logic;
SIGNAL \mux_instance|Mux1~2_combout\ : std_logic;
SIGNAL \subtractor_instance|adder_instance|full_adder_instance_2|o_R~combout\ : std_logic;
SIGNAL \mux_instance|Mux1~3_combout\ : std_logic;
SIGNAL \i_B[3]~input_o\ : std_logic;
SIGNAL \i_A[3]~input_o\ : std_logic;
SIGNAL \incrementer_instance|adder|full_adder_instance_2|o_CARRY_OUT~0_combout\ : std_logic;
SIGNAL \mux_instance|Mux0~4_combout\ : std_logic;
SIGNAL \subtractor_instance|adder_instance|full_adder_instance_3|o_R~0_combout\ : std_logic;
SIGNAL \adder_instance|full_adder_instance_3|o_R~combout\ : std_logic;
SIGNAL \mux_instance|Mux0~0_combout\ : std_logic;
SIGNAL \register_instance|o_R\ : std_logic_vector(3 DOWNTO 0);
SIGNAL \ALT_INV_i_A[3]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_B[3]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_A[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_B[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_B[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_A[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_SEL[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_SEL[2]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_SEL[1]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_B[0]~input_o\ : std_logic;
SIGNAL \ALT_INV_i_A[0]~input_o\ : std_logic;
SIGNAL \mux_instance|ALT_INV_Mux2~1_combout\ : std_logic;
SIGNAL \mux_instance|ALT_INV_Mux2~0_combout\ : std_logic;
SIGNAL \mux_instance|ALT_INV_Mux0~4_combout\ : std_logic;
SIGNAL \incrementer_instance|adder|full_adder_instance_2|ALT_INV_o_CARRY_OUT~0_combout\ : std_logic;
SIGNAL \adder_instance|full_adder_instance_3|ALT_INV_o_R~combout\ : std_logic;
SIGNAL \subtractor_instance|adder_instance|full_adder_instance_3|ALT_INV_o_R~0_combout\ : std_logic;
SIGNAL \mux_instance|ALT_INV_Mux1~2_combout\ : std_logic;
SIGNAL \mux_instance|ALT_INV_Mux1~1_combout\ : std_logic;
SIGNAL \adder_instance|full_adder_instance_1|ALT_INV_o_CARRY_OUT~0_combout\ : std_logic;
SIGNAL \subtractor_instance|adder_instance|full_adder_instance_2|ALT_INV_o_R~combout\ : std_logic;
SIGNAL \mux_instance|ALT_INV_Mux3~1_combout\ : std_logic;
SIGNAL \mux_instance|ALT_INV_Mux1~0_combout\ : std_logic;

BEGIN

ww_i_A <= i_A;
ww_i_B <= i_B;
ww_i_SEL <= i_SEL;
ww_i_LOAD <= i_LOAD;
ww_i_CLK <= i_CLK;
o_R <= ww_o_R;
ww_devoe <= devoe;
ww_devclrn <= devclrn;
ww_devpor <= devpor;
\ALT_INV_i_A[3]~input_o\ <= NOT \i_A[3]~input_o\;
\ALT_INV_i_B[3]~input_o\ <= NOT \i_B[3]~input_o\;
\ALT_INV_i_A[2]~input_o\ <= NOT \i_A[2]~input_o\;
\ALT_INV_i_B[2]~input_o\ <= NOT \i_B[2]~input_o\;
\ALT_INV_i_B[1]~input_o\ <= NOT \i_B[1]~input_o\;
\ALT_INV_i_A[1]~input_o\ <= NOT \i_A[1]~input_o\;
\ALT_INV_i_SEL[0]~input_o\ <= NOT \i_SEL[0]~input_o\;
\ALT_INV_i_SEL[2]~input_o\ <= NOT \i_SEL[2]~input_o\;
\ALT_INV_i_SEL[1]~input_o\ <= NOT \i_SEL[1]~input_o\;
\ALT_INV_i_B[0]~input_o\ <= NOT \i_B[0]~input_o\;
\ALT_INV_i_A[0]~input_o\ <= NOT \i_A[0]~input_o\;
\mux_instance|ALT_INV_Mux2~1_combout\ <= NOT \mux_instance|Mux2~1_combout\;
\mux_instance|ALT_INV_Mux2~0_combout\ <= NOT \mux_instance|Mux2~0_combout\;
\mux_instance|ALT_INV_Mux0~4_combout\ <= NOT \mux_instance|Mux0~4_combout\;
\incrementer_instance|adder|full_adder_instance_2|ALT_INV_o_CARRY_OUT~0_combout\ <= NOT \incrementer_instance|adder|full_adder_instance_2|o_CARRY_OUT~0_combout\;
\adder_instance|full_adder_instance_3|ALT_INV_o_R~combout\ <= NOT \adder_instance|full_adder_instance_3|o_R~combout\;
\subtractor_instance|adder_instance|full_adder_instance_3|ALT_INV_o_R~0_combout\ <= NOT \subtractor_instance|adder_instance|full_adder_instance_3|o_R~0_combout\;
\mux_instance|ALT_INV_Mux1~2_combout\ <= NOT \mux_instance|Mux1~2_combout\;
\mux_instance|ALT_INV_Mux1~1_combout\ <= NOT \mux_instance|Mux1~1_combout\;
\adder_instance|full_adder_instance_1|ALT_INV_o_CARRY_OUT~0_combout\ <= NOT \adder_instance|full_adder_instance_1|o_CARRY_OUT~0_combout\;
\subtractor_instance|adder_instance|full_adder_instance_2|ALT_INV_o_R~combout\ <= NOT \subtractor_instance|adder_instance|full_adder_instance_2|o_R~combout\;
\mux_instance|ALT_INV_Mux3~1_combout\ <= NOT \mux_instance|Mux3~1_combout\;
\mux_instance|ALT_INV_Mux1~0_combout\ <= NOT \mux_instance|Mux1~0_combout\;

-- Location: IOOBUF_X89_Y37_N56
\o_R[0]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \register_instance|o_R\(0),
	devoe => ww_devoe,
	o => ww_o_R(0));

-- Location: IOOBUF_X89_Y37_N22
\o_R[1]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \register_instance|o_R\(1),
	devoe => ww_devoe,
	o => ww_o_R(1));

-- Location: IOOBUF_X89_Y35_N79
\o_R[2]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \register_instance|o_R\(2),
	devoe => ww_devoe,
	o => ww_o_R(2));

-- Location: IOOBUF_X89_Y9_N56
\o_R[3]~output\ : cyclonev_io_obuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	open_drain_output => "false",
	shift_series_termination_control => "false")
-- pragma translate_on
PORT MAP (
	i => \register_instance|o_R\(3),
	devoe => ww_devoe,
	o => ww_o_R(3));

-- Location: IOIBUF_X89_Y35_N61
\i_CLK~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_CLK,
	o => \i_CLK~input_o\);

-- Location: CLKCTRL_G10
\i_CLK~inputCLKENA0\ : cyclonev_clkena
-- pragma translate_off
GENERIC MAP (
	clock_type => "global clock",
	disable_mode => "low",
	ena_register_mode => "always enabled",
	ena_register_power_up => "high",
	test_syn => "high")
-- pragma translate_on
PORT MAP (
	inclk => \i_CLK~input_o\,
	outclk => \i_CLK~inputCLKENA0_outclk\);

-- Location: IOIBUF_X89_Y37_N4
\i_B[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_B(0),
	o => \i_B[0]~input_o\);

-- Location: IOIBUF_X89_Y38_N38
\i_SEL[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_SEL(1),
	o => \i_SEL[1]~input_o\);

-- Location: IOIBUF_X89_Y35_N95
\i_A[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_A(0),
	o => \i_A[0]~input_o\);

-- Location: IOIBUF_X89_Y38_N4
\i_SEL[0]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_SEL(0),
	o => \i_SEL[0]~input_o\);

-- Location: IOIBUF_X89_Y35_N44
\i_SEL[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_SEL(2),
	o => \i_SEL[2]~input_o\);

-- Location: LABCELL_X88_Y37_N0
\mux_instance|Mux3~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux3~0_combout\ = ( \i_SEL[0]~input_o\ & ( \i_SEL[2]~input_o\ & ( (!\i_SEL[1]~input_o\ & ((\i_A[0]~input_o\) # (\i_B[0]~input_o\))) # (\i_SEL[1]~input_o\ & ((!\i_A[0]~input_o\))) ) ) ) # ( !\i_SEL[0]~input_o\ & ( \i_SEL[2]~input_o\ & ( 
-- (!\i_B[0]~input_o\ & (\i_SEL[1]~input_o\ & \i_A[0]~input_o\)) # (\i_B[0]~input_o\ & (!\i_SEL[1]~input_o\ $ (!\i_A[0]~input_o\))) ) ) ) # ( \i_SEL[0]~input_o\ & ( !\i_SEL[2]~input_o\ & ( !\i_A[0]~input_o\ $ (((!\i_B[0]~input_o\) # (\i_SEL[1]~input_o\))) ) 
-- ) ) # ( !\i_SEL[0]~input_o\ & ( !\i_SEL[2]~input_o\ & ( !\i_A[0]~input_o\ $ (((!\i_B[0]~input_o\ & !\i_SEL[1]~input_o\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0111100001111000010010110100101100010110000101100111110001111100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_B[0]~input_o\,
	datab => \ALT_INV_i_SEL[1]~input_o\,
	datac => \ALT_INV_i_A[0]~input_o\,
	datae => \ALT_INV_i_SEL[0]~input_o\,
	dataf => \ALT_INV_i_SEL[2]~input_o\,
	combout => \mux_instance|Mux3~0_combout\);

-- Location: IOIBUF_X89_Y38_N21
\i_LOAD~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_LOAD,
	o => \i_LOAD~input_o\);

-- Location: FF_X88_Y37_N1
\register_instance|o_R[0]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \i_CLK~inputCLKENA0_outclk\,
	d => \mux_instance|Mux3~0_combout\,
	ena => \i_LOAD~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \register_instance|o_R\(0));

-- Location: IOIBUF_X89_Y37_N38
\i_A[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_A(1),
	o => \i_A[1]~input_o\);

-- Location: IOIBUF_X89_Y38_N55
\i_B[1]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_B(1),
	o => \i_B[1]~input_o\);

-- Location: LABCELL_X88_Y37_N18
\mux_instance|Mux2~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux2~1_combout\ = ( \i_SEL[0]~input_o\ & ( \i_B[1]~input_o\ & ( (!\i_A[1]~input_o\ & ((!\i_SEL[1]~input_o\) # (\i_SEL[2]~input_o\))) # (\i_A[1]~input_o\ & (!\i_SEL[2]~input_o\ $ (!\i_SEL[1]~input_o\))) ) ) ) # ( !\i_SEL[0]~input_o\ & ( 
-- \i_B[1]~input_o\ & ( !\i_A[1]~input_o\ $ (((!\i_SEL[1]~input_o\ & ((\i_SEL[2]~input_o\) # (\i_B[0]~input_o\))))) ) ) ) # ( \i_SEL[0]~input_o\ & ( !\i_B[1]~input_o\ & ( !\i_A[1]~input_o\ $ (((!\i_SEL[2]~input_o\) # (!\i_SEL[1]~input_o\))) ) ) ) # ( 
-- !\i_SEL[0]~input_o\ & ( !\i_B[1]~input_o\ & ( (!\i_SEL[2]~input_o\ & (!\i_A[1]~input_o\ $ (((!\i_B[0]~input_o\ & !\i_SEL[1]~input_o\))))) # (\i_SEL[2]~input_o\ & (((\i_A[1]~input_o\ & \i_SEL[1]~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0110000011000011001100110011110010010011110011001100111100111100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_B[0]~input_o\,
	datab => \ALT_INV_i_A[1]~input_o\,
	datac => \ALT_INV_i_SEL[2]~input_o\,
	datad => \ALT_INV_i_SEL[1]~input_o\,
	datae => \ALT_INV_i_SEL[0]~input_o\,
	dataf => \ALT_INV_i_B[1]~input_o\,
	combout => \mux_instance|Mux2~1_combout\);

-- Location: LABCELL_X88_Y37_N42
\mux_instance|Mux2~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux2~0_combout\ = ( \i_SEL[0]~input_o\ & ( \i_B[1]~input_o\ & ( (!\i_SEL[2]~input_o\ & (!\i_A[1]~input_o\ $ (((\i_SEL[1]~input_o\) # (\i_B[0]~input_o\))))) # (\i_SEL[2]~input_o\ & (((!\i_A[1]~input_o\) # (!\i_SEL[1]~input_o\)))) ) ) ) # ( 
-- !\i_SEL[0]~input_o\ & ( \i_B[1]~input_o\ & ( !\i_A[1]~input_o\ $ (!\i_SEL[2]~input_o\ $ (!\i_SEL[1]~input_o\)) ) ) ) # ( \i_SEL[0]~input_o\ & ( !\i_B[1]~input_o\ & ( !\i_A[1]~input_o\ $ (((!\i_SEL[2]~input_o\ & ((!\i_B[0]~input_o\) # 
-- (\i_SEL[1]~input_o\))) # (\i_SEL[2]~input_o\ & ((!\i_SEL[1]~input_o\))))) ) ) ) # ( !\i_SEL[0]~input_o\ & ( !\i_B[1]~input_o\ & ( (\i_A[1]~input_o\ & ((!\i_SEL[2]~input_o\) # (\i_SEL[1]~input_o\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0011000000110011011000110011110011000011001111001001111100111100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_B[0]~input_o\,
	datab => \ALT_INV_i_A[1]~input_o\,
	datac => \ALT_INV_i_SEL[2]~input_o\,
	datad => \ALT_INV_i_SEL[1]~input_o\,
	datae => \ALT_INV_i_SEL[0]~input_o\,
	dataf => \ALT_INV_i_B[1]~input_o\,
	combout => \mux_instance|Mux2~0_combout\);

-- Location: LABCELL_X88_Y37_N9
\mux_instance|Mux2~2\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux2~2_combout\ = ( \i_A[0]~input_o\ & ( \mux_instance|Mux2~1_combout\ ) ) # ( !\i_A[0]~input_o\ & ( \mux_instance|Mux2~0_combout\ ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000111100001111010101010101010100001111000011110101010101010101",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \mux_instance|ALT_INV_Mux2~1_combout\,
	datac => \mux_instance|ALT_INV_Mux2~0_combout\,
	datae => \ALT_INV_i_A[0]~input_o\,
	combout => \mux_instance|Mux2~2_combout\);

-- Location: FF_X88_Y37_N10
\register_instance|o_R[1]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \i_CLK~inputCLKENA0_outclk\,
	d => \mux_instance|Mux2~2_combout\,
	ena => \i_LOAD~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \register_instance|o_R\(1));

-- Location: LABCELL_X88_Y36_N27
\adder_instance|full_adder_instance_1|o_CARRY_OUT~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \adder_instance|full_adder_instance_1|o_CARRY_OUT~0_combout\ = ( \i_B[1]~input_o\ & ( ((\i_A[0]~input_o\ & \i_B[0]~input_o\)) # (\i_A[1]~input_o\) ) ) # ( !\i_B[1]~input_o\ & ( (\i_A[0]~input_o\ & (\i_A[1]~input_o\ & \i_B[0]~input_o\)) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000100000001000000010000000100110111001101110011011100110111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_A[0]~input_o\,
	datab => \ALT_INV_i_A[1]~input_o\,
	datac => \ALT_INV_i_B[0]~input_o\,
	dataf => \ALT_INV_i_B[1]~input_o\,
	combout => \adder_instance|full_adder_instance_1|o_CARRY_OUT~0_combout\);

-- Location: IOIBUF_X89_Y36_N38
\i_B[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_B(2),
	o => \i_B[2]~input_o\);

-- Location: LABCELL_X88_Y36_N15
\mux_instance|Mux3~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux3~1_combout\ = (!\i_SEL[1]~input_o\ & !\i_SEL[2]~input_o\)

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "1010101000000000101010100000000010101010000000001010101000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_SEL[1]~input_o\,
	datad => \ALT_INV_i_SEL[2]~input_o\,
	combout => \mux_instance|Mux3~1_combout\);

-- Location: IOIBUF_X89_Y36_N21
\i_A[2]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_A(2),
	o => \i_A[2]~input_o\);

-- Location: LABCELL_X88_Y36_N33
\mux_instance|Mux1~1\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux1~1_combout\ = ( \i_A[2]~input_o\ & ( (\mux_instance|Mux3~1_combout\ & (!\i_SEL[0]~input_o\ & (!\adder_instance|full_adder_instance_1|o_CARRY_OUT~0_combout\ $ (\i_B[2]~input_o\)))) ) ) # ( !\i_A[2]~input_o\ & ( 
-- (\mux_instance|Mux3~1_combout\ & (!\i_SEL[0]~input_o\ & (!\adder_instance|full_adder_instance_1|o_CARRY_OUT~0_combout\ $ (!\i_B[2]~input_o\)))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000011000000000000001100000000000001001000000000000100100000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \adder_instance|full_adder_instance_1|ALT_INV_o_CARRY_OUT~0_combout\,
	datab => \ALT_INV_i_B[2]~input_o\,
	datac => \mux_instance|ALT_INV_Mux3~1_combout\,
	datad => \ALT_INV_i_SEL[0]~input_o\,
	dataf => \ALT_INV_i_A[2]~input_o\,
	combout => \mux_instance|Mux1~1_combout\);

-- Location: LABCELL_X88_Y36_N12
\mux_instance|Mux1~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux1~0_combout\ = (!\i_SEL[1]~input_o\ & ((!\i_B[2]~input_o\ & (\i_A[2]~input_o\ & \i_SEL[0]~input_o\)) # (\i_B[2]~input_o\ & ((\i_SEL[0]~input_o\) # (\i_A[2]~input_o\))))) # (\i_SEL[1]~input_o\ & (!\i_A[2]~input_o\ $ (((!\i_B[2]~input_o\ & 
-- !\i_SEL[0]~input_o\)))))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0001011001111010000101100111101000010110011110100001011001111010",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_SEL[1]~input_o\,
	datab => \ALT_INV_i_B[2]~input_o\,
	datac => \ALT_INV_i_A[2]~input_o\,
	datad => \ALT_INV_i_SEL[0]~input_o\,
	combout => \mux_instance|Mux1~0_combout\);

-- Location: LABCELL_X88_Y36_N36
\mux_instance|Mux1~2\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux1~2_combout\ = ( !\i_SEL[2]~input_o\ & ( \i_SEL[1]~input_o\ & ( !\i_A[2]~input_o\ $ (((!\i_A[1]~input_o\) # ((!\i_A[0]~input_o\) # (\i_SEL[0]~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000001010110010101010000000000000000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_A[2]~input_o\,
	datab => \ALT_INV_i_A[1]~input_o\,
	datac => \ALT_INV_i_A[0]~input_o\,
	datad => \ALT_INV_i_SEL[0]~input_o\,
	datae => \ALT_INV_i_SEL[2]~input_o\,
	dataf => \ALT_INV_i_SEL[1]~input_o\,
	combout => \mux_instance|Mux1~2_combout\);

-- Location: LABCELL_X88_Y36_N48
\subtractor_instance|adder_instance|full_adder_instance_2|o_R\ : cyclonev_lcell_comb
-- Equation(s):
-- \subtractor_instance|adder_instance|full_adder_instance_2|o_R~combout\ = ( \i_A[0]~input_o\ & ( \i_B[1]~input_o\ & ( !\i_B[2]~input_o\ $ (!\i_A[2]~input_o\ $ (!\i_A[1]~input_o\)) ) ) ) # ( !\i_A[0]~input_o\ & ( \i_B[1]~input_o\ & ( !\i_B[2]~input_o\ $ 
-- (!\i_A[2]~input_o\ $ (((!\i_A[1]~input_o\) # (\i_B[0]~input_o\)))) ) ) ) # ( \i_A[0]~input_o\ & ( !\i_B[1]~input_o\ & ( !\i_B[2]~input_o\ $ (!\i_A[2]~input_o\) ) ) ) # ( !\i_A[0]~input_o\ & ( !\i_B[1]~input_o\ & ( !\i_B[2]~input_o\ $ (!\i_A[2]~input_o\ $ 
-- (((\i_B[0]~input_o\ & !\i_A[1]~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0110100100111100001111000011110011000011011010011100001100111100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_B[0]~input_o\,
	datab => \ALT_INV_i_B[2]~input_o\,
	datac => \ALT_INV_i_A[2]~input_o\,
	datad => \ALT_INV_i_A[1]~input_o\,
	datae => \ALT_INV_i_A[0]~input_o\,
	dataf => \ALT_INV_i_B[1]~input_o\,
	combout => \subtractor_instance|adder_instance|full_adder_instance_2|o_R~combout\);

-- Location: LABCELL_X88_Y36_N6
\mux_instance|Mux1~3\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux1~3_combout\ = ( !\i_SEL[2]~input_o\ & ( (((\i_SEL[0]~input_o\ & (\subtractor_instance|adder_instance|full_adder_instance_2|o_R~combout\ & !\i_SEL[1]~input_o\))) # (\mux_instance|Mux1~2_combout\)) # (\mux_instance|Mux1~1_combout\) ) ) # ( 
-- \i_SEL[2]~input_o\ & ( ((((\mux_instance|Mux1~2_combout\)) # (\mux_instance|Mux1~0_combout\))) # (\mux_instance|Mux1~1_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "on",
	lut_mask => "0101011111111111010111111111111101010101111111110101111111111111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \mux_instance|ALT_INV_Mux1~1_combout\,
	datab => \ALT_INV_i_SEL[0]~input_o\,
	datac => \mux_instance|ALT_INV_Mux1~0_combout\,
	datad => \mux_instance|ALT_INV_Mux1~2_combout\,
	datae => \ALT_INV_i_SEL[2]~input_o\,
	dataf => \ALT_INV_i_SEL[1]~input_o\,
	datag => \subtractor_instance|adder_instance|full_adder_instance_2|ALT_INV_o_R~combout\,
	combout => \mux_instance|Mux1~3_combout\);

-- Location: FF_X88_Y36_N7
\register_instance|o_R[2]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \i_CLK~inputCLKENA0_outclk\,
	d => \mux_instance|Mux1~3_combout\,
	ena => \i_LOAD~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \register_instance|o_R\(2));

-- Location: IOIBUF_X89_Y36_N55
\i_B[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_B(3),
	o => \i_B[3]~input_o\);

-- Location: IOIBUF_X89_Y36_N4
\i_A[3]~input\ : cyclonev_io_ibuf
-- pragma translate_off
GENERIC MAP (
	bus_hold => "false",
	simulate_z_as => "z")
-- pragma translate_on
PORT MAP (
	i => ww_i_A(3),
	o => \i_A[3]~input_o\);

-- Location: LABCELL_X88_Y36_N24
\incrementer_instance|adder|full_adder_instance_2|o_CARRY_OUT~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \incrementer_instance|adder|full_adder_instance_2|o_CARRY_OUT~0_combout\ = (\i_A[0]~input_o\ & (\i_A[1]~input_o\ & \i_A[2]~input_o\))

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000100000001000000010000000100000001000000010000000100000001",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_A[0]~input_o\,
	datab => \ALT_INV_i_A[1]~input_o\,
	datac => \ALT_INV_i_A[2]~input_o\,
	combout => \incrementer_instance|adder|full_adder_instance_2|o_CARRY_OUT~0_combout\);

-- Location: LABCELL_X88_Y36_N18
\mux_instance|Mux0~4\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux0~4_combout\ = ( \i_SEL[2]~input_o\ & ( \i_SEL[1]~input_o\ & ( !\i_A[3]~input_o\ $ (((!\i_B[3]~input_o\ & !\i_SEL[0]~input_o\))) ) ) ) # ( !\i_SEL[2]~input_o\ & ( \i_SEL[1]~input_o\ & ( !\i_A[3]~input_o\ $ 
-- (((!\incrementer_instance|adder|full_adder_instance_2|o_CARRY_OUT~0_combout\) # (\i_SEL[0]~input_o\))) ) ) ) # ( \i_SEL[2]~input_o\ & ( !\i_SEL[1]~input_o\ & ( (!\i_B[3]~input_o\ & (\i_A[3]~input_o\ & \i_SEL[0]~input_o\)) # (\i_B[3]~input_o\ & 
-- ((\i_SEL[0]~input_o\) # (\i_A[3]~input_o\))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000100010111011100111100001100110110011011001100",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_B[3]~input_o\,
	datab => \ALT_INV_i_A[3]~input_o\,
	datac => \incrementer_instance|adder|full_adder_instance_2|ALT_INV_o_CARRY_OUT~0_combout\,
	datad => \ALT_INV_i_SEL[0]~input_o\,
	datae => \ALT_INV_i_SEL[2]~input_o\,
	dataf => \ALT_INV_i_SEL[1]~input_o\,
	combout => \mux_instance|Mux0~4_combout\);

-- Location: LABCELL_X88_Y36_N42
\subtractor_instance|adder_instance|full_adder_instance_3|o_R~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \subtractor_instance|adder_instance|full_adder_instance_3|o_R~0_combout\ = ( \i_A[0]~input_o\ & ( \i_B[1]~input_o\ & ( (!\i_B[2]~input_o\ & (!\i_A[2]~input_o\ & !\i_A[1]~input_o\)) # (\i_B[2]~input_o\ & ((!\i_A[2]~input_o\) # (!\i_A[1]~input_o\))) ) ) ) # 
-- ( !\i_A[0]~input_o\ & ( \i_B[1]~input_o\ & ( (!\i_B[2]~input_o\ & (!\i_A[2]~input_o\ & ((!\i_A[1]~input_o\) # (\i_B[0]~input_o\)))) # (\i_B[2]~input_o\ & (((!\i_A[2]~input_o\) # (!\i_A[1]~input_o\)) # (\i_B[0]~input_o\))) ) ) ) # ( \i_A[0]~input_o\ & ( 
-- !\i_B[1]~input_o\ & ( (\i_B[2]~input_o\ & !\i_A[2]~input_o\) ) ) ) # ( !\i_A[0]~input_o\ & ( !\i_B[1]~input_o\ & ( (!\i_B[2]~input_o\ & (\i_B[0]~input_o\ & (!\i_A[2]~input_o\ & !\i_A[1]~input_o\))) # (\i_B[2]~input_o\ & ((!\i_A[2]~input_o\) # 
-- ((\i_B[0]~input_o\ & !\i_A[1]~input_o\)))) ) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0111000100110000001100000011000011110011011100011111001100110000",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \ALT_INV_i_B[0]~input_o\,
	datab => \ALT_INV_i_B[2]~input_o\,
	datac => \ALT_INV_i_A[2]~input_o\,
	datad => \ALT_INV_i_A[1]~input_o\,
	datae => \ALT_INV_i_A[0]~input_o\,
	dataf => \ALT_INV_i_B[1]~input_o\,
	combout => \subtractor_instance|adder_instance|full_adder_instance_3|o_R~0_combout\);

-- Location: LABCELL_X88_Y36_N30
\adder_instance|full_adder_instance_3|o_R\ : cyclonev_lcell_comb
-- Equation(s):
-- \adder_instance|full_adder_instance_3|o_R~combout\ = ( \i_A[2]~input_o\ & ( !\i_B[3]~input_o\ $ (!\i_A[3]~input_o\ $ (((\i_B[2]~input_o\) # (\adder_instance|full_adder_instance_1|o_CARRY_OUT~0_combout\)))) ) ) # ( !\i_A[2]~input_o\ & ( !\i_B[3]~input_o\ $ 
-- (!\i_A[3]~input_o\ $ (((\adder_instance|full_adder_instance_1|o_CARRY_OUT~0_combout\ & \i_B[2]~input_o\)))) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0001111011100001000111101110000101111000100001110111100010000111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \adder_instance|full_adder_instance_1|ALT_INV_o_CARRY_OUT~0_combout\,
	datab => \ALT_INV_i_B[2]~input_o\,
	datac => \ALT_INV_i_B[3]~input_o\,
	datad => \ALT_INV_i_A[3]~input_o\,
	dataf => \ALT_INV_i_A[2]~input_o\,
	combout => \adder_instance|full_adder_instance_3|o_R~combout\);

-- Location: LABCELL_X88_Y36_N0
\mux_instance|Mux0~0\ : cyclonev_lcell_comb
-- Equation(s):
-- \mux_instance|Mux0~0_combout\ = ( !\i_SEL[0]~input_o\ & ( (((\adder_instance|full_adder_instance_3|o_R~combout\ & ((\mux_instance|Mux3~1_combout\))))) # (\mux_instance|Mux0~4_combout\) ) ) # ( \i_SEL[0]~input_o\ & ( ((\mux_instance|Mux3~1_combout\ & 
-- (!\i_A[3]~input_o\ $ (!\i_B[3]~input_o\ $ (\subtractor_instance|adder_instance|full_adder_instance_3|o_R~0_combout\))))) # (\mux_instance|Mux0~4_combout\) ) )

-- pragma translate_off
GENERIC MAP (
	extended_lut => "on",
	lut_mask => "0101010101010101010101010101010101011111010111110111110111010111",
	shared_arith => "off")
-- pragma translate_on
PORT MAP (
	dataa => \mux_instance|ALT_INV_Mux0~4_combout\,
	datab => \ALT_INV_i_A[3]~input_o\,
	datac => \ALT_INV_i_B[3]~input_o\,
	datad => \subtractor_instance|adder_instance|full_adder_instance_3|ALT_INV_o_R~0_combout\,
	datae => \ALT_INV_i_SEL[0]~input_o\,
	dataf => \mux_instance|ALT_INV_Mux3~1_combout\,
	datag => \adder_instance|full_adder_instance_3|ALT_INV_o_R~combout\,
	combout => \mux_instance|Mux0~0_combout\);

-- Location: FF_X88_Y36_N1
\register_instance|o_R[3]\ : dffeas
-- pragma translate_off
GENERIC MAP (
	is_wysiwyg => "true",
	power_up => "low")
-- pragma translate_on
PORT MAP (
	clk => \i_CLK~inputCLKENA0_outclk\,
	d => \mux_instance|Mux0~0_combout\,
	ena => \i_LOAD~input_o\,
	devclrn => ww_devclrn,
	devpor => ww_devpor,
	q => \register_instance|o_R\(3));

-- Location: LABCELL_X23_Y59_N0
\~QUARTUS_CREATED_GND~I\ : cyclonev_lcell_comb
-- Equation(s):

-- pragma translate_off
GENERIC MAP (
	extended_lut => "off",
	lut_mask => "0000000000000000000000000000000000000000000000000000000000000000",
	shared_arith => "off")
-- pragma translate_on
;
END structure;


