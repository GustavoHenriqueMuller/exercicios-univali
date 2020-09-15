###############################################################################
# Exercício 03 - Patterson pag. 65
# Mostra a compilação de um comando de desvio condicional (if-then) simples
###############################################################################
# Trecho em C:
# if (i!=j)
#     f = g + h;
# f = f - i;      // também poderia ser escrito assim:  f -= i;

.text
main:
	addi $s0, $zero, 20 # i
	addi $s1, $zero, 20 # j
	addi $s2, $zero, 60 # f
	addi $s3, $zero, 20 # g
	addi $s4, $zero, 90 # h
	
	beq $s0, $s1, L1
	add $s2, $s3, $s4
L1:	sub $s2, $s2, $s0