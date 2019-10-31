/*
数据结构趣题

递归函数的非递归求解
已知n是大于等于0的整数，请编写非递归的程序计算下列递归函数f(n)

f(n) = n+1.  n=0
f(n) = n * f(n/2)  n!=0



int func(int n)
{
   if(n==0)
   {
       return n+1;
   }
   else 
   {
       return (n*func(n/2));
   }
}

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

typedef int ElemType;
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


//
int func(int n)
{
	int r = 1, e = 0;
	sqStack stack;
	initStack(&stack);
	while (n != 0)
	{
		Push(&stack, n);
		n = n / 2;
	}

	while (stack.top != stack.base)
	{
		Pop(&stack, &e);
		r = r*e;
	}
	return r;
}


int main()
{
	printf("The result for conversion of recursion to non recursion is \r\n");
	printf("f(5)=%d \r\n", func(5));


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

The result for conversion of recursion to non recursion is
f(5)=10




*/
