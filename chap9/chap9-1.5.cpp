/*
综合题

八皇后求解
八皇后问题是一道经典的数学问题。
问题描述为：求解如何在一个8*8的棋盘上，
无冲突地摆放8个皇后棋子。
在国际象棋里，皇后的移动方式为横竖交叉的，
因此在任意一个皇后所在的位置的水平、竖直，以及45度斜线上都不能出现皇后的棋子。

求出所有复合要求的摆放方法。



*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <malloc.h>
using namespace std;

#define BOARD_WIGHT  8

typedef struct quenePos
{
	int x;
	int y;
	int seriNum; // y*BOARD_WIGHT+x....从0开始编号
	int state;//0:未放下，1:放下
}quenePos;

static int CountNum = 0;


//横着
bool checkLine1(int checkX, int checkY, int posX, int posY)
{
	//不是同一点，而且都在同一横轴上
	if (checkY == posY) return false;

	return true;
}

//竖着
bool checkLine2(int checkX, int checkY, int posX, int posY)
{
	//不是同一点，而且都在同一竖轴上
	if (checkX == posX) return false;

	return true;
}


//左斜着...计算斜率。斜率 k = (Y2-Y1)/(X2-X1)
bool checkLine3(int checkX, int checkY, int posX, int posY)
{
	//不是同一点，而且都在同一竖轴上...斜率为1
	if (posY - checkY == posX - checkX) return false;
	
	return true;
}

//右斜着
bool checkLine4(int checkX, int checkY, int posX, int posY)
{
	//不是同一点，而且都在同一竖轴上...斜率为-1
	if (posY - checkY == -(posX - checkX)) return false;

	return true;
}

bool checkValid(quenePos eightQuene[], int posX, int posY)
{
	bool bYes = true;
	for (int i = 0; i < BOARD_WIGHT; i++)
	{
		if (1 == eightQuene[i].state)
		{
			if (!checkLine1(eightQuene[i].x, eightQuene[i].y, posX, posY) ||
				!checkLine2(eightQuene[i].x, eightQuene[i].y, posX, posY) ||
				!checkLine3(eightQuene[i].x, eightQuene[i].y, posX, posY) ||
				!checkLine4(eightQuene[i].x, eightQuene[i].y, posX, posY))
			{
				bYes = false;
				return bYes;
			}
		}
	}

	return bYes;
}


void PrintOneSolution(quenePos eightQuene[])
{
	printf("One solution:\r\n");
	int checkMap[BOARD_WIGHT][BOARD_WIGHT] = { 0 };
	CountNum++;
	for (int i = 0; i < BOARD_WIGHT; i++)
	{
		//printf("%d:(%d,%d), ", eightQuene[i].seriNum, eightQuene[i].x, eightQuene[i].y);
		checkMap[eightQuene[i].x][eightQuene[i].y] = 1;
	}

	for (int i = 0; i < BOARD_WIGHT; i++)
	{
		for (int j = 0; j < BOARD_WIGHT; j++)
		{
			printf("%2d", checkMap[i][j]);
		}
		printf("\r\n");
	}
	printf("CountNum:%d-------------------------------\r\n", CountNum);
}


//我自己没有解出来。问题出在，不知道如何去拆分、分解问题。
//////首先问题出在了函数参数的设计上
///其次，没有想清楚，如何一行，一行去解决放置问题.
///最后，遍历所有的解，也是无头绪的！！！
//判断函数，一行一行的判断....检测 第startRow行 的 全部8列，是否有满足条件的
void PlaceQuene(quenePos eightQuene[], int startRow)
{
	//输出一种结果
	if (startRow == BOARD_WIGHT)
	{
		PrintOneSolution(eightQuene);
		return;
	}

	//检测 第startRow行 的 全部8列，是否有满足条件的
	for (int iColum = 0; iColum < BOARD_WIGHT; iColum++)
	{
		if (eightQuene[startRow].state == 0 && checkValid(eightQuene, startRow, iColum))
		{
			eightQuene[startRow].x = startRow;
			eightQuene[startRow].y = iColum;
			eightQuene[startRow].state = 1;
			eightQuene[startRow].seriNum = startRow;

			//检测下一行
			PlaceQuene(eightQuene, startRow+1);

			eightQuene[startRow].x = 0;
			eightQuene[startRow].y = 0;
			eightQuene[startRow].state = 0;
			eightQuene[startRow].seriNum = 0;
		}
	}
}




int main()
{
	quenePos eightQuene[BOARD_WIGHT] = { 0 };

	PlaceQuene(eightQuene, 0);//总共92种情况



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*


One solution:
1 0 0 0 0 0 0 0
0 0 0 0 1 0 0 0
0 0 0 0 0 0 0 1
0 0 0 0 0 1 0 0
0 0 1 0 0 0 0 0
0 0 0 0 0 0 1 0
0 1 0 0 0 0 0 0
0 0 0 1 0 0 0 0







*/
