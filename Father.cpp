#include<iostream>
#include<cstring>
using namespace std;

class Father {
	private:
		char name[16];
		int money;
	public:
		Father(char *n, int m);
		char* getName();		//返回name 
		void reveice(int m);	//接受m元 
		int pay(int m);			//支付m元 
		void print();
};
class Son {
	private:
		char name[16];
		int money;
		Father *father;		//父类
	public:
		Son(Father *p, char *n, int m);
		char* getName();		//返回name 
		Father* getFather(); 	//返回father
		void receive(int m);	//接受m元
		int pay(int m);
		void print(); 
}; 

//Son类实现
Son::Son(Father *p, char *n, int m) {
	father = p;
	strcpy(name, n);
	money = m;
} 
char* Son::getName() {
	return name;
}
Father* Son::getFather() {
	return father;
}
void Son::receive(int m) {
	if(m > 0)
		money = money + m;
}
/*支付， 返回支付钱数*/
int Son::pay(int m)
{
	if(m <= 0)
		return 0;
	if(money > m) {
		money = money - m;
		return m;
	} else {
		return 0;
	}
}
void Son::print() {
	cout << "name:" << name << " money:" << money << endl;
} 

//Father类实现
int Father::pay(int m) {
	if(m <= 0)
		return 0;
	if(money >= 0) {
		money = money - m;
		return m;
	}
	else
		return 0;
}
char* Father::getName()
{
	return name;
}
Father::Father(char *n, int m)
{
	strcpy(name, n);
	money = m;
}
void Father::reveice(int m)
{
	money = money + m;
}
void Father::print()
{
	cout << "name:" << name << " money:" << money << endl;
}

int main()
{
	Father f1("李四", 10000);
	Son s1(&f1, "李小四", 100);
	s1.receive(f1.pay(1000));
	f1.print();
	s1.print();	 
	return 0;
}
