/*

寻找矩阵中的“鞍点”

在一个矩阵中，可能会有这样的元素：它在该行中最大，而在该列中最小。我们把这样的元素称为“鞍点”。
一个矩阵中可能没有鞍点。
任意一个5 X 5的矩阵，寻找该矩阵中的鞍点，并将它在矩阵中的位置（行，列）输出.


仔细分析鞍点的定义可知，一个矩阵中，最多出现一个鞍点。
假设一个君子有2个鞍点，那么另一个鞍点就不满足 鞍点 需要满足的条件。因此假设不成立。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int getSaddlePoint(int* x, int* y, int(*A)[5], int m, int n)
{
	int max=0, flag=0;
	for (int i = 0; i < m; i++)//逐行扫描，寻找鞍点
	{
		max = 0;//记录第i行中最大值的列数
		flag = 1;

		for (int j = 1; j < n; j++)//找出第i行中最大元素的位置 A[i][max]
		{
			if (A[i][j] > A[i][max])
			{
				max = j;
			}
		}

		for (int k = 0; k < n; k++)
		{
			if (A[i][max] == A[i][k] && max != k)
			{
				flag = 0;
				break;
			}
		}

		if (1 == flag)
		{
			for (int k = 0; k < m; k++)
			{
				//不是最小元素，因此A[i][max]不是鞍点
				if (A[k][max] <= A[i][max] && k != i)
				{
					flag = 0;
					break;
				}
			}
		}

		if (1 == flag)
		{
			*x = i;//找到鞍点，用x,y返回，程序结束,返回1
			*y = max;
			return 1;
		}
	}

	return 0;  //没有找到鞍点，返回0
}



int main()
{
	int A[5][5], x, y;
	printf("Please input some digit into the 5*5 matrix \r\n");
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			scanf("%d", &A[i][j]);
		}
	}

	//寻找鞍点，用参数x,y返回数组下标
	if (getSaddlePoint(&x, &y, A, 5, 5))
	{
		printf("\r\n SaddlePoint is at (%d,%d). [%d]\r\n", x + 1, y + 1, A[x][y]);
	}
	else
	{
		printf("\r\n There is no saddlepoint in the matrix \r\n");
	}

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

1 2 3 4 5
2 3 4 5 6
3 4 5 6 7
4 5 6 7 8
5 6 7 8 9


*/
