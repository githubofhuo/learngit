#include<iostream>
#include<cstring>
using namespace std;

class Clock {
	private:
		int hour;
		int minute, second;
	public:
		void setClock(int h, int m, int s) {
			hour = h;
			minute = m;
			second = s;
		}		 
		void showClock() const {	//����Ա���� 
			cout << hour << minute << second;
		}
};

int main()
{
	
	return 0;
} 
