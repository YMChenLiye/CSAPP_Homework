/*In the following code, A and B are constants deﬁned with #define:
typedef struct {
short x[A][B]; / Unknown constants A and B /
int y;
} str1;
typedef struct {
char array[B];
int t;
short s[B];
int u;
} str2;
void setVal(str1 *p, str2 *q) {
int v1 = q->t;
int v2 = q->u;
p->y = v1 + v2;
}
gcc generates the following code for the body of setVal :
1 movl 12(%ebp), %eax				eax=q
2 movl 36(%eax), %edx				edx=(q+36)
3 addl 12(%eax), %edx				edx+=(q+12)    --->		9<=B<=10			--->
4 movl 8(%ebp), %eax				eax=p												A=5,B=9
5 movl %edx, 92(%eax)				(p+92)=edx	   --->		45<=A*B<=46			--->
What are the values of A and B ? (The solution is unique.)*/

#define A 5
#define B 9

typedef struct {
	short x[A][B]; /* Unknown constants A and B */
	int y;
} str1;
typedef struct {
	char array[B];
	int t;
	short s[B];
	int u;
} str2;
void setVal(str1 *p, str2 *q) {
	int v1 = q->t;
	int v2 = q->u;
	p->y = v1 + v2;
}