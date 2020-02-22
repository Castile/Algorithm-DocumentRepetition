#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include "dynamic.h"
#include "fileReader.h"
#include "SplitSentence.h"
#include "struct.h"
#include "print.h"
#include "Utils.h"
//#include "Test.h"

using namespace std;


/*
	��̬�滮ʵ�����ײ���
	Created By �����

*/

int main()
{
	textStruct text[100];
	textStruct lib[100];

	int textCount = sentenceSplit("text.txt", text);

	cout << "text�о��ӵĸ���Ϊ��"<<textCount << endl;

	int libCount = sentenceSplit("lib.txt", lib);

	cout << "lib�о��ӵĸ���Ϊ��" << libCount << endl;

	//printSentence::printList(text, textCount);
	//printSentence::printList(lib, libCount);



	//����
	//�����ڴ�
	int **wordSimilarity = new int *[60];
	float **score = new float *[60];
	int ***insert_space = new int**[60];
	for (int i = 0; i<60; i++)
	{
		wordSimilarity[i] = new int[60];
		score[i] = new float[60];
		insert_space[i] = new int*[60];
		for (int j = 0; j < 60; j++)
		{
			insert_space[i][j] = new int[2];
			insert_space[i][j][0] = 0;
			insert_space[i][j][1] = 0;
		}
	}

	//��ʼ��
	for (int i = 0; i < 60; i++)
	{
		for (int j = 0; j < 60; j++)
		{
			wordSimilarity[i][j]=0;
			score[i][j] = 0;
		}
		
	}

	dynamicAlgorithm(wordSimilarity, score, insert_space);

	/*cout << text[11].textSentence << endl;
	cout << "����������������������������������������������������������������������������"<<endl;
	cout << lib[31].textSentence << endl;*/

	/*dynamic(wordSimilarity, score);
	cout << "���ƾ���Ϊ��" << endl;
	printSimilarityMatrix(wordSimilarity);
	cout << "�÷־���Ϊ��" << endl;
	printScoreMatrix(score);*/

	//getchar();

	return 0;
}
