library IEEE;
use IEEE.std_logic_1164.all;

entity decodifier2_4 is
port
  (
    i_A: in std_logic_vector (1 downto 0);
    o_S: out std_logic_vector (3 downto 0)
  );
end decodifier2_4;

architecture arch_decodifier2_4 of decodifier2_4 is
begin
  o_S(3) <= i_A(1) and i_A(0);
  o_S(2) <= i_A(1) and not i_A(0);
  o_S(1) <= not i_A(1) and i_A(0);
  o_S(0) <= not i_A(1) and not i_A(0);
end arch_decodifier2_4;
