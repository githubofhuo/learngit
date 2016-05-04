#include<iostream>
#include<istream>
#include<ostream>
using namespace std;

int main()
{
	int c;
	while((c = cin.get()) != EOF)
		cout.put(c);	
	return 0;
} 
