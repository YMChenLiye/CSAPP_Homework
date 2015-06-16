/*Write a function good_echo that reads a line from standard input and writes it to
standard output. Your implementation should work for an input line of arbitrary
length. You may use the library function fgets, but you must make sure your
function works correctly even when the input line requires more space than you
have allocated for your buffer. Your code should also check for error conditions
and return when one is encountered. Refer to the deﬁnitions of the standard I/O
functions for documentation [48, 58].*/
#include<stdio.h>

void good_echo() {
	char buf[8];
	if (fgets(buf, 8, stdin) != 0)
		puts(buf);
	return;
}

void main()
{
	good_echo();
}