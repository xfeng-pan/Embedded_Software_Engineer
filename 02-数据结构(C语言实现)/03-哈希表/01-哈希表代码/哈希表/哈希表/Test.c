#define _CRT_SECURE_NO_WARNINGS 1

#include "hash.h"
#include <stdio.h>


int main()
{
	char* ele[] = {"China", "England", "Japan", "America"};

	HashTable* hTable = InitHash(16);
	HashInsert(hTable, 0, ele[0]);
	HashInsert(hTable, 1, ele[1]);
	HashInsert(hTable, 2, ele[2]);
	HashInsert(hTable, 3, ele[3]);

	HashDelete(hTable, 2);

	for (int i = 0; i < 4; i++)
	{
		Element e = HashFind(hTable, i);
		if (e)
		{
			printf("%s\r\n", (const char*)Retrieve(e));
		}
	}

	HashDestory(hTable);
	return 0;
}

