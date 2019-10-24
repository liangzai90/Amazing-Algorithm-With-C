/*

基于switch语句的译码器

优点：简单直观，容易理解，效率较高
缺点：代码量较大，如果码表庞大，代码量也会随之增大，比较机械，缺乏灵活性


前缀码：
a   0
b   01
c   001

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void Decode(char* str, int n)
{
	int i = 0;
	while (i < n)
	{
		switch (str[i])
		{
		case '1':
		{
					printf("a");//译码a(1) 
					break;
		}
		case '0':
		{
					i++;
					switch (str[i])
					{
					case '1':
					{
								printf("b");
								break;//译码b(01)
					}
					case '0':
					{
								i++;
								switch (str[i])
								{
								case '1':
								{
											printf("c");
											break;//译码c(001)
								}
								}
					}
					}
		}
		}

		i++;
	}
	printf("\r\n");
}


int main()
{
  //注意不要让数组越界了
	// "001011101001011001"  
	char str[19]= "001011101001011001";
	Decode(str,19);
	

	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

