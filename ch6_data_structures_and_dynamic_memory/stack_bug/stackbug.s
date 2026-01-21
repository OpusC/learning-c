	.file	"stackbug.c"
	.text
	.section	.rodata
.LC0:
	.string	"enter name"
	.text
	.globl	getName
	.type	getName, @function
getName:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp			# push value from register rbp onto the stack. this was the old stack pointer prepared from main
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp		# move value from rsp into register rbp
	.cfi_def_cfa_register 6
	subq	$48, %rsp		# subtract 48 bytes stack pointer, allowing for space for local variables
	movq	%fs:40, %rax		# move value of 40 into register rax (apparently this is the stack canary)
	movq	%rax, -8(%rbp)		# store the canary value in the stack at -8(rbp)
	xorl	%eax, %eax		# zero the value in register eax
	leaq	.LC0(%rip), %rax	# load the value of the string LCO into register rax
	movq	%rax, %rdi		# move the string LC0 from register rax to rdi, required setup for calling procedure puts to print
	call	puts@PLT		# required setup for calling puts to print
	movq	stdin(%rip), %rdx	# load address of std into register rdx
	leaq	-48(%rbp), %rax		# load the address of rbp -48 into register rax. this is the start of the buffer for user input
	movl	$30, %esi		# move value of 30 into register esi. this is required setup for fgets procedure, this value specifies max num of bytes to read from input
	movq	%rax, %rdi		# move value of rax into rdi. rax was the start of the buffer of user input. fgets procedure looks at register rdi for the buffer pointer
	call	fgets@PLT		# call fgets procedure
	nop				# no instruction, padding(?)
	movq	-8(%rbp), %rdx		# load the stack canary value into register rdx to check if it has been modified
	subq	%fs:40, %rdx		# compare the stack canary value to what it was filled with
	je	.L2			# jump to label l2 if stack canary was unaltered. note that at this point
	call	__stack_chk_fail@PLT
.L2:
	leave				# restore the previous stack frame
	.cfi_def_cfa 7, 8
	ret				# return to code address that was previously stored in the stack. this will be the next address fromt the original call instruction
	.cfi_endproc
.LFE0:
	.size	getName, .-getName
	.section	.rodata
.LC1:
	.string	"name: %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp			# push a value onto the stack, in this case, the value from register rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp		# move a value from register rsp to register rbp. RSP is the current stack pointer and we are duplicating this value before subtracting it
					# in a later instruction
	.cfi_def_cfa_register 6
	subq	$16, %rsp		# subtract 16 bytes from the value in register rsp. This is the current stack pointer
	movl	$0, %eax		# move value of 0 into register eax
	call	getName			# getName function is called (jump to getName label in assembly)
	movq	%rax, -8(%rbp)		# register rax contains return value from getName, only by chance, the compiler didn't explicitly set it
	movq	-8(%rbp), %rax		
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$1, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
