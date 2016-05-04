#include<stdio.h>
#include<ctype.h>

//getline: read a line into s,return length
int getline(char *s,int lim)
{
	int c;
	char *t=s;

	while(--lim>0 && (c=getchar()) != EOF && c != '\n')
		*s++ = c;
	if(c=='\n')
		*s++=c;
	*s='\0';
	return s-t;
}

//atoi: convert s to interger: pointer version
int atoi(char *s)
{
	int n,sign;

	for(;isspace(*s);s++)
		;
	sign=(*s=='-')? -1: 1;
	if(*s=='+' || *s=='-')
		s++;
	for(n=0;isdigit(*s);s++)
		n=10*n+(*s-'0');
	return sign*n;
}

#define MAXLINE 30
int main()
{
	char *s="-456123";
	printf("%d",atoi(s));
	return 0;
}
