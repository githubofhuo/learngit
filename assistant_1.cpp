#include<iostream>
#include<cstring>
using namespace std;

class Person {
	protected:
		int id;		//身份证号 
	public:
		Person(int id) : id(id) {
			cout << "Person构造函数" << endl;
		}
		int getID() {
			return this->id;
		}
		void print() {
			cout << "Person ID: " << this->id << endl;
		} 
};

class Student : virtual public Person {
	protected:
		char school[10];
		int id;
	public:
		Student(int p_id, int s_id, char school[]): Person(p_id), id(s_id) {
			cout << "Student构造函数" << endl;
			strcpy(this->school, school);
		}
		void print() {
			Person::print();
			cout << "Student ID: " << Student::id << endl;
			cout << "School: " << Student::school << endl;
		} 
}; 

class Teacher : virtual public Person {
	protected:
		char title[10];
		int id;
	public:
		Teacher(int p_id, int t_id, char title[]): Person(p_id), id(t_id) {
			cout << "Teacher构造函数" << endl; 
			strcpy(this->title, title);
		}
		void print() {
			Person::print();
			cout << "Teacher ID: " << endl;
			cout << "Teacher title: " << endl;
		}
}; 

class Assistant: public Student, public Teacher {
	private:
		float salary;
	public:
		Assistant(int p_id, int s_id, char school[], int t_id, char title[], float salary) 
		:Person(p_id), Student(p_id, s_id, school), Teacher(p_id, t_id, title), salary(salary) {
			cout << "Assistant构造函数\n" << endl;
		}
		void test() {
			strcpy(school, "dlut");
			strcpy(title, "assistant");
			Student::id = 1001;
			Teacher::id = 101;
			Person::id = 10001;
		}
		void print() {
			cout << "人 id: " << Person::id << endl;
			cout << "学生 id: " << Student::id << endl;
			cout << "教师 id: " << Teacher::id << endl;
			cout << "学校: " << school << endl;
			cout << "职称: " << title << endl;
			cout << "薪金: " << Assistant::salary << endl;   
		}
};

void function(Person& a)
{
	cout << a.getID() << endl; 
}
int main()
{
//	Assistant a(10001, 999, "dlut", 18, "assistant", 543.21);
//	a.print();
//	Student b(111, 100, "DUT");
//	cout << endl;
//	b.print();
//	cout << endl;
//	b = a;
//	b.print();
//	cout << endl;
//	
//	Person& c = a;
//	function(c);
	
	Person p(10001);
	Student s(20304, 997, "dlut");
	Teacher t(11100, 7, "Professor");
	Assistant a(40062, 999, "dlut", 18, "assistant", 543.21f);
	
	Person * group[4];
	group[0] = &p;
	group[1] = &s;
	group[2] = &t;
	group[3] = &a;
	for(int i=0;i<4;++i) {
		group[i]->print();
	}
	return 0;
}
