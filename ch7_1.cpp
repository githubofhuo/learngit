#include<iostream>
#include<cstring>
using namespace std;

class Clock {
	private:
		int hour;
		int minute;
		int second;
	public:
		Clock(int h, int m, int s): hour(h), minute(m), second(s) {}
		void print() {
			cout << hour << ':' << minute << ':' << second << endl;
		}
//		��������� 
		bool operator < (Clock& another) {
			int temp = (hour - another.hour) * 3600
						+ (minute - another.minute) * 60
						+ (second - another.second);
			if(temp < 0)
				return true;
			else
				return false; 
		}
};

//�������������ݵ���Сֵ�Ĳ���
template<class T>
T min(T& a, T& b)
{
	return (a < b)? a: b;
} 

int main()
{
	Clock c1(12,40,50);
	Clock c2(11,30,30);
	
	min(c1, c2).print();	
	return 0;
} 
