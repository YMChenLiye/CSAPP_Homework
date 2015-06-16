/*Consider the following union declaration:
union ele {
struct {
int *p;
int y;
} e1;
struct {
int x;
union ele *next;
} e2;
};
This declaration illustrates that structures can be embedded within unions.
The following procedure (with some expressions omitted) operates on a
linked list having these unions as list elements:
void proc (union ele *up)
{
up-> = *(up-> ) - up-> ;
}
A. What would be the offsets (in bytes) of the following ﬁelds:
e1.p:		0
e1.y:		4
e2.x:		0
e2.next:	4
B. How many total bytes would the structure require?		8
C. The compiler generates the following assembly code for the body of proc:
up at %ebp+8
1 movl 8(%ebp), %edx		edx=up
2 movl 4(%edx), %ecx		ecx=(up+4)
3 movl (%ecx), %eax			eax=(ecx)
4 movl (%eax), %eax			eax=(eax)
5 subl (%edx), %eax			eax-=(edx)
6 movl %eax, 4(%ecx)		(ecx+4)=eax
On the basis of this information, ﬁll in the missing expressions in the code
for proc. Hint: Some union references can have ambiguous interpretations.
These ambiguities get resolved as you see where the references lead. There
is only one answer that does not perform any casting and does not violate
any type constraints.*/

union ele {
	struct {
		int *p;
		int y;
	} e1;
	struct {
		int x;
		union ele *next;
	} e2;
};


void proc(union ele *up)
{
	up->e2.next->e2.x = *(up->e2.next->e1.p) - up->e1.y;
}