/*

矩阵的乘法运算

三重循环嵌套

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main()
{
	int A[2][3] = { { 1, 2, 3 }, { 4, 5, 6 } };
	int B[3][4] = { { 1, 0, 2, 3 }, { 4, 1, 5, 6 }, { 6, 8, 9, 0 } };
	int C[2][4] = { { 0, 0, 0, 0 }, { 0, 0, 0, 0 } };

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				C[i][j] = C[i][j] + A[i][k] * B[k][j];//矩阵的乘法，还是需要多理解理解
			}
		}
	}

	printf("The result is \r\n");

	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%3d", C[i][j]);
		}
		printf("\r\n");
	}


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
