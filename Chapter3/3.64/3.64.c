﻿/*For this exercise, we will examine the code generated by gcc for functions that have
structures as arguments and return values, and from this see how these language
features are typically implemented.
The following C code has a function word_sum having structures as argument
and return values, and a function prod that calls word_sum:

typedef struct {
int a;
int *p;
} str1;
typedef struct {
int sum;
int diff;
} str2;
str2 word_sum(str1 s1) {
str2 result;
result.sum = s1.a + *s1.p;
result.diff = s1.a - *s1.p;return result;
}
int prod(int x, int y)
{
str1 s1;
str2 s2;
s1.a = x;
s1.p = &y;
s2 = word_sum(s1);
return s2.sum * s2.diff;
}
gcc generates the following code for these two functions:
1 word_sum:
2 pushl %ebp
3 movl %esp, %ebp
4 pushl %ebx
5 movl 8(%ebp), %eax			eax=s2
6 movl 12(%ebp), %ebx			ebx=s1.a
7 movl 16(%ebp), %edx			edx=s1.p
8 movl (%edx), %edx				edx=*s1.p
9 movl %ebx, %ecx				ecx=s1.a
10 subl %edx, %ecx				ecx-= *s1.p
11 movl %ecx, 4(%eax)			s2.diff=ecx
12 addl %ebx, %edx				edx+=s1.a
13 movl %edx, (%eax)			s2.sum=edx
14 popl %ebx
15 popl %ebp
16 ret $4


1 prod:
2 pushl %ebp
3 movl %esp, %ebp
4 subl $20, %esp
5 leal 12(%ebp), %edx					edx=&y
6 leal -8(%ebp), %ecx					ecx=&s2
7 movl 8(%ebp), %eax					eax=x
8 movl %eax, 4(%esp)					
9 movl %edx, 8(%esp)
10 movl %ecx, (%esp)
11 call word_sum
12 subl $4, %esp
13 movl -4(%ebp), %eax
14 imull -8(%ebp), %eax
15 leave
16 ret

The instruction ret $4 is like a normal return instruction, but it increments
the stack pointer by 8 (4 for the return address plus 4 additional), rather than 4.

A. We can see in lines 5–7 of the code for word_sum that it appears as if three
values are being retrieved from the stack, even though the function has only
a single argument. Describe what these three values are.
B. We can see in line 4 of the code for prod that 20 bytes are allocated in the
stack frame. These get used as ﬁve ﬁelds of 4 bytes each. Describe how each
of these ﬁelds gets used.
						&s2,x,&y,s2.sum,s2.diff
C. How would you describe the general strategy for passing structures as argu-
ments to a function?
By passing the structure directly in the stack as the common arguments.
D. How would you describe the general strategy for handling a structure as a
return value from a function?
By passing the structure's address.
*/