#include <iostream>
using namespace std;

//定义时间类型
class Clock
{
	private:
		int hour;
		int minute;
		int second;
	public:
		Clock(int h = 0, int m = 0, int s = 0) : hour(h), minute(m), second(s) {}
		void print() const {
			cout << hour << ':' << minute << ':' << second << endl;
		}
		//		重载运算符 
		bool operator < (Clock& another) const {
			int temp = (hour - another.hour) * 3600
				+ (minute - another.minute) * 60
				+ (second - another.second);
			if (temp < 0)
				return true;
			else
				return false;
		}
};

/*对arr数组中的n个数据排序*/
template<class T>
void BubbleSort(T *arr, int n)
{
	T temp;
	int i, j;
	for (i = 0; i < n - 1; ++i)
		for (j = n - 1; j > i;--j)
		{
			if(arr[j] < arr[j-1])
			{
				temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
}

int main()
{
	int i;
	int m_iarray[5] = { 10, 8, 20, 15, 5 };
	Clock m_tarray[3] = { Clock(12,12,12), Clock(10,10,10), Clock(7,7,7) };
	BubbleSort(m_iarray, 5);
	BubbleSort(m_tarray, 3);
	for (i = 0; i < 5; ++i)
		cout << m_iarray << ' ';
	cout << endl;

	cout << "-------------------------------------------------------" << endl;
	for (i = 0; i < 3; ++i)
		m_tarray[i].print();
	return 0;
	return 0;
}


