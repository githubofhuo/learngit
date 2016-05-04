#include<stdio.h>
#include<ctype.h>

int getch(void);
void ungetch(int);

/*		getint: get next integer from input into *pn	 */
int getint(int *pn)
{
	int c, sign;
	while (isspace(c = getch()))
		;
	
	if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
		ungetch(c);
		return 0;
	}
	sign = (c == '-') ? -1 : 1;
	if (c == '+' || c == '-')
		c = getch();
	for (*pn = 0; isdigit(c); c = getch())
		*pn = 10 * *pn + (c - '0');
	*pn *= sign;
	if (c != EOF)
		ungetch(c);
	return c;
}

#define BUFSIZE 100
char buf[BUFSIZE];		//buffer for ungetch
int bufp = 0;			//next free position in buf

int getch(void)
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

/*
	The getfloat function 
	
	Reads the next number from input, and puts it into *fp. Return EOF for end of
	the file, zero if the next input is not a number, and a positive value of the 
	input contains a valid number.

	Based heavily on the getint function from K&R2.
*/

#include<ctype.h>
#include<math.h>

int getfloat(float *fp)
{
	int ch;
	int sign;
	int fraction;		//小数
	int digits;
		
	while (isspace(ch = getch()))	//skiip the space
		;
	if (!isdigit(ch) && ch != EOF && ch != '+' && ch != '-' && ch != '.') {
		ungetch(ch);
		return 0;
	}
	
	sign = (ch == '-') ? -1 : 1;
	if (ch == '+' || ch == '-') {
		ch = getch();
		if (!isdigit(ch) && ch != '.') {
			if (ch == EOF)
				return EOF;
			else {
				ungetch(ch);
				return 0;
			}
		}
	}

	*fp = 0;
	fraction = 0;
	digits = 0;		//小数的位数，包含整数部分和小数部分
	for (; isdigit(ch) || ch == '.'; ch = getch()) {
		if (ch == '.') {
			fraction = 1;
		}
		else {
			if (!fraction) {
				*fp = 10 * *fp + (ch - '0');
			}
			else {
				*fp = *fp + ((ch - '0') / pow(10, fraction));
				fraction++;
			}
			digits++;
		}
	}

	*fp *= sign;
	if (ch == EOF) {
		return EOF;
	}
	else {
		ungetch(ch);
		return (digits) ? ch : 0;
	}
}

/*
	Test module.
*/

#include<stdio.h>
int main()
{
	int ret;

	do {
		float f;
		fputs("Enter a number: ", stdout);
		fflush(stdout);
		ret = getfloat(&f);
		if (ret > 0) {
			printf("You entered: %f\n", f);
		}
	} while (ret > 0);

	if (ret == EOF) {
		puts("Stopped By EOF.");
	}
	else {
		puts("Stopped by bad input.");
	}

	return 0;
}
