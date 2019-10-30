/*
数据结构趣题

括号匹配

假设表达式中只允许两种括号：圆括号和方括号，他们刻意任意的嵌套
例如[()[()]]都是合法的。
但是要求括号必须成对出现，像[(])的形式就是非法的。
编写一个程序，从终端输入一组括号，以字符#作为结束标志，
判断输入的括号是否匹配合法。




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
typedef char ElementType;

typedef struct
{
	ElementType* base;
	ElementType* top;
	int stacksize;
}sqStack;


//内存中开辟一段空间
void initStack(sqStack* s)
{
	s->base = (ElementType*)malloc(STACK_INIT_SIZE * sizeof(ElementType));
	if (!s->base) exit(0);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
}

//入栈操作
void Push(sqStack* s, ElementType e)
{
	if (s->top - s->base >= s->stacksize)
	{
		s->base = (ElementType*)realloc(s->base, (s->stacksize + STACKINCREATEMENT)*sizeof(ElementType));
		if (!s->base) exit(0);
		s->top = s->base + s->stacksize;
		s->stacksize = s->stacksize + STACKINCREATEMENT;
	}

	//放入数据
	*(s->top) = e;
	s->top++;
}

//出站操作
void Pop(sqStack* s, ElementType* e)
{
	if (s->top == s->base) return;
	*e = *--(s->top);
}

//获得栈s的大小
int StackLen(sqStack s)
{
	return (s.top - s.base);
}

int match(char e, char c)
{
	if (e == '(' && c == ')') return 1;
	if (e == '[' && c == ']') return 1;
	return 0;
}


int main()
{
	sqStack s;
	char c, e;
	initStack(&s);
	printf("Please input [](), type '#' for end \r\n");
	scanf("%c", &c);//输入第一个字符 
	while (c!='#')
	{
		if (!StackLen(s))
		{
			Push(&s, c);//如果栈为空，则说明输入的是第一个字符
		}
		else
		{
			Pop(&s, &e);//取出栈顶元素
			if (!match(e, c))
			{
				//如果匹配不成功，2个元素都入栈
				Push(&s, e);
				Push(&s, c);
			}
		}

		//输入下一个字符
		scanf("%c", &c);
	}

	if (!StackLen(s))
	{
		printf("The brackets are matched \r\n");
	}
	else
	{
		printf("The brackets are not matched \r\n");
	}


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*


Please input [](), type '#' for end
[[()][]()]#
The brackets are matched




*/
