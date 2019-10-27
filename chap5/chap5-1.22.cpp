/*

数学趣题

递归实现数值转换

应用递归的方法实现一个数制转换器，它可以将输入的二进制转为十进制表达。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

void biTode(int n, int* sum, int* m)
{
	char c;
	scanf("%c", &c);//从终端输入一个 0/1 字符

	if (c != '#')//判断是否是结束标志
	{
		*m = *m + 1;
		biTode(n + 1, &(*sum), &(*m));//递归调用
	}

	if (c == '1')
	{
		*sum = *sum + pow(2, (*m) - n - 1);//最后一层递归调用开始计算
	}
}

int main()
{
	int sum = 0, m = 0;
	printf("Please input a binary number ending for '#' \r\n");
	biTode(0, &sum, &m);
	printf("The Decimal Decimal digit is \r\n");
	printf("%d", sum);




	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

算法中参数 sum 用来记录累加和。
参数m随着递归的深入不断加1，并且递归结束m的值也不会发生改变。
因为参数sum和m都要在递归中保持值的不变，因此采用指针传递方式。


*/
