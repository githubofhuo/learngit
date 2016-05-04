#include<stdio.h>
int main()
{
	int k=3,sum=0;
	switch(k--) {
		default: break;
		case 1:sum=sum+k;break;
		case 2:
		case 3:sum=sum+k;break;
	}
	printf("%d",sum);
	return 0;
}
