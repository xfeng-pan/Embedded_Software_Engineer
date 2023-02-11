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
	printf("请输入两个相加数：\n");
	printf("请输入第一个数：\n");
	scanf("%d", &a);
	printf("请输入第二个数：\n");
	scanf("%d", &b);
	sum = add(a, b);
	printf("%d + %d = %d\n", a, b, sum);
	return 0;
}