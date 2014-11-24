/*
 *	Author:zjj
 *	Date:2014/11/24 14:45 
 *  Desc:�Ŷ�OJ1517������һ����������������е�����k����㡣
	(hint: �����ʹ������)
 *  Method:ʹ������ָ��p,q�ֱ�ָ��������q�����ƶ�k��Ԫ�أ�֮��p,qͬʱ�ƶ�����q�ƶ�������ĩβʱ��
 	p�պ��ƶ���������K��Ԫ�� 
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

void countBackwardK(LinkNode *l,int k)
{
	LinkNode *p,*q;
	bool flag = true;	//��־�Ƿ���ڵ�����K��Ԫ�� 
	p = l;
	q = l;
	if(k==0) flag = false;
	/*��qָ��ָ��pָ������k��Ԫ��*/
	for(int i=0;i<k;i++)
	{
		if(q->next) q = q->next;
		else flag = false;
	}
	if(flag == true)
	{
		/*��q�ƶ�������ĩβʱ��pָ������k��Ԫ��*/ 
		while(q)
		{
			q = q->next;
			p = p->next;
		}
		printf("%d\n",p->data);
	}
	else
	{
		printf("NULL\n"); 
	}
}

int main()
{
	int n,k;
	LinkNode *l;
	while(scanf("%d %d",&n,&k)!=EOF)
	{
		initList(&l);
		createList(&l,n);
		countBackwardK(l,k); 
	}
	return 1;
}
/*
�������룺
5 2
1 2 3 4 5
1 0
5
���������
4
NULL
*/ 
