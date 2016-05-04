#include<iostream>
#include<cstring>
using namespace std;

class Person {
	protected:
		int id;
	public:
		Person() {
			cout << "Person��������" << endl;
		}
};
class Student {
	protected:
		char name[10];
		char sex;
		int number;
	public:
//		���캯��
		Student(int number, char name[], char sex): number(number), sex(sex) {
			cout << "Student�๹��" << endl;
			strcpy(this->name, name);
		}
//		��������
		~Student() {
			cout << "Student������" << endl;
		} 
//		���ѧ����Ϣ
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
//		���캯��
		Teacher(int age, char t_name[], char title[]): age(age) {
			cout << "Teacher�๹��" << endl;
			strcpy(this->t_name, t_name);
			strcpy(this->title, title);
		}
//		��������
		~Teacher() {
			cout << "Teacher������(" << t_name << ")" << endl;
		} 
//		�����ʦ��Ϣ
		void print() {
			cout << "Teacher name: " << t_name << endl;
			cout << "age: " << age << endl;
			cout << "title: " << title << endl;
		} 
};

class Assistant : public Student, public Teacher {
	private:
		float salary;		//нˮ
		Teacher teacher;	//н�� 
	public:
//		���캯��
		Assistant(int nubmer, int age, char name[], char sex, char title[], float salary, int t_age, char t_name[], char t_title[])
			:Student(number, name, sex), Teacher(age, name, title), teacher(t_age, t_name, t_title), salary(salary) {
				cout << "Assistant�๹��" << endl;
			}
//		��������
		~Assistant() {
			cout << "Assistant������" << endl;
		} 
//		���������Ϣ
		void print() {
			cout << "Assistant name: " << name << endl;
			cout << "title: " << title << endl;
			cout << "Student ID: " << number << endl;
			cout << "age: " << age << endl;
			cout << "sex: " << sex << endl;
			cout << "salary: " << salary << endl;
			cout << "���̽�ʦ��Ϣ: " << endl;
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

