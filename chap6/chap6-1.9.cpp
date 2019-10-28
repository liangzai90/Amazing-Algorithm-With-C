/*

数学趣题(=)

三重回文数字

编写一个程序，找出1~999之间的所有三重回文数字。
所谓三重回文数a就是指a、a^2、a^3都是回文数字。


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


///////////注意不要越界，这是3次方了，可能会超过int
/////////传入的参数i，需要保留一个备份

//11~999
int isHuiwen(long i)
{
	long iTemp = i;//保留一个备份，用来比较是否是回文数
	long iTempValue = 0;
	while (i > 0)
	{
		iTempValue = 10 * iTempValue + i % 10;
		i = i / 10;
	}

	//判断是否是回文数
	if (iTemp == iTempValue)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

void isHuiwen_3()
{
	for (int k = 11; k <= 999; k++)
	{
		if (isHuiwen(k) && isHuiwen(k*k) && isHuiwen(k*k*k))
		{
			printf("%d is 3 huiwen. \r\n",k);
		}
	}
}


int main()
{


	isHuiwen_3();



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

11 is 3 huiwen.
101 is 3 huiwen.
111 is 3 huiwen.



*/
