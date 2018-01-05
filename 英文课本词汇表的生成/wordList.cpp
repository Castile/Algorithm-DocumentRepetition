#include <iostream>
#include <algorithm>
#include "fileReader.h"
#include "wordSort.h"
#include "wordSplit.h"
#include "wordsSave.h"
#include "wordUnit.h"
#include "wordsTablePrint.h"
#include  "Utils.h"

using namespace std;
string wordlist[10000]; // 分割后的单词

Unit verb[10000]; // 单词结构体


/*
	读入一段文本，然后输出两张词汇表。
	其中一张是按字母排序的词汇统计表，
	另外一张是按单词频率降序排序的词汇表，
	两张表格均需附上每个单词的频率

	Created By 朱宏梁
	2018年1月2日 20:00:55

*/

//主函数Test
int main()
{
	int count = wordSplit("text.txt",wordlist);

	cout << "\n\n***************************************************************************"<<endl;

	cout << "共分割为" << count << "个单词:\n" << endl;

	int numVerb = wordSave(wordlist, verb, count);
	cout << "单词表数量=" << numVerb << endl;


	//排序
	SortWord::__MergeSortByName(verb, 0, numVerb - 1);
	cout << "按照单词字母顺序排序的单词表：" << endl;
	cout << "------------------------------------------------------------------" << endl;
	printWordTable::printList(verb, numVerb);
	//保存在文件中
	fileUtils::saveToFile(verb, numVerb, "WordListByName.txt");


	cout << "\n************************************************************************\n" << endl;

	SortWord::__MergeSortByFreq(verb, 0, numVerb - 1);
	cout << "按照单词出现的频率排序的单词表：" << endl;
	cout << "------------------------------------------------------------------" << endl;
	printWordTable::printList(verb, numVerb);
	fileUtils::saveToFile(verb, numVerb, "WordListByFreq.txt");

	return 0;

}