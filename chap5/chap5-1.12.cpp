/*
数学趣题

兔子产仔问题

13世纪意大利数学家斐波那契在他的《算盘书》中提出这样一个问题：
有人想知道一年内一对兔子可以繁殖多少对，便筑了一道围墙把一对新生的兔子关在里面。
已知一对两个月大的兔子以后每一个月都可以生一对小兔子，而一对新生的兔子出生两个月后才可以生小兔子
（例如：1月份出生，3月份才可产仔）
假如一年内没有发生死亡，则一年内共能繁殖成多少对？

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;


int Fibonacci(int n)
{
	if (1 == n || 2 == n)
	{
		return 1;
	}
	else
	{
		return Fibonacci(n - 1) + Fibonacci(n - 2);
	}
}


int main()
{
	printf("There are %d pairs of rabbits 1 year later.\r\n", Fibonacci(12));

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
