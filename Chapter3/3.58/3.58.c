/*The code that follows shows an example of branching on an enumerated type
value in a switch statement.Recall that enumerated types in C are simply a way
to introduce a set of names having associated integer values.By default, the values
assigned to the names go from zero upward.In our code, the actions associated
with the different case labels have been omitted.
///* Enumerated type creates set of constants numbered 0 and upward */
/*typedef enum { MODE_A, MODE_B, MODE_C, MODE_D, MODE_E } mode_t;
int switch3(int *p1, int *p2, mode_t action)
{
int result = 0;
switch (action) {
case MODE_A:
case MODE_B:
case MODE_C:
case MODE_D:
case MODE_E:
default:
}
return result;
}
The part of the generated assembly code implementing the different actions
is shown in Figure 3.43.The annotations indicate the argument locations, the
register values, and the case labels for the different jump destinations.Register
%edx corresponds to program variable result and is initialized to − 1.
Fill in the missing parts of the C code.Watch out for cases that fall through.298 Chapter 3 Machine - Level Representation of Programs
Arguments : p1 at %ebp + 8, p2 at %ebp + 12, action at %ebp + 16
Registers : result in %edx(initialized to - 1)
The jump targets :
1.L17 : MODE_E
2 movl $17, %edx
3 jmp.L19
4.L13 : MODE_A
5 movl 8(%ebp), %eax	get eax=p1
6 movl(%eax), %edx		edx=*p1
7 movl 12(%ebp), %ecx	get ecx=p2
8 movl(%ecx), %eax		eax=*p2
9 movl 8(%ebp), %ecx	ecx=p1
10 movl %eax, (%ecx)	*p1=eax=*p2
11 jmp.L19
12.L14: MODE_B
13 movl 12(%ebp), %edx	edx=p2
14 movl(%edx), %eax		eax=*p2
15 movl %eax, %edx		edx=eax=*p2
16 movl 8(%ebp), %ecx	ecx=p1
17 addl(%ecx), %edx		edx+=*p1
18 movl 12(%ebp), %eax	eax=p2
19 movl %edx, (%eax)	*p2=edx
20 jmp.L19
21.L15: MODE_C
22 movl 12(%ebp), %edx	edx=p2
23 movl $15, (%edx)		*p2=15
24 movl 8(%ebp), %ecx	ecx=p1
25 movl(%ecx), %edx		edx=*p1
26 jmp.L19
27.L16: MODE_D
28 movl 8(%ebp), %edx	edx=p1
29 movl(%edx), %eax		eax=*p1
30 movl 12(%ebp), %ecx	ecx=p2
31 movl %eax, (%ecx)	*p2=eax=*p1
32 movl $17, %edx		edx=17
33.L19: default
34 movl %edx, %eax Set return value
Figure 3.43 Assembly code for Problem 3.58.This code implements the different
branches of a switch statement.*/

typedef enum { MODE_A, MODE_B, MODE_C, MODE_D, MODE_E } mode_t;
int switch3(int *p1, int *p2, mode_t action)
{
	int result = 0;
	switch (action) {
	case MODE_A:
		result = *p1;
		*p1 = *p2;
		break;
	case MODE_B:
		result = *p1 + *p2;
		*p2 = result;
		break;
	case MODE_C:
		*p2 = 15;
		result = *p1;
		break;
	case MODE_D:
		*p2 = *p1;
		result = 17;
		break;
	case MODE_E:
		result = 17;
	default:
		result = -1;
	}
	return result;
}