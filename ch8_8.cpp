#include <iostream>
using namespace std;
class BaseExcept {};	//�����쳣��
class DerivExcept: public BaseExcept {};	//�����쳣��
DerivExcept de;
DerivExcept *pDe = &de;
BaseExcept *pBase = pDe;
BaseExcept be;

//���Ժ���
void testFun(int test)
{
	try
	{
		if(test == 3)
		{
			cout << "�׳�BaseExcept		";
			throw be;
		}
		if(test == 2)
		{
			cout << "�׳�DeriveExcept	";
			throw de;
		}
		if(test == 1)
		{
			cout << "�׳�BaseExcept *	";
			throw pBase;
		}
		if(test == 0)
		{
			cout << "�׳�DeriveExcept *	";
			throw pDe;
		}
	} 
	catch(DerivExcept *)
	{
		cout << "ƥ��DerivExcept * " << endl;
	}
	catch(BaseExcept * )
	{
		cout << "ƥ��BaseExcept * " << endl;
	}
}
//
//int main()
//{
//	cout << "��ʼ" << endl;
//	for(int i=0;i < 4;i++)
//	{
//		try
//		{
//			testFun(i);
//		} catch(BaseExcept& )
//		{
//			cout << "ƥ��BaseExpect" << endl;
//		}
//	}
//	cout << "����" << endl;
//	return 0;
//}