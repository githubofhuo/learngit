#include<iostream>
#include<cstring>
using namespace std;

class Clock {
	private:
		int hour, minute, second;
	public:
		void setClock(int h, int m, int s);
};

void Clock::setClock(int h, int m, int s)
{
	hour = h;
	minute = m;
	second = s;
}

int main()
{
	cout << sizeof(int) << endl;
	cout << sizeof(Clock) << endl;
	return 0;
}
