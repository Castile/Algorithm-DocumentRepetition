#pragma once

#include <iostream>
#include "wordUnit.h"
#include "wordSort.h"
#include "wordsSave.h"
using namespace std;


/*

	�淶��ʽ��ӡ���ʱ�Dao����̨��

	Created By �����
	2018��1��2�� 19:55:13
*/
namespace printWordTable{

	void printList(Unit word[],int numVerb)
	{
		printf("���� \t\t\tƵ��\n");
		for (int t = 0; t < numVerb; t++)
		{
			printf("%-10s\t %10d\n", word[t].sequence.c_str(),word[t].freq);  //�Ҷ��룬15λ���ȣ��������ո�
			//cout << word[t].sequence <<"\t\t\t\t\t"<<word[t].freq<< endl;
		}
	}
}