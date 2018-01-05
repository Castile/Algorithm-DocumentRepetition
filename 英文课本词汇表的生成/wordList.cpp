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
string wordlist[10000]; // �ָ��ĵ���

Unit verb[10000]; // ���ʽṹ��


/*
	����һ���ı���Ȼ��������Ŵʻ��
	����һ���ǰ���ĸ����Ĵʻ�ͳ�Ʊ�
	����һ���ǰ�����Ƶ�ʽ�������Ĵʻ��
	���ű����踽��ÿ�����ʵ�Ƶ��

	Created By �����
	2018��1��2�� 20:00:55

*/

//������Test
int main()
{
	int count = wordSplit("text.txt",wordlist);

	cout << "\n\n***************************************************************************"<<endl;

	cout << "���ָ�Ϊ" << count << "������:\n" << endl;

	int numVerb = wordSave(wordlist, verb, count);
	cout << "���ʱ�����=" << numVerb << endl;


	//����
	SortWord::__MergeSortByName(verb, 0, numVerb - 1);
	cout << "���յ�����ĸ˳������ĵ��ʱ�" << endl;
	cout << "------------------------------------------------------------------" << endl;
	printWordTable::printList(verb, numVerb);
	//�������ļ���
	fileUtils::saveToFile(verb, numVerb, "WordListByName.txt");


	cout << "\n************************************************************************\n" << endl;

	SortWord::__MergeSortByFreq(verb, 0, numVerb - 1);
	cout << "���յ��ʳ��ֵ�Ƶ������ĵ��ʱ�" << endl;
	cout << "------------------------------------------------------------------" << endl;
	printWordTable::printList(verb, numVerb);
	fileUtils::saveToFile(verb, numVerb, "WordListByFreq.txt");

	return 0;

}