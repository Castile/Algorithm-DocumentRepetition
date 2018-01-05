#pragma once
#include <iostream>
#include "wordUnit.h"

/*
	
	文件的工具：将输出的单词表存入文件中

	Created By 朱宏梁
	2018年1月2日 19:53:05

*/

namespace fileUtils {
	
	void saveToFile(Unit Verb[],int numVerb, char* filename)
	{
		/*将排好序的数据写入Sorted_telebook_Byname.txt文件中*/

		FILE * fp;

		if ((fp = fopen(filename, "w")) == NULL)
		{
			printf("\t打开文件为%s失败! 请按任意键退出！\n", filename);
			system("pause");
			exit(0);
		}
		for (int i = 0; i<numVerb; i++)
		{
			fprintf(fp, "%-10s\t %10d\n", Verb[i].sequence.c_str(),Verb[i].freq);
		}
		printf("\n\t\t\t\t正在保存中...\n\n");
		fclose(fp);
		printf("\t\t\t\t数据保存成功！\n\n");
	}

}