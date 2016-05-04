/*
#include <iostream>
namespace std
{
	class exception
	{
	public:
		exception() throw();
		exception(const exception &) throw();				//复制构造函数
		exception operator = (const exception &) throw();	//赋值
		virtual ~exception() throw();						//析构函数		
		virtual const char * what() const throw();			//返回异常文本描述
	};
}
*/
// expre_bad_cast_Exception.cpp
// compile with: /EHsc /GR

#include <typeinfo.h>
#include <iostream>

class Shape {
public:
	virtual void virtualfunc() const {}
};

class Circle : public Shape {
public:
	virtual void virtualfunc() const {}
};

using namespace std;
/*
int main() {
	Shape shape_instance;
	Shape& ref_shape = shape_instance;
	try {
		Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);
	}
	catch (bad_cast b) {
		cout << "Caught: " << b.what();
	}
}
*/