#include<stdio.h>
#include<string.h>
#include<ctype.h>

#define MAXLINE 100				/*maximum line size*/
#define TABINC 8				/*default tab increment size*/
#define YES 1					
#define NO 0

void settab(int argc, char *argv[], char *tab);
void entab(char *tab);
int tabpos(int pos, char *tab);

/*replace strings of blanks with tabs*/
int main(int argc, char *argv[])
{
	char tab[MAXLINE + 1];
	settab(argc, argv, tab);
	entab(tab);
	return 0;
}

/*atoi: convert s to interger; pointer version*/
int atoi(char *s)
{
	int n, sign;
	for (; isspace(*s); s++)		/*skip white space*/
		;
	sign = (*s == '-') ? -1 : 1;
	if (*s == '-' || *s == '+')		/*skip sign*/
		s++;
	for (n = 0; isdigit(*s); s++)
		n = 10 * n + *s - '0';
	return sign*n;
}


/*settab: set tab stops in array tab*/
/*
	数组tab中的每一个元素对应着文本行的一个位置，即，tab[1]对应着文本行的第一个位置，（pos=1）
	如果文本行的某一个位置出有一个制表符停止位，与之对应的tab[i]元素就将取值为YES,否则，与之对应的tab[i]元素就将取值为NO
*/
void settab(int argc, char * argv[], char * tab)
{
	int i, pos;
	if (argc <= 1)			/*default tab stops*/
		for (i = 1; i <= MAXLINE; i++)
			if (i % TABINC == 0)
				tab[i] == YES;
			else
				tab[i] == NO;

	else {					/*user provided tab stops*/
		for (i = 1; i <= MAXLINE; i++)
			tab[i] = NO;	/*turn off all tab stops*/
		while (--argc > 0) {
			pos = atoi(*++argv);
			if (pos > 0 && pos <= MAXLINE)
				tab[pos] = YES;
		}
	}
}

/*entab: replace strings of blanks with tabs and blanks*/
void entab(char *tab)
{
	int c, pos;
	int nb = 0;		/* # of blanks necessary*/
	int nt = 0;		/* # of tabs necessary*/

	for (pos = 1; (c = getchar()) != EOF;pos++)
		if (c == ' ') {
			if (tabpos(pos, tab) == NO)
				++nb;
			else {
				nb = 0;
				++nt;
			}
		}
		else {
			for (; nt > 0; nt--)
				putchar('\t');
			if (c == '\t')
				nb = 0;
			else
				for (; nb > 0; nb--)
					putchar(' ');
			putchar(c);
			if (c == '\n')
				pos = 0;
			else if (c == '\t')
				while (tabpos(pos, tab) != YES)
					++pos;
		}
}

/*tabpos: determine if pos is at a tab stop*/
int tabpos(int pos, char *tab)
{
	if (pos > MAXLINE)
		return YES;
	else
		return tab[pos];
}

