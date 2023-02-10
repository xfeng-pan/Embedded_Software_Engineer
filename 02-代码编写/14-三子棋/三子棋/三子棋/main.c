#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

int main()
{
	int input = 0;
	//创建棋盘
	
	printf("%p \n", &Board[0][0]);
	
	//设置随机数种子
	srand((unsigned int)time(NULL));
	//进入菜单选择并进行游戏
	do
	{
		printf("***************************************\n");
		printf("*******  1.Play        0.Exit  ********\n");
		printf("***************************************\n");
		printf("请选择是否进行游戏：\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			GameStart(Board, Row, Col);
			break;
		case 0:
			printf("退出游戏\n");
			break;
		default:
			printf("输入错误！！！\n");
			break;
		}

	} while (input);






	return 0;
}