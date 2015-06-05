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



unsigned  replace_byte(unsigned x, unsigned char b, int i)
{
	show_int(x);
	printf("\n");
	char *p_x = (char *)&x;
	*(p_x + i) = b;
	show_int(x);
	return x;

}

void main()
{
	unsigned x = 0x12345678;
	
	
	replace_byte(x, 0xab, 0);
	
	getchar();
}