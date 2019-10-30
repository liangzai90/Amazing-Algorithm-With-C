/*
数据结构趣题

在原表空间进行链表的归并

有两个按元素值递增有序排列的链表L1,L2，
编写一个程序将L1，L2，归并为一个按元素值递增有序的链表L3

要求：
1.链表中允许有相同元素，只要链表L1,L2,L3单调不减即可
2.要利用原表空间（即L1,L2,L3）的结点空间构造表L3.


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


typedef int  ElementType;

typedef struct node
{
	ElementType data;//数据域
	struct node* next;//指针域
}LNode,*LinkList;


LinkList CreateLink(int count)
{
	LinkList pNewNode = NULL;//新加入的元素
	LinkList pMove = NULL;////定义一个可移动的指针，用来串联各个元素
	LinkList list = NULL;//保存头结点指针
	ElementType numb;

	for (int i = 1; i <= count; i++)
	{
		scanf("%d", &numb);
		pNewNode = (LNode*)malloc(sizeof(LNode));
		pNewNode->data = numb;
		pNewNode->next = NULL;

		if (list == NULL)
		{
			list = pNewNode;//保存第1个结点的指针地址
		}
		else
		{
			pMove->next = pNewNode;
		}

		// pMove 串联起整个链表
		pMove = pNewNode;//在第一次创建的时候，r也指向了p，这就让后续所有 元素 都串联起来了
	}

	return list;
}

void PrintLink(LinkList list)
{
	printf("\r\nprintLinkList:");
	while (list != NULL)
	{
		printf("%3d,", list->data);
		list = list->next;
	}
	printf("\r\n");
}



//除非传入的是一个LinkList的引用，否则，必须传入LinkList*，指向指针的指针
// 函数参数，总是会把当前参数做一个拷贝，而且当前参数的修改是无意义的，跳出了函数，是不会生效的
// 因此，这里需要传入指针的指针，这样，函数就拷贝了指针的指针，但是我们在函数里面是修改的指针指向的值，，因此这里的修改会生效，跳出了函数依然生效
void inserNode(LinkList* list, ElementType data)
{
	LNode* p = (LNode*)malloc(sizeof(LNode));
	p->data = data;
	p->next = NULL;

	LinkList listTail = (*list);

	while (listTail != NULL && listTail->next != NULL)
	{
		listTail = listTail->next;
	}

	if ((*list) == NULL)
	{
		*list = p;
	}
	else
	{
		p->next = listTail->next;
		listTail->next = p;
	}
}




void destroyList(LinkList* list)
{
	while ((*list) != NULL)
	{
		LNode* p = (*list);
		(*list) = (*list)->next;
		free(p);
	}
	(*list) = NULL;
}

//合并2个链表，将1合并到2里面
void mergeTwoLinkList(LinkList* listOne, LinkList* listTwo)
{
	LinkList* listAHead = listOne;
	LinkList* listBHead = listTwo;
	LNode* nodeA = NULL;
	LNode* nodeB = NULL;
	LNode* nodeTemp = NULL;

	nodeA = (*listAHead);
	nodeB = (*listBHead);

	while (nodeA != NULL)
	{
		//头部插入元素
		if (nodeA->data <= nodeB->data)
		{
			nodeTemp = nodeA->next;
			
			nodeA->next = nodeB;//结点A加入到表头
			(*listBHead) = nodeA;//更新链表头
			nodeA = nodeTemp;//nodeA 往下移
			nodeB = (*listBHead);/////****此处记得修改nodeB的值
		}
		else
		{			
			if (nodeB->next == NULL)
			{
				//直接插入后面所有元素
				nodeB->next = nodeA;
				break;//退出while循环，否则会死循环
			}
			else
			{ 				
      ///寻找nodeA插入的位置,就是nodeB->next的地方
				while (nodeB->next != NULL)
				{
					if (nodeA->data > nodeB->next->data)
					{
						nodeB = nodeB->next;
					}
					else
					{
						break;//退出while循环，否则会死循环
					}
				}

				if (nodeB->next != NULL)
				{
					//在nodeB之后插入NodeA
					nodeTemp = nodeA->next;
					nodeA->next = nodeB->next;
					nodeB->next = nodeA;
					nodeA = nodeTemp;
					nodeB = nodeB->next;
				}
				else
				{
					//直接插入后面所有元素
					nodeB->next = nodeA;
					break;//退出while循环，否则会死循环
				}
			}
		}
	}
}

int main()
{	
	LinkList listOne = NULL;
	LinkList listTwo = NULL;

	listOne = CreateLink(8);
	PrintLink(listOne);

	printf("Please input some integer.and type 0 for end. \r\n");
	int n;
	scanf("%d", &n);
	while (n)
	{
		inserNode(&listTwo, n);
		scanf("%d", &n);
	}
	PrintLink(listTwo);


	mergeTwoLinkList(&listOne, &listTwo);
	
	PrintLink(listTwo);




	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


