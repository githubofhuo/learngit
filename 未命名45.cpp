#include<iostream>
#include<cstddef>
#include<vector>
#include<string>
using namespace std;
using std::vector;
int main()
{
//	int ia[] = {0,1,2,3,-8,4,5,6,7,8,9};
//	int *beg = begin(ia);
//	int *last = end(ia);
//	while(beg != last && *beg >= 0)
//		++beg;
//	cout << *beg << endl;
	
	string s("Hello World!");
	const char *str = s.c_str();
	for(auto &c : s)
		cout << c;
	cout << endl;

}
