#pragma once
#include <iostream>
#include <string.h>
#include "fileReader.h"
#include "wordsSave.h"

using namespace std;
const char * text; // ��������ı�����text��

string Word = ""; //���ָ�ĵ�����word��ʾ


/*
	���ʷָ��
	Created By �����

	2018��1��2�� 19:58:42

*/
 int wordSplit(char * fileName,string wordlist[])
{
	int wordcount = 0; // ͳ�Ƶ��ʵĸ���
	int m = 0;
	// �ļ���ȡ
    string txt = readtext(fileName);

	cout << txt << endl;

	text = txt.c_str(); //ת�����ַ�����
	
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
				transform(Word.begin(), Word.end(), Word.begin(), ::tolower); // ת��ΪСд
				//cout << Word << endl;

				wordlist[m] = Word;
				//cout << wordlist[m] << endl;
				wordcount = m;
				m++;
				//wordSave(Word);
				//cout << Word << endl;
				Word = "";  // ����
			}
		}
	
	}
	return wordcount;
}