#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
//using std::vector;

class Screen {
	public:
		typedef std::string::size_type pos;
		Screen() = default;		//��ΪScreen����һ�����캯�������Ա������Ǳ���� 
		Screen(pos cursor, pos ht, pos wd, char c):
			cursor(0), height(ht), width(wd), contents(ht * wd, c) {}
		char get() const {
			return contents[cursor];		//��ȡ��괦���ַ�����ʽ���� 
		}
		inline char get(pos ht, pos wd) const;
		Screen &move(pos r, pos c);		//����֮����Ϊ���� 
		void some_member() const; 
		//���ù������λ�õ��ַ�
		Screen &set(char);
		Screen &set(pos, pos, char); 
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;
		mutable size_t access_str;		//��ʹ��һ��const������Ҳ���޸� 
};
//�ƶ���굽��r�е�c�� 
inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this; 
}
//�õ���r�е�c�е��ַ� 
inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row+c];
}
//��¼��Ա���������õĴ��� 
void Screen::some_member() const 
{
	++access_str;
}

//���ù������λ�õ�ֵ 
inline Screen &Screen::set(char c)
{
	contents[cursor] = c;
	return *this;
} 
inline Screen &Screen::set(pos r, pos col, char ch)
{
	contents[r*width+col] = ch;
	return *this;
}
class Window_mgr {
	private:
		//���Window_mgr׷�ٵ�Screen
		//Ĭ������£�һ��Window_mgr����һ����׼�ߴ�Ŀհ�Screen
		vetcor<Screen> screens{Screen(24, 80, ' ')}; 
}; 
int main()
{
	Screen myscreen;
	char ch = myscreen.get(1, 2);
	myscreen.move(4, 0).set('#');
	std::cout << ch << std::endl;
	return 0;
}

