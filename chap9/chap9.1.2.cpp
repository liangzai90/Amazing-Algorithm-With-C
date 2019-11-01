/*
综合题

计算24的问题
在屏幕上输入1~10范围内的4个整数（可以有重复），
对它们进行加、减、乘、除，四则运算后（可以任意的加括号限定计算的优先级），
寻找计算结果等于24的表达式。
 
例如输入4个整数4,5,6,7，可以得到表达式：4*((5-6)+7)=24.
这只是一个解，本题目要求输出全部的解。
要求表达式中数字的书序不能改变。


如果不考虑括号优先级，仅用四则运算符将他们链接，
例如： A+B*C/D...，共有4^3=64种表达情形。

如果考虑括号，不考虑运算符，有5种情形：
((A#B)#C)#D
(A#(B#C))#D
A#(B#(C#D))
A#((B#C)#D)
(A#B)#(C#D)

将AB,BC,CD之间的运算符分别设置为变量op1,op2,op3.
规定op1,op2,op3的取值范围是1，2,3,4，分别表示：加、减、乘、除。



*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <time.h>
#include <vector>
#include <malloc.h>
using namespace std;

#define MIN_NUMBER  1
#define MAX_NUMBER  50


int outArr[4] = { 0 };
int inArr[4] = {0};
int bookArr[4] = { 0 };
static int COUNT = 0;

char op[5] = { '#', '+', '-', '*', '/' };

float cal(float x, float y, int op)
{
	switch (op)
	{
	case 1:return x + y;
	case 2:return x - y;
	case 3:return x*y;
	case 4:return x / y;
	}
}


//((A#B)#C)#D
float calculate_model1(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2,  r3;
	r1 = cal(i, j, op1);
	r2 = cal(r1, k, op2);
	r3 = cal(r2, t, op3);

	if (r3 == 24.0f)
	{
		int a1 = 0;
	}

	return r3;
}


//(A#(B#C))#D
float calculate_model2(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(j, k, op2);
	r2 = cal(i, r1, op1);
	r3 = cal(r2, t, op3);

	if (r3 == 24.0f)
	{
		int a2 = 0;
	}

	return r3;
}


//A#(B#(C#D))
float calculate_model3(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(k, t, op3);
	r2 = cal(j, r1, op2);
	r3 = cal(i, r2, op1);

	if (r3 == 24.0f)
	{
		int a3 = 0;
	}

	return r3;
}


//A#((B#C)#D)
float calculate_model4(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(j, k, op2);
	r2 = cal(r1, t, op3);
	r3 = cal(i, r2, op1);

	if (r3 == 24.0f)
	{
		int a4 = 0;
	}

	return r3;
}


//(A#B)#(C#D)
float calculate_model5(float i, float j, float k, float t, int op1, int op2, int op3)
{
	float r1, r2, r3;
	r1 = cal(i, j, op1);
	r2 = cal(k, t, op3);
	r3 = cal(r1, r2, op2);
	
	if (r3 == 24.0f)
	{
		int a5 = 0;
	}

	return r3;
}

int get24(int i, int j, int k, int t)
{
	int flag = 0;
	for (int index1 = 1; index1 <= 4; index1++)
	{
		for (int index2 = 1; index2 <= 4; index2++)
		{
			for (int index3 = 1; index3 <= 4; index3++)
			{
				//((A#B)#C)#D
				if (calculate_model1(i, j, k, t, index1, index2, index3) == 24.0f)
				{
					printf("((%d%c%d)%c%d)%c%d=24\r\n", i, op[index1], j, op[index2], k, op[index3], t);
					flag = 1;
				}
				////(A#(B#C))#D
				if (calculate_model2(i, j, k, t, index1, index2, index3) == 24.0f)
				{
					printf("((%d%c(%d%c%d))%c%d=24\r\n", i, op[index1], j, op[index2], k, op[index3], t);
					flag = 1;
				}
				//A#(B#(C#D))
				if (calculate_model3(i, j, k, t, index1, index2, index3) == 24.0f)
				{
					printf("(%d%c(%d%c(%d%c%d))\r\n", i, op[index1], j, op[index2], k, op[index3], t);
					flag = 1;
				}
				//A#((B#C)#D)
				if (calculate_model4(i, j, k, t, index1, index2, index3) == 24.0f)
				{
					printf("(%d%c((%d%c%d)%c%d)=24\r\n", i, op[index1], j, op[index2], k, op[index3], t);
					flag = 1;
				}
				//(A#B)#(C#D)
				if (calculate_model5(i, j, k, t, index1, index2, index3) == 24.0f)
				{
					printf("((%d%c%d)%c(%d%c%d)=24\r\n", i, op[index1], j, op[index2], k, op[index3], t);
					flag = 1;
				}
			}
		}
	}

	return flag;
}


void findSolution(int inArr[], int outArr[], int bookArr[], int step)
{
	if (step >= 4)
	{
		//printf("count:%d,one solution:%d,%d,%d,%d\r\n", COUNT, outArr[0], outArr[1], outArr[2], outArr[3]);
		if (1 == get24(outArr[0], outArr[1], outArr[2], outArr[3]))
		{
			COUNT++;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		if (bookArr[i] == 0)
		{
			bookArr[i] = 1;
			outArr[step] = inArr[i];
			findSolution(inArr, outArr, bookArr, step + 1);
			bookArr[i] = 0;
		}
	}
}

int main()
{
	//////扩展，i,j,k,t顺序不固定的情况
	//findSolution(inArr, outArr, bookArr, 0);///输出4个数的全排列情况


	int i, j, k, t;
	printf("Please input four integer(1~50)\r\n");
	scanf("%d %d %d %d", &i, &j, &k, &t);
	if (i<MIN_NUMBER || i>MAX_NUMBER ||
		j<MIN_NUMBER || j>MAX_NUMBER ||
		k<MIN_NUMBER || k>MAX_NUMBER ||
		t<MIN_NUMBER || t>MAX_NUMBER)
	{
		printf("Input illege,Please input again \r\n");
		system("pause");
		return 0;
	}

	//if (get24(i,j,k,t))
	//{
	//	printf("Get 24 !!!");
	//}
	//else
	//{
	//	printf("Sorry,the four integer cannot be calculated to get 24.\r\n");
	//}

	inArr[0] = i;
	inArr[1] = j;
	inArr[2] = k;
	inArr[3] = t;
	findSolution(inArr, outArr, bookArr, 0);
	if (0 == COUNT)
	{
		printf("Sorry,None solution.\r\n");
	}
	else
	{
		printf("Total %d solution.\r\n", COUNT);
	}



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

Please input four integer(1~50)
17 15 2 5
((17*2)-15)+5=24
((17*2)-(15-5)=24
((17*2)+5)-15=24
((17*2)+(5-15)=24
((2*17)-15)+5=24
((2*17)-(15-5)=24
((2*17)+5)-15=24
((2*17)+(5-15)=24
((5+(17*2))-15=24
(5+((17*2)-15)=24
((5-15)+(17*2)=24
(5-(15-(17*2))
((5-15)+(2*17)=24
(5-(15-(2*17))
((5+(2*17))-15=24
(5+((2*17)-15)=24
Total 8 solution.




*/
