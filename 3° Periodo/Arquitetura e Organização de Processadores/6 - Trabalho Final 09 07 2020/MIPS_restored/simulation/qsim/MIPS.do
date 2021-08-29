onerror {exit -code 1}
vlib work
vlog -work work MIPS.vo
vlog -work work Simulacao.vwf.vt
vsim -novopt -c -t 1ps -L cycloneiii_ver -L altera_ver -L altera_mf_ver -L 220model_ver -L sgate work.mips_mono_vlg_vec_tst -voptargs="+acc"
vcd file -direction MIPS.msim.vcd
vcd add -internal mips_mono_vlg_vec_tst/*
vcd add -internal mips_mono_vlg_vec_tst/i1/*
run -all
quit -f
