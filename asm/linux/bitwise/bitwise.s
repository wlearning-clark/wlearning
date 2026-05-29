	.file	"bitwise.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"binary of 7: %0b\n"
.LC1:
	.string	"binary of -7: %0b\n"
.LC2:
	.string	"binary of ~7: %0b\n"
.LC3:
	.string	"binary of ~(-7): %0b\n"
.LC5:
	.string	"binary of 3.14: %0b\n"
	.text
	.globl	main
	.type	main, @function
main:
	subq	$8, %rsp
	movl	$7, %esi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movl	$-7, %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	movl	$-8, %esi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movl	$6, %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movsd	.LC4(%rip), %xmm0
	movl	$.LC5, %edi
	movl	$1, %eax
	call	printf
	movl	$-8, %eax
	addq	$8, %rsp
	ret
	.size	main, .-main
	.section	.rodata.cst8,"aM",@progbits,8
	.align 8
.LC4:
	.long	1374389535
	.long	1074339512
	.ident	"GCC: (SUSE Linux) 15.2.1 20260202"
	.section	.note.GNU-stack,"",@progbits
