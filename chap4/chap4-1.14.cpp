/*

打印特殊图案

理解输出格式的规律。
第1行 1个*
第2行 3个*
第3行 5个*
...

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void PrintTrangle(int n)
{
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j < n - i; j++)
		{
			printf(" ");
		}
		for (int j = 0; j < 2 * i - 1; j++)
		{
			printf("*");
		}
		printf("\r\n");
	}
}


int main()
{
	int n;
	printf("How many rows of * for trangle \r\n");
	scanf("%d", &n);
	PrintTrangle(n);//打印n阶符号三角形


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
