/*

数学趣题

 谁在说谎
3个嫌疑犯在法官面前各执一词，
甲说：乙在说谎；
乙说：丙在说谎
丙说：甲乙两人都在说谎。
法官为难了，甲乙丙三个人到低谁在说谎，谁说的是真话？


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


int main()
{
	for (int a = 0; a <= 1; a++)
	{
		for (int b = 0; b <= 1; b++)
		{
			for (int c = 0; c <= 1; c++)
			{
				if (((a &&!b) || (!a&&b)) &&
					((b&&!c) || (!b&&c)) &&
					((c&&a + b == 0) || (!c&&a + b != 0)))
				{
					printf("甲：told a %s \r\n", a ? "True" : "lie");
					printf("乙：told a %s \r\n", b ? "True" : "lie");
					printf("丙：told a %s \r\n", c ? "True" : "lie");
				}
			}
		}
	}





	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
