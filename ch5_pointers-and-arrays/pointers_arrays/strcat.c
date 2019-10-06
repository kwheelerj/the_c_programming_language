#include <stdio.h>

void strcat_old(char[], char[]);


int main()
{
	//char str1[] = "This is a complet";
	char str1[30] = "This is a complet";
	char str2[] = "e sentence.";

	printf("str1 = >%s<\n", str1);
	strcat_old(str1, str2);
	printf("str1 = >%s<\n", str1);

/* This program throws a segmentation fault, but it still completes.
 *	I believe this is because the strcat_old method (given from book)
 *	actually writes over garbage since it iterates out of bounds
 *	of the allocated space for str1.
 * A simple fix for this is to give the str1 char array a size large
 *	enough to be concatenated into.
 */

return 0;
}

void strcat_old(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0')    /* find end of s */
		i++;
	while ((s[i++] = t[j++]) != '\0')    /* copy t */
//		printf("\tso far s = >%s<\n", s);
		;
	s[i] = '\0';
}
