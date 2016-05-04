#include<iostream>
#include<cmath>
using namespace std;

class Point
{
	public:
		//计算两点间距离
		double distance(Point &p) {		//引用形参 
			return sqrt( (p.x - x) * (p.x - x) + (p.y - y) * (p.y - y));
		}
		void setX(double i){
			x=i;
		}
		void setY(double j){
			y=j;
		}
	private:
		double x;
		double y;  
};

int main()
{
	Point p1, p2;
	p1.setX(2); p1.setY(2);
	p2.setX(5); p2.setY(6);
	cout << p1.distance(p2) << endl;
	return 0;
}
