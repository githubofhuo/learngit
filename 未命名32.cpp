#include<iostream>
#include<cstring>
using namespace std;
//Point��
class Point {
	private:
		double x, y;
		char *name;
	public:
		//�������캯��������������������ͬ 
		Point(char *n=NULL, double a=0.0, double b=0.0);
		Point(Point &p);
		~Point();
		void disp();		//���˽�б����ĳ�Ա���� 
};
 
Point::Point(char *n, double a, double b)
{
	x=a; y=b;
	if(n) {
		name =  new char[strlen(n)+1];
		strcpy(name, n);
	} else {
		name = new char[8];
		strcpy(name, "no name");
	}
	cout << name << " constructing" << endl;
}
Point::Point(Point &p)
{
	x = p.x; y = p.y;
	if(p.name) {
		name = new char[strlen(p.name)+1];
		strcpy(name, p.name);
	} else {
		name = new char[8];
		strcpy(name, "no name");
	}
	cout << name << " copy constructing" << endl;
}

Point::~Point()
{
	cout << name << " destructing" << endl;
	delete [] name;
}

void Point::disp()
{
	cout << name << ":" << x << "," << y <<endl;
}

//���Ժ��� 
Point test()
{
	Point p("home", 1.0, 2.0);
	return p;
}

int main()
{
	Point p1 = test();
	
	return 0;
}
