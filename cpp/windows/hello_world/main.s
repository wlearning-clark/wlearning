	.file	"main.cpp"
	.text
	.section	.text$_Z6printfPKcz,"x"
	.linkonce discard
	.globl	_Z6printfPKcz
	.def	_Z6printfPKcz;	.scl	2;	.type	32;	.endef
_Z6printfPKcz:
	pushq	%rbx
	subq	$48, %rsp
	movq	%rcx, 64(%rsp)
	movq	%rdx, 72(%rsp)
	movq	%r8, 80(%rsp)
	movq	%r9, 88(%rsp)
	leaq	72(%rsp), %rbx
	movq	%rbx, 40(%rsp)
	movl	$1, %ecx
	call	*__imp___acrt_iob_func(%rip)
	movq	%rax, %rcx
	movq	%rbx, %r8
	movq	64(%rsp), %rdx
	call	__mingw_vfprintf
	addq	$48, %rsp
	popq	%rbx
	ret
	.section .rdata,"dr"
.LC0:
	.ascii "Hello World.\12\0"
	.text
	.globl	_Z11hello_worldv
	.def	_Z11hello_worldv;	.scl	2;	.type	32;	.endef
_Z11hello_worldv:
	subq	$40, %rsp
	leaq	.LC0(%rip), %rcx
	call	_Z6printfPKcz
	addq	$40, %rsp
	ret
	.section .rdata,"dr"
	.align 8
.LC1:
	.ascii "the answer is: %ld, and the absolute value of it is %ld\12\0"
	.text
	.globl	_Z14absolute_valuev
	.def	_Z14absolute_valuev;	.scl	2;	.type	32;	.endef
_Z14absolute_valuev:
	subq	$40, %rsp
	movl	$41, %r8d
	movl	$41, %edx
	leaq	.LC1(%rip), %rcx
	call	_Z6printfPKcz
	addq	$40, %rsp
	ret
	.globl	_Z26get_absolute_value_passptrPl
	.def	_Z26get_absolute_value_passptrPl;	.scl	2;	.type	32;	.endef
_Z26get_absolute_value_passptrPl:
	movq	%rcx, %rax
	movl	(%rcx), %edx
	testl	%edx, %edx
	jns	.L8
	negl	%edx
	movl	%edx, (%rcx)
.L8:
	ret
	.globl	_Z26get_absolute_value_passvall
	.def	_Z26get_absolute_value_passvall;	.scl	2;	.type	32;	.endef
_Z26get_absolute_value_passvall:
	movl	%ecx, %eax
	negl	%eax
	cmovs	%ecx, %eax
	ret
	.section .rdata,"dr"
	.align 8
.LC2:
	.ascii "the size of unsigned long long is : %zd byte \12\0"
	.align 8
.LC3:
	.ascii "the size of long double is : %zd byte \12\0"
	.align 8
.LC4:
	.ascii "the size of LONG is : %zd byte \12\0"
	.align 8
.LC5:
	.ascii "the size of LONGLONG is : %zd byte \12\0"
	.align 8
.LC6:
	.ascii "the size of INT is : %zd byte \12\0"
	.align 8
.LC7:
	.ascii "the size of INT16 is : %zd byte \12\0"
	.align 8
.LC8:
	.ascii "the size of INT32 is : %zd byte \12\0"
	.align 8
.LC9:
	.ascii "the size of INT64 is : %zd byte \12\0"
	.align 8
.LC10:
	.ascii "the size of LONG32 is : %zd byte \12\0"
	.align 8
.LC11:
	.ascii "the size of LONG64 is : %zd byte \12\0"
	.align 8
.LC12:
	.ascii "the size of SHORT is : %zd byte \12\0"
	.align 8
.LC13:
	.ascii "the size of CHAR is : %zd byte \12\0"
	.align 8
.LC14:
	.ascii "the size of WCHAR is : %zd byte \12\0"
	.align 8
.LC15:
	.ascii "the size of DWORD is : %zd byte \12\0"
	.align 8
.LC16:
	.ascii "the size of DWORDLONG is : %zd byte \12\0"
	.align 8
.LC17:
	.ascii "the size of FLOAT is : %zd byte \12\0"
	.align 8
.LC18:
	.ascii "the size of FLOAT128 is : %zd byte \12\0"
	.align 8
.LC19:
	.ascii "the size of DOUBLE is : %zd byte \12\0"
	.text
	.globl	_Z16sizeof_datatypesv
	.def	_Z16sizeof_datatypesv;	.scl	2;	.type	32;	.endef
_Z16sizeof_datatypesv:
	subq	$40, %rsp
	movl	$8, %edx
	leaq	.LC2(%rip), %rcx
	call	_Z6printfPKcz
	movl	$16, %edx
	leaq	.LC3(%rip), %rcx
	call	_Z6printfPKcz
	movl	$4, %edx
	leaq	.LC4(%rip), %rcx
	call	_Z6printfPKcz
	movl	$8, %edx
	leaq	.LC5(%rip), %rcx
	call	_Z6printfPKcz
	movl	$4, %edx
	leaq	.LC6(%rip), %rcx
	call	_Z6printfPKcz
	movl	$2, %edx
	leaq	.LC7(%rip), %rcx
	call	_Z6printfPKcz
	movl	$4, %edx
	leaq	.LC8(%rip), %rcx
	call	_Z6printfPKcz
	movl	$8, %edx
	leaq	.LC9(%rip), %rcx
	call	_Z6printfPKcz
	movl	$4, %edx
	leaq	.LC10(%rip), %rcx
	call	_Z6printfPKcz
	movl	$8, %edx
	leaq	.LC11(%rip), %rcx
	call	_Z6printfPKcz
	movl	$2, %edx
	leaq	.LC12(%rip), %rcx
	call	_Z6printfPKcz
	movl	$1, %edx
	leaq	.LC13(%rip), %rcx
	call	_Z6printfPKcz
	movl	$2, %edx
	leaq	.LC14(%rip), %rcx
	call	_Z6printfPKcz
	movl	$4, %edx
	leaq	.LC15(%rip), %rcx
	call	_Z6printfPKcz
	movl	$8, %edx
	leaq	.LC16(%rip), %rcx
	call	_Z6printfPKcz
	movl	$4, %edx
	leaq	.LC17(%rip), %rcx
	call	_Z6printfPKcz
	movl	$16, %edx
	leaq	.LC18(%rip), %rcx
	call	_Z6printfPKcz
	movl	$8, %edx
	leaq	.LC19(%rip), %rcx
	call	_Z6printfPKcz
	addq	$40, %rsp
	ret
	.globl	main
	.def	main;	.scl	2;	.type	32;	.endef
main:
	subq	$40, %rsp
	call	__main
	call	_Z14absolute_valuev
	call	_Z16sizeof_datatypesv
	movl	$0, %eax
	addq	$40, %rsp
	ret
	.def	__main;	.scl	2;	.type	32;	.endef
	.ident	"GCC: (GNU) 15.2.0"
	.def	__mingw_vfprintf;	.scl	2;	.type	32;	.endef
