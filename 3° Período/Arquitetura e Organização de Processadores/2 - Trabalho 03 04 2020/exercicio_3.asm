# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 01 – Programação em Linguagem de Montagem
# Exercício 03
# Grupo: - Gustavo Henrique Stahl Müller
#        - Paulo Henrique Rohling

.data
	preText: .asciiz "Value at["
	posText: .asciiz "]: "
	lineBreak: .asciiz "\n"
	array: .word 0, 0, 0, 0, 0, 0, 0, 0
.text
		li $s0, 0 # amount of values read
		la $s6, array # base address of array
READSTART:
		slti $t1, $s0, 8 # if the amount of values read is less than 8
		beq $t1, $zero, READEND
		
		# Reads the value
		li $v0, 5
		syscall
		
		# Sets the value in the vector ($t2 = index of the vector the value will be saved)
		add $t2, $s0, $s0 # $t2 = 2i
		add $t2, $t2, $t2 # $t2 = 4i
		add $t2, $t2, $s6 # $t2 = 4i + base adress
		sw $v0, 0($t2)
		
		addi $s0, $s0, 1 # adds 1 to the amount of values read
		j READSTART
READEND:

		li $s0, 0 # amount of values writed
WRITESTART:	
		slti $t1, $s0, 8 # if the amount of values writed is less than 8
		beq $t1, $zero, WRITEEND
		
		# Gets the value
		add $t2, $s0, $s0 # t2 = 2i
		add $t2, $t2, $t2 # t2 = 4i
		add $t2, $t2, $s6 # t2 = 4i + base adress
		
		lw $t3, 0($t2) # t3 = value in position [i]
		
		# Writes the text before the value
		la $a0, preText
		li $v0, 4
		syscall
		
		# Writes the index
		add $a0, $s0, $zero
		li $v0, 1
		syscall
		
		# Writes the text after the value
		la $a0, posText
		li $v0, 4
		syscall

		# Writes the value
		add $a0, $t3, $zero
		li $v0, 1
		syscall
		
		# Writes linebreak
		la $a0, lineBreak
		li $v0, 4
		syscall
		
		addi $s0, $s0, 1 # adds 1 to the amounnt of values writed
		j WRITESTART
WRITEEND:	
		
		
