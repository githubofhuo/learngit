#include<iostream>
#include<cstring>
#include<initializer_list>
#include<vector>
using namespace std;
using std::vector;

vector<string> process()
{
	string expected, actual;
	if(expected.empty())
		return {};		//返回空的vector对象
	else if(expected == actual)
		return {"functionX", "okay"};		//返回列表初始化的vector对象 
	else 
		return {"functionX", expected, actual}; 
}

int iCount(initializer_list<int> il)
{
	int count = 0;
	for(auto val : il)
		count += val;
	return count;
}

char &get_val(string &str, string::size_type ix)
{
	return str[ix];
}

const string &make_plural(size_t ctr, const string &word, const string &ending);
const string &shorterString(const string &s1, const string &s2);

int main()
{
//	cout << "1,6,9: " << iCount({1,6,9}) << endl;
// 	string s1 = "Python";
// 	string s2 = "Hello";
// 	auto sz = shorterString(s1, s2).size();
//	cout << sz << endl;
	string s("a value");
	cout << s << endl;
	get_val(s, 0) = 'A';
	cout << s << endl;
	return 0;
}

bool str_subrange(const string &str1, const string &str2)
{
	if(str1.size() == str2.size())
		return str1 == str2;
	auto size = (str1.size() < str2.size())? str1.size() : str2.size();
	for(decltype(size) i=0; i != size; ++i) {
		if(str1[i] != str2[i])
			return false;
	}
}

const string &make_plural(size_t ctr, const string &word, const string &ending)
{
	return (ctr > 1)? word + ending: word;
}

const string &shorterString(const string &s1, const string &s2)
{
	return (s1.size() <= s2.size()) ? s1 : s2;
}
