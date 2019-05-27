#include <stdio.h>
#include <ctype.h>

/* atof: convert string s to double,
 *	while handling scientific notation
 */
double atof_sci(char s[])
{
	double val, power;
	int i,j, sign;
	int sci_val;
	int sci_power = 1;
	int SCI_FLAG = 0;
	int sci_sign_neg = 0;

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

	val = sign * val / power;
	
	if (s[i] == 'e' || s[i] == 'E')
	{
		SCI_FLAG = 1;
		i++;
	}

	if (SCI_FLAG)
	{
		sci_sign_neg = s[i] == '-';
		if (s[i] == '+' || s[i] == '-')
			i++;

		for (sci_val = 0; isdigit(s[i]); i++)
			sci_val = 10 * sci_val + (s[i] - '0');

		for (j=0; j < sci_val; j++)
			sci_power *= 10;

		if (sci_sign_neg)
			val /= sci_power;
		else
			val *= sci_power;
	}

	return val;
}
