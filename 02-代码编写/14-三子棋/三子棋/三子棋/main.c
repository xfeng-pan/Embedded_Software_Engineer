#define _CRT_SECURE_NO_WARNINGS

#include "game.h"

int main()
{
	int input = 0;
	//��������
	
	printf("%p \n", &Board[0][0]);
	
	//�������������
	srand((unsigned int)time(NULL));
	//����˵�ѡ�񲢽�����Ϸ
	do
	{
		printf("***************************************\n");
		printf("*******  1.Play        0.Exit  ********\n");
		printf("***************************************\n");
		printf("��ѡ���Ƿ������Ϸ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			GameStart(Board, Row, Col);
			break;
		case 0:
			printf("�˳���Ϸ\n");
			break;
		default:
			printf("������󣡣���\n");
			break;
		}

	} while (input);






	return 0;
}