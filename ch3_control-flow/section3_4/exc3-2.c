#include <stdio.h>

#define MAXLIMIT	10000
/* Write a function "escape(s, t)" that converts characters like newline
 * and tab into visible sequences like "\n" and "\t" as it copies the string
 * t to s.  Use a switch.  Write a function for the other direction as well,
 * converting escape sequences into the real characters.
 */

int mygetline(char s[], int limit);
void escape(char t[], char s[], int limit);
void unescape(char t[], char s[], int limit);

int main()
{
	char line[MAXLIMIT];
	char escaped_line[MAXLIMIT];
	char unescaped_line[MAXLIMIT];

	mygetline(line, MAXLIMIT);
	escape(line, escaped_line, MAXLIMIT);
	unescape(escaped_line, unescaped_line, MAXLIMIT);

	printf("%s\n", escaped_line);
	printf("%s\n", unescaped_line);

	return 0;
}


void unescape(char t[], char s[], int limit)
{
	int i, j = 0;

	for (i = 0; i < limit-1 && t[i] != '\0'; i++)
	{
		if (t[i] == '\\')
		{
			switch(t[i+1])
			{
				case 't':
					s[j++] = '\t';				
					i++;
					break;
				case 'n':
					s[j++] = '\n';
					i++;
					break;
				default:
					s[j++] = t[i];
			}

		}
		else
			s[j++] = t[i];
	}
	s[j] = '\0';
}


void escape(char t[], char s[], int limit)
{
	int i, j = 0;

	for (i = 0; i < limit-1 && j < limit-1 && t[i] != '\0'; i++)
	{
		switch (t[i])
		{
		case '\n':
			if (j < limit-2)
			{	
				s[j++] = '\\';
				s[j++] = 'n';
			}
			else
				s[j++] = '*';
			break;
		case '\t':
			if (j < limit-2)
			{
				s[j++] = '\\';
				s[j++] = 't';
			}
			else
				s[j++] = '*';
			break;
		default:
			s[j++] = t[i];
			break;
		}
	}
	s[j] = '\0';

}

int mygetline(char s[], int limit)
{
	int i;
	char c;

	for (i=0; i<limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	if (c= '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}


















