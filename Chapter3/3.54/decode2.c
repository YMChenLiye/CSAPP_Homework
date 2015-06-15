#include<stdio.h>


int decode2(int x, int y, int z)
{
	return (((y - z) << 31) >> 31) ^ ((y - z) / x);
}


