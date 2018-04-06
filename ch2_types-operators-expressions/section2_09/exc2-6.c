#include <stdio.h>

/* Write a function "setbits(x, p, n, y)" that returns 'x' with the
 * 'n' bits that begin at position 'p' set to the rightmost 'n' bits of 'y',
 * leaving the other bits unchanged.
 */

unsigned char setbits(unsigned char x, int p, int n, unsigned char y);
void printbits(char s[], unsigned char x);

int main()
{
	unsigned char x = 85;	// "01010101" -> 0x55
	unsigned char y = 204;	// "01010001" -> 0xCC
	unsigned char result;
	
	printbits("x is: ", x);
	printbits("y is: ", y);

	// want result is "01010001" -> 81 -> 0x51
	result = setbits(x, 4, 3, y); 	
	printbits("Result is: ", result);
	printf("(Expected: 0x51)\n");

	return 0;
}

unsigned char setbits(unsigned char x, int p, int n, unsigned char y)
{ 
	unsigned char x_masked;
	unsigned char inter;

	y &= ~(~0 << n);
	y <<= (p + 1 - n);

//	x_masked = x & ~((~ZERO << (p+1)) >> n);
	inter =  ~0 << (p+1);	
	inter = ~(inter >> n);
	
	x &= inter;

	return (x | y);
}

void printbits(char s[], unsigned char x)
{
	printf("%s%x\n", s, x);
}
