/*
数学趣题

填数字游戏求解

ABCD * E = DCBA
ABCDE代表的数字各不相同


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

//求i的倒置数
int reverse(int i)
{
	int r = 0;
	while (i)
	{
		r = r * 10 + i % 10;
		i = i / 10;
	}

	return r;
}

//判断ABCDE5个数字是否相同
int fun(int i, int j)
{
	int buf[4], k = 0;
	while (i)
	{
		buf[k] = i % 10;
		i = i / 10;
		k++;
	}
	
	if (buf[0] == buf[1]) return 0;// A B
	if (buf[0] == buf[2]) return 0;//A C
	if (buf[0] == buf[3]) return 0;//A D
	if (buf[0] == j) return 0;//A E
	if (buf[1] == buf[2]) return 0;//B C
	if (buf[1] == buf[3]) return 0;//B D
	if (buf[1] == j) return 0;//B E
	if (buf[2] == buf[3]) return 0;//C D
	if (buf[2] == j) return 0;//C E
	if (buf[3] == j) return 0;//D E

	return 1;
}


int main()
{
	for (int i = 1000; i < 10000; i++)
	{
		for (int j = 1; j < 10; j++)
		{
			if (i*j == reverse(i) && fun(i, j))
			{
				printf("%d \r\n", i);
				printf("*  %d\r\n", j);
				printf("-----\r\n");
				printf("%d\r\n", i*j);
			}
		}
	}


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

/*

2178
*  4
-----
8712


*/
