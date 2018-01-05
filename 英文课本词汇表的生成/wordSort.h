#pragma once

#include <iostream>
#include <algorithm>
#include "wordUnit.h"

/*
	
	合并排序算法： 将单词表排序（1. 按字母顺序		2.按单词出现的频率降序排列）

	Created By 朱宏梁

	2018年1月2日 19:56:32
*/
namespace SortWord 
{
	/*
		按照字母顺序合并排序单词
	*/
	void MergeByName(Unit word[], int left, int mid, int right)
	{
		//创建一个辅助数组
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


		//把t[]的元素复制回a[]中left到right段  
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
	按照字母顺序合并排序单词
	*/
	void MergeByFreq(Unit word[], int left, int mid, int right)
	{
		//创建一个辅助数组
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


		//把t[]的元素复制回a[]中left到right段  
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
