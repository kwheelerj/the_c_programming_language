#include <stdio.h>

/* Write a function "invert(x, p, n)" that retuns 'x' with the
 * 'n' bits that begin at position 'p' inverted (i.e., 1 changed
 * into 0 and vice versa), leaving the others unchanged.
 */

unsigned char invert(unsigned char x, int p, int n);
void printbits(char s[], unsigned char x);

int main()
{
	unsigned char x = 255;	// "11111111" -> 0xff
	unsigned char result;

	printbits("x is: ", x);
	
	result = x & 077; 	// oct 77, dec 63, hex 3f
	printbits("077 is:", 077);
	printbits("result is:", result);

	result = x & 77;
	printbits("77 is:", 77);
	printbits("result is:", result);
	
	return 0;
}

void printbits(char s[], unsigned char x)
{
	printf("%s %x\n", s, x);
}
