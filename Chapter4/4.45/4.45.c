/*4.45 ◆◆◆
Your assignment will be to write a Y86 program to perform bubblesort.For ref -
erence, the following C function implements bubblesort using array referencing:
// Bubble sort: Array version

void bubble_a(int *data, int count) {
int i, last;
for (last = count - 1; last > 0; last--) {
for (i = 0; i < last; i++)
if (data[i + 1] < data[i]) {
// Swap adjacent elements
int t = data[i + 1];
data[i + 1] = data[i];
data[i] = t;
}
}
}

A.Write and test a C version that references the array elements with pointers,
rather than using array indexing.
B.Write and test a Y86 program consisting of the function and test code.You
may ﬁnd it useful to pattern your implementation after IA32 code generated
by compiling your C code.Although pointer comparisons are normally done
using unsigned arithmetic, you can use signed arithmetic for this exercise.*/


//A.
void bubble_a(int *data, int count) {
	int i, last;
	for (last = count - 1; last > 0; last--) {
		for (i = 0; i < last; i++)
			if (*(data + i + 1) < *(data + i)) {
				// Swap adjacent elements 
				int t = *(data + i + 1);
				*(data + i + 1) = *(data + i);
				*(data + i) = t;
			}
	}
}


//B
//默认的64为版本   命令：gcc -S test.c
/*
.file	"test.c"
.text
.globl	bubble_a
.type	bubble_a, @function
bubble_a :
.LFB0 :
.cfi_startproc
pushq	%rbp
.cfi_def_cfa_offset 16
.cfi_offset 6, -16
movq	%rsp, %rbp
.cfi_def_cfa_register 6
movq	%rdi, -24(%rbp)
movl	%esi, -28(%rbp)
movl - 28(%rbp), %eax
subl	$1, %eax
movl	%eax, -8(%rbp)
jmp.L2
.L6:
movl	$0, -4(%rbp)
jmp.L3
.L5 :
movl - 4(%rbp), %eax
cltq
addq	$1, %rax
leaq	0(, %rax, 4), %rdx
movq - 24(%rbp), %rax
addq	%rdx, %rax
movl(%rax), %edx
movl - 4(%rbp), %eax
cltq
leaq	0(, %rax, 4), %rcx
movq - 24(%rbp), %rax
addq	%rcx, %rax
movl(%rax), %eax
cmpl	%eax, %edx
jge.L4
movl - 4(%rbp), %eax
cltq
addq	$1, %rax
leaq	0(, %rax, 4), %rdx
movq - 24(%rbp), %rax
addq	%rdx, %rax
movl(%rax), %eax
movl	%eax, -12(%rbp)
movl - 4(%rbp), %eax
cltq
addq	$1, %rax
leaq	0(, %rax, 4), %rdx
movq - 24(%rbp), %rax
addq	%rax, %rdx
movl - 4(%rbp), %eax
cltq
leaq	0(, %rax, 4), %rcx
movq - 24(%rbp), %rax
addq	%rcx, %rax
movl(%rax), %eax
movl	%eax, (%rdx)
movl - 4(%rbp), %eax
cltq
leaq	0(, %rax, 4), %rdx
movq - 24(%rbp), %rax
addq	%rax, %rdx
movl - 12(%rbp), %eax
movl	%eax, (%rdx)
.L4:
addl	$1, -4(%rbp)
.L3 :
movl - 4(%rbp), %eax
cmpl - 8(%rbp), %eax
jl.L5
subl	$1, -8(%rbp)
.L2 :
cmpl	$0, -8(%rbp)
jg.L6
popq	%rbp
.cfi_def_cfa 7, 8
ret
.cfi_endproc
.LFE0:
.size	bubble_a, . - bubble_a
.globl	main
.type	main, @function
main :
.LFB1 :
.cfi_startproc
pushq	%rbp
.cfi_def_cfa_offset 16
.cfi_offset 6, -16
movq	%rsp, %rbp
.cfi_def_cfa_register 6
subq	$48, %rsp
movl	$21, -48(%rbp)
movl	$23, -44(%rbp)
movl	$43, -40(%rbp)
movl	$34, -36(%rbp)
movl	$54, -32(%rbp)
movl	$64, -28(%rbp)
movl	$65, -24(%rbp)
movl	$45, -20(%rbp)
movl	$12, -16(%rbp)
movl	$64, -12(%rbp)
leaq - 48(%rbp), %rax
movl	$10, %esi
movq	%rax, %rdi
call	bubble_a
movl	$0, %eax
leave
.cfi_def_cfa 7, 8
ret
.cfi_endproc
.LFE1:
.size	main, . - main
.ident	"GCC: (GNU) 4.7.2 20120921 (Red Hat 4.7.2-2)"
.section.note.GNU - stack, "", @progbits
*/




