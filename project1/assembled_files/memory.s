	.file	"memory.c"
	.section	.rodata
	.align 8
.LC0:
	.string	" \n Source is at : %p new string at destination %p \t"
.LC1:
	.string	"Pointer ERROR"
	.text
	.globl	my_memmove
	.type	my_memmove, @function
my_memmove:
.LFB0:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$112, %rsp
	movq	%rdi, -88(%rbp)
	movq	%rsi, -96(%rbp)
	movl	%edx, -100(%rbp)
	movq	%fs:40, %rax
	movq	%rax, -8(%rbp)
	xorl	%eax, %eax
	movl	$0, -72(%rbp)
	movl	$0, -68(%rbp)
	cmpq	$0, -88(%rbp)
	je	.L2
	leaq	-64(%rbp), %rcx
	movq	-88(%rbp), %rdx
	movl	-100(%rbp), %esi
	movl	-72(%rbp), %eax
	movl	%eax, %edi
	movl	$0, %eax
	call	copying_LOOP
	movl	$0, -72(%rbp)
	movq	-96(%rbp), %rcx
	leaq	-64(%rbp), %rdx
	movl	-100(%rbp), %esi
	movl	-72(%rbp), %eax
	movl	%eax, %edi
	movl	$0, %eax
	call	copying_LOOP
	movq	-96(%rbp), %rdx
	movq	-88(%rbp), %rax
	movq	%rax, %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$0, -72(%rbp)
	jmp	.L3
.L4:
	movl	-72(%rbp), %edx
	movq	-96(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %edi
	call	putchar
	addl	$1, -72(%rbp)
.L3:
	movl	-72(%rbp), %eax
	cmpl	-100(%rbp), %eax
	jb	.L4
	movl	$0, %eax
	jmp	.L6
.L2:
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %eax
.L6:
	movq	-8(%rbp), %rcx
	xorq	%fs:40, %rcx
	je	.L7
	call	__stack_chk_fail
.L7:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	my_memmove, .-my_memmove
	.section	.rodata
.LC2:
	.string	" \n New String is \t"
.LC3:
	.string	"Pointer Error"
	.text
	.globl	my_memzero
	.type	my_memzero, @function
my_memzero:
.LFB1:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movw	$0, -4(%rbp)
	movw	$0, -2(%rbp)
	jmp	.L9
.L10:
	movzwl	-2(%rbp), %eax
	addl	$1, %eax
	movw	%ax, -2(%rbp)
	movzwl	-4(%rbp), %eax
	addl	$1, %eax
	movw	%ax, -4(%rbp)
.L9:
	movzwl	-4(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	testb	%al, %al
	jne	.L10
	movw	$0, -4(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L11
	jmp	.L12
.L13:
	movzwl	-4(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movb	$0, (%rax)
	movzwl	-4(%rbp), %eax
	addl	$1, %eax
	movw	%ax, -4(%rbp)
.L12:
	movzwl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jb	.L13
	movw	$0, -4(%rbp)
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	jmp	.L14
.L15:
	movzwl	-4(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movzbl	%al, %eax
	movl	%eax, %edi
	call	putchar
	movzwl	-4(%rbp), %eax
	addl	$1, %eax
	movw	%ax, -4(%rbp)
.L14:
	movzwl	-4(%rbp), %eax
	cmpw	-2(%rbp), %ax
	jb	.L15
	movl	$10, %edi
	call	putchar
	movl	$0, %eax
	jmp	.L16
.L11:
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$1, %eax
.L16:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE1:
	.size	my_memzero, .-my_memzero
	.section	.rodata
.LC4:
	.string	"\n Reveresed string is \t"
	.text
	.globl	my_reverse
	.type	my_reverse, @function
my_reverse:
.LFB2:
	.cfi_startproc
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movq	%rdi, -24(%rbp)
	movl	%esi, -28(%rbp)
	movw	$0, -4(%rbp)
	cmpq	$0, -24(%rbp)
	je	.L18
	movw	$0, -2(%rbp)
	jmp	.L19
.L20:
	movzwl	-2(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movb	%al, -5(%rbp)
	movzwl	-2(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movl	-28(%rbp), %eax
	movslq	%eax, %rcx
	movzwl	-2(%rbp), %eax
	subq	%rax, %rcx
	movq	%rcx, %rax
	leaq	-1(%rax), %rcx
	movq	-24(%rbp), %rax
	addq	%rcx, %rax
	movzbl	(%rax), %eax
	movb	%al, (%rdx)
	movl	-28(%rbp), %eax
	movslq	%eax, %rdx
	movzwl	-2(%rbp), %eax
	subq	%rax, %rdx
	movq	%rdx, %rax
	leaq	-1(%rax), %rdx
	movq	-24(%rbp), %rax
	addq	%rax, %rdx
	movzbl	-5(%rbp), %eax
	movb	%al, (%rdx)
	movzwl	-2(%rbp), %eax
	addl	$1, %eax
	movw	%ax, -2(%rbp)
.L19:
	movzwl	-2(%rbp), %edx
	movl	-28(%rbp), %eax
	movl	%eax, %ecx
	shrl	$31, %ecx
	addl	%ecx, %eax
	sarl	%eax
	cmpl	%eax, %edx
	jl	.L20
	movl	$.LC4, %edi
	movl	$0, %eax
	call	printf
	jmp	.L21
.L22:
	movzwl	-4(%rbp), %edx
	movq	-24(%rbp), %rax
	addq	%rdx, %rax
	movzbl	(%rax), %eax
	movsbl	%al, %eax
	movl	%eax, %edi
	call	putchar
	movzwl	-4(%rbp), %eax
	addl	$1, %eax
	movw	%ax, -4(%rbp)
.L21:
	movzwl	-4(%rbp), %eax
	cmpl	-28(%rbp), %eax
	jl	.L22
	movl	$0, %eax
	jmp	.L23
.L18:
	movl	$1, %eax
.L23:
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE2:
	.size	my_reverse, .-my_reverse
	.ident	"GCC: (Ubuntu 5.4.0-6ubuntu1~16.04.2) 5.4.0 20160609"
	.section	.note.GNU-stack,"",@progbits
