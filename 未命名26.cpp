#include<iostream>
#include<string>
#include<vector>
using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;
int main()
{
//	char *s;
//	while (cin >> s && s != "sought")
//		;
//	int val=0;
//	int sum=0;
//	while (val <= 10) {
//		sum += val;
//		++val;
//	}
//	
//	cout << sum <<endl;
//	
//	while(int i=get_num())
//		cout << i << endl;
//	i=0;
	
	const vector<string> scores = { "F","D","C","B","A","A++" };
	string lettergrade;
	if (grade < 60)
		lettergrade = scores[0];
	else
		lettergrade = scores[(grade - 50) / 10];
	
	return 0;
}
