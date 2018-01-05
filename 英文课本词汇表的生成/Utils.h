#pragma once
#include <iostream>
#include "wordUnit.h"

/*
	
	�ļ��Ĺ��ߣ�������ĵ��ʱ�����ļ���

	Created By �����
	2018��1��2�� 19:53:05

*/

namespace fileUtils {
	
	void saveToFile(Unit Verb[],int numVerb, char* filename)
	{
		/*���ź��������д��Sorted_telebook_Byname.txt�ļ���*/

		FILE * fp;

		if ((fp = fopen(filename, "w")) == NULL)
		{
			printf("\t���ļ�Ϊ%sʧ��! �밴������˳���\n", filename);
			system("pause");
			exit(0);
		}
		for (int i = 0; i<numVerb; i++)
		{
			fprintf(fp, "%-10s\t %10d\n", Verb[i].sequence.c_str(),Verb[i].freq);
		}
		printf("\n\t\t\t\t���ڱ�����...\n\n");
		fclose(fp);
		printf("\t\t\t\t���ݱ���ɹ���\n\n");
	}

}