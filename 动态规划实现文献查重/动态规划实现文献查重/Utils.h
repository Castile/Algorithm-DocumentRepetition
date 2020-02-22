#pragma once
#include "include.h"

using namespace std;

/*
	句子处理的工具类
	Created By 朱宏梁
	2018年1月3日 11:42:51
*/
namespace sentenceTools {

	/*
	从一个句子中拿出全部的单词

	*/
	int wordSplit(string sentence, string wordList[])
	{
		int m = 0;

		string Word;

		text = sentence.c_str(); //转化成字符数组

		for (int k = 0; k < strlen(text); k++)
		{
			if ((text[k] >= 'a') && (text[k] <= 'z') || (text[k] >= 'A') && (text[k] <= 'Z'))
			{
				Word += text[k];
			}
			if ((text[k + 1] < 'A') || ((text[k + 1] > 'Z') && (text[k + 1] < 'a')) || (text[k + 1] > 'z'))
			{
				if (Word != "")
				{
					wordList[m] = Word;

					m++;

					Word = "";  // 重置
				}
			}

		}
		return m;
	}



	//打印矩阵
	template <typename T>
	void printMatrix(T **wordSimilarity,int row,int col)
	{
		ofstream score;
		score.open("score.txt");
		for (int i = 0; i < row; i++)
		{
			for (int j = 0; j < col; j++)
			{
				score << wordSimilarity[i][j] << "\t";
			}
			cout << endl;
		}
	}

}
