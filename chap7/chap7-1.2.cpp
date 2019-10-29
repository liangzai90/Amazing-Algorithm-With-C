/*

数学趣题(=)

动态数列排序

编写一个C程序，实现这样的功能：
从键盘输入任意个整数，以0作为结束标志，
对这个整数序列从小到达排序，并输出排序后的结果


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

//定义int为ElemType类型
typedef int ElemType;

//定义链表的结点类型
typedef struct node
{
	ElemType  data;//数据域
	struct node* next;//指针域
}LNode,*LinkList;

//创建一个长度为n的链表，并输入数据
LinkList CreateLinkList(int n)
{
	LinkList p=NULL, r=NULL, list = NULL;
	ElemType e;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &e);
		p = (LinkList)malloc(sizeof(LNode));
		p->data = e;
		p->next = NULL;

		if (!list)
		{
			list = p;
		}
		else
		{
			r->next = p;
		}
		r = p;//r是一个移动的指针，相当于 r = r->next，往后移动.串联起所有输入的p元素.
	}
	return list;
}

//向链表中插入结点，并向该结点的数据域中存放数据e
void insertList(LinkList* list, LinkList q, ElemType e)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->data = e;
	if (!*list)
	{
		*list = p;
		p->next = NULL;
	}
	else
	{
		p->next = q->next;
		q->next = p;//p结点插入在q结点之后
	}
}

//销毁链表
void destroyLinkList(LinkList* list)
{
	LinkList p, q;
	p = *list;
	while (p)
	{
		q = p->next;
		free(p);
		p = q;
	}
	*list = NULL;
}


//基于链表的冒泡排序算法
void Sort(LinkList q)
{
	LNode* p = q;
	int k = 0;
	int t = 0;
	while (p)
	{
		k++;
		p = p->next;//计算出链表长度
	}

	p = q;//重新给p指针赋值，重新指向链表表头
	for (int i = 0; i < k - 1; i++)
	{
		for (int j = 0; j < k - 1 - i; j++)
		{
			if (p->data > p->next->data)
			{
				t = p->data;
				p->data = p->next->data; //交换链表结点中的数据内容
				p->next->data = t;
			}
			p = p->next;
		}

		p = q;//链表真是麻烦，，很容易就错掉了
	}
}


//打印出排序后的新链表的内容
void printLink(LinkList q)
{
	while (q)
	{
		printf("%3d,", q->data);
		q = q->next;
	}
}


int main()
{	
	ElemType  e;
	LinkList list, q;//定义链表list
	printf("Please input some integer digit and type 0 for end.\r\n");
	q = list = CreateLinkList(1);//创建一个链表结点，q,list都指向该结点
	scanf("%d", &e);
	while (e)
	{
		insertList(&list, q, e);
		q = q->next;
		scanf("%d", &e);
	}

	Sort(list);
	printLink(list);
	destroyLinkList(&list);


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


