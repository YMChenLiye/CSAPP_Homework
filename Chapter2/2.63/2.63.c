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


unsigned srl(unsigned x, int k)
{
	/* Perform shift arithmetically */
	unsigned xsra = (int)x >> k;
	int wordlength = sizeof(int) * 8;
	int tmp = (1 << (wordlength - k)) - 1;
	return xsra & tmp;
}


int sra(int x, int k)
{
	/* Perform shift logically */
	int xsrl = (unsigned)x >> k;
	int wordlength = sizeof(int) * 8;
	int tmp = ~((1 << (wordlength - k)) - 1);
	int sign = x & (1 << (wordlength - 1));
	sign && (xsrl |= tmp);   
	//&& operator:if the first argment is false,the second value will not cpmputer
	//so,if the most significant bit of x is 0, 'xsrl |= tmp' will not computer
	return xsrl;
}
void main()
{

	show_int(sra(0xffffffff, 4));
	getchar();
}