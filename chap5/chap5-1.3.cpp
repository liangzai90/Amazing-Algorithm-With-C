/*

数学趣题

哥德巴赫猜想 的近似证明。
所谓哥德巴赫猜想是说任何一个大于2的偶数都能表示成为两个素数之和。
质数（素数的同义词）是指在大于1的自然数中，除了1和它本身以外不再有其他因数的自然数。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;


//判断是否为素数
int isPrime(int i)
{
	int flag = 1;
	if (1 == i)
	{
		flag = 0; // 1不是素数，素数都要大于1
	}
	for (int n = 2; n < i; n++)
	{
		if (i%n == 0) //如果在2和i-1之间存在其他因子，则不是素数，flag置为0
		{
			flag = 0;
			break;
		}
	}
	if (1 == flag)
	{
		return 1;//i是素数，返回1
	}
	else
	{
		return 0;//i不是素数，返回0
	}
}



//判断偶数a是否符合哥德巴赫猜想
int isGoldbach(int a)
{
	int flag = 0;
	for (int i = 1; i <= a / 2; i++)
	{
		if (isPrime(i) && isPrime(a - i))//如果i和a-i都为素数，则符合哥德巴赫猜想
		{
			flag = 1;
			printf("%d=%d+%d ,", a, i, a - i);
			break;
		}
	}

	if (1 == flag)
	{
		return 1;//符合猜想
	}
	else
	{
		return 0;//不符合猜想
	}
}

//在low和high范围内验证哥德巴赫猜想
int TestfyGB_Guess(int low, int high)
{
	int flag = 0;
	int j = 0;
	for (int i = low; i <= high; i++)
	{
		if (i % 2 == 0 && i > 2)
		{
			if (isGoldbach(i)) //偶数i符合哥德巴赫猜想
			{
				j++;
				if (5 == j)
				{
					printf("\r\n");
					j = 0;
				}
			}
			else
			{
				flag = 1;//如果哥德巴赫猜想错误，则跳出循环,flag=1
				break;
			}
		}
	}

	if (0 == flag)
	{
		return 1;//在low和high的范围内，哥德巴赫猜想正确返回
	}
	else
	{
		return 0;//在low和high的范围内，哥德巴赫猜想【不正确】返回
	}
}


int main()
{
	//验证1~100以内的哥德巴赫猜想
	printf("Now testify Goldbach Guess in the range of 1~100:\r\n");
	if (TestfyGB_Guess(1, 100))
	{
		printf("\r\n In the range of 1~100,Goldbach Guess is right.\r\n");
	}
	else
	{
		printf("\r\n Goldbach Guess is wrong.\r\n");
	}

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

