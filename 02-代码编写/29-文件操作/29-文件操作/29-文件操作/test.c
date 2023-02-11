#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>


int main()
{
	int a = 10000;
	FILE* pf = fopen("test.txt", "wb");//w：写   b：以二进制的形式来写
	fwrite(&a, 4, 1, pf);//以二进制的形式写入文件中
	//表示数据来自a，
	//写的数据的类型是4个字节的;
	//写一个这种类型的数据;
	//写到pf指针所指的地方


	fclose(pf);
	pf = NULL;
	return 0;
}


