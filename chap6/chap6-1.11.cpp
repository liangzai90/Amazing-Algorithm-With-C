/*

数学趣题(=)

渔夫捕鱼问题
ABCDE这5个渔夫夜间合伙捕鱼，凌晨时都疲倦不堪，各自在河边的树丛中找地方睡着了。
待日上三竿，渔夫A第1个醒来，他将鱼分作5份，把多余的一条扔回河中，拿走自己的一份回家去了。
渔夫B第2个醒来，也将鱼分作5分，扔掉多余的一条，拿走自己的一份，
接着CDE依次醒来，也都按照同样的办法分鱼，问5个渔夫至少合伙捕了多少条鱼？


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

//假设最多尝试10000次计算
#define MAX_N  10000  



int main()
{
	int left_fish = 0;
	int flag = 0;
	int s = 0;
	for (int n = 1; n < MAX_N; n++)
	{
		left_fish = 5 * n + 1;//假设第5个渔夫醒来看到的鱼数，只能是5*n+1
		s = left_fish;//以假设left_fish为基础向上反推

		flag = 1;//标记是否全部反推成功

		for (int i = 0; i < 4; i++)//循环反推S4,S3,S2,S1
		{
			if (0 == (s * 5) % 4)
			{
				s = s * 5 / 4 + 1;	//从Sn反推 Sn-1 的结果
			}
			else
			{
				flag = 0;//返推过程中，出现非整数，flag=0,标记失败
				break;//跳出内层循环，调整left_fish重新反推
			}
		}

		if (1 == flag)
		{
			printf("Fish which were gotten by fishers at least are:%d \r\n", s);//输出结果
			break;
		}
	}

	


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Fish which were gotten by fishers at least are:3121



*/
