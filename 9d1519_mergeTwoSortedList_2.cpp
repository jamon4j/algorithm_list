/*
 *	Author:zjj
 *	Date:2014/11/24 16:27
 *  Desc:�Ŷ�OJ1519���ϲ�����������������������������������������������ϳɺ������
 		��Ȼ������Ҫ�ϳɺ���������㵥����������(hint: �����ʹ������)
 *  Method:���ǿ��Ըı�ԭ�е���������������£���������Ҫ����ռ䣬ֱ��ʹ��ԭ�����㼴�� 
 		ͨ�����ϱȽ���������Ԫ�ز������½ڵ����������
 		ע�⿼�ǵ�����ֱ�Ϊ�գ��Լ�һ���������һ��δ���������� 
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

LinkNode* mergeList(LinkNode *l1,LinkNode *l2)
{
	LinkNode *l = NULL;
	LinkNode *p,*q;
	LinkNode *rear;
	if(l1->next == NULL) l = l2;
	else if(l2->next == NULL) l = l1;
	else 
	{
		p = l1->next;
		q = l2->next;
		initList(&l);
		rear = l;
		while(p&&q)
		{
			if(p->data<=q->data) 
			{
				rear->next = p;
				rear = p;
				p = p->next;
			}
			else 
			{
				rear->next = q;
				rear = q;
				q = q->next;
			}
		}
		/*������l1δ�����꣬��l1ʣ��Ԫ��ֱ�Ӽ��뵽�±�*/ 
		if(p!=NULL) rear->next = p; 
		/*������l2δ�����꣬��l2ʣ��Ԫ��ֱ�Ӽ��뵽�±�*/ 
		if(q!=NULL) rear->next = q; 
	}
	return l;
}

int main()
{
	int n,m;
	LinkNode *l1,*l2;
	LinkNode *l;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		initList(&l1);
		initList(&l2);
		createList(&l1,n);
		createList(&l2,m);
		l = mergeList(l1,l2); 
		printList(l);
	}
	return 1;
}
/*
�������룺
5 2
1 3 5 7 9
2 4
0 0
���������
1 2 3 4 5 7 9
NULL
*/ 
