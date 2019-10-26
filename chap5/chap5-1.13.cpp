/*
数学趣题

分解质因数

根据数论的知识可知，任何一个合数都可以写成几个质因数相乘的形式，这几个质因数都叫作这个合数的质因数。
例如：24 = 2 * 2 * 2 * 3
把一个合数写成几个质因数相乘的形式表示，叫作分解质因数。
对于一个质数，它的质因数可定义为它本身。
编写一个程序，实现分解质因数。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;


//判断是否是质数（素数）
int isPrime(int a)
{
	for (int i = 2; i <= a - 1; i++)
	{
		if (a % i == 0)
		{
			return 0;//不是质数
		}		
	}

	//是质数
	return 1;
}

void PrimeFactor(int n)
{
	if (isPrime(n))
	{
		printf("%3d", n);
	}
	else
	{
		for (int i = 2; i <= n - 1; i++)
		{
			if (n%i == 0)
			{
				if (isPrime(i))
				{
					printf("%3d", i);//第一个因数一定是质因数
				}

				if (isPrime(n / i))
				{
					printf("%3d", n / i);
					break;//找到全部质因子
				}
				else
				{
					PrimeFactor(n / i);//递归地调用PrimeFactor()函数分解 n/i 
				}
				break;
			}
		}
	}
}


int main()
{
	int n;
	printf("Please input a integer for getting Prime factor \r\n");
	scanf("%d", &n);
	PrimeFactor(n);//对n分解质因数


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
