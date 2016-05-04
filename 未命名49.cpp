#include<iostream>
#include<cstdlib>
using namespace std;

int odd[] = {1,3,5,7,9};
int even[] = {0,2,4,6,8};
decltype(odd) &arrPtr(int i)
{
	return (i % 2) ? odd : even;
}

int main()
{
//	typedef int arrT[10];
//	using arrT = int[10];
//	arrt* func(int i)
	auto &au = arrPtr(1);
	cout <<	sizeof(au) << endl;
//	for(auto beg = au.begin(); beg != au.end(); ++beg)
//		cout << *beg << endl;
	for(int index=0; index<sizeof(au)/sizeof(int); ++index)
		cout << au[index] << endl;
	return 0;
}
