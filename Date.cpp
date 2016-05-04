#include<iostream>
#include<cstring>
using namespace std;

class Date {
	public:
		Date(int m = 1, int d = 1, int y = 1900);	//构造函数
		Date &operator ++ ();						//重载前置++
		Date &operator ++ (int);						//重载后置++
		bool leapYear(int);							//闰年 
		bool endOfMonth(int);						//是否是月末
		void print() const;
		void helpIncreament();						//日期合理增加一
	private:
		int month;
		int day;
		int year;
		static const int days[]; 					//每月的天数
};

const int Date::days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};	//每月天数
Date::Date(int m, int d, int y) {
	//设置年月合理值 
	month = (m >= 1 && m <= 12)? m : 1;
	year = (y >= 1900 && y <= 2100)? y : 1900; 
	//设置日期合理值
	if(month == 2 && leapYear(year))
		day = (d >= 1 && d <= 29)? d : 1;
	else
		day = (d >= 1 && d <= days[month])? d : 1; 
}

bool Date::leapYear(int y)
{
	if(y % 400 == 0 || (y % 100 != 0 && y % 4 == 0))
		return true;
	else
		return false;
}

/*重载自增运算符*/
Date &Date::operator ++ () {
	helpIncreament();		//日期合理增加一
	return *this; 
}
Date &Date::operator ++(int) {
	Date temp = *this;
	helpIncreament();		//按值返回历史对象 
	return temp;
}

bool Date::endOfMonth(int d)
{
	if(month == 2 && leapYear(year))
		return d == 29;
	else
		return d == days[month];
}

void Date::helpIncreament()
{
	if(endOfMonth(day) && month == 12) {
		day = 1;
		month = 1;
		++year;
	}
	else if(endOfMonth(day)) {
		day = 1;
		++month;
	}
	else
		++day;
}

void Date::print() const {
	char * monthName[13] = {
		" ",
		"Jan",
		"Feb",
		"Mar",
		"Apr",
		"May",
		"June",
		"July",
		"Aug",
		"Sep",
		"Oct",
		"Nov",
		"Dec"
	};
	cout << monthName[month] << " " << day << " " << year << endl;
}
int main()
{
	Date d0, d1(12, 31, 2011);
//	测试前置自增运算符
	d0 = ++d1;
	cout << "d0 = ++d1 \n";
	cout << "d0: ";
	d0.print();
	cout << "d1: ";
	d1.print();
//	测试后置自增运算符
	Date d2(2, 28, 2012);
	d0 = d2++;
	cout << "d0 = d2++ \n";
	cout << "d0: ";
	d0.print();
	cout << "d2: ";
	d2.print(); 
	system("pause");
//	system("error");
	return 0;
}
