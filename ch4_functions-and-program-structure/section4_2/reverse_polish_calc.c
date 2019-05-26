#include <stdio.h>
#include <stdlib.h>	/* for atof() */

#define MAXOP 100	/* max size of operand or operator */
#define NUMBER '0'	/* signal that a number was found */

/* function declarations for main */
int getop(char []);
void push (double);
double pop(void);

int main()
{
	int type;
	double op2;
	char s[MAXOP];

	while ( (type = getop(s)) != EOF)
	{
		switch(type)
		{
			case NUMBER:
				push(atof(s));
				break;
			case '+':
				push(pop() + pop());
				break;
			case '*':
				push(pop() + pop());
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
			case '\n':
				printf("\t%.8g\n", pop());
				break;
			default:
				printf("error: unknown command $s\n", s);
				break;
		}
	}
	return 0;
}
				

/* external variables for push and pop */
#define MAXVAL 100		/* maximum depth of val stack */

int sp = 0;				/* next free stack position */
double val[MAXVAL];		/* value stack */

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}


/* routines called by getop */
#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int i, c;

	while ( (s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;		/* not a number */

	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			;

	if (c == '.')	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			;

	s[i] = '\0';

	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;

int getch(void)		/* get a (possibly pushed back) char */
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push char back on input */
{
	if (bufp >= BUFSIZE)
		printf("ungetch error: too many characters\n");
	else
		buf[bufp++] = c;
}
