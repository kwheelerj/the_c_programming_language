#include <stdio.h>
#include <ctype.h>

double atof(char [])
double atof_old(char [])


int main()
{
	char *inp = "123.1234";
	float res;

	res = atof_old(inp);
	printf("res = >%f<\n", f);

	res = atof(inp);
	printf("res = >%f<\n", f);

return 0;
}

double atof(char s[])
{
	double val, power;
	int sign;

	for ( ; isspace(*s); s++)	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}

double atof_old(char s[])
{
	double val, power;
	int i, sign;

	for (i=0; isspace(s[i]); i++)	/* skip white space */
		;
	sign = (s[i] == '-') ? -1 : 1;
	if (s[i] == '+' || s[i] == '-')
		i++;
	for (val = 0.0; isdigit(s[i]); i++)
		val = 10.0 * val + (s[i] - '0');
	if (s[i] == '.')
		i++;
	for (power = 1.0; isdigit(s[i]); i++)
	{
		val = 10.0 * val + (s[i] - '0');
		power *= 10.0;
	}

	return sign * val / power;
}
