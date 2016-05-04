#include<iostream>
#include<cstring>
using namespace std;

class Circle {
	private:
		double x,y;			//圆心坐标 
		double radius;		//半径 
		const double pi;	//π 
	public:
		//常数据成员必须在构造函数初始化列表中初始化
		Circle(double x, double y, double radius, double pi):pi(pi) {
			this->x = x;
			this->y = y;
			this->radius = radius;
		} 
		double getRadius() {
			return radius;
		}
		double area() const {
			return pi * radius * radius;
		}
		double setRadius(double radius) {
			this->radius = radius;
			return radius;
		}
//		double area() {
//			return pi * radius * radius;
//		}
	
		void f(const Circle &r) {
//			cout << r.setRadius(10);
			cout << r.area();
		}
};

int main()
{
	Circle c1(1.2, 3.4, 4, 3.14);
	Circle *p = &c1;
//	c1.setRadius(10), c1.area()
	
//	c1.getRadius();
	f(c1);
	cout << c1.area() <<endl;
	return 0;
}
