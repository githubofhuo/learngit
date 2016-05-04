#include <iostream>
using namespace std;
/*数组越界类*/
class ArrayIndexOutOfBounds
{
public:
	ArrayIndexOutOfBounds(int index) : index(index) {}
	void show() const
	{
		cout << "数组下标越界访问异常,index = " << index << endl;
	}
private:
	int index;
};

/*数组类*/
class MyArray
{
private:
	int *p;
	int sz;
public:
	MyArray(int s) : sz(s)
	{
		p = new int[sz];
	}
	~MyArray()
	{
		delete[] p;
	}
	int size() const
	{
		return sz;
	}
	int& operator[] (int i) const
	{
		if (i < 0 || i >= sz)
			throw ArrayIndexOutOfBounds(i);
		return p[i];
	}
};
//
//int main()
//{
//	MyArray a(10);
//	for (int i = 0; i < 3; i++)
//	{
//		try
//		{
//			if (i != 1)
//			{
//				a[i] = i;
//				cout << "a[" << i << "] = " << a[i] << endl;
//			}
//			else
//				a[a.size() + 10] = 10;
//		}
//		catch (ArrayIndexOutOfBounds& a)
//		{
//			a.show();
//		}
//	}
//	return 0;
//}