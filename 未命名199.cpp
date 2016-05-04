#include<iostream>
#include<cstdlib>
int main()
{
//	int ival = 1024;
//	int &refval = ival;
//	refval = 2;
//	int i1 = refval;
//	std::cout << ival << " "  << i1 << std::endl;
	
	int ival = 42;
	int *p = &ival;
	std::cout << *p << std::endl;
	
	int *p1 = nullptr;
	
	return 0;
}
