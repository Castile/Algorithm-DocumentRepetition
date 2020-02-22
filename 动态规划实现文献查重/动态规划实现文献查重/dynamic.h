#pragma once
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <math.h>
#include "dynamic.h"
#include "fileReader.h"
#include "SplitSentence.h"
#include "struct.h"
#include "print.h"
#include "Utils.h"
#include <fstream>
#include <stack>

using namespace std;
string tempWord, libWord; // 表示从tempSentence与libSentence分别取的单词

/*
	wordSimilarity : wordSimilarity[i][j]表示tempSentence的第i个单词与libSentence的第j个单词是否相同
	 
	score：score[m][n] 表示该矩阵运行动态规划算法时tempSentence与libSentence的比对得分
	
	Created by 朱宏梁

	2018年1月3日 11:34:13

*/
void dynamicAlgorithm(int ** wordSimilarity, float ** score, int ***max_insert_space)
{
	int k = 0;

	//读取
	textStruct text[500];
	textStruct lib[500];

	int textCount = sentenceSplit("text.txt", text);

	int libCount = sentenceSplit("lib.txt", lib);

	int ***insert_space = new int**[60];
	for (int i = 0; i<60; i++)
	{
		insert_space[i] = new int*[60];
		for (int j = 0; j < 60; j++)
		{
			insert_space[i][j] = new int[2];
			insert_space[i][j][0] = 0;
			insert_space[i][j][1] = 0;
		}
	}
	

	//text与所有lib中的句子比较，得出相似矩阵
	for (k = 0; k< textCount; k++)
	{
		string *tempWord = new string[text[k].wordCount];  // 存储tempSentence中的单词
		
		sentenceTools::wordSplit(text[k].textSentence,tempWord); //得到当前句子的所有单词
		
		float maxSimilarity = -1000;

		//记录相似句子的下标
		int simIndex = 0;
		int libsimIndex = 0;


		for (int x = 0; x < libCount; x++)
		{
			string *libWord = new string[lib[x].wordCount]; // 存储libSentence中的单词
			sentenceTools::wordSplit(lib[x].textSentence, libWord); //得到lib文件中句子的全部单词

			//得出相似矩阵：--->这个句子与当前lib中的句子
			for (int r = 0; r < text[k].wordCount; r++)
			{
				for (int t = 0; t < lib[x].wordCount; t++)
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


			//打印相似矩阵
			/*cout << "第" << k+1 << "句话与lib中的第" << x+1 << "句话的相似矩阵为：" << endl;
			sentenceTools::printMatrix(wordSimilarity, text[k].wordCount, lib[x].wordCount);*/

			//计算score

			int m = text[k].wordCount; // score 
			int n = lib[x].wordCount;


			for (int i = 1; i < m; i++)
			{
				if ((score[i-1][0] - 0.5) > wordSimilarity[i][0] - 0.5*(i - 1))
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
				if ((score[0][i-1] - 0.5) > wordSimilarity[0][i] - 0.5*(i - 1))
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
					if ((score[i - 1][j] - 0.5) > (score[i][j - 1] - 0.5))
					{
						score[i][j] = score[i - 1][j] - 0.5;
						insert_space[i][j][0] = i - 1;
						insert_space[i][j][1] = j;
					}
					else
					{
						score[i][j] = score[i][j - 1] - 0.5;
						insert_space[i][j][0] = i;
						insert_space[i][j][1] = j - 1;
					}
					if (score[i][j] < (score[i - 1][j - 1] + wordSimilarity[i][j]))
					{
						score[i][j] = score[i - 1][j - 1] + wordSimilarity[i][j];
						insert_space[i][j][0] = i - 1;
						insert_space[i][j][1] = j - 1;
					}
				}
			}
			
			if (maxSimilarity <= score[m - 1][n - 1])
			{
				for (int i = 0; i < m; i++)
				{
					for (int j = 0; j < n; j++)
					{
						max_insert_space[i][j][0] = insert_space[i][j][0];
						max_insert_space[i][j][1] = insert_space[i][j][1];
					}
				}
				maxSimilarity = score[m - 1][n - 1];
				simIndex = k;
				libsimIndex = x;
			}
			

			//打印相似矩阵
			/*ofstream scores;
			scores.open("score.txt", ios::app);

			scores << "第" << k+1 << "句话与lib中的第" << x+1 << "句话的score为：" << endl;*/
			//sentenceTools::printMatrix(score, text[k].wordCount, lib[x].wordCount);
			
			/*for (int i = 0; i < text[k].wordCount; i++)
			{
				for (int j = 0; j < lib[x].wordCount; j++)
				{
					scores << score[i][j] << "\t";
				}
				scores << endl;
			}*/


		}

		int mm = text[simIndex].wordCount; 
		int nn = lib[libsimIndex].wordCount;


		/*for (int i = 0; i < mm; i++)
		{
			for (int j = 0; j < nn; j++)
			{
				cout << '(' << max_insert_space[i][j][0] << ',' << max_insert_space[i][j][1] << ") ";
			}
			cout << endl;
		}*/
		stack<int*> insert_space_stack;
		insert_space_stack.push(new int[2]);
		insert_space_stack.top()[0] = mm - 1;
		insert_space_stack.top()[1] = nn - 1;
		//cout << mm << ',' << nn;
		//system("pause");
		for (int i = mm - 1, j = nn - 1; i > 0 && j > 0;)
		{
			insert_space_stack.push(max_insert_space[i][j]);
			int temp = i;
			i = max_insert_space[i][j][0];
			j = max_insert_space[temp][j][1];
		}

		/*while (!insert_space_stack.empty())
		{
			cout << '(' << insert_space_stack.top()[0] << ',' << insert_space_stack.top()[1] << ")\n";
			insert_space_stack.pop();
		}*/



		string new_text;
		string new_lib_text;

		string *tWord = new string[text[simIndex].wordCount];  // 存储tempSentence中的单词
		string *libWord = new string[lib[libsimIndex].wordCount];  // 存储tempSentence中的单词


		sentenceTools::wordSplit(text[simIndex].textSentence, tWord); //得到当前句子的所有单词
		sentenceTools::wordSplit(lib[libsimIndex].textSentence, libWord); //得到当前句子的所有单词
		/*cout << text[simIndex].textSentence << endl;
		cout << lib[libsimIndex].textSentence << endl;*/
		int i, j, before_i = -1, before_j = -1;
		while (!insert_space_stack.empty()) {
			i = insert_space_stack.top()[0];
			j = insert_space_stack.top()[1];
			if (i != before_i && j != before_j) {
				new_text.append(tWord[i] + ' ');
				new_lib_text.append(libWord[j] + ' ');
				int w = tWord[i].size() - libWord[j].size();
				while (w > 0) {
					new_lib_text.append(" ");
					w--;
				}
				while (w < 0) {
					new_text.append(" ");
					w++;
				}
			}
			else if (i == before_i) 
			{
				new_lib_text.append(libWord[j] + ' ');
				for (int l = 0; l <= libWord[j].size(); l++)
				{
					new_text.append(" ");
				}
			}
			else 
			{
				new_text.append(tWord[i] + ' ');
				for (int l = 0; l <= tWord[i].size(); l++)
				{
					new_lib_text.append(" ");
				}
			}

			before_i = i;
			before_j = j;

			/*cout << new_text << endl;
			cout << new_lib_text << endl;
			system("pause");*/

			insert_space_stack.pop();
		}


		cout << endl << "第" << simIndex + 1 << "句话与lib中的第" << libsimIndex << "句话最相似!" << endl;
		cout << "得分为：" << maxSimilarity << endl;
		cout << "比对结果：" << endl;
		/*cout << text[simIndex].textSentence << endl;
		cout << lib[libsimIndex].textSentence << endl;*/
		cout << new_text << endl << new_lib_text << endl;
		cout << "---------------------------------------------------------------" << endl;

	}
	

}