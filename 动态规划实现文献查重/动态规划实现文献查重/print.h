#pragma once

#include <iostream>
#include <cstdio>
#include "struct.h"



using namespace std;


/*

	�淶��ʽ��ӡ

	Created By �����
	2018��1��3�� 11:01:14
*/
namespace printSentence {

	void printList(textStruct text[],int count)
	{
		printf("���� \t\t\t���ʸ���\n");
		for (int t = 0; t < count; t++)
		{
			printf("%-20s\t %10d\n", text[t].textSentence.c_str(),text[t].wordCount);  //�Ҷ��룬15λ���ȣ��������ո�
																			   //cout << word[t].sequence <<"\t\t\t\t\t"<<word[t].freq<< endl;
		}
	}
}