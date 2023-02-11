#define _CRT_SECURE_NO_WARNINGS 1


#include "contact.h"

void menu()
{
	printf("*******************************************\n");
	printf("***** 1.add            2.del    ***********\n");
	printf("***** 3.serch          4.modify ***********\n");
	printf("***** 5.show           6.sort   ***********\n");
	printf("***** 0.exit                    ***********\n");
	printf("*******************************************\n");
}

int main()
{
	int input = 0;//从键盘输入的值


	//创建通讯录
	//con就是通讯录
	//包含*data，size，capacity
	struct Contact con;

	//初始化通讯录
	//最好能传址
	//传址才能改变通讯录里的值
	InitContact(&con);

	do
	{
		menu();
		printf("请选择->:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:
			AddContact(&con);
			break;
		case DEL:
			DelContact(&con);
			break;
		case SEARCH:
			SearchContact(&con);
			break;
		case MODIFY:
			ModifyContact(&con);
			break;
		case SHOW:
			ShowContact(&con);
			break;
		case SORT:
			break;
		case EXIT:
			DestroyContact(&con);
			printf("推出通讯录");
			break;
		default:
			printf("选择错误");
		}
	} while (input);

	return 0;
}

