# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 02
# Grupo: - Gustavo Henrique Stahl Müller
#        - Paulo Henrique Rohling

.data
	textIndex: .asciiz "Index: "
	lineBreak: .asciiz "\n"

.text
	li $s0, 0 # index
	li $t0, 1 # true
	
START:
	slti $t1, $s0, 10 # if index < 10
	bne $t1, $t0, EXIT # goto EXIT
	
	li $v0, 4 # print string operation
	la $a0, textIndex
	syscall # prints text
	
	li $v0, 1 # print integer operation
	add $a0, $s0, $zero # loads the index in the argument
	syscall # prints the index
	
	li $v0, 4 # print string operation
	la $a0, lineBreak
	syscall # prints linebreak
	
	addi $s0, $s0, 1 # i++
	j START
EXIT:	nop # quit