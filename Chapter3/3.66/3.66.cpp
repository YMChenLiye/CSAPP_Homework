/*You are charged with maintaining a large C program, and you come across the
following code:

1 typedef struct {
2 int left;
3 a_struct a[CNT];
4 int right;
5 } b_struct;
6
7 void test(int i, b_struct *bp)
8 {
9 int n = bp->left + bp->right;
10 a_struct *ap = &bp->a[i];
11 ap->x[ap->idx] = n;
12 }

1 00000000 <test>:
2 0: push %ebp
3 1: mov %esp,%ebp
4 3: mov 0x8(%ebp),%eax				eax=i
5 6: mov 0xc(%ebp),%ecx				ecx=bp
6 9: lea (%eax,%eax,4),%eax			eax=5*i
7 c: add 0x4(%ecx,%eax,4),%eax		eax+=(bp+20*i+4)	--->idx+5i	sizeof(a_struct)=20
8 10: mov 0xb8(%ecx),%edx			edx=(bp+184)		(184-4)/20=9	,	CNT=9
9 16: add (%ecx),%edx				edx+=(bp)				--->	
10 18:mov %edx,0x8(%ecx,%eax,4)		(bp+4*idx+20*i+8)=edx
11 1c:pop %ebp
12 1d:ret

Figure 3.45 Disassembled code for Problem 3.66.
The declarations of the compile-time constant CNT and the structure a_struct
are in a ﬁle for which you do not have the necessary access privilege. Fortunately,
you have a copy of the ‘.o’ version of code, which you are able to disassemble with
the objdump program, yielding the disassembly shown in Figure 3.45.
Using your reverse engineering skills, deduce the following.
A. The value of CNT.
B. A complete declaration of structure a_struct. Assume that the only ﬁelds
in this structure are idx and x.*/


#define CNT 9
typedef struct{
	int idx;
	int x[4];
}a_struct;

typedef struct {
	int left;
	a_struct a[CNT];
	int right;
} b_struct;

void test(int i, b_struct *bp)
{
	int n = bp->left + bp->right;
	a_struct *ap = &bp->a[i];
	ap->x[ap->idx] = n;
}