

typedef long long ll_t;
void store_prod(ll_t *dest, int x, ll_t y)
{
	*dest = x * y;
}
/*
dest at %ebp+8, x at %ebp+12, y at %ebp+16
1 movl 16(%ebp), %esi			get low_y
2 movl 12(%ebp), %eax			get x
3 movl %eax, %edx				
4 sarl $31, %edx				shift right 31bit
5 movl 20(%ebp), %ecx			get high_y	
6 imull %eax, %ecx				x*high_y
7 movl %edx, %ebx				
8 imull %esi, %ebx
9 addl %ebx, %ecx
10 mull %esi
11 leal (%ecx,%edx), %edx
12 movl 8(%ebp), %ecx
13 movl %eax, (%ecx)
14 movl %edx, 4(%ecx)*/



/*This code uses three multiplications to implement the multiprecision arith-
metic required to implement 64-bit arithmetic on a 32-bit machine. Describe the
algorithm used to compute the product, and annotate the assembly code to show
how it realizes your algorithm. Hint: See Problem 3.12 and its solution.*/

