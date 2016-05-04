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

/*getop: ��ȡ��һ�������*/
int getop(char s[])
{
	int i, c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (!isdigit(c) && c != '.')
		return c;		//������
	i = 0;
	if (isdigit(c))		/*�ռ���������*/
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')		/*�ռ�С������*/
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
char buf[BUFSIZE];		/*����ungetch�����Ļ�����*/
int bufp = 0;			/*buf����һ������λ��*/
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
/*ungets(): �������ַ���ѹ�ص�������*/
void ungets(const char s[])
{
	size_t i = strlen(s);		//size_t��unsigned int���͵�
	while (i > 0)
		ungetch(s[--i]);
}

#define MAXVAL 100		/*ջval��������*/
int sp = 0;				/*��һ������ջ��λ��*/
double val[MAXVAL];		/*ֵջ*/

/*push������ ��fѹ�뵽ֵջ��*/
void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}
/*pop������ ����������ջ����ֵ*/
double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty.\n");
		return 0.0;
	}
}
