	.file	"main.c"
	.text
	.section	.rodata.str1.1,"aMS",@progbits,1
.LC0:
	.string	"iptr is %p\n"
.LC1:
	.string	"iptr's val is %d\n"
.LC2:
	.string	"iptr2 is %p\n"
.LC3:
	.string	"iptr2's val is %d\n"
	.text
	.globl	main
	.type	main, @function
main:
	subq	$24, %rsp
	movb	$3, 15(%rsp)
	movb	$9, 14(%rsp)
	leaq	15(%rsp), %rsi
	movl	$.LC0, %edi
	movl	$0, %eax
	call	printf
	movsbl	15(%rsp), %esi
	movl	$.LC1, %edi
	movl	$0, %eax
	call	printf
	leaq	14(%rsp), %rsi
	movl	$.LC2, %edi
	movl	$0, %eax
	call	printf
	movsbl	14(%rsp), %esi
	movl	$.LC3, %edi
	movl	$0, %eax
	call	printf
	movl	$0, %eax
	addq	$24, %rsp
	ret
	.size	main, .-main
	.ident	"GCC: (SUSE Linux) 15.3.0"
	.section	.note.GNU-stack,"",@progbits
