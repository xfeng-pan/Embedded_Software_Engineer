#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int add(int x, int y)
{
	int z = 0;
	return z = x + y;
}

int main()
{
	int a = 0, b = 0;
	int sum = 0;
	printf("�����������������\n");
	printf("�������һ������\n");
	scanf("%d", &a);
	printf("������ڶ�������\n");
	scanf("%d", &b);
	sum = add(a, b);
	printf("%d + %d = %d\n", a, b, sum);
	return 0;
}