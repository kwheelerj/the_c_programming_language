#include <stdio.h>
#include "printbits.h"

/* getbits: get n bits from position p */
/* position 0 is far right */

/* 1 & x is going to keep x the same
 * 0 & x is going to "change" x to '0'
 *
 * 1 | x is going to "change" x to '1'
 * 0 | x is going to keep x the same.
 */

unsigned char getbits(unsigned char x, int p, int n);

int main()
{
	unsigned char input = 85;	// "01010101"
	unsigned char result;

	result = getbits(input, 4 ,3);
	printbits(result);	// expect 101


return(0);
}

unsigned char getbits(unsigned char x, int p, int n)
{
	/*	  "00010101"
	 *	& "00000111"
	 */
	return (x >> (p+1-n)) & ~(~0 << n);
}
