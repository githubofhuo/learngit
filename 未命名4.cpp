#include<stdio.h>
/*strlen: 返回字符串s的长度*/
int strlen(char *s)
{
	int n;
	for(n=0;*s != '\0';s++)
		n++;
	return n;
}
 
int main()
{
	printf("%d", strlen("hello, world"));
//	int a[10];
//	for (int i = 0; i < 10; i++)
//		a[i] = i;
//	int *pa = &a[0];
////	int x = *(pa+2);
////	printf("%d",x);
//	for(int i=0;i<10;i++)
//		printf("%d\n", a ); 
	return 0;
}
