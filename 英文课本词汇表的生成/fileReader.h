#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "wordUnit.h"

#define N 100


/*
	ԭʼ���ݵĶ�ȡ

	Created By �����

	2018��1��2�� 19:53:59

*/

/*��ȡ����*/
string  readtext(char* text)
{
	char *str = new char[N + 1];

	string word = "";

	int numCount = 0;
	char *p = text;
	FILE *fp;
	int i = 0;
	if ((fp = fopen(p, "r")) == NULL)
	{
		printf("\t\t\t\t���ļ�Ϊ%sʧ��! �밴������˳���\n", p);
		system("pause");
		exit(0);

	}

	while (fgets(str, 100, fp) != NULL)
	{
		word += str;
	}
	//numCount = i;
	printf("\t\t\t\t��ȡ��ϣ�\n\n\n\n\n");

	/*int j = 0;
	while (word[j] != NULL)
	{
		printf("%c", word[j]);
		j++;
	}*/

	return word;
}