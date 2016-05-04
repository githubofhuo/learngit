#include<stdio.h>
int atoi(int *s);
int main(int argc,int *argv[])
{
	int i1,i2;

//	if(argc<3) {
//		printf("Parameter number error!");
//		return 0;
//	}
	i1=atoi(argv[1]);
	i2=atoi(argv[2]);
	printf("%d + %d = %d",i1,i2,i1+i2);
	return 0;
}

int atoi(int *s){
	int n=0;
	int *p=s;

	int i;
	for(i=0;*s++ != '\0';i++)
		;
	while(p==s)
		n = 10*n + (*s-- - '0');
	return n;
}
