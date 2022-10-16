library IEEE;
use IEEE.std_logic_1164.all;

entity circuit_channel_sharing_with_fault is
  port
  (
    i_SW: in std_logic_vector (1 downto 0);
	 i_SEL: in std_logic;
	 i_BT: in std_logic;
	 o_LED: out std_logic_vector (1 downto 0)
  );
end circuit_channel_sharing_with_fault;

architecture arch_circuit_channel_sharing_with_fault of circuit_channel_sharing_with_fault is
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
	
  signal o_MUX: std_logic;
  signal o_MUX_BT: std_logic;
	
begin
	u_mux2_1bit: mux2_1bit port map (i_SEL, i_SW(0), i_SW(1), o_MUX);
	u_demux1_2bit: demux1_2bit port map (o_MUX_BT, i_SEL, O_LED);
	
	process(i_SW, i_SEL, i_BT)
	begin
		o_MUX_BT <= o_MUX XOR i_BT;
	end process;
end arch_circuit_channel_sharing_with_fault;