#include <stdio.h>
#include <math.h>

void printhex(unsigned char x);
void printbits(unsigned char x);

int main()
{
	char n[9] = "10101010";
	unsigned char x = 85;	// "01010101" -> 0x55
	unsigned char y = 255;	// "11111111" -> 0xFF
	unsigned char result;
	
	printhex("x is:", x);
	printhex("y is:", y);

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
	printf("Result in hex is >%x<\n", x);
}

void printbits(unsigned char x)
{
	int exp = -1;
	while ( (int)pow(2,exp) < x )
		exp++;

	int i = exp;
	for ( ; i >= 0; i++) {
		result = num - (2^exp
	}
	printf("Result in bits is >%x<\n", x);
}
