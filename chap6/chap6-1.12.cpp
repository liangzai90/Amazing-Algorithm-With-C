/*

数学趣题(=)

寻找假币
30没金币，1没假。假币轻一些。
只能用一个天平作为测量工具，
并用尽量少的比较次数找出这枚假币


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

int getFalseCoin(int coin[], int low, int high)
{
	int sum1 = 0, sum2 = 0, sum3 = 0;
	if (low + 1 == high)//只剩2枚金币
	{
		if (coin[low] < coin[high])
		{
			return low + 1;//数组索引是从0开始的，所以这里做 加1 操作
		}
		else
		{
			return high + 1;//数组索引是从0开始的，所以这里做 加1 操作
		}
	}

	if ((high - low + 1) % 2 == 0) //n是偶数
	{
		for (int i = low; i <= low + (high - low) / 2; i++)
		{
			sum1 = sum1 + coin[i];//前半段和
		}
		for (int i = low + (high - low) / 2 + 1; i <= high; i++)
		{
			sum2 = sum2 + coin[i];//后半段和
		}

		if (sum1 < sum2)
		{
			return getFalseCoin(coin, low, low + (high - low) / 2);
		}
		if (sum1 > sum2)
		{
			return getFalseCoin(coin, low + (high - low) / 2+1,high);
		}
	}

	if ((high - low + 1) % 2 != 0)
	{
		for (int i = low; i <= low + (high - low) / 2 - 1; i++)
		{
			sum1 = sum1 + coin[i];//前半段和
		}
		for (int i = low + (high - low) / 2 + 1; i <= high; i++)
		{
			sum2 = sum2 + coin[i];
		}

		sum3 = coin[low + (high - low) / 2];
		if (sum1 < sum2)
		{
			return getFalseCoin(coin, low, low + (high - low) / 2 - 1);
		}

		if (sum1>sum2)
		{
			return getFalseCoin(coin, low + (high - low) / 2 + 1, high);
		}
		if (sum1 + sum3 == sum2 + sum3)
		{
			return low + (high - low) / 2 + 1;//如果前后段重量相等，刚好中间那个金币是假的
		}
	}
	return 6666;
}



int main()
{
	int coin[30] = { 
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2, 2, 2, 2,
		2, 2 ,1, 2, 2 };

	printf("The %dth coin is false.\r\n", getFalseCoin(coin, 0, 29));
	


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

The 28th coin is false.


*/
