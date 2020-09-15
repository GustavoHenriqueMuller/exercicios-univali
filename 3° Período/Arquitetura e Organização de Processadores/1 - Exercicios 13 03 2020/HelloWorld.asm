.data
msg:.asciiz "Hello World!"

.text
main:
	addi $v0, $zero, 4
	la $a0, msg
	syscall
	addi $v0, $zero, 7
	syscall