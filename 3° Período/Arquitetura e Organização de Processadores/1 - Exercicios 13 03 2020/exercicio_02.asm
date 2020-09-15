####################################################################
# Exercício 02 - Patterson pags. 54/55/56
# Mostra a compilação de um comando de atribuição em C usando Array
####################################################################
# Trecho em C:
#
# A[12] = h + A[8]


.data

Array_A: .word 0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150

.text

main:
	addi $s2, $zero, 1
	la $s3, Array_A
	
	lw $t0, 32($s3)
	add $t0, $s2, $t0
	sw $t0, 48($s3)
