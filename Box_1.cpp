#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Box {
	private:
		double length;
		double width;
		double height;
	public:
		Box(double l = 1.0, double w = 1.0, double h = 1.0) {
			length = l;
			width = w;
			height = h;
		}
		double volume() const {
			return length * width * height;
		}
		void show() const {
			cout << length << "*" << width << "*" << height ;//" volume= " << volume << endl;
		}
		bool operator < (const Box &b) const {
			return volume() < b.volume();
		}
		bool operator < (const double dVolume) const {
			return volume() < dVolume;
		}
		friend bool operator < (const double dVolume, const Box &b) {
			return dVolume < b.volume();
		}
};
//��������� 
inline int random(int count) {
	return (1 + (int)(count * (double)(rand() / RAND_MAX + 1.0)));
}

int main()
{
	const int boxCount = 10;		//�����С
	Box boxes[boxCount];			//�������������
	
	//�����ʼ��������Ԫ��
	const int dimLimit = 10;		//���ӱ߳����ֵ
	srand((unsigned)time(0));		//�������
	for(int i = 0;i < boxCount; i++) {
		boxes[i] = Box(random(dimLimit), random(dimLimit), random(dimLimit));
	}
	//Ѱ��������������Ķ���
	Box *pLargest = &boxes[0];
	for(int i = 0; i < boxCount; ++i) {
		if(*pLargest < boxes[i]) {
			//	pLargest->volume() < box[i].volume();
			pLargest = &boxes[i];
		}
	}
	cout << "The largest box in the array has dimensions: ";
	pLargest->show();
	
	//���������100~500֮��ĺ���
	double volMin = 100.0;
	double volMax = 500.0;
	cout << "Boxes with volumes between " << volMin << " and " << volMax << " are:";
	for(int i = 0; i < boxCount; ++i) {
		if(volMin < boxes[i] && boxes[i] < volMax) {
			boxes[i].show();
		}
	} 
	
	return 0;
}
