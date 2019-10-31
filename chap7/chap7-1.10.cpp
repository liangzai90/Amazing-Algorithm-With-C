/*
数据结构趣题

判断完全二叉树

完全二叉树的定义是这样的：
深度为k的，有n个结点的二叉树，
当且仅当其每一个结点都与深度为k的满二叉树中的编号为1~n的结点相对应，
则它被称为完全二叉树。
所谓满二叉树就是：深度为k且有(2^k -1)个结点的二叉树。
其中，结点的编号约定为：编号从根结点其从上至下，自左向右地顺序编号。


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


typedef struct BiTNode
{
	char data;//结点的数据域
	struct BiTNode *LChild, *RChild;//指向左孩子和右孩子
}BiTNode, *BiTreePtr;

//创建一棵二叉树...传入指针的指针
void CreateBiTree(BiTreePtr* T, int* level1, int level2)
{
	char c;
	scanf("%c", &c);
	if (c == '#') *T = NULL;
	else
	{
		*T = (BiTNode*)malloc(sizeof(BiTNode));//创建根结点
		(*T)->data = c;//向根结点输入数据
		if (*level1 < level2)
		{
			*level1 = level2;
		}

		//递归创建左子树
		CreateBiTree(&((*T)->LChild), &(*level1), level2 + 1);
		//递归创建右子树
		CreateBiTree(&((*T)->RChild), &(*level1), level2 + 1);
	}
}


//判断是否是完全二叉树.1:yes; 0:no
int JusticCompleteBiTree(BiTreePtr T, int level, int n, int *flag)
{
	if (!T)
	{
		return 1;
	}
	if (n == level)
	{
		if (T->LChild == NULL && T->RChild != NULL) return 0;

		//同层的前面的结点无空指针，出现空指针
		if (*flag == 0)
		{
			if (T->RChild == NULL)
			{
				*flag = 1;
			}
		}
		else if (*flag == 1)
		{
			if (T->LChild != NULL || T->RChild!=NULL )
			{
				return 0;
			}
		}
	}

	if (level != n && level != n + 1)
	{
		if (T->LChild == NULL || T->RChild==NULL)
		{
			return 0;
		}
	}


	if (!JusticCompleteBiTree(T->LChild, level + 1, n, flag)) return 0;

	if (!JusticCompleteBiTree(T->RChild, level + 1, n, flag)) return 0;

	return 1;
}



int main()
{
	BiTreePtr T;
	int level1 = 0;
	int flag = 0;
	printf("Please input some character to create a binary tree \r\n");

	//创建一棵二叉树T，level1返回它的深度
	CreateBiTree(&T, &level1, 0);

	if (JusticCompleteBiTree(T, 0, level1 - 1, &flag))
	{
		printf("It is a complete binary tree .\r\n");
	}
	else
	{
		printf("It is NOT a complete binary tree .\r\n");
	}

	

	cout << endl;
	cout << "Hello World C Algorithm." << endl;
	system("pause");
	return 0;
}


/*

//先根遍历
abc##d##ef###



*/
