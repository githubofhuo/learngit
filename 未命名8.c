#include<stdio.h>
#include<string.h>
void reverse(char *s)
{
	char *start = s;
	char *end = s + strlen(s) - 1;
	char c;
	for(; start < end; start++, end--) {
		c = *start;
		*start = *end;
		*end = c;
	}
}

int main()
{
	char *s = "hello, world";
	printf("%s\n",s);
	reverse(s);
//	printf("s",s);
	
//	char *s = "hello, world";
//	printf("%d\n",1 strlen(s));
//	printf("%c", *s);
	return 0;
}
