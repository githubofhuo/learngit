#include<cctype>
#include<cstdlib>

Input::Input()
{
	std::cin >> _buf;
//	�ж�����ĵ�һ���ַ���ʲô����
	int c = _buf[0];
	
	if(std::isdigit(c))
		_token = tokNumber;
	else if(c == '+' || c == '*' || c== '/')
		_token = c;
	else if(c == '-') {		//���븺�� 
		if(std::isdigit(_buf[1]))		//������һ���ַ�
			_token = tokNumber;
		else
			_token = c; 
	}
	else
		_token = tokError;
}
