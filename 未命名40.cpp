#include<iostream>
#include<cmath>
#include<cstring>
#include<vector> 
//using namespace string;
using namespace std;
int fact(int val)
{
	int ret=1;
	while(val > 1)
		ret *= val--;
	return ret;
}

size_t count_calls()
{
	static size_t ctr = 0;		//调用结束后，这个值仍然有效 
	return ++ctr;
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

//返回s中c第一次出现的位置索引
//引用形参occurs负责统计c出现的总次数
string::size_type find_char(const string &s, char c, 
								string::size_type &occurs) 
{
	int ret = s.size();		//第一次出现的位置
	occurs = 0;			//设置表示出现次数的形参的值 1
	for(int i = 0; i != s.size(); ++i) {
		if(s[i]==0) {
			if(ret == s.size())
				ret = i;
			++occurs;
		}
	} 
	return ret;
}

bool is_sentence(const string &s)
{
	//如果在s的末尾有且只有一个句号，则s是一个句子
	string::size_type ctr = 0;
	return find_char(s, '.', ctr) == s.size() - 1 && ctr == 1;  
}
int main()
{
	char *s = "asdfzxcvbasdf";
	string::size_type ctr = 0;
	int index = find_char("hello world", 's', ctr);
	cout << index << endl;
//	int j = fact(5.12);
//	cout << "5! is " << j << endl;
//	for(size_t i = 0; i != 100; ++i)
//		cout << count_calls() << endl;
//	cout << ctr << endl;
	return 0;
}
 
