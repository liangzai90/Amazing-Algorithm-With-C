/*
数学趣题

魔幻方阵

有一种方阵被称为“魔幻方阵”。
所谓魔幻方阵是指在 n X n 的矩阵中填写 1~n的平方 这n的平方个数字，使得它每一行、每一列以及两个对角线之和均相等。
例如魔幻方阵如下：

8 1 6
3 5 7
4 9 2



*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


int paraArr[10] = { 0 };

int match(int paraArr[])
{
	if (paraArr[0] != paraArr[1] && paraArr[0] != paraArr[2] && paraArr[0] != paraArr[3] && paraArr[0] != paraArr[4] && paraArr[0] != paraArr[5] && paraArr[0] != paraArr[6] && paraArr[0] != paraArr[7] && paraArr[0] != paraArr[8] &&
		paraArr[1] != paraArr[2] && paraArr[1] != paraArr[3] && paraArr[1] != paraArr[4] && paraArr[1] != paraArr[5] && paraArr[1] != paraArr[6] && paraArr[1] != paraArr[7] && paraArr[1] != paraArr[8] &&
		paraArr[2] != paraArr[3] && paraArr[2] != paraArr[4] && paraArr[2] != paraArr[5] && paraArr[2] != paraArr[6] && paraArr[2] != paraArr[7] && paraArr[2] != paraArr[8] &&
		paraArr[3] != paraArr[4] && paraArr[3] != paraArr[5] && paraArr[3] != paraArr[6] && paraArr[3] != paraArr[7] && paraArr[3] != paraArr[8] &&
		paraArr[4] != paraArr[5] && paraArr[4] != paraArr[6] && paraArr[4] != paraArr[7] && paraArr[4] != paraArr[8] &&
		paraArr[5] != paraArr[6] && paraArr[5] != paraArr[7] && paraArr[5] != paraArr[8] &&
		paraArr[6] != paraArr[7] && paraArr[6] != paraArr[8] &&
		paraArr[7] != paraArr[8]
		)
	{
		return 1;
	}

	return 0;
}

//判断是否满足魔幻方阵的要求，满足返回1，不满足返回0
int justic(int paraArr[])
{
	if (paraArr[0] + paraArr[1] + paraArr[2] == paraArr[3] + paraArr[4] + paraArr[5] &&
		paraArr[3] + paraArr[4] + paraArr[5] == paraArr[6] + paraArr[7] + paraArr[8] &&
		paraArr[6] + paraArr[7] + paraArr[8] == paraArr[0] + paraArr[3] + paraArr[6] &&
		paraArr[0] + paraArr[3] + paraArr[6] == paraArr[1] + paraArr[4] + paraArr[7] &&
		paraArr[2] + paraArr[5] + paraArr[8] == paraArr[1] + paraArr[4] + paraArr[7] &&
		paraArr[2] + paraArr[5] + paraArr[8] == paraArr[0] + paraArr[4] + paraArr[8] &&
		paraArr[2] + paraArr[4] + paraArr[6] == paraArr[0] + paraArr[4] + paraArr[8]
		)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void getMatrix()
{
	for (int A1 = 1; A1 <= 9; A1++)
	{
		for (int A2 = 1; A2 <= 9; A2++)
		{
			for (int A3 = 1; A3 <= 9; A3++)
			{
				for (int A4 = 1; A4 <= 9; A4++)
				{
					for (int A5 = 1; A5 <= 9; A5++)
					{
						for (int A6 = 1; A6 <= 9; A6++)
						{
							for (int A7 = 1; A7 <= 9; A7++)
							{
								for (int A8 = 1; A8 <= 9; A8++)
								{
									for (int A9 = 1; A9 <= 9; A9++)
									{
										paraArr[0] = A1;
										paraArr[1] = A2;
										paraArr[2] = A3;
										paraArr[3] = A4;
										paraArr[4] = A5;
										paraArr[5] = A6;
										paraArr[6] = A7;
										paraArr[7] = A8;
										paraArr[8] = A9;

										if (match(paraArr))
										{
											if (justic(paraArr))
											{
												printf("%3d%3d%3d\r\n", paraArr[0], paraArr[1], paraArr[2]);
												printf("%3d%3d%3d\r\n", paraArr[3], paraArr[4], paraArr[5]);
												printf("%3d%3d%3d\r\n", paraArr[6], paraArr[7], paraArr[8]);

												printf("\r\n\n");
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


int main()
{
	getMatrix();




	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

2  7  6
9  5  1
4  3  8


2  9  4
7  5  3
6  1  8


4  3  8
9  5  1
2  7  6


4  9  2
3  5  7
8  1  6


6  1  8
7  5  3
2  9  4


6  7  2
1  5  9
8  3  4


8  1  6
3  5  7
4  9  2


8  3  4
1  5  9
6  7  2






*/
