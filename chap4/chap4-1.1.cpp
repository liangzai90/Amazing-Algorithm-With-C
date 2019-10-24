/*

编写一个C程序，在终端用键盘输入字符串，以Ctrl+Z组合键表示输入完毕，统计输入的字符串中空格符、制表符、换行符的个数，并显示统计结果

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



int main()
{
	char cTemp;
	int space = 0, table = 0, enter = 0;
	
	//ASCII code:A 65
	printf("ASCII code:%c %d \r\n", 'A','A');//输出A的ASCII码

	printf("Please input a string:\r\n");
	scanf("%c", &cTemp);
	while (cTemp != 'A')
	{
		switch (cTemp)
		{
		case 32:
		{
				   space++;//过滤空格符
				   break;
		}
		case 9:
		{
				  table++;//过滤制表符
				  break;
		}
		case 10:
		{
				   enter++;//过滤换行符
				   break;
		}
		default:
			break;
		}

		scanf("%c", &cTemp);//继续输入字符
	}

	printf("The number of space:%d \r\n", space);
	printf("The number of table:%d \r\n", table);
	printf("The number of enter:%d \r\n", enter);

	cout << "Hello World C++ Algorithm." << endl;
	system("pause");
	return 0;
}

