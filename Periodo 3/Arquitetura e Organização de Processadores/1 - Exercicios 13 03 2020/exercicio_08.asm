####################################################################
# Exercício 08 - Patterson pag. 74
# Mostra a compilação de um procedimento que chama outro, neste caso,
# o fatorial recursivo
####################################################################
# Trecho em C:
# int fact (int n) {
#    if (n<1)
#        return 1;
#    else
#        return (n * fact(n-1));
#

.text

j main

fact:
	slti $t0, $a0, 1
	beq $t0, $zero, again
	addi $v0, $zero, 1
	jr $ra	
again:	sub $t1, $a0, 1
	addi $a0, $t1, 0
	mul $a0, $a0, $v0
	jal fact

main:
	addi $a0, $zero, 5
	jal fact
	nop