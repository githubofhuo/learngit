#include<iostream>
using namespace std;

double divide(double a, double b)
{
	if(b==0)
		throw b;
	return a/b;
}

int main()
{
	double a = 0;
	double b = 0;
	try {
		cout << "请输入两个实数a,b:" << endl;
		cin >> a >> b;
		cout << "a/b = " << divide(a,b)<< endl; 
	} catch(double) {
		cout << "除数不能为0" << endl; 
	}
	
	cout << "完毕" << endl;
	return 0;
} 
