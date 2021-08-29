##################################################################################
# Exercício 04 - Patterson pags. 65/66
# Mostra a compilação de um comando de desvio condicional (if-then-else) com else
##################################################################################
# Trecho em C:
# if (i==j)
#     f = g + h;
# else
#     f = g - h;


.text

main:
	addi $s0, $zero, 12  # i
	addi $s1, $zero, 12 # j
	addi $s2, $zero, 23 # f
	addi $s3, $zero, 12 # g
	addi $s4, $zero, 7  # h
	
	bne $s0, $s1, ELSE
		add $s2, $s3, $s4
		j EXIT
ELSE:	sub $s2, $s3, $s4
EXIT:	nop