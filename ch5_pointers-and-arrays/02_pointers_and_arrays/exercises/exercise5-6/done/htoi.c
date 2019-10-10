#include <stdio.h>

/* Write the function htoi(s), which converts a string of hexadecimal digits
 * (including an optional "Ox" or "OX") into its equivalent integer value.
 * The allowable digits are 0 through 9, 'a' through 'f', and 'A' through 'F'.
 */

int htoi_old(char []);
int htoi(char *);


int main()
{
	int decimal;
	char *input = "0xff";
	
	printf("%d\n", 'f');
	printf("%d\n", 'a');
	printf("%d\n", 'F');
	printf("%d\n", 'A');

	decimal = htoi_old(input);
	printf("Decimal value of %s is: %d\n", input, decimal);

	decimal = htoi(input);
	printf("Decimal value of %s is: %d\n", input, decimal);

	input = "0xKK";
	decimal = htoi(input);
	printf("Decimal value of %s is: %d\n", input, decimal);

return 0;
}

int htoi(char *s)
{
	int dec, additional;
	dec = 0;
	
	while(*s != '\0')
	{
		additional = 0;

		if (*s <= 'F' && *s >= 'A')
			additional = *s - 55;
		else if (*s <= 'f' && *s >= 'a')
			additional = *s - 87;
		else if (*s >= '0' && *s <= '9')
			additional = *s - '0';
		else {
			printf(">%c< is an invalid character - filtering out\n", *s++);
			continue;
		}

		dec = 16 * dec + (additional);
		
		s++;
	}

	return dec;
}

int htoi_old(char s[])
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
		else {
			printf(">%c< is an invalid character - filtering out\n", s[i++]);
			continue;
		}

		dec = 16 * dec + (additional);
		
		i++;
	}

	return dec;
}
