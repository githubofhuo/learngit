#include<stdio.h>
#include<ctype.h>
#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;
int getch(void)
{
	return (bufp>0)? buf[--bufp]: getchar();
}
void ungetch(int c)
{
	if(bufp>=BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}

//getfloat: get next floating-point number form input
int getfloat(float *pn)
{
	int c,sign;
	float power;

	while(isspace(c=getch()))
		;
	if(!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}
	sign=(c=='-')? -1: 1;
	if(c=='+' || c=='-')
		c=getch();
	for(*pn=0.0;isdigit(c);c=getch())
		*pn = 10.0 * *pn + (c-'0');
	if(c=='.')
		c=getch();
	for(power=1.0;isdigit(c);c=getch()) {
		*pn = 10.0 * *pn + (c-'0');
		power *= 10.0;
	}
	*pn = sign * *pn/power;
	if(c != EOF)
		ungetch(c);
	return c;
}

#define SIZE 20
int main()
{
	int ret;
	do {
		float f;

		fputs("Enter a number: ",stdout);
		fflush(stdout);
		ret=getfloat(&f);
		if(ret>0)
			printf("You entered: %f\n",f);
	} while(ret>0);

	if(ret==EOF) {
		puts("Stopped by EOF.");
	} else {
		puts("Stopped by bad input.");
	}

	return 0;
}
