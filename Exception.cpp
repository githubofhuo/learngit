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
		cout << "����������ʵ��a,b:" << endl;
		cin >> a >> b;
		cout << "a/b = " << divide(a,b)<< endl; 
	} catch(double) {
		cout << "��������Ϊ0" << endl; 
	}
	
	cout << "���" << endl;
	return 0;
} 
