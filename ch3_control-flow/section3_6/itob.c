#include <stdio.h>
#include <math.h>

/* Exercise 3-5:
 *	Write the function itob(n,s,b) that converts the integer
 *	n into a base b character representation in the string s.
 *	In particular, itob(n,s,16) formats n as a hexadecimal
 *	integer in s.
 */
void itob(int n, char s[], int b);
char get_val(int n);

int main()
{
	char result[32];
	int number, base;

	number = 16;
	base = 16;
	itob(number, result, base);
	printf("itob(%d, result[], %d) = >%s<\n", number, base, result);

	number = 17;
	base = 16;
	itob(number, result, base);
	printf("itob(%d, result[], %d) = >%s<\n", number, base, result);

	number = 35;
	base = 10;
	itob(number, result, base);
	printf("itob(%d, result[], %d) = >%s<\n", number, base, result);

	number = 55;
	base = 8;
	itob(number, result, base);
	printf("itob(%d, result[], %d) = >%s<\n", number, base, result);

	number = 478;
	base = 8;
	itob(number, result, base);
	printf("itob(%d, result[], %d) = >%s<\n", number, base, result);

	number = 478;
	base = 16;
	itob(number, result, base);
	printf("itob(%d, result[], %d) = >%s<\n", number, base, result);

return(0);
}

void itob(int n, char s[], int b)
{
/*
	printf("-----------------------------\n");
	printf("itob(%d, s[], %d)\n", n, b);
*/
	int num, good_num, val,
		power, i, j;

	power = -1;

	/* get the higher power */
	while ( (val = pow((double)b, (double)(power+1))) <= n)
		power++;

	/* loop for each power (descending) to get result char array */
	num = n;
	j = 0;

/*
	printf("-----------------------------\n");
	printf("INIT Tests (before loop):\n");
	printf("\tinitial num = >%d<\n", num);
	printf("\thighest power = >%d<\n", power);
*/
	while (power >= 0)
	{
		i = 0;
		while ( (val = i * pow((double)b, (double)power)) <= num )
		{
			i++;
			good_num = val;
		}
		s[j++] = (b == 16) ? get_val(i-1) : ( (i-1) + '0' );
		num -= good_num;
		power--;

/*
		printf("\n\tTests (bottom of loop):\n");
		printf("\t\ts[] (so far...) = >%s<\n", s);
		printf("\t\tnum (is now) = >%d<\n", num);
		printf("\t\tpower (decr) = >%d<\n", power);
*/
	}
	s[j] = '\0';

}

char get_val(int n)
{
	if (n >= 0 && n < 10)
		return n + '0';
	return n + 55;
}
