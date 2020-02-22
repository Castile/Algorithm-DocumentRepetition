#pragma once
#include "include.h"

using namespace std;

/*
	���Ӵ���Ĺ�����
	Created By �����
	2018��1��3�� 11:42:51
*/
namespace sentenceTools {

	/*
	��һ���������ó�ȫ���ĵ���

	*/
	int wordSplit(string sentence, string wordList[])
	{
		int m = 0;

		string Word;

		text = sentence.c_str(); //ת�����ַ�����

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

					Word = "";  // ����
				}
			}

		}
		return m;
	}



	//��ӡ����
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
