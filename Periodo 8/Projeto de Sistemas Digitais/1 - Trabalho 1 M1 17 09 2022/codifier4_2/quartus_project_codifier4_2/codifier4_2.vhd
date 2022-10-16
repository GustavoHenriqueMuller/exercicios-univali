library IEEE;
use IEEE.std_logic_1164.all;

entity codifier4_2 is
port
  (
    i_A: in std_logic_vector (3 downto 0);
    o_S: out std_logic_vector (1 downto 0)
  );
end codifier4_2;

architecture arch_codifier4_2 of codifier4_2 is
begin
  o_S(0) <= i_A(1) or i_A(3);
  o_S(1) <= i_A(2) or i_A(3);
end arch_codifier4_2;
