/*

数学趣题(=)

具有特殊性质的数
有这样一个4位数abcd，它具有这样的性质abcd=(ab+cd)2.
其中，ab和cd为两个2位数，求这个4位数abcd.


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


void SpecialNum(int abcd)
{ 
	for (int ab = 10; ab <= 99; ab++)//ab从10开始
	{
		for (int cd = 0; cd <= 99; cd++)//cd是从0开始
		{
			if ((abcd == (ab + cd)*(ab + cd)) && (ab==abcd/100) && (cd ==abcd%100))
			{
				printf("(%d + %d)^2=%d \r\n", ab, cd, abcd);
			}
		}
	}
}




int main()
{
	for (int i = 1000; i < 9999; i++)
	{
		SpecialNum(i);
	}

	//SpecialNum(9801);

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

(20 + 25)^2=2025
(30 + 25)^2=3025
(98 + 1)^2=9801


*/
