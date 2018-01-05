#pragma once
#include <iostream>
#include <string.h>
#include "fileReader.h"
#include "wordsSave.h"

using namespace std;
const char * text; // 将读入的文本存入text中

string Word = ""; //被分割的单词用word表示


/*
	单词分割函数
	Created By 朱宏梁

	2018年1月2日 19:58:42

*/
 int wordSplit(char * fileName,string wordlist[])
{
	int wordcount = 0; // 统计单词的个数
	int m = 0;
	// 文件读取
    string txt = readtext(fileName);

	cout << txt << endl;

	text = txt.c_str(); //转化成字符数组
	
	for(int k = 0; k < strlen(text); k++)
	{
		if ((text[k] >= 'a') && (text[k] <= 'z') || (text[k] >= 'A') && (text[k] <= 'Z'))
		{
			Word += text[k];
		}
		if ((text[k+1] < 'A') || ((text[k+1] > 'Z') && (text[k+1] < 'a')) || (text[k+1] > 'z'))
		{
			if (Word != "") 
			{
				transform(Word.begin(), Word.end(), Word.begin(), ::tolower); // 转换为小写
				//cout << Word << endl;

				wordlist[m] = Word;
				//cout << wordlist[m] << endl;
				wordcount = m;
				m++;
				//wordSave(Word);
				//cout << Word << endl;
				Word = "";  // 重置
			}
		}
	
	}
	return wordcount;
}