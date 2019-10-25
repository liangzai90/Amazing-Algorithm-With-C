/*

递归反向输出字符串

编写一个递归函数，实现将输入的任意长度的字符串反向输出的功能。例如输入字符串：ABCD，输出字符串: DCBA 

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//递归函数
void Print()
{
	char a;
	scanf("%c", &a);
	if (a != '#')
	{
		Print();//输入的字符不是结束标志 #,则递归调用 Print()
	}
	if (a != '#')//输出字符时，不输出#,也就是#不作为字符串内容输出
	{
		printf("%c", a);
	}
}



int main()
{
	printf("Please input a string ending for '#' \r\n");
	Print();



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

