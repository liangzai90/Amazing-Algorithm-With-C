/*

一年中的第几天

输入某年某月某日，判断这一天是这一年中的第几天？

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int Day(int year, int month, int date)
{
	int monthArr[13] = { 0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	int days = 0;
	if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
	{
		monthArr[2] = 29;//判断是否是闰年
	}
	else
	{
		monthArr[2] = 28;
	}

	//计算天数
	for (int i = 1; i < month; i++)
	{
		days = days + monthArr[i];
	}

	days = days + date;
	return days;
}


int main()
{
	//计算2009.3.6是本年度第几天
	printf("The days of 6th Match 2009 is %d \r\n", Day(2009, 3, 6));



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

