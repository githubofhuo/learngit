/*
	Point(x,y),  line: ax+by+c=0
	distance: d = abs(a*x+b*y+c) / sqrt(a*a+b*b)
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Line;			//Line类声明
//点类实现 
class Point {
	private:
		double x, y;
	public:
		Point(double x = 0.0, double y = 0.0);
		void disp();
		friend double distance(Point p1, Point p2);
//		friend double distance(Point p, Line l);		//声明为Point的友元 
		friend class ComputeTools;		//声明为Point友元类 
};
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Point::disp()
{
	cout << "点(" << x << "," << y << ")";
}
//double distance(Point p1, Point p2)
//{
//	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
//}

class Line {
	private:
		double a, b, c;
	public:
		Line(double a = 0.0, double b = 0.0, double c = 0.0);
		void disp();
//		friend double distance(Point p, Line l);		//声明为Line的友元
		friend class ComputeTools;		//声明为友元类 
};
Line::Line(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
void Line::disp()
{
	cout << "线: " << a << "x+" << b << "y+" << c << "=0";
}
//double distance(Point p, Line l)
//{
//	return fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
//}

class ComputeTools {
	public:
		//重载点与点距离函数
		static double distance(Point p1, Point p2);
		//重载点与直线距离函数
		static double distance(Point p, Line l); 
};
double ComputeTools::distance(Point p1, Point p2)
{
	return sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
}
double ComputeTools::distance(Point p, Line l)
{
	return fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
}
int main()
{
	Point p1(1.0, 2.0);
	Point p2(3.0, 4.0);
	Line l1(3.0, 4.0, 5.0);
	p1.disp();
	p2.disp();
	cout << "距离为:" << ComputeTools::distance(p1, p2) << endl;
	p1.disp();
	l1.disp();
	cout << "距离为:" << ComputeTools::distance(p1, l1) << endl;
	return 0;
}
