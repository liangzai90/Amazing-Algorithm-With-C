/*

文件的读写

创建一个后缀名为 txt 的文件，并向改文件中写入一个字符串保存起来。再打开该文件，读出文件中的内容。


FILE* fopen(char* filename, char* type);//打开指定路径的文件
int fclose(FILE* fp);//关闭文件
int fread(void* buf, int size,int count,FILE* fp);//读取文件函数
int fwrite(void* buf,int size,int count,FILE* fp);//写文件函数

*/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;


int main()
{
	FILE* fp;
	char pathName[20], txt1[200] = { '\0' }, txt2[200] = { '\0' };
	int fileLen;
	printf("Please type the path name of the file \r\n");
	scanf("%s", pathName);

	//以写的方式打开文件
	fp = fopen(pathName, "w");//此处必须是小写
	//将字符串写入文件
	printf("Please input a string to this file.\r\n");
	scanf("%s", txt1);
	fileLen = strlen(txt1);
	fwrite(txt1, fileLen, 1, fp);// 将字符串内容写入文件
	fclose(fp);//关闭文件 
	printf("The file has been saved \r\n");
	printf("The content of the file: %s is \r\n", pathName);


	fp = fopen(pathName, "r");//以读的方式打开文件
	fread(txt2, fileLen, 1, fp);//将文件内容读入缓冲区
	printf("%s \r\n", txt2);
	fclose(fp);//关闭文件 


	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}
