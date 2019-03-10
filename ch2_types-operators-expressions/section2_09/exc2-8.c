#include <stdio.h>
#include "printbits.h"

#define CHAR_SZ 8

/* Exercise 2-8:
 *	Write a function rightrot(x,n) that returns the value of the integer
 *	x rotated to the right by n bit positions.
 */

unsigned char rightrot(unsigned char x, int n);

int main()
{
	unsigned char x;
	unsigned char result;

	x = 85;					// "01010101" -> 0x55
	printf("Input:\n\t");
	printbits(x);
	result = rightrot(x, 3); 	
	printf("\nOutput:\n\t");
	printbits(result);
	printf("\tExp:\t\t>10101010<\n");	// = 170 -> 0xAA
	

	x = 204;				// "11001100" -> 0xCC
	printf("Input:\n\t");
	printbits(x);
	result = rightrot(x, 3); 	
	printf("\nOutput:\n\t");
	printbits(result);
	printf("\tExp:\t\t>01100110<\n");	// = 102 -> 0x66

	x = 229;				// "11100101" -> 0xE5
	printf("Input:\n\t");
	printbits(x);
	result = rightrot(x, 4); 	
	printf("\nOutput:\n\t");
	printbits(result);
	printf("\tExp:\t\t>01011110<\n");	// = 94 -> 0x5E

return(0);
}

unsigned char rightrot(unsigned char x, int n)
{
	unsigned char keep, keep_mask,
		      zero, _zero;

	zero = 0;
	_zero = ~zero;

	keep_mask = ~(_zero >> n);
/*printf("keep_mask: ");
printbits(keep_mask);*/
	keep = x & keep_mask;
	keep = keep >> (CHAR_SZ - n);
/*printf("keep: ");
printbits(keep);*/

	x = x << n;
/*printf("x: ");
printbits(x);*/

	return (x | keep);
}
