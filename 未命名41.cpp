#include<iostream>
#include<cstring>
#include<iterator>
#include<algorithm>
#include<vector>
using namespace std;

void print(const int *);
void print(const int []);
void print(const int [10]);

void print(const char *cp)
{
	if(cp)
		while(*cp)
			cout << *cp++;
}

void print(const int *beg, const int *end)
{
	//输出beg到end之间（不含end）的所有函数
	while(beg != end)
		cout << *beg++ << endl; 
}
int main()
{
	vector<string> *n = "name";
//	const char *beg = (char *)n;
//	const char *end = (char *)(n+sizeof(n));
	print(begin(n), end(n));
	return 0;
}
