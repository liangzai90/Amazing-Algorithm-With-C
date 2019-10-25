/*
数学趣题

 百鸡百钱问题

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

int accord(int i, int j, int k)
{
	if (5 * i + 3 * j + k / 3 == 100 && k % 3 == 0 && i + j + k == 100)
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
	printf("The possible plans for buying 100 fowls with 100 yuan are:\r\n");
	for (int i = 0; i <= 100; i++)
	{
		for (int j = 0; j <= 100; j++)
		{
			for (int k = 0; k <= 100; k++)
			{
				if (accord(i, j, k))
				{
					printf("(公鸡)cock:%d, (母鸡)hen:%d, (小鸡)chicken:%d \r\n", i, j, k);
				}
			}
		}
	}


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

