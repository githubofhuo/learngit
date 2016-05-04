#include<iostream>
#include<cstring>
using namespace std;

class Increase {
	private:
		int value;
	public:
		Increase(int v = 0) {
			value = v;
		}
		void show() {
			cout << value << endl;
		}
		Increase& operator ++ ();		//重载前置 
		Increase operator ++ (int);		//重载后置 
};
Increase& Increase::operator ++ () {
	++value;
	return *this;
}
Increase Increase::operator ++ (int) {
	Increase temp;
	temp.value = value++;
	temp.show();
	return temp;
}
int main()
{
	Increase obj1, obj2;
//	cout << (++obj1).value<< " " << (obj2++).value;
//	(++++++++++obj1).show();
//	Increase obj3(obj2++);
//	obj3.show();
//	Increase obj3 = ++obj1;
//	obj3.show();
//	Increase obj4 = ++obj1;
//	obj4.show();
	
	Increase obj3 = obj2++++;
	return 0;
}
