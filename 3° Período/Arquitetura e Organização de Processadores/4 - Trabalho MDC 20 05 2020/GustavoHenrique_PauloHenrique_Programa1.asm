# Disciplina: Arquitetura e Organização de Computadores
# Atividade: Avaliação 03 – Programação de Procedimentos
# Grupo: - Gustavo Henrique Stahl Müller
#        - Paulo Henrique Rohling 


.data
	labelBeginning: .asciiz "CALCULADORA DE MDC\n\n"
	labelTexto1: .asciiz "Digite o primeiro número: "
	labelTexto2: .asciiz "Digite o segundo número: "
	labelResultado: .asciiz "\nResultado: "

.text
j main

rec_mdc:
	# Ssalva os argumentos e o endereço de retorno na pilha.
	subi $sp, $sp, 16
	sw $a0, 0($sp)	
	sw $a1, 4($sp)
	sw $ra, 8($sp)
	sw $s0, 12($sp)
	
	bne $a0, $a1, elseif
	
	# Retorna o primeiro argumento se $a0 = $a1.
	move $v0, $a0
	
	# Termina a chamada de função.
	j end_rec_mdc
	
elseif:
	bge $a0, $a1, else
	
	# Retorna rec_mdc($a0, $a1-$a0) se $a0 < $a1.
	sub $s0, $a1, $a0
	move $a1, $s0
	jal rec_mdc
	
	# Termina a chamada de função.
	j end_rec_mdc
	
else:
	# Retorna rec_mdc($a0, $a0-$a1) se $a0 >= $a1.
	sub $s0, $a0, $a1
	move $a0, $s0
	jal rec_mdc
	
	# Termina a chamada de função.
	j end_rec_mdc
	
end_rec_mdc:
	# Retorna os valores salvos na pilha.
	lw $a0, 0($sp)
	lw $a1, 4($sp)
	lw $ra, 8($sp)
	lw $s0, 12($sp)
	addi $sp, $sp, 16

	# Termina a chamada de função.
	jr $ra

main:
	# Imprime o texto de começo.
	la $a0, labelBeginning
	li $v0, 4
	syscall

	# Imprime o primeiro texto.
	la $a0, labelTexto1
	li $v0, 4
	syscall
	
	# Pega o primeiro valor e salva ele em $s0.
	li $v0, 5
	syscall
	move $s0, $v0
	
	# Imprime o segundo texto.
	la $a0, labelTexto2
	li $v0, 4
	syscall
	
	# Pega o segundo valor e salva ele em $s1.
	li $v0, 5
	syscall
	move $s1, $v0
	
	# Chama o procedimento recursivo de fatorial.
	move $a0, $s0
	move $a1, $s1
	jal rec_mdc
	
	# Ao retornar, coloca o resultado em $s2.
	move $s2, $v0
	
	# Mostra o texto do resultado na tela.
	la $a0, labelResultado
	li $v0, 4
	syscall
	
	# Mostra o valor final concatenado com o texto.
	move $a0, $s2
	li $v0, 1
	syscall
