/*

数学趣题(=)

 计算组合数

编写一个程序，计算 C(m,n),是多少

组合数 C(m,n) ，是从m个事物中任意选出n个事物的选法。
例如从5个小球中任意选出2个


事件划分：
1.不选取第5号小球，从1~4号小球中选取2个小球
2.选取5号小球，从1~4号小球中选取剩下的1个小球。
事件1,2不是相容的（不存在交集）。

因此可以构成一个【递归表达式】

n=m,or n=1,时：C(n,m)=1
1<=n<m  时：C(n,m)=C(m-1,n) + C(m-1,n-1);

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

int cnr(int m, int n)
{
	if (m < n)
	{
		printf("Error m:%d,n%d", m, n);
		exit(0);
	}
	if (n == 0 || n == m)
	{
		return 1;
	}
	else
	{
		return cnr(m - 1, n) + cnr(m-1, n - 1);  /////就是这个神奇的【递归式】
	}
}




int main()
{
	int m, n;
	printf("Please input m and n for C(m,n)\r\n");
	scanf("%d %d", &m, &n);
	printf("C(%d,%d)=%d", m, n, cnr(m, n));


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*


Please input m and n for C(m,n)
5 3
C(5,3)=10




*/
