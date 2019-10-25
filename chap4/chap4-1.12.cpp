/*

记录程序的运行时间

任意编写一段程序，要求记录并输出该段程序执行的时间。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>       //包含时间头文件
#include <dos.h>
#include <windows.h>//加这个头文件
using namespace std;


int main()
{
	clock_t  start, end;
	start = clock();//标记时间戳

	Sleep(3333);//间隔N秒

	end = clock();//标记时间戳

	printf("The time was: end:%d,,start:%d,,CLK_TCK:%d, ,,,%0.3f \r\n",end,start,CLK_TCK, ((float)(end - start) / CLK_TCK));

	float ft = (end - start) / CLK_TCK;
	cout << "time was:" << ft << endl;

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
