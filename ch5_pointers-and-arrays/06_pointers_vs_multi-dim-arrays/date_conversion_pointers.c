#include <stdio.h>

//static char daytab[2][13] = 
static char daytab[][13] = 
{
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

int day_of_year(int year, int month, int day)
{
	int leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (day > *(daytab[leap] + month))
	{
		printf("ERROR - invalid date given: [ m%02d/d%02d/%d ]\n", month, day, year);
		return -1;
	}
//	for (i = 1; i < month; i++)
	while (month > 0 )
		day += *(daytab[leap] + --month);
	return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	*pmonth = 1;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	if (leap && yearday > 366 || yearday > 365)
	{
		printf("ERROR - invalid yearday given: [ %d ]\n", yearday);
		return;
	}
//	for (i = 1; yearday > daytab[leap][i]; i++)
	char *p;
	p = daytab[leap];
	while ( yearday > *(++p) )
		yearday -= *p, ++*pmonth;
	*pday = yearday;
}

int main()
{
	int yearday;
	int pm;
	int pd;

	//printf("%d\n", *(daytab[0]+2));	// prints '28'
	//printf("%d\n", *(daytab[1]+2));	// prints '29'
	yearday = day_of_year(1975, 8, 14);
	printf("%d\n", yearday);
	month_day(1975, yearday, &pm, &pd);
	printf("month = %d , day = %d\n", pm, pd);

return 0;
}
