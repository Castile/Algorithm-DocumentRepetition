#pragma once
#include <iostream>
#include <cstdio>
#include <string>
#include <string.h>

#define N 100

using namespace std;

/*
	�ļ���ȡ����
	Created By �����
	2018��1��3�� 10:15:05
*/
string  read(char* fileName)
{
	char *str = new char[N + 1];

	string text = "";

	char *p = fileName;
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
		text += str;
	}
	
	printf("\t\t\t\t��ȡ��ϣ�\n\n\n\n\n");

	
	return text;
}