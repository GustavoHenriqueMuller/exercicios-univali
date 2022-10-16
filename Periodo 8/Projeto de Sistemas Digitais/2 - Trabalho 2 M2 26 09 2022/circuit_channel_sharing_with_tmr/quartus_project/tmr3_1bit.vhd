library IEEE;
use IEEE.std_logic_1164.all;

entity tmr3_1bit is
  port
  (
    i_A: in std_logic;
	 i_B: in std_logic;
	 i_C: in std_logic;
	 o_S: out std_logic
  );
end tmr3_1bit;

architecture arch_tmr3_1bit of tmr3_1bit is
begin
	o_S <= (i_A AND i_B) OR (i_A AND i_C) OR (i_B AND i_C);
end arch_tmr3_1bit;