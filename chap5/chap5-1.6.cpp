/*
数学趣题

判断回文数字

有这样一类数字，它们顺着和倒着看都是相同的数，例如：121,656,2332，这样的数字叫回文数字。
编写一个程序，判断从键盘接收的数字使否为回文数字

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;


//求i的倒置数.这里要注意，别超过了int范围
int reverse(int i)
{
	int m, j = 0;
	m = i;
	while (m)
	{
		j = j * 10 + m % 10;
		m = m / 10;
	}
	return j;//返回i的倒置数
}

//判断n是否是回文数字
int isCircle(int n)
{
	int m;
	m = reverse(n);
	if (n == m)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}



int main()
{
	int n;
	printf("Type a integer for judging is Circle: \r\n");
	scanf("%d", &n);
	if (isCircle(n))
	{
		printf("%d is Circle \r\n", n);
	}
	else
	{
		printf("%d is not Circle . \r\n", n);
	}

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

