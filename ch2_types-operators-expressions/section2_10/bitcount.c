#include <stdio.h>

/* bitcount: count 1 bits in 'x' */
int bitcount(unsigned char x);

int main()
{
	unsigned char x = 85;
	int result;
	
	result = bitcount(x);
	
	printf("1 bits count is: %d\n", result);

	return 0;
}

int bitcount(unsigned char x)
{
	int b;

	for (b = 0; x != 0; x >>= 1)
		if (x & 01)
			b++;
	return b;
}
