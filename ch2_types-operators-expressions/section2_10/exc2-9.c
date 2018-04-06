#include <stdio.h>

/* In a two's complement number system, x &= (x-1) deletes the rightmost
 * 1-bit in x.  Use this observation to write a faster version of "bitcount".
 */

int bitcount_fast(unsigned char x);

int main()
{
	unsigned char x = 85;
	int result;
	
	result = bitcount_fast(x);
	
	printf("1 bits count is: %d\n", result);

	return 0;
}

int bitcount_fast(unsigned char x)
{
	int b;

	for (b = 0; x != 0; x&=(x-1))
		b++;

	return b;
}
