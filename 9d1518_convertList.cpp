/*
 *	Author:zjj
 *	Date:2014/11/24 15:40 
 *  Desc:九度OJ1518：反转链表，输入一个链表，反转链表后，输出链表的所有元素。
	(hint : 请务必使用链表)
 *  Method:如果考虑可以改变链表结构的，使用头插法建表，再输出即可 
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
	/*头插法建表*/ 
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
样例输入：
5
1 2 3 4 5
0
样例输出：
5 4 3 2 1
NULL
*/ 
