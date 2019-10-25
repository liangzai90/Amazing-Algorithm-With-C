/*

数学趣题

三色球问题

有红、黄、绿三种颜色的球，其中红球3个，黄球3个，绿球6个。
现将这12个球混放在一个盒子中，从中任意摸出8个球，编程计算摸出球的各种颜色搭配。


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <vector>
using namespace std;


/**************************方法1，穷举实现****************************************/
void Qiongju()
{
	printf("red yellow green \r\n");
	for (int red=0; red <= 3; red++)
	{
		for (int yellow = 0; yellow <= 3; yellow++)
		{
			for (int green = 0; green <= 6; green++)
			{
				if (red + yellow + green == 8)
				{
					printf("%3d %3d %3d\r\n", red, yellow, green);
				}
			}
		}
	}
}




/**************************方法2，递归实现**************************************/
//记录球色，过滤重复的情况
typedef struct tagRYG
{
	int red;
	int yellow;
	int green;
}RYGDef;
static vector<tagRYG> Result;

void InputResult(int red, int yellow, int green)
{
	int isRepeat = 1;
	for (vector<tagRYG>::iterator it1 = Result.begin(); it1 != Result.end(); ++it1)
	{
		if (it1->red == red && it1->yellow == yellow && it1->green == green)
		{
			//repeat result.
			isRepeat = 0;
			break;
		}
	}

	if (1 == isRepeat)
	{
		tagRYG temp;
		temp.red = red;
		temp.yellow = yellow;
		temp.green = green;
		Result.push_back(temp);
	}
}

void OutputResult()
{
	cout << "OutputResult:" << endl;
	for (vector<tagRYG>::iterator it1 = Result.begin(); it1 != Result.end(); ++it1)
	{
		printf("oneResult:r(%d),y(%d),g(%d)\r\n", it1->red,it1->yellow, it1->green);
	}
	cout << "Count is " << Result.size() << endl;
}

//递归查找
void Dfs(int red, int yellow, int green)
{
	if (red > 3 || yellow > 3 || green > 6)
	{
		return;//边界判断
	}

	if (red + yellow + green == 8)
	{		
		InputResult(red, yellow, green);
//		printf("oneResult:r(%d),y(%d),g(%d)\r\n", red, yellow, green);
		return;
	}

	for (int k = 0; k < 3; k++)
	{
		if (0 == k)
		{
			red++;
			Dfs(red, yellow, green);
			red--;
		}
		else if (1 == k)
		{
			yellow++;
			Dfs(red, yellow, green);
			yellow--;
		}
		else
		{
			green++;
			Dfs(red, yellow, green);
			green--;
		}
	}

	return;
}



int main()
{
	//穷举实现
	Qiongju();


	//递归实现
	Dfs(0,0,0);
	OutputResult();


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/* 


red yellow green
0   2   6
0   3   5
1   1   6
1   2   5
1   3   4
2   0   6
2   1   5
2   2   4
2   3   3
3   0   5
3   1   4
3   2   3
3   3   2



*/
