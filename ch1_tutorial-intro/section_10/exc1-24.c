#include <stdio.h>

#define	MAXLINE	1000
#define	MAXDATA	5000

/* Write a program to check a C program for rudimentary syntax errors like
 * unbalanced parentheses, brackets, and braces.  Don't forget about quotes,
 * both single and double, escape sequences, and commas.  (This program is
 * hard if you do it in full generality.
 */

int mygetline(char s[], int limit);

int getBalanceData(char d[], int count, char s[], int length); 
int checkBalance(char d[], int length);

int main()
{
	int length;
	int data_count;
	int status;
	char line[MAXLINE];
	char data[MAXDATA];

	data_count = 0;

	while ((length = mygetline(line, MAXLINE)) > 0)
	{
		printf("LINE is:\n%s\n", line);
		data_count = getBalanceData(data, data_count, line, length);
	}

	status = checkBalance(data, data_count);

	if (status)
		printf("ERROR: a lonely %c\n", data[status]);
	else
		printf("HOORAY!\n");
}

int mygetline(char s[], int limit)
{
	int i, c;
	for(i = 0; i <= limit-1 && (c = getchar()) != EOF && c != '\n'; i++)
	{
		s[i] = c;
	}
	if (c == '\n')
		s[i++] = c;
	s[i] = '\0';

	return i;
}

/* Logic:
 * With each char, if it is:
 * 	(),{},[],'',""
 * 	TODO: /*, \
 * then add to data[].
 */
int getBalanceData(char d[], int count, char s[], int length)
{
	int i;
	for (i=0; i< length; i++)
	{
		switch(s[i]){
		case '(':
			/*printf("open parenthesis\n");*/
			d[count++]=s[i];
			break;
		case ')':
			/*printf("close parenthesis\n");*/
			d[count++]=s[i];
			break;
		case '{':
			/*printf("open curly\n");*/
			d[count++]=s[i];
			break;
		case '}':
			/*printf("close curly\n");*/
			d[count++]=s[i];
			break;
		case '[':
			/*printf("open bracket\n");*/
			d[count++]=s[i];
			break;
		case ']':
			/*printf("close bracket\n");*/
			d[count++]=s[i];
			break;
		case '\'':
			/*printf("single quote\n");*/
			d[count++]=s[i];
			break;
		case '"':
			/*printf("double quote\n");*/
			d[count++]=s[i];
			break;
		default:
			/*printf("char\n");*/
			break;
		}
	}	
	return count;
}
/* Logic:
 * With each char, if it is:
 * 	(),{},[],'',"",/*, or \
 * then need to check for balance
 * or, as with \, need the next
 * char to be n, 0, or t.
 */
int checkBalance(char d[], int length)
{
	int i, j;
	int stack_counter;
	int inSingleQuote;
	int inDoubleQuote;
	int bad_quote_index;
	char stack[length];

	inSingleQuote = 0;
	inDoubleQuote = 0;
	stack_counter = 0;

	for(i=0; i<length; i++)
	{
		if (inSingleQuote)
		{
			if (d[i] != '\'')
				continue;
			else
			{
				/*stack[--stack_counter] = '\0';*/
				--stack_counter;
				inSingleQuote = 0;
				bad_quote_index = 0;
			}
		}
		else if (inDoubleQuote)
		{
			if (d[i] != '"')
				continue;
			else
			{
				/*stack[--stack_counter] = '\0';*/
				--stack_counter;
				inDoubleQuote = 0;
				bad_quote_index = 0;
			}
		}
		else
		{
			if (d[i]=='(' || d[i]=='[' || d[i]=='{')
			{
				stack[stack_counter++] = d[i];	
			} else if (d[i]=='\'')
			{
				stack[stack_counter++] = d[i];	
				inSingleQuote = 1;
				bad_quote_index = i;
			} else if (d[i]=='"')
			{
				stack[stack_counter++] = d[i];	
				inDoubleQuote = 1;
				bad_quote_index = i;
			} else if (d[i]==')')
			{
				if (stack[stack_counter-1] != '(')
					return i;		
				else
				{
					stack[--stack_counter] = '\0';
				}
			} else if (d[i]==']')
			{
				if (stack[stack_counter-1] != '[')
					return i;		
				else
				{
					stack[--stack_counter] = '\0';
				}
			} else if (d[i]=='}')
			{
				if (stack[stack_counter-1] != '{')
					return i;		
				else
				{
					stack[--stack_counter] = '\0';
				}
			}
		}

		printf("stack_counter = %d\n",stack_counter);
		for(j=0; j<stack_counter; j++)
		{
			printf("%c, ",stack[j]);
		}
		printf("\n");
	}
	
	if (inSingleQuote || inDoubleQuote)
		return bad_quote_index;
	return 0;
}
