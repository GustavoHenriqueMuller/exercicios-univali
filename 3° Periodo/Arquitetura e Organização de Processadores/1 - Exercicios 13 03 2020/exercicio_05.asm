####################################################################
# Exercício 05 - Patterson pags. 67
# Mostra a compilação de um laço While
####################################################################
# Trecho em C:
# while (save[i] == k)
#     i = i + j;

.data

Array_save: .word 3, 3, 3, 3, 3, 1, 4, 3, 1

.text
main:
	la $s6, Array_save
	addi $s5, $zero, 3 # k
	addi $s4, $zero, 1 # j
	addi $s3, $zero, 0 # i
	
LOOP: 	add $t1, $s3, $s3  # t1 = 2 * i
      	add $t1, $t1, $t1  # t1 = 4 * i
	add $t1, $t1, $s6  # $t1 = end.base + 4.i (deslocamento) = end. de save[i]
	lw $t0, 0($t1)     # $t0 = save[i]
	
	bne $t0, $s5, EXIT # se save[i] != k goto Exit# se save[i] != k goto Exit
	add $s3, $s3, $s4  # i = i + j
	j LOOP 		   # volta pro loop
EXIT: 	nop		   # faz nada