/*
数据结构趣题

回文字符串的判定
有一种字符序列，正读和反读都相同，这种字符序列被称为“回文”。
例如：abba就是回文。
编写一个程序，从键盘输入一个任意长度的字符串，以@作为结束标志，判定该字符串是否回文。

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

#define  STACK_INIT_SIZE    20
#define  STACKINCREATEMENT  10
typedef char ElemType; //将char类型定义为ElemType

typedef struct QNode
{
	ElemType data;
	struct QNode * next;
}QNode, *QueuePtr;


//定义一个链队列
typedef struct  
{
	QueuePtr front;//队头指针
	QueuePtr rear;//队尾指针
}LinkQueue;

//定义一个栈类型
typedef struct 
{
	ElemType* base;
	ElemType* top;
	int stackSize;
}sqStack;


//初始化一个空队列
void initQueue(LinkQueue *q)
{
	//创建一个头结点，对头队尾指针指向该结点
	q->front = q->rear = (QueuePtr)malloc(sizeof(QNode));

	if (!q->front) exit(0); //内存分配失败

	q->front->next = NULL;//头结点指针域置NULL
}


//入队列操作
void EnQueue(LinkQueue* q, ElemType e)
{
	QueuePtr p;
	p = (QueuePtr)malloc(sizeof(QNode));
	if (!q->front)  exit(0);
	p->data = e;
	p->next = NULL;
	q->rear->next = p;
	////这里是个指针地址.第1个元素入栈的时候，由于q->rear=q->front，因此front的next是指向了第一个元素p的
	///后来rear地址变化了，就出现了rear的指针独自后移的情况了...front还是指向第1个元素，没有移动
	q->rear = p;
}


///队列，先进先出，，，这里将队首元素出队
//如果队列q不为空，删除q的对头元素，用e返回其值
void DeQueue(LinkQueue* q, ElemType *e)
{
	QueuePtr p;
	if (q->front == q->rear) return;  //队列为空

	p = q->front->next;
	*e = p->data;
	q->front->next = p->next;
	if (q->rear == p)
	{
		q->rear = q->front;  //队头就是队尾，修改队尾指针
	}
	free(p);
}

//内存中开辟一段连续空间作为栈空间，首地址赋值给s->base
void initStack(sqStack* s)
{
	s->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!s->base) exit(0);
	s->top = s->base;
	s->stackSize = STACK_INIT_SIZE;
}

void Push(sqStack* s, ElemType e)
{
	if (s->top - s->base >= s->stackSize)
	{
		s->base = (ElemType*)realloc(s->base, (s->stackSize + STACKINCREATEMENT)*sizeof(ElemType));
		if (!s->base) exit(0);
		s->top = s->base + s->stackSize;
		s->stackSize = s->stackSize + STACKINCREATEMENT;
	}

	//放入数据
	*(s->top) = e;
	s->top++;
}


//出站操作，将栈顶元素弹出
void Pop(sqStack* s, ElemType* e)
{
	if (s->top == s->base) return; 
	*e = *--(s->top); //修改栈顶指针
}

///获得栈s的大小
int StackLen(sqStack s)
{
	return (s.top - s.base);
}


int main()
{	
	sqStack s;
	LinkQueue q;
	ElemType e, r1, r2;
	int flag = 1, len = 0;
	initQueue(&q);
	initStack(&s);

	printf("Please input a string,type '@' for end \r\n");
	scanf("%c", &e);
	while (e != '@')
	{
		Push(&s, e);
		EnQueue(&q, e);
		scanf("%c", &e);
	}
	
		//printf("\r\n-----------Queue----------\r\n");
		//while (q.rear != q.front)
		//{
		//ElemType qe;
		//DeQueue(&q,&qe);
		//printf("%c,", qe);
		//}
		//printf("\r\n-----------Queue----------\r\n");
		//


	//判断该字符串是否是回文
	len = StackLen(s) / 2;
	for (int i = 0; i < len; i++)
	{
		Pop(&s, &r1);//出栈操作，r1将栈顶元素返回
		DeQueue(&q, &r2);//出队列操作，r2将队头元素返回
		if (r1 != r2)
		{
			flag = 0;
			break;
		}
	}
	if (1 == flag)
	{
		printf("It is a circle string.\r\n");
	}
	else
	{
		printf("It is not a circle string.\r\n");
	}



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input a string,type '@' for end
abcddcba@
It is a circle string.





*/
