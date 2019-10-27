/*

数学趣题(=)

验证角谷猜想
角谷猜想的内容为：任意给定一个自然数，若它为偶数则除以2，
若它为奇数则乘以3加1，得到一个新的自然数，按照遮掩的计算方式计算下去，若干次后得到的结果必然为1.

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


void proveJiaoGu(int  n)
{
	int count = 1;
	while (n != 1 && count <= 1000)
	{
		if (n % 2 == 0)
		{
			printf("%d/2=%d \r\n", n, n / 2);
			n = n / 2;
		}
		else
		{
			printf("%d*3+1=%d\r\n", n, n * 3 + 1);
			n = n * 3 + 1;
		}
		count++;
	}

	if (count < 1000 && n == 1)
	{
		printf("This natural number is according to JiaoGu Guess \r\n");
	}
}



int main()
{
	int n;
	printf("Please input a number to verify.\r\n");
	scanf("%d", &n);
	printf("-----------------step of verification---------------\r\n");
	proveJiaoGu(n);


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input a number to verify.
10
-----------------step of verification---------------
10/2=5
5*3+1=16
16/2=8
8/2=4
4/2=2
2/2=1
This natural number is according to JiaoGu Guess



*/
