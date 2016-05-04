#include "Input.h"
#include "stack.h"
#include <iostream>
#include <cassert>

class Input;

class Calculator {
	public:
		bool Execute(Input const& input);
//		让stack可以访问
		Istack const& GetStack() const {
			return _stack;
		}
	private:
		int Calculate(int n1,  int n2, int token) const;
		Istack _stack;
};


bool Calculator::Execute(Input const& input)
{
	int token = input.Token();
	bool status = false;		//假定失败

	if(token == tokError)
		std::cout << "Unknown token.\n";
	else if(token == tokNumber) {
		if(_stack.IsFull())
			std::cout << "Stack is full"; 
		else{
			_stack.Push(input.Number());
			status = true;
		}
	} 
	else {
//		假定：Input不能产生任何其他符号
		assert(token == '+' || token == '-' || token == '*' || token == '/');
		if(_stack.IsEmpty())
			std::cout << "Stack is empty";
		else {
			int num2 = _stack.Pop();
			int num1;
			//特例：仅当堆栈中有一个数
			//对两个操作数使用这个数
			if(_stack.IsEmpty())
				num1 = num2;
			else
				num1 = _stack.Pop();
			
			_stack.Push(Calculate(num1, num2, token));
			status = true; 
		}
	}
	return status;
}

int Calculator::Calculate(int num1, int num2, int token) const
{
	int result;
	
	if(token == '+')
		result = num1 + num2;
	else if(token == '-')
		result = num1 - num2;
	else if(token == '*')
		result = num1 * num2;
	else if(token == '/') {
		if(num2 == 0) {
			std::cout << "Division by zero\n";
			result = 0;
		} else
			result = num1 / num2;		//整数除 
	}
	return result; 
}
