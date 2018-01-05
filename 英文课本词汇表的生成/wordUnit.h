#pragma once
#include <iostream>
#include <string.h>
#include <string>
#include <stdio.h>
#include <cstdlib>

using namespace std;

/*
	单词的结构体

	2018年1月2日 19:54:24
*/

//用于存储单词
struct Unit {
	
	string sequence; // 单词

	int freq;   // 该单词的频率
};