#include "stack.h"
#include "stack.cpp"
#include<iostream>

int main()
{
	Calculator TheCalculator;
	bool status;
	do {
//		 ‰»ÎÃ· æ
		std::cout << "> ";
		Input input;
		status = TheCalculator.Execute(input);
		if(status) {
			for(StackSeq seq(TheCalculator.GetStack()); !seq.AtEnd(); seq.Advance())
				std::cout << " " << seq.GetNum() << std::endl;
		}
	}while(status);
	
	
	return 0;
}
