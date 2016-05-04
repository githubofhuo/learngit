#include<iostream>
#include<math.h>
using namespace std;

class Line;
class Point {
	private:
		double x,y;
	public:
		Point(double x=0.0, double y=0.0);
		void disp();
		friend double distance(Point p, Line l);
};
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Point::disp()
{
	cout << "µã(" << x << "," << y << ")" << endl; 
}

class Line {
	private:
		double a, b, c;
	public:
		Line(double a=0.0, double b=0.0, double c=0.0);
		void disp();
		friend double distance(Point p, Line l);
};
Line::Line(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
void Line::disp()
{
	cout << "line: " << a << "x+" << b << "y+" << c << "=0" << endl;
}
double distance(Point p, Line l)
{
	return fabs(l.a*p.x+l.b*p.y+l.c) / sqrt(l.a*l.a + l.b*l.b);
}

int main()
{
	Point p1(1.0, 2.0);
	Line l1(3.0, 4.0, 5.0);
	p1.disp();
	l1.disp();
	cout << "distance is " << distance(p1, l1) << endl;
	
	return 0;
}
