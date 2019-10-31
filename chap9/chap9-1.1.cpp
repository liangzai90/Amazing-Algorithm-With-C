/*
综合题

破碎的砝码
发过数学家梅奇亚克在他所著的《数字组合游戏》中提出了这样一个问题：
一个商人有一个质量为40磅的砝码，
一天他不小心将该砝码摔成了4块。
商人发现，每块砝码的质量都是整磅数，而且每块砝码的质量各不相同，
并且发现这4块砝码碎片可以在天平上称出1~40磅之间的任意质量。
（整磅数，即1磅，2磅...）
问，这4块砝码碎片的质量各是多少？


问题分解：
1.4层循环，找出a1,a2,a3,a4的N种砝码质量情况；
2.计算4个砝码加起来等于 weight.  x属于（-1,0,1）3种情况。###这个是个比较难，不太容易抽象出来###
3.for循环，校验1~40种情况
4.


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



//x1*a1+x2*a2+x3*a3+x4*a4=weight.(weight:1~40).
//x#(-1,0,1)...
int getWeight(int i, int j, int k, int s, int weight)
{
	for (int x1 = -1; x1 <= 1; x1++)
	{
		for (int x2 = -1; x2 <= 1; x2++)
		{
			for (int x3 = -1; x3 <= 1; x3++)
			{
				for (int x4 = -1; x4 <= 1; x4++)
				{
					if (x1*i + x2*j + x3*k + x4*s == weight)
					{
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

////校验1~40之间的数字是否可以计算出来
int justify(int i, int j, int k, int s)
{
	for (int weight = 1; weight <= 40; weight++)
	{
		if (!getWeight(i, j, k, s, weight))
		{
			return 0;
		}
	}
	return 1;
}


//穷举N种情况
void pieces()
{
	for (int i = 1; i <= 40; i++)
	{
		for (int j = i+1; j <= 40; j++)
		{
			for (int k = j+1; k <= 40; k++)
			{
				for (int s = k + 1; s <= 40; s++)
				{
					if (i + j + k + s == 40)
					{
						if (justify(i, j, k, s))
						{
							printf("The weight is broken up 4 pieces:\r\n");
							printf("%d,%d,%d,%d", i, j, k, s);
						}
					}
				}
			}
		}
	}
}


int main()
{
	pieces();


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

The weight is broken up 4 pieces:
1,3,9,27



*/
