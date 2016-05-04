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
	if(month<1 || month>12)
		return -1;
	if(day<1 || day > daytab[year][month])
		return -1; 
	for (i = 1; i < month; i++)
		day += daytab[leap][i];
	return day;
}

/*month_day: ��ĳ���еڼ�������ڱ�ʾ��ʽת��Ϊĳ��ĳ�յı�ʾ��ʽ*/
void month_day(int year, int yearday, int *pmonth, int *pday)
{
	int i, leap;
	if(year<1) {
		*pmonth=-1;
		*pday=-1;
		return;
	}
	leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
	for (i = 0; yearday > daytab[leap][i]; i++)
		yearday -= daytab[leap][i];
	if(i>12 && yearday > daytab[leap][12]) {
		*pmonth=-1;
		*pday=-1;
	} else {
		*pmonth = i;
		*pday = yearday;	
	}
}

/*month_name: ���ص�n���·ݵ�����*/
char *month_name(int n)
{
	static char *name[] = {
		"Illegal month",
		"January",
		"February",
		"March",
		"April",
		"May",
		"June",
		"July",
		"August",
		"September",
		"October",
		"November",
		"December"
	};
	
	return (n<1 || n>12)? name[0]: name[n];
} 
 
 
int main()
{
	printf("%s", month_name(4));
	return 0;
//	//printf("%d", day_of_year(1988, 4, 4));
//	int pmonth;
//	int pday;
//	month_day(1988,95,&pmonth,&pday);
//	printf("%d\t%d",pmonth,pday);
//	return 0;
}

