#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h> //���ݼ�����Ҫ�õ��Ŀ⺯��

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
//	int arr[10] = {1,2,3,4,5,6,7,8,9,10};//����ĳ�ʼ��
//	char ch[20] = { 65 };//����ֻ��ʼ���˵�һ��Ԫ�أ�
//	printf("%c\n", ch[9]);
//	return 0;
//}