#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "wordUnit.h"

/*

	保存分割下来的单词，要求单词不重复

	Created By 朱宏梁
	2018年1月2日 19:58:33

*/
 int  wordSave(string word[],Unit verb[],int count)
{
	int numVerb = 0;// 该变量表示不同单词的数量

	int newWord = 1;  // 该单词用于标记一个单词是否收录进词汇表中

	for(int x = 0; x <= count; x++)
	{
		newWord = 1;  // 对每一个比较的单词都初始化为新单词
		int i = 0;
		while (i <= numVerb)
		{
			if (word[x] == verb[i].sequence)
			{
				verb[i].freq++;
				newWord = 0;

				break;
			}

			i++;
		}

		if (newWord == 1) 
		{
			// 将Word存入词汇表中，单词数量+1
			verb[numVerb].sequence = word[x];
			verb[numVerb].freq = 1;
			numVerb++;
		}
		

	}
	
	return numVerb;
}