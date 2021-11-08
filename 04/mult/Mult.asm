// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Mult.asm

// Multiplies R0 and R1 and stores the result in R2.
// (R0, R1, R2 refer to RAM[0], RAM[1], and RAM[2], respectively.)
//
// This program only needs to handle arguments that satisfy
// R0 >= 0, R1 >= 0, and R0*R1 < 32768.

// Put your code here.

// algorithm: use a loop that terminates when R0 == 0. each iteration of the loop adds R1 to exsisting total in R2, and then decrements R0
// set R2 equal to 0
// start loop
// check if R0 = 0, if true move to end
// get number from R1 and add it to R2
// decrement R0 by 1 and move to begining of loop

 
@R2
M=0
(LOOP)
	@R0
	D=M
	@END
	D;JEQ
	
	@R1
	D=M 
	@R2
	M=M+D
	
	@R0
	M=M-1
	
	@LOOP
	0;JMP

(END)
@END
0;JMP