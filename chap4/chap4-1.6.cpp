/*

编写一个函数inputArray()，该函数被主函数调用，通过该函数实现向主函数中定义的数组输入数据

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

void inputArray(int* array, int len)
{
	for (int i = 0; i < len; i++ )
	{
		scanf("%d", array + i);//指向数组中第i个元素的指针，也就是数组第i个元素的地址，等价于 &array[i]
	}
}

int main()
{
	int array[10];
	printf("Please input data for array \r\n");
	inputArray(array, 10);

	for (int i = 0; i < 10; i++)
	{
		printf("%d ,", array[i]);
	}



	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}

