#include<iostream>
#include<string>
#include<vector>
#include<cctype>
//#include<name.h>

using namespace std;
using std::string;
using std::vector; 
int main()
{
//	vector<string> line;
//	auto len = line.size();
//	string str = "Hello";
//	string phrase = "Hello world";
//	string slang = "Hiya";
//	cout << (str < phrase) << endl;
//	cout << sizeof(len) << endl;
//	string s1 = "hello, ";
//	string s2 = "world.\n";
//	string s3 = s1 + s2;
//	cout << s3 << endl;
//	string s6 = s3 + ", " + "world";
//	cout << s6 << endl;
//	string s = "Hello";
//	cout << toupper() << endl;
//	string str("some string");
//	for(auto c : str)
//		cout << c << endl;
	
//	string s("Hello World!!!");
//	decltype(s.size()) punct_cnt = 0;
//	for(auto c : s)
//		if(ispunct(c))
//			++punct_cnt;
//	
//	for(auto &c : s)
//		c = toupper(c);
//	cout << s << endl;
//	cout << punct_cnt << " punctuation characters in " << s << endl;
//	string s("some string");
//	if(!s.empty())
//		s[0] = toupper(s[0]);
//	
//	cout << s << endl;
//	for(decltype(s.size()) index=0; index != s.size() && !isspace(s[index]); ++index)
//		s[index] = toupper(s[index]);
//	cout << s << endl;

//	const string hexdigits = "0123456789ABCDEF";	//可能的十六进制数字
//	cout << "Enter a serise of numbers between 0 and 15" 
//			<< " separated by spaces. HIT ENTER when finished: "
//			<< endl;
//	string result;			//用于保存十六进制的字符串 
//	string::size_type n; 	//用于保存从输入流读取的数
//	while(cin >> n) 
//		if(n < hexdigits.size() && n >= 0)
//			result += hexdigits[n];
//		else {
//			cout << "Wrong input!" << endl;
//			return 1;
//		}
//		
//			
//	cout << "Your hex number is: " << result << endl;
	
//	vector<int> ivec;
//	vector<Sales_item> Sales_vec;
//	vector<vector<string>> file;
//	vector<string> v1;
//	return 0;
//	vector<int> ivec(10, -1);
//	for(int &a: ivec)
//		cout << a << endl;

//	vector<string> v1 = {"a" ,"an", "the"};
//	for(auto &s : v1)
//		cout << s << endl;
//	vector<string> v5{"hi"};
//	cout << sizeof(v5) << endl;
	
//	vector<int> v2;
//	for(int i=0; i != 100; ++i)
//		v2.push_back(i);
//	
//	string word;
//	vector<string> text;
//	while(cin >> word)
//		text.push_back(word);
//	
//	for(auto &s : text) {
//		for(decltype(s.size()) index=0; index != s.size() && !isspace(s[index]); ++index)
//			s[index] = toupper(s[index]);
//		cout << s << endl;	
//	}
//	
//	cout << text.empty() << endl;	
	
//	vector<int> v{1,2,3,4,5,6,7,8,9};
//	for(auto &i : v)
//		i *= i;
//	for(auto i : v)
//		cout << i << " ";
//	cout << endl;
	
//	vector<int>::size_type s;
//	
//	vector<unsigned> scores(11, 0);
//	unsigned grade;
//	while(cin >> grade && isdigit(grade)) {
//		if(grade <= 100 && grade >= 0)
//			++scores[grade / 10];
//	}
//	auto b = scores.begin(), e = scores.end();
//	for(int index=0; index != scores.size(); ++index)
//		cout << scores[index] << " ";
//	cout << endl;
	string s("some string");
//	if(s.begin() != s.end()) {
//		auto it = s.begin();
//		*it = toupper(*it);
//	}
//		
//	cout << s << endl;
//	for(auto it = s.begin(); it != s.end() && !isspace(*it); ++it)
//		*it = toupper(*it);
//	cout << s << endl;
//	
//	vector<int>::iterator it;
//	string::iterator it2;
//	
//	vector<int>::const_iterator it3;
//	vector<int>::const_iterator it4;
//	
//	vector<int> v;
//	const vector<int> cv;
//	auto it5 = v.begin();
//	auto it6 = v.end();
//	cout << sizeof(it5) << " " << sizeof(it6) << endl;

	int ia[] = {0,1,2,3,-8,4,5,6,7,8,9};
	int *beg = begin(ia);
	int *last = end(ia);
	while(beg != last && *beg >= 0)
		++beg;
	cout << *beg << endl;
}

