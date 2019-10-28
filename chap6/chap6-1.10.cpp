/*

数学趣题(=)

马克思手稿中的数学题
伟大的思想家马克思的手稿中有这样一道有趣的数学题：
有30个人，其中有男人、女人和小孩。
他们在一家饭店中吃饭，共花费50先令。
如果每个男人吃饭要花3先令，
每个女人要花2先令，
每个小孩要花1先令，
问男人、女人、小孩各为多少人？


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
	for (int man = 1; man < 30; man++)
	{
		for (int woman = 1; woman < 30; woman++)
		{
			for (int child = 1; child < 30; child++)
			{
				if (man * 3 + woman * 2 + child == 50 &&
					(man + woman + child==30))	
				{
					printf("man:%d,woman:%d,child:%d\r\n", man, woman, child);					
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

man:1,woman:18,child:11
man:2,woman:16,child:12
man:3,woman:14,child:13
man:4,woman:12,child:14
man:5,woman:10,child:15
man:6,woman:8,child:16
man:7,woman:6,child:17
man:8,woman:4,child:18
man:9,woman:2,child:19



*/
