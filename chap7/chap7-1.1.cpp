/*

数学趣题(=)

顺序表的就地逆置
编写一个函数，实现顺序表的就地逆置，
也就是说利用原表的存储空间将顺序表（a1,a2,...an）
逆置为（an,an-1,...,a2,a1）


*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;


//静态顺序表的最大空间
#define MAXSIZE  10

typedef struct {
	int* base;
	int length;
}sqlist;


//实现顺序表的就地逆置
void reverseSQ(sqlist* sqList)
{
	int low = 0, high = sqList->length - 1;//low,high分别指向顺序表的首尾
	int buf = 0;
	for (int i = 0; i < sqList->length / 2; i++)
	{
		buf = sqList->base[low];
		sqList->base[low] = sqList->base[high];
		sqList->base[high] = buf;
		low++;
		high--;
	}
}



int main()
{	
	sqlist list;
	int a, i = 0;
	//创建一个顺序表
	list.base = (int *)malloc(sizeof(int)* MAXSIZE);
	list.length = 0;

	//输入数据 
	printf("Please input below 10 integer into the sqlist.\r\n");
	printf("Type -1 for stopping input \r\n");
	scanf("%d", &a);
	while (a != -1 && i <= 9)
	{
		list.base[i] = a;
		list.length++;
		i++;
		scanf("%d", &a);
	}

	//输出原顺序表中的数据
	printf("The contents of the sqlist are:\r\n");
	for (int k = 0; k < list.length; k++)
	{
		printf("%3d,", list.base[k]);
	}
	printf("\r\n");

	//就地逆置顺序表
	reverseSQ(&list);

	//输出 逆置后的 顺序表中的数据
	printf("The contents of the reversed sqlist are:\r\n");
	for (int k = 0; k < list.length; k++)
	{
		printf("%3d,", list.base[k]);
	}
	printf("\r\n");


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


