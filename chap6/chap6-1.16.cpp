/*

数学趣题(=)

选美比赛

在选美比赛现场，有一批选手参赛，比赛的规则是最后得分越高，名次越低。
当比赛结束时，要在现场按照参赛选手的出场顺序（即选手编号）宣布最后得分和最后名词，
获得相同分数的选手具有相同的名次，名次连续编号，不用考虑同名次选手的人数。

例如：
选手序号为：   1,2,3,4,5,6,7
选手得分为：   5,3,4,7,3,5,6
则输出名次为： 3,1,2,5,1,3,4


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


typedef struct tagPlayerInfo
{
	int Numb;
	int Score;
	int Rank;
}PlayerInfoDef;


//按照名词排列一次
void bubbleSort(PlayerInfoDef pArr[])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7 - i -1; j++)
		{
			if (pArr[j].Score > pArr[j + 1].Score)
			{
				PlayerInfoDef iTempInfo = pArr[j + 1];
				pArr[j + 1] = pArr[j];
				pArr[j] = iTempInfo;
			}
		}
	}
}

//按照序号再排列一次
void bubbleSort2(PlayerInfoDef pArr[])
{
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 7 - i - 1; j++)
		{
			if (pArr[j].Numb > pArr[j + 1].Numb)
			{
				PlayerInfoDef iTempInfo = pArr[j + 1];
				pArr[j + 1] = pArr[j];
				pArr[j] = iTempInfo;
			}
		}
	}
}


int main()
{	
	PlayerInfoDef pArr[7] = { 0 };
	for (int i = 0; i < 7; i++)
	{
		pArr[i].Numb = i+1;
	}
	pArr[0].Score = 5;
	pArr[1].Score = 3;
	pArr[2].Score = 4;
	pArr[3].Score = 7;
	pArr[4].Score = 3;
	pArr[5].Score = 5;
	pArr[6].Score = 6;

	bubbleSort(pArr);

	int iRank = 1;
	for (int i = 1; i < 7; i++)
	{
		if (pArr[i - 1].Score != pArr[i].Score)
		{
			pArr[i - 1].Rank = iRank;
			iRank++;
			pArr[i].Rank = iRank;
		}
		else
		{
			pArr[i-1].Rank = iRank;
			pArr[i].Rank = iRank;
		}
	}


	bubbleSort2(pArr);
	printf("Rank:");
	for (int i = 0; i < 7; i++)
	{
		printf("%3d,", pArr[i].Rank);
	}

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
