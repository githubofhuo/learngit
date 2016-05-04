#include<stdio.h>
static char daytab[2][13] = {
	{0,31,28,31,30,31,30,31,31,30,31,30,31},
	{0,31,29,31,30,31,30,31,31,30,31,30,31}
};

/*day_of_year: ��ĳ��ĳ�յ�������ʾ��ʽת��Ϊĳ���е�ĳ��ı�ʾ��ʽ*/
int day_of_year(int year, int month, int day)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/*month_day: ��ĳ���еڼ�������ڱ�ʾ��ʽת��Ϊĳ��ĳ�յı�ʾ��ʽ*/
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 0; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	*pmonth = i;
	*pday = yearday;
}

/*day_of_year1: set day of year from month & day; pointer version*/
int day_of_year1(int year, int month, int day)
{
	int leap;
	char *p;

	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	p = daytab[leap];
	while (--month)
		day += *++p;
	return day;
}

void month_day1(int year, int yearday, int *pmonth, int *pday)
{
	int leap;
	char *p;
	
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	p = daytab[leap];
	while (yearday > *++p)
		yearday -= *p;
	*pmonth = p - *(daytab + leap);
	*pday = yearday;
}


int main()
{
	int month;
	int day;
	month_day1(1988,95,&month,&day);
	printf("%d\t%d", month,day);
	return 0;
}
