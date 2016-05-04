#include<iostream>
#include<cstring>
using namespace std;

class Student {
	private:
		char name[20];
		int age;
		float score;
	public:
		static float sum;		//声明静态数据成员
		Student(char *n, int a, int s) {
			strcpy(name, n);
			age = a;
			score = s;
			sum += score;		//构造同时把score累加到静态成员sum 
		}
		static float getAverage();	//声明静态函数成员 
		void display();			//输出总和与平均值 
};

float Student::sum = 0;
float Student::getAverage()
{
	return sum / 3;
}
void Student::display()
{
	cout << "sum=" << sum << " average=" << getAverage() << endl;	
} 

int main()
{
	Student stud[3] = {
		Student("zhang san", 20, 60),
		Student("Li si", 19, 70),
		Student("Wang wu", 18, 78)
	};
	cout << "sum=" << Student::sum << " average=" << Student::getAverage() << endl;
	cout << "sum=" << stud[0].sum << "average=" << stud[0].getAverage() << endl; 
	stud[2].display();
	return 0;
} 
