/*

数学趣题(=)

寻找同构数

正整数N若是它平方数的尾部，则称N为同构数。
例如，6是平方数36的尾部，76是其平方数5776的尾部，因此，6与76都是同构数。

编写程序，找出1000以内的同构数


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

int func(int i)
{
	int j = 0;
	for (j = 10; j < 1000; j = j * 10)
	{
		if (i / j == 0) ///判断i是各位数还是十位数
			break;
	}
	//各位数,i^2%10，求得尾部； 10位数，i^2%100，求得尾部；
	if ((i*i) % j == i)//判断i是否为同构数
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void gettonggou()
{
	for (int i = 1; i <= 1000; i++)
	{
		if (func(i))
		{
			printf("%4d,", i);
		}
	}
}

int main()
{
	printf("The Tonggoushu bellow 1000 are:\r\n");
	gettonggou();



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*


The Tonggoushu bellow 1000 are:
1,   5,   6,  25,  76, 376, 625,



*/
