#include <stdio.h>
#include "printbits.h"

/* Write a function "setbits(x, p, n, y)" that returns 'x' with the
 * 'n' bits that begin at position 'p' set to the rightmost 'n' bits of 'y',
 * leaving the other bits unchanged.
 */
/* EXAMPLE:
 * 	x = "01010101" // = 85
 * 	y = "11001100" // = 204
 * 	result = setbits(x, 3, 4 y);
 * 	printbits(result); // "01011100"
 *
 * 	x = "01010101" // = 85
 * 	y = "11001100" // = 204
 * 	result = setbits(x, 3, 3 y);
 * 	printbits(result); // "01011001"
 *
 */

unsigned char setbits(unsigned char x, int p, int n, unsigned char y);

int main()
{
	unsigned char x = 85;	// "01010101" -> 0x55
	unsigned char y = 204;	// "11001100" -> 0xCC
	unsigned char result;
	
	printf("Input:\n\t");
	printbits(x);
	printf("\t");
	printbits(y);

	result = setbits(x, 3, 4, y); 	
	printf("\nOutput:\n\t");
	printbits(result);
	printf("\tExp:\t\t>01011100<\n");	// = 92 -> 0x5C

	result = setbits(x, 4, 3, y); 	
	printf("\t");
	printbits(result);
	printf("\tExp:\t\t>01010001<\n");	// = 81 -> 0x51

	result = setbits(x, 3, 3, y); 	
	printf("\t");
	printbits(result);
	printf("\tExp:\t\t>01011001<\n");	// = 89 -> 0x59

	return 0;
}

unsigned char setbits(unsigned char x, int p, int n, unsigned char y)
{
	unsigned char x_m, x_m2;
	x_m = x >> n;
	x_m = x_m << n;

	if (p >= n)
	{
		x_m2 = x << (p + n);
		x_m2 = x_m2 >> (p + n);
		x_m = x_m | x_m2;
	}

	y = y << (8 - n);
	y = y >> (8 - n);
	y = y << p - (n - 1);

	return x_m | y;
}
