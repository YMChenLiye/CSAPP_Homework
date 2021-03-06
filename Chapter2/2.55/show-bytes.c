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

void show_float(float x)
{
	show_bytes((byte_pointer)&x, sizeof(float));
}

void show_double(double x)
{
	show_bytes((byte_pointer)&x, sizeof(double));
}

void show_pointer(void *x)
{
	show_bytes((byte_pointer)&x, sizeof(void *));
}


int main()
{
	int a = 10;
	float b = 11.5;
	double c = 13.33;
	void *d = &a;
	show_int(a);
    show_float(b);
    show_double(c);

	getchar();
}
