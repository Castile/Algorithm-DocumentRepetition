#pragma once
#include <stdio.h>
#include <stdlib.h>
#include "wordUnit.h"

/*

	����ָ������ĵ��ʣ�Ҫ�󵥴ʲ��ظ�

	Created By �����
	2018��1��2�� 19:58:33

*/
 int  wordSave(string word[],Unit verb[],int count)
{
	int numVerb = 0;// �ñ�����ʾ��ͬ���ʵ�����

	int newWord = 1;  // �õ������ڱ��һ�������Ƿ���¼���ʻ����

	for(int x = 0; x <= count; x++)
	{
		newWord = 1;  // ��ÿһ���Ƚϵĵ��ʶ���ʼ��Ϊ�µ���
		int i = 0;
		while (i <= numVerb)
		{
			if (word[x] == verb[i].sequence)
			{
				verb[i].freq++;
				newWord = 0;

				break;
			}

			i++;
		}

		if (newWord == 1) 
		{
			// ��Word����ʻ���У���������+1
			verb[numVerb].sequence = word[x];
			verb[numVerb].freq = 1;
			numVerb++;
		}
		

	}
	
	return numVerb;
}