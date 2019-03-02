#include <stdio.h>

int main()
{
	double d;
	int i;

	d = 2.4;
	i = (int)d;
       	printf("d=>%f<\n", d);	
	printf("i=>%d<\n\n",i);

       	printf("d=>%f<; i=>%d<\n\n", d, i);	

       	printf("i=>%f< , i=>%d<\n", i ,i);	
       	printf("d=>%f<; i=>%f<\n\n", d, i);	

       	printf("d=>%f<; i=>%f< , i=>%d<\n\n", d, i, i);	
	printf("i=>%d<\n",i);

	d = 2.5;
	i = (int)d;
       	printf("d=>%f<\n", d);	
	printf("i=>%d<\n\n",i);

	d = 2.6;
	i = (int)d;
       	printf("d=>%f<\n", d);	
	printf("i=>%d<\n\n",i);


return(0);
}
