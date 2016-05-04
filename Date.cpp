#include <iostream>
using namespace std;
int dd[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };

class Date
{
public:
	Date(int y = 2000, int m = 1, int d = 1) throw(out_of_range);
	void init(int y, int m, int d) throw(out_of_range);
	void show();
	int isleapYear(int y);
private:
	int month;
	int day;
	int year;
};

Date::Date(int y, int m, int d) throw(out_of_range)
{
	init(y, m, d);
}

void Date::init(int y, int m, int d) throw(out_of_range)
{
	if(y>5000 || y<1 || m<1 || m>12 || d<1 || d>dd[m-1])
	{
		throw out_of_range("设置的日期有误");
	} else if(!isleapYear(y) && d == 29)
	{
		throw out_of_range("设置日期有误");
	} else
	{
		year = y;
		month = m;
		day = d;
	}
}

void Date::show()
{
	cout << month << '/' << day << '/' << year << endl;
}

int Date::isleapYear(int y)
{
	return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int main()
{
	try
	{
		Date d1(2003, 12, 6);
		d1.show();
		Date d2(2011, 2, 29);
		d2.show();
	} catch(out_of_range ex)
	{
		cout << ex.what() << endl;
	}
	return 0;
}