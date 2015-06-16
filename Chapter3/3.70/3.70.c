/*Using the same tree data structure we saw in Problem 3.69, and a function with
the prototype
long traverse(tree_ptr tp);
gcc generates the following x86-64 code:

1 traverse:
tp in %rdi
2 movq %rbx, -24(%rsp)
3 movq %rbp, -16(%rsp)
4 movq %r12, -8(%rsp)
5 subq $24, %rsp

6 movq %rdi, %rbp								rbp=tp
7 movabsq $-9223372036854775808, %rax			rax=
8 testq %rdi, %rdi
9 je .L9										tp==NULL?   goto Done
10 movq (%rdi), %rbx							rbx=tp->val
11 movq 8(%rdi), %rdi							rdi=rdi+8
12 call traverse
13 movq %rax, %r12								r12=rax
14 movq 16(%rbp), %rdi							rdi=tp->right
15 call traverse
16 cmpq %rax, %r12								r12-rax
17 cmovge %r12, %rax							>=  rax=r12
18 cmpq %rbx, %rax								rax-rbx
19 cmovl %rbx, %rax								<   rax=rbx
20 .L9:
21 movq (%rsp), %rbx
22 movq 8(%rsp), %rbp
23 movq 16(%rsp), %r12
24 addq $24, %rsp
25 ret


A. Generate a C version of the function.
B. Explain in English what this function computes.*/


#include<stdio.h>
#include<stdlib.h>

typedef struct ELE *tree_ptr;

struct ELE {
	long val;
	tree_ptr left;
	tree_ptr right;
};


long traverse(tree_ptr tp)
{
	long result = -9223372036854775808;
	if (tp != NULL)
	{
		long rbx = tp->val;
		tp = tp->right;
		long r12 = traverse(tp);
		tp = tp->right;
		result = traverse(tp);
		if (r12>=result)
		{
			result = r12;
		}
		if (result<rbx)
		{
			result = rbx;
		}
	}
	return result;
}

