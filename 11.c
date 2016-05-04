#include<stdio.h>
#include<stdlib.h>

struct student {
	int num;
	float score;
	struct student *pstrnext;
};

//创建链表
struct student *create()
{
	struct student *pstrstuhead=0,*pstrstutemp,*pstrstutail=0;
	int numtemp;
	float scoretemp;
	printf("input num and score(>=0, <0): \n");
	scanf("%d",&numtemp);
	scanf("%f",&scoretemp);
	//添加节点，当输入成绩值为负数时结束
	while(scoretemp>0) {
		//申请结点并填入数据，结点的指针与为零，因为新节点将作为最后一个结点
		pstrstutemp=(struct student *)malloc(sizeof(struct student));
		pstrstutemp->num = numtemp;
		pstrstutemp->score = scoretemp;
		pstrstutemp->pstrnext=0;
	//接入链表
	if(!pstrstuhead)
		//接入第一个结点，头指针、尾指针均指向该结点
		pstrstuhead = pstrstutail = pstrstutemp;
	else {
		//接入非第一个结点
		pstrstutail->pstrnext=pstrstutemp;
		pstrstutail = pstrstutemp;
	}
	printf("input num and score(>=0, 0<): \n");
	scanf("%d",&numtemp);
	scanf("%f",&scoretemp);
	}
	return pstrstuhead;
}

//输出链表
void list(struct student *pstrstuhead)
{
	while(pstrstuhead) {
		printf("%d\t%f\t\n",pstrstuhead->num,pstrstuhead->score);
		pstrstuhead = pstrstuhead->pstrnext;
	}
}

//查找结点
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
	//创建链表
	pstrstuhead = create();
	//输出链表所有的结点
	list(pstrstuhead);
	//输入要查找的成绩，然后返回找到的节点的地址，找不到返回空
	printf("input search score:\n");
	scanf("%f",&scoretemp);
	pstrsturesualt = search(pstrstuhead,scoretemp);
	if(pstrsturesualt)
		printf("num=%d,score=%f\n",pstrsturesualt->num,pstrsturesualt->score);
	else
		printf("not found!");

	return 0;
}
