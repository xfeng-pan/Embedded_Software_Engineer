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
	printf("****1. 尾插                    2. 头插   *****************\r\n");
	printf("****3. 尾删                    4. 头删   *****************\r\n");
	printf("****5. 打印                    6. 查找   *****************\r\n");
	printf("****7. 变更                    -1.退出    *****************\r\n");
	printf("**********************************************************\r\n");
	printf("请输入您的选项：-> ");
}

int main()
{
//	TestSeqList();//测试接口
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
			printf("请输入要插入的数据，以-1结束:\r\n");
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

	 