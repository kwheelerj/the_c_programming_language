#include <stdio.h>

/* Write a program to remove trailing blanks and tabs from each line
 * of input, and to delete entirely blank lines.
 */

#define MAXLINE	1000

int mygetline(char line[], int maxline);
void trim(char s[], int length);

int main()
{
	int len;
	char line[MAXLINE];

	while((len = mygetline(line, MAXLINE)) > 0)
	{
		trim(line, len);
		if (line[0] != '\n')
			printf(">%s<\n", line);
	}

	return 0;
}

int mygetline(char s[], int limit)
{
	int c, i;

	for (i = 0; i < limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
		s[i] = c;
	/*if (c == '\n')
		s[i++] = c;
	*/
	s[i] = '\0';

	return i;
}

void trim(char s[], int length)
{
	int i, atFirstWord, inWord, return_s_index, end;
	atFirstWord = inWord = return_s_index = end = 0;

	for (i = 0; i < length; i++)
	{
		if (!atFirstWord)
		{
			if (s[i] != ' ' && s[i] != '\t')
			{
				atFirstWord = inWord = 1;
				s[return_s_index++] = s[i];
				end=return_s_index;
			}
		}
		else
		{
			if (inWord) {
				if (s[i] == '\t' || s[i] == ' ')
				{
					inWord=0;
					end=return_s_index;	
				}	
				else 
					end=return_s_index + 1;	
				s[return_s_index++] = s[i];
			} 
			else {
				if (s[i] !='\t' && s[i] != ' ') {
					inWord=1;
					end=return_s_index + 1;
				}
				s[return_s_index++] = s[i];

			}		
			
		}
	}
	s[end] = '\0';
}
