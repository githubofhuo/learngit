#include<iostream>
#include<cstring>
using namespace std;
class Point
{
	private:
		double x, y;
		char *name;
		int flag;		//���ֹ������Ϳ���������� 
	public:
		//�������캯��
		Point(char *n = NULL, double a=0.0, double b=0.0);
		//�������� 
		Point(Point &p);
		//�������� 
		~Point();
		void disp();	//���˽�б����ĳ�Ա���� 
};

Point::Point(char *n, double a, double b)
{
	x=a; y=b;
	flag = 1;	//flagΪ1ʱ���������ɶ��� 
	if(n) {
		name = new char[strlen(n)+1];
		strcpy(name, n);
	} else {
		name = new char[8];
		strcpy(name, "no name");
	}
	cout << name << " constructing" << endl;
}

//���쿽������ 
Point::Point(Point &p)
{
	x=p.x; y=p.y;
	name = p.name;
	flag = 0; 	//flagΪ0ʱ�������������ƶ��� 
//	if(p.name) {
//		name = new char[strlen(p.name)+1];
//		strcpy(name, p.name);
//	} else {
//		name = new char[8];
//		strcpy(name, "no name");
//	}

//	name = new char[strlen(p.name)+1];
//	strcpy(name, p.name);

	cout << name << " copy constructing" << endl;
}

Point::~Point() {
	cout << name << " destructing" << endl;
	if(flag)
		delete [] name;
}

void Point::disp() {
	cout << name << ": " << x << ", " << y << endl;
}
int main()
{
	//�������
	Point p1("name", 1.0, 2.0);
	Point p2("school", 3.0);
	Point p3;
	Point p4(p1);
	
	//�������
	cout << "p1 =";
	p1.disp();
	cout << "p2 =";
	p2.disp();
	cout << "p3 =";
	p3.disp();
	cout << "p4 =";
	p4.disp();
	
	return 0;
}
