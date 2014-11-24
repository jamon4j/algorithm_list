/*
 *	Author:zjj
 *	Date:2014/11/24 15:40 
 *  Desc:�Ŷ�OJ1518����ת��������һ��������ת�����������������Ԫ�ء�
	(hint : �����ʹ������)
 *  Method:ͨ���ı�����ָ��ָ�򣬴ӵڶ���Ԫ�ؿ�ʼ����Ľ�Ԫ�ز��뵽����ĵ�һ��Ԫ�أ���ɷ�ת 
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
	LinkNode *rear = *l;
	LinkNode *node;
	/*β�巨����*/
	for(int i=0;i<n;i++)
	{
		scanf("%d",&data);
		node = (LinkNode*)malloc(sizeof(LinkNode));
		node->data = data;
		node->next = NULL;
		rear->next = node;
		rear = node;
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

void convertList(LinkNode **l)
{
	LinkNode *p,*q;
	/*�������Ԫ��С�ڵ���1��ֱ�ӷ���*/
	if((*l)->next==NULL) return;
	if((*l)->next->next==NULL) return;
	/*qָ��ָ��ǰ��Ҫ��ת��Ԫ��,pָ��ָ��qָ��ָ��Ԫ�ص�ǰһ��Ԫ��*/ 
	p = (*l)->next;
	q = p->next;
	/*�ı�����ָ�뷭ת����ÿ��ѭ����qָ���Ԫ�ط�ת����һ��Ԫ�أ��ٽ�qָ�����ת��Ԫ�أ�ֱ��qΪ��*/
	while(q)
	{
		p->next = q->next;
		q->next = (*l)->next;
		(*l)->next = q;
		q = p->next;
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
		convertList(&l); 
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
