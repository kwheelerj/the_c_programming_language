#include <stdio.h>

#define dprint(expr) printf(#expr " = %g\n", expr)
//#define paste(front,back) front ## back
#define swap(t,x,y) { t tmp = x; x = y; y = tmp; }

/* printd: print n in decimal */
void printd(int n)
{
	if (n < 0)
	{
		putchar('-');
		n = -n;
	}
	if (n / 10)
		printd(n / 10);
	putchar(n % 10 + '0');
}

int main()
{
/*
	char str[10] = paste("12", "45");
	printf("%s\n", str);
*/

int x = 10;
int y = 2

dprint(x/y);

return 0;
}
