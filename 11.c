#include<stdio.h>
#include<stdlib.h>

struct student {
	int num;
	float score;
	struct student *pstrnext;
};

//��������
struct student *create()
{
	struct student *pstrstuhead=0,*pstrstutemp,*pstrstutail=0;
	int numtemp;
	float scoretemp;
	printf("input num and score(>=0, <0): \n");
	scanf("%d",&numtemp);
	scanf("%f",&scoretemp);
	//��ӽڵ㣬������ɼ�ֵΪ����ʱ����
	while(scoretemp>0) {
		//�����㲢�������ݣ�����ָ����Ϊ�㣬��Ϊ�½ڵ㽫��Ϊ���һ�����
		pstrstutemp=(struct student *)malloc(sizeof(struct student));
		pstrstutemp->num = numtemp;
		pstrstutemp->score = scoretemp;
		pstrstutemp->pstrnext=0;
	//��������
	if(!pstrstuhead)
		//�����һ����㣬ͷָ�롢βָ���ָ��ý��
		pstrstuhead = pstrstutail = pstrstutemp;
	else {
		//����ǵ�һ�����
		pstrstutail->pstrnext=pstrstutemp;
		pstrstutail = pstrstutemp;
	}
	printf("input num and score(>=0, 0<): \n");
	scanf("%d",&numtemp);
	scanf("%f",&scoretemp);
	}
	return pstrstuhead;
}

//�������
void list(struct student *pstrstuhead)
{
	while(pstrstuhead) {
		printf("%d\t%f\t\n",pstrstuhead->num,pstrstuhead->score);
		pstrstuhead = pstrstuhead->pstrnext;
	}
}

//���ҽ��
struct student *search(struct student *pstrstutemp,float scoretemp)
{
	while(pstrstutemp) {
		if(pstrstutemp->score == scoretemp)
			break;
		pstrstutemp = pstrstutemp->pstrnext;
	}
	return pstrstutemp;
}

int main()
{
	struct student strstutemp;
	struct student *pstrstuhead,*pstrsturesualt;
	float scoretemp;
	int numtemp;
	//��������
	pstrstuhead = create();
	//����������еĽ��
	list(pstrstuhead);
	//����Ҫ���ҵĳɼ���Ȼ�󷵻��ҵ��Ľڵ�ĵ�ַ���Ҳ������ؿ�
	printf("input search score:\n");
	scanf("%f",&scoretemp);
	pstrsturesualt = search(pstrstuhead,scoretemp);
	if(pstrsturesualt)
		printf("num=%d,score=%f\n",pstrsturesualt->num,pstrsturesualt->score);
	else
		printf("not found!");

	return 0;
}
