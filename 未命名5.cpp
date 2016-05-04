#include<stdio.h>
#include<ctype.h>

#define NUMBER '0'	/*signal that a number was found*/

int getch(void);
void ungetch(int);

/*getop: get next operator or numberic operand; pointer ver*/
int getop(char *s)
{
	int c;
	while((*s = c = getch()) == ' ' || c == '\t')
		;
	*(s+1) = '\0';
	
	if(!isdigit(c) && c != '.')
		return c;		//not a number
	if(isdigit(c))
		while(isdigit(*++s = c = getch()))
			;
	if(c=='.')
		while(isdigit(*++s = c = getch()))
			;
	*s = '\0';
	if(c != EOF)
		ungetch(c);
	return NUMBER;	
}

#define BUFSIZE 100
char buf[BUFSIZE];	//用于ungetch函数的缓冲区
int　bufp=0;
int getch(void)
{
	return (bufp>0)? buf[--bufp] : getchar();
}

void ungetch(int c)		//把字符压回到输入中
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
		
 } 
