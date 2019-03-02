#include <stdio.h>

/* Write the function "any(s1, s2)", which returns the first location in
 * the string "s1" where any character from the string "s2" occurs,
 * or "-1" if "s1" contains no characters from "s2".  (The standard library
 * function "strpbrk" does the same job but returns a pointer to the location.)
 */

#define MAXLIMIT	1000

int mygetline(char s[], int limit);
int any(char s1[], char s2[]);

int main()
{
	char line1[MAXLIMIT];
	char line2[MAXLIMIT];
	int location;

	mygetline(line1, MAXLIMIT);
	mygetline(line2, MAXLIMIT);

	location = any(line1, line2);
	printf("Location found: %d\n", location);

	return 0;
}

int mygetline(char s[], int limit)
{
	int i;
	char c;

	for (i=0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c == '\n')
		s[i++] = '\0';
	//s[i] = '\0';

	return i;
}

int any(char s1[], char s2[])
{
	int i, k, loc;
	loc = -1;
	
	for (i = 0; s1[i] != '\0'; i++)
	{
		for (k = 0; s2[k] != '\0'; k++)
		{
			if (s1[i] == s2[k])
			{
				loc = i;
				break;
			}
				 
		}
		if (loc != -1)
			break;
		
	}
	return loc;
}
