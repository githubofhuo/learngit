#include<stdio.h>
enum weekday
{
	sun,mon,tue,wed,thu,fri,sat
};
enum weekday week1,week2,week3;

int main()
{
	enum weekday enumweek[3];
	enumweek[0] = sun;
	enumweek[1] = mon;
	enumweek[2] = tue;
	printf("%d %d %d \n",enumweek[0],enumweek[1],enumweek[2]);
	return 0;
}
