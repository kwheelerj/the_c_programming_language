#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>

#define BUF_SZ 500

int main()
{
	printf("Max float value = %f\n", FLT_MAX);
	
	float _f = FLT_MAX;
	
	float fa = _f % 10.0f;
	printf("fa = >%f<\n", fa);

return 0;

	double f = _f;
	
	double integral;
	double fraction;
	int n;
	char c;
	char buf[BUF_SZ];
	memset(buf, '\0', BUF_SZ);
	int ibuf = 0;
	int count = 0;
	double work;
	double ten = 10.0;

int i = 2;
while (i > 0)
//while (f > 0)
{
	printf("======================\n");
	printf("top f = %lf\n", f);
	integral = trunc(f);
	fraction = f - integral;

	printf("integral = >%lf<\n", integral);
	printf("fraction = >%lf<\n", fraction);

	work = integral;
	double subtract = 1.0;
	while (work > ten)
	{
		work /= ten;
		printf("\t_work = >%lf<\n", work);
		count++;
		subtract *= ten;
	}
	subtract /= ten;
	printf("work = >%lf<\n", work);
	printf("count = >%lf<\n", count);
	printf("subtract = >%lf<\n", subtract);


	n = work;
	c = n + '0';
	printf("c = >%c<\n", c);

	subtract *= n;
	printf("subtract = >%lf<\n", subtract);
	f = integral - subtract;
	printf("new f = %lf\n", f);

	if (ibuf < BUF_SZ)
		buf[ibuf++] = c;
	printf("buf = >%s<\n", buf);
	i--;
}
printf("ORIGINAL : >%lf<\n", FLT_MAX);
printf("FINAL : buf = >%s<\n", buf);

return 0;
}
