#pragma once

#include <iostream>
#include "wordUnit.h"
#include "wordSort.h"
#include "wordsSave.h"
using namespace std;


/*

	规范格式打印单词表Dao控制台上

	Created By 朱宏梁
	2018年1月2日 19:55:13
*/
namespace printWordTable{

	void printList(Unit word[],int numVerb)
	{
		printf("单词 \t\t\t频率\n");
		for (int t = 0; t < numVerb; t++)
		{
			printf("%-10s\t %10d\n", word[t].sequence.c_str(),word[t].freq);  //右对齐，15位长度，不够补空格
			//cout << word[t].sequence <<"\t\t\t\t\t"<<word[t].freq<< endl;
		}
	}
}