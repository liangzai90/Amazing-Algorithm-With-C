/*

数学趣题

亲密数
如果整数A的全部因子（包括1，不包括A本身）之和等于B，并且整数B的全部因子（包括1，不包括B本身）之和等于A，则称整数A和B为亲密数。
求解3000以内的全部亲密数。


比较合理的做法：
先全部计算出 1~3000 以内所有的整数的因子的和，存放到数组x[]中。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


//求a的因子和
int factorSum(int a)
{
	int sum = 0;
	for (int i = 1; i < a; i++)
	{
		if (a%i == 0) //i是a的一个因子
		{
			sum = sum + i;//通过变量sum累加求和
		}
	}
	return sum;//返回a的因子的和
}

int isfriend(int a, int b, int i, int j)
{
	if (a == j && b == i)
	{
		//判断a,b是否是亲密数，如是亲密数返回1，否则返回0 
		return 1;
	}
	else
	{
		return 0;
	}
}

//寻找1~3000范围内的亲密数
void friendly()
{
	int x[3001] = { 0 };

	for (int i = 1; i <= 3000; i++)
	{
		x[i] = factorSum(i);
	}

	for (int i = 1; i <= 3000; i++)
	{
		if (x[i] != -111)
		{
			for (int j = i + 1; j <= 3000; j++)
			{
				if (isfriend(x[i], x[j], i, j))
				{
					printf("(%d,%d) ", i, j);
					x[j] = -111;//表示j已经找到亲密数
				}
			}
		}
	}
}

int main()
{
	printf("There are following friendly numbers from 1 to 3000. \r\n");
	friendly();


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*





*/