//32位版本的   命令：gcc -m32 -S test.c
/*
.file	"test.c"
.text
.globl	bubble_a
.type	bubble_a, @function
bubble_a:
.LFB0:
.cfi_startproc
pushl	%ebp
.cfi_def_cfa_offset 8
.cfi_offset 5, -8
movl	%esp, %ebp
.cfi_def_cfa_register 5
subl	$16, %esp
movl	12(%ebp), %eax
subl	$1, %eax
movl	%eax, -8(%ebp)
jmp	.L2
.L6:
movl	$0, -4(%ebp)
jmp	.L3
.L5:
movl	-4(%ebp), %eax
addl	$1, %eax
leal	0(,%eax,4), %edx
movl	8(%ebp), %eax
addl	%edx, %eax
movl	(%eax), %edx
movl	-4(%ebp), %eax
leal	0(,%eax,4), %ecx
movl	8(%ebp), %eax
addl	%ecx, %eax
movl	(%eax), %eax
cmpl	%eax, %edx
jge	.L4
movl	-4(%ebp), %eax
addl	$1, %eax
leal	0(,%eax,4), %edx
movl	8(%ebp), %eax
addl	%edx, %eax
movl	(%eax), %eax
movl	%eax, -12(%ebp)
movl	-4(%ebp), %eax
addl	$1, %eax
leal	0(,%eax,4), %edx
movl	8(%ebp), %eax
addl	%eax, %edx
movl	-4(%ebp), %eax
leal	0(,%eax,4), %ecx
movl	8(%ebp), %eax
addl	%ecx, %eax
movl	(%eax), %eax
movl	%eax, (%edx)
movl	-4(%ebp), %eax
leal	0(,%eax,4), %edx
movl	8(%ebp), %eax
addl	%eax, %edx
movl	-12(%ebp), %eax
movl	%eax, (%edx)
.L4:
addl	$1, -4(%ebp)
.L3:
movl	-4(%ebp), %eax
cmpl	-8(%ebp), %eax
jl	.L5
subl	$1, -8(%ebp)
.L2:
cmpl	$0, -8(%ebp)
jg	.L6
leave
.cfi_restore 5
.cfi_def_cfa 4, 4
ret
.cfi_endproc
.LFE0:
.size	bubble_a, .-bubble_a
.globl	main
.type	main, @function
main:
.LFB1:
.cfi_startproc
pushl	%ebp
.cfi_def_cfa_offset 8
.cfi_offset 5, -8
movl	%esp, %ebp
.cfi_def_cfa_register 5
subl	$56, %esp
movl	$21, -40(%ebp)
movl	$23, -36(%ebp)
movl	$43, -32(%ebp)
movl	$34, -28(%ebp)
movl	$54, -24(%ebp)
movl	$64, -20(%ebp)
movl	$65, -16(%ebp)
movl	$45, -12(%ebp)
movl	$12, -8(%ebp)
movl	$64, -4(%ebp)
movl	$10, 4(%esp)
leal	-40(%ebp), %eax
movl	%eax, (%esp)
call	bubble_a
movl	$0, %eax
leave
.cfi_restore 5
.cfi_def_cfa 4, 4
ret
.cfi_endproc
.LFE1:
.size	main, .-main
.ident	"GCC: (GNU) 4.7.2 20120921 (Red Hat 4.7.2-2)"
.section	.note.GNU-stack,"",@progbits*/