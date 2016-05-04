#include<iostream>
using namespace std;

class Clock {
	private:
		int hour, minute, second;
	public:
		Clock(int h, int m, int s);
		~Clock() {
			cout << "destructing";
		}
		void setClock(int h, int m, int s) {
			hour = (h >= 0 && h <= 23)? h : 0;
			minute = (m >= 0 && m <= 59)? m : 0;
			second = (s >= 0 && s <= 59)? s : 0;
		}
//		void setClock(int h, int m);
//		void setClock(int h);
		void showClock() {
			cout << hour << ": "<< minute<< ": " << second << endl;
		}
} clock1, clock2;

Clock::Clock(int h, int m, int s) {
	hour = h;
	minute = m;
	second = s;
}
class TimeBomb {
	private:
		Clock timer;
		int explosive;
	public:
		void setTime();
}; 

int main()
{
	Clock *p;
	p = &clock1;
	Clock &clock3 = clock2;
//	(*p).hour = 8
	clock3.setClock(6, 15, 24);
//	clock1.hour = 6;
	clock1.setClock(1,2,3);
//	clock2.setClock(4,5,6);
	
	clock1.showClock();
	clock2.showClock();
	return 0;
} 
