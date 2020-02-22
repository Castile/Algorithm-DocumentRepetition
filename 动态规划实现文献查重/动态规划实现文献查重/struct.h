#pragma once

#include <cstdio>
#include <iostream>

using namespace std;
/*
	保存用于被查询的文本文件

	Created by 朱宏梁
	2018年1月3日 10:09:41
*/


/*
	被查询文献的结构体
*/
struct textStruct {
	
	string textSentence; // 保存句子的内容

	int wordCount; // 该句子单词的个数

};


///*
//	查询库的结构体
//*/
//struct libStruct {
//
//	string libSentence; // 保存库文件句子的内容
//
//	int wordCount; // 句子单词的个数
//};