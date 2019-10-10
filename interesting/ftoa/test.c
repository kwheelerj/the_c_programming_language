#include <stdio.h>
#include <float.h>
#include <limits.h>


int main()
{
	float f = FLT_MAX;
	if (f> LONG_MAX)
	{
		printf("okay\n");
	}
	else
	{
		printf("nope\n");
	}

return 0;
}
