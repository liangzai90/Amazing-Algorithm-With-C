/*
数学趣题

移数字游戏

有这样一个包含9个圆圈的数阵。

把这圈数字看作一个链表。
这里的排序，是通过交换变量来实现。所以，可以考虑用冒泡排序来实现链表的排序。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


void getStep(int m[])
{
	int tmp;
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7 - i; j++)
		{
			if (m[j] >= m[j + 1])
			{
				tmp = m[j];
				m[j] = m[j + 1];
				m[j + 1] = tmp;

				printf("(%d# --> 0#) \r\n", j + 1);
				printf("(%d# --> %d#) \r\n", j+2, j + 1);
				printf("(0# --> %d#) \r\n", j + 2);
			}
		}
	}
	printf("\r\n");
}

void Print(int m[])
{
	printf("  [%d]--[%d]--[%d] \r\n", m[0], m[1], m[2]);
	printf("  |  %c  |  %c  | \r\n", 92, 47);
	printf("  [%d]--[ ]--[%d] \r\n", m[7], m[3]);
	printf("  |  %c  |  %c  | \r\n", 92, 47);
	printf("  [%d]--[%d]--[%d] \r\n", m[6], m[5], m[4]);
}

int main()
{
	int m[8];
	printf("Please input 8 integer (1~8) to arrange this matrix \r\n");
	for (int i = 0; i < 8; i++)
	{
		scanf("%d", &m[i]);
	}
	printf("The initial data matrix is like \r\n");

	Print(m);

	printf("\r\n Move Step:\r\n");
	getStep(m);

	printf("The result of moving is \r\n");
	Print(m);



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input 8 integer (1~8) to arrange this matrix
1  2 4 3 6 5 7 8
The initial data matrix is like
[1]--[2]--[4]
|  \  |  /  |
[8]--[ ]--[3]
|  \  |  /  |
[7]--[5]--[6]

Move Step:
(3# --> 0#)
(4# --> 3#)
(0# --> 4#)
(5# --> 0#)
(6# --> 5#)
(0# --> 6#)

The result of moving is
[1]--[2]--[3]
|  \  |  /  |
[8]--[ ]--[4]
|  \  |  /  |
[7]--[6]--[5]


*/
