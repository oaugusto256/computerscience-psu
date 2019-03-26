	.section	__TEXT,__text,regular,pure_instructions
	.macosx_version_min 10, 10
	.globl	_main
	.align	4, 0x90
_main:                                  ## @main
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$44, %esp
	calll	L0$pb
L0$pb:
	popl	%eax
	movl	%eax, -16(%ebp)         ## 4-byte Spill
	cmpl	$5, 8(%ebp)
	jne	LBB0_2
## BB#1:
	movl	12(%ebp), %edi
	movl	4(%edi), %eax
	movl	%eax, (%esp)
	calll	_atoi
	movl	%eax, -20(%ebp)         ## 4-byte Spill
	movl	8(%edi), %eax
	movl	%eax, (%esp)
	calll	_atoi
	movl	%eax, %esi
	movl	12(%edi), %eax
	movl	%eax, (%esp)
	calll	_atoi
	movl	%eax, %ebx
	movl	16(%edi), %eax
	movl	%eax, (%esp)
	calll	_atoi
	movl	%eax, -24(%ebp)         ## 4-byte Spill
	movl	%eax, 16(%esp)
	movsbl	%bl, %ebx
	movl	%ebx, 12(%esp)
	movswl	%si, %esi
	movl	%esi, 8(%esp)
	movl	-20(%ebp), %edi         ## 4-byte Reload
	movl	%edi, 4(%esp)
	movl	-16(%ebp), %eax         ## 4-byte Reload
	leal	L_.str1-L0$pb(%eax), %eax
	movl	%eax, (%esp)
	calll	_printf
	movl	-24(%ebp), %eax         ## 4-byte Reload
	movl	%eax, 16(%esp)
	movl	%ebx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%edi, (%esp)
	movl	$0, 12(%esp)
	calll	_foo
	movl	%eax, 4(%esp)
	movl	-16(%ebp), %eax         ## 4-byte Reload
	leal	L_.str2-L0$pb(%eax), %eax
	movl	%eax, (%esp)
	calll	_printf
	xorl	%eax, %eax
	addl	$44, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl
LBB0_2:
	movl	-16(%ebp), %eax         ## 4-byte Reload
	leal	L_str-L0$pb(%eax), %eax
	movl	%eax, (%esp)
	calll	_puts
	movl	$-1, (%esp)
	calll	_exit

	.globl	_foo
	.align	4, 0x90
_foo:                                   ## @foo
## BB#0:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	pushl	%edi
	pushl	%esi
	subl	$28, %esp
	movl	24(%ebp), %edi
	movl	8(%ebp), %esi
	testl	%edi, %edi
	je	LBB1_1
## BB#3:
	movzwl	12(%ebp), %ecx
	movb	16(%ebp), %dl
	movswl	%cx, %eax
	movl	%eax, -16(%ebp)         ## 4-byte Spill
	movl	%ecx, %ebx
	andl	$32768, %ebx            ## imm = 0x8000
	leal	(%eax,%eax), %ecx
	shrl	$15, %ebx
	orl	%ecx, %ebx
	movl	%esi, %eax
	movsbl	%dl, %esi
	leal	(%esi,%esi), %ecx
	movl	%ecx, -20(%ebp)         ## 4-byte Spill
	shrb	$7, %dl
	movzbl	%dl, %ecx
	orl	-20(%ebp), %ecx         ## 4-byte Folded Reload
	movl	%eax, %edx
	roll	%edx
	xorl	-16(%ebp), %edx         ## 4-byte Folded Reload
	xorl	%esi, %ebx
	movl	20(%ebp), %esi
	xorl	%eax, %ecx
	incl	%esi
	decl	%edi
	movl	%edi, 16(%esp)
	movl	%esi, 12(%esp)
	movl	%edx, (%esp)
	movsbl	%cl, %eax
	movl	%eax, 8(%esp)
	movswl	%bx, %eax
	movl	%eax, 4(%esp)
	calll	_foo
	addl	8(%ebp), %eax
	jmp	LBB1_2
LBB1_1:
	calll	_recover
	movl	%esi, %eax
LBB1_2:
	addl	$28, %esp
	popl	%esi
	popl	%edi
	popl	%ebx
	popl	%ebp
	retl

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"Usage: program <int> <int> <int> <int>\n"

L_.str1:                                ## @.str1
	.asciz	"main called with a = %d, b = %d, c = %d, countDown = %d\n"

L_.str2:                                ## @.str2
	.asciz	"foo returns %d\n"

	.align	4                       ## @str
L_str:
	.asciz	"Usage: program <int> <int> <int> <int>"


.subsections_via_symbols
