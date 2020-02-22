#pragma once

#include <iostream>
#include <cstdio>
#include "struct.h"



using namespace std;


/*

	规范格式打印

	Created By 朱宏梁
	2018年1月3日 11:01:14
*/
namespace printSentence {

	void printList(textStruct text[],int count)
	{
		printf("句子 \t\t\t单词个数\n");
		for (int t = 0; t < count; t++)
		{
			printf("%-20s\t %10d\n", text[t].textSentence.c_str(),text[t].wordCount);  //右对齐，15位长度，不够补空格
																			   //cout << word[t].sequence <<"\t\t\t\t\t"<<word[t].freq<< endl;
		}
	}
}