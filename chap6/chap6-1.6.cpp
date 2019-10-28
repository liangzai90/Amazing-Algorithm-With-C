/*

数学趣题(=)

递归法寻找最小值
编写一个程序，要求从一个整数序列中找出最小的元素，并用递归的方法实现。



*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

int getMin(int array[], int n)
{
	int val1, val2, val3;
	if(1 == n)
	{
		return array[0];
	}

	if (n % 2 == 0)
	{
		val1 = getMin(array, n / 2);
		val2 = getMin(array + n / 2, n / 2);
		if (val1 < val2)
		{
			return val1;
		}
		else
		{
			return val2;
		}
	}

	if (n % 2 != 0)
	{
		val1 = getMin(array, n / 2);
		val2 = getMin(array + n / 2 + 1, n / 2);
		val3 = array[n / 2];
		if (val1 < val2)
		{
			if (val1 < val3)
			{
				return val1;
			}
			else
			{
				return val3;
			}
		}
		else
		{
			if (val2 < val3)
			{
				return val2;
			}
			else
			{
				return val3;
			}
		}
	}
}


int main()
{
	int array[9] = { 11, 13, 23, 56, 8, 23, 11, 23, 111 };
	int val = 0;
	val = getMin(array, 9);//调用 递归函数 getMin()获得最小值
	printf("Min:%d\r\n", val);



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

