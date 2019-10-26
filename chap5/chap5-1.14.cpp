/*
数学趣题

常胜将军

现有21根火柴，两人轮流取，没人每次可以取走1~4根，不可夺取，也不能不取，
谁取走最后一根火柴谁输。

请编写一个程序进行人机对弈，要求人先取，计算机后取；
计算机一方为“常胜将军”。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

	

int main()
{
	int computer, people, spare = 21;
	printf("-------------------------------------\r\n");
	printf("-------------你不能战胜我，不信试试-------\r\n");
	printf("-------------------------------------\r\n");
	printf("Game Begin:\r\n\n");

	while (1)
	{
		printf("--------------------目前还有火柴 %d 根----------\r\n", spare);
		printf("People:");
		scanf("%d",&people);
		if (people<1 || people>4 || people > spare)
		{
			printf("你违规了，你取的火柴数有问题！\r\n");
			continue;
		}
		
		spare = spare - people;
		if (spare == 0)
		{
			printf("\r\nComputer win! GameOver!\r\n");
			break;
		}

		computer = 5 - people;////计算机取火柴
		spare = spare - computer;
		printf("Computer:%d \r\n", computer);
		if (spare == 0)
		{
			printf("People Win! Game Over!\r\n");
			break;
		}
	}



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
