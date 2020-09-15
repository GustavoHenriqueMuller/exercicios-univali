library verilog;
use verilog.vl_types.all;
entity mips_mono is
    port(
        Branch          : out    vl_logic;
        clock           : in     vl_logic;
        Instruction     : out    vl_logic_vector(31 downto 0);
        PC              : out    vl_logic_vector(31 downto 0);
        reset           : in     vl_logic;
        RegDst          : out    vl_logic;
        Operation       : out    vl_logic_vector(2 downto 0);
        ALUOp           : out    vl_logic_vector(1 downto 0);
        RegWrite        : out    vl_logic;
        MemToReg        : out    vl_logic;
        MemWrite        : out    vl_logic;
        ALUSrc          : out    vl_logic;
        clkSys          : out    vl_logic;
        \function\      : out    vl_logic_vector(5 downto 0);
        imed16          : out    vl_logic_vector(15 downto 0);
        nextPC          : out    vl_logic_vector(31 downto 0);
        op              : out    vl_logic_vector(31 downto 26);
        rd              : out    vl_logic_vector(15 downto 11);
        rs              : out    vl_logic_vector(25 downto 21);
        rt              : out    vl_logic_vector(20 downto 16);
        shamt           : out    vl_logic_vector(10 downto 6)
    );
end mips_mono;
