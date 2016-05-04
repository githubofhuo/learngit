#include<iostream>
#include<cstring>
using namespace std;

class Box {
	private:
		double length;
		double width;
		double height;
	public:
		Box(double l = 1.0, double w = 1.0, double h = 1.0) :
			length(l), width(w), height(h) 	{}
		double volume () const {
			return length * width * height;		//计算盒子体积 
		}
		bool operator < (const Box & b) const {
			return volume() < b.volume();
		}
		Box& operator = (const Box &b);
};
Box& Box::operator = (const Box &b)
{
	length = b.length;
	width = b.width;
	height = b.height;
	return *this;
}
int main()
{
	Box box1(1,3,4);
	Box box2(2,2,2);
	Box box4, box3;
	box4 = box3 = box1;
	if(box2 < box1) 
		cout << "Box1 is less than Box2" << endl;
	return 0;
}
