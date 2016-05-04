#include<iostream>
#include<string>
#include<initializer_list>
#include<vector>
using namespace std;
using std::string;
using std::vector;
vector<string> ErrCode;
void error_msg(ErrCode e, initializer_list<string> il)
{
	cout << e.msg() << ": ";
	for(const auto &elem : il)
		cout << elem << " ";
	cout << endl;
}

int main()
{
	string expected, actual;
	initializer_list<string> il;
	if(expected != actual)
		error_msg(ErrCode(42), {"functionX", expected, actual});
	else
		error_msg(ErrCode(0), {"functionX", "okay"});
	return 0;
}
