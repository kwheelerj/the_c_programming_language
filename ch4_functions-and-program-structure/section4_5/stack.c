#include <stdio.h>

#include "calc"

#define MAXVAL 100		/* maximum depth of val stack */

static int sp = 0;				/* next free stack position */
static double val[MAXVAL];		/* value stack */

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
	if (sp > 0)
		return val[--sp];
	else
	{
		printf("error: stack empty\n");
		return 0.0;
	}
}
