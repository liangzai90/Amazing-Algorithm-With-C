/*

复杂级数的前n项和

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;



int main()
{
	float m=1.0;//记录 (1/2)n
	float n = 1.0;//记录 n!
	float s = 0.0;//
	//前10项和,最外层循环控制加法运算
	for (int i = 1; i <= 10; i++)
	{
		for (int j = 0; j < i; j++)
		{
			m = m*0.5;//计算 (1/2)n
		}
		for (int j = 1; j <= i; j++)
		{
			n = n*j;//计算 n!
		}
		s = s + m*n;//累加
		m = 1.0;
		n = 1.0;
	}
	printf("Sn = %f \r\n", s);//输出结果



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
