#include<iostream>
#include<cstring>
using namespace std;
class Student {
	private:
		char name[20];
		int age;
		float score;
	public:
		Student(char *n, int a, int s) {
			strcpy(name, n);
			age = a;
			score = s;
		}
		float getScote() {
			return score;		//·µ»Ø³É¼¨Öµ 
		}
};

Student stud[3] = {
	Student("zhang san", 20, 60),
	Student("li si", 19, 70),
	Student("Wang wu", 18, 78)
};

int main()
{
//	cout << stud[1].score << endl;
//	return 0;
	float sum=0, average=0;
	int i;
	for(i=0;i<3;i++)
		sum += stud[i].getScote();
	average = sum/3;
	cout << "sum=" << sum << " average=" << average << endl;
	return 0; 
}
