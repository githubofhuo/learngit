#if !defined input_h		//��ֹ���ذ���
#define input_h

const int maxBuf = 100;

//����ΪtokNumber, tokError, +, -, *, /,

const int tokNumber = 1;
const int tokError = 2;

//��stdin�������, ת���ɷ���

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
