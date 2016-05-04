#include<stdio.h>
#include<string.h>

#define MAXLINES 5000		/*�������������ı�����*/

char *lineptr[MAXLINES];	/*ָ���ı��е�ָ������*/

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/*��������ı��н�������*/
int main()
{
	int nlines;		/*��ȡ����������Ŀ*/
	
	if((nlines = readlines(lineptr, MAXLINES)) > 0) {
		qsort(lineptr, 0, nlines-1);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: input too big to sort.\n");
		return 1;
	}
}

#define MAXLEN 1000  	/*ÿ�������ı��е���󳤶�*/
int getline(char *, int);
char *alloc(int);

/*readlines: ��ȡ������*/ 
int readlines(char *lineptr[], int maxlines)
{
	int len, nlines;
	char *p, line[MAXLEN];
	nlines=0;
	
	while((len = getline(line, MAXLEN)) > 0) {
		if(nlines >= maxlines || (p=alloc(len)) == NULL)
			return -1;
		else {
			line[len-1] = '\0';		/*ɾ�����з�*/
			strcpy(p, line);
			lineptr[nlines++] = p; 
		}
	}
	return nlines;
}

/*writelines: д�����*/
void writelines(char *lineptr[], int nlines)
{
	int i;
	
	for(i=0; i<nlines; i++)
		printf("%s\n", lineptr[i]);
}

/*
void writelines(char *lineptr[], int nlines)
{
	while(nlines-- > 0)
		printf("%s\n", *lineptr++);
}
*/


/*getline: ��һ�ж��뵽s�в������䳤��*/
int getline(char s[], int lim) 
{
	int c,i;
	
	for(i=0;i<lim-1 && (c=getchar()) != EOF && c != '\n';i++) {
		s[i]=c;
	}
	if(c=='\n') {
		s[i] = c;
		i++;
	}
	s[i] = '\0';
	return i;
}

/*swap: ����v[i]��v[j]*/
void swap(char *v[], int i, int j)
{
	char *temp;
	
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

/*qsort: ������˳���v[left],...,v[right]��������*/
void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);
	
	if(left >= right)	/*�������Ԫ�صĸ���С��2���򷵻�*/
		return;
	swap(v, left, (left + right)/2);
	last = left;
	for(i=left+1;i <= right; i++)
		if(strcmp(v[i],v[left]) < 0)
			swap(v, ++last, i);
	
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right); 
} 

//int strcmp(const char *dest, const char *source)
//{
//	assert((NULL != dest) && (NULL != source));
//	while(*dest && *source && (*dest == *source)) {
//		dest++;
//		source++;
//	}
//	return *dest - *source;
//	/*
//		���dest > source,�򷵻�ֵ����0��
//		���dest = source,�򷵻�ֵ����0��
//		���dest  < source ,�򷵻�ֵС��0��
//	*/  
//}

/*alloc and afree*/
#define ALLOCSIZE 10000		/*���ÿռ��С*/
static char allocbuf[ALLOCSIZE];	/*allocʹ�õĴ洢��*/
static char *allocp = allocbuf;		/*��һ������λ��*/

char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp-n;		//���ط���ǰ��ָ�� 
	} else
		return 0; 
} 

void afree(char *p)
{
	if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
		allocp = p;
}
