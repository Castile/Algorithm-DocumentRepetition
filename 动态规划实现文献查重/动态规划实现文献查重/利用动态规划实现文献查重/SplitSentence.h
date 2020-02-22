#pragma once
#include <iostream>
#include <string.h>
#include "fileReader.h"
#include "struct.h"

using namespace std;


const char *text; //读取的被查询的文献
const char *lib;  // 保存读取的库文件
const char *textStr;


/*
	把文献分成单个句子保存在对应的数据结构中
	Created By 朱宏梁

	2018年1月3日 10:14:40
*/


int sentenceSplit(char *fileName, textStruct textStruct[])
 {
	int wordCount = 0; //  统计单词的个数

	int num = 0; // 句子的个数

	string tempSentence; // 用于存储当前处理的句子

	string Word; //临时存储单词

	// 读取文件
	string txt = read(fileName);

	//cout << txt << endl;

	textStr = txt.c_str(); // 转换成字符数组

	for (int k = 0; k < strlen(textStr); k++)
	{

		//int last = 0;// 记录句子最后一个字符的下标

		if ((textStr[k] >= 'a') && (textStr[k] <= 'z') || (textStr[k] >= 'A') && (textStr[k] <= 'Z'))
		{
			//tempSentence += textStr[k];
			Word += textStr[k];
		}
		if ((textStr[k + 1] < 'A') || ((textStr[k + 1] > 'Z') && (textStr[k + 1] < 'a')) || (textStr[k + 1] > 'z'))
		{
			if (Word != "")
			{
				wordCount++;

				tempSentence += Word + " ";

				Word = "";  // 重置
			}
		}
		if ((textStr[k] == '.') || (textStr[k] == '?') || (textStr[k] == '!'))
		{
			
			transform(tempSentence.begin(), tempSentence.end(), tempSentence.begin(), ::tolower);
			textStruct[num].textSentence = tempSentence;
			textStruct[num].wordCount = wordCount;
			tempSentence = ""; // 重置临时句子
			wordCount = 0; //重置
			num++;
		}

	}
	return num;

}