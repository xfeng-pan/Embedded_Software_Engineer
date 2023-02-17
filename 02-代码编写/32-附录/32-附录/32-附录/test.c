#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stddef.h>

#define OFFSETOF(struct_name,struct_member) (int)&(((struct_name*)0)->struct_member)

typedef struct Student
{
	char c1;
	int a;
	char c2;
}S;//所占空间为12个字节

int main()
{
	S s = { 0 };
	printf("%d\n", offsetof(S, c1));
	printf("%d\n", offsetof(S, a));
	printf("%d\n", offsetof(S, c2));
	printf("\n");
	printf("%d\n", OFFSETOF(S, c1));
	printf("%d\n", OFFSETOF(S, a));
	printf("%d\n", OFFSETOF(S, c2));
	return 0;
}

