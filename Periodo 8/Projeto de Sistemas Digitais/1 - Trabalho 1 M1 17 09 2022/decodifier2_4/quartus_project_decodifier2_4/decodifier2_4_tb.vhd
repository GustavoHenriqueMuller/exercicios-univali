library IEEE;
use IEEE.std_logic_1164.all;

entity decodifier2_4_tb is
end decodifier2_4_tb;

architecture arch_decodifier2_4_tb of decodifier2_4_tb is
  component decodifier2_4 is
  port
      (
        in_NUMBER: in std_logic_vector (1 downto 0);
        out_S: out std_logic_vector (3 downto 0)
      );
  end component;
  
  signal in_NUMBER: std_logic_vector (1 downto 0);
  signal out_S: std_logic_vector (3 downto 0);

  begin
    decodifier_instance: decodifier2_4 port map(in_NUMBER, out_S);
      
    process
    begin
      in_NUMBER(0) <= '0';
      in_NUMBER(1) <= '0';
      wait for 1ns;
      assert (out_S(3) = '0') report "Fail 0/0 -> output(3) == 1" severity error;
      assert (out_S(2) = '0') report "Fail 0/0 -> output(2) == 1" severity error;
      assert (out_S(1) = '0') report "Fail 0/0 -> output(1) == 1" severity error;
      assert (out_S(0) = '1') report "Fail 0/0 -> output(0) != 1" severity error;
      
      in_NUMBER(0) <= '0';
      in_NUMBER(1) <= '1';
      wait for 1ns;
      assert (out_S(3) = '0') report "Fail 0/1 -> output(3) == 1" severity error;
      assert (out_S(2) = '0') report "Fail 0/1 -> output(2) == 1" severity error;
      assert (out_S(1) = '1') report "Fail 0/1 -> output(1) != 1" severity error;
      assert (out_S(0) = '0') report "Fail 0/1 -> output(0) == 1" severity error;
      
      in_NUMBER(0) <= '1';
      in_NUMBER(1) <= '0';
      wait for 1ns;
      assert (out_S(3) = '0') report "Fail 1/0 -> output(3) == 1" severity error;
      assert (out_S(2) = '1') report "Fail 1/0 -> output(2) != 1" severity error;
      assert (out_S(1) = '0') report "Fail 1/0 -> output(1) == 1" severity error;
      assert (out_S(0) = '0') report "Fail 1/0 -> output(0) == 1" severity error;
      
      in_NUMBER(0) <= '1';
      in_NUMBER(1) <= '1';
      wait for 1ns;
      assert (out_S(3) = '1') report "Fail 1/1 -> output(3) != 1" severity error;
      assert (out_S(2) = '0') report "Fail 1/1 -> output(2) == 1" severity error;
      assert (out_S(1) = '0') report "Fail 1/1 -> output(1) == 1" severity error;
      assert (out_S(0) = '0') report "Fail 1/1 -> output(0) == 1" severity error;
    end process;
end arch_decodifier2_4_tb;