#include <stdio.h>

void test(int, int, float);

int main()
{
	int a = 12;
	float b = 4.1;
	float c = 4.0;

	test(1, a, b);
	test(2, a, c);


printf("Conclusion:\n");
printf("\tint op float will PROMOTE the answer to a float; be prepared to store it or print as such.\n");
printf("\tIf you print %%d for a float-sized value, then the decimal places (float part) will be truncated.\n");

return 0;
}

void test(int testcase_num, int i, float f)
{
	int	int_sized_var;
	float float_sized_var;

	printf("test case %d: i = %d; f = %.1f\n", testcase_num, i, f);
	printf("-----------------------------\n");

	printf("\tmultiply operator:\n");
	printf("\t------------------\n");
	int_sized_var = i * f;
	float_sized_var = i * f;
	printf("\ta) i * f = %d [%%d]\n", i * f);
	printf("\tb) (float)i * f = %d [%%d]\n", (float)i * f);
	printf("\t*c) i * f = %f [%%f]\n", i * f);
	printf("\td) (float)i * f = %f [%%f]\n", (float)i * f);
	printf("\te) (i * f => ) int_sized_var = %d [%%d]\n", int_sized_var);
	printf("\t*f) (i * f => ) float_sized_var = %f [%%f]\n\n", float_sized_var);

	printf("\tdivision operator:\n");
	printf("\t------------------\n");
	int_sized_var = i / f;
	float_sized_var = i / f;
	printf("\ta) i / f = %d [%%d]\n", i / f);
	printf("\tb) (float)i / f = %d [%%d]\n", (float)i / f);
	printf("\t*c) i / f = %f [%%f]\n", i / f);
	printf("\td) (float)i / f = %f [%%f]\n", (float)i / f);
	printf("\te) (i / f => ) int_sized_var = %d [%%d]\n", int_sized_var);
	printf("\t*f) (i / f => ) float_sized_var = %f [%%f]\n\n", float_sized_var);
	printf("=============================\n");
}
