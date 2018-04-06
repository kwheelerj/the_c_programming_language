#include <stdio.h>

/* Write a function "rightrot(x, n)" that returns the value of the
 * integer 'x' rotated to the right by 'n' bit positions.
 */

unsigned char rightrot(unsigned char x, int n);
void printbits(char s[], unsigned char x);

int main()
{
	unsigned char x = 85;	// "01010101" -> 0x55
	unsigned char result;

	printbits("x is: ", x);
	
	result = rightrot(x, 3);
	printbits("Result is: ", result);
	printf("(Expected: 0xaa)\n");
	
	return 0;
}

unsigned char rightrot(unsigned char x, int n)
{
	unsigned char x_a, x_b;

	x_a = x >> n;
	x_b = x << (8-n);

	return x_a | x_b;

}

void printbits(char s[], unsigned char x)
{
	printf("%s0x%x\n", s, x);
}
