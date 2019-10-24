/*

巧用位运算

用位运算操作实现两个整数的交换。例如 x1=5, x2=10,交换后x1=10, x2=5

巧妙采用位运算
a = a ^ b;
b = b ^ a;
a = a ^ b;

^为按位异或运算。

证明如下：
a'=a^b,(a'为中间值)
b = b^a'=b^(a^b)=b^a^b=b^b^a=0^a=a
同理，a = a'^b=a^b^a=b

利用了异或运算的结合律和交换律

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main()
{
	int a=555, b=66666;
	printf("a=%d,b=%d\r\n", a, b);

	a = a^b;
	b = b^a;
	a = a^b;

	printf("a=%d,b=%d\r\n", a, b);

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
