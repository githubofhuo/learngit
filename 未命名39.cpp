#include<iostream>
#include<math.h>

using namespace std;
class Point {
	private:
		double x, y;		//x, y����
	public:
		Point(double x=0.0, double y=0.0);
		void disp();		//���˽�б����ĳ�Ա���� 
		friend double distance(Point p1, Point p2);		//����ΪPoint����Ԫ 
};
Point::Point(double x, double y) {
	this->x = x;
	this->y = y;
} 
void Point::disp()
{
	cout << "��(" << x << "," << y << ")" << endl; 
}
//���뺯��
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
	
	cout << "�����ǣ�" << distance(p1, p2) << endl;
	
	return 0;
} 
