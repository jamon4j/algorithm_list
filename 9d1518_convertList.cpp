/*
 *	Author:zjj
 *	Date:2014/11/24 15:40 
 *  Desc:�Ŷ�OJ1518����ת��������һ��������ת�����������������Ԫ�ء�
	(hint : �����ʹ������)
 *  Method:������ǿ��Ըı�����ṹ�ģ�ʹ��ͷ�巨������������� 
 */
 
#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int data;
	struct Node *next;	
}LinkNode;

void initList(LinkNode **l)
{
	*l = (LinkNode*)malloc(sizeof(LinkNode));
	(*l)->next = NULL;
}

void createList(LinkNode **l,int n)
{
	int data;
	LinkNode *node;
	/*ͷ�巨����*/ 
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		node = (LinkNode*)malloc(sizeof(LinkNode));
		node->data = data;
		node->next = (*l)->next;
		(*l)->next = node;
	}
}

void printList(LinkNode *l)
{
	LinkNode *p = l->next;
	if(p == NULL) printf("NULL\n");
	else
	{
		while(p)
		{
			if(p->next) printf("%d ",p->data);
			else printf("%d\n",p->data);
			p = p->next;
		}
	}
}

int main()
{
	int n;
	LinkNode *l;
	while(scanf("%d",&n)!=EOF)
	{
		initList(&l);
		createList(&l,n);
		printList(l);
	}
	return 1;
}
/*
�������룺
5
1 2 3 4 5
0
���������
5 4 3 2 1
NULL
*/ 
