#pragma once
#pragma once
#include <cstdio>
#include <iostream>
//#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
//#include "dynamic.h"
#include "fileReader.h"
#include "SplitSentence.h"
#include "struct.h"
#include "print.h"
#include "Utils.h"

using namespace std;
string tempWord, libWord; // 表示从tempSentence与libSentence分别取的单词

						  /*
						  wordSimilarity : wordSimilarity[i][j]表示tempSentence的第i个单词与libSentence的第j个单词是否相同

						  score：score[m][n] 表示该矩阵运行动态规划算法时tempSentence与libSentence的比对得分

						  Created by 朱宏梁

						  2018年1月3日 11:34:13

						  */
void dynamic(int ** wordSimilarity, float **score)
{

	string test1 = "Machine learning allows computers to identify hidden insights and patterns without being explicitly programmed where to look.";

	string test2 = "Machine learning is a method of data analysis that automates analytical model building. Using algorithms that iteratively learn from data, machine learning allows computers to find hidden insights without being explicitly programmed where to look.";
	
	
	string *tempWord = new string[17];  // 存储tempSentence中的单词
	sentenceTools::wordSplit(test1, tempWord); //得到当前句子的所有单词
	//cout << p << endl;

	string *libWord = new string[35]; // 存储libSentence中的单词
	sentenceTools::wordSplit(test2, libWord); //得到lib文件中句子的全部单词
	//cout << u << endl;

	//得出相似矩阵：--->这个句子与当前lib中的句子
	for (int r = 0; r < 17; r++)
		{
			for (int t = 0; t < 35; t++)
				{
					if (tempWord[r] == libWord[t])
					{
						wordSimilarity[r][t] = 1;
					}
					else
					{
						wordSimilarity[r][t] = 0;
					}
				}
		}

			//计算score

	int m = 17; // score 
	int n = 35;

	for (int i = 1; i < m; i++)
	{
		if ((score[i - 1][0] - 0.5) > wordSimilarity[i][0] - 0.5*(i - 1))
		{
			score[i][0] = score[i][0] - 0.5;
		}
		else
		{
			score[i][0] = wordSimilarity[i][0] - 0.5*(i - 1);
		}
	}
	for (int i = 1; i < n; i++)
	{
		//score[0][i] = max(score[0][i - 1] - 0.5, wordSimilarity[0][i] - 0.5*(i - 1));
		if ((score[0][i - 1] - 0.5) > wordSimilarity[0][i] - 0.5*(i - 1))
		{
			score[0][i] = score[0][i - 1] - 0.5;
		}
		else
		{
			score[0][i] = wordSimilarity[0][i] - 0.5*(i - 1);
		}
	}
	for (int i = 1; i < m; i++)
	{
		for (int j = 1; j < n; j++)
		{
			//score[i][j] = max(score[i - 1][j] - 0.5, score[i][j - 1] - 0.5, score[i - 1][j - 1] + wordSimilarity[i][j]);
			if ((score[i - 1][j] - 0.5) >(score[i][j - 1] - 0.5))
			{
				score[i][j] = score[i - 1][j] - 0.5;
			}
			else
			{
				score[i][j] = score[i][j - 1] - 0.5;
			}
			if (score[i][j] < (score[i - 1][j - 1] + wordSimilarity[i][j]))
			{
				score[i][j] = score[i - 1][j - 1] + wordSimilarity[i][j];
			}
		}
	}

}

void printSimilarityMatrix(int **wordSimilarity)
{
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 35; j++)
		{
			cout << wordSimilarity[i][j] << "  ";
		}
		cout << endl;
	
	}
}

void printScoreMatrix(float **score)
{
	for (int i = 0; i < 17; i++)
	{
		for (int j = 0; j < 35; j++)
		{
			cout << score[i][j] << "  ";
		}
		cout << endl;
	
	}
}
