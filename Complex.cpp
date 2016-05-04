#include<iostream>
#include<cstring>
#include<cmath>

using namespace std;
class Complex {
	private:
		double dReal;
		double dImag;
	public:
		Complex(double r = 0.0, double i = 0.0) {
			dReal = r;
			dImag = i;
		}
		Complex operator + (const Complex &c2) {
			Complex c(0, 0);
			c.dReal = dReal + c2.dReal;
			c.dImag = dImag + c2.dImag;
			return c;
		}
//		Complex operator - (const Complex &c2);
//		Complex operator - () {
//			return Complex(-dReal, -dImag);
//		}
		friend Complex operator - (const Complex &c1, const Complex &c2);
		friend Complex operator - (const Complex &c);		
		friend Complex operator + (double d, const Complex &c);
		
		void print() const {
			if(dImag > 0)
				cout << dReal << "+" << dImag << "i";	
			else if(dImag < 0)
				cout << dReal << "-" << -dImag << "i";
			else
				cout << dReal;
			
			cout << endl;
		}
}; 

Complex operator - (const Complex &c1, const Complex &c2) {
	return Complex(c1.dReal - c2.dImag, c1.dImag - c2.dImag);
}

Complex operator - (const Complex &c) {
	return Complex(-c.dReal, -c.dImag);
}

Complex operator + (double d, const Complex &c)
{
	return Complex(d+c.dReal, c.dImag);
}

//Complex Complex::operator - (const Complex &c2)
//{
//	return Complex(dReal - c2.dReal, dImag - c2.dImag);
//}

int main()
{
	Complex c0;
	Complex c1(1,2); 
	Complex c2(4,5);
	Complex c3 = c1 + c2;
	Complex c4 = c1 - c2;
	Complex c5 = 0 + 5.5;
	c3.print();
	c4.print();
	(-c1).print();
	c5.print();
	return 0;
}
