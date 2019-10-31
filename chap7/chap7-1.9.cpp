/*
数据结构趣题

动态双向链表
设有一个双向链表，每个结点中除了有prior,data和next这3个域外，还有一个访问频度域freq。
在该双向链表启用之前，频度freq的值全部初始化为0，每当链表进行一次访问时，被访问的结点的频度域freq就自动增加1，
同时调整链表中结点之间的次序，使其按照被访问频度非递增的次序顺序排列，
以便始终保持经常被访问的结点总是靠近表头的位置。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <malloc.h>
using namespace std;

//定义双向链表类型
typedef struct node
{
	int data;
	int freq;
	struct node* prior;
	struct node* next;
}dbLNode,*dbLinkList;
 
//创建一个双向链表，返回它的头指针
dbLinkList CreatedbLinkList(int n)
{
	dbLinkList p=NULL, r=NULL, list = NULL;
	int e = 0;
	list = (dbLinkList)malloc(sizeof(dbLNode));
	list->next = list->prior = NULL;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &e);
		p = (dbLinkList)malloc(sizeof(dbLNode));
		p->data = e;
		p->freq = 0;
		p->next = NULL;
		p->prior = NULL;
		if (!list->next)
		{
			list->next = p;//第一个节点
			p->prior = list;
		}
		else
		{
			r->next = p;
			p->prior = r;
		}

		//要深刻理解这里的【指针 串联】所有结点的含义****
		r = p; // 第1个结点创建的时候，r指向了p.r是从第1个结点开始的，然后串联起所有的结点...
	}
	return list;
}


//访问双向链表中指定的结点，并调整结点次序
void visit(dbLinkList *List, int x)
{
	dbLinkList p = *List, q, r, s;
	p = p->next;//p指向第一个节点
	while (p->data != x)
	{
		p = p->next;//通过循环找到指定结点
	}
	if (NULL == p)
	{
		printf("Input error! \r\n");
		return;
	}
	p->freq++;
	printf("Visiting this node \r\n");
	while ((p->prior != *List) && p->freq > p->prior->freq)
	{
		//实现双向链表结点的交换
		q = p->prior;
		r = p->next;
		s = p->prior->prior;
		p->prior = q->prior;
		p->next = q;
		q->prior = p;
		q->next = r;

		if (r != NULL)
		{
			r->prior = q;
		}
		s->next = p;
	}
}

//遍历整个双向链表，并打印出每个结点中的数据和访问频度
void TransdbLinkList(dbLinkList list)
{
	list = list->next;
	while (list != NULL)
	{
		printf("(data:%d,freq:%d)-->", list->data, list->freq);
		list = list->next;
	}

	printf("\r\n");
}


int main()
{
	dbLinkList list;
	int d;
	printf("Input five integer to create a doubly link list.\r\n");

	//创建一个包含5个元素，6个结点的双向链表
	list = CreatedbLinkList(5);
	TransdbLinkList(list);//遍历双向链表，打印出每个结点中的数据和访问频度

	printf("Please input the data that you want to visit. enter 0 to end. \r\n");
	scanf("%d", &d);
	while (d != 0)
	{
		visit(&list, d);
		TransdbLinkList(list);
		scanf("%d", &d);
	}


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*






*/
