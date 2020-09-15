####################################################################
# Exercício 06 - 
# Mostra a compilação de um laço For
####################################################################
# Trecho em C:
#
# for (i==0; i<10; i++)
#     j++;
#

.text

main:
	addi $s0, $zero, 0 # i = 0
LOOP: 	slti $t0, $s0, 10  # se i<10 então $t0=1 senão $t0=0
	beq $t0, $zero, EXIT
	add $s1, $s1, 1
	add $s0, $s0, 1
	j LOOP
EXIT: nop