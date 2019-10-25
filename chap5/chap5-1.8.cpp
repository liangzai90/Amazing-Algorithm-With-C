/*
数学趣题

新郎和新娘

3对新婚夫妇参加婚礼，3个新郎为A、B、C，3个新娘为X、Y、Z。
有人不知道谁和谁结婚，于是询问了6位新人中的3位，但听到的回答是这样的：

A说他将和X结婚
X说她的未婚夫是C
C说他将和Z结婚

这人听后知道他们在开玩笑，全是假话。请编程找出谁将和谁结婚。


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;

//配对条件筛选
int match(int i, int j, int k, char wife[])
{
	//A不和X结婚
	if (wife[i] == 'X') return 0;

	//X不和C结婚
	if (wife[k] == 'X') return 0;

	//C不和Z结婚
	if (wife[k] == 'Z') return 0;

	return 1;
}


int main()
{
	char husband[3] = { 'A', 'B', 'C' }, wife[3] = { 'X', 'Y', 'Z' };
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				if (i != j && i != k && j != k)
				{
					if (match(i, j, k, wife))
					{
						printf("husband wife:\r\n");
						printf("A---%c\r\n", wife[i]);
						printf("B---%c\r\n", wife[j]);
						printf("C---%c\r\n", wife[k]);
						printf("==========\r\n");
					}
				}
			}
		}
	}



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

/*

husband wife:
A---Z
B---X
C---Y
==========



*/
