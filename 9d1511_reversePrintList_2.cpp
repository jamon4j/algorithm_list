/*
 *	Author:zjj
 *	Date:2014/11/16 9:32
 *  Desc:九度OJ1511,输入一个链表，从尾到头打印链表每个节点的值。 
 *  Method: 递归输出链表 
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
	LNode *tail;
	tail = L; 
	while(scanf("%d",&data)!=EOF)
	{
		if(data == -1) break;
		p = (LNode*)malloc(sizeof(LNode));
		p->data = data;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}	
}

void printList(LNode *p)
{
	if(p->next) printList(p->next);
	printf("%d\n",p->data);
}

int main()
{
	LinkList L;
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = -1;
	
	createList(L);
	if(L->next != NULL)
	{
		printList(L->next);
	}	
	return 1;
}

