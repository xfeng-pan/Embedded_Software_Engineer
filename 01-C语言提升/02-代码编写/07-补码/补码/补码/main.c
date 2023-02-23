#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
int main()
{
	int a = 0;	//int类型4bytes，一共32位
	//a=0000000000
	int b = a;
	//b=0000000000
	b = ~a;
	//b=1111111111
	//此时b相当于是存储的一个复数的补码
	//补码：1111111111（补码-1=反码）
	//反码：1111111110（原码=反码（除符号位）取反）
	//原码：1000000001（此时变为-1，溢出了）
	printf("%d\n", b);
	return 0;
}