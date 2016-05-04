#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	constexpr int mf = 20;
	constexpr int limit = mf + 1;
	cout << mf << " " << limit;
	const int *p = nullptr;
	constexpr int *q = nullptr;
	return 0;
} 
