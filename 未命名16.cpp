#include<stdio.h>
int fib()
{
	static unsigned first=0,second=1,next,retval;
	next = first + second;
	retval = next;
	first = second;
	second = next;
	
	return retval;	
} 

int main()
{
	int i=0;
	while(i<30) {
		i++;
		printf("%d\n", fib());
	}
	return 0;
}
