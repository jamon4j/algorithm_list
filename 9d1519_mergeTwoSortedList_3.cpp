/*
 *	Author:zjj
 *	Date:2014/11/24 16:27
 *  Desc:九度OJ1519：合并两个排序的链表，输入两个单调递增的链表，输出两个链表合成后的链表，
 		当然我们需要合成后的链表满足单调不减规则。(hint: 请务必使用链表。)
 *  Method:递归实现合并链表 
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
	/*尾插法建表*/
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
	LinkNode *p = l;
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
	if(l1 == NULL) return l2;
	if(l2 == NULL) return l1;
	LinkNode *l = NULL;
	if(l1->data<=l2->data) 
	{
		l = l1;
		l->next = mergeList(l1->next,l2);
	}
	else 
	{
		l = l2;
		l->next = mergeList(l1,l2->next);
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
		l = mergeList(l1->next,l2->next); 
		printList(l);
	}
	return 1;
}
/*
样例输入：
5 2
1 3 5 7 9
2 4
0 0
样例输出：
1 2 3 4 5 7 9
NULL
*/ 
