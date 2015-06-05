#include<stdio.h>


int is_big_endian()//
{
	int x = 1;
	return *((char *)&x) == 0;
	//will return 1 when compiled and run on a big-endian machine,and will renturn 0 when compiled and run on a little-endian machine.
}

void main()
{
	printf("%d", is_big_endian());//my machine has Intel's chip,so print 0(little-endian).
	getchar();
}