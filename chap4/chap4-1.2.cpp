/*

编写一个程序，在终端输入一个字符，输出它的ASCII码

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
	
	printf("Please input a string:\r\n");

	while (1)
	{		
		scanf("%c", &cTemp);
		printf("The ASCII code of %c is %d \n", cTemp, cTemp);
		if (cTemp == 'A')
		{
			break;
		}
	}

	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

