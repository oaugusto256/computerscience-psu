	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_recover
	.align	4, 0x90
_recover:                               ## @recover
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%esi
	subl	$20, %esp
	calll	L0$pb
L0$pb:
	popl	%esi
	movl	$1234, -8(%ebp)         ## imm = 0x4D2
	movl	-4(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	L_.str-L0$pb(%esi), %eax
	movl	%eax, (%esp)
	calll	_printf
	leal	(%ebp), %eax
	movl	%eax, 4(%esp)
	leal	L_.str1-L0$pb(%esi), %eax
	movl	%eax, (%esp)
	calll	_printf
	addl	$20, %esp
	popl	%esi
	popl	%ebp
	retl

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"The hex value of X is: %X \n"

L_.str1:                                ## @.str1
	.asciz	"The hex value of X is: %p \n"


.subsections_via_symbols
