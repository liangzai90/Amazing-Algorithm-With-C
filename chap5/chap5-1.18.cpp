/*
数学趣题

数字的全排列

输入一个数字序列，{a1,a2,a3,... an}
将该序列进行排列，并输出每一种排列方式

例如输入数字序列：1 3 5 ，会有6种排列方式

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

#define max 100
int book[max] = { 0 };
int b[max] = { 0 };

//书本介绍的递归实现
void Perm(int a[], int n, int s, int r[], int m)
{
	int flag = 0;
	int b[max];
	int j;
	for (int i = 0; i < n; i++)
	{
		flag = 1;
		r[s] = a[i];//复制数列a中第i个元素到数组
		j = 0;
		for (int k = 0; k < n; k++)//产生子序列b 
		{
			if (i != k)
			{
				b[j] = a[k];
				j++;
			}
		}

		Perm(b, n - 1, s + 1, r, m);//全排列子序列b
	}

	if (0 == flag)
	{
		printf("\r\n");
		for (int k = 0; k < m; k++)
		{
			printf("%3d", r[k]);//输出存放排列结果的数组r中的内容
		}
		printf("\r\n");
	}
}




////我的递归实现
void printDigit(int a[],int b[], int step, int maxStep=0)
{
	if (step >= maxStep)
	{
		for (int i = 0; i < maxStep; i++)
		{
			printf("%3d", b[i]);//一次遍历结束，输出我们的结果
		}
		printf("\r\n--------printDigit--------打印排列结果。\r\n");
		return;
	}

	for (int i = 0; i < maxStep; i++)
	{
		if (book[i] == 0)
		{
//			printf("%d", a[i]);
			book[i] = 1;
			b[step] = a[i];//保留这个数，后面要输出的
			printDigit(a,b, step + 1, maxStep);
			book[i] = 0;
		}
	}
	return;
}



int main()
{
	int a[max] = { 0 }, r[max] = { 0 };
	int n;
	printf("Please input the number of digit in the array \r\n");
	scanf("%d", &n);
	printf("Please input a string for array \r\n");
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	Perm(a, n, 0, r, n);


	cout << "================>>>>>>>>>>>>>>>" << endl;
	printDigit(a,b, 0, n);

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*



*/
