#define _CRT_SECURE_NO_WARNINGS 1

#include "SList.h"

void TestSList()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);
	SListPrint(plist);

	SListPushFront(&plist, 0);
	SListPrint(plist);

	SListPopFront(&plist);
	SListPrint(plist);

	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPopBack(&plist);
	SListPrint(plist);
}

void TestSList2()
{
	SLTNode* plist = NULL;

	SListPushBack(&plist, 1);
	SListPushBack(&plist, 2);
	SListPushBack(&plist, 3);
	SListPushBack(&plist, 4);
	SListPushBack(&plist, 5);

	//在3前面插入一个30
	SLTNode* pos = SListFind(plist, 3);
	if (pos)
	{
		SListInsert(&plist, pos, 30);
	}

	SListInsert(&plist, plist,10);

	SListPrint(plist);

	SListErase(&plist, SListFind(plist, 30));

	SListPrint(plist);

	SListErase(&plist, SListFind(plist, 10));

	SListPrint(plist);
}

int main()
{
	//TestSList();
	TestSList2();
	return 0;
}



