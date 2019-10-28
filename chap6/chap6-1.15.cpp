/*

数学趣题(=)

汉诺塔
一块地板上有三根针：A、B、C。
A针上套有64个大小不等的圆盘，大的在下，小的在上。
要把这64个圆盘从A移到C，每次只能移动一个圆盘，移动可以借助B针进行。
在任何时候，针上的圆盘都必须保持大盘在下，小盘在上。
求移动的步骤。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


void move(int n,char A,char B,char C)
{
	if (1 == n)
	{
		printf("%c-->%c\r\n",A,C);
	}
	else
	{
		move(n - 1, A, C, B);//上面n-1个盘移动到了B

		printf("%c-->%c\r\n", A, C);//最下面一个盘，从A移动到C

		move(n - 1, B, A, C);//借助A,将剩余的盘移动到C 
	}	
}



int main()
{
	int n;
	printf("Please input diskes number:\r\n");
	scanf("%d", &n);
	printf("The step to moving %d diskes:\r\n", n);
	move(n, 'A', 'B', 'C');


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input diskes number:
3
The step to moving 3 diskes:
A-->C
A-->B
C-->B //上面的n-1个移动到了B 

A-->C //最下面一个盘，从A移动到C

B-->A //借助A,将剩余的盘移动到C 
B-->C
A-->C


*/
