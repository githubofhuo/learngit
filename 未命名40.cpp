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
	static size_t ctr = 0;		//���ý��������ֵ��Ȼ��Ч 
	return ++ctr;
}

bool isShorter(const string &s1, const string &s2)
{
	return s1.size() < s2.size();
}

//����s��c��һ�γ��ֵ�λ������
//�����β�occurs����ͳ��c���ֵ��ܴ���
string::size_type find_char(const string &s, char c, 
								string::size_type &occurs) 
{
	int ret = s.size();		//��һ�γ��ֵ�λ��
	occurs = 0;			//���ñ�ʾ���ִ������βε�ֵ 1
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
	//�����s��ĩβ����ֻ��һ����ţ���s��һ������
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
 
