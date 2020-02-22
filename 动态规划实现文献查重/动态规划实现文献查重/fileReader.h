#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

#define N 100

using namespace std;

/*
	文件读取功能
	Created By 朱宏梁
	2018年1月3日 10:15:05
*/
string  read(char* fileName)
{
	char *str = new char[N + 1];

	string text = "";

	char *p = fileName;
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
		text += str;
	}
	
	printf("\t\t\t\t读取完毕！\n\n\n\n\n");

	
	return text;
}