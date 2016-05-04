#include<iostream>
#include<string>
using namespace std;

class Student {
	protected:
		char name[10];
		char sex;
		int number;
		char school[10];
	public:
//		输入学生信息函数
		void input_data() {
			cin >> name >> sex >> number >> school;
		} 
//		输出信息函数 
		void print() {
			cout << "name: " << name << endl;
			cout << "sex: " << sex << endl;
			cout << "number: " << number << endl;
			cout << "school: " << school << endl;			
		}
};

class CollegeStudent : protected Student {
	protected:
		char major[10];
	public:
		void input() {
			input_data();
			cin >> major;
		}
//		输入主修专业信息函数
		void input_major() {
			cin >> major;
		}
//		输出大学生信息函数a
		void print() {
			cout << "name: " << name << endl;
			cout << "sex: " << sex << endl;
			cout << "number: " << number << endl;
			cout << "school: " << school << endl;			
			cout << "major: " << major << endl;
		} 
};

class GraduateStudent : protected CollegeStudent {
	private:
		char tutor[10];
	public:
//		输入研究生信息函数
		void input() {
			input_data();
			input_major();
			cin >> tutor;
		} 
//		输出研究生信息函数
		void print() {
			cout << "name: " << name << endl;
			cout << "sex: " << sex << endl;
			cout << "number: " << number << endl;
			cout << "school: " << school << endl;			
			cout << "major: " << major << endl;
			cout << "tutor: " << tutor << endl;
		} 
};

int main()
{
	GraduateStudent cs;
	cs.input();
//	cs.input_data();
	cs.print();
	
	return 0;
}
