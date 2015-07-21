/*
4.47 ◆
In our example Y86 programs, such as the Sum function shown in Figure 4.6, we
encounter many cases (e.g., lines 12 and 13 and lines 14 and 15) in which we want
to add a constant value to a register. This requires ﬁrst using an irmovl instruction
to set a register to the constant, and then an addl instruction to add this value to
the destination register. Suppose we want to add a new instruction iaddl with the
following format:
0
C
Byte
iaddl V, rB
1 2 3 4 5
0 F rB V
This instruction adds the constant value V to register rB. Describe the computa-
tions performed to implement this instruction. Use the computations for irmovl
and OPl (Figure 4.18) as a guide.
*/