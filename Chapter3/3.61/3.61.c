﻿/*The code generated by the C compiler for var_prod_ele (Figure 3.29) cannot ﬁt
all of the values it uses in the loop in registers, and so it must retrieve the value of
n from memory on each iteration. Write C code for this function that incorporates
optimizations similar to those performed by gcc, but such that the compiled code
does not spill any loop values into memory.
Recall that the processor only has six registers available to hold temporary
data, since registers %ebp and %esp cannot be used for this purpose. One of these
registers must be used to hold the result of the multiply instruction. Hence, you
must reduce the number of values in the loop from six (result, Arow, Bcol, j, n,
and 4*n) to ﬁve.
You will need to ﬁnd a strategy that works for your particular compiler. Keep
trying different strategies until you ﬁnd one that works.*/

int var_prod_ele(int n, int A[n][n], int B[n][n], int i, int k) {
	int *j;
	int result = 0;
	int *end = A[i] + n;
	int *Bp = B[0] + k;
	for (j = A[i]; j != end; ++j) {
		result += (*j * *Bp);
		Bp += n;
	}
	return result;
}