#pragma once
#include <iostream>
#include <string.h>
#include "fileReader.h"
#include "struct.h"

using namespace std;


const char *text; //��ȡ�ı���ѯ������
const char *lib;  // �����ȡ�Ŀ��ļ�
const char *textStr;


/*
	�����׷ֳɵ������ӱ����ڶ�Ӧ�����ݽṹ��
	Created By �����

	2018��1��3�� 10:14:40
*/


int sentenceSplit(char *fileName, textStruct textStruct[])
 {
	int wordCount = 0; //  ͳ�Ƶ��ʵĸ���

	int num = 0; // ���ӵĸ���

	string tempSentence; // ���ڴ洢��ǰ����ľ���

	string Word; //��ʱ�洢����

	// ��ȡ�ļ�
	string txt = read(fileName);

	//cout << txt << endl;

	textStr = txt.c_str(); // ת�����ַ�����

	for (int k = 0; k < strlen(textStr); k++)
	{

		//int last = 0;// ��¼�������һ���ַ����±�

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

				Word = "";  // ����
			}
		}
		if ((textStr[k] == '.') || (textStr[k] == '?') || (textStr[k] == '!'))
		{
			
			transform(tempSentence.begin(), tempSentence.end(), tempSentence.begin(), ::tolower);
			textStruct[num].textSentence = tempSentence;
			textStruct[num].wordCount = wordCount;
			tempSentence = ""; // ������ʱ����
			wordCount = 0; //����
			num++;
		}

	}
	return num;

}