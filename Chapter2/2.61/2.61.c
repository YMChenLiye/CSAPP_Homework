#include<stdio.h>

int QuestionA(int x)
{
	//A. Any bit of x equals 1. 
	return !(~x);
}
int QuestionB(int x)
{
	//B. Any bit of x equals 0. 
	return !x;
}

int QuestionC(int x)
{
	//C.Any bit in the least signiﬁcant byte of x equals 1.
	x = x << (sizeof(int) * 8 - 8);
	x = x >> (sizeof(int) * 8 - 8);
	return !(~x);
}

int QuestionD(int x)
{
	//D.Any bit in the most signiﬁcant byte of x equals 0.
	x = x >> (sizeof(int) * 8 - 8);
	x = x << (sizeof(int) * 8 - 8);
	return !x;
}

void main()
{
	int x = 0x00ffffff;
	printf("%x", QuestionD(x));
	getchar();

}
