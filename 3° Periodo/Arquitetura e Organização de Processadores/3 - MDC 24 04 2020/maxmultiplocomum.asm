.data

textvar1: .asciiz "Digite o primeiro número:\n"
textvar2: .asciiz "Digite o segundo número:\n"
result: .asciiz "Resultado: "

.text
j main

mdc:
loopStart:
	beq $a0, $a1, loopEnd
	bge $a0, $a1, else
	sub $a1, $a1, $a0
	j loopStart
else:
	sub $a0, $a0, $a1
	j loopStart
loopEnd:
	addi $v0, $a1, 0
	jr $ra

main:
	# Mostrando texto na tela
	la $a0, textvar1
	li $v0, 4
	syscall

	# Pegando o primeiro valor
	li $v0, 5
	syscall
	addi $s0, $v0, 0
	
	# Mostrando texto na tela
	la $a0, textvar2
	li $v0, 4
	syscall
	
	# Pegando o segundo valor
	li $v0, 5
	syscall
	addi $s1, $v0, 0	
	
	# Chamando o procedimento
	addi $a0, $s0, 0
	addi $a1, $s1, 0
	jal mdc
	addi $s2, $v0, 0
	
	# Mostrando o texto
	la $a0, result
	li $v0, 4
	syscall
	
	# Mostrando o valor na tela
	addi $a0, $s2, 0
	li $v0, 1
	syscall
	
	
	
	
	
	
	
	
	
	
	
	