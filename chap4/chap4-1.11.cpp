/*

文件大小计算

编写一个程序，用来计算指定文件的大小。

I/O函数中，有两个经常被使用的函数fseek(),ftell().
fseek(FILE* fp, long offset, int base); 重定位流上的文件指针，即将fp指向的文件的位置指针移向以base为基准，以offset为偏移量的位置。
ftell(FILE* fp);返回当前文件指针的位置。这个位置是指当前文件指针相对于文件开头的位移量。

因此可以先通过fseek()将文件的指针定位到文件的最后 SEEK_END，然后通过函数 ftell() 返回当前文件指针相对于文件开头的偏移量，也就是文件的长度。

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main()
{
	FILE *myf;
	long f;
	myf = fopen("abc.mp3", "r");//打开当前目录下的abc.txt文件
	fseek(myf, 0, SEEK_END);//将文件指针置于最后
	f = ftell(myf);//返回文件长度
	fclose(myf);

	printf("The length of the file is %ld bytes. \r\n", f);

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
