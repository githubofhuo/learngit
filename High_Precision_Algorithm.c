#include<stdio.h>
#include<string.h>
#include<math.h>
#include<malloc.h>

/* 	
	��an,bn,k��Ϊȫ�ֱ���,an��¼��һ���߾��������λ��,
	bn��¼�ڶ����߾��������λ��,k��¼��������λ��
	fa,fb��ʾ���� 
*/
int an, bn, fa=1, fb=1; 
/*	��¼��Ҫ����������߾�������  */
char b1[250], b2[250];
/*
	����inputΪ���뺯��,������¼����������ĸ߾�������,
	�������׵�ַΪ����.��ʵ�ַ��������߾�������
*/  
void input(int a1[], int a2[])
{
	//a1[],a2[]˳����b1[],b2[]�෴ 
	int i,ai=1,bi=1;
	scanf("%s%s", b1, b2);		//���������߾�������
	an = strlen(b1);			//an��¼b1��λ�� 
	bn = strlen(b2); 			//bn��¼b2��λ��
	
	//�ж�����ķ��� 
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
		/*���ַ�������b1ת��Ϊ����������,ͬ���������¼*/		
	}
	for(i=0; i<bn; i++,bi++)
		a2[i] = b2[bn-bi]-'0';			/*ͬ��*/
	return;
}

void addition(int a[], int b[], int q)	// �߾��ȼӷ�����
{
	int i,c[251]={0},k;
	if(fa * fb > 0 || q)
	{
		/*k��¼�����λ��*/
		if(an > bn)
			k = an;
		else 
			k = bn;
		
		for(i=0; i<k; i++)
		{
			c[i] = a[i] + b[i] + c[i];
			c[i+1] = (int)(c[i]/10);
			c[i] = (int)(c[i] % 10);
		}	/*�߾��ȼӷ��������*/
		
		if(c[k])		//�ж��������λ�� 
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

void subtraction(int a[], int b[], int q)		//�߾��ȼ�������
{
	int i, f=0, c[251]={0}, k;
	if(fa * fb > 0 || q)
	{
		if(an > bn)
			k = an;
		else {
			k = bn;			//��k��¼���λ�� 
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
		while(!c[k-1] && k>1)		//�ж�λ��,�ݼ�ֱ����һ����Ϊ0��λΪֹ 
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
