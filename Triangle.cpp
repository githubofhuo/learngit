#include<iostream>
using namespace std;

class Triangle {
public:
	Triangle(int n) : num(n) {
		cout << "构造函数调用, num=" << num << endl;
	}
	~Triangle() {
		cout << "析构函数调用, num=" << num << endl;
	}
	void set_sides(double a, double b, double c)
	{
		if (a <= 0 || b <= 0 || c <= 0)
			throw "边长必须为正";
		if (a + b <= c || b + c <= a || c + a <= b)
			throw "边长不满足三角不等式";
		s1 = a;
		s2 = b;
		s3 = c;
		cout << "三角形" << num << "三边设置完毕" << endl;
	}
private:
	int num;
	double s1;
	double s2;
	double s3;
};

void test()
{
	Triangle tri1(1);
	Triangle tri2(2);
	tri1.set_sides(3, 4, 5);
	tri2.set_sides(1, 4, 5);
}
//
//int main()
//{
//	cout << "main start" << endl;
//	cout << "call test" << endl;
//	try {
//		test();
//	}
//	catch (char * c) {
//		cout << "异常 : " << c << endl;
//	}
//	cout << "main end" << endl;
//
//	return 0;
//}