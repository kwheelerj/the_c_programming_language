#include <stdio.h>
#include "printbits.h"

#define CHAR_SZ 8

/* Exercise 2-7:
 *	Write a function "invert(x,p,n)" that returns x with the n bits that
 *	begin at position p inverted, leaving the others unchanged.
 */

unsigned char invert(unsigned char x, int p, int n);

int main()
{
	unsigned char x;
	unsigned char result;

	x = 85;					// "01010101" -> 0x55
	printf("Input:\n\t");
	printbits(x);
	result = invert(x, 5, 4); 	
	printf("\nOutput:\n\t");
	printbits(result);
	printf("\tExp:\t\t>01101001<\n");	// = 105 -> 0x69
	

return(0);
}

unsigned char invert(unsigned char x, int p, int n)
{
	unsigned char x_c1, x_c2, x_p, m;

	x_c1 = x >> (p + 1);
	x_c1 <<= (p + 1);

	x_c2 = x << (p + 1);
	x_c2 >>= (p + 1);

	x_p = x_c1 | x_c2;

	m = ~x << CHAR_SZ - (p + 1);
	m >>= CHAR_SZ - (p + 1);
	m >>= (p + 1) - n;
	m <<= (p + 1) - n;

	return (x_p | m);
}
