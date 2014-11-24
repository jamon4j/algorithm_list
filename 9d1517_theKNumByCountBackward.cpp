/*
 *	Author:zjj
 *	Date:2014/11/24 14:45 
 *  Desc:九度OJ1517：输入一个链表，输出该链表中倒数第k个结点。
	(hint: 请务必使用链表。)
 *  Method:使用两个指针p,q分别指向链表，令q往后移动k个元素，之后p,q同时移动，当q移动到链表末尾时，
 	p刚好移动到倒数第K个元素 
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

void countBackwardK(LinkNode *l,int k)
{
	LinkNode *p,*q;
	bool flag = true;	//标志是否存在倒数第K个元素 
	p = l;
	q = l;
	if(k==0) flag = false;
	/*让q指针指向p指针后面第k个元素*/
	for(int i=0;i<k;i++)
	{
		if(q->next) q = q->next;
		else flag = false;
	}
	if(flag == true)
	{
		/*当q移动到链表末尾时，p指向倒数第k个元素*/ 
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
样例输入：
5 2
1 2 3 4 5
1 0
5
样例输出：
4
NULL
*/ 
