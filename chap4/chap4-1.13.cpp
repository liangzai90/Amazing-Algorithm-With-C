/*

十进制/二进制 转换器

编写一个程序，将输入的十进制转化为二进制表示。例如输入十进制64，输出二进制表示 1000000.

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void deTobi(int a)
{
	int i = 0,r=0,s=0;
	int stack[10];
	do{
		r = a / 2;//商
		s = a % 2;//余数
		stack[i] = s;

		if (r != 0)
		{
			i++;
			a = r;
		}
	} while (r);///循环，知道商r为0为止

	for (; i >= 0; i--)
	{
		printf("%d", stack[i]);
	}
}

int main()
{
	int a;
	printf("Please input a Decimal digit less than 1023 \r\n");
	scanf("%d", &a);
	deTobi(a);


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
