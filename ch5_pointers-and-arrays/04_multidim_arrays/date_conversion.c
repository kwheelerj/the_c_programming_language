#include <stdio.h>

static char daytab[2][13] = 
{
	{ 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
	{ 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }
};

/* day_of_year: set day of the year from month and day */
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/* month_day: set month and day, from day of the year */
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	for (i = 1; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

int main()
{
	int yearday;
	int pm;
	int pd;

	yearday = day_of_year(1975, 1, 1);
	printf("%d\n", yearday);
	month_day(1975, yearday, &pm, &pd);
	printf("month = %d , day = %d\n", pm, pd);

	yearday = day_of_year(2000, 11, 31);
	printf("%d\n", yearday);
	month_day(2000, yearday, &pm, &pd);
	printf("month = %d , day = %d\n", pm, pd);


return 0;
}
