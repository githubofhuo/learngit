#include<iostream>
using namespace std;
class Point
{
	private:
		double x, y;
	public:
		Point(double a = 0.0, double b = 0.0);
		void disp();
};
Point::Point(double a, double b)
{
	x=a;
	y=b;
}
void Point::disp()
{
	cout << x << ", " << y << endl;
}

int main()
{
	Point p1(1.0, 2.0), p2(3, 0), p3;
	cout << "p1 = ";
	p1.disp();
	cout << "p2 = ";
	p2.disp();
	cout << "p3 = ";
	p3.disp();
	return 0;
}
