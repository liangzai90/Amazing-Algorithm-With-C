/*
数学趣题

爱因斯坦的阶梯问题

爱因斯坦曾经出过这样一道有趣的数学题：
有一个长阶梯，
若每步上2阶，最后剩1阶；
若每步上3阶，最后剩2阶；
若每步上5阶，最后剩4阶；
若每步上6阶，最后剩5阶；
若每步上7阶，最后刚好一阶也不剩。
请问该阶梯至少有多少阶。


抽象为数学表达式：
x mod 2 =1
x mod 3 =2
x mod 5 =4
x mod 6 =5
x mod 7 =0


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;



int main()
{
	int x = 7, res, flag = 0;
	for (int i = 1; i < 1000; i++)
	{
		if ((x % 2 == 1) &&
			(x % 3 == 2) &&
			(x % 5 == 4) &&
			(x % 6 == 5) &&
			(x % 7 == 0))
		{
			res = x;
			flag = 1;
			break;
		}

		x = 7 * (i + 1);//x我7的整数倍
	}

	if (1 == flag)
	{
		//119 
		printf("The result of Einstein's question is %d", res);
	}

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

/*

119


*/
