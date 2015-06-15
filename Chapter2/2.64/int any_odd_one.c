#include<stdio.h>

int any_odd_one(unsigned x)
{
	/* Return 1 when any odd bit of x equals 1; 0 otherwise. Assume w=32. */
	return (x & 0xaaaaaaaa) != 0;
}