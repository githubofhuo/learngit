#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

/* 	
	把an,bn,k设为全局变量,an纪录第一个高精度数组的位数,
	bn纪录第二个高精度数组的位数,k纪录输出结果的位数
	fa,fb表示正负 
*/
int an, bn, fa=1, fb=1; 
/*	纪录需要计算的两个高精度数据  */
char b1[250], b2[250];
/*
	函数input为输入函数,用来纪录两个待计算的高精度数据,
	以数组首地址为参数.以实现返回两个高精度数据
*/  
void input(int a1[], int a2[])
{
	//a1[],a2[]顺序与b1[],b2[]相反 
	int i,ai=1,bi=1;
	scanf("%s%s", b1, b2);		//输入两个高精度数据
	an = strlen(b1);			//an记录b1的位数 
	bn = strlen(b2); 			//bn记录b2的位数
	
	//判断数组的符号 
	if(b1[0] == 45) {	//char(45) = '-' 
		an--;
		fa = -1;
		ai = 0;
	} 
	if(b2[0] == 45) {
		bn--;
		fb = -1;
		bi = 0;
	}
	for(i=0;i<an; i++,ai++) {
		a1[i] = b1[an-ai]-'0';
		printf("%d", a1[i]);
		/*把字符型数据b1转换为整数型数据,同样用数组记录*/		
	}
	for(i=0; i<bn; i++,bi++)
		a2[i] = b2[bn-bi]-'0';			/*同上*/
	return;
}

void addition(int a[], int b[], int q)	// 高精度加法运算
{
	int i,c[251]={0},k;
	if(fa * fb > 0 || q)
	{
		/*k记录结果的位数*/
		if(an > bn)
			k = an;
		else 
			k = bn;
		
		for(i=0; i<k; i++)
		{
			c[i] = a[i] + b[i] + c[i];
			c[i+1] = (int)(c[i]/10);
			c[i] = (int)(c[i] % 10);
		}	/*高精度加法计算过程*/
		
		if(c[k])		//判断最后结果的位数 
			k++;
		if(fa < 0 && q || fa < 0)
			printf("-");
		for(i=k-1; i>=0; i--)
			printf("%d",c[i]);
		return;	
	}
	else subtraction(a, b, 1);
	return;
} 

void subtraction(int a[], int b[], int q)		//高精度减法运算
{
	int i, f=0, c[251]={0}, k;
	if(fa * fb > 0 || q)
	{
		if(an > bn)
			k = an;
		else {
			k = bn;			//用k记录最大位数 
			for(i=k;a[i] <= b[i] && i >= 0; i--)
				if(a[i] < b[i])
					f=1;
		}
		
		if(!f)
		{
			for(i=0;i<k;i++)
			{
				a[i+1]--;
				a[i] += 10;
			}
			c[i] = a[i] - b[i];
		}
		else				//a<b
		{
			for(i=0;i<k;i++)
			{
				if(b[i] < a[i])
				{
					b[i+1]--;
					b[i] += 10;
				}
				c[i] = b[i] - a[i];
			}
		}
		while(!c[k-1] && k>1)		//判断位数,递减直到第一个不为0的位为止 
			k--;
		if(	q && (fa>0 && f || fa<0 && !f) || fa>0 && 
			(fb>0 && !f || f && !q))
			printf("-");
		return; 
		}
		else addition(a, b, 1);  	
} 

int main()
{
	return 0;
} 
