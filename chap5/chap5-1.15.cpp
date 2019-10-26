/*
数学趣题

求 派 的近似值


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

//方法1
double getPI(int n)
{
	int i = 4;
	double b = sqrt(2) / 2.0f;
	double c = 0.0f;
	for (int div = 0; div < n; div++)
	{
		b = sqrt(2.0 - 2.0*sqrt(1.0 - b*b))*0.5;///如果n太大，这里的b会变成特别小的小数，直到变成0
		i = i * 2;
	}

	c = b*i;
	return c;
}



//
////方法2
//double getPI(int n)
//{
//	int inCircle = 0;
//	float x, y;
//	int count = n;
//	while (count)
//	{
//		srand(count);
//		x = rand()%101;
//		y = rand()%101;
//		if (x*y + y*y <= 10000)
//		{
//			inCircle++;
//		}
//		count--;
//	}
//
//	return (4.0*inCircle / n);
//}


int main()
{
	int n;
	double PI;
	printf("Please enter accuracy \r\n");
	scanf("%d", &n);
	PI = getPI(n);
	printf("The simulater value of PI is %f \r\n", PI);




	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

/*



*/
