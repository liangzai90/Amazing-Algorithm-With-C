/*

打印杨辉三角

在屏幕打印出一个6阶杨辉三角

1
1 1
1 2 1
1 3 3 1
1 4 6 4 1
1 5 10 10 5 1
1 6 15 20 15 6 1

...

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



int main()
{
	int buf[7], temp[7];
	for (int i = 0; i <= 6; i++)
	{
		if (0 == i)
		{
			printf("%d", 1);//打印第一行
		}
		else if (1 ==i)
		{
			printf("\r\n%d %d\r\n", 1, 1);//打印第二行
			buf[0] = 1;
			buf[1] = 1;
		}
		else
		{
			for (int j = 1; j <= i + 1; j++)
			{
				if (j == 1 || j == i + 1)
				{
					printf("%d ", 1);//打印第1个和第i+1个数，他们都是1
					temp[j - 1] = 1;
				}
				else
				{
					//打印第2~i个数据
					printf("%d ", buf[j - 2] + buf[j - 1]);
					temp[j - 1] = buf[j - 2] + buf[j - 1];
				}
			}

			//完成一行打印，换行
			printf("\r\n");
			for (int k = 0; k < 7; k++)
			{
				buf[k] = temp[k];//将第i行的数据存放到 buf[0] ~ buf[i] 中
			}
		}
	}




	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
