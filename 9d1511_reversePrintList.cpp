/*
 *	Author:zjj
 *	Date:2014/11/16 9:32
 *  Desc:�Ŷ�OJ1511,����һ��������β��ͷ��ӡ����ÿ���ڵ��ֵ�� 
 *  Method:ʹ��ջ���洢�����˳��������ٽ�ջ��� 
 */


#include<stdio.h>
#include<stdlib.h>
#include<stack>

using namespace std;
typedef struct Node
{
	struct Node* next;
	int data;	
}LNode,*LinkList;

void createList(LinkList &L)
{
	int data;
	LNode *p,*tail;
	p = NULL;
	tail = L;
	while(scanf("%d",&data)!=EOF)
	{
		if(data==-1)
		{
			break;			
		}
		
		p = (LNode*)malloc(sizeof(LNode));
		p->data = data;
		p->next = NULL;
		tail->next = p;
		tail = p;
	}		
}

void printList(LinkList L)
{
	LNode *p;
	stack<int> s;
	p = L->next;
	while(p)
	{
		s.push(p->data);
		p = p->next;
	}
	
	while(!s.empty())
	{
		printf("%d\n",s.top());
		s.pop();
	}
}

int main()
{
	LinkList L; 
	L = (LinkList)malloc(sizeof(LNode));
	L->next = NULL;
	L->data = -1;
	
	createList(L);
	printList(L);
}

/*
1
2
3
4
5
-1
*/
