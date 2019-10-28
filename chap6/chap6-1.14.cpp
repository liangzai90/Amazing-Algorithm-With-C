/*

数学趣题(=)

递归法求幂

m的n次方

n=0,return 1;
n=1, return m
n>1, return m* m的n-1次方  

由此，可以构造【递归表达式】

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


//m的n次方
int qiuMi(int m, int n)
{
	if (n == 0)
	{
		return 1;
	}
	if (n == 1)
	{
		return m;
	}
	
	return m * qiuMi(m, n - 1);
}


unsigned long myPow(int m, int n)
{
	unsigned long temp;
	if (n == 0) return 1;
	if (n == 1) return m;

	if (n % 2 == 0)
	{
		temp = myPow(m, n / 2);    //在n特别大的时候，这种方法能更加高效
		return temp * temp;
	}

	if (n % 2 != 0)
	{
		return m*myPow(m, n - 1);
	}
}


int main()
{
	int m, n;
	printf("Please input m and n \r\n");
	scanf("%d %d", &m, &n);

	printf("%d^%d=%d \r\n", m, n, myPow(m, n));
	printf("%d^%d=%d \r\n", m, n, qiuMi(m, n));


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input m and n
2 5
2^5=32



*/
