#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void TestSeqList(void)
{
	SL s1;
	SeqListInit(&s1);

	SeqListPushBack(&s1, 1);
	SeqListPushBack(&s1, 2);
	SeqListPushBack(&s1, 3);
	SeqListPushBack(&s1, 4);
	SeqListPushBack(&s1, 5);
	SeqListPrint(&s1);

	SeqListPushFront(&s1, 0);
	SeqListPrint(&s1);

	SeqListPopBack(&s1);
	SeqListPrint(&s1);

}

int main()
{
	TestSeqList();
	
	return 0;
}

	 