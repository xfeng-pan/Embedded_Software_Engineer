#define _CRT_SECURE_NO_WARNINGS 1


#include "List.h"

void TestList1()
{
	ListNode* plist = ListInit();


	ListPushBack2(&plist,1);
	ListPushBack2(&plist,2);
	ListPushBack2(&plist,3);
	ListPushBack(plist, 4);
	ListPushBack(plist, 5);
	ListPushBack(plist, 6);

	ListPrint(plist);

	ListPushFront(plist, 0);
	ListPrint(plist);

	ListPopFront(plist);
	ListPrint(plist);

	ListPopBack(plist);
	ListPrint(plist);


	ListNode* pos = ListFind(plist, 3);
	if (pos)
	{
		pos->data *= 3;
		printf("�ҵ���,����3\r\n");
		ListPrint(plist);
	}
	else
	{
		printf("�Ҳ���\r\n");
	}

	ListInsert(pos, 30);
	ListPrint(plist);

	printf("ɾ��pos\r\n");
	ListErase(pos);
	ListPrint(plist);

	ListDestory(plist);

}


int main()
{
	TestList1();
	return 0;
}
