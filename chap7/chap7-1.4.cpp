/*
数据结构趣题

约舍夫环
编号为1,2,3，...，n 的n个人按顺时针方向围坐一圈，每个人手中持有一个密码。
开始时任选一个正整数作为报数的上限m，
从第1个人开始按顺时针方向自1开始顺序报数，报到m停止。
报m的人出列，将他手中的密码作为新的报数上限m，
从他在顺时针方向上的下一个人开始重新从1开始报数，
如此循环报数下去，求最后剩下的那个人的最初编号是多少。


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

//链表结点定义
typedef struct node{
	int number;//编号
	int psw;//个人密码
	struct node *next;
}LNode,*LinkList;


//向链表list中q指向的结点后面插入一个新结点，数据域值为 e1,e2
void insertList(LinkList* list, LinkList q, int e1, int e2)
{
	LinkList p;
	p = (LinkList)malloc(sizeof(LNode));
	p->number = e1;
	p->psw = e2;
	p->next = NULL;
	if (!(*list))
	{
		*list = p;
	}
	else
	{
		p->next = q->next;
		q->next = p;  //结点q后面插入结点p
	}
}


//创建约舍夫环
void CreateJoseph(LinkList* jsp, int n)
{
	LinkList q = NULL, list = NULL;
	int e;
	printf("Please input the password for people in the joseph cicle \r\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &e);
		//q指向链表最后一个结点
		insertList(&list, q, i + 1, e);
		if (0 == i)
		{
			q = list;//初始是指向表头的第1个结点
		}
		else
		{
			q = q->next;//后移指针，指向表尾
		}
	}
	//形成循环链表
	q->next =list;
	*jsp = list;
}


void exJoseph(LinkList* jsp, int m)
{
	LinkList p, q;
	q = p = (*jsp);
	while (q->next!=p)
	{
		q = q->next;//q指向p的前一个结点。。。注意这里是while循环的！！！ q 结点走了一圈了
	}
	printf("The order of a column is \r\n");
	while (p->next != p)
	{
		for (int i = 0; i < m - 1; i++)
		{
			//p指向要删除的结点，q指向p的前一个结点
			q = p;
			p = p->next;
		}
		//删除p指向的结点
		q->next = p->next;
		printf("%3d,", p->number);//打印出"出列"的顺序
		m = p->psw;//重置报数上限
		free(p);
		p = q->next;
	}
	printf("\r\nThe last person in the circle is:%d \r\n", p->number);
}


int main()
{	
	LinkList jsp;
	int n, m;
	printf("Please input number of the people in the Joseph circle.\r\n");
	scanf("%d", &n);//输入约瑟夫环的人数
	CreateJoseph(&jsp, n);//创建约瑟夫环
	printf("Please input the first maxinum number \r\n");
	scanf("%d", &m);// 输入第1次的报数上限
	exJoseph(&jsp, m);

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input number of the people in the Joseph circle.
7
Please input the password for people in the joseph cicle
3 1 7 2 4 8 4
Please input the first maxinum number
6
The order of a column is
6,  1,  4,  7,  2,  3,
The last person in the circle is:5




*/
