/*

数学趣题(=)

连续整数固定和问题


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

void cntnsIntSum(int n)
{
	int j=0,sum = 0;
	for (int i = 1; i < n; i++)  //控制起点的选择，从1到n-1
	{
		j = i - 1;
		while (sum < n)  //从起点向后顺序累加
		{
			j++;
			sum = sum + j;//sum记录当前的累加和
		}
		if (sum == n)//找到了一个n的连续整数固定和
		{
			printf("%d+...+%d = %d \r\n", i, j, n);
		}
		sum = 0;
	}
}


int main()
{
	int n;
	printf("Please input a integer \r\n");
	scanf("%d", &n);
	cntnsIntSum(n);



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input a integer
27
2+...+7 = 27
8+...+10 = 27
13+...+14 = 27



*/
