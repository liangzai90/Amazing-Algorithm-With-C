/*
数据结构趣题

打印符号三角形

第一行决定了下面的行
两个相同的符号，则推导出下面一行是 + ，否则是 -


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


//定义队列结点类
typedef struct QNode
{
	char data;
	struct QNode *next;
}QNode, *QueuePtr;

//定义一个链队列
typedef struct
{
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//初始化一个空队列
void initQueue(LinkQueue *q)
{
	//头尾指针起始地址相同。然后从这个地址往后陆续添加其他节点。
	//添加节点过程中，front保持不动，rear往后移动...
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)  exit(0);
	q->front->next = NULL;
	q->front->data = 66;
}

void EnQueue(LinkQueue *q, char e)
{
	//创建一个队列元素节点
	QueuePtr p= (QueuePtr)malloc(sizeof(QNode));
	if (!q->front) exit(0);

	p->data = e;
	p->next = NULL;
	//修改队尾指针
	q->rear->next = p;
	q->rear = p;
}

//如果队列q不为空，删除q的队头元素，用e返回其值
void DeQueue(LinkQueue *q, char *e)
{
	QueuePtr p=NULL;
	if (q->front == q->rear) return;//队列为空，返回
	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;

	//队列只剩下一个元素的时候，front->next和rear都指向这个元素.
	//如果队头就是队尾，则修改队尾指针
	if (q->rear == p) q->rear = q->front;

	free(p);
}

void printTriangle(int n)
{
	LinkQueue q;
	char e, a, b;
	//初始化队列
	initQueue(&q);
	printf("Input the charecter(+/-) of the row.1 \n");
	
	for (int i = 0; i < n; i++)
	{
		scanf("%c", &e);
		EnQueue(&q, e);
	}

	printf("The charecter triangle is like:\r\n");
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			printf(" ");//控制输出格式，打印成倒三角形状
		}
		//出队列，打印每行的第一个符号
		DeQueue(&q, &a);
		printf("%2c", a);

		//控制输出每一行，第i行输出n-i个符号
		for (int j = 0; j < n - i-1; j++)
		{
			DeQueue(&q, &b);//出队列
			printf("%2c", b);
			if (a == b)
			{
				EnQueue(&q, '+');//向队尾插入新元素
			}
			else
			{
				EnQueue(&q, '-');
			}
			a = b;
		}
		printf("\r\n");
	}
}



int main()
{
	int n;
	printf("Please input the number of '+' or '-' of the row.1 \r\n");
	scanf("%d", &n);

	getchar();//输入n之后，我们会按下回车，如果这里没有getchar()去过滤这个回车，那么这个回车符会进入队列

	printTriangle(n);

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*


+--++----++--++




Please input the number of '+' or '-' of the row.1
15
Input the charecter(+/-) of the row.1
+--++----++--++
The charecter triangle is like:
+ - - + + - - - - + + - - + +
- + - + - + + + - + - + - +
- - - - - + + - - - - - -
+ + + + - + - + + + + +
+ + + - - - - + + + +
+ + - + + + - + + +
+ - - + + - - + +
- + - + - + - +
- - - - - - -
+ + + + + +
+ + + + +
+ + + +
+ + +
+ +
+


*/
