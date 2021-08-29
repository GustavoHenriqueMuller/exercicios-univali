# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 01
# Grupo: - Gustavo Henrique Stahl Müller
#        - Paulo Henrique Rohling

.data

textVar1: .asciiz "Type the value of X: \n"
textVar2: .asciiz "\nType the value of Y: \n"
textSum: .asciiz "\nSum of X and Y: \n"

.text
	# Prints text
	la $a0, textVar1
	li $v0, 4
	syscall
	
	# Gets the value of $t0
	li $v0, 5
	syscall
	add $s0, $zero, $v0
	
	# Prints text
	la $a0, textVar2
	li $v0, 4
	syscall
	
	# Gets the value of $t1
	li $v0, 5
	syscall
	add $s1, $zero, $v0
	
	# Prints text
	la $a0, textSum
	li $v0, 4
	syscall
	
	# Shows the sum of $t0 and $t1
	add $a0, $s0, $s1
	li $v0, 1
	syscall
