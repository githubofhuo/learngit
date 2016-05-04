#include<iostream>
#include<cstring>
using namespace std;

class Engine {
	public:
		void work() {
			cout << "work" << endl;
		}
};

class Wheel {
	public:
		void roll() {
			cout << "roll" << endl;
		}
};

class Automobile {
	private:
		Engine *engine;
		Wheel *wheel[4];
	public:
		void move() {
			engine->work();
			for(int i=0; i<4; ++i)
				wheel[i]->roll();
		}
};

/*
class Vehicle {
	protected:
		double weight;
		float speed;
	public:
		void run();
};
class Automobile : public Vehicle {
	private:
		int load;
	public:
		void move() {
			run();
		}
};
*/

class Person {
	public:
		void buy(Automobile& automobile) {
			automobile.move();
		}
};

int main()
{
	Person person;
	Automobile automobile;
	automobile.move();
	cout << endl;
	person.buy(automobile);
	return 0;
}
