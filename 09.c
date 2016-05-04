#include<stdio.h>
#include<ctype.h>
#include<string.h>
#define MAXWORD 100

struct key {
	char *word;
	int count;
} keytab[] = {
	"break",0,
	"case",0,
	"char",0,
	"const",0,
	"continue",0,
	"unsigned",0,
	"void",0,
	"while",0
};
#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))

#define BUFSIZE 100
char buf[BUFSIZE];
int bufp=0;

int getch(void)
{
	return (bufp>0)?buf[--bufp]: getchar();
}
void ungetch(int c)
{
	if(bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++]=c;
}

//getword: 从输入中读取下一个单词或字符
int getword(char *word,int lim)
{
	int c,getch(void);
	void ungetch(int);
	char *w=word;

	while(isspace(c=getch()))
		;
	if(c != EOF)
		*w++ = c;
	if(!isalpha(c)) {
		*w = '\0';
		return c;
	}
	for(;--lim>0;w++) {
		if(!isalnum(*w=getch())) {
			ungetch(*w);
			break;
		}
	}
	*w = '\0';
	return word[0];
}

int getword(char *word,int lim);
struct key *binsearch(char *word,struct key *keytab[],int n);

int main()
{
	char word[MAXWORD];
	struct key *p;

	while(getword(word,MAXWORD) != EOF) {
		if(isalpha(word[0]))
			if((p=binsearch(word,keytab,NKEYS)) != NULL)
				p->count++;
	}
	for(p=keytab;p<keytab+NKEYS;p++)
		if(p->count > 0)
			printf("%4d %s\n",p->count,p->word);

	return 0;
}

//binsearch: 在keytab[0]到keytab[n-1]中查找与读入单词匹配的元素
struct key *binsearch(char *word,struct key *keytab[],int n)
{
	int cond;
	struct key *low = &keytab[0];
	struct key *high = &keytab[n];
	struct key *mid;

	while(low<high) {
		mid = low+(high-low)/2;
		if((cond = strcmp(word,mid->word)) < 0)
			high = mid;
		else if(cond>0)
			low = mid-1;
		else
			return mid;
	}
	return NULL;
}
