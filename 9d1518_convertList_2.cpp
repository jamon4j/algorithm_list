/*
 *	Author:zjj
 *	Date:2014/11/24 15:40 
 *  Desc:九度OJ1518：反转链表，输入一个链表，反转链表后，输出链表的所有元素。
	(hint : 请务必使用链表)
 *  Method:通过改变链表指针指向，从第二个元素开始逐个的将元素插入到链表的第一个元素，完成翻转 
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

void convertList(LinkNode **l)
{
	LinkNode *p,*q;
	/*如果链表元素小于等于1则直接返回*/
	if((*l)->next==NULL) return;
	if((*l)->next->next==NULL) return;
	/*q指针指向当前需要翻转的元素,p指针指向q指针指向元素的前一个元素*/ 
	p = (*l)->next;
	q = p->next;
	/*改变链表指针翻转链表，每次循环将q指向的元素翻转到第一个元素，再将q指向待翻转的元素，直至q为空*/
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
样例输入：
5
1 2 3 4 5
0
样例输出：
5 4 3 2 1
NULL
*/ 
