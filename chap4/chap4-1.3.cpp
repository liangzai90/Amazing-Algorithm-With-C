/*

学校进行成绩分级管理

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



int main()
{
	int score;
	printf("Please input the score\r\n");
	scanf("%d", &score);

	if (score < 80)
	{
		if (score < 70)
		{
			if (score < 60)
			{
				printf("Level:E \r\n");
			}
			else 
				printf("Level:D \r\n");
		}
		else
		{
			printf("Level:C \r\n");
		}
	}
	else
	{
		if (score < 90)
		{
			printf("Level:B \r\n");
		}
		else
		{
			printf("Level:A \r\n");
		}
	}



	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

