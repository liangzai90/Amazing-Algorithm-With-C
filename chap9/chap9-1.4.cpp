/*
综合题

0-1背包问题

给定n种物品和一个背包。
物品i的质量为Wi，其价值为Vi,
背包的最大载重量为C。
编写一个程序，求解如何装在背包中的物品，使得装入背包中的物品总价值最大。


分解问题：
1.背包可以装入的总价值最大的物品是多少？
2.如何装在，可以达到 问题1 里面的 物品价值？

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

#define LIMIT_WEIGHT     13
#define MAX_PRODUCTNUM   20

typedef struct productInfo
{
	int weight;
	int value;
	int state;//是否被装载了
}productInfo;

//
/////函数调用效率太低了，weight,value.作为参数返回，可以提升效率
//int GetMaxWeight(productInfo productArr[])
//{
//	int iWeight = 0;
//	for (int i = 0; i < MAX_PRODUCTNUM; i++)
//	{
//		if (0 == productArr[i].state)
//		{
//			iWeight += productArr[i].weight;
//		}
//	}
//	return iWeight;
//}
//
/////函数调用效率太低了，weight,value.作为参数返回，可以提升效率
//int GetMaxValue(productInfo productArr[])
//{
//	int iValue = 0;
//	for (int i = 0; i < MAX_PRODUCTNUM; i++)
//	{
//		if (0 == productArr[i].state)
//		{
//			iValue += productArr[i].value;
//		}
//	}
//	return iValue;
//}

void printSolution(productInfo productArr[])
{
	printf("One solution:\r\n");
	for (int i = 0; i < MAX_PRODUCTNUM; i++)
	{
		if (1 == productArr[i].state)
		{
			printf("(weight:%d,value:%d)\r\n", productArr[i].weight, productArr[i].value);
		}
	}
}


void findMaxValue(productInfo productArr[], int step, int curWeight, int curValue, int *maxValue)
{
	if (step > MAX_PRODUCTNUM)
	{
		if (curValue > *maxValue)
		{
			*maxValue = curValue;
		}
		return;
	}

	for (int i = 0; i < MAX_PRODUCTNUM; i++)
	{
		if (0 == productArr[i].value)  continue;
		//&& 
		if (0 == productArr[i].state && curWeight + productArr[i].weight <= LIMIT_WEIGHT)
		{
			productArr[i].state = 1;
			curWeight += productArr[i].weight;
			curValue += productArr[i].value;
			if (curValue > *maxValue)
			{
				*maxValue = curValue;
			}

			findMaxValue(productArr, step + 1, curWeight, curValue, maxValue);
			productArr[i].state = 0;
			curWeight -= productArr[i].weight;
			curValue -= productArr[i].value ;
		}

	}
	return;
}


//根据maxValue查找解决方案
void findOneSolution(productInfo productArr[], int step, int curWeight, int curValue, int maxValue)
{
	if (step > MAX_PRODUCTNUM)
	{
		if (curValue == maxValue)
		{
			printSolution(productArr);
		}
		return;
	}

	for (int i = 0; i < MAX_PRODUCTNUM; i++)
	{
		if (0 == productArr[i].value)  continue;
		//&& 
		if (0 == productArr[i].state && curWeight + productArr[i].weight <= LIMIT_WEIGHT)
		{
			productArr[i].state = 1;
			curWeight += productArr[i].weight;
			curValue += productArr[i].value;
			if (curValue == maxValue)
			{
				if (curValue == maxValue)
				{
					printSolution(productArr);
				}
				return;
			}

			findOneSolution(productArr, step + 1, curWeight, curValue, maxValue);
			productArr[i].state = 0;
			curWeight -= productArr[i].weight;
			curValue -= productArr[i].value ;
		}

	}
	return;
}



int main()
{
	int maxValue = 0;
	productInfo productArr[MAX_PRODUCTNUM] = { 0 };
	productArr[0].weight = 3;
	productArr[0].value = 8;

	productArr[1].weight = 5;
	productArr[1].value = 9;

	productArr[2].weight = 6;
	productArr[2].value = 6;

	productArr[3].weight = 4;
	productArr[3].value = 7;

	productArr[4].weight = 7;
	productArr[4].value = 5;

	productArr[5].weight = 5;
	productArr[5].value = 6;

	findMaxValue(productArr, 0, 0, 0, &maxValue);
	printf("the MaxValue is :%d.\r\n", maxValue);

	findOneSolution(productArr, 0, 0, 0, maxValue);


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

products:6
weight:3 5 6 4 7 5
price:8 9 6 7 5 6 
limitWeight:13

grass price:24
weight:12


///价值相同的时候，weight越低越好.
the MaxValue is :24.
One solution:
(weight:3,value:8)
(weight:5,value:9)
(weight:4,value:7)






*/
