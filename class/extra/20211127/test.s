	.file	"test.cpp"
	.text
	.globl	map
	.bss
	.align 32
	.type	map, @object
	.size	map, 100000000
map:
	.zero	100000000
	.section	.rodata
.LC0:
	.string	"%d"
	.text
	.globl	_Z6getSumv
	.type	_Z6getSumv, @function
_Z6getSumv:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$16, %rsp
	movl	$0, -12(%rbp)
	movl	$0, -8(%rbp)
.L5:
	cmpl	$9999, -8(%rbp)
	jg	.L2
	movl	$0, -4(%rbp)
.L4:
	cmpl	$9999, -4(%rbp)
	jg	.L3
	movl	-4(%rbp), %eax
	cltq
	movl	-8(%rbp), %edx
	movslq	%edx, %rdx
	imulq	$10000, %rdx, %rdx
	addq	%rax, %rdx
	leaq	map(%rip), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	addl	%eax, -12(%rbp)
	addl	$1, -4(%rbp)
	jmp	.L4
.L3:
	addl	$1, -8(%rbp)
	jmp	.L5
.L2:
	movl	-12(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rdi
	movl	$0, %eax
	call	printf@PLT
	nop
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	_Z6getSumv, .-_Z6getSumv
	.section	.rodata
.LC1:
	.string	"%d %d %d"
	.text
	.globl	main
	.type	main, @function
main:
.LFB1:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -16(%rbp)
.L10:
	cmpl	$9999, -16(%rbp)
	jg	.L7
	movl	$0, -12(%rbp)
.L9:
	cmpl	$9999, -12(%rbp)
	jg	.L8
	leaq	-20(%rbp), %rcx
	leaq	-24(%rbp), %rdx
	leaq	-28(%rbp), %rax
	movq	%rax, %rsi
	leaq	.LC1(%rip), %rdi
	movl	$0, %eax
	call	__isoc99_scanf@PLT
	movl	-20(%rbp), %ecx
	movl	-28(%rbp), %edx
	movl	-24(%rbp), %eax
	cltq
	movslq	%edx, %rdx
	imulq	$10000, %rdx, %rdx
	addq	%rax, %rdx
	leaq	map(%rip), %rax
	addq	%rdx, %rax
	movb	%cl, (%rax)
	addl	$1, -12(%rbp)
	jmp	.L9
.L8:
	addl	$1, -16(%rbp)
	jmp	.L10
.L7:
	call	_Z6getSumv
	movl	$0, %eax
	movq	-8(%rbp), %rsi
	xorq	%fs:40, %rsi
	je	.L12
	call	__stack_chk_fail@PLT
.L12:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	 1f - 0f
	.long	 4f - 1f
	.long	 5
0:
	.string	 "GNU"
1:
	.align 8
	.long	 0xc0000002
	.long	 3f - 2f
2:
	.long	 0x3
3:
	.align 8
4:
