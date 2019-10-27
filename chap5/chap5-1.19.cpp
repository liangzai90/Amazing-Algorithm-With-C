/*
数学趣题

完全数
如果一个数恰好等于它的因子（包括1，但不包括本身）之和，那么这个数就被称为完全数。
例如：6的因子为1,2,3。6=1+2+3,因此6是一个完整数。求出1000以内的完整数。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

int factorSum(int a)
{
	int sum = 0;
	for (int i = 1; i < a; i++)
	{
		if (a%i == 0)
		{
			sum = sum + i;
		}
	}
	return sum;
}

int perfextnumber(int a)
{
	if (a == factorSum(a))
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
	printf("There are following perfect numbers 1~1000 are:\r\n");
	for (int a = 1; a <= 1000; a++)
	{
		if (perfextnumber(a))
		{
			printf("%4d,", a);
		}
	}


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

There are following perfect numbers 1~1000 are:
6,  28, 496,

*/
