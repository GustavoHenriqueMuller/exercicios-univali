library IEEE;
use IEEE.std_logic_1164.all;

entity circuit_channel_sharing_with_tmr is
  port
  (
    i_SW: in std_logic_vector (1 downto 0);
	 i_SEL: in std_logic;
	 i_BT: in std_logic_vector (2 downto 0);
	 o_LED: out std_logic_vector (1 downto 0)
  );
end circuit_channel_sharing_with_tmr;

architecture arch_circuit_channel_sharing_with_tmr of circuit_channel_sharing_with_tmr is
  component mux2_1bit is
    port
	 (
	   i_SEL : in std_logic;
		i_A : in std_logic;
		i_B : in std_logic;
		o_S : out std_logic
	 );
  end component;
	
  component demux1_2bit is
    port
	 (
	   i_A: in std_logic;
		i_SEL: in std_logic;
		o_S: out std_logic_vector (1 downto 0)
	 );
  end component;
  
  component tmr3_1bit is
    port
	 (
	   i_A: in std_logic;
	   i_B: in std_logic;
	   i_C: in std_logic;
	   o_S: out std_logic
	 );
  end component;
	
  signal o_MUX: std_logic;
  signal o_TMR: std_logic;
	
begin
	mux2_1bit_instance: mux2_1bit port map (i_SEL, i_SW(0), i_SW(1), o_MUX);
	tmr3_1bit_instance: tmr3_1bit port map (o_MUX XOR i_BT(0), o_MUX XOR i_BT(1), o_MUX XOR i_BT(2), o_TMR);
	demux1_2bit_instance: demux1_2bit port map (o_TMR, i_SEL, O_LED);
	
	process(i_SW, i_SEL, i_BT)
	begin
	end process;
end arch_circuit_channel_sharing_with_tmr;