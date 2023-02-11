#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h> //次幂计算需要用到的库函数

int main()
{
	int a = 2, b = 3;
	int c = 0;
	c = a ^ b;
	printf("a\^b = %d\n", c);
	c = pow(a, b);
	printf("pow\(a,b\)=%d\n", c);
	return 0;
}

//int main()
//{
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//数组的初始化
//	char ch[20] = { 65 };//这样只初始化了第一个元素，
//	printf("%c\n", ch[9]);
//	return 0;
//}