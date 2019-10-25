/*
数学趣题

寻找水仙花数

如果一个3位数，等于其余各位数字的立方和，则称这个数为水仙花数。
例如:407 = 4^3 + 0^3 + 7^3
因此，407就是一个水仙花数。
编写程序，找出全部的水仙花数

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;


//判断是否是水仙花数，是则返回1，不是返回0
int IsNarcissus(int a)
{
	int sum = 0, temp;
	temp = a;
	while (temp > 0)
	{
		sum = sum + (temp % 10)*(temp % 10)*(temp % 10);
		temp = temp / 10;
	}
	if (a == sum)
	{
		return 1;//a是水仙花数
	}
	else
	{
		return 0;//a不是水仙花数
	}
}

//寻找水仙花数
void Narcissus()
{
	for (int i = 100; i <= 999; i++)
	{
		if (IsNarcissus(i))
		{
			printf("%5d,", i);
		}
	}
}

int main()
{
	printf("The Narcissus number below are \r\n");
	Narcissus();



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

/*

The Narcissus number below are
153,  370,  371,  407,

*/
