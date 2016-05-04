/*
	Point(x,y),  line: ax+by+c=0
	distance: d = abs(a*x+b*y+c) / sqrt(a*a+b*b)
*/
#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
class Line;			//Line������
//����ʵ�� 
class Point {
	private:
		double x, y;
	public:
		Point(double x = 0.0, double y = 0.0);
		void disp();
		friend double distance(Point p1, Point p2);
//		friend double distance(Point p, Line l);		//����ΪPoint����Ԫ 
		friend class ComputeTools;		//����ΪPoint��Ԫ�� 
};
Point::Point(double x, double y)
{
	this->x = x;
	this->y = y;
}
void Point::disp()
{
	cout << "��(" << x << "," << y << ")";
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
//		friend double distance(Point p, Line l);		//����ΪLine����Ԫ
		friend class ComputeTools;		//����Ϊ��Ԫ�� 
};
Line::Line(double a, double b, double c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}
void Line::disp()
{
	cout << "��: " << a << "x+" << b << "y+" << c << "=0";
}
//double distance(Point p, Line l)
//{
//	return fabs(l.a * p.x + l.b * p.y + l.c) / sqrt(l.a * l.a + l.b * l.b);
//}

class ComputeTools {
	public:
		//���ص������뺯��
		static double distance(Point p1, Point p2);
		//���ص���ֱ�߾��뺯��
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
	cout << "����Ϊ:" << ComputeTools::distance(p1, p2) << endl;
	p1.disp();
	l1.disp();
	cout << "����Ϊ:" << ComputeTools::distance(p1, l1) << endl;
	return 0;
}
