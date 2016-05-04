#include<iostream>
#include<vector>
using std::string;
using std::vector;
int main()
{
	vector<int> v;
	for(int i=0;i < 10;i++)
		v.push_back(i);
	for(auto &i : v)
		i *= i;
	for(auto i: v)
		std::cout << i << " " << endl;
	return 0;
}
