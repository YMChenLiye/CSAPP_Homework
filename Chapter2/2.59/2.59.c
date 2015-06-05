#include<stdio.h>

typedef unsigned char *byte_pointer;

void show_bytes(byte_pointer start, int len)
{
	for (int i = 0; i < len; i++)
	{
		printf(" %.2x", start[i]);
		//%.2x indicates that an integer should be print in hexadecimal with at least two digits
	}
}

void show_int(int x)
{
	show_bytes((byte_pointer)&x, sizeof(int));
}


void homework(int x, int y)
{
	show_int(x);
	printf("\n");
	show_int(y);
	printf("\n after function \n");
	byte_pointer x1 = (byte_pointer)&x;
	byte_pointer y1 = (byte_pointer)&y;
	int z;
	byte_pointer z1 = (byte_pointer)&z;
	*(z1) = *(y1);
	*(z1+1) = *(x1+1);
	*(z1+2) = *(x1+2);
	*(z1+3) = *(x1+3);
	show_int(z);
	
}

void main()
{
	int x = 0x89abcdef;
	int y = 0x76543210;
	homework(x, y);
	getchar();
}