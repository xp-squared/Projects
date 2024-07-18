; https://schweigi.github.io/assembler-simulator/ for testing

start:

	; For this lab you’re going to make a program that can take a given number, and double it a set amount of times. For example, if someone gave you “3 doubled 4 times” the result would be 48.

	; The doubler doesn’t need to handle results greater than 255, so don’t worry about overflow and carry. Also a helpful reminder, in X86, shift operators are denoted as SHR and SHL (for shift logical right and shift logical left), and SAR and SAL (for shift arithmetic right and arithmetic left).

	; NOTES: so if you have 3 in binary (0011) and want to double it to 6 (0110) you shift the binary to the left (Logical shift to the left)

	MOV A, 3 ; this is where you input your number
	SHL A, 4 ; how many times you want to double your input number

	
	CMP A, 100         
	JNB three_digits      


two_digits:

	MOV B, A 
	DIV 10
	MUL 10
	SUB B, A

	; okay at this point, A = 70, B = 4
	; we need to output both of these values now
	; 48-57 is 0 through 9
	MOV A, A
	DIV 10; making this just the single first digit
	; A =7, B = 4

	MOV C, 48
	ADD C, A 
	MOV D, 232
	MOV [D], C

	INC D ; increase D value
	MOV C, 48; start from 0, add the remaining of the number 
	ADD C, B; output other part of number
	MOV [D], C
	HLT ; Stop execution

three_digits:

	MOV B, A ; b = 213 now
	DIV 100 ; b = 2
	MUL 100 ; b = 200
	SUB B, A ; b = 13
	; okay at this point, A = 213 , B = 13


	MOV A, A 
	; going to a
	DIV 100 
	; a = 2 BECAUSE 213 / 100 = 2

	; outputting a
	MOV C, 48
	ADD C, A 
	MOV D, 232
	MOV [D], C
	INC D ; increase D value

	; b = 13 still
	MOV A, B ; PUTTING B INTO A'S PLACE AS WELL FOR PLACEHOLDER
	MOV B, B ; B = 13 
	DIV 10 ; B = 1
	MUL 10 ; B = 10

	SUB B, A 
	; 13 - 10 = 3
	; B = 3, A = 13

	MOV A, A
	DIV 10

	
	MOV C, 48
	ADD C, A
	MOV [D], C
	INC D ; increase D value


	MOV C, 48
	ADD C, B
	MOV [D], C
	HLT ; Stop execution

