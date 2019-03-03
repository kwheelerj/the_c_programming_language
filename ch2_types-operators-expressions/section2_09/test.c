#include <stdio.h>
#include "printbits.h"

void printhex(char s[], unsigned char x);

int main()
{
	unsigned char x = 255;	// "11111111" -> 0xff
	unsigned char result;

	printhex("x is: ", x);
	
	result = x & 077; 	// oct 77, dec 63, hex 3f
	printhex("077 is:", 077);
	printhex("result is:", result);
	printbits(result);

	result = x & 77;
	printhex("77 is:", 77);
	printhex("result is:", result);
	printbits(result);
	
	return 0;
}

void printhex(char s[], unsigned char x)
{
	printf("%s %x\n", s, x);
}
