#include <stdio.h>
#include <stdarg.h>

void pprint_addr(int *);
void pprint_val(int *);
void pprint(char *, int *);
void pprint_all(char *, ...);

void swap_wrong(int *, int *);
void swap(int *, int *);

int main()
{
	int x = 1;
	int y = 2;
	swap_wrong(&x, &y);
	printf("++++++++\n");
	swap(&x, &y);

return 0;
}

void swap_wrong(int *px, int *py)
{	// swap the pointers.
	printf("in swap_wrong(int *, int*) function:\n");

	int *temp;

	temp = px;
	pprint_all(" step 1: temp = px;\n", "temp", temp, "px", px, "py", py);

	px = py;
	pprint_all(" step 2: px = py;\n", "temp", temp, "px", px, "py", py);

	py = temp;
	pprint_all(" step 3: py = temp;\n", "temp", temp, "px", px, "py", py);

/* This way is wrong because swapping the pointers will also swap the
 *	values with the pointers, so address 001 will still have value 1
 *	while address 002 will still have value 2 in the end.
 */
/* You need to swap the values at the pointers, swapping the addresses does not impact
 *	the values at the addresses.
 */
/* Here, you are just swapping COPIES of the address, without impact to the values! */
}

void swap(int *px, int *py)
{	// swap the values at the pointer.
	int temp;

	temp = *px;
	pprint_all(" step 1: temp = *px;\n", "temp", &temp, "px", px, "py", py);

	*px = *py;
	pprint_all(" step 2: *px = *py;\n", "temp", &temp, "px", px, "py", py);

	*py = temp;
	pprint_all(" step 3: *py = temp;\n", "temp", &temp, "px", px, "py", py);
}

void pprint_all(char *s, ...)
{
	va_list ap;
	char *var_name;
	int var;
	int *pvar;

	printf("%s", s);

	va_start(ap, s);

	var_name = va_arg(ap, char *);
	pvar = va_arg(ap, int *);
	pprint(var_name, pvar);

	var_name = va_arg(ap, char *);
	pvar = va_arg(ap, int *);
	pprint(var_name, pvar);

	var_name = va_arg(ap, char *);
	pvar = va_arg(ap, int *);
	pprint(var_name, pvar);

	printf(" ==========\n");
}
void pprint(char *s, int *p)
{
	printf("  [ptr *%s]\n", s);
	pprint_addr(p);
	pprint_val(p);
	printf("  ---\n");
}
void pprint_addr(int *p)
{
	printf("    addr : <%d>\n", p);
}
void pprint_val(int *p)
{
	printf("    val  : |%d|\n", *p);
}
