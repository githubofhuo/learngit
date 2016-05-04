#include<iostream>
using std::string;
using std::cout;
using std::endl;

int main()
{
	string s("some string");
	if(s.begin() != s.end()) {
		auto it = s.begin();
		*it = toupper(*it);
	}
	cout << s << endl;
	return 0;
}
