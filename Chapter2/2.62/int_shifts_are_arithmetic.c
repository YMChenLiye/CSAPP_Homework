#include<stdio.h>

int int_shifts_are_arithmetic()
{
	//yields 1 when run on a machine that uses arithmetic right shifts for int¡¯s, and 0 otherwise.
	int x = -10;
	return x >> 1 < 0;
}

void main()
{
	printf("%d", int_shifts_are_arithmetic());
	getchar();
}