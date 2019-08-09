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

	printf("Before while loop\n");
	while ( (type = getop(s)) != EOF)
	{
		printf("In switch:\n");
		switch(type)
		{
			case NUMBER:
				printf("\tNUMBER:%s\n", s);
				push(atof(s));
				break;
			case '%':
				printf("\t%\n");
				op2 = pop();
				push((int)pop() % (int)op2);
				break;
			case '+':
				printf("\t+\n");
				push(pop() + pop());
				break;
			case '*':
				printf("\t*\n");
				push(pop() * pop());
				break;
			case '-':
				printf("\t-\n");
				op2 = pop();
				push(pop() - op2);
				break;
			case '/':
				printf("\t/\n");
				op2 = pop();
				if (op2 != 0.0)
					push(pop() / op2);
				else
					printf("error: zero divisor\n");
				break;
			case '\n':
				printf("\t\\n\n");
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
	printf("void push(double f = %g)\n", f);
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	printf("double pop(void)\n");
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
	printf("int getop(char s[])\n");
	int i, c;

	while ( (s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	printf("s = %s\n", s);
	printf("c = %c\n", c);
	if ( !isdigit(c) && (c != '.' && c != '-') )
	{
		return c;		/* not a number */
	}

	i = 0;
	if (isdigit(c))		/* collect integer part */
		while (isdigit(s[++i] = c = getch()))
			printf("true\n");

	if (c == '.')	/* collect fraction part */
		while (isdigit(s[++i] = c = getch()))
			printf("true2\n");
	if (c == '-')
	{
		printf("here\n");
		if ( !isdigit(s[++i] = c = getch()) )
		{
			printf("here: c = %c\n", c);
			ungetch(c);
			return '-';
		}
		printf("out: c = %c\n", c);
		while (isdigit(s[++i] = c = getch()))
			;
	}

	s[i] = '\0';

	printf("s = %s\n", s);
	if (c != EOF)
		ungetch(c);

	return NUMBER;
}

#define BUFSIZE 100

char buf[BUFSIZE];		/* buffer for ungetch */
int bufp = 0;

int getch(void)		/* get a (possibly pushed back) char */
{
	printf("int getch(void)\n");
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)		/* push char back on input */
{
	printf("void ungetch(int c = %d)\n", c);
	printf("ungetch(char c = %c)\n", c);
	if (bufp >= BUFSIZE)
		printf("ungetch error: too many characters\n");
	else
		buf[bufp++] = c;
}
