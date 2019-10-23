#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>	/* for atoi() */

#define NUMBER '0'	/* signal that a number was found */

int getType(char);
void push(int);
int pop(void);

int main(int argc, char *argv[])
{
if (argc < 4)
{
	printf("Usage: expr <num> <num> <op> ...\n");
	return -1;
}

	int type;
	double op2;
	char c;
	char *s;

	while ( (s = *++argv) && (c = *s))
	{
		type = getType(c);
		switch(type)
		{
			case NUMBER:
				push(atoi(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() * pop());
				break;
			case '-':
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			default:
				printf("error: unknown command $s\n", s);
				break;
		}
	}
	printf("Result: >%d<\n", pop());
	return 0;
}
				

/* external variables for push and pop */
#define MAXVAL 100		/* maximum depth of val stack */


int sp = 0;				/* next free stack position */
int val[MAXVAL];		/* value stack */

void print_stack(void);

void push(int n)
{
	if (sp < MAXVAL)
		val[sp++] = n;
	else
		printf("error: stack full, can't push %d\n", n);
	//print_stack();
}

int pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0;
	}
}

void print_stack(void)
{
	for (int i = 0; i < sp; i++)
		printf("\t%d : >%d<\n", i+1, val[i]);
}


int getType(char c)
{
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */

	return NUMBER;
}
