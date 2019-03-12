#include <stdio.h>

/* In a two's complement number system, x &= (x-1) deletes the rightmost
 * 1-bit in x.  Use this observation to write a faster version of "bitcount".
 */

/* "01010101" *//* "01010100" *//* "01010000" *//* "0100000" */
/* "01010100" *//* "01010011" *//* "01001111" *//* "0011111" */
/* "01010100" *//* "01010000" *//* "01000000" *//* "0000000" */

/* Every iteration causes the most right 1-bit to be effectively removed */

int bitcount_fast(unsigned char x);

int main()
{
	unsigned char x = 85;
	int result;
	
	result = bitcount_fast(x);
	
	printf("1-bits count is: %d\n", result);

	return 0;
}

int bitcount_fast(unsigned char x)
{
	int b;

	for (b = 0; x != 0; x&=(x-1))
		b++;

	return b;
}
