#include <iostream>
using namespace std;
class BaseExcept {};	//基类异常类
class DerivExcept: public BaseExcept {};	//派生异常类
DerivExcept de;
DerivExcept *pDe = &de;
BaseExcept *pBase = pDe;
BaseExcept be;

//测试函数
void testFun(int test)
{
	try
	{
		if(test == 3)
		{
			cout << "抛出BaseExcept		";
			throw be;
		}
		if(test == 2)
		{
			cout << "抛出DeriveExcept	";
			throw de;
		}
		if(test == 1)
		{
			cout << "抛出BaseExcept *	";
			throw pBase;
		}
		if(test == 0)
		{
			cout << "抛出DeriveExcept *	";
			throw pDe;
		}
	} 
	catch(DerivExcept *)
	{
		cout << "匹配DerivExcept * " << endl;
	}
	catch(BaseExcept * )
	{
		cout << "匹配BaseExcept * " << endl;
	}
}
//
//int main()
//{
//	cout << "开始" << endl;
//	for(int i=0;i < 4;i++)
//	{
//		try
//		{
//			testFun(i);
//		} catch(BaseExcept& )
//		{
//			cout << "匹配BaseExpect" << endl;
//		}
//	}
//	cout << "结束" << endl;
//	return 0;
//}