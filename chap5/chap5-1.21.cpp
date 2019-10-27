/*

数学趣题

数字翻译器

输入一个正整数N，输出它的英文表达。
例如输入1，输出one，输入12，输出twelve.
输入135，输出 one hundred thirty five...



要弄清楚阿拉伯数字和英文表达的对应关系。
数字1~19，对应一个英文单词
20~99，
100~999，
1000~9999，
10000~999999 （英文没有万、十万）

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
using namespace std;

char data_1[19][10] = { "one", "two", "three", "four",
"five", "six", "seven", "eight",
"nine", "ten", "eleven", "twelve",
"thirteen", "forteen", "fifteen", "sixteen",
"seventeen", "eighteen", "ninteen"};

char data_2[8][10] = {
	"twenty", "thirty", "forty", "fifty",
	"sixty", "seventy", "eighty", "ninty" };


void translation_C(long b)
{
	long c;
	if (b <= 19)
	{
		printf("%s ", data_1[b - 1]);
	}
	else
	{
		c = b / 10;
		printf("%s ", data_2[c - 2]);
		c = b % 10;
		if (0 != c)
		{
			printf("%s ", data_1[c - 1]);
		}
	}
}


void translation_B(long a)
{
	long b;
	b = a / 100;
	if (b != 0)
	{
		translation_C(b);
		printf("hundred ");
	}
	b = a % 100;
	if (b != 0)
	{
		translation_C(b);
	}
}


void translation_A(long N)
{
	long a;
	if (0 == N)
	{
		printf("Zero \r\n");
		return;
	}
	a = N / 1000;
	if (a != 0)
	{
		translation_B(a);
		printf("thousand ");
	}
	a = N % 1000;
	if (a != 0)
	{
		translation_B(a);
	}
}

int main()
{
	long N;
	printf("Please input a longeger from 0~99999\r\n");
	scanf("%ld", &N);
	translation_A(N);



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
