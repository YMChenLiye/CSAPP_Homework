﻿/*
Consider the following assembly code:
x at %ebp+8, n at %ebp+12
1 movl 8(%ebp), %esi		esi=x
2 movl 12(%ebp), %ebx		ebx=n
3 movl $-1, %edi				edi=-1	result
4 movl $1, %edx				edx=1	mask
5 .L2:
6 movl %edx, %eax
7 andl %esi, %eax
8 xorl %eax, %edi
9 movl %ebx, %ecx
10 sall %cl, %edx
11 testl %edx, %edx
12 jne .L2
13 movl %edi, %eax
The preceding code was generated by compiling C code that had the following
overall form:

Your task is to ﬁll in the missing parts of the C code to get a program equivalent
to the generated assembly code. Recall that the result of the function is returned
in register %eax. You will ﬁnd it helpful to examine the assembly code before,
during, and after the loop to form a consistent mapping between the registers and
the program variables.
A. Which registers hold program values x, n, result, and mask?
B. What are the initial values of result and mask?			-1  1
C. What is the test condition for mask?						mask!=0
D. How does mask get updated?	
E. How does result get updated?
F. Fill in all the missing parts of the C code.*/

int loop(int x, int n)
{
	int result = -1;
	int mask;
	for (mask = 1; mask != 0; mask >>= n)
	{
		result ^= x&mask;
	}
	return result;
}