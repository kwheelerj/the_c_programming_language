#include <stdio.h>
#include <float.h>
#include <math.h>
#include <string.h>

#define BUF_SZ 500

int main()
{
	printf("Max float value = %f\n", FLT_MAX);
	
	float f = FLT_MAX;
	
	float integral;
	float fraction;
	int n;
	char c;
	char buf[BUF_SZ];
	memset(buf, '\0', BUF_SZ);
	int ibuf = 0;
	int count = 0;
	float work;
	float ten = 10.0f;

//int i = 2;
//while (i > 0)
while (f > 0)
{
	printf("======================\n");
	printf("top f = %f\n", f);
	integral = truncf(f);
	fraction = f - integral;

	printf("integral = >%f<\n", integral);
	printf("fraction = >%f<\n", fraction);

	work = integral;
	float subtract = 1.0f;
	while (work > ten)
	{
		work /= ten;
		printf("\t_work = >%f<\n", work);
		count++;
		subtract *= ten;
	}
	subtract /= ten;
	printf("work = >%f<\n", work);
	printf("count = >%f<\n", count);
	printf("subtract = >%f<\n", subtract);


	n = work;
	c = n + '0';
	printf("c = >%c<\n", c);

	subtract *= n;
	printf("subtract = >%f<\n", subtract);
	f = integral - subtract;
	printf("new f = %f\n", f);

	if (ibuf < BUF_SZ)
		buf[ibuf++] = c;
	printf("buf = >%s<\n", buf);
//	i--;
}
printf("ORIGINAL : >%f<\n", FLT_MAX);
printf("FINAL : buf = >%s<\n", buf);

return 0;
}
