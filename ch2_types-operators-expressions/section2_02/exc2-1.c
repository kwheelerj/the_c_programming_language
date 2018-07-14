#include <stdio.h>
#include <limits.h>

int main()
{
	unsigned char uc;
	unsigned short usi;
	unsigned int ui;
	unsigned long uli;
	signed char c;
	signed short si;
	signed int i;
	signed long li;

	uc = 0;
	for (;;)
		if (++uc == 0)
			break;	
	printf("Max value of unsigned char is: %d\n", --uc);

	usi = 0;
	for (;;)
		if (++usi == 0)
			break;	
	printf("Max value of unsigned short (int) is: %d\n", --usi);

	ui = 0;
	for (;;ui++)
		if (ui+1 == 0)
			break;	

	unsigned int max_int;
	max_int = 4294967295U;

	printf("Max value of unsigned int is: %u\n", ui);
	printf("Actually is: %u\n", max_int);
	printf("Actually is: %u\n", max_int + 1);
	printf("%u\n",UINT_MAX);

	uli = 0;
	for (;;uli++)
		if (uli+1 == 0)
			break;	
	printf("Max value of unsigned long (int) is: %ld\n", uli);

	c = 0;
	for (;;)
		if (++c == 0)
			break;	
	printf("Max value of (signed) char is: %d\n", --c);

	si = 0;
	for (;;)
		if (++si == 0)
			break;	
	printf("Max value of (signed) short (int) is: %d\n", --si);

	i = 0;
	for (;;)
		if (++i == 0)
			break;	
	printf("Max value of (signed) int is: %d\n", --i);

	li = 0;
	for (;;)
		if (++li == 0)
			break;	
	printf("Max value of (signed) long (int) is: %d\n", --li);

	return 0;
}
