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

	SeqListPopFront(&s1);
	SeqListPrint(&s1);

	SeqListInsert(&s1, 2, 5);
	SeqListPrint(&s1);

	SeqListErase(&s1, 2);
	SeqListPrint(&s1);

	printf("Position find result: %d\r\n", SeqListFind(&s1, 2));

	SeqListModify(&s1, 2, 20);
	SeqListPrint(&s1);

	printf("Position find result: %d\r\n", SeqListFind(&s1, 20));


	SeqListDestory(&s1);

}

void menu()
{
	printf("**********************************************************\r\n");
	printf("****1. β��                    2. ͷ��   *****************\r\n");
	printf("****3. βɾ                    4. ͷɾ   *****************\r\n");
	printf("****5. ��ӡ                    6. ����   *****************\r\n");
	printf("****7. ���                    -1.�˳�    *****************\r\n");
	printf("**********************************************************\r\n");
	printf("����������ѡ�-> ");
}

int main()
{
//	TestSeqList();//���Խӿ�
	int option = 0;
	int x = 1;
	SL s;

	SeqListInit(&s);

	while (option != -1)
	{
		menu();
		scanf("%d", &option);
		switch (option)
		{
		case 1:
			printf("������Ҫ��������ݣ���-1����:\r\n");
			do
			{
				scanf("%d", &x);
				SeqListPushBack(&s, x);
			} while (x != -1);

			break;
		case 2:
			break;
		case 3:
			break;
		case 4:
			break;
		case 5:
			SeqListPrint(&s);
			break;
		case 6:
			break;
		case -1:
			SeqListDestory(&s);
			return 0;
			break;
		default:
			break;
		}
	}
	

	
	return 0;
}

	 