#include <stdio.h>
#include <math.h>

void printbits(unsigned char x);

int main()
{
	double exp = 3.1;
	double d;

	d = pow(2, 3);
	printf("%f\n", d);

	//d = pow(2, 3.1);
	d = pow(2.3, exp);
	printf("%f\n", d);

return(0);
}
