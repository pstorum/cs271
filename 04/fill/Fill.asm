// This file is part of www.nand2tetris.org
// and the book "The Elements of Computing Systems"
// by Nisan and Schocken, MIT Press.
// File name: projects/04/Fill.asm

// Runs an infinite loop that listens to the keyboard input.
// When a key is pressed (any key), the program blackens the screen,
// i.e. writes "black" in every pixel;
// the screen should remain fully black as long as the key is pressed. 
// When no key is pressed, the program clears the screen, i.e. writes
// "white" in every pixel;
// the screen should remain fully clear as long as no key is pressed.

// Put your code here.

@black
M=-1
@white
M=0

(INPUT)
	@SCREEN
	D=A
	@pixel
	M=D
	
	@KBD
	D=M
	@BLACKEN
	D;JGT
	@WHITEN
	0;JMP

(BLACKEN)
	@black
	D=M
	@pixel
	A=M
	M=D
	
	@pixel
	M=M+1
	D=M
	
	@24576
	D=D-A
	@BLACKEN
	D;JLT
	
@INPUT
0;JMP

(WHITEN)
	@white
	D=M
	@pixel
	A=M
	M=D
	
	@pixel
	M=M+1
	D=M
	
	@24576
	D=D-A
	@WHITEN
	D;JLT
	
@INPUT
0;JMP
