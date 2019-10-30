/*
数据结构趣题

二进制/八进制转换器

编写一个程序，要求从终端输入一串0/1表示的二进制数，输出它的八进制表示形式


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

#define STACK_INIT_SIZE      20
#define STACKINCREATEMENT    10

typedef char ElemType;

typedef struct {
	ElemType* base;
	ElemType* top;
	int stacksize;
}sqStack;


//初始化栈
void initStack(sqStack* s)
{
	//内存中开辟一段连续空间作为栈空间，首地址赋值给 s->base
	s->base = (ElemType*)malloc(STACK_INIT_SIZE*sizeof(ElemType));
	if (!s->base) exit(0);//分配空间失败
	s->top = s->base;//最开始栈顶就是栈底
	s->stacksize = STACK_INIT_SIZE;
}

//入栈操作，将e压入栈中
void Push(sqStack* s, ElemType e)
{
	//栈满，追加空间
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (ElemType*)realloc(s->base, (s->stacksize + STACKINCREATEMENT)*sizeof(ElemType));
		if (!s->base)  exit(0); //存储空间分配失败
		s->top = s->base + s->stacksize;//
		s->stacksize = s->stacksize + STACKINCREATEMENT;//设置栈的最大容量
	}

	*(s->top) = e;
	s->top++;
}


//出栈操作，用e将栈顶元素返回
void Pop(sqStack* s, ElemType* e)
{
	if (s->top == s->base) return;
	*e = *--(s->top);
}

///计算栈s的当前长度
int StackLen(sqStack s)
{
	return (s.top - s.base);
}


int main()
{	
	ElemType e;
	sqStack s1;
	sqStack s2;
	int len, sum = 0;
	initStack(&s1);
	printf("Please input a binary number and type # for end \r\n");
	scanf("%c", &e);
	while (e != '#')
	{
		if (e == '0' || e == '1')
		{
			Push(&s1, e);
		}
		scanf("%c", &e);
	}

	initStack(&s2);//创建s2栈

	len = StackLen(s1);//得到栈中元素个数，即二进制的长度
	for (int i = 0; i < len; i = i + 3)
	{
		for (int j = 0; j < 3; j++)
		{
			Pop(&s1, &e);//取出栈顶元素
			sum = sum + (e - 48)*pow(2, j);//转换为八进制数
			if (s1.base == s1.top)
			{
				break;
			}
		}

		Push(&s2, sum + 48);//将八进制数以字符形式压入栈中
		sum = 0;
	}

	printf("ba jinzhi :\r\n");
	while (s2.base != s2.top)
	{
		Pop(&s2, &e);
		printf("%c", e);
	}


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
