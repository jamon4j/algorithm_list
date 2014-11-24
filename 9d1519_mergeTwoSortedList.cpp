/*
 *	Author:zjj
 *	Date:2014/11/24 16:27
 *  Desc:九度OJ1519：合并两个排序的链表，输入两个单调递增的链表，输出两个链表合成后的链表，
 		当然我们需要合成后的链表满足单调不减规则。(hint: 请务必使用链表。)
 *  Method:考虑不改变原有的两个链表的条件下，新链表需要申请空间，
 		通过不断比较两个链表元素并创建新节点加入新链表
 		注意考虑到两表分别为空，以及一表插入完另一表未插入完的情况 
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
	LinkNode *rear,*node;;
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
			node = (LinkNode*)malloc(sizeof(LinkNode));
			if(p->data<=q->data) 
			{
				node->data = p->data;
				p = p->next;
			}
			else 
			{
				node->data = q->data; 
				q = q->next;
			}
			node->next = NULL;
			rear->next = node;
			rear = node; 
		}
		/*若链表l1未插入完，将l1剩余元素直接加入到新表*/ 
		while(p!=NULL) 
		{
			node = (LinkNode*)malloc(sizeof(LinkNode));			
			node->data = p->data;			
			node->next = NULL;
			rear->next = node;
			rear = node; 
			p = p->next;
		}
		/*若链表l2未插入完，将l2剩余元素直接加入到新表*/ 
		while(q!=NULL) 
		{
			node = (LinkNode*)malloc(sizeof(LinkNode));			
			node->data = q->data;			
			node->next = NULL;
			rear->next = node;
			rear = node; 
			q = q->next;
		}
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
样例输入：
5 2
1 3 5 7 9
2 4
0 0
样例输出：
1 2 3 4 5 7 9
NULL
*/ 
