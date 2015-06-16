/*The following code transposes the elements of an M × M array, where M is a
constant deﬁned by #define:

void transpose(Marray_t A) {
int i, j;
for (i = 0; i < M; i++)
for (j = 0; j < i; j++) {
int t = A[i][j];
A[i][j] = A[j][i];
A[j][i] = t;
}
}

When compiled with optimization level -O2, gcc generates the following code for
the inner loop of the function:

1 .L3:									lable:loop
2 movl (%ebx), %eax						eax=(ebx)			ebx=&A[i][j]
3 movl (%esi,%ecx,4), %edx				edx=(esi+4*ecx)		edx=&A[j][i]
4 movl %eax, (%esi,%ecx,4)				(esi+4*ecx)=eax		(esi+4*ecx)=(ebx)
5 addl $1, %ecx							ecx+=1				j++
6 movl %edx, (%ebx)						(ebx)=edx	 -->		(ebx)=(esi+4*ecx)
7 addl $52, %ebx						ebx+=52				ebx
8 cmpl %edi, %ecx
9 jl .L3								ecx < edi goto loop


A. What is the value of M?			52/4=13
B. What registers hold program values i and j?			i=edi		j=ecx
C. Write a C code version of transpose that makes use of the optimizations
that occur in this loop. Use the parameter M in your code rather than numeric
constants.*/

#define M 13
typedef int Marray_t[M][M];
void transpose(Marray_t A) {
	int i, j;
	for (i = 0; i < M; i++)
		for (j = 0; j < i; j++) {
			int t = A[i][j];
			A[i][j] = A[j][i];
			A[j][i] = t;
		}
}


void transpose1(Marray_t A)
{
	int i, j;
	for (i = 0; i < M; i++)
	{
		int *Ap1 = A[i];
		int *Ap2 = A[0] + i;
		for (j = 0; j < i; j++)
		{
			int t = *(Ap1 + j);
			*(Ap1 + j) = *Ap2;
			*Ap2 = t;
			Ap2 += M;
		}
	}
}

