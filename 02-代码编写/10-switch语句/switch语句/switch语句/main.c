#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int day = 0;
	scanf("%d", &day);	
	switch (day)
	{
	case 1:
	case 2:
	case 3:
	case 4:
	case 5:
		printf("����������%d,�ǹ�����\n", day);
		break;
	case 6:
	case 7:
		printf("����������%d,����Ϣ��\n", day);
		break;
	default:
		printf("�������\n");
		break;
	}
	return 0;
}