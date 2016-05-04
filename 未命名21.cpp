#include<iostream>
#include<vector>
using std::string;
using std::vector;
int main()
{
	vector<int> v2;
	for(int i=0;i != 100;i++)
		v2.push_back(i);
	std::cout << v2.empty() << std::endl;
	return 0;
} 
