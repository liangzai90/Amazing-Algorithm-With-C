/*

输入一个年份，判断该年是否是闰年

所谓闰年，是要符合下面两个条件之一：
1.该年份能被4整除，但不能被100整除
2.该年份能被4整除，有能被400整除

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int main()
{
	int year;
	printf("Please input a yera:\r\n");
	scanf("%d", &year);

	//判断是否是闰年
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		printf("%d is leap year!\r\n", year); //判断是闰年
	}
	else
	{
		printf("%d is not leap year!\r\n", year);
	}

	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

