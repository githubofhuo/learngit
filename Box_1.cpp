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
//随机数函数 
inline int random(int count) {
	return (1 + (int)(count * (double)(rand() / RAND_MAX + 1.0)));
}

int main()
{
	const int boxCount = 10;		//数组大小
	Box boxes[boxCount];			//合资类对象数组
	
	//随机初始对象数组元素
	const int dimLimit = 10;		//盒子边长最大值
	srand((unsigned)time(0));		//随机种子
	for(int i = 0;i < boxCount; i++) {
		boxes[i] = Box(random(dimLimit), random(dimLimit), random(dimLimit));
	}
	//寻找数组中体积最大的对象
	Box *pLargest = &boxes[0];
	for(int i = 0; i < boxCount; ++i) {
		if(*pLargest < boxes[i]) {
			//	pLargest->volume() < box[i].volume();
			pLargest = &boxes[i];
		}
	}
	cout << "The largest box in the array has dimensions: ";
	pLargest->show();
	
	//搜索体积在100~500之间的盒子
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
