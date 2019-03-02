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
	unsigned char y = 204;	// "11001100" -> 0xCC
	unsigned char result;
	
	printbits("x is:", x);
	printbits("y is:", y);

	// want result is "01010100" -> 84 -> 0x54
	result = setbits(x, 4, 3, y); 	
	printbits("Result is: ", result);
	printf("(Expected: 0x54)\n");

	return 0;
}

unsigned char setbits(unsigned char x, int p, int n, unsigned char y)
{ 
	unsigned char x_masked, y_masked;

	x_masked = x & (~0 << n);		//   "01010101"
						// & "11111000" =
//	printbits("x_masked is:", x_masked); 	//   "01010000" -> 0x50 -> 80

	y_masked = y & ~(~0 << n);		//   "11001100"
						// & "00000111" =
//	printbits("y_masked is:", y_masked);	//   "00000100" -> 0x4 -> 4

	return (x_masked | y_masked);
}

void printbits(char s[], unsigned char x)
{
	printf("%s %x\n", s, x);
}
