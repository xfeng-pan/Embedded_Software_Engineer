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
		printf("今天是星期%d,是工作日\n", day);
		break;
	case 6:
	case 7:
		printf("今天是星期%d,是休息日\n", day);
		break;
	default:
		printf("输入错误\n");
		break;
	}
	return 0;
}