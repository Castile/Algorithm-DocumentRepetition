#pragma once

#include <iostream>
#include <algorithm>
#include "wordUnit.h"

/*
	
	�ϲ������㷨�� �����ʱ�����1. ����ĸ˳��		2.�����ʳ��ֵ�Ƶ�ʽ������У�

	Created By �����

	2018��1��2�� 19:56:32
*/
namespace SortWord 
{
	/*
		������ĸ˳��ϲ����򵥴�
	*/
	void MergeByName(Unit word[], int left, int mid, int right)
	{
		//����һ����������
		Unit *t = new Unit[right - left + 1];
		int i = left;
		int j = mid + 1;
		int k = 0;

		while (i <= mid && j <= right)
		{
			if (strcmp(word[i].sequence.data(), word[j].sequence.data())<0)
				t[k++] = word[i++];
			else
				t[k++] = word[j++];
		}
		while (j <= right)
			t[k++] = word[j++];


		while (i <= mid)
			t[k++] = word[i++];


		//��t[]��Ԫ�ظ��ƻ�a[]��left��right��  
		for (int i = left; i <= right; i++)
		{
			word[i] = t[i - left];
		}

	}

	void __MergeSortByName(Unit word[], int left, int right)
	{
		if (left >= right)
			return;
		int mid = (left + right) / 2;

		__MergeSortByName(word, left, mid);
		__MergeSortByName(word, mid + 1, right);

		MergeByName(word, left, mid, right);

	}

	/*
	������ĸ˳��ϲ����򵥴�
	*/
	void MergeByFreq(Unit word[], int left, int mid, int right)
	{
		//����һ����������
		Unit *t = new Unit[right - left + 1];
		int i = left;
		int j = mid + 1;
		int k = 0;

		while (i <= mid && j <= right)
		{
			if (word[i].freq > word[j].freq)
				t[k++] = word[i++];
			else
				t[k++] = word[j++];
		}
		while (j <= right)
			t[k++] = word[j++];


		while (i <= mid)
			t[k++] = word[i++];


		//��t[]��Ԫ�ظ��ƻ�a[]��left��right��  
		for (int i = left; i <= right; i++)
		{
			word[i] = t[i - left];
		}

	}

	void __MergeSortByFreq(Unit word[], int left, int right)
	{
		if (left >= right)
			return;
		int mid = (left + right) / 2;

		__MergeSortByFreq(word, left, mid);
		__MergeSortByFreq(word, mid + 1, right);

		MergeByFreq(word, left, mid, right);

	}




}
