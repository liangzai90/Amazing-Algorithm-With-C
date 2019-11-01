/*
综合题


马踏棋盘

国际象棋的棋盘为8*8的方格棋盘。
现将“马”放在任意指定的方格中，按照“马”走棋的规则，将“马”进行移动。
要求每个方格只能进入一次，最终使得“马”走遍棋盘的64个方格。
编写一个C程序，实现马踏棋盘操作，
要求用1~64这64个数字标注马移动的路径，
也就是按照要求出的行走路线，
将数字1,2，...64一次填入棋盘的方格中，并输出。



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

#define BOARD_WIDE    8
#define BOARD_HEIGHT  8

typedef struct moveMap
{
	int x;
	int y;
	int number;//棋盘编号
	int step;//第N步
}moveMap;


int nextMove[8][2] = {
	{1,-2},
	{2,-1},
	{2,1},
	{1,2},
	{-1,-2},
	{-2,-1},
	{-1,2},
	{-2,1}
};

//记录行走轨迹
moveMap moveLine[64] = { 0 };
int bookLine[65] = { 0 };//标记某个点是否走过 



void PrintSolution(moveMap moveLine[])
{
	for (int i = 0; i < BOARD_WIDE*BOARD_WIDE; i++)
	{
		printf("%d:(X:%d,Y:%d).[%d]\r\n", moveLine[i].step, moveLine[i].x, moveLine[i].y, ((moveLine[i].y - 1) * BOARD_WIDE + moveLine[i].x));
	}
}


void HorseMove(int startX, int startY, moveMap moveLine[], int step ,int *flag)
{
	if (step >= BOARD_WIDE*BOARD_WIDE)
	{
		printf("\r\n------------------------get one solution.\r\n");
		PrintSolution(moveLine);
		*flag = 1;//找到标记，只输出一种结果
		return;
	}
	if (*flag == 1)
	{
		return;
	}
	//if (startX<1 || startX>BOARD_WIDE || startY<1 || startY>BOARD_WIDE)
	//{
	//	return;//wrong solution.
	//}

	for (int i = 0; i < BOARD_WIDE; i++)
	{
		int iTempPos = 0;
		int iTempX = startX + nextMove[i][0];
		int iTempY = startY + nextMove[i][1];
		iTempPos = (iTempY - 1) * BOARD_WIDE + iTempX;

		if (iTempX<1 || iTempX>BOARD_WIDE || iTempY<1 || iTempY>BOARD_WIDE)
		{
			continue;
		}
		if (iTempPos<1 || iTempPos>64)
		{
			continue;
		}

		if (bookLine[iTempPos] == 0)
		{
			//此处未走过
			bookLine[iTempPos] = 1;
			moveLine[step].x = iTempX;
			moveLine[step].y = iTempY;
			moveLine[step].step = step;
			moveLine[step].number = iTempPos;//棋盘编号

			//最后一个点找到的时候，一定会走到了这里...
			//然后，再次调用 HorseMove... 然后就结束了
			HorseMove(iTempX, iTempY, moveLine, step + 1, flag);
			bookLine[iTempPos] = 0;
		}
	}
	return;
}




int main()
{
	int startX = 3;
	int startY = 5;
	int falg = 0;
	//scanf("%d %d", &startX, &startY);
	bookLine[(startY - 1) * BOARD_WIDE + startX] = 1;//标记起点
	moveLine[0].x = startX;
	moveLine[0].y = startY;
	moveLine[0].number = (startY - 1) * BOARD_WIDE + startX;
	moveLine[0].step = 0;
	
	HorseMove(startX, startY, moveLine, 1, &falg);


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*


(3,5)start
------------------------get one solution.
0:(X:3,Y:5).[35]
1:(X:4,Y:3).[20]
2:(X:5,Y:1).[5]
3:(X:7,Y:2).[15]
4:(X:8,Y:4).[32]
5:(X:6,Y:3).[22]
6:(X:7,Y:1).[7]
7:(X:8,Y:3).[24]
8:(X:6,Y:2).[14]
9:(X:8,Y:1).[8]
10:(X:7,Y:3).[23]
11:(X:8,Y:5).[40]
12:(X:6,Y:4).[30]
13:(X:7,Y:6).[47]
14:(X:8,Y:8).[64]
15:(X:6,Y:7).[54]
16:(X:7,Y:5).[39]
17:(X:8,Y:7).[56]
18:(X:6,Y:6).[46]
19:(X:7,Y:4).[31]
20:(X:8,Y:2).[16]
21:(X:6,Y:1).[6]
22:(X:5,Y:3).[21]
23:(X:6,Y:5).[38]
24:(X:8,Y:6).[48]
25:(X:7,Y:8).[63]
26:(X:5,Y:7).[53]
27:(X:4,Y:5).[36]
28:(X:3,Y:3).[19]
29:(X:4,Y:1).[4]
30:(X:2,Y:2).[10]
31:(X:3,Y:4).[27]
32:(X:5,Y:5).[37]
33:(X:3,Y:6).[43]
34:(X:4,Y:8).[60]
35:(X:2,Y:7).[50]
36:(X:1,Y:5).[33]
37:(X:2,Y:3).[18]
38:(X:1,Y:1).[1]
39:(X:3,Y:2).[11]
40:(X:1,Y:3).[17]
41:(X:2,Y:1).[2]
42:(X:4,Y:2).[12]
43:(X:5,Y:4).[29]
44:(X:4,Y:6).[44]
45:(X:3,Y:8).[59]
46:(X:1,Y:7).[49]
47:(X:2,Y:5).[34]
48:(X:4,Y:4).[28]
49:(X:5,Y:2).[13]
50:(X:3,Y:1).[3]
51:(X:1,Y:2).[9]
52:(X:2,Y:4).[26]
53:(X:1,Y:6).[41]
54:(X:2,Y:8).[58]
55:(X:4,Y:7).[52]
56:(X:6,Y:8).[62]
57:(X:5,Y:6).[45]
58:(X:7,Y:7).[55]
59:(X:5,Y:8).[61]
60:(X:3,Y:7).[51]
61:(X:1,Y:8).[57]
62:(X:2,Y:6).[42]
63:(X:1,Y:4).[25]



*/
