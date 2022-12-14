library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity rom_256x16_im is
	generic 
	(
		DATA_WIDTH : natural := 16;
		ADDRESS_WIDTH : natural := 8
	);

	port 
	(
		addr	: in std_logic_vector (ADDRESS_WIDTH - 1 downto 0);
		q		: out std_logic_vector((DATA_WIDTH -1) downto 0)
	);
end entity;

architecture arch_rom_256x16_im of rom_256x16_im is

	-- Build a 2-D array type for the RoM
	subtype word_t is std_logic_vector((DATA_WIDTH - 1) downto 0);
	type memory_t is array(2 ** ADDRESS_WIDTH - 1 downto 0) of word_t;

	function init_rom
		return memory_t is 
		variable tmp : memory_t := (others => (others => '0'));
	begin
      tmp(0) := "1111000000000100";
		tmp(1) := "0010000000000000";
		tmp(2) := "1111000100000010";
		tmp(3) := "0011001000000001";
		tmp(4) := "0010001000000001";
		tmp(5) := "0011001100000010";
		tmp(6) := "0010001100000000";
		
		for i in 8 to (2 ** ADDRESS_WIDTH - 1) loop
			tmp(i) := "0000000000000000";
		end loop;
		
		return tmp;
	end init_rom;	 

	-- Declare the ROM signal and specify a default value.	Quartus II
	-- will create a memory initialization file (.mif) based on the 
	-- default value.
	signal rom : memory_t := init_rom;

begin
	q <= rom(to_integer(unsigned(addr)));

end arch_rom_256x16_im;
