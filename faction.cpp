#include<iostream>
#include<cmath> 
using namespace std;

int main()
{
	double a = 0;
	double b = 0;
	double c = 0;
	try {
		cout << "Input a,b,c: " << endl;
		cin >> a >> b >> c;
		double delta  = b * b - 4 * a * c;
		if(delta < 0) 
			throw delta;
		if(delta == 0)
			cout << "������Ψһ��" << (-b/2/a) << endl;
		else {
			cout << "������������" << endl;
			cout << ((-b + sqrt(delta))/(2*a)) << " " << ((-b - sqrt(delta))/(2*a)) << endl;
		}
	} catch(double d) {
		cout << "delta=" << d << ",������ʵ��" << endl;
	}
	return 0;
}
