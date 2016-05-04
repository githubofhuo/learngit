#include<iostream>
using namespace std;

class InputNum {
	public:
		InputNum(char msg[]) {
//			cout << "Enter number ";
			cout << msg;
			cin >> _num;
		}
		int GetValue() const {
			return _num;
		}
		void AddInput(char msg[]) {
			InputNum aNum(msg);
			_num = GetValue() + aNum.GetValue();
		}
	private:
		int _num;
};

const char SumString [] = "The sum is ";

int main() 
{
	InputNum num("Enter number ");
	num.AddInput("Another one ");
	num.AddInput("One more ");
	cout << SumString << num.GetValue() << "\n";
//	InputNum num;
//	cout << "The value is " << num.GetValue() << "\n";
//	num.AddInput();
//	cout << "Now the value is " << num.GetValue() << "\n";
//	return 0;
}
