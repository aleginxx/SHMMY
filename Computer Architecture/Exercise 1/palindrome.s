.data
	input: .asciz "MENEM"
	length .word 5
.text
	main:
		la $a0, length
		lw $a0, 0($a0)
		la $a1, input
		la $s0, 0
		addi $s1, length, -1
		jal Palindrome 
		syscall
	Palindrome:
		beq $a0, $zero, True
		beq $a0, 1, True
		lb $t0, $s0($a1)
		lb $t1, $s1($a1)
		bne $t0, $t1, False
		addi $s0, $s0, 1
		addi $s1, $s1, -1
		addi $a0, $a0, -2
		slt $t2, $s0, $s1
		beq $t2, 1, Palindrome
	False:
		addi $v0, $zero, 0
		jr $ra
	True:
		addi $v0, $zero, 1
		jr $ra

