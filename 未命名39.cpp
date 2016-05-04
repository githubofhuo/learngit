#include<iostream>
#include<math.h>

using namespace std;
class Point {
	private:
		double x, y;		//x, y坐标
	public:
		Point(double x=0.0, double y=0.0);
		void disp();		//输出私有变量的成员函数 
		friend double distance(Point p1, Point p2);		//声明为Point的友元 
};
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
} 
void Point::disp()
{
	cout << "点(" << x << "," << y << ")" << endl; 
}
//距离函数
double distance(Point p1, Point p2)
{
	return sqrt((p1.x-p2.x) * (p1.x-p2.x) + (p1.y-p2.y) * (p1.y-p2.y));
} 
 
int main()
{
	Point p1(1.0, 2.0);
	Point p2(3.0, 4.0);
	p1.disp();
	p2.disp();
	
	cout << "距离是：" << distance(p1, p2) << endl;
	
	return 0;
} 
