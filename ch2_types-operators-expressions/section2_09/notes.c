#include <stdio.h>
#include <string.h>
#include <math.h>

void printhex(unsigned char x);
void printbits(unsigned char x);

int main()
{
	char n[9] = "10101010";
	unsigned char x = 85;	// "01010101" -> 0x55
	unsigned char y = 255;	// "11111111" -> 0xFF
	unsigned char result;
	
	printhex(x);
	printbits(x);
	printhex(y);
	printbits(y);

	result = x & 0177;
	printhex(result);
	printbits(result);

	result = y & 0177;	
	printhex(result);
	printbits(result);

	return 0;
}

void printhex(unsigned char x)
{
	printf("%d in hex is >%x<\n", x, x);
}

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

	int i = 7;
	for ( ; i >= 0; i--)
	{
		power_test = (int) pow(2, i);
		result = copy - power_test;
		//printf("\t%d = %d - %d\n", result, copy, power_test);
		if (result >= 0)
		{
			copy = result;
			strcat(bits, "1");
		}
		else
		{
			strcat(bits, "0");
		}
		//printf("\t\t>%s<\n", bits);
	}
	bits[8] = '\0';

	printf("%d in bits is >%s<\n", x, bits);
}
