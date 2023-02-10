#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a = 20;
	int* p = &a;
	double d = 3.14;
	double* pd = &d;

	*p = 50;//*是解引用操作符
	printf("p的值是：%p\n", p);
	printf("p的值是：%lld\n", p);//这里是以十进制的形式输出的地址，用%d表示的范围会不够
	//这里会警告是因为printf中的p是一个指针变量，需要的是%p，而这里强制转化为了%lld
	printf("a的值是：%d\n", *p);
	printf("指针p所占的空间大小为：%lldbytes\n", sizeof(p));

	printf("--------------\n");
	printf("%.2lf\n", d);
	printf("%.2lf\n", *pd);
	return 0;
}