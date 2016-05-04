#include<stdio.h>
#include<math.h>	/*for atof()*/

#define MAXOP 100	/*max size of operand or operator*/
#define NUMBER '0'	/*signal that a number was found */

int getop(char []);
void ungets(const char s[]);
void push(double);
double pop(void);

/*reverse Polish calculator; uses command line*/
int main(int argc, char *argv[])
{
	char s[MAXOP];
	double op2;

	while (--argc > 0) {
		ungets(" ");	/*push end of argument*/
		ungets(*++argv);
		switch (getop(s)) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: zero divisor\n");
			break;
		default:
			printf("error: unknown command %s\n");
			argc = 1;
			break;
		}
	}
	printf("\t%.8g\n", pop());
	return 0;
}


#include<ctype.h>
int getch(void);
void ungetch(int);

/*getop: 获取下一个运算符*/
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;		//不是数
	i = 0;
	if (isdigit(c))		/*收集整数部分*/
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/*收集小数部分*/
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#include<string.h>
/*getch()  and  ungetch()*/
#define BUFSIZE 100
char buf[BUFSIZE];		/*用于ungetch函数的缓冲区*/
int bufp = 0;			/*buf中下一个空闲位置*/
int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
/*ungets(): 将整个字符串压回到输入中*/
void ungets(const char s[])
{
	size_t i = strlen(s);		//size_t是unsigned int类型的
	while (i > 0)
		ungetch(s[--i]);
}

#define MAXVAL 100		/*栈val的最大深度*/
int sp = 0;				/*下一个空闲栈的位置*/
double val[MAXVAL];		/*值栈*/

/*push函数： 把f压入到值栈中*/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/*pop函数： 弹出并返回栈顶的值*/
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty.\n");
		return 0.0;
	}
}
