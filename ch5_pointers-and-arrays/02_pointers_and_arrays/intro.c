#include <stdio.h>

int main()
{
	int a[10];
	for (int i=0; i < 10; i++)
		a[i] = i+1;

	int *pa_1;
	int *pa_2;

	pa_1 = &a[0];
	pa_2 = a;

	int x1, x2;
	x1 = *pa_1;
	x2 = *pa_2;

	printf("x1 = <%d>\n", x1);
	printf("x2 = <%d>\n", x2);

printf("===\n");
	printf("     a[1] = <%d>\n", a[1]);
	printf("   *(a+1) = <%d>\n", *(a+1));
	printf("  pa_2[1] = <%d>\n", pa_2[1]);
	printf("*(pa_2+1) = <%d>\n", *(pa_2+1));
	printf("  pa_1[1] = <%d>\n", pa_1[1]);
	printf("*(pa_1+1) = <%d>\n", *(pa_1+1));

return(0);
}
