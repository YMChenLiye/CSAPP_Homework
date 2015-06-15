/*This problem will give you a chance to reverse engineer a switch statement from
machine code. In the following procedure, the body of the switch statement has
been removed:1 int switch_prob(int x, int n)
2 {
3 int result = x;
4
5 switch(n) {
6
7 /* Fill in code here /
8 }
9
10 return result;
11 }
Figure 3.44 shows the disassembled machine code for the procedure.We can
see in lines 4 and 5 that parameters x and n are loaded into registers %eax and
%edx, respectively.
The jump table resides in a different area of memory.We can see from the
indirect jump on line 9 that the jump table begins at address 0x80485d0.Using
the gdb debugger, we can examine the six 4 - byte words of memory comprising
the jump table with the command x / 6w 0x80485d0.gdb prints the following :
(gdb)x / 6w 0x80485d0
0x80485d0 : 0x08048438 0x08048448 0x08048438 0x0804843d
0x80485e0 : 0x08048442 0x08048445
Fill in the body of the switch statement with C code that will have the same
behavior as the machine code.
1 08048420 <switch_prob> :
2 8048420 : 55 push %ebp
3 8048421 : 89 e5 mov %esp, %ebp
4 8048423 : 8b 45 08 mov 0x8(%ebp), %eax
5 8048426 : 8b 55 0c mov 0xc(%ebp), %edx
6 8048429 : 83 ea 32 sub $0x32, %edx
7 804842c : 83 fa 05 cmp $0x5, %edx
8 804842f : 77 17 ja 8048448 <switch_prob + 0x28>
9 8048431 : ff 24 95 d0 85 04 08 jmp * 0x80485d0(, %edx, 4)
10 8048438 : c1 e0 02 shl $0x2, %eax
11 804843b : eb 0e jmp 804844b <switch_prob + 0x2b>
12 804843d : c1 f8 02 sar $0x2, %eax
13 8048440 : eb 09 jmp 804844b <switch_prob + 0x2b>
14 8048442 : 8d 04 40 lea(%eax, %eax, 2), %eax
15 8048445 : 0f af c0 imul %eax, %eax
16 8048448 : 83 c0 0a add $0xa, %eax
17 804844b : 5d pop %ebp
18 804844c : c3 ret
Figure 3.44 Disassembled code for Problem 3.59.* /*/


int switch_prob(int x, int n)
{
	int result = x;
	n -= 0x32;
	switch (n) {

	case 0:
	case 2:
		result <<= 2;
		break;
	case 3:
		result >>= 2;
		break;
	case 4:
		result *= 3;
		result = result*result;
		result += 10;
		break;
	case 5:
		result = result*result;
		result += 10;
		break;

	case 1:
	default:
		result += 10;
		/* Fill in code here */
	}

	return result;
}