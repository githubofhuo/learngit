#include<cctype>
#include<cstdlib>

Input::Input()
{
	std::cin >> _buf;
//	判断输入的第一个字符是什么符号
	int c = _buf[0];
	
	if(std::isdigit(c))
		_token = tokNumber;
	else if(c == '+' || c == '*' || c== '/')
		_token = c;
	else if(c == '-') {		//输入负数 
		if(std::isdigit(_buf[1]))		//参照下一个字符
			_token = tokNumber;
		else
			_token = c; 
	}
	else
		_token = tokError;
}
