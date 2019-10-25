/*

数学趣题

求两个数的最大公约数和最小公倍数


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

//最大公约数
int gcd(int a, int b)
{
	int min = 0;
	if (a <= 0 || b <= 0)
	{
		return -1;
	}

	if (a > b)//找到ab中较小的值赋给min
	{
		min = b;
	}
	else
	{
		min = a;
	}

	while (min)
	{
		//判定公因数
		if (a%min == 0 && b%min == 0)
		{
			return min;//找到了最大公约数
		}

		//没有找到最大用约数，min减1
		min--;
	}
	return -1;
}


//最小公倍数
int lcm(int a, int b)
{
	int max;
	if (a <= 0 || b <= 0)
	{
		return -1;
	}

	//找到a,b中较大的一个赋值给max
	if (a < b)
	{
		max = a;
	}
	else
	{
		max = b;
	}
	while (max)
	{
		//判定公倍数
		if (max % a == 0 && max %b == 0)
		{
			return max;//找到最小公倍数，返回
		}
		max++;//没有最小公倍数max加1
	}
	return -1;
}



int main()
{
	int a, b;
	printf("Please input two digit for getting GCD and LCM\r\n");
	scanf("%d %d", &a, &b);
	printf("The GCD(最大公约数) of %d,%d is %d \r\n",a,b, gcd(a,b));
	printf("The GCD(最小公倍数) of %d,%d is %d \r\n",a,b,lcm(a,b));


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

