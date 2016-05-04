#include<iostream>
#include<ctime>
using namespace std;
#define PI 3.1415926
//
//int main()
//{
//	double area(int radius);
//	cout << area(2) << endl;
//	return 0;	
//}
//
//double area(int radius)
//{
//	return PI * radius * radius;
// } 
//
//int main()
//{
//	enum Weather {
//		Sunny,
//		Cloudy,
//		Rainy
//	} weather;
//	weather = Cloudy;
//	cout << weather << endl;
//	
//	void showTime();
//	showTime();
//	
//	return 0;
//}
//
//void showTime()
//{
//	long lct;
//	lct = time(0);
//	cout << lct << endl;
//}
//
//int main()
//{
//	int fact(int n1);
//	cout << fact(8) << endl;
//	return 0;	
//}
//
//int fact(int n1)
//{
//	int f1=0;
//	if(n1 > 1)
//		f1 = fact(n1-1) * n1;
//	else
//		f1 = 1;
//	return f1;
//}
//
//void swap(int &p1, int &p2)
//{
//	int p;
//	p=p1;
//	p1=p2;
//	p2=p;
//}
//int main()
//{
//	int a,b;
//	cin >> a >> b;
//	swap(a,b);
//	cout << a << " " << b << endl;
//	return 0;
//}
//
//int main()
//{
//	int a;
//	const int &ra = a;
////	ra = 1;
//	a = 1;
//	return 0;
//}
//
//int &put(int n);
//int vals[10];
//int error = -1;
//int main()
//{
//	put(0) = 10;
//	put(9) = 20;
//	cout << vals[0];
//	cout << vals[9];
//	return 0;
//}
//
//int &put(int n)
//{
//	if(n >=0 && n <= 9)
//		return vals[n];
//	else {
//		cout << "subscript error" << endl;
//		return error;
//	}
//}

//float *p1 = new float;
//float *p2 = new float[10];
//
//delete p1;
//delete [] p2;

int main()
{
	int num, i;
	int *p;
	cin >> num;
	p = new int[num];
	for(i=0;i<num;i++)
		cin >> p[i];
	
	for(i=0;i<num;i++)
		cout << p[i] << endl;
	delete [] p;
}
