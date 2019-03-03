#ifndef __PRINTBITS__
#define __PRINTBITS__

#define NUM_BITS 8

#include <stdio.h>
#include <string.h>
#include <math.h>


void printbits(unsigned char x)
{
	int exp, power_test, result;
	char bits[9];
	unsigned char copy = x;

	strcpy(bits, "");
	exp = 0;

	while ( (int) pow(2,exp) < x )
		exp++;
	--exp;

	int i = NUM_BITS - 1;
	for ( ; i >= 0; i--)
	{
		power_test = (int) pow(2, i);
		result = copy - power_test;
		if (result >= 0)
		{
			copy = result;
			strcat(bits, "1");
		}
		else
		{
			strcat(bits, "0");
		}
	}
	bits[8] = '\0';

	printf("%d in bits is >%s<\n", x, bits);
}
#endif
