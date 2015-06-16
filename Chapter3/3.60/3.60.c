/*Consider the following source code, where R, S, and T are constants declared with
#define:
int A[R][S][T];
int store_ele(int i, int j, int k, int *dest)
{
*dest = A[i][j][k];
return sizeof(A);
}
In compiling this program, gcc generates the following assembly code:
i at %ebp+8, j at %ebp+12, k at %ebp+16, dest at %ebp+20

1 movl 12(%ebp), %edx					edx=j
2 leal (%edx,%edx,4), %eax				eax=5*edx=5*j
3 leal (%edx,%eax,2), %eax				eax=2*eax+edx   ->	11*j
4 imull $99, 8(%ebp), %edx				edx=i*99
5 addl %edx, %eax						eax+=edx(i*99) -->  i*99+11*j
6 addl 16(%ebp), %eax					eax+=k
7 movl A(,%eax,4), %edx					edx=(A+4*eax)  --> (A+396*i+44*j+4*k)  T=11,S=9
8 movl 20(%ebp), %eax					eax=dest
9 movl %edx, (%eax)						*dest=edx
10 movl $1980, %eax						sizeof(A)=1980		R*S*T=495,R=5

A. Extend Equation 3.1 from two dimensions to three to provide a formula for
the location of array element A[i][j][k].
B. Use your reverse engineering skills to determine the values of R, S, and T
based on the assembly code.*/

#define R 5
#define S 9
#define T 11

int A[R][S][T];

int store_ele(int i, int j, int k, int *dest)
{
	*dest = A[i][j][k];
	return sizeof(A);
}