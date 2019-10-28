/*

数学趣题(=)

验证四方定理
四方定理是数论中的重要定理，它可以叙述为：
所有自然数最多只要4个数的平方和就可以表示，编写一个程序验证四方定理。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


//判断自然数N是否可以表示成为 N=a^2 的形式
int mode_1(int N)
{
	if ((int)sqrt(N) * (int)sqrt(N) == N)
	{
		printf("%d*%d=%d\r\n", (int)sqrt(N), (int)sqrt(N), N);
		return 1;
	}
	else
	{
		return 0;
	}
}

//判断自然数N是否可以表示成 N=a^2+b^2
int mode_2(int N)
{
	for (int x = 1; x < sqrt(N); x++)
	{
		for (int y = x; y < sqrt(N); y++)
		{
			if (x*x + y*y == N)
			{
				printf("%d^2+%d^2=%d\r\n", x, y, N);
				return 1;
			}
		}
	}
	return 0;
}


//判断自然数N是否可以表示成 N=a^2+b^2+c^2
int mode_3(int N)
{
	for (int x = 1; x < sqrt(N); x++)
	{
		for (int y = x; y < sqrt(N); y++)
		{
			for (int z = y; z < sqrt(N); z++)
			{
				if (x*x + y*y + z*z== N)
				{
					printf("%d^2+%d^2+%d^2=%d\r\n", x, y,z, N);
					return 1;
				}
			}
		}
	}
	return 0;
}




//判断自然数N是否可以表示成 N=a^2+b^2+c^2+d^2

//判断自然数N是否可以表示成 N=a^2+b^2+c^2
int mode_4(int N)
{
	for (int x = 1; x < sqrt(N); x++)
	{
		for (int y = x; y < sqrt(N); y++)
		{
			for (int z = y; z < sqrt(N); z++)
			{
				for (int t = z; t < sqrt(N); t++)
				{
					if (x*x + y*y + z*z + t*t == N)
					{
						printf("%d^2+%d^2+%d^2+%d^2=%d\r\n", x, y, z,t, N);
						return 1;
					}
				}
			}
		}
	}
	return 0;
}

void proveFourSquares(int n)
{
	if (mode_1(n))
	{
		printf("It has virified Four Squares.\r\n");
	}
	else if (mode_2(n))
	{
		printf("It has virified Four Squares.\r\n");
	}
	else if (mode_3(n))
	{
		printf("It has virified Four Squares.\r\n");
	}
	else if (mode_4(n))
	{
		printf("It has virified Four Squares.\r\n");
	}
	else
	{
		printf("something error!!! \r\n");
	}
}


int main()
{
	int N;
	printf("Please input a natural number.\r\n");
	scanf("%d", &N);

	printf("-----------------Step of Verification------------------\r\n");
	proveFourSquares(N);


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input a natural number.
156
-----------------Step of Verification------------------
1^2+3^2+5^2+11^2=156
It has virified Four Squares.




*/
