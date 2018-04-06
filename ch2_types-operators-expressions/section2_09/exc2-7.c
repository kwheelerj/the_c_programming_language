#include <stdio.h>

/* Write a function "invert(x, p, n)" that retuns 'x' with the
 * 'n' bits that begin at position 'p' inverted (i.e., 1 changed
 * into 0 and vice versa), leaving the others unchanged.
 */

unsigned char invert(unsigned char x, int p, int n);
void printbits(char s[], unsigned char x);

int main()
{
	unsigned char x = 85;	// "01010101" -> 0x55
	unsigned char result;

	printbits("x is: ", x);
	
	result = invert(x, 4, 3);
	printbits("Result is: ", result);
	printf("(Expected: 0x49)\n");
	
	return 0;
}

unsigned char invert(unsigned char x, int p, int n)
{
	unsigned char x_a, a, x_b, b;
	
	x_a = ~0 << (p+1);
	x_a >>= n;
	a = x & ~x_a;
	//printbits("a is: ", a);

	x_b = ~0 << (p+1);
	x_b >>= n;
	b = ~x & x_b;	
	//printbits("b is: ", b);

	return a | b;
}

void printbits(char s[], unsigned char x)
{
	printf("%s%x\n", s, x);
}
