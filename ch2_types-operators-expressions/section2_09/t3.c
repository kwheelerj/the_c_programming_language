#include <stdio.h>
#include <math.h>

int main()
{
	int i, base;

	base = 2;

	for(i = 0; i<= 10; ++i)
	{
		printf("%d\n", pow(2, i));	
	}

/*
	for(i = 0; i<= 10; ++i)
	{
		printf("%d\n", pow(i, 2));	
		printf("%d\n", pow(i, 3));	
		printf("%d\n", pow(i, 4));	
	}
*/

return(0);
}
