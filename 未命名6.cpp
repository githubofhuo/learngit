#include<stdio.h>
int strlen(char *s)
{
	int len=0;
	for(;*s != '\0';s++,len++)
		;
	return len;
}

void reverse(char *s)
{
	char *t;
	char *c;
	for (t = s + strlen(s) - 1; t < s; s++, t--) {
		c = s;
		s = t;
		t = c;
	}
}

/**/
int main()
{
	char *s = "hello, world";
	strlen(s);
	printf("%s", s);
	return 0;
}
