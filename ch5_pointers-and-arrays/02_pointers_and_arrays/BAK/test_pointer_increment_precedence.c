#include <stdio.h>

void print_ptr(int *v)
{
	printf("pointer address = %d\n", v);
	printf("pointer value = %d\n\n", *v);
}

int main()
{
	int var1 = 11;
	int *p = &var1;
	
	char *pc = "kenneth";

	printf("orignal:\n");
	print_ptr(&var1);

	++*p;
	print_ptr(&var1);

	(*p)++;
	print_ptr(&var1);

	*p++
	/* derefrence the pointer, then increment the value */

	*++pc;
	/* Increment pointer, then dereference the pointer */
	print_ptr(p);

return 0;
}
