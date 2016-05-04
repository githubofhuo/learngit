#include<iostream>
#include<cstring>
#include<vector>
using namespace std;
//using std::vector;

class Screen {
	public:
		typedef std::string::size_type pos;
		Screen() = default;		//因为Screen有另一个构造函数，所以本函数是必须的 
		Screen(pos cursor, pos ht, pos wd, char c):
			cursor(0), height(ht), width(wd), contents(ht * wd, c) {}
		char get() const {
			return contents[cursor];		//读取光标处的字符，隐式内联 
		}
		inline char get(pos ht, pos wd) const;
		Screen &move(pos r, pos c);		//能在之后被设为内联 
		void some_member() const; 
		//设置光标所在位置的字符
		Screen &set(char);
		Screen &set(pos, pos, char); 
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		std::string contents;
		mutable size_t access_str;		//即使在一个const对象内也能修改 
};
//移动光标到第r行第c列 
inline Screen &Screen::move(pos r, pos c)
{
	pos row = r * width;
	cursor = row + c;
	return *this; 
}
//得到第r行第c列的字符 
inline char Screen::get(pos r, pos c) const
{
	pos row = r * width;
	return contents[row+c];
}
//记录成员函数被调用的次数 
void Screen::some_member() const 
{
	++access_str;
}

//设置光标所在位置的值 
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
		//这个Window_mgr追踪的Screen
		//默认情况下，一个Window_mgr包含一个标准尺寸的空白Screen
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

