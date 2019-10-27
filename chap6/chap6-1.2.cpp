/*

数学趣题(=)

表示成两个数的平方和

已知一个正整数N，编写一个程序，找出所有满足 x^2 + y^2 = N 的正整数对x,y.


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

void getXY(int N)
{
	for (int x = 1; x < sqrt(N); x++)
	{
		for (int y = x; y < sqrt(N); y++)
		{
			if (x*x + y*y == N)
			{
				printf("%d^2 + %d^2 = %d \r\n", x, y, N);
			}
		}
	}
}

int main()
{
	int N;
	printf("Please input a integer N:\r\n");
	scanf("%d", &N);
	getXY(N);


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*



*/
