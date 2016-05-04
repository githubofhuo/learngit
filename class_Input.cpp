#if !defined input_h		//防止多重包含
#define input_h

const int maxBuf = 100;

//符号为tokNumber, tokError, +, -, *, /,

const int tokNumber = 1;
const int tokError = 2;

//从stdin获得输入, 转换成符号

class Input {
	public:
		Input();
		int Token() const {
			return _token;
		}
		int Number() const;
	private:
		int _token;
		char _buf[maxBuf];
}; 

#endif 		//input_h
