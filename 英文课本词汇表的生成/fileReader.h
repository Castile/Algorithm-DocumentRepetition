#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "wordUnit.h"

#define N 100


/*
	原始数据的读取

	Created By 朱宏梁

	2018年1月2日 19:53:59

*/

/*读取数据*/
string  readtext(char* text)
{
	char *str = new char[N + 1];

	string word = "";

	int numCount = 0;
	char *p = text;
	FILE *fp;
	int i = 0;
	if ((fp = fopen(p, "r")) == NULL)
	{
		printf("\t\t\t\t打开文件为%s失败! 请按任意键退出！\n", p);
		system("pause");
		exit(0);

	}

	while (fgets(str, 100, fp) != NULL)
	{
		word += str;
	}
	//numCount = i;
	printf("\t\t\t\t读取完毕！\n\n\n\n\n");

	/*int j = 0;
	while (word[j] != NULL)
	{
		printf("%c", word[j]);
		j++;
	}*/

	return word;
}