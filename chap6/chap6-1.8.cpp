/*

数学趣题(=)

验证尼科彻斯定理
尼科彻斯定理可以叙述为：任何一个整数的立方都可以表示成一串连续奇数的和。
这里要注意，这些奇数一定是要连续的，
例如：1、3、5、7、9... 编写一个程序，验证尼科彻斯定理


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;



////所谓连续n个数的问题，利用2重循环来解决。第2层循环里，让j从i出开始。。。
//
void proveNKCS(int n)
{
	for (int i = 1; i < n*n*n; i=i+2)
	{
		int iTempSum = 0;
		for (int j = i; j < n*n*n; j=j+2)
		{
			iTempSum += j;
			if (iTempSum == n*n*n)
			{
				printf("we find it:");
				for (int k = i; k<=j; k = k + 2)
				{
					printf("%3d,", k);
				}
				printf("\r\n");
				return;
			}
			else if (iTempSum >n*n*n)
			{
				break;//重新寻找
			}
		}
	}
}


int main()
{

	int n;
	scanf("%d", &n);

	proveNKCS(n);




	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

5
we find it: 21, 23, 25, 27, 29,



*/
