/*Consider the following source code, where E1 and E2 are macro expressions de-
clared with #define that compute the dimensions of array A in terms of parameter
n. This code computes the sum of the elements of column j of the array.

1 int sum_col(int n, int A[E1(n)][E2(n)], int j) {
2 int i;
3 int result = 0;
4 for (i = 0; i < E1(n); i++)
5 result += A[i][j];
6 return result;
7 }

In compiling this program, gcc generates the following assembly code:
n at %ebp+8, A at %ebp+12, j at %ebp+16

1 movl 8(%ebp), %eax					eax=n
2 leal (%eax,%eax), %edx				edx=2*n
3 leal (%edx,%eax), %ecx				ecx=3*n
4 movl %edx, %ebx						ebx=2*n
5 leal 1(%edx), %eax					eax=1+2*n
6 movl $0, %edx							edx=0
7 testl %eax, %eax						test eax
8 jle .L3								if (eax <=0) goto L3
9 leal 0(,%ecx,4), %esi					esi=12*n
10 movl 16(%ebp), %edx					edx=j
11 movl 12(%ebp), %ecx					ecx=A
12 leal (%ecx,%edx,4), %eax				eax=A+4*j
13 movl $0, %edx						edx=0
14 movl $1, %ecx						ecx=1
15 addl $2, %ebx						ebx=2*n+2
16 .L4:
17 addl (%eax), %edx					edx+=(A+4*j)
18 addl $1, %ecx						ecx++
19 addl %esi, %eax						eax+=12*n
20 cmpl %ebx, %ecx						ecx-ebx
21 jne .L4
22 .L3:
23 movl %edx, %eax						eax=edx

Use your reverse engineering skills to determine the deﬁnitions of E1 and E2.*/

#define E1 2*n+2
#define E2 3*n
int sum_col(int n, int A[E1][E2], int j) {
	int i;
	int result = 0;
	for (i = 0; i < E1; i++)
		result += A[i][j];
	return result;

}