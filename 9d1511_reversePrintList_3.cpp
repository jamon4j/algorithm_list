/*
 *	Author:zjj
 *	Date:2014/11/16 9:32
 *  Desc:�Ŷ�OJ1511,����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ�� 
 *  Method: ͷ�巨�������ı�������Ľṹ�� 
 */
 
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	struct Node *next;
	int data;
}LNode,*LinkList;

void createList(LinkList &L)
{
	int data;
	LNode *p = NULL;
	while(scanf("%d",&data)!=EOF)
	{
		if(data == -1) break;
		p = (LNode*)malloc(sizeof(LNode));
		p->data = data;
		p->next = L->next;
		L->next = p;
	}	
}

void printList(LNode *p)
{
	while(p)
	{
		printf("%d\n",p->data);
		p = p->next;
	}
}

int main()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = -1;
	
	createList(L);
	printList(L->next);	
	return 1;
}

