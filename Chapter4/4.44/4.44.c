/*4.44 ¡ô
In Section 3.4.2, the IA32 popl instruction was described as copying the result from
the top of the stack to the destination register and then incrementing the stack
pointer. So, if we had an instruction of the form popl REG, it would be equivalent
to the code sequence:
movl (%esp),REG Read REG from stack
addl $4,%esp Increment stack pointer
A. In light of analysis done in Problem 4.7, does this code sequence correctly
describe the behavior of the instruction popl %esp? Explain.452 Chapter 4 Processor Architecture
B. How could you rewrite the code sequence so that it correctly describes both
the cases where REG is %esp as well as any other register?*/

//1.doesn't

//2.
//addl $4,%esp
//movl -4(%esp),REG