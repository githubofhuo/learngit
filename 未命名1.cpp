#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

int getch(void);
void ungetch(int);

#include<math.h>
/*getfloat1: like 4.7e-12*/
int getfloat1(float *pn)
{
	int c, sign1;
	int sign2;
	float power1;
	int *index = 0;

	while (isspace(c = getch()))	//skip the white space
		;
	if (!isdigit(c) && c != EOF && c != '+' && c != '-' && c != '.') {
		ungetch(c);
		return 0;
	}
	sign1 = (c == '-') ? -1 : 1;
	/*底数*/
	for (*pn = 0.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
	}
	if (c == '.')
		c = getch();
	for (power1 = 1.0; isdigit(c); c = getch()) {
		*pn = 10.0 * *pn + (c - '0');
		power1 *= 10;
	}
	*pn *= sign1 / power1;

	for (; isspace(c); c = getch())
		continue;
	if (c == 'e' || c == 'E') {			//指数
		while (isspace(c = getch()))
			;
		if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
			ungetch(c);
			index = 0;
			return 0;
		}
		if (c == '.') {
			ungetch(c);
			return 0;
		}
		sign2 = (c == '-') ? -1 : 1;
		if (c == '+' || c == '-') {
			int d = c;			//remember sign char
			if (!isdigit(c = getch())) {
				if (c != EOF)
					ungetch(c);
				ungetch(d);
				return d;
			}
		}

		for (*index = 0; isdigit(c); c = getch()) {
			*index = 10 * *index + (c - '0');
		}
		*index *= sign2;
	}

	if (*index > 0)
		*pn = *pn * pow(10, *index);
	else if (*index < 0)
		*pn = *pn / pow(10, abs(*index));
	else
		*pn = *pn;

	return *pn;
}



#define BUFSIZE 100
char buf[BUFSIZE];		//用于ungetch函数的缓冲区
int bufp = 0;			//buf中下一个空闲位置

int getch(void)		//取一个字符
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters.\n");
	else
		buf[bufp++] = c;
}

#define SIZE 2
int main()
{
	int n, getint(int *p);
	float array[SIZE];
	for (n = 0; n < SIZE && getfloat1(&array[n]) != EOF; n++)
		;
	for (int i = 0; i < SIZE; i++)
		printf("%lf\n", array[i]);
//	system("pause");
	return 0;
	
	
}


