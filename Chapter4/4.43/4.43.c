/*4.43 ¡ô
In Section 3.4.2, the IA32 pushl instruction was described as decrementing the
stack pointer and then storing the register at the stack pointer location.So, if
we had an instruction of the form pushl REG, for some register REG, it would be
equivalent to the code sequence :
subl $4, %esp Decrement stack pointer
movl REG, (%esp) Store REG on stack
A.In light of analysis done in Problem 4.6, does this code sequence correctly
describe the behavior of the instruction pushl %esp ? Explain.
B.How could you rewrite the code sequence so that it correctly describes both
the cases where REG is %esp as well as any other register ?*/

//1.it doesn't

//2.	movl %esp,%eax
//		subl $4,%eax
//		movl REG,(%esp)