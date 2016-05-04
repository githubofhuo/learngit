#include<iostream>
#include<cstring>
using namespace std;

class Person {
	protected:
		int id;
	public:
		Person() {
			cout << "Person析构函数" << endl;
		}
};
class Student {
	protected:
		char name[10];
		char sex;
		int number;
	public:
//		构造函数
		Student(int number, char name[], char sex): number(number), sex(sex) {
			cout << "Student类构造" << endl;
			strcpy(this->name, name);
		}
//		析构函数
		~Student() {
			cout << "Student类析构" << endl;
		} 
//		输出学生信息
		void print() {
			cout << "Studnet ID: " << number << endl;
			cout << "name: " << name << endl;
			cout << "sex: " << sex << endl;
 		} 
};

class Teacher {
	protected:
		char t_name[10];
		int age;
		char title[10];
	public:
//		构造函数
		Teacher(int age, char t_name[], char title[]): age(age) {
			cout << "Teacher类构造" << endl;
			strcpy(this->t_name, t_name);
			strcpy(this->title, title);
		}
//		析构函数
		~Teacher() {
			cout << "Teacher类析构(" << t_name << ")" << endl;
		} 
//		输出教师信息
		void print() {
			cout << "Teacher name: " << t_name << endl;
			cout << "age: " << age << endl;
			cout << "title: " << title << endl;
		} 
};

class Assistant : public Student, public Teacher {
	private:
		float salary;		//薪水
		Teacher teacher;	//薪金 
	public:
//		构造函数
		Assistant(int nubmer, int age, char name[], char sex, char title[], float salary, int t_age, char t_name[], char t_title[])
			:Student(number, name, sex), Teacher(age, name, title), teacher(t_age, t_name, t_title), salary(salary) {
				cout << "Assistant类构造" << endl;
			}
//		析构函数
		~Assistant() {
			cout << "Assistant类析构" << endl;
		} 
//		输出助教信息
		void print() {
			cout << "Assistant name: " << name << endl;
			cout << "title: " << title << endl;
			cout << "Student ID: " << number << endl;
			cout << "age: " << age << endl;
			cout << "sex: " << sex << endl;
			cout << "salary: " << salary << endl;
			cout << "助教教师信息: " << endl;
			teacher.print();
		}
//		test
		void test()
		{
			cout << Student::name << endl;
			cout << Teacher::t_name << endl;
		}
};

int main()
{
	Assistant a(1001, 18, "Li Ming", 'M', "Assistant", 987.65f, 42, "Wang Feng", "Professor");
//	a.print(); 
	cout << endl;
	a.test();
	return 0;
}

