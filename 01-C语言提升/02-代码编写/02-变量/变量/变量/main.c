#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

//int main()
//{
//	int age = 20;
//	float weight = 95.6;
//	char ch = 'A';
//	return 0;
//}

int main()
{
	int a = 0;
	int b = 0;
	int sum = 0;
	scanf("%d%d", &a, &b);
	//b = a + b;
	sum = a + b;
	//printf("%d", b);	这样也是可用的
	printf("%d", sum);
	return 0;

}