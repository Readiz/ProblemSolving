	.file	"test.cpp"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"%d"
	.text
	.p2align 4
	.globl	_Z6getSumv
	.type	_Z6getSumv, @function
_Z6getSumv:
.LFB30:
	.cfi_startproc
	endbr64
	leaq	10000+map(%rip), %rsi
	xorl	%edx, %edx
	leaq	100000000(%rsi), %rdi
.L3:
	leaq	-10000(%rsi), %rax
	.p2align 4,,10
	.p2align 3
.L2:
	movsbl	(%rax), %ecx
	addq	$1, %rax
	addl	%ecx, %edx
	cmpq	%rsi, %rax
	jne	.L2
	leaq	10000(%rax), %rsi
	cmpq	%rdi, %rsi
	jne	.L3
	leaq	.LC0(%rip), %rsi
	movl	$1, %edi
	xorl	%eax, %eax
	jmp	__printf_chk@PLT
	.cfi_endproc
.LFE30:
	.size	_Z6getSumv, .-_Z6getSumv
	.section	.rodata.str1.1
.LC1:
	.string	"%d %d %d"
	.section	.text.startup,"ax",@progbits
	.p2align 4
	.globl	main
	.type	main, @function
main:
.LFB31:
	.cfi_startproc
	endbr64
	pushq	%r15
	.cfi_def_cfa_offset 16
	.cfi_offset 15, -16
	pushq	%r14
	.cfi_def_cfa_offset 24
	.cfi_offset 14, -24
	pushq	%r13
	.cfi_def_cfa_offset 32
	.cfi_offset 13, -32
	pushq	%r12
	.cfi_def_cfa_offset 40
	.cfi_offset 12, -40
	leaq	map(%rip), %r12
	pushq	%rbp
	.cfi_def_cfa_offset 48
	.cfi_offset 6, -48
	leaq	.LC1(%rip), %rbp
	pushq	%rbx
	.cfi_def_cfa_offset 56
	.cfi_offset 3, -56
	subq	$56, %rsp
	.cfi_def_cfa_offset 112
	movq	%fs:40, %rax
	movq	%rax, 40(%rsp)
	xorl	%eax, %eax
	leaq	36(%rsp), %r15
	leaq	32(%rsp), %r14
	movl	$10000, 12(%rsp)
	leaq	28(%rsp), %r13
.L9:
	movl	$10000, %ebx
	.p2align 4,,10
	.p2align 3
.L8:
	movq	%r15, %rcx
	movq	%r14, %rdx
	movq	%r13, %rsi
	movq	%rbp, %rdi
	xorl	%eax, %eax
	call	__isoc99_scanf@PLT
	movslq	28(%rsp), %rax
	movslq	32(%rsp), %rdx
	movl	36(%rsp), %ecx
	imulq	$10000, %rax, %rax
	addq	%r12, %rax
	movb	%cl, (%rax,%rdx)
	subl	$1, %ebx
	jne	.L8
	subl	$1, 12(%rsp)
	jne	.L9
	call	_Z6getSumv
	movq	40(%rsp), %rax
	xorq	%fs:40, %rax
	jne	.L14
	addq	$56, %rsp
	.cfi_remember_state
	.cfi_def_cfa_offset 56
	xorl	%eax, %eax
	popq	%rbx
	.cfi_def_cfa_offset 48
	popq	%rbp
	.cfi_def_cfa_offset 40
	popq	%r12
	.cfi_def_cfa_offset 32
	popq	%r13
	.cfi_def_cfa_offset 24
	popq	%r14
	.cfi_def_cfa_offset 16
	popq	%r15
	.cfi_def_cfa_offset 8
	ret
.L14:
	.cfi_restore_state
	call	__stack_chk_fail@PLT
	.cfi_endproc
.LFE31:
	.size	main, .-main
	.globl	map
	.bss
	.align 32
	.type	map, @object
	.size	map, 100000000
map:
	.zero	100000000
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
