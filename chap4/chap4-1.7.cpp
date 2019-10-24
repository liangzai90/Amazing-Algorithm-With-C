
/*

矩阵的转置运算

从键盘终端键入一个3行4列的矩阵，编写一个函数对该矩阵进行转置操作


scanf("%d", &a[i][j]);
scanf("%d", *(a + i) + j);

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void InputMatrix(int(*a)[4], int n, int m)
{
	//输入 n * m 阶的矩阵
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", &a[i][j]);
//			scanf("%d", *(a + i) + j);
		}
	}
}

void OutputMatrix(int(*b)[3], int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			printf("%3d", b[i][j]);
//			printf("%3d", *(*(b + i)+j));
		}
		printf("\r\n");
	}
}

void MatrixTranspose(int(*a)[4], int(*b)[3])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			b[i][j] = a[j][i];
		}
	}
}

int main()
{
	int a[3][4], b[4][3];
	printf("Please input 3 X 4 matrix \r\n");
	InputMatrix(a, 3, 4);
	MatrixTranspose(a, b);
	printf("The Transposex matrix is \r\n");
	OutputMatrix(b, 4, 3);



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

/*

1 2 3 4 
5 6 7 8 
9 0 1 2


*/

