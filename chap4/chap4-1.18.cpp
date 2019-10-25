/*

n阶勒让德多项式求解

勒让德多项式是一个递归形式的定义。


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//递归函数，求勒让德多项式
float Rand(int n, float x)
{
	if (0 == n)
	{
		return 1;
	}
	else if (1 == n)
	{
		return x;
	}
	else
	{
		return ((2 * n - 1)*x - Rand(n - 1, x) - (n - 1)*Rand(n - 2, x)) / (float)n;
	}
}




int main()
{
	int n;
	float x, p;
	printf("Please input n:\r\n");
	scanf("%d", &n);
	printf("Please input x:\r\n");
	scanf("%f", &x);
	p = Rand(n, x);
	printf("The result of P%d(%f)=%f \r\n", n, x, p);



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

