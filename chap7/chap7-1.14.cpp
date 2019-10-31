/*
数据结构趣题

任意长度整数加法

编写一个程序，实现任意长度的整数加法。


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

typedef char ElemType;
typedef struct 
{
	ElemType *base;
	ElemType *top;
	int stacksize;
}sqStack;


//初始化栈
void initStack(sqStack* s)
{
	s->base = (ElemType*)malloc(sizeof(ElemType)* STACK_INIT_SIZE);
	if (!s->base)  exit(0); 
	s->top = s->base;//最开始栈顶就是栈底
	s->stacksize = STACK_INIT_SIZE;
}

//入栈操作，将e压入栈中
void  Push(sqStack* s,ElemType e)
{
	//栈满，追加空间
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (ElemType *)realloc(s->base, (s->stacksize + STACKINCREATEMENT)*sizeof(ElemType));
		if (!s->base)  exit(0);
		
		s->top = s->base + s->stacksize;
		s->stacksize = s->stacksize + STACKINCREATEMENT;
	}

	*(s->top) = e;
	s->top++;
}

//出栈操作，用e将栈顶元素返回
void Pop(sqStack *s, ElemType *e)
{
	if (s->top == s->base)  return;
	*e = *--(s->top);
}

//计算堆栈s当前的长度
int StackLen(sqStack s)
{
	return (s.top - s.base);
}

void ADD(sqStack *s1, sqStack *s2, sqStack *s3)
{
	char a1, a2, a3, c = 0;//a1,a2分别存放从堆栈s1,s2中取出的数据 a3 = a1 + a2,c中存放进位

	while (StackLen(*s1) != 0 && (StackLen(*s2)) != 0)
	{
		Pop(s1, &a1);//取出s1栈顶的元素给a1
		Pop(s2, &a2);//取出s2栈顶元素给a2
		a3 = (a1 - 48) + (a2 - 48) + c + 48;//相加
		if (a3 > '9')
		{
			a3 = a3 - '9' + 47;
			c = 1;
		}
		else
		{
			c = 0;
		}

		//将结果入栈s3
		Push(s3, a3);
	}

	//栈s1不为空的情况
	if (StackLen(*s1) != 0)
	{
		while (StackLen(*s1) != 0)
		{
			Pop(s1, &a1);//取出s1栈的栈顶元素给a1
			a3 = a1 + c;//与进位标志相加
			if (a3 > '9')
			{
				a3 = a3 - '9' + 47;
				c = 1;
			}
			else
			{
				c = 0;
			}

			//将结果入栈s3
			Push(s3, a3);
		}
	}
	else if (StackLen(*s2) != 0)
	{
		while (StackLen(*s2) != 0)
		{
			Pop(s2, &a2);
			a3 = a2 + c;
			if (a3 > '9')
			{
				a3 = a3 - '9' + 47;
				c = 1;
			}
			else
			{
				c = 0;
			}

			//栈s2不为空的情况
			Push(s3, a3);
		}
	}

	/// 如果最后结果有进位，将字符1入栈s3
	if (c == 1)
	{
		Push(s3, '1');
	}
}


int main()
{
	char e;
	sqStack s1, s2, s3;
	initStack(&s1);
	initStack(&s2);
	initStack(&s3);
	printf("Please input the first integer.\r\n");

	scanf("%c", &e);
	while (e != '#')  //将加数（字符串）入栈s1
	{
		Push(&s1, e);
		scanf("%c", &e);
	}

	getchar();
	printf("Plese input the second integer.\r\n");
	scanf("%c", &e);
	while (e != '#')  //将加数（字符串）入栈s2
	{
		Push(&s2, e);
		scanf("%c", &e);
	}

	//加法运算，将结果放在s3
	ADD(&s1, &s2, &s3);

	printf("The result is \r\n");
	while (StackLen(s3) != 0)
	{
		Pop(&s3, &e);
		printf("%c", e);
	}
	

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input the first integer.
12345678987654321#
Plese input the second integer.
98765432123456789#
The result is
111111111111111110



*/
