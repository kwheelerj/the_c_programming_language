#include <stdio.h>

/* Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional "Ox" or "OX") into its equivalent integer value.
 * The allowable digits are 0 through 9, 'a' through 'f', and 'A' through 'F'.
 */

#define MAXLIMIT	1000

int htoi(char s[]);
int mygetline(char s[], int length);

int main()
{
	int length, decimal;
	char line[MAXLIMIT];

	while ((length = mygetline(line, MAXLIMIT)) > 0)
	{
		decimal = htoi(line);
		printf("Decimal value of %s is: %d\n", line, decimal);
	}
	return 0;
}

int htoi(char s[])
{
	int i, dec, additional;
	i = dec = 0;
	
	while(s[i] != '\0')
	{
		additional = 0;

		if (s[i] <= 'F' && s[i] >= 'A')
			additional = s[i] - 55;
		else if (s[i] <= 'f' && s[i] >= 'a')
			additional = s[i] - 87;
		else if (s[i] >= '0' && s[i] <= '9')
			additional = s[i] - '0';

		dec = 16 * dec + (additional);
		
		i++;
	}

	return dec;
}

int mygetline(char s[], int limit)
{
	int i;
	char c;

	for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c = '\n')
		s[i++] = '\0';
	//s[i] = '\0';
	
	return i;
}

























