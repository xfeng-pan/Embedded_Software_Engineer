#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main()
{
	int a = 20;
	int* p = &a;
	double d = 3.14;
	double* pd = &d;

	*p = 50;//*�ǽ����ò�����
	printf("p��ֵ�ǣ�%p\n", p);
	printf("p��ֵ�ǣ�%lld\n", p);//��������ʮ���Ƶ���ʽ����ĵ�ַ����%d��ʾ�ķ�Χ�᲻��
	//����ᾯ������Ϊprintf�е�p��һ��ָ���������Ҫ����%p��������ǿ��ת��Ϊ��%lld
	printf("a��ֵ�ǣ�%d\n", *p);
	printf("ָ��p��ռ�Ŀռ��СΪ��%lldbytes\n", sizeof(p));

	printf("--------------\n");
	printf("%.2lf\n", d);
	printf("%.2lf\n", *pd);
	return 0;
}