/*

数学趣题

舍罕王的失算
2的n次方问题


需要引用头文件 <math.h>
pow(x,y),的作用是计算 x的y次方


只有double 和 long double类型的数据可以容纳这么大的数。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;



int main()
{
    long double llSum = 0;
	for (int i = 1; i <= 64; i++)
	{
		llSum = llSum + pow(2, i - 1);//累加求和
	}
	printf("The number of the grain is:\r\n %lf \r\n", llSum);

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

