/*The following declaration deﬁnes a class of structures for use in constructing
binary trees:
1 typedef struct ELE *tree_ptr;
2
3 struct ELE {
4 long val;
5 tree_ptr left;
6 tree_ptr right;
7 };For a function with the following prototype:
long trace(tree_ptr tp);
gcc generates the following x86-64 code:

1 trace:
tp in %rdi
2 movl $0, %eax				eax=0
3 testq %rdi, %rdi			tp==NULL?
4 je .L3					goto Done
5 .L5:
6 movq (%rdi), %rax			rax=tp->val
7 movq 16(%rdi), %rdi		rdi=rdi+16
8 testq %rdi, %rdi			rdi==null?
9 jne .L5
10 .L3:
11 rep
12 ret

A. Generate a C version of the function, using a while loop.
B. Explain in English what this function computes.*/
#include<stdio.h>
#include<stdlib.h>

typedef struct ELE *tree_ptr;

struct ELE {
	long val;
	tree_ptr left;
	tree_ptr right;
};

long trace(tree_ptr tp)
{
	long result = 0;
	while (tp != NULL)
	{
		result = tp->val;
		tp = tp->right;
	}
	return result;
}